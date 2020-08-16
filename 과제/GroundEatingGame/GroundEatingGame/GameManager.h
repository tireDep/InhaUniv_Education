#pragma once
#include "stdafx.h"
#include "GroundEatingGame.h"

class GameManager
{
private:
	int playerScene;

	GameManager();
	~GameManager();

public:
	static GameManager *GetInstance();

	void SetSceneNum(int setNum);
	int GetSceneNum();
};
