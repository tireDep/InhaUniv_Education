// ������ ���
// ��ã�� �˰��� �� 

// ������ ���ο��� �ð��� �����ɸ��� �۾��� ���� �ȵ�
// ex) ��Ÿũ����Ʈ ��ã��
// ��ã���� ��� ��ã�� ���۰� ���ÿ� ĳ���Ͱ� ������ �ְ� ������
// ������ Ŭ ��� �����ؼ� ��ã�⸦ �Ҽ��� ���� + ���� �濡 ��� �� Ž��
// ���� ������ ��� �� ĳ���͸� ��ã�� ���� �������� ��� ���� -> �Ϸķ� ���� ���

// ���� ����, �����Ҵ� �� ����, 

#include <stdio.h>
#include <process.h>
#include <Windows.h>

int value = 0;	// �־��� ��
int valuePlusOne = 0;	// value + 1

int cnt = 0;	// value > valuePlusOne�� �߻��� ��� üũ�ϴ� �뵵
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThreadFun1(LPVOID lpParam);
DWORD WINAPI ThreadFun2(LPVOID lpParam);

int main()
{
	DWORD dwThID1, dwThID2;
	HANDLE hThread[2];

	unsigned long ulStackSize = 0;

	InitializeCriticalSection(&cs);

	dwThID1 = 0;	dwThID2 = 0;
	hThread[0] = NULL;	hThread[1] = NULL;

	hThread[0] = CreateThread(NULL, ulStackSize, ThreadFun1, NULL, CREATE_SUSPENDED, &dwThID1);
	hThread[1] = CreateThread(NULL, ulStackSize, ThreadFun2, NULL, CREATE_SUSPENDED, &dwThID2);
	// CREATE_SUSPENDED : �����带 �����ϵ�, �ٷ� ���� x

	ResumeThread(hThread[0]);
	ResumeThread(hThread[1]);

	WaitForMultipleObjects(2, hThread, true, INFINITE);	// �����尡 ����� ������ ���α׷��� �����Ű�� x

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
		// �۾��� ����Ǵ� ���� ������� �̵����� ����
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
		// // ����Ī �Ǵ� ������ �� ������ �����Ƿ� �����
		// // �� ������ ���� ���� : �� �߰� �� ����(�� ���� ���)

		// [ Case 1 ]
		// if (isChecked)
		// {
		// 	if (value > valuePlusOne)
		// 		printf("%d\n", cnt++);
		// }
		// �ȵǴ� ��찡 ���� �� ����

		// [ Case 2 ]
		//EnterCriticalSection(&cs);
		if (value > valuePlusOne)
			printf("%d\n", cnt++);
		//LeaveCriticalSection(&cs);
	}
	return 0;
}