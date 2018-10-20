#pragma once

#include "macros.h"
#include "ztypes.h"


class zCSyncObject
{
public:
	enum
	{ 
		zTIME_OUT_INFINITE = INFINITE			
	};
	virtual ~zCSyncObject() {};						
	virtual BOOL Lock(DWORD dwMilliseconds) = 0;	
	virtual BOOL Unlock() = 0;						
};



class zCMutex : public zCSyncObject
{
public:

	virtual ~zCMutex()
	{
		XCALL(0x005F95B0);
	};

	virtual int Lock(unsigned long)
	{
		XCALL(0x005F95E0);
	};

	virtual int Unlock(void)
	{
		XCALL(0x005F9600);
	};
private:
	HANDLE				mutex;
};



class zCCriticalSection : public zCSyncObject
{
public:
	zCCriticalSection(void)
	{
		XCALL(0x005F93E0);
	};

	virtual ~zCCriticalSection()
	{
		XCALL(0x005F9420);
	};

	virtual int Lock(unsigned long)
	{
		XCALL(0x005F9460);
	};

	virtual int Unlock(void)
	{
		XCALL(0x005F9480);
	};

private:
	CRITICAL_SECTION	criticalSection;
};

class zCThread
{
public:
	enum zTThread_Prio
	{	zTHREAD_PRIORITY_TIME_CRITICAL	= THREAD_PRIORITY_TIME_CRITICAL,
		zTHREAD_PRIORITY_HIGHEST		= THREAD_PRIORITY_HIGHEST,
		zTHREAD_PRIORITY_ABOVE_NORMAL	= THREAD_PRIORITY_ABOVE_NORMAL,
		zTHREAD_PRIORITY_NORMAL			= THREAD_PRIORITY_NORMAL,
		zTHREAD_PRIORITY_BELOW_NORMAL	= THREAD_PRIORITY_BELOW_NORMAL,
		zTHREAD_PRIORITY_LOWEST			= THREAD_PRIORITY_LOWEST,
		zTHREAD_PRIORITY_IDLE			= THREAD_PRIORITY_IDLE
	};
	zCThread(void)
	{
		XCALL(0x005F9160);
	};

	void SleepThread(unsigned long)
	{
		XCALL(0x005F93D0);
	};

	virtual ~zCThread()
	{
		XCALL(0x005F91E0);
	};

	virtual void BeginThread(void)
	{
		XCALL(0x005F9230);
	};

	virtual void EndThread(void)
	{
		XCALL(0x005F9330);
	};

	virtual int IsThreadRunning(void)
	{
		XCALL(0x005DC950);
	};

	virtual int SuspendThread(void)
	{
		XCALL(0x005F9370);
	};

	virtual int ResumeThread(void)
	{
		XCALL(0x005F93A0);
	};

	virtual int GetTerminationRequested(void)const 
	{
		XCALL(0x005DC960);
	};

	virtual void SetTerminationRequested(int)
	{
		XCALL(0x005DC970);
	};

	virtual unsigned long ThreadProc(void)
	{
		XCALL(0x005F9320);
	};
private:
	HANDLE			threadHandle;
	unsigned int	threadID;
	int				suspendCount;
	BOOL			isThreadRunning;
	BOOL			terminationRequested;
};