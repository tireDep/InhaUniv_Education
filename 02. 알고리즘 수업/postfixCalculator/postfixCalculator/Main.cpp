#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

bool IsOperand(string s)	// 피연산자 구별
{
	if (
		s == string("+") ||
		s == string("-") ||
		s == string("*") ||
		s == string("/") ||
		s == string(")") ||
		s == string("(")
		)
		return false;
	
	return true;
}

bool IsOperator(string sInfix, int &n)	// 연산자 기호 판별
{
	if (
		sInfix[n] == '(' ||
		sInfix[n] == ')' ||
		sInfix[n] == '+' ||
		// sInfix[n] == '-' || // 부호 일 수 있으므로 제외
		sInfix[n] == '*' ||
		sInfix[n] == '/'
		)
		return true;

	if (sInfix[n] == '-' && sInfix[n - 1] != '(')	// 연산자가 앞에 존재하지 않으면 부호 
		return true;

	return false;
}

string GetToken(string sInfix, int &n) // 문장을 토큰 단위로 자름
{
	string sToken;
	while (1)
	{
		if (IsOperator(sInfix, n))
		{
			if (sToken.length() == 0)
				sToken = sInfix[n++];
			break;
		}
		else
		{
			char szTemp[] = { sInfix[n++],'\0' };
			sToken += string(szTemp);
		}
	}
	return sToken;
}

int main()
{
	char szTemp[1024];
	FILE *fp = NULL;
	fopen_s(&fp, "calc.txt", "r");
	fgets(szTemp, 1024, fp);
	fclose(fp);

	string sInfix(szTemp);
	sInfix = string("(") + sInfix + string(")");
	cout << "Infix Notation : " << sInfix << endl;

	// : 연산자 우선순위
	map<string, int> mapOperatorPriority;
	mapOperatorPriority["("] = 0;
	mapOperatorPriority["*"] = 2;
	mapOperatorPriority["/"] = 2;
	mapOperatorPriority["+"] = 1;
	mapOperatorPriority["-"] = 1;
	// 닫는 괄호는 만나는 순간 모두 제거되므로 필요 x

	vector<string> vecPostFixQueue;
	vector<string> vecOperatorStack;

	int nIndex = 0;
	while (nIndex < sInfix.length())
	{
		string sToken = GetToken(sInfix, nIndex);
		if (IsOperand(sToken))	// 피연산자
		{
			vecPostFixQueue.push_back(sToken);
		}
		else // 연산자
		{
			if (sToken == "(")
			{
				vecOperatorStack.push_back(sToken);
			}
			else if (sToken == ")")
			{
				while (1)
				{
					string sTop = vecOperatorStack.back();
					vecOperatorStack.pop_back();

					if (sTop == "(")
						break;
					else
						vecPostFixQueue.push_back(sTop);
				}
			}
			else
			{
				int nPriority = mapOperatorPriority[sToken];	// 연산자 우선순위 저장
				while (1)
				{
					string sTop = vecOperatorStack.back();

					if (mapOperatorPriority[sTop] < nPriority)
						break;
					vecPostFixQueue.push_back(sTop);
					vecOperatorStack.pop_back();
				}
				vecOperatorStack.push_back(sToken);
			}	// << else
		} // <<  < : if else
	}	// while

	cout << "Postfix Notation : " ;
	for (int i = 0; i < vecPostFixQueue.size(); ++i)
	{
		cout << vecPostFixQueue[i] << " ";
	}

	cout << endl;

	// 실질적인 계산
	vector<float> vecOperandStack;
	for (size_t i = 0; i < vecPostFixQueue.size(); ++i)
	{
		if (IsOperand(vecPostFixQueue[i]))
		{
			float f = (float)atof(vecPostFixQueue[i].c_str());
			vecOperandStack.push_back(f);
		}
		else
		{
			float f2 = vecOperandStack.back();
			vecOperandStack.pop_back();
			float f1 = vecOperandStack.back();
			vecOperandStack.pop_back();

			if (vecPostFixQueue[i] == "+")
			{
				vecOperandStack.push_back(f1 + f2);
			}
			else if (vecPostFixQueue[i] == "-")
			{
				vecOperandStack.push_back(f1 - f2);
			}
			else if (vecPostFixQueue[i] == "*")
			{
				vecOperandStack.push_back(f1 * f2);
			}
			else if (vecPostFixQueue[i] == "/")
			{
				vecOperandStack.push_back(f1 / f2);
			}	// << :  else if
		}	 // << < :  if else
	}	// << < :  for

	cout << "계산결과 : " << vecOperandStack.front() << endl;

	return 0;
}