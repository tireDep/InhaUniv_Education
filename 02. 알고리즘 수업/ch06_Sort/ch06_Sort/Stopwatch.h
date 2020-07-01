#pragma once

class STOPWATCH_C
{
private:
	int startHour;
	int startMin;
	int startSec;
	int startMs;

	int endHour;
	int endMin;
	int endSec;
	int endMs;


public:
	STOPWATCH_C();
	~STOPWATCH_C();

	void StartTime();
	void EndTime();

	float GetElapsedTime();
};