#include "GameManager.h"
#include "SceneState.h"
#include "State.h"

CGameManager * CGameManager::GetInstance()
{
	static CGameManager instance;
	return &instance;
}

CGameManager::~CGameManager() { }

void CGameManager::CheckSceneChange(SceneType input)
{
	// >> 1
	CheckNullScene();
	m_nowScene = CSceneState::SetScene(input);
	m_nowScene->PrintState();

	// // >> 2
	// switch (input)
	// {
	// 	case eMainScene:
	// 	{
	// 		CheckNullScene();
	// 		m_nowScene = new CMainState;
	// 		m_nowScene->SetNowScene();
	// 	}
	// 	break;
	// 
	// 	case eGameScene:
	// 	{
	// 		CheckNullScene();
	// 		m_nowScene = new CGameState;
	// 		m_nowScene->SetNowScene();
	// 	}
	// 	break;
	// 
	// 	case ePauseScene:
	// 	{
	// 		CheckNullScene();
	// 		m_nowScene = new CPauseState;
	// 		m_nowScene->SetNowScene();
	// 	}
	// 	break;
	// 
	// 	case eEndScene:
	// 	{
	// 		CheckNullScene();
	// 		m_nowScene = new CEndState;
	// 		m_nowScene->SetNowScene();
	// 	}
	// 	break;
	// }
}

void CGameManager::CheckNullScene()
{
	if (m_nowScene != NULL)
		delete m_nowScene;
}

void CGameManager::Destroy()
{
	if (m_nowScene)
		delete m_nowScene;
}
