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

	POINT GetCenterPos();
	int GetNowDegree();
	int GetAddDegree();
};

class Bullet : public Gun
{
private:
	POINT bulletPos[4];
	POINT tempBulletPos[4];
	POINT centerPos;
	POINT movePos;

	int nowDegree;
	int bulletSpped;

public:
	Bullet();
	Bullet(POINT posLB, POINT posRB, POINT move, POINT _centerPos, int _nowDegree);
	~Bullet();

	void DrawWeapon(HDC hdc);
	void Update(vector<Bullet*> &Bullet, RECT viewRect);

	void MoveBullet(vector<Bullet *> &bullet);
	void CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect);
};