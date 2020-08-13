// 스레드 사용
// 길찾기 알고리즘 등 

// 스레드 내부에는 시간이 오래걸리는 작업이 들어가면 안됨
// ex) 스타크래프트 길찾기
// 길찾기의 경우 길찾기 시작과 동시에 캐릭터가 딜레이 있고 움직임
// 지형이 클 경우 분할해서 길찾기를 할수도 있음 + 가는 길에 경로 재 탐색
// 여러 무리일 경우 한 캐릭터만 길찾기 수행 나머지는 경로 공유 -> 일렬로 가는 모양

// CreateThread() 내부에서 랜덤, 정적 버퍼 사용, 메모리 동적할당 등의 작업은 안전하지 않음 => 간단한 작업 or 테스트용으로 사용하는 것이 좋음

#include <stdio.h>
#include <process.h>
#include <Windows.h>

int value = 0;	// 주어질 값
int valuePlusOne = 0;	// value + 1

int cnt = 0;	// value > valuePlusOne가 발생할 경우 체크하는 용도
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThreadFun1(LPVOID lpParam);
DWORD WINAPI ThreadFun2(LPVOID lpParam);

unsigned __stdcall thFunc7(LPVOID lpParam);
unsigned __stdcall thFunc8(LPVOID lpParam);

int main()
{
	DWORD dwThID1, dwThID2;
	HANDLE hThread[2];

	unsigned long ulStackSize = 0;

	InitializeCriticalSection(&cs);

	dwThID1 = 0;	dwThID2 = 0;
	hThread[0] = NULL;	hThread[1] = NULL;

	// hThread[0] = CreateThread(NULL, ulStackSize, ThreadFun1, NULL, CREATE_SUSPENDED, &dwThID1);
	// hThread[1] = CreateThread(NULL, ulStackSize, ThreadFun2, NULL, CREATE_SUSPENDED, &dwThID2);
	// CREATE_SUSPENDED : 스레드를 생성하되, 바로 실행 x

	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall *)(void *))thFunc7, NULL, 0, (unsigned*)&dwThID1);
	hThread[1] = (HANDLE)_beginthreadex(NULL, 0, (unsigned(__stdcall *)(void *))thFunc8, NULL, 0, (unsigned*)&dwThID2);
	// 옵션 존재

	if (hThread[0] == 0 || hThread[1] == 0)
	{
		exit(1);	// 스레드가 생성되지 x
	}

	ResumeThread(hThread[0]);
	ResumeThread(hThread[1]);

	WaitForMultipleObjects(2, hThread, true, INFINITE);	// 스레드가 종료될 때까지 프로그램을 종료시키지 x

	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);

	DeleteCriticalSection(&cs);

	return 0;
}

DWORD WINAPI ThreadFun1(LPVOID lpParam)
{
	while (1)
	{
		// [ Error Case ]
		// value = rand() % 1000;
		// valuePlusOne = value + 1;

		// [ Case 1 ]
		// isChecked = false;
		// value = rand() % 1000;
		// valuePlusOne = value + 1;
		// isChecked = true;

		// [ Case 2 ]
		EnterCriticalSection(&cs);
		value = rand() % 1000;
		valuePlusOne = value + 1;
		LeaveCriticalSection(&cs);
		// 작업이 실행되는 동안 제어권이 이동하지 않음
	}
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID lpParam)
{
	while (1)
	{
		// [ Error Case ]
		// if (value > valuePlusOne)
		// 	printf("%d\n", cnt++);
		// // 스위칭 되는 순간에 값 변동이 있으므로 실행됨
		// // ※ 스레드 사용시 주의 : 값 추가 및 삭제(값 변동 경우)

		// [ Case 1 ]
		// if (isChecked)
		// {
		// 	if (value > valuePlusOne)
		// 		printf("%d\n", cnt++);
		// }
		// 안되는 경우가 나올 수 있음

		// [ Case 2 ]
		EnterCriticalSection(&cs);
		if (value > valuePlusOne)
			printf("%d\n", cnt++);
		LeaveCriticalSection(&cs);
	}
	return 0;
}

unsigned __stdcall thFunc7(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		value = rand() % 1000;
		valuePlusOne = value + 1;
		LeaveCriticalSection(&cs);
	}
	return 0;
}

unsigned __stdcall thFunc8(LPVOID lpParam)
{
	while (1)
	{
		EnterCriticalSection(&cs);
		if (value > valuePlusOne)
			printf("%d\n", cnt++);
		LeaveCriticalSection(&cs);
	}
	return 0;
}