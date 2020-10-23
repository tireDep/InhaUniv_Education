#include <iostream>
#include "Singleton.h"
#include "SingletonObj.h"

#include "Collegue.h"
#include "ConcreteMediator.h"

using namespace std;

int main()
{
	// CSingletonObj* cSObj = CSingletonObj::GetInstance();
	// cSObj->PrintSuccess();
	// cSObj->SetNumber(5);
	// 
	// CSingletonObj* cSObj2 = CSingletonObj::GetInstance();
	// cSObj2->SetNumber(7);
	// 
	// cSObj->PrintNumber();
	// cSObj2->PrintNumber();
	// // 출력결과 : 7 \n 7

	CCollegueA* cA = new CCollegueA;
	CCollegueB* cB = new CCollegueB;
	CConcreteMediator *mediCenter = new CConcreteMediator();
	mediCenter->AddCollegue(cA);
	mediCenter->AddCollegue(cB);

	cA->DoA();

	delete cA;
	delete cB;
	delete mediCenter;

	return 0;
}