#pragma once

class CSceneState;

#define g_pGameManager CGameManager::GetInstance()

enum SceneType : int
{
	eMainScene, eGameScene, ePauseScene, eEndScene
};

class CGameManager
{
private:
	CSceneState* m_nowScene;
	CGameManager() { }

public:
	static CGameManager* GetInstance();
	virtual ~CGameManager();

	void CheckSceneChange(SceneType input);
	void CheckNullScene();

	void Destroy();
};

