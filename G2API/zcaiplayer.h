#pragma once

#include "ztypes.h"
#include "zcmodel.h"
#include "zctimer.h"
#include "zccollisionobject.h"

class zCQuadMark; 
class zCPathSearch; 
class zCAICamera;
class oCItem;
class oCNpc;
class zCPositionKey;
class zCCSCamera;





const	int		AZI						= 0;
const	int		ELEV					= 1;
const	int		RANGE					= 2;


struct zSEvasionSearchDesc;
struct zSPathSearchState_Internal;
class  zCMovementTracker;
class  zCAICamera;

typedef BOOL (*zTPathSearchFunc)(const zSEvasionSearchDesc &searchDesc);


struct zSEvasionSearchDesc 
{
public:
	struct zSEvasionSearchOptions	
	{ 
		zVEC3				scSign;								
		zVEC3				scQuality;							
		zVEC3				scStart;
		zVEC3				scEnd;
		zSTRING				scSequence;							
		zSTRING				scName;
	};

	zTPathSearchFunc						searchFunc;
	zSTRING									searchName;
	zCArray		<zSEvasionSearchOptions>	sphereSearchList;
};


enum zTPoseFailReason 
{ 
	
	zFAILREASON_NONE						= 0,
	zFAILREASON_PLAYER_INVISIBLE			= 1	<< 0, 
	zFAILREASON_CAM_INVISIBLE				= 1	<< 1, 
	zFAILREASON_PLAYER_TARGET_INVISIBLE		= 1	<< 2, 
	zFAILREASON_CAM_HIT_WALL				= 1	<< 3, 
	zFAILREASON_NO_EVASION_FOUND			= 1 << 4,
	
	zFAILREASON_BADSCENE_STAND				= 1	<< 5, 
	zFAILREASON_BADSCENE_MELEE				= 1	<< 6, 
	zFAILREASON_BADSCENE_RANGED				= 1	<< 7,
	zFAILREASON_BADSCENE_MAGIC				= 1	<< 8, 
	zFAILREASON_BADSCENE_CINEMA				= 1 << 9,
	zFAILREASON_VOB_CROSS_LINEOFSIGHT		= 1	<< 10, 
	zFAILREASON_NPC_CROSS_LINEOFSIGHT		= 1	<< 11, 
	zFAILREASON_VOB_HIT_CAM					= 1	<< 12, 
	zFAILREASON_NPC_HIT_CAM					= 1	<< 13, 
	zFAILREASON_AZIBOUND_LEFT				= 1	<< 14, 
	zFAILREASON_ELEVBOUND_LEFT				= 1	<< 15, 
	zFAILREASON_RANGEBOUND_LEFT				= 1	<< 16, 
	zFAILREASON_TARGET_NOT_IN_FRUSTUM		= 1	<< 17,
	zFAILREASON_PLAYER_BEAMED				= 1 << 18
};


enum zTPathLerpMode
{
	zPATH_LERP_NONE							= 0,			
	zPATH_LERP_CUSTOM_JUMP					= 1 << 0,
	zPATH_LERP_JUMP							= 1	<< 1,		
	zPATH_LERP_CUSTOM						= 1	<< 2,		
	zPATH_LERP_SPLINE						= 1	<< 3,		
	zPATH_LERP_LINE							= 1	<< 4,		
	zPATH_LERP_ARC							= 1	<< 5,		
	zPATH_LERP_MAX							= 1 << 6
};

enum zTPathSearchFlags
{
	zPATHSEARCH_INCLUDE_NONE				= 0,
	zPATHSEARCH_INCLUDE_CAM_CHECK			= 1	<< 1,
	zPATHSEARCH_INCLUDE_PLAYER_CHECK		= 1	<< 2,
	zPATHSEARCH_INCLUDE_PLAYER_TARGET_CHECK = 1	<< 3,
	zPATHSEARCH_INCLUDE_NEARWALL_CHECK		= 1	<< 4,
	zPATHSEARCH_INCLUDE_VOB_CHECK			= 1	<< 5,
	zPATHSEARCH_INCLUDE_NPC_CHECK			= 1	<< 6,
	zPATHSEARCH_INCLUDE_INFRUSTUM_CHECK		= 1	<< 7,
	zPATHSEARCH_INCLUDE_BOUNDS_CHECK		= 1 << 8,
	zPATHSEARCH_USE_PLAYER_FUTURE_POS		= 1	<< 9,
	zPATHSEARCH_USE_PLAYER_MESH				= 1	<< 10,
	zPATHSEARCH_USE_DYNCOLLISION			= 1 << 11
};

struct zSPathSearchResult
{
public:
	BOOL				foundEvasion;
	zPOINT3				p1,p2;
	zCQuat				r1,r2;
	zTPathLerpMode		bestLerpMode;
	int					lerpModes;			
	zCArray<zCPositionKey*>resPath;			
	float				avgScore;			
	float				bestScore;			
	float				veloTrans;
	float				veloRot;

