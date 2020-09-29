// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <assert.h> // ��� ���õ� ���
// ���� �ǹ����� �̸� �� �־�α� x

using namespace std;

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;

#define SafeRelease(p) { if(p) p->Release(); p = NULL; }	// �������̽� ����

#define SafeDelete(p)	{ if(p) delete p; } // ���� ����

// >>
#define SingleTone(class_name)\
	private :\
		class_name(void);\
		~class_name(void);\
	public:\
		static class_name* GetInstance()\
		{\
			static class_name instance;\
			return &instance;\
		}
// �ڵ����� �̱��� �����ϴ� ��ũ�� 

struct stPC_Vertex	// point, color
{
	D3DXVECTOR3 p;
	D3DCOLOR c;

	enum { eFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };	// �� ǥ�� ����
};

struct stPNT_Vertext
{
	D3DXVECTOR3 p;	// Point
	D3DXVECTOR3 n;	// Normal 
	D3DXVECTOR2 t;	// Texture

	enum { eFVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };	// �� ǥ�� ����
};

#define Synthesize(varType, varName, funName) \
protected : varType varName; \
public : inline varType Get##funName(void) const { return varName; } \
public : inline void Set##funName(varType var) { varName = var; }
// ## : �Լ� �̸�(funName)
// >> GET, SET �Լ� ��ũ��

#define Synthesize_pass_by_Ref(varType, varName, funName) \
protected : varType varName; \
public : inline varType& Get##funName(void) { return varName; } \
public : inline void Set##funName(varType& var) { varName = var; }
// >> GET, SET �Լ� ��ũ��

#include "cDeviceManager.h"

// <<