#pragma once
#include <iostream>
#include "SceneState.h"

using namespace std;

class CMainState : public CSceneState
{
public:
	CMainState() { }
	~CMainState() { }
	void SetNowScene() override { PrintState(); }
	void PrintState() override { cout << "Main Scene" << endl; }
};

class CGameState : public CSceneState
{
public:
	CGameState() { }
	~CGameState() { }
	void SetNowScene() override { PrintState(); }
	void PrintState() override { cout << "Game Scene" << endl; }
};

class CPauseState : public CSceneState
{
public:
	CPauseState() { }
	~CPauseState() { }
	void SetNowScene() override { PrintState(); }
	void PrintState() override { cout << "Pause Scene" << endl; }
};

class CEndState : public CSceneState
{
public:
	CEndState() { }
	~CEndState() { }
	void SetNowScene() override { PrintState(); }
	void PrintState() override { cout << "End Scene" << endl; }
};


