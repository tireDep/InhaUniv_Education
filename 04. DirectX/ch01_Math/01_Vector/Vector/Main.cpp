#include <iostream>
#include "cVector.h"

using namespace std;

int main()
{
	cVector3 temp;
	cVector3 uVec(1,-1,0);
	cVector3 vVec(3,2,1);

	if (uVec == vVec)
		cout << "µŒ ∫§≈Õ ∫Ò±≥ : " << "µŒ ∫§≈Õ∞° ∞∞¿Ω" << endl << endl;
	else
		cout << "µŒ ∫§≈Õ ∫Ò±≥ : " << "µŒ ∫§≈Õ∞° ∞∞¡ˆ x" << endl << endl;
	// >> ∫§≈Õ ∫Ò±≥

	temp = uVec + vVec;
	cout <<"Vector + : ";
	temp.PrintValue();
	cout << endl;
	// >> ∫§≈Õ µ°º¿

	cout << "Dot Product : " << uVec.Dot(uVec, vVec) << endl << endl;
	// >> ∫§≈Õ ≥ª¿˚

	temp = uVec.Cross(uVec, vVec);
	cout << "Cross Product : ";
	temp.PrintValue();
	cout << endl;
	// >> ∫§≈Õ ø‹¿˚
}