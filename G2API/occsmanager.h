#pragma once

#include "zccscutscene.h"

class oCCSManager : public zCCSManager		
{
public:
	static zCClassDef* classDef;

	void oCSManager(void)
	{
		XCALL(0x00401600);
	};

	oCCSManager(void)
	{
		oCSManager();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004022C0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0041B250);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0041B4A0);
	};

	virtual ~oCCSManager()
	{
		XCALL(0x00402360);
	};

	virtual zCEventMessage* CreateMessage(int)
	{
		XCALL(0x00402420);
	};

	virtual zCEventMessage* CreateOuMessage(void)
	{
		XCALL(0x00402410);
	};

	virtual zCCSPlayer* CreateCutscenePlayer(zCWorld*)
	{
		XCALL(0x00402370);
	};

	virtual zCCSProps* CreateProperties(void)
	{
		XCALL(0x00402B10);
	};

	virtual void RemoveCutscenePlayer(zCCSPlayer*)
	{
		XCALL(0x0041A6B0);
	};

	virtual int LibIsLoaded(void)
	{
		XCALL(0x0041C410);
	};

	virtual zCCSBlock* LibGet(int)
	{
		XCALL(0x0041BF20);
	};

	virtual zCCSBlock* LibGetFirst(int&)
	{
		XCALL(0x0041BE50);
	};

	virtual zCCSBlock* LibGetFirst(void)
	{
		XCALL(0x0041BDA0);
	};

	virtual zCCSBlock* LibGetNext(int&)
	{
		XCALL(0x0041BEC0);
	};

	virtual zCCSBlock* LibGetNext(void)
	{
		XCALL(0x0041BE00);
	};

	virtual int LibAddOU(zCCSBlock*)
	{
		XCALL(0x0041BF50);
	};

	virtual void LibDelOU(int)
	{
		XCALL(0x0041BF70);
	};

	virtual void LibNullOU(int)
	{
		XCALL(0x0041BF90);
	};

	virtual void LibLoad(int)
	{
		XCALL(0x0041B700);
	};

	virtual void LibStore(int)
	{
		XCALL(0x0041BFB0);
	};

	virtual int LibValidateOU(zSTRING&)
	{
		XCALL(0x0041C3E0);
	};

	virtual int LibValidateOU(int)
	{
		XCALL(0x0041C3B0);
	};

	virtual zSTRING LibGetSvmModuleName(int)
	{
		XCALL(0x00419BC0);
	};

	virtual int LibIsSvmModuleRunning(int)
	{
		XCALL(0x00419E80);
	};

	virtual int LibSvmModuleStart(int)
	{
		XCALL(0x00419FC0);
	};

	virtual int LibSvmModuleStop(int)
	{
		XCALL(0x0041A160);
	};

	virtual void InsertPlayerInList(zCCSPlayer*)
	{
		XCALL(0x0041A6C0);
	};

	virtual void RemovePlayerFromList(zCCSPlayer*)
	{
		XCALL(0x0041A7A0);
	};

	virtual void LibCheckLoaded(int)
	{
		XCALL(0x0041BD80);
	};

	virtual zCCSPoolItem* PoolFindItem(zSTRING&)
	{
		XCALL(0x0041AD50);
	};

	virtual void PoolInsertItem(zCCSPoolItem*)
	{
		XCALL(0x0041AC70);
	};

};

