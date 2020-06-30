// Q. Stopwatch Class�� �����϶�.
// 1) get �Լ��� ���� ���� ������ �ʵ� startTime�� endTime
// 2) startTime�� ���� �ð����� �ʱ�ȭ �ϴ� �μ� ���� ������
// 3) startTime�� ���� �ð����� �缳���ϴ� start() �Լ�
// 4) endTime�� ���� �ð����� �����ϴ� stop()�Լ�
// 5) �����ġ�� ��� �ð��� milliseconde(ms)�� ��ȯ�ϴ� getElapsedTime()�Լ�

// �ش� Ŭ������ ���� UML ���̾�׷��� �׸���, ���� ���İ� ���� ������ ����Ͽ�
// 100,000���� ���ڸ� �����ϴµ� �ɸ� ���� �ð��� ���� ���ϴ� ���α׷��� �ۼ�

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<ctime>
#include"Stopwatch.h"

STOPWATCH_C::STOPWATCH_C()
{
	time_t tTime;
	struct tm *t;

	tTime = time(NULL);
	t = localtime(&tTime);

	startHour = t->tm_hour;
	startMin= t->tm_min;
	startSec = t->tm_sec;
}

STOPWATCH_C::~STOPWATCH_C()
{

}


void STOPWATCH_C::StartTime() 
{
	time_t tTime;
	struct tm *t;

	tTime = time(NULL);
	t = localtime(&tTime);

	startHour = t->tm_hour;
	startMin = t->tm_min;
	startSec = t->tm_sec;

	std::cout <<"���۽ð� : " << startHour << "�� " << startMin << "�� " << startSec << "��" << std::endl;
}

void STOPWATCH_C::EndTime()
{
	time_t tTime;
	struct tm *t;

	tTime = time(NULL);
	t = localtime(&tTime);

	endHour = t->tm_hour;
	endMin = t->tm_min;
	endSec = t->tm_sec;

	std::cout << "����ð� : " << endHour << "�� " << endMin << "�� " << endSec << "��" << std::endl;
}

float STOPWATCH_C::GetElapsedTime()
{
	int timeGap = -1;
	while (1)
	{
		timeGap++;
		if (startMin + timeGap == endMin)
			break;
	}

	endSec += 60 * timeGap;

	return abs(endSec - startSec);
}


