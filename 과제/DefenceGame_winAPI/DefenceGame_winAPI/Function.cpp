#include"stdafx.h"
#include"DefenceGame_winAPI.h"
#include"Function.h"

#include<stdlib.h>
#include<io.h>

double DegreeToRadian(int degree)
{
	return degree * M_PI / 180;
}

POINT PointRotate(int centerX, int centerY, int degree, const POINT *point)
{
	double rad = DegreeToRadian(degree);

	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

POINT PointRotate(int centerX, int centerY, double rad, const POINT *point)
{
	double tempX = cos(rad) * (point->x - centerX) - sin(rad) * (point->y - centerY);
	double tempY = sin(rad) * (point->x - centerX) + cos(rad) * (point->y - centerY);
	POINT temp = { centerX + tempX, centerY + tempY };
	return temp;
}

void SetColor(HDC hdc, HPEN &hPen, HPEN &oldPen, int r, int g, int b)
{
	hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));
	oldPen = (HPEN)SelectObject(hdc, hPen);
}

void DeleteColor(HDC hdc, HPEN &hPen, HPEN &oldPen)
{
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

void SetColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush, int r, int g, int b)
{
	hBrush = CreateSolidBrush(RGB(r, g, b));
	oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
}

void DeleteColor(HDC hdc, HBRUSH &hBrush, HBRUSH &oldBrush)
{
	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void DrawHpBar(HDC hdc, int _loseHpPoint)
{
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;

	SetColor(hdc, hPen, oldPen, 50, 50, 50);
	SetColor(hdc, hBrush, oldBrush, 50, 50, 50);

	MoveToEx(hdc, 0, 656, NULL);
	LineTo(hdc, 500, 656);

	Rectangle(hdc, 0, 656, 500 - _loseHpPoint, 700);

	DeleteColor(hdc, hPen, oldPen);
	DeleteColor(hdc, hBrush, oldBrush);
	
	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc,_loseHpPoint, 485);
	TextOut(hdc, 10, 665, _T("H"), _tcslen(_T("H")));

	SetTextColor(hdc, _loseHpPoint, 475);
	TextOut(hdc, 20, 665, _T("P"), _tcslen(_T("P")));

	SetTextColor(hdc, RGB(0, 0, 0));
}

void SetTextColor(HDC hdc, int _loseHpPoint, int checkNum)
{
	if (_loseHpPoint < checkNum)
		SetTextColor(hdc, RGB(255, 255, 255));
	else
		SetTextColor(hdc, RGB(0, 0, 0));
}

void ReadRanking(multimap<int, string> *playerData)
{
	ifstream fp;
	fp.open("rank.bin", std::ios::binary | std::ios::in);;

	if (!fp.is_open())
		return;

	fp.seekg(0, fp.end);
	int length = (int)fp.tellg();
	fp.seekg(0, fp.beg);

	int i = 0;
	char *buffer = new char[length];
	fp.read(buffer, length);
	while (1)
	{
		char *tNum;
		char *name;
		if (i == 0)
		{
			tNum = strtok(buffer, " ");
			name = strtok(NULL, " \r\n");
		}
		else
		{
			tNum = strtok(NULL, " ");
			name = strtok(NULL, " \r\n");
		}
		i++;
		int num = atoi(tNum);

		if (name == NULL) break;
		playerData->insert(pair<int, string>(num, (string)name));
	}

	if (fp.is_open())
		fp.close();
}

void WriteRanking(multimap<int, string> *playerData)
{
	ofstream fp;
	fp.open("rank.bin", std::ios::binary | std::ios::out);
	
	if (!fp.is_open())
		return;

	multimap<int, string>::iterator iter;
	for (iter = playerData->begin(); iter != playerData->end(); iter++)
	{
		int temp = iter->first;
		string saveStr = std::to_string(temp) + " " + iter->second + "\n" + "\0";

		fp.write(saveStr.c_str(), saveStr.size());
	}

	if(fp.is_open())
		fp.close();
}

void ResultScreen(HDC hdc, TCHAR *tcharScore, TCHAR *playerName, int playerScore, multimap<int, string> *playerData)
{
	RECT resultScreen = { 0,55,eViewW,eViewH };

	DrawText(hdc, _T("RESULT"), _tcslen(_T("RESULT")), &resultScreen, DT_CENTER | DT_VCENTER);
	resultScreen.top += 50;
	DrawText(hdc, tcharScore, _tcslen(tcharScore), &resultScreen, DT_CENTER | DT_VCENTER);

	resultScreen.top += 75;
	DrawText(hdc, _T("RANK"), _tcslen(_T("RANK")), &resultScreen, DT_CENTER | DT_VCENTER);
	
	resultScreen.left += 130;
	resultScreen.top += 50;
	resultScreen.right -= 130;
	PrintRank(hdc,resultScreen,playerData);
	
	RECT btn1 = { 50,500,200,550 };
	RECT btn2 = { 300,500,450,550 };

	Rectangle(hdc, btn1.left, btn1.top, btn1.right, btn1.bottom);
	Rectangle(hdc, btn2.left, btn2.top, btn2.right, btn2.bottom);

	DrawText(hdc, _T("Main"), _tcslen(_T("Main")), &btn1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	DrawText(hdc, _T("Exit"), _tcslen(_T("Exit")), &btn2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	// DrawUI
}

void SaveData(multimap<int, string> *playerData, TCHAR *playerName, int playerScore)
{
	int len = wcslen((wchar_t*)playerName);
	char *tempName = new char[2 * len + 1];
	wcstombs(tempName, (wchar_t*)playerName, 2 * len + 1);
	std::string sName = tempName;
	delete[] tempName;

	playerData->insert(pair<int, string>(playerScore, sName));
}

void PrintRank(HDC hdc, RECT resultScreen, multimap<int, string> *playerData)
{
	int check = 0;
	multimap<int, string>::reverse_iterator iter;
	for (iter = playerData->rbegin(); iter != playerData->rend(); iter++)
	{
		if (check > 4) break;

		wchar_t rank[32];
		_itow_s(check + 1, rank, 10);
		// change to int -> LPCWSTR

		int len;
		int sLength = (int)iter->second.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, iter->second.c_str(), sLength, 0, 0);
		wchar_t *buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, iter->second.c_str(), sLength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		// change to string -> LPCWSTR

		wchar_t num[32];
		_itow_s(iter->first, num, 10);
		// change to int -> LPCWSTR

		DrawText(hdc, rank, _tcslen(rank), &resultScreen, DT_LEFT | DT_VCENTER);
		DrawText(hdc, r.c_str(), _tcslen(r.c_str()), &resultScreen, DT_CENTER | DT_VCENTER);
		DrawText(hdc, num, _tcslen(num), &resultScreen, DT_RIGHT | DT_VCENTER);
		check++;
		resultScreen.top += 50;
	}
}