#include "Framework.h"
#include "FreeCam.h"

FreeCam::FreeCam() :
	move(20), 
	rotation(0)
{
}

FreeCam::~FreeCam()
{
}

void FreeCam::Update()
{
	if (Mouse::Get()->Press(1) == false)
		return;

	const Vector3& f = Forward();
	const Vector3& r = Right();
	const Vector3& u = Up();

	Vector3 position;
	Position(&position); // 현재위치 get

	// : forward
	if (Keyboard::Get()->Press('W'))
		position += f * move * Time::Delta();
	else if (Keyboard::Get()->Press('S'))
		position -= f * move * Time::Delta();

	// : right
	if (Keyboard::Get()->Press('A'))
		position -= r * move * Time::Delta();
	else if (Keyboard::Get()->Press('D'))
		position += r * move * Time::Delta();

	// : up
	if (Keyboard::Get()->Press('E'))
		position += u * move * Time::Delta();
	else if (Keyboard::Get()->Press('D'))
		position -= u * move * Time::Delta();

	Position(position); // : set
}

void FreeCam::Speed(float move, float rotation)
{
	this->move = move;
	this->rotation = rotation;
}
