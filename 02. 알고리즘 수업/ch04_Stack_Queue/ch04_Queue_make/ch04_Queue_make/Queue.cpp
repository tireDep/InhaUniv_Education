#include<iostream>
#include "_Queue.h"

using namespace std;

bool Initalize(QUEUE_S &queue)
{
	int inputNum;
	cout << "������ ���� �Է� : ";
	cin >> inputNum;

	queue.value = new int[inputNum];
	if (queue.value == NULL)
	{
		cout << "error : ������ �Ҵ� ����\n\n";
		return false;
	}
	queue.front = 0;
	queue.rear = 0;
	queue.cnt = 0;
	queue.max = inputNum;

	return true;
}

int GetMax(const QUEUE_S &queue)
{
	return queue.max;
}

int GetCnt(const QUEUE_S &queue)
{
	return queue.cnt;
}

bool IsFull(const QUEUE_S &queue)
{
	if (queue.front == queue.rear && queue.cnt == queue.max)
		return false;
	else
		return true;
}

bool IsEmpty(const QUEUE_S &queue)
{
	if (queue.front == queue.rear && queue.cnt == 0)
		return false;
	else
		return true;
}

bool Enque(QUEUE_S &queue)
{
	int inputData;
	if (!IsFull(queue))
	{
		cout << "Error : ��ť\n\n";
		return false;
	}

	cout << "\n������ �Է� : ";
	cin >> inputData;

	queue.value[queue.rear] = inputData;
	queue.cnt++;
	queue.rear = ++queue.rear % queue.max;
	// �ִ��� �Ѿ�� ����!
	// ex)
	// max = 8, rear�� ���� �� �ִ� ���� 0 ~ 7

	return true;
}

bool Deque(QUEUE_S &queue, int &resultVal)
{
	if (!IsEmpty(queue))
	{
		cout << "Error : ��ť\n\n";
		return false;
	}

	resultVal = queue.value[queue.front];
	queue.cnt--;
	queue.front = ++queue.front % queue.max;
	// �ִ��� �Ѿ�� ����!
	// ex)
	// max = 8, rear�� ���� �� �ִ� ���� 0 ~ 7
	
	return true;
}

bool Peek(const QUEUE_S &queue, int &resultVal)
{
	if (!IsEmpty(queue))
	{
		cout << "Error : ��ũ\n\n";
		return false;
	}

	resultVal = queue.value[queue.front];

	return true;
}

bool Print(const QUEUE_S &queue)
{
	if (!IsEmpty(queue))
	{
		cout << "Error : ���\n\n";
		return false;
	}

	for (int i = 0; i < queue.cnt; i++)
	{
		cout << queue.value[i] << " ";
	}
	return true;
}

void Search(const QUEUE_S &queue)
{
	int searchData;
	cout << "\n�˻��� �� �Է� : ";
	cin >> searchData;

	for (int i = 0; i < queue.cnt; i++)
	{
		if (searchData == queue.value[i])
		{
			cout << "\n�˻���� : " << queue.value[i] << "\n�ε��� : " << i << endl << endl;
			return;
		}
	}

	cout << "\n�˻���� : �ش� ���� �������� ����\n\n";
}

void Clear(QUEUE_S &queue)
{
	for (int i = 0; i < queue.cnt; i++)
	{
		queue.value[i] = 0;
	}
	queue.cnt = 0;
	queue.front = 0;
	queue.rear = 0;
}

void Terminate(QUEUE_S &queue)
{
	delete[] queue.value;
}