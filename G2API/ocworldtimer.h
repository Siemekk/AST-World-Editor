#pragma once

#include "ztypes.h"


class oCWorldTimer
{
private:
	float	worldTime;
	int		day;
public:
	
	
	int GetDay(void)
	{
		XCALL(0x00780DD0)
	};

	
	
	float GetFullTime(void)
	{
		XCALL(0x00780E80)
	};

	
	
	void GetTime(int & p1, int & p2)
	{
		XCALL(0x00780DF0)
	};

	
	
	zSTRING GetTimeString(void)
	{
		XCALL(0x00780EC0)
	};

	
	
	int IsDay(void)
	{
		XCALL(0x00781280)
	};

	
	
	int IsLater(int p1, int p2)
	{
		XCALL(0x00781110)
	};

	
	
	int IsLaterEqual(int p1, int p2)
	{
		XCALL(0x00781150)
	};

	
	
	int IsNight(void)
	{
		XCALL(0x00781300)
	};

	
	
	int IsTimeBetween(int p1, int p2, int p3, int p4)
	{
		XCALL(0x00781190)
	};

	
	
	void SetDay(int p1)
	{
		XCALL(0x00780DE0)
	};

	
	
	void SetFullTime(float p1)
	{
		XCALL(0x00780E90)
	};

	
	
	void SetTime(int p1, int p2)
	{
		XCALL(0x00780E40)
	};

	
	
	void Timer(void)
	{
		XCALL(0x00780D80)
	};

	
	
	oCWorldTimer(void)
	{
		XCALL(0x00780D60)
	};
};


