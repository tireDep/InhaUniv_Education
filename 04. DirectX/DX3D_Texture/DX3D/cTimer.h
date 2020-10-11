#pragma once
#include "stdafx.h"

class cTimer
{
private:
	LARGE_INTEGER m_CountTime;
	LARGE_INTEGER m_CurTime;
	LARGE_INTEGER m_PrevTime;

	double m_dDeltaTime;
	float m_fDeltaTime;

	cTimer();

public:
	~cTimer();

	static cTimer *GetInstance();

	float DeltaTime()
	{
		return m_fDeltaTime;
	}

	void SetUp()
	{
		QueryPerformanceFrequency(&m_CountTime);
		QueryPerformanceCounter(&m_CurTime);
		QueryPerformanceCounter(&m_PrevTime);
	}

	void Update()
	{
		QueryPerformanceCounter(&m_CurTime);

		m_dDeltaTime = (static_cast<double>(m_CurTime.QuadPart) - static_cast<double>(m_PrevTime.QuadPart)) / static_cast<double>(m_CountTime.QuadPart);

		m_fDeltaTime = static_cast<float>(m_dDeltaTime);
		m_PrevTime = m_CurTime;
	}
};
