#pragma once
#include "stdafx.h"
#include "GroundEatingGame.h"

class GameManager
{
private:
	int nowScene;

public:
	GameManager();
	~GameManager();
	static GameManager* GetInstance();

	void SetSceneNum(int sceneNum);
	int GetSceneNum();


};
