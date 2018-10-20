#pragma once

#include "ztypes.h"
#include "zcvob.h"




enum zTMoveState;
class zCBspLeaf;
class zCCollisionObjectDef;
class zCCollisionReport;
class CShip;
class CDynamicWater;


class zCCollisionObject				
{
	friend class CShip;
	friend class CDynamicWater;
	struct BIT_ARRAY
	{
		BYTE		tMove:1;	
		BYTE		tRotate:1;	
	};
	zMAT4			m_mOldVobTrafo;		
	zMAT4			m_mVobTrafo;		
	zCVob*			m_pVob;				
	BIT_ARRAY		f;					
public:
	

	virtual zCCollisionObjectDef* GetCollObjClass(void)const 
	{
		XCALL(0x0054D1E0);
	};

	virtual ~zCCollisionObject()
	{
		XCALL(0x0054D230);
	};

	virtual void __fastcall DetectCollisionsSelf(zCArray<zCCollisionObject*> const&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x0054D1F0);
	};

	virtual void __fastcall CollisionResponse(zCArray<zCCollisionReport*> const&,int&)
	{
		XCALL(0x0054D200);
	};

	virtual float __fastcall GetAdaptiveStepSize(void)
	{
		XCALL(0x0054D210);
	};

	virtual int __fastcall SuppressCollisionResponse(void)
	{
		XCALL(0x0054D220);
	};

	virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D&)
	{
		XCALL(0x0054D520);
	};
};

class zCCollisionReport				
{
	float				m_fDistance;		
	zVEC3				m_vContactPoint;	
	zVEC3				m_vNormal1;			
	zVEC3				m_vNormal2;			
	zCCollisionObject*	m_pCollObj1;		
	zCCollisionObject*	m_pCollObj2;		

	void zCollisionReport()
	{
		XCALL(0x0054C550);
	};

	zCCollisionReport()
	{
		zCollisionReport();
	};

	~zCCollisionReport()
	{
		XCALL(0x0054C580);
	};
};


class zCCollisionObjectDef			
{
	zCCollisionObject* (*m_pfCreater)();	
	BOOL				m_bDestroy;			
	int					m_nIndex;			
public:

	void zCollisionObjectDef(int,zCCollisionObject* (__cdecl*)(void))
	{
		XCALL(0x0054D250);
	};

	zCCollisionObjectDef(BOOL bDestroy, zCCollisionObject* (*pfCreater)())
	{
		zCollisionObjectDef(bDestroy,pfCreater);
	};

	~zCCollisionObjectDef(void)
	{
		XCALL(0x0054D380);
	};

	static zCArray<zCCollisionObjectDef*>* GetCollClassList()
	{
		return *(zCArray<zCCollisionObjectDef*>**)0x008D8304;
	};
};



typedef BOOL (*zTStaticIntersectionTest)(float, zCCollisionObject*, zMAT4 const&, zCCollisionObject*, zMAT4 const&, zCCollisionReport**);	
typedef BOOL (*zTDynamicIntersectionTest)(zCCollisionObject*, zCCollisionObject*, zCCollisionReport**);

class zCCollisionDetector			
{
	zTStaticIntersectionTest*		m_pfStaticTest;		
	zTDynamicIntersectionTest*		m_pfDynamicTest;	
public:

	virtual ~zCCollisionDetector()
	{
		XCALL(0x0054C640);
	};

	virtual void __fastcall DetectCollisions(zCCollisionObject*,zCArray<zCCollisionObject*> const&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x0054CE50);
	};

	virtual void __fastcall RegisterStaticIntersectionTest(zCCollisionObjectDef*,zCCollisionObjectDef*,int (__cdecl*)(float,zCCollisionObject*,zMAT4 const&,zCCollisionObject*,zMAT4 const&,zCCollisionReport**))
	{
		XCALL(0x0054C720);
	};

	virtual void __fastcall RegisterDynamicIntersectionTest(zCCollisionObjectDef*,zCCollisionObjectDef*,int (__cdecl*)(zCCollisionObject*,zCCollisionObject*,zCCollisionReport**))
	{
		XCALL(0x0054C750);
	};

	virtual int __fastcall CanCollide(zCCollisionObjectDef*,zCCollisionObjectDef*)
	{
		XCALL(0x0054C780);
	};

	void zCollisionDetector(void)
	{
		XCALL(0x0054C5E0);
	};

	zCCollisionDetector(void)
	{
		zCollisionDetector();
	};

	int __fastcall GetTestFuncIndex(zCCollisionObjectDef*,zCCollisionObjectDef*)
	{
		XCALL(0x0054C6C0);
	};

	int (__cdecl*__fastcall GetStaticTestFunc(zCCollisionObjectDef*,zCCollisionObjectDef*))(float,zCCollisionObject*,zMAT4 const&,zCCollisionObject*,zMAT4 const&,zCCollisionReport**)
	{
		XCALL(0x0054C6E0);
	};

	int (__cdecl*__fastcall GetDynamicTestFunc(zCCollisionObjectDef*,zCCollisionObjectDef*))(zCCollisionObject*,zCCollisionObject*,zCCollisionReport**)
	{
		XCALL(0x0054C700);
	};

	static void S_ResetFreeCollReportList(void)
	{
		XCALL(0x0054C7C0);
	};

	static zCCollisionReport* S_GetNextFreeCollReport(void)
	{
		XCALL(0x0054C7D0);
	};

	void __fastcall DoDynamicIntersectionTests(zCCollisionObject*,zCArray<zCCollisionObject*>&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x0054C8B0);
	};

	void __fastcall DoStaticIntersectionTests(zCCollisionObject*,zCArray<zCCollisionObject*>&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x0054CAA0);
	};
};

class zCCollObjectBase : public zCCollisionObject	
{
public:
	virtual zCCollisionObjectDef* GetCollObjClass(void)const 
	{
		XCALL(0x0054D1E0);
	};

	virtual ~zCCollObjectBase()
	{
		XCALL(0x0054F8C0);
	};

	virtual void __fastcall DetectCollisionsSelf(zCArray<zCCollisionObject*> const&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x0054D1F0);
	};

	virtual void __fastcall CollisionResponse(zCArray<zCCollisionReport*> const&,int&)
	{
		XCALL(0x0054D200);
	};

	virtual float __fastcall GetAdaptiveStepSize(void)
	{
		XCALL(0x0054D210);
	};

	virtual int __fastcall SuppressCollisionResponse(void)
	{
		XCALL(0x0054D220);
	};

	virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D&)
	{
		XCALL(0x0054EBD0);
	};

	static float __fastcall S_CalcAdaptiveCollStepFromVisualBBox(zCVisual*)
	{
		XCALL(0x0054E9D0);
	};

	static void __fastcall S_CalcGeneric_CollNormal_ContactPoint(zCVob const*,zCVob const*,zCCollisionReport&)
	{
		XCALL(0x0054EA50);
	};

	static void __fastcall S_RegisterCollisionTestFuncs(void*)
	{
		XCALL(0x0054EC60);
	};
};


class zCRayCache		
{
	void*				m_pElement;		
	zCRayCache*			m_pNextCache;		
public:

	char* Hit(void)const 
	{
		XCALL(0x005D2C60);
	};

	zCArray<unsigned short>& HitList(void)const 
	{
		XCALL(0x005D2C70);
	};

	static float LastTraceRayEffort(void)
	{
		XCALL(0x005D2C80);
	};

	void StartTraceRay(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005D2CB0);
	};

	void StopTraceRay(void)
	{
		XCALL(0x005D2F90);
	};

	~zCRayCache(void)
	{
		XCALL(0x005D3170);
	};

	void NextNode(int const*)
	{
		XCALL(0x005D3210);
	};

	static void NodeDeleted(zCBspLeaf*)
	{
		XCALL(0x005D3800);
	};
};

class zCCollObjectCharacter : public zCCollObjectBase	
{
public:
	enum zEConfigState
	{
		zCONFIG_STATE_STAND			= 0,
		zCONFIG_STATE_FLY			= 1,
		zCONFIG_STATE_SLIDE			= 2,
		zCONFIG_STATE_SWIM			= 3,
		zCONFIG_STATE_DIVE			= 4,
	};	
	struct BIT_ARRAY
	{
		BYTE	tFlyingCreature:1;		
		BYTE	tMoving:1;				
		BYTE	tAniNoPlace:1;			
		BYTE	tUpperScanOrigin:1;		
		BYTE	tFallDown:1;			
		BYTE	tAlignModel:1;			
		BYTE	tPlayer:1;				
	};
	struct BIT_ARRAY_HIT
	{
		BYTE	tForwardHit:1;			
		BYTE	tBackHit:1;				
		BYTE	tLeftHit:1;				
		BYTE	tRightHit:1;			
		BYTE	tHit:1;					
	};
	struct BIT_ARRAY_COLL
	{
		BYTE	tCeilingLow:1;			
		BYTE	tSlopeHighUp:1;			
		BYTE	tSlopeHighDown:1;		
		BYTE	tObstacleUp:1;			
		BYTE	tObstacleDown:1;		
		BYTE	tVobHitPoly:1;			
		BYTE	tSlidingDowm:1;			
	};
	struct zTSpatialState
	{
		struct BIT_ARRAY
		{
			BYTE	tStair:1;			
			BYTE	tTraceVob:1;		
			BYTE	tUninited:1;		
		};
		float			m_fFloorY;		
		float			m_fWaterY;		
		float			m_fCeilY;		
		float			m_fStoreFloorY;	
		zCPolygon*		m_pFloorPoly;	
		zCPolygon*		m_pWaterPoly;	
		zCPolygon*		m_pCeilPoly;	
		union
		{
			BYTE		m_dbFlags;		
			BIT_ARRAY	f;
		};
		zTSpatialState() 
		{ 
			m_fFloorY      = 0;  
			m_fWaterY      = 0;  
			m_fCeilY       = 0;  
			m_fStoreFloorY = 0;  
			m_pFloorPoly   = 0;  
			m_pWaterPoly   = 0;  
			m_pCeilPoly    = 0;  
			m_dbFlags      = 0;  
		}
	};
	zCRayCache				m_AboveRay;			
	zCRayCache				m_UnderRay;			
	zCRayCache				m_ForwardRay;		
	zCRayCache				m_BackRay;			
	zCRayCache				m_LeftRay;			
	zCRayCache				m_RightRay;			
	void*					m_pConvex;			
	zTSpatialState			m_Spatial;			
	float					m_fDistFeetY;		
	float					m_fDistHeadY;		
	float					m_fSlidingTime;		
	float					m_fSlope;			
	zVEC3					m_vSlideDirect;		
	float					m_fSlideAngle;		
	float					m_fStepHeight;		
	union
	{
		BIT_ARRAY			pf;					
		BYTE                m_dbFlags;
	};
	zTMoveState				m_MoveState;		
	zCPolygon*				m_pForwardPoly;		
	zCVob*					m_pForwardVob;		
	zCPolygon*				m_pBackPoly;		
	zCVob*					m_pBackVob;			
	zCPolygon*				m_pLeftPoly;		
	zCVob*					m_pLeftVob;			
	zCPolygon*				m_pRightPoly;		
	zCVob*					m_pRightVob;		
	union
	{
		BYTE				m_dbHits;			
		BIT_ARRAY_HIT		hit;
	};
	union
	{
		BYTE				m_dbColl;			
		BIT_ARRAY_COLL		coll;
	};
	zVEC3					m_vDirectColl;		
public:

	virtual zCCollisionObjectDef* GetCollObjClass(void)const 
	{
		XCALL(0x0054F8E0);
	};

	virtual ~zCCollObjectCharacter()
	{
		XCALL(0x0054F950);
	};

	virtual void __fastcall DetectCollisionsSelf(zCArray<zCCollisionObject*> const&,zCArray<zCCollisionReport*>&)
	{
		XCALL(0x00553230);
	};

	virtual void __fastcall CollisionResponse(zCArray<zCCollisionReport*> const&,int&)
	{
		XCALL(0x005537A0);
	};

	virtual float __fastcall GetAdaptiveStepSize(void)
	{
		XCALL(0x00553C20);
	};

	virtual int __fastcall SuppressCollisionResponse(void)
	{
		XCALL(0x0054D220);
	};

	virtual void __fastcall GetLargestBBox3DLocal( zTBBox3D&)
	{
		XCALL(0x00553C00);
	};

	virtual void* GetPrimitiveCC(void)const 
	{
		XCALL(0x0054FA10);
	};

	virtual int IsDead(void)const 
	{
		XCALL(0x0054F8F0);
	};

	virtual int DontLetHimComeNearer(zCVob const*)const 
	{
		XCALL(0x0054F900);
	};

	virtual float TurnSpeed(void)const 
	{
		XCALL(0x0054F910);
	};

	virtual void PushAround(zVEC3 const&)
	{
		XCALL(0x0054F920);
	};

	int __fastcall IsMoveInvalid(zVEC3 const&,zVEC3 const&,zVEC3&, zCCollObjectCharacter::zTSpatialState&,zVEC3&)
	{
		XCALL(0x00511060);
	};

	void zCollObjectCharacter(void)
	{
		XCALL(0x0054F730);
	};

	zCCollObjectCharacter(void)
	{
		zCollObjectCharacter();
	};

	void __fastcall GetFallbackTrafoCC(zMAT4 const&,zMAT4 const&,zVEC3 const&,int,zMAT4&)const 
	{
		XCALL(0x0054FAF0);
	};

	static zVEC3 __fastcall S_SlideCC(zVEC3 const&,float,zVEC3 const&)
	{
		XCALL(0x0054FF10);
	};

	void __fastcall GetCollisionPoleYDims(float&,float&)const 
	{
		XCALL(0x00550840);
	};

	int __fastcall CalcSlideVector(zVEC3 const&,zVEC3 const&,zVEC3&,zVEC3&,float&)
	{
		XCALL(0x00550870);
	};

	void __fastcall DoWallSlidingLatentRotation(zMAT4&)
	{
		XCALL(0x00550D50);
	};

	void __fastcall FindFloorWaterCeiling(zVEC3 const&, zCCollObjectCharacter::zTSpatialState&)
	{
		XCALL(0x00550E20);
	};

	void MarkSpatialStateAsUninited(int)
	{
		XCALL(0x00551100);
	};

	int __fastcall TestHardCollisions(zVEC3 const&,zVEC3 const&,zVEC3&, zCCollObjectCharacter::zTSpatialState&,zVEC3&)
	{
		XCALL(0x00551150);
	};

	static int __fastcall S_CalcAvgNormalVariance( zTTraceRayReport const (&)[4],zVEC3&,float&)
	{
		XCALL(0x00551EC0);
	};

	zVEC3 __fastcall GetSurfaceAlignScanOrigin(zVEC3 const&)
	{
		XCALL(0x00552060);
	};

	int __fastcall TestSoftCollisions(zVEC3 const&,zVEC3 const&,zVEC3&,zVEC3&)
	{
		XCALL(0x00552180);
	};

	void __fastcall PrintDebugInfos(void)
	{
		XCALL(0x00553C60);
	};
};