	void		Initialize()												{	memset(this,0,sizeof(this)); };
};

struct zSPathSearchState
{
	float			startAzi,	startElev,	startRange;
	float			endAzi	,	endElev,	endRange;
	float			bestAzi,	bestElev,	bestRange;
	zMAT4			trafoCamToWorld;								
	zTPathLerpMode	bestLerpMode;
	int				lerpModes;
	float			totalScore;
	zSTRING			sphereSearchName;
	zSTRING			sphereSearchSegment;
};

struct zSPathSearchState_Internal
{
	float			maxRange;
	zVEC3			foundPos;
	zMAT4			trafoCamToWorld;								
	zTPathLerpMode	bestLerpMode;
	float			scoreLerpMode;				
	float			scoreDistToIdealPos;		
	float			scoreFoundNumNpcs;			
	float			scoreFoundNumBBoxes;		
	float			scoreFoundNumTargets;		
	float			scorePlayerVisibility;		
	float			scoreDistToLastEvasion;
	float			totalScore;					
};


class zCAIBase : public zCObject
{
public:
	zCLASS(zCAIBase);
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0048BD20);
	};

	virtual ~zCAIBase()
	{

	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};
};

class zCAIPlayer : public zCAIBase 
{
public:
	zCLASS(zCAIPlayer)


	struct zTConfig
	{
		float			zMV_MIN_SPACE_MOVE_FORWARD;
		float			zMV_DETECT_CHASM_SCAN_AT;
		float			zMV_STEP_HEIGHT;				
		float			zMV_JUMP_UP_MIN_CEIL;
		float			zMV_WATER_DEPTH_KNEE;
		float			zMV_WATER_DEPTH_CHEST;
		float			zMV_YMAX_SWIM_CLIMB_OUT;
		float			zMV_FORCE_JUMP_UP;
		float			zMV_YMAX_JUMPLOW;
		float			zMV_YMAX_JUMPMID;
						
		
		float			zMV_MAX_GROUND_ANGLE_WALK;		
		float			zMV_MAX_GROUND_ANGLE_SLIDE;
		float			zMV_MAX_GROUND_ANGLE_SLIDE2;
						
		
		float			zMV_DCUL_WALL_HEADING_ANGLE;
		float			zMV_DCUL_WALL_HORIZ_ANGLE;
		float			zMV_DCUL_GROUND_ANGLE;
	} config;

	enum zTSurfaceAlignMode
	{						
		zMV_SURFACE_ALIGN_NONE	= 0,				
		zMV_SURFACE_ALIGN_NORMAL= 1,				
		zMV_SURFACE_ALIGN_HIGH	= 2,				
	};		

	

   struct zTLedgeInfo
   {
        zVEC3 point;            
        zVEC3 normal;           
        zVEC3 cont;             
        float maxMoveForward;   

        zTLedgeInfo(const zCAIPlayer *):point(0,0,0), normal(0,0,0), cont(0,0,0), maxMoveForward(0){}
    };
	enum zTMovementState
	{							
		zMV_STATE_STAND			= 0,				
		zMV_STATE_FLY			= 1,				
		zMV_STATE_SWIM			= 2,				
		zMV_STATE_DIVE			= 3,				
	};					
	zCVob				*vob;							
	zCModel				*model;
	zCWorld				*world;
						
	zVEC3				centerPos;						
	float				feetY   , headY;
	float				aboveFloor;
	
	int					waterLevel;						

	
	float				velocityLen2;
	zVEC3				velocity;
						
	float				fallDownDistanceY;
	float				fallDownStartY;
			
	zVEC3				slidePolyNormal;
	float				checkWaterCollBodyLen;
	zCModelNodeInst*	modelHeadNode;

	
	#pragma pack (push, 1)							
	struct
	{	
		UINT8			zMV_DO_SURFACE_ALIGN			: 2;	
		UINT8			zMV_DO_DETECT_WALK_STOP_CHASM	: 1;
		UINT8			zMV_DO_WALL_SLIDING				: 1;	
		UINT8			zMV_DO_HEIGHT_CORRECTION		: 1;	

		UINT8			cdStatOriginal					: 1;
		UINT8			cdStat							: 1;
		UINT8			startFXModelLandDust			: 1;

		UINT8			forceModelHalt					: 1;
		UINT8			autoRollEnabled					: 1;
		UINT8			modelAnisInPlace				: 1;
		zTMovementState	oldState						: 3;	
		zTMovementState	state							: 3;	
		UINT8			oldWaterLevel					: 2;	
		zCCollObjectCharacter::zEConfigState m_eCollObjectState		: 4;
		zCCollObjectCharacter::zEConfigState m_eCollObjectStateOld	: 4;
	};
	#pragma pack (pop)								

	
	struct zTBloodVobTrack
	{
		zCVob			*bloodVob;
		float			alpha;
	};
	zCArray<zTBloodVobTrack>	bloodVobList;
	float				bleedingPerc;
	zVEC3				bleedingLastPos;
	float				bleedingNextDist;

	
	zCVob*				weaponTrailVob;

	
	zCVob				*waterRingVob;
	float				waterRingTimer;

	
	float				autoRollPos;
	float				autoRollPosDest;
	float				autoRollSpeed;
	float				autoRollMaxAngle;
				
	BYTE				dummyLastVar;							

	
	

	zSTRING				bloodDefaultTexName;
	static BOOL zCAIPlayer::s_bShowWeaponTrails;
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0050C730);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00511E60);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00511F50);
	};

	virtual ~zCAIPlayer()
	{
		XCALL(0x0050C770);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0050E980);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0050CA60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	virtual void StartStandAni(void)
	{
		XCALL(0x00511D80);
	};

	virtual void StartFallDownAni(void)
	{
		XCALL(0x00511DA0);
	};

	void zAIPlayer(void)
	{
		XCALL(0x0050C5C0);
	};

	zCAIPlayer(void)
	{
		zAIPlayer();
	};

	void RemoveEffects(void)
	{
		XCALL(0x0050C980);
	};

	float GetJumpUpHeight(void)
	{
		XCALL(0x0050CA70);
	};

	void SetJumpUpForceByHeight(float)
	{
		XCALL(0x0050CAB0);
	};

	void SetVob(zCVob*)
	{
		XCALL(0x0050CAD0);
	};

	void DoAutoRoll(void)
	{
		XCALL(0x0050CC30);
	};

	void ResetAutoRoll(void)
	{
		XCALL(0x0050CDF0);
	};

	void CalcModelAnisInPlace(void)
	{
		XCALL(0x0050CE20);
	};

	void DoSurfaceAlignment(void)
	{
		XCALL(0x0050CE80);
	};

	int IsSliding(void)
	{
		XCALL(0x0050D4A0);
	};

	int CheckFloorSliding(void)
	{
		XCALL(0x0050D4D0);
	};

	void CheckPhysics(void)
	{
		XCALL(0x0050DC40);
	};

	void PropagateCollObjectStates(zCAIPlayer::zTMovementState)
	{
		XCALL(0x0050E180);
	};

	void CalcForceModelHalt(void)
	{
		XCALL(0x0050E390);
	};

	void CalcStateVars(void)
	{
		XCALL(0x0050E440);
	};

	void DoProceduralMovement(void)
	{
		XCALL(0x0050E6C0);
	};

	void Begin(zCVob*)
	{
		XCALL(0x0050E750);
	};

	void End(void)
	{
		XCALL(0x0050E8F0);
	};

	void UpdateEffects(void)
	{
		XCALL(0x0050E990);
	};

	zCQuadMark* GetBloodQuadMark(void)
	{
		XCALL(0x0050F520);
	};

	void SetBloodDefaultTexture(zSTRING const&)
	{
		XCALL(0x0050F780);
	};

	void AddBlood(zVEC3 const&,zVEC3 const&,float,int,zSTRING*)
	{
		XCALL(0x0050F8C0);
	};

	void AddWeaponTrailSegment(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x0050F950);
	};

	void CreateLedgeInfo(void)
	{
		XCALL(0x0050FCA0);
	};

	zTLedgeInfo* GetLedgeInfo(void)const 
	{
		XCALL(0x0050FCC0);
	};

	int GetFoundLedge(void)const 
	{
		XCALL(0x0050FD00);
	};

	void ClearFoundLedge(void)
	{
		XCALL(0x0050FD20);
	};

	int DetectClimbUpLedge(zVEC3&,int)
	{
		XCALL(0x0050FD90);
	};

	void AlignModelToLedge(zSTRING const&)
	{
		XCALL(0x00511070);
	};

	zVEC3 GetHandPositionWorld(void)const 
	{
		XCALL(0x00511170);
	};

	void AlignToFloor(float)
	{
		XCALL(0x005112C0);
	};

	float GetModelFloorWorld(void)
	{
		XCALL(0x00511300);
	};

	int CheckEnoughSpaceMoveDir(zVEC3 const&,int)
	{
		XCALL(0x00511320);
	};

	int CheckEnoughSpaceMoveForward(int)
	{
		XCALL(0x00511700);
	};

	int CheckEnoughSpaceMoveBackward(int)
	{
		XCALL(0x00511740);
	};

	int CheckEnoughSpaceMoveRight(int)
	{
		XCALL(0x00511790);
	};

	int CheckEnoughSpaceMoveLeft(int)
	{
		XCALL(0x005117D0);
	};

	float GetProtoYHeight(void)
	{
		XCALL(0x00511820);
	};

	zVEC3 GetSurfaceAlignScanOrigin(void)
	{
		XCALL(0x00511840);
	};

	void DiveRotateX(float const&)
	{
		XCALL(0x00511970);
	};

	void SetCDStat(int)
	{
		XCALL(0x00511AC0);
	};

	void LandAndStartAni(zSTRING const&)
	{
		XCALL(0x00511B10);
	};

	void LandAndStartAni(zCModelAni*)
	{
		XCALL(0x00511BC0);
	};

	int CheckForceModelHalt(zSTRING const&)
	{
		XCALL(0x00511C20);
	};

	int CheckForceModelHalt(zCModelAni*)
	{
		XCALL(0x00511C60);
	};

	int ShouldCorrectFloorHeight(void)
	{
		XCALL(0x00511CA0);
	};

	void BeginStateSwitch(void)
	{
		XCALL(0x00511CC0);
	};

	void SetPhysicsEnabled(int)
	{
		XCALL(0x00511D40);
	};

	void StartPhysicsWithVel(void)
	{
		XCALL(0x00511D50);
	};

	void Print(zSTRING const&)const 
	{
		XCALL(0x00512080);
	};

	void Line3D(zVEC3 const&,zVEC3 const&,int)const 
	{
		XCALL(0x00512090);
	};

	void PrintScreen(int,int,zSTRING)const 
	{
		XCALL(0x005120A0);
	};

	zCModel* GetModel(void)const 
	{
		XCALL(0x006A9810);
	};
};

enum zTAICamMsg
{
	zAI_MOVE_BACKWARD	= 4,
	zAI_TARGET_MOVED	= 0x8000
};

class zCAIBaseSound : public zCAIBase		
{

public:
	zCLASS(zCAIBaseSound)
	zTSoundHandle	slideSoundHandle;
	char			slideSoundOn;
	static zCClassDef* classDef;
	void RemoveSlideSound(void)
	{
		XCALL(0x0050C120);
	};

	void CheckSlideSound(zCVob*)
	{
		XCALL(0x0050C140);
	};

	void StartDefaultCollisionSound(zCVob*,zCCollisionReport const&)
	{
		XCALL(0x0050C1D0);
	};
};

class oCAISound : public zCAIBase
{
	zTSoundHandle	slideSoundHandle;
	char			slideSoundOn;
public:
	zCLASS(oCAISound)
	static zCClassDef *classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0069F490);
	};

	virtual ~oCAISound()
	{
		XCALL(0x0069F4A0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	void RemoveSlideSound(void)
	{
		XCALL(0x0069EE80);
	};

	void CheckSlideSound(zCVob*)
	{
		XCALL(0x0069EEA0);
	};

	int GetSoundMaterial(zCVob*,int&)
	{
		XCALL(0x0069EF30);
	};

	void StartCollisionSound(zCVob*,zCCollisionReport const&)
	{
		XCALL(0x0069F0B0);
	};
};

class oCAIDrop : public oCAISound
{
public:
	zCLASS(oCAIDrop)
	zCList<zCVob>	ignoreVobList;
	zCVob*			vob;
	zCVob*			owner;
	BOOL			collisionOccured;
	float			timer;
	float			count;
	static zCClassDef *classDef;
public:
	void oAIDrop(void)
	{
		XCALL(0x006A1EA0);
	};

	oCAIDrop(void)
	{
		oAIDrop();
	};

	void AddIgnoreCDVob(zCVob*)
	{
		XCALL(0x006A2130);
	};

	void ClearIgnoreCDVob(void)
	{
		XCALL(0x006A2150);
	};

	void SetupAIVob(zCVob*,zCVob*)
	{
		XCALL(0x006A21C0);
	};

	void SetVelocity(float,float)
	{
		XCALL(0x006A24E0);
	};

	void SetStartPosition(zVEC3&)
	{
		XCALL(0x006A2590);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006A1F80);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006A2710);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006A2720);
	};

	virtual ~oCAIDrop()
	{
		XCALL(0x006A2010);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x006A2420);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x006A1FA0);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x006A2490);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x006A1F90);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

};

class zCPolyStrip;

class oCAIArrowBase : public oCAISound
{
public:
	zCLASS(oCAIArrowBase)
	zCList<zCVob>	ignoreVobList;
	BOOL			collisionOccured;
	float			timeLeft;
	zCVob*			vob;
	BOOL			startDustFX;
	zCVob*			trailVob;
	zCPolyStrip*	trailStrip;
	BOOL			trailActive;
	float			trailTime;
	BOOL			hasHit;
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006A0210);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006A0CD0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006A0D50);
	};

	virtual ~oCAIArrowBase()
	{
		XCALL(0x006A0280);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x006A0640);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x006A09C0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x006A0220);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x006A0230);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x006A0240);
	};

	void oAIArrowBase(void)
	{
		XCALL(0x006A0120);
	};

	oCAIArrowBase(void)
	{
		oAIArrowBase();
	};

	void AddIgnoreCDVob(zCVob*)
	{
		XCALL(0x006A0390);
	};

	void ClearIgnoreCDVob(void)
	{
		XCALL(0x006A03B0);
	};

	void CreateTrail(zCVob*)
	{
		XCALL(0x006A0420);
	};
};

class oCAIVobMove : public oCAISound
{
public:
	zCLASS(oCAIVobMove)
	zCVob			*vob, *owner;
	zCList<zCVob>	ignoreVobList;
public:
	static zCClassDef *classDef;

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0069F2F0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0069FA80);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0069FAE0);
	};

	virtual ~oCAIVobMove()
	{
		XCALL(0x0069F370);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0069F8C0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0069F300);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0069FA30);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	virtual void Init(zCVob*,zCVob*,zVEC3&,float,float,zMAT4*)
	{
		XCALL(0x0069F540);
	};

	void oAIVobMove(void)
	{
		XCALL(0x0069F220);
	};

	oCAIVobMove(void)
	{
		oAIVobMove();
	};

	void AddIgnoreCDVob(zCVob*)
	{
		XCALL(0x0069FBD0);
	};

	void ClearIgnoreCDVob(void)
	{
		XCALL(0x0069FBF0);
	};
};

class oCAIVobMoveTorch : public oCAIVobMove	
{
public:
	zCLASS(oCAIVobMoveTorch)
	float			timer;
public:
	static zCClassDef* classDef;
	void oAIVobMoveTorch(void)
	{
		XCALL(0x0069FC60);
	};

	oCAIVobMoveTorch(void)
	{
		oAIVobMoveTorch();
	};

	int CheckWater(void)
	{
		XCALL(0x0069FE90);
	};

	void BurnedOut(void)
	{
		XCALL(0x0069FF40);
	};


	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0069FCF0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0069FA80);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0069FAE0);
	};

	virtual ~oCAIVobMoveTorch()
	{
		XCALL(0x0069FD30);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0069FE60);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0069F300);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0069FA30);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

	virtual void Init(zCVob*,zCVob*,zVEC3&,float,float,zMAT4*)
	{
		XCALL(0x0069FE40);
	};
};

class oCAIArrow : public oCAIArrowBase
{
public:
	zCLASS(oCAIArrow)
	oCItem*			arrow;
	oCNpc*			owner;
	BOOL			removeVob;
	zCVob*			targetNPC;
	static zCClassDef *classDef;
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006A0EC0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006A1CC0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006A1D90);
	};

	virtual ~oCAIArrow()
	{
		XCALL(0x006A0F00);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x006A1460);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x006A1490);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x006A1530);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x006A0220);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x006A0230);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x006A0240);
	};
	// [AST]
	void SetupAIVob_AST(zCVob*, zCVob*, zCVob*);
	// [/AST]
	void oAIArrow(void)
	{
		XCALL(0x006A0E10);
	};

	oCAIArrow(void)
	{
		oAIArrow();
	};

	void SetTarget(zCVob*)
	{
		XCALL(0x006A0FF0);
	};

	void ClearUsedVobs(void)
	{
		XCALL(0x006A1030);
	};

	void SetupAIVob(zCVob*,zCVob*,zCVob*)
	{
		XCALL(0x006A10E0);
	};
};

class zCPose		
{
	zCQuat	qRing[100];
	zVEC3	pRing[50];
	int		ringPosTrans;
	int		ringPosRot;

	zCQuat	actRotAbs;
	zVEC3 actPosAbs;
	zCQuat	actRot;
	zVEC3	actPos;
	BOOL   oneTurn;

	int		numSamplesPos;
	int		numSamplesRot;
	static zMAT4 tmpMat;
public:

	~zCPose(void)
	{
		XCALL(0x004B4A10);
	};

	void SetPose(zMAT4&)
	{
		XCALL(0x004C39E0);
	};

	void SetInertiaRot(float)
	{
		XCALL(0x004D90E0);
	};

	void SetInertiaPos(float)
	{
		XCALL(0x004D9160);
	};

	void SetInertiaSamplesRot(int)
	{
		XCALL(0x004D91D0);
	};

	void SetInertiaSamplesPos(int)
	{
		XCALL(0x004D9240);
	};

	void CalcAvgRot(void)
	{
		XCALL(0x004D92A0);
	};

	void UpdatePose(zMAT4&)
	{
		XCALL(0x004D94B0);
	};

	void UpdatePose(zCQuat&,zVEC3&)
	{
		XCALL(0x004D9660);
	};

	void UpdateRot(zMAT4&)
	{
		XCALL(0x004D9800);
	};

	void UpdateRot(zCQuat&)
	{
		XCALL(0x004D9880);
	};

	void UpdatePos(zVEC3&)
	{
		XCALL(0x004D9900);
	};

	zCPose(void)
	{
		XCALL(0x004D9A30);
	};

	void SetRot(zMAT4&)
	{
		XCALL(0x004D9AA0);
	};

	void SetRot(zCQuat&)
	{
		XCALL(0x004D9B20);
	};

	void SetPos(zMAT4&)
	{
		XCALL(0x004D9B90);
	};

	void SetPos(zVEC3&)
	{
		XCALL(0x004D9C30);
	};

	void GetPose(zMAT4&)
	{
		XCALL(0x004D9C90);
	};

	zMAT4& GetPose(void)
	{
		XCALL(0x004D9CD0);
	};

	void GetPoseAbs(zMAT4&)
	{
		XCALL(0x004D9D20);
	};

	zMAT4& GetRotMatAbs(void)
	{
		XCALL(0x004D9D60);
	};

	zMAT4& GetRotMat(void)
	{
		XCALL(0x004D9D90);
	};
};

const int	NUM_WAYPOINTS						= 3; 

class zCMovementTracker
{
public:
	friend class zCAICamera;
	typedef DWORD zTPlayerMovement;

	enum zTWayPoint		
	{ 
		zWAYPOINT_PLAYER, 
		zWAYPOINT_CAM, 
		zWAYPOINT_HEAD, 
		zWAYPOINT_HIP_LEFT, 
		zWAYPOINT_HIP_RIGHT 
	};
	zTPlayerMovement	movement;

	zCArray<zCPositionKey*>targetKFList;

	float	frameTime;
	zPOINT3 sampledPlayerPos;				
	zPOINT3 sampledPlayerPosRing;			
	zPOINT3	playerPos;						
	zPOINT3 playerPosRing;					
	zPOINT3 POI_Player;
	zPOINT3 camPos;
	zPOINT3 camPosRing;
	zPOINT3 oldSampledPlayerPosRing;
	zPOINT3 oldSampledPlayerPos;
	zPOINT3 offsetPos;
	zPOINT3 playerFuturePos;
	float	playerFuturePosDT;
	
	int		numPreSamplesPlayerPos;


	int		numSamplesCam;


	int		numSamplesPlayer;


	zCPose	rotPoseTargetFOR;
	zCPose	headPose;
	zCPose	sampledPlayerPose;

	

	zPOINT3 wayPointHead    [NUM_WAYPOINTS];
	zPOINT3 wayPointHipLeft [NUM_WAYPOINTS];
	zPOINT3 wayPointHipRight[NUM_WAYPOINTS];
	zPOINT3 wayPointCam	    [NUM_WAYPOINTS];
	int     actWayPointHead;
	int     actWayPointHipLeft;
	int     actWayPointHipRight;
	int		actWayPointCam;
	float	wayTimeHead;
	float	wayTimeHipLeft;
	float	wayTimeHipRight;
	float	wayTimeCam;

	zPOINT3 playerHead;
	zPOINT3 playerHipLeft;
	zPOINT3 playerHipRight;
	zVEC3   playerPosMovement;
	zVEC3   playerPosMovementRing;
	zVEC3   playerPosMovementLocal;
	zVEC3   playerPosMovementLocalCam;
	zVEC3	oldPlayerPosMovement;
	zPOINT3	oldPlayerPos;
	zPOINT3	oldCamPos;
	float	oldDistToPlayer;

	
	float	inertiaTrans;
	float	inertiaHead;
	float	inertiaRotTargetFOR;
	float	inertiaTargetTrans;
	float	inertiaTargetRot;

	float	actAzi;
	float	actElev;
	float	distToPlayer;
	float	playerVeloRange;
	float   oldAzi;
	float	oldElev;

	zMAT4	trafoWStoTS;					
	zMAT4	trafoTStoWS;					
	zMAT4	trafoWStoCS;					
	zMAT4	trafoCStoWS;					
	zMAT4	oldTrafoWStoTS;
	zMAT4	oldTrafoWStoCS;
	zMAT4   oldTrafoRotOffsetWStoCS;
	zMAT4	lastValidCamTrafo; 

	zCQuat	startRot;
	zCQuat	endRot;
	zCQuat	maxAziRot;
	zCQuat	minAziRot;
	zCQuat	idealRot;
	zCQuat	idealRotTrans;
	zCQuat	actRot;
	zCQuat	idealRotLocal;
	zMAT4	initialPoseRotFreeze;

	float	timeSamples;
	float	standTimer;

	BOOL	standing ;
	BOOL			rotate;
	BOOL			bMouseUsed;
	float			playerAziSideSign;				
	float			playerElevSideSign;				

	zCVob*			target;
	zCVob*			camVob;
	zCAICamera*		camai;
	zCPathSearch*	pathSearch;						
public:
	
	void TargetChanged()
	{
		XCALL(0x004BAF00);
	};
	
	void Update()
	{
		XCALL(0x004B73F0);
	};

	// 0x004B87C0 public: void __thiscall zCMovementTracker::InterpolateTo(struct zSPathSearchResult const &)
	void InterpolateTo (zSPathSearchResult const &) { XCALL(0x004B87C0); };

	// 0x004BA380 public: class zMAT4 & __thiscall zCMovementTracker::GetShoulderCamMat(void)
	zMAT4 & GetShoulderCamMat() { XCALL(0x004BA380); };

	//
	int PlayerStands () { return (!(movement & 2048) && !(movement & 8192)); };
};

class zCAICamera : public zCAIBase
{
public:
	zCLASS(zCAICamera)
	
	BOOL			d_showDots;	  
	BOOL			pathDetectCollision;
	

	
	float			bestRange;
	float			minRange;
	float			maxRange;

	
	float			bestRotX;
	float			minRotX;
	float			maxRotX;
	float			bestRotY;
	float			minRotY;
	float			maxRotY;
	float			bestRotZ;
	float			minRotZ;
	float			maxRotZ;

	
	float			rotOffsetX;
	float			rotOffsetY;
	float			rotOffsetZ;

	
	float			focusOffsetX;
	float			focusOffsetY;
	float			focusOffsetZ;

	
	float			veloTrans;			  
	float			veloRot;			  
	
	
	BOOL			translate;			    
	BOOL			rotate;					
	BOOL			collision;			    

	
	BYTE			endOfDScript;

	zCArray<zCVob*>			targetVobList;			
	zCVob*					camVob;
	zCVob*					target;
	float					targetAlpha;			
	int						numTargets;				
	zSTRING					oldCamSys;
	BOOL					sysChanged;
	BOOL					playerIsMovable;
	BOOL					followIdealPos;
	float					dialogCamDuration;
	int						numOUsSpoken;
	int						numDialogCamTakes;
	int						lastNumDialogCamTakes;
	int						lastDialogCamSide;				
	int						firstSpeakerWasPC;
	zCCSCamera*				dialogCam;
	zSTRING					lastPresetName;
	int						raysCasted;
	BOOL					underWater;
	BOOL					inCutsceneMode;
							
	
	zSTRING					debugS;  
	BOOL					showPath;
	zCVob*					focusVob; 
	zCVob*					ctrlDot[80];
	zCPathSearch*			pathSearch;				
	zCMovementTracker*		moveTracker;			
	zSPathSearchResult*		evasionSearchReport;	
	zSTRING					curcammode;
	float					npcVolumeRangeOffset;
	float					camDistOffset;
	zPOINT3					camSysFirstPos;
	BOOL					firstPerson;
	BOOL					targetInPortalRoom;	

	static zCClassDef *classDef;
	static int zCAICamera::bCamChanges;
	static short zCAICamera::s_iLookAroundSgn;
	static zCArray<zCCSCamera*>* zCAICamera::dialogCamList;
	static zCAICamera*& zCAICamera::current;
	static int zCAICamera::bCreated;
	static float zCAICamera::lookingCamLastAzi;
	static int zCAICamera::lookingCamAziGoalReached;
public:
	static zCAICamera* GetCurrent(void)
	{
		XCALL(0x0049FD20);
	};

	void zAICamera(void)
	{
		XCALL(0x0049FD30);
	};

	zCAICamera(void)
	{
		zAICamera();
	};

	static zCAICamera* Create(void)
	{
		XCALL(0x004A0180);
	};

	void StartUp(void)
	{
		XCALL(0x004A0230);
	};

	void CleanUp(void)
	{
		XCALL(0x004A0850);
	};

	static void GlobalStartUp(void)
	{
		XCALL(0x004A0880);
	};

	static void GlobalCleanUp(void)
	{
		XCALL(0x004A0890);
	};

	float GetBestRange(void)
	{
		XCALL(0x004A08F0);
	};

	float GetMinRange(void)
	{
		XCALL(0x004A09A0);
	};

	float GetMaxRange(void)
	{
		XCALL(0x004A09B0);
	};

	void SetMode(zSTRING&,zCArray<zCVob*>)
	{
		XCALL(0x004A09C0);
	};

	zSTRING GetMode(void)
	{
		XCALL(0x004A0D40);
	};

	int IsModeActive(zSTRING&)
	{
		XCALL(0x004A0D90);
	};

	int IsModeAvailable(zSTRING const&)
	{
		XCALL(0x004A0E10);
	};

	void ReceiveMsg(zTAICamMsg const&)
	{
		XCALL(0x004A0E30);
	};

	void SetVob(zCVob*)
	{
		XCALL(0x004A0E60);
	};

	void SetTarget(zCVob*)
	{
		XCALL(0x004A1120);
	};

	void SetTargetList(zCArray<zCVob*>)
	{
		XCALL(0x004A15B0);
	};

	void ClearTargetList(void)
	{
		XCALL(0x004A1870);
	};

	void AddTarget(zCVob*)
	{
		XCALL(0x004A18F0);
	};

	void SubTarget(zCVob*)
	{
		XCALL(0x004A1A40);
	};

	int Console_EvalFunc(zSTRING const&,zSTRING&)
	{
		XCALL(0x004A1AD0);
	};

	void ParameterChanged(void)
	{
		XCALL(0x004A23B0);
	};

	void CalcFirstPosition(void)
	{
		XCALL(0x004A2550);
	};

	int SetByScript(zSTRING&)
	{
		XCALL(0x004A26E0);
	};

	zSTRING SetByScriptLine(zSTRING&)
	{
		XCALL(0x004A2D30);
	};

	void CreateInstance(zSTRING&)
	{
		XCALL(0x004A3670);
	};

	void AI_LookingCam(void)
	{
		XCALL(0x004A3690);
	};

	void AI_FirstPerson(void)
	{
		XCALL(0x004A40E0);
	};

	void AI_Normal(void)
	{
		XCALL(0x004A4370);
	};

	zVEC3& GetCamSysFirstPos(void)
	{
		XCALL(0x004A4570);
	};

	void SetHintTargetInPortalRoom(int)
	{
		XCALL(0x004A4580);
	};

	void CheckKeys(void)
	{
		XCALL(0x004A45C0);
	};

	void SetRotateEnabled(int)
	{
		XCALL(0x004A54E0);
	};

	static zCObject* _CreateNewInstance(void)
	{
		XCALL(0x004A56E0);
	};

	void StartupDialogCam(void)
	{
		XCALL(0x004B1940);
	};

	static void GlobalDialogCamCleanUp(void)
	{
		XCALL(0x004B1DE0);
	};

	void InitDialogCam(void)
	{
		XCALL(0x004B1EE0);
	};

	void SetDialogCamDuration(float)
	{
		XCALL(0x004B1F20);
	};

	void ReleaseLastDialogCam(void)
	{
		XCALL(0x004B1F30);
	};

	zCCSCamera* PickPreset(zSTRING,zCArray<zCCSCamera*> const&)
	{
		XCALL(0x004B1FF0);
	};

	void StartDialogCam(int)
	{
		XCALL(0x004B20F0);
	};

	int DialogPresetIsValid(zCCSCamera*)
	{
		XCALL(0x004B4290);
	};

	void InitHelperVobs(void)
	{
		XCALL(0x004BB4A0);
	};

	void DeleteHelperVobs(void)
	{
		XCALL(0x004BB740);
	};

	void ShowDebug(void)
	{
		XCALL(0x004BB7B0);
	};

	void DrawClipLine(zVEC3 const&,zVEC3 const&, zCOLOR)
	{
		XCALL(0x004BCC00);
	};

	zTBSphere3D CalcMinimumBSphere(zCArray<zVEC3>&)
	{
		XCALL(0x004BCE60);
	};

	int CheckUnderWaterFX(void)
	{
		XCALL(0x004BD2E0);
	};

	zVEC3& CalcAziElevRange(float const&,float const&,float const&,zMAT4 const&)
	{
		XCALL(0x004BD7F0);
	};

	zSTRING GetPreviousMode(void)
	{
		XCALL(0x0069D800);
	};

	// ------------- AST -------------
	// [AST]
	void AI_FirstPerson_AST();
	// [/AST]
};

class oCAICamera : public zCAIBase
{
public:
	zCLASS(oCAICamera)
	zCTimer	localTimer;
public:
	static zCClassDef *classDef;
	void oAICamera(void)
	{
		XCALL(0x0069DD00);
	};

	oCAICamera(void)
	{
		oAICamera();
	};


	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0069DE40);
	};

	virtual ~oCAICamera()
	{
		XCALL(0x0069DE90);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0069DEA0);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0069DE50);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};

};

class oCAIHuman_Stand : public zCAIBase
{
public:
	zCLASS(oCAIHuman_Stand)
	static zCClassDef *classDef;

	void oAIHuman_Stand(zCVob*)
	{
		XCALL(0x0069E0E0);
	};

	oCAIHuman_Stand(zCVob* vob)
	{
		oAIHuman_Stand(vob);
	};


	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0069E200);
	};

	virtual ~oCAIHuman_Stand()
	{
		XCALL(0x0069E240);
	};

	virtual void DoAI(zCVob*,int&)
	{
		XCALL(0x0069E250);
	};

	virtual int CanThisCollideWith(zCVob*)
	{
		XCALL(0x0048BD30);
	};

	virtual void ReportCollisionToAI(zCCollisionReport const&)
	{
		XCALL(0x0048BDF0);
	};

	virtual int HasAIDetectedCollision(void)
	{
		XCALL(0x0048BD40);
	};

	virtual void AICollisionResponseSelfDetected(zVEC3 const&,int&)
	{
		XCALL(0x0048BD50);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BD60);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x0048BE00);
	};

	virtual int GetIsProjectile(void)
	{
		XCALL(0x0048BE10);
	};
};


