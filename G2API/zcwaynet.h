#pragma once

#include "ztypes.h"
class oCMobDoor;
class oCMobLadder;

class zCVobWaypoint : public zCVob
{
public:
	static zCClassDef *classDef;
	void zVobWaypoint(void)
	{
		XCALL(0x007ACBC0);
	};

	zCVobWaypoint(void)
	{
		zVobWaypoint();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x007ACBE0);
	};

	virtual ~zCVobWaypoint(void)
	{
		XCALL(0x007ACC20);
	};
};

class zCVobSpot : public zCVob
{
	float		m_fUseTime;
	zCVob*		m_pUsedVob;
public:
	static zCClassDef *classDef;
	void zVobSpot(void)
	{
		XCALL(0x007B2FA0);
	};

	zCVobSpot(void)
	{
		zVobSpot();
	};

	int IsAvailable(zCVob*)
	{
		XCALL(0x007B3020);
	};

	void MarkAsUsed(float,zCVob*)
	{
		XCALL(0x007B31A0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x007B2FC0);
	};

	virtual ~zCVobSpot(void)
	{
		XCALL(0x007B3000);
	};
};

class zCVobStartpoint : public zCVob
{
public:
	static zCClassDef *classDef;
};

class zCRoute
{
public:
	zCList<zCWay>	m_lstWay;
	zCWaypoint*		m_pCurrentWp;
	zCWaypoint*		m_pTargetWp;
	zCWay*			m_pWay;
	zCList<zCWay>*	m_pNextWayList;
	zCRoute(void)
	{
		XCALL(0x007B2860);
	};

	void SetStart(zCWaypoint*)
	{
		XCALL(0x007B28E0);
	};

	zCWaypoint* GetNextWP(void)
	{
		XCALL(0x007B28F0);
	};

	zCWaypoint* GetTargetWP(void)
	{
		XCALL(0x007B2960);
	};

	zCWay* GetCurrentWay(void)
	{
		XCALL(0x007B2970);
	};

	zSTRING GetDesc(void)
	{
		XCALL(0x007B2980);
	};

	zSTRING GetRemainingDesc(void)
	{
		XCALL(0x007B2B60);
	};

	int GetNumberOfWaypoints(void)
	{
		XCALL(0x007B2D40);
	};

	int IsEmpty(void)
	{
		XCALL(0x007B2D60);
	};

	int IsLastTarget(void)
	{
		XCALL(0x007B2D80);
	};

	int GetInterpolatedPosition(float,int,zVEC3&)
	{
		XCALL(0x007B2DA0);
	};

	virtual ~zCRoute()
	{
		XCALL(0x007B28A0);
	};
};

class zCWay
{
public:
	int				m_nDistance;
	int				m_nWayIndex;
	float			m_fChasm;
	int				us10;
	BOOL			m_bCanJump;
	zCWaypoint*		m_pWpStart;
	zCWaypoint*		m_pWpEnd;
	zCWay(void)
	{
		XCALL(0x007AE830);
	};

	zCWay(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AE890);
	};

	void Free(void)
	{
		XCALL(0x007AE9E0);
	};

	zCWaypoint* GetGoalWaypoint(zCWaypoint*)
	{
		XCALL(0x007AEA90);
	};

	void EstimateCost(void)
	{
		XCALL(0x007AEAA0);
	};

	float GetLength(void)
	{
		XCALL(0x007AEB10);
	};

	float GetJumpDistance(void)
	{
		XCALL(0x007AEBC0);
	};

	zVEC3 GetDistancePos(float,zCWaypoint*)
	{
		XCALL(0x007AEC80);
	};

	void Draw(zCCamera*)
	{
		XCALL(0x007AED90);
	};

	zVEC3 GetFloor(zCWorld*,zVEC3 const&)
	{
		XCALL(0x007AF270);
	};

	virtual ~zCWay()
	{

	};

	virtual void Init(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AE940);
	};

	virtual void CalcProperties(zCWorld*)
	{
		XCALL(0x007AF310);
	};

	virtual float GetChasm(void)
	{
		XCALL(0x007AF600);
	};

	virtual int CanJump(void)
	{
		XCALL(0x007AF610);
	};

	virtual int CanBeUsed(zCVob const*)
	{
		XCALL(0x007AED80);
	};

	virtual int IsObjectOnWay(zCVob const*)
	{
		XCALL(0x007AE850);
	};
};

class zCWaypoint : public zCObject		
{
public:
	int					m_nWayIndex;	
	int					m_nDistToNext;	
	int					m_nDistToEnd;	
	int					m_nDistance;	
	int					m_nRouteType;	
	zCWay*				m_pWay;			
	int					m_nWaterDepth;	
	BOOL				m_bUnderWater;	
	zVEC3				m_vPosition;	
	zVEC3				m_vDirection;	
	zSTRING				m_sWpName;		
	zCVob*				m_pVob;			
	zCList<zCWay>		m_lstWays;		
	static zCClassDef *classDef;
	void zWaypoint(void)
	{
		XCALL(0x007AF770);
	};

	zCWaypoint(void)
	{
		zWaypoint();
	};

	void Init(zVEC3&)
	{
		XCALL(0x007AF8A0);
	};

	void Init(float,float,float)
	{
		XCALL(0x007AF900);
	};

	void Init(zCVobWaypoint*)
	{
		XCALL(0x007AF970);
	};

	void Free(void)
	{
		XCALL(0x007AFA10);
	};

	zVEC3& GetPositionWorld(void)
	{
		XCALL(0x007AFB30);
	};

	void UpdatePositionWorld(void)
	{
		XCALL(0x007AFB40);
	};

	void SetName(zSTRING&)
	{
		XCALL(0x007AFBB0);
	};

	zSTRING const& GetName(void)
	{
		XCALL(0x007AFD10);
	};

	zCVobWaypoint* GetVob(void)
	{
		XCALL(0x007AFE70);
	};

	void CalcProperties(zCWorld*)
	{
		XCALL(0x007AFE80);
	};

	void CorrectHeight(zCWorld*)
	{
		XCALL(0x007B00A0);
	};

	void InsertWay(zCWay*)
	{
		XCALL(0x007B0140);
	};

	void RemoveWay(zCWay*)
	{
		XCALL(0x007B0150);
	};

	zCWay* HasWay(zCWaypoint*)
	{
		XCALL(0x007B01B0);
	};

	int GetNumberOfWays(void)
	{
		XCALL(0x007B01E0);
	};

	zCList<zCWay>& GetWayList(void)
	{
		XCALL(0x007B0200);
	};

	void SetWaypointVob(zCVobWaypoint*)
	{
		XCALL(0x007B0210);
	};

	void Draw(void)
	{
		XCALL(0x007B0250);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0077DF10);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x007B0260);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x007B02C0);
	};

	virtual ~zCWaypoint(void)
	{
		XCALL(0x007AFA80);
	};

	virtual int CanBeUsed(zCVob const*)
	{
		XCALL(0x007AF860);
	};
};

class zCWayNet : public zCObject		
{
	zCWorld*				m_pWorld;		
	zCListSort<zCWaypoint>	m_lstAllWp;		
	zCList<zCWay>			m_lstWay;		
	zCListSort<zCWaypoint>	m_lstOpenWp;	
	int						m_nRouteIndex;	
	static zCClassDef *classDef;
	void zWayNet(void)
	{
		XCALL(0x007ACC30);
	};

	zCWayNet(void)
	{
		zWayNet();
	};

	void zWayNet(zCWorld*)
	{
		XCALL(0x007ACD10);
	};

	zCWayNet(zCWorld* wld)
	{
		zWayNet(wld);
	};

	zCWaypoint* HasWaypoint(float,float,float)
	{
		XCALL(0x007ACF00);
	};

	int HasWaypoint(zCWaypoint*)
	{
		XCALL(0x007ACF70);
	};

	zCWaypoint* HasWaypoint(zVEC3&)
	{
		XCALL(0x007ACFA0);
	};

	zCWaypoint* InsertWaypoint(float,float,float)
	{
		XCALL(0x007ACFF0);
	};

	void InsertWaypoint(zCWaypoint*)
	{
		XCALL(0x007AD100);
	};

	void InsertWaypoint(zCWaypoint*,zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AD130);
	};

	void DeleteWaypoint(zCWaypoint*)
	{
		XCALL(0x007AD2B0);
	};

	void CreateWay(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AD420);
	};

	void DeleteWay(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AD4F0);
	};

	zCWaypoint* __fastcall GetNearestWaypoint(zVEC3 const&)
	{
		XCALL(0x007AD660);
	};

	zCWaypoint* GetSecNearestWaypoint(zVEC3&)
	{
		XCALL(0x007AD6F0);
	};

	void CorrectHeight(void)
	{
		XCALL(0x007AD7B0);
	};

	void Draw(zCCamera*)
	{
		XCALL(0x007AD870);
	};

	void UpdateVobDependencies(void)
	{
		XCALL(0x007AD8A0);
	};

	void ClearVobDependencies(void)
	{
		XCALL(0x007ADAF0);
	};

	void CreateVobDependencies(zCWorld*)
	{
		XCALL(0x007ADCF0);
	};

	zSTRING MergeWaypoints(void)
	{
		XCALL(0x007ADF70);
	};

	zSTRING CheckConsistency(int)
	{
		XCALL(0x007AE230);
	};

	void AddWays(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AE730);
	};

	static int SortWpList(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007AF620);
	};

	zCWaypoint* __fastcall GetWaypoint(zSTRING const&)const 
	{
		XCALL(0x007B0330);
	};

	zCWaypoint* SearchWaypoint(zCVobWaypoint*)
	{
		XCALL(0x007B04A0);
	};

	zCRoute* FindRoute(zVEC3 const&,zVEC3 const&,zCVob const*)
	{
		XCALL(0x007B04D0);
	};

	zCRoute* FindRoute(zVEC3 const&,zCWaypoint*,zCVob const*)
	{
		XCALL(0x007B0560);
	};

	zCRoute* FindRoute(zVEC3 const&,zSTRING const&,zCVob const*)
	{
		XCALL(0x007B05D0);
	};

	zCRoute* FindRoute(zCWaypoint*,zCWaypoint*,zCVob const*)
	{
		XCALL(0x007B0640);
	};

	zCRoute* FindRoute(zSTRING const&,zSTRING const&,zCVob const*)
	{
		XCALL(0x007B0680);
	};

	static int SortOpenList(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007B06E0);
	};

	void InsertInOpen(zCWaypoint*)
	{
		XCALL(0x007B0700);
	};

	int IsInOpen(zCWaypoint*)
	{
		XCALL(0x007B0730);
	};

	void InsertInClosed(zCWaypoint*)
	{
		XCALL(0x007B0750);
	};

	void RemoveFromClosed(zCWaypoint*)
	{
		XCALL(0x007B0770);
	};

	int IsInClosed(zCWaypoint*)
	{
		XCALL(0x007B0780);
	};

	int IsInAnyList(zCWaypoint*)
	{
		XCALL(0x007B07A0);
	};

	int EstimateCost(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x007B07D0);
	};

	zCRoute* CreateRoute(zCWaypoint*)
	{
		XCALL(0x007B0830);
	};

	int AStar(zCWaypoint*,zCWaypoint*,zCVob const*)
	{
		XCALL(0x007B08D0);
	};

	void GetWPList(zCList<zVEC3>&,zVEC3&,float,float)
	{
		XCALL(0x007B0B50);
	};

	void CreateWPVobList(zCList<zCVobWaypoint>&,zCTree<zCVob>*)
	{
		XCALL(0x007B0CB0);
	};

	void RemoveUnusedWPVobs(void)
	{
		XCALL(0x007B0CF0);
	};

	void ArchiveOldFormat(zCArchiver&)
	{
		XCALL(0x007B0E40);
	};

	void UnarchiveOldFormat(zCArchiver&)
	{
		XCALL(0x007B16F0);
	};

	void CalcProperties(zCWorld*)
	{
		XCALL(0x007B2820);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x007ACCD0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x007B11D0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x007B2200);
	};

	virtual ~zCWayNet()
	{
		XCALL(0x007ACDB0);
	};
};

class oCWaypoint : public zCWaypoint	
{
public:
	void oWaypoint(void)
	{
		XCALL(0x0077DEF0);
	};

	oCWaypoint(void)
	{
		oWaypoint();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0077DF10);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x007B0260);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x007B02C0);
	};

	virtual ~oCWaypoint()
	{
		XCALL(0x0077DF50);
	};

	virtual int CanBeUsed(zCVob const*)
	{
		XCALL(0x0077DF60);
	};
};

class oCWay : public zCWay				
{
	oCMobLadder*	m_pLadder;	
	oCMobDoor*		m_pDoor;	
public:
	virtual ~oCWay()
	{
		XCALL(0x0077E010);
	};

	virtual void Init(zCWaypoint*,zCWaypoint*)
	{
		XCALL(0x0077E190);
	};

	virtual int CanBeUsed(zCVob const*)
	{
		XCALL(0x0077E0A0);
	};

	virtual int IsObjectOnWay(zCVob const*)
	{
		XCALL(0x0077E880);
	};
};