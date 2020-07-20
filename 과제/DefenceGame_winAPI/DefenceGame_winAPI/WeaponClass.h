#pragma once

class Obstacle;	// Update() 용 전방선언

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
	static int bulletCnt;
	int radius;

public:
	Bullet();
	Bullet(POINT _centerPos, int _nowDegree);
	~Bullet();

	void DrawWeapon(HDC hdc);
	void Update(vector<Bullet*> &bullet, vector<vector<Obstacle *>> &obstacle, RECT viewRect);

	void MoveBullet(vector<Bullet *> &bullet);
	void CheckBulletOutScreen(vector<Bullet *> &bullet, RECT viewRect);

	int GetBulletCnt();
	double GetCenterPosX()
	{
		return (bulletPos[0].x + bulletPos[1].x) / 2;
	}
	double GetCenterPosY()
	{
		return (bulletPos[1].y + bulletPos[2].y) / 2;
	}
	int GetRadius()
	{
		return radius;
	}

	//POINT GetBulletPosLT()
	//{
	//	return bulletPos;
	//}
};