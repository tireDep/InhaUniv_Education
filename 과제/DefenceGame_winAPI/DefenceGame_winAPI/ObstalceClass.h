#pragma once
#include"stdafx.h"
#include"DefenceGame_winAPI.h"

class Obstacle
{
private:

public:
	Obstacle() 
	{

	}

	Obstacle(int left, int top, int right, int bottom){ }

	~Obstacle() {}

	virtual void Update(vector<vector<Obstacle *>> &obstacle, int &_loseHpPoint) = 0;
	virtual void CheckHitDeadLine(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int linePos) = 0;
	virtual void CheckLoseHp(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int &_loseHpPoint, int linePos) = 0;

	virtual void DrawObstacle(HDC hdc) = 0;
	virtual void DownObstacle() = 0;
	virtual bool CheckDeadLine() = 0;

	virtual int GetRadius() = 0;
	virtual double GetCenterPosX() = 0;
	virtual double GetCenterPosY() = 0;
};	

class Block : public Obstacle
{
private:
	RECT blockPos;
	RECT hitCheckPos;
	POINT centerPos;

	int radius;
	int downSpeed;

public:
	Block();
	Block(int left, int top, int right, int bottom, int _downSpeed);
	~Block();

	void DrawObstacle(HDC hdc);
	void DownObstacle();
	bool CheckDeadLine();

	void Update(vector<vector<Obstacle *>> &obstacle, int &_loseHpPoint);
	void CheckHitDeadLine(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int linePos);
	void CheckLoseHp(vector<vector<Obstacle *>> &obstacle, int &hitCnt, int &_loseHpPoint, int linePos);
	
	double GetCenterPosX();
	double GetCenterPosY();
	int GetRadius();
};
