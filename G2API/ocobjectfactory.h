#pragma once

#include "ztypes.h"

#include "ocnpc.h"
#include "ocitem.h"
#include "zcworld.h"

class zFILE;
class zCGameInfo;
class zCPlayerInfo;
class zCWaypoint;
class zCWay;
class zCCSManager;
class zCNetVobControl;

class zCObjectFactory : public zCObject
{
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00426C80);
	};

	virtual ~zCObjectFactory()
	{
		XCALL(0x00426CB0);
	};

	virtual zCEventManager* CreateEventManager(zCVob*)
	{
		XCALL(0x005AB9B0);
	};

	virtual zFILE* CreateZFile(zSTRING const&)
	{
		XCALL(0x005AB940);
	};

	virtual zCSession* CreateSession(void)
	{
		XCALL(0x005ABDD0);
	};

	virtual zCCSManager* CreateCSManager(void)
	{
		XCALL(0x005ABE30);
	};

	virtual zCNetVobControl* CreateNetVobControl(zCVob*)
	{
		XCALL(0x005ABB30);
	};

	virtual zCGameInfo* CreateGameInfo(void)
	{
		XCALL(0x00426C90);
	};

	virtual zCPlayerInfo* CreatePlayerInfo(void)
	{
		XCALL(0x00426CA0);
	};

	virtual zCWorld* CreateWorld(void)
	{
		XCALL(0x005ABEF0);
	};

	virtual zCWaypoint* CreateWaypoint(void)
	{
		XCALL(0x005ABC00);
	};

	virtual zCWay* CreateWay(void)
	{
		XCALL(0x005ABD70);
	};
};


class oCObjectFactory : public zCObjectFactory
{
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00426A70);
	};

	virtual ~oCObjectFactory()
	{
		XCALL(0x00426C70);
	};

	virtual zCEventManager* CreateEventManager(zCVob*)
	{
		XCALL(0x0076FB20);
	};

	virtual zFILE* CreateZFile(zSTRING const&)
	{
		XCALL(0x005AB940);
	};

	virtual zCSession* CreateSession(void)
	{
		XCALL(0x005ABDD0);
	};

	virtual zCCSManager* CreateCSManager(void)
	{
		XCALL(0x0076FB80);
	};

	virtual zCNetVobControl* CreateNetVobControl(zCVob*)
	{
		XCALL(0x005ABB30);
	};

	virtual zCGameInfo* CreateGameInfo(void)
	{
		XCALL(0x0076FBE0);
	};

	virtual zCPlayerInfo* CreatePlayerInfo(void)
	{
		XCALL(0x0076FC40);
	};

	virtual zCWorld* CreateWorld(void)
	{
		XCALL(0x0076FCA0);
	};

	virtual zCWaypoint* CreateWaypoint(void)
	{
		XCALL(0x0076FEA0);
	};

	virtual zCWay* CreateWay(void)
	{
		XCALL(0x0076FF00);
	};

	virtual oCNpc* CreateNpc(int)
	{
		XCALL(0x0076FD20);
	};

	virtual oCItem* CreateItem(int)
	{
		XCALL(0x0076FDE0);
	};
	// [AST]
	virtual oCNpc* CreateNpc_AST(int);
	// [/AST]
};
