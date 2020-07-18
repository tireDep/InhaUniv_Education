#pragma once

class Weapon
{
private:

public:
	Weapon() { }
	~Weapon() { }

	virtual void DrawWeapon(HDC hdc) = 0;
};

class Gun : public Weapon
{
private:
	POINT barrelPos[4];
	POINT tempbarrelPos[4];
	POINT barrelCenter = { 250, 650 };

	int nowDegree;
	int addDegree;

public:
	Gun();
	~Gun();

	void CheckBarrelPos(int inputKey);
	void MoveBarrel(int inputKey);
	void DrawWeapon(HDC hdc);
};
