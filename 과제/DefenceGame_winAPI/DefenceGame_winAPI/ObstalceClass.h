#pragma once
#include"stdafx.h"
#include"DefenceGame_winAPI.h"

class Obstacle
{
private:
	int spinCnt;

public:
	Obstacle() : spinCnt(0) { }
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

	virtual int GetBlockPos(int i, int check) = 0;
	virtual void SetBlockPos(int i, int check, int val) = 0;
	virtual void SetHitFlag() = 0;
	virtual bool GetHitFlag() = 0;

	void SetSpinCnt()
	{
		spinCnt++;
	}

	int GetSpinCnt()
	{
		return spinCnt;
	}

	virtual void SetDownSpeed(int speed) = 0;

};	

class Block : public Obstacle
{
private:
	// RECT blockPos;
	POINT blockPos[4];
	RECT hitCheckPos;
	POINT centerPos;

	int radius;
	int downSpeed;

	bool isHit;

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

	int GetBlockPos(int i, int check)
	{
		if (check == 0)
			return blockPos[i].x;
		if (check == 1)
			return blockPos[i].y;
	}


	void SetBlockPos(int i, int check, int val)
	{
		if (check == 0)
			blockPos[i].x = val;
		else if (check == 1)
			blockPos[i].y = val;
	}
	
	void SetHitFlag()
	{
		isHit = TRUE;
	}

	bool GetHitFlag()
	{
		return isHit;
	}

	void SetDownSpeed(int speed)
	{
		downSpeed = speed;
	}

};
