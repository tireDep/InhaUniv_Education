#include "stdafx.h"
#include "GameManager.h"
#include "GroundEatingGame.h"


GameManager* GameManager::GetInstance()
{
	static GameManager gameManager;
	return &gameManager;
}

GameManager::GameManager()
{
	nowScene = eStartScene;
}

GameManager::~GameManager()
{

}

void GameManager::SetSceneNum(int sceneNum)
{
	nowScene = sceneNum;
}

int GameManager::GetSceneNum()
{
	return nowScene;
}

