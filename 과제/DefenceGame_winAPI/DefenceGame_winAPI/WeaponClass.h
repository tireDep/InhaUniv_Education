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

	POINT GetBarrelPosLB();
	POINT GetBarrelPosRB();
};

class Bullet : public Gun
{
private:
	POINT bulletPos[2];
	POINT movePos;

public:
	Bullet();
	Bullet(POINT pos1, POINT pos2, POINT move);
	~Bullet();

	void DrawWeapon(HDC hdc);
};