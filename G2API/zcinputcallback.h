#pragma once

#include "ztypes.h"

class zCInputCallback
{
public:
	virtual int HandleEvent(int)
	{
		XCALL(0x0043D4E0);
	};

	zCInputCallback(void)
	{
		XCALL(0x007A53F0);
	};

	~zCInputCallback(void)
	{
		XCALL(0x007A5400);
	};

	void SetHandleEventTop(void)
	{
		XCALL(0x007A5470);
	};

	void SetEnableHandleEvent(int)
	{
		XCALL(0x007A54E0);
	};

	int GetEnableHandleEvent(void)
	{
		XCALL(0x007A5560);
	};

	static int DoEvents(int)
	{
		XCALL(0x007A5590);
	};

	static void GetInput(void)
	{
		XCALL(0x007A55C0);
	};
};

