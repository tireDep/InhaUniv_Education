#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
{
	playerScene = eStartScene;
}

GameManager::~GameManager()
{

}

GameManager* GameManager::GetInstance()
{
	static GameManager gameManger;
	return &gameManger;
}

void GameManager::SetSceneNum(int setNum)
{
	playerScene = setNum;
}

int GameManager::GetSceneNum()
{
	return playerScene;
}