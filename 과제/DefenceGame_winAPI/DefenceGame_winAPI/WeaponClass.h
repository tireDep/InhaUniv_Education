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

	POINT GetBarrelPos0();
	POINT GetBarrelPos1();
	int GetNowDegree();
	int GetAddDegree();
};

class Bullet : public Gun
{
private:
	POINT bulletPos;
	POINT tempBulletPos[4];
	POINT centerPos;
	POINT movePos;

	int nowDegree;
	int bulletSpped;
	int radius;

public:
	Bullet();
	Bullet(POINT _BarrelPos1, POINT _BarrelPos2, int degree);
	~Bullet();

	void DrawWeapon(HDC hdc);
	void Update(vector<Bullet*> &bullet, RECT viewRect);

	void MoveBullet(vector<Bullet *> &bullet);
	void CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect);

	double GetCenterPosX();
	double GetCenterPosY();
	int GetRadius();
};