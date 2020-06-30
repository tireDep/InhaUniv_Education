// Q. Stopwatch Class를 설계하라.
// 1) get 함수를 갖는 전용 데이터 필드 startTime과 endTime
// 2) startTime을 현재 시간으로 초기화 하는 인수 없는 생성자
// 3) startTime을 현재 시간으로 재설정하는 start() 함수
// 4) endTime을 현재 시간으로 설정하는 stop()함수
// 5) 스톱워치의 경과 시간을 milliseconde(ms)로 반환하는 getElapsedTime()함수

// 해당 클래스에 대한 UML 다이어그램을 그리고, 버블 정렬과 선택 정렬을 사용하여
// 100,000개의 숫자를 정렬하는데 걸린 실행 시간을 측정 비교하는 프로그램을 작성

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

	std::cout <<"시작시간 : " << startHour << "시 " << startMin << "분 " << startSec << "초" << std::endl;
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

	std::cout << "종료시간 : " << endHour << "시 " << endMin << "분 " << endSec << "초" << std::endl;
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


