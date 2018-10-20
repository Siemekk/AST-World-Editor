#pragma once

#include "zCObject.h"
#include "zThread.h"

class zCResource;


enum zTResourceCacheState : BYTE
{
	zRES_STATE_UNLOADED,			
	zRES_STATE_WAITING_FOR_LOAD,	
	zRES_STATE_LOADING,				
	zRES_STATE_LOADED				
};

class zCResource : public zCObject
{
	zCResource					*nextRes;
	zCResource					*prevRes;
	DWORD						timeStamp;						
	zCCriticalSection			stateChangeGuard;				
	struct
	{					
		UINT8					cacheState		: 2;			
		UINT8					cacheOutLock	: 1;
		UINT8					cacheClassIndex	: 8;
		UINT8					managedByResMan	: 1;			
		UINT16					cacheInPriority	: 16;			
		UINT8					canBeCachedOut	: 1;
	};
	enum { zMAX_CACHE_IN_PRIO	= 65535 };
public:
	static zCClassDef *classDef;
	zTResourceCacheState CacheIn(float)
	{
		XCALL(0x005C4A50);
	};

	void zResource(void)
	{
		XCALL(0x005DC470);
	};

	zCResource(void)
	{
		zResource();
	};

	void SetCacheInPriority(float)
	{
		XCALL(0x005DC6B0);
	};

	void CacheOut(void)
	{
		XCALL(0x005DC7F0);
	};

	void TouchTimeStamp(void)
	{
		XCALL(0x005DC810);
	};

	void TouchTimeStampLocal(void)
	{
		XCALL(0x005DC890);
	};

	void LockStateChange(void)
	{
		XCALL(0x005DC8A0);
	};

	void UnlockStateChange(void)
	{
		XCALL(0x005DC8B0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005DC610);
	};

	virtual ~zCResource()
	{
		XCALL(0x005DC620);
	};

	virtual int LoadResourceData(void)
	{
		XCALL(0x005DC6E0);
	};

	virtual int ReleaseResourceData(void)
	{
		XCALL(0x005DC7C0);
	};

	virtual unsigned long GetResSizeBytes(void)
	{
		XCALL(0x005DC7D0);
	};

	virtual void GetCacheConfig(unsigned long&,unsigned long&)
	{
		XCALL(0x005DC7E0);
	};
};

