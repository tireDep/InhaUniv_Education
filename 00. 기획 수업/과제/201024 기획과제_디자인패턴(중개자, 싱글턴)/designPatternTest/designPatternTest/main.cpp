#include <iostream>
#include "Singleton.h"
#include "SingletonObj.h"

#include "Collegue.h"
#include "ConcreteMediator.h"

#include "Observer.h"
#include "Observer2.h"

using namespace std;

int main()
{
	// Singleton
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
	}

	// Mediator
	{
		// CCollegueA* cA = new CCollegueA;
		// CCollegueB* cB = new CCollegueB;
		// CConcreteMediator *mediCenter = new CConcreteMediator();
		// mediCenter->AddCollegue(cA);
		// mediCenter->AddCollegue(cB);
		// 
		// cA->DoA();
		// 
		// delete cA;
		// delete cB;
		// delete mediCenter;
	}


	Subject subj;
	DivObserver divObs1(&subj, 4); // 7. Client configures the number and
	DivObserver divObs2(&subj, 3); //    type of Observers
	ModObserver modObs3(&subj, 3);
	subj.SetVal(14);

	// SensorSystem ss;
	// ss.Attach(&Gates());
	// ss.Attach(&Lighting());
	// ss.Attach(&Surveillance());
	// ss.SoundTheAlarm();

	return 0;
}