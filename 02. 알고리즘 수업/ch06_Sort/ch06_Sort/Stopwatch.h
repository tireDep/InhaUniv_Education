#pragma once

class STOPWATCH_C
{
private:
	float startHour;
	float startMin;
	float startSec;
	float startMs;

	float endHour;
	float endMin;
	float endSec;
	float endMs;


public:
	STOPWATCH_C();
	~STOPWATCH_C();

	void StartTime();
	void EndTime();

	float GetElapsedTime();
};