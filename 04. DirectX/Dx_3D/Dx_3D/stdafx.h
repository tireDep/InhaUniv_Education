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
#include <assert.h> // 경고에 관련된 헤더
// 실제 실무에선 미리 다 넣어두기 x

using namespace std;

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;

#define SafeRelease(p) { if(p) p->Release(); p = NULL; }	// 인터페이스 해제

#define SafeDelete(p)	{ if(p) delete p; } // 실제 삭제

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
// 자동으로 싱글턴 생성하는 매크로 

struct stPC_Vertex	// point, color
{
	D3DXVECTOR3 p;
	D3DXCOLOR c;

	enum { eFVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };	// 색 표현 정의
};

#include "cDeviceManager.h"

// <<