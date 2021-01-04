#include "SceneState.h"
#include "State.h"

CSceneState * CSceneState::GetInstance()
{
	static CSceneState instance;
	return &instance;
}

CSceneState* CSceneState::SetScene(SceneType type)
{
	switch (type)
	{
	case eMainScene:
		return new CMainState();
		break;

	case eGameScene:
		return new CGameState();
		break;

	case ePauseScene:
		return new CPauseState();
		break;

	case eEndScene:
		return new CEndState();
		break;
	}
}
