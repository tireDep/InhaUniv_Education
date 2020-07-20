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
}

void SetTextColor(HDC hdc, int _loseHpPoint, int checkNum)
{
	if (_loseHpPoint < checkNum)
		SetTextColor(hdc, RGB(255, 255, 255));
	else
		SetTextColor(hdc, RGB(0, 0, 0));
}

void ReadRanking(multimap<int, string> &playerData)
{
	FILE *fp;

	if (!_access("rank.txt", 0))
		fp = fopen("rank.txt", "r");
	else
		return;

	fseek(fp, 0, SEEK_END);
	long lSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *buffer = new char[lSize];
	//fread(buffer, 1, lSize, fp);
	while (fgets(buffer, 100, fp) != NULL)
	{
		char *tNum = strtok(buffer, " ");
		char *name = strtok(NULL, " \r\n");
		int num = atoi(tNum);
		playerData.insert(pair<int, string>(num, (string)name));
	}

	// delete[] buffer;
	if(fp != NULL)
		fclose(fp);
}

void WriteRanking(multimap<int, string> &playerData)
{
	FILE *fp;
	fp = fopen("rank.txt", "w");
	if (fp == NULL)
		exit(1);

	multimap<int,string>::iterator iter;
	for (iter = playerData.begin(); iter != playerData.end(); iter++)
	{
		int temp = iter->first;
		string saveStr = std::to_string(temp) + " " + iter->second + "\n";

		char saveChar[100];
		for (int i = 0; i < saveStr.size(); i++)
			saveChar[i] = saveStr[i];

		saveChar[saveStr.size()] = '\0';
		// fwrite(&saveStr, sizeof(saveStr), 1, fp);
		// fprintf(fp,"%d %s\n", temp, stemp);
		fprintf(fp, "%s", saveChar);
	}

	if (fp != NULL)
		fclose(fp);
}

void ResultScreen(HDC hdc, TCHAR *tcharScore, TCHAR *playerName, int playerScore, multimap<int, string> &playerData)
{
	// multimap<int, string> playerData;
	// ReadRanking(playerData);
	
	RECT resultScreen = { 0,100,eViewW,eViewH };

	DrawText(hdc, _T("RESULT"), _tcslen(_T("RESULT")), &resultScreen, DT_CENTER | DT_VCENTER);
	resultScreen.top += 50;
	DrawText(hdc, tcharScore, _tcslen(tcharScore), &resultScreen, DT_CENTER | DT_VCENTER);

	resultScreen.top += 75;
	DrawText(hdc, _T("RANK"), _tcslen(_T("RANK")), &resultScreen, DT_CENTER | DT_VCENTER);
	resultScreen.left += 100;
	resultScreen.top += 50;
	resultScreen.right -= 100;
	DrawText(hdc, _T("PlayerName + Score"), _tcslen(_T("PlayerName + Score")), &resultScreen, DT_LEFT | DT_VCENTER);

	RECT btn1 = { 50,500,200,550 };
	RECT btn2 = { 300,500,450,550 };

	Rectangle(hdc, btn1.left, btn1.top, btn1.right, btn1.bottom);
	Rectangle(hdc, btn2.left, btn2.top, btn2.right, btn2.bottom);

	DrawText(hdc, _T("Main"), _tcslen(_T("Main")), &btn1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	DrawText(hdc, _T("Exit"), _tcslen(_T("Exit")), &btn2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	// DrawUI

	

	//WriteRanking(playerData);
}