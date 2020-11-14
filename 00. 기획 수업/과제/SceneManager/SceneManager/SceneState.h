#pragma once
#include "GameManager.h"

class CSceneState
{
protected:
	CSceneState() { }

public:
	virtual ~CSceneState() { }
	static CSceneState* GetInstance();
	static CSceneState* SetScene(SceneType type);
	virtual void SetNowScene() { }
	virtual void PrintState() { }
};
