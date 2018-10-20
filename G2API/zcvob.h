#pragma once

#include "ztypes.h"

class zCModelNodeInst;
class zCVob;
class zCVobLight;
class zCEventManager;
class zCWorld;
class zCAIBase;
class zCEventMessage;
class zCBuffer;
class zCZone;
class zCVobBBox3DSorter;
class zCCamera;
class zCEventManager;
class zCRigidBody;
class zCCollisionObject;
class zCCollisionObjectDef;
class zCCollisionDetector;
class zCCollisionReport;
class zCPolygon;
class zCVertex;
class zCMaterial;
class zCBspLeaf;
class zCVisual;
enum zTCam_AlignType;

#define zTRACERAY_DEFAULT					0x00000000
#define zTRACERAY_VOB_CHECK_COLLDET			0x00000001
#define zTRACERAY_IGNORE_VOBS				0x00000002
#define zTRACERAY_VOB_CHECK_BBOX_ONLY		0x00000004
#define zTRACERAY_UNUSED_8					0x00000008
#define zTRACERAY_IGNORE_LEVEL				0x00000010
#define zTRACERAY_LEVEL_FIND_NEAREST_INTERS	0x00000020
#define zTRACERAY_ALLOW_PORTALS				0x00000040
#define zTRACERAY_CALC_NORMAL				0x00000080
#define zTRACERAY_IGNORE_TRANSPARENT		0x00000100
#define zTRACERAY_ALLOW_WATER				0x00000200
#define zTRACERAY_TWO_SIDED					0x00000400
#define zTRACERAY_IGNORE_CHARACTERS			0x00000800
#define zTRACERAY_VOB_FIND_ANY_INTERS		0x00001000
#define zTRACERAY_ALLOW_HELPERS				0x00002000
#define zTRACERAY_ALLOW_PROJECTILES			0x00004000	

enum zTFlareType
{
	zFT_CORONA,
	zFT_GLOW,
	zFT_FLARE
};

enum zTVobType
{	
	zVOB_TYPE_NORMAL, 
	zVOB_TYPE_LIGHT,
	zVOB_TYPE_SOUND,
	
	zVOB_TYPE_LEVEL_COMPONENT,
	
	zVOB_TYPE_SPOT,
	zVOB_TYPE_CAMERA,
	zVOB_TYPE_STARTPOINT,
	zVOB_TYPE_WAYPOINT,
	zVOB_TYPE_MARKER,
	zVOB_TYPE_SEPARATOR	=127,
	
	zVOB_TYPE_MOB		=128,
	zVOB_TYPE_ITEM		=129,
	zVOB_TYPE_NSC		=130
};

enum zTVobSleepingMode
{
	zVOB_SLEEPING				=0, 
	zVOB_AWAKE					=1,  
	zVOB_AWAKE_DOAI_ONLY		=2 
};

enum zTAnimationMode
{
	zVISUAL_ANIMODE_NONE	= 0,
	zVISUAL_ANIMODE_WIND,
	zVISUAL_ANIMODE_WIND2,
};

class zCVobCallback			
{
public:
	virtual void HandleVob(zCVob*, void*) = 0;
};

enum zTVisualCamAlign
{
	zVISUAL_CAMALIGN_NONE=0,
	zVISUAL_CAMALIGN_YAW,
	zVISUAL_CAMALIGN_FULL,
	zVISUAL_CAMALIGN_COUNT
};

struct zTTraceRayReport		
{
	BOOL		m_bIntersect;	
	zCVob*		m_pVob;			
	zCPolygon*	m_pPolygon;		
	zVEC3		m_vIntersect;	
	zVEC3		m_vNormal;		
	zCVertex*	m_pVertex;		

	void Reset() { m_bIntersect = FALSE; m_pVob = NULL; m_pPolygon = NULL; m_vIntersect = zVEC3(0, 0, 0); m_vNormal = zVEC3(0, 0, 0); m_pVertex = NULL;}
};

struct zTRenderContext
{
	int					clipFlags;
	zCVob				*vob;
	zCWorld				*world;
	zCCamera			*cam;
	float				distVobToCam;
	zTVisualCamAlign	visualCamAlign;
	zTAnimationMode		m_AniMode;
	float				m_aniModeStrength;

	zCOLOR				hintLightingHighlightColor;			
	struct {
		UINT8			hintLightingFullbright		: 1;	
		UINT8			hintLightingSwell			: 1;	
		UINT8			hintLightingHighlight		: 1;	
	};
		
	void		Clear	()	{ memset (this, 0, sizeof(*this)); clipFlags=-1; };
};

enum zTRigidBodyMode : BYTE
{
	zRIGID_GRAVITY,
	zRIGID_SLIDING
};

class zCRigidBody
{
public:
	struct BIT_ARRAY
	{
		BYTE		     tGravity:1;
		BYTE	 	     tCollision:1;
		zTRigidBodyMode  tMode:1;
		BYTE		     tCount:4;
	};
	float			m_fForceScale;		
	float			m_fImpulseScale;	
	zMAT3			m_mInertiaTensor;	
	zMAT3			m_mInvInertiaTensor;
	zVEC3			m_vPoint;			
	zMAT3			us5C;
	zVEC3			m_vImpulseVelo;		
	zVEC3			m_vImpulseRot;		
	zMAT3			us98;
	zVEC3			m_vVelocity;		
	zVEC3			m_vRotation;		
	zVEC3			m_vForceVelo;		
	zVEC3			m_vRorceRot;		
	float			m_fGravityScale;	
	zVEC3			m_vSlideDir;		
	float			m_fSlideAngle;		
	union
	{
		BYTE		m_dbFlags;			
		BIT_ARRAY	f;
	};
public:

	zCRigidBody(void)
	{
		XCALL(0x005B5660);
	};

	void ComputeForceTorque(float)
	{
		XCALL(0x005B5730);
	};

	zMAT3 Star(zVEC3 const&)
	{
		XCALL(0x005B5740);
	};

	int SetSliding(zVEC3 const&)
	{
		XCALL(0x005B57C0);
	};

	void Integrate(float)
	{
		XCALL(0x005B5A50);
	};

	void RunSimulation(void)
	{
		XCALL(0x005B5CF0);
	};

	void SetInertiaTensorBlock(float,float,float)
	{
		XCALL(0x005B5D20);
	};

	void ApplyForceCM(zVEC3 const&)
	{
		XCALL(0x005B5DB0);
	};

	void ApplyForce(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005B5DF0);
	};

	zVEC3 GetPointVelocity(zVEC3 const&)const 
	{
		XCALL(0x005B5E30);
	};

	void ApplyImpulseCM(zVEC3 const&)
	{
		XCALL(0x005B5EB0);
	};

	void ApplyImpulse(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005B5F20);
	};

	void CollisionImpulseStatic(zVEC3 const&,zVEC3 const&,float)
	{
		XCALL(0x005B5F90);
	};

	void CollisionImpulseCenterStatic(zVEC3 const&,float)
	{
		XCALL(0x005B60A0);
	};

	void CollisionImpulse(zVEC3 const&,zVEC3 const&,float,zCRigidBody*)
	{
		XCALL(0x005B6290);
	};

	void StopRotation(void)
	{
		XCALL(0x005B6450);
	};

	void StopTranslation(void)
	{
		XCALL(0x005B64F0);
	};

	void StopTransRot(void)
	{
		XCALL(0x005B6590);
	};

	void SetVelocity(zVEC3 const&)
	{
		XCALL(0x005B66D0);
	};

	void SetMode(zTRigidBodyMode const&)
	{
		XCALL(0x005B6770);
	};

	int ShouldSlide(zVEC3 const&)const 
	{
		XCALL(0x005B6790);
	};

	void Archive(zCArchiver&)
	{
		XCALL(0x005B6930);
	};

	void Unarchive(zCArchiver&)
	{
		XCALL(0x005B69B0);
	};
};

class zCVob : public zCObject
{
public:
	zCLASS(zCVob);
	enum zTVobCharClass
	{
		zVOB_CHAR_CLASS_NONE, 
		zVOB_CHAR_CLASS_PC, 
		zVOB_CHAR_CLASS_NPC
	};

	enum zTMovementMode
	{
		zMOVEMENT_NONE,		
		zMOVEMENT_ALREADY,	
		zMOVEMENT_PHASE		
	};

	enum zTVisualAniMode
	{
		NONE,				
		WIND,				
		WIND2				
	};

	enum zTDynShadowType
	{
		zDYN_SHADOW_TYPE_NONE=0,
		zDYN_SHADOW_TYPE_BLOB,
		zDYN_SHADOW_TYPE_COUNT
	};

	struct zTModelLimbColl
	{
		zCVob					*hitVob;
		zCMaterial				*hitMaterial;
		zCList<zCModelNodeInst> hitModelNodeList;
		zVEC3					approxCollisionPos;

		zTModelLimbColl()
		{
			XCALL(0x00603A20);
		};

		~zTModelLimbColl()
		{
			XCALL(0x00603A50);
		};
	};

	struct zTCollisionContext
	{
		zCArray<zCCollisionObject*>	m_arrCollObject;
		zCArray<zCVob*>				m_arrVobs;
	};

	zCTree<zCVob>		*globalVobTreeNode;
	zTFrameCtr			lastTimeDrawn;
	DWORD				lastTimeCollected;

	zCArray<zCBspLeaf*>	vobLeafList;
	zMAT4				trafoObjToWorld;
	zTBBox3D			bbox3D;

	zTBSphere3D			bsphere3D;
	zCArray<zCVob*>		touchVobList;
	zTVobType			type;
	DWORD				groundShadowSizePacked;	
	zCWorld				*homeWorld;
	zCPolygon			*groundPoly;
	zCAIBase			*callback_ai;
	zMAT4				*trafo;

	zCVisual			*visual;
	float				visualAlpha;
	float				m_fVobFarClipZScale;
	zTAnimationMode		m_AniMode;
	float				m_aniModeStrength;
	int					m_zBias;

	zCRigidBody			*rigidBody;

	zCOLOR				lightColorStat;
	zCOLOR				lightColorDyn;
	zVEC3				lightDirectionStat;
	zSTRING				*vobPresetName;

	zCEventManager		*eventManager;
	float				nextOnTimer;
	
	struct {			
		UINT8			showVisual					: 1;
		UINT8			drawBBox3D					: 1;
		UINT8			visualAlphaEnabled			: 1;	
		UINT8			physicsEnabled				: 1;
		UINT8			staticVob					: 1;
		UINT8			ignoredByTraceRay			: 1;	
		UINT8			collDetectionStatic			: 1;
		UINT8			collDetectionDynamic		: 1;
		UINT8			castDynShadow				: 2;
		UINT8			lightColorStatDirty			: 1;	
		UINT8			lightColorDynDirty			: 1;	
		zTMovementMode	isInMovementMode			: 2;
		UINT8			sleepingMode				: 2;	
		UINT8			mbHintTrafoLocalConst		: 1;
		UINT8			mbInsideEndMovementMethod	: 1;
		zTVisualCamAlign visualCamAlign				: 2;
		UINT8			collButNoMove				: 4;
		UINT8			dontWriteIntoArchive		: 1;
		UINT8			bIsInWater					: 1;
		UINT8			bIsAmbientVob				: 1;
	};
	
	zCCollisionObjectDef*			m_poCollisionObjectClass;
	zCCollisionObject*				m_poCollisionObject;
	static int zCVob::s_renderVobs;
	static int zCVob::s_enableAnimations;
	static int zCVob::s_vobAlreadyInMovement;
	static zCMesh*& zCVob::s_shadowMesh;
	static unsigned long zCVob::s_nextFreeID;
	static int zCVob::s_ignoreVisuals;
	static int zCVob::s_showHelperVisuals;
	static zCCollisionDetector*& zCVob::s_poCollisionDetector;
	static zCClassDef			*classDef;
public:
	virtual zCClassDef* _GetClassDef				(void)const															{XCALL(0x0043CCB0)};
	virtual void		OnTrigger					(zCVob*,zCVob*)														{XCALL(0x005FE170)};
	virtual void		 OnUntrigger				(zCVob*,zCVob*)														{XCALL(0x005FE180)};
	virtual void		OnTouch						(zCVob*)															{XCALL(0x005FE190)};
	virtual void		OnUntouch					(zCVob*)															{XCALL(0x005FE1A0)};
	virtual void		OnTouchLevel				(void)																{XCALL(0x005FE1B0)};
	virtual void		OnDamage					(zCVob*,zCVob*,float,int,zVEC3 const&)								{XCALL(0x005FE1C0)};
	virtual void		OnMessage					(zCEventMessage*,zCVob*)											{XCALL(0x005FE1D0)};
	virtual ~zCVob									()																	{XCALL(0x100034C0)};
	virtual void		OnTick						()																	{XCALL(0x00404270)};						
	virtual void		OnTimer						()																	{XCALL(0x0043CCC0)};						
	virtual void		PostLoad					()																	{XCALL(0x00404280)};					
	virtual zTVobCharClass GetCharacterClass		()																	{XCALL(0x00404290)};
	virtual void		SetSleepingMode				(const zTVobSleepingMode smode)										{XCALL(0x00602960)};
	virtual void		EndMovement					(const BOOL a_bHintTrafoChanged=TRUE)								{XCALL(0x0061E0D0)};	
	virtual BOOL		CanThisCollideWith			(zCVob* vob)														{ return TRUE; };		
	virtual BOOL __fastcall  Render					(zTRenderContext &renderContext)									{XCALL(0x006015D0)};	
	virtual void		SetVisual					(zCVisual *v)														{XCALL(0x006024F0)};	
	virtual void		SetVisual					(const zSTRING& visualFileName)										{XCALL(0x00602680)};	
	
	virtual BOOL		GetScriptInstance			(zSTRING* &scriptInstanceName, int &scriptInstanceIndex)			{ scriptInstanceName=0; scriptInstanceIndex=0; return FALSE;	};	
	virtual BOOL		SetByScriptInstance			(const zSTRING* scriptInstanceName, const int scriptInstanceIndex)	{ return FALSE;	};	
	
	
	virtual int			GetCSStateFlags				()																	{ XCALL(0x004042E0)		};	
	
	virtual BOOL		TraceRay					(const zVEC3&rayOrigin,const zVEC3&ray, const int traceFlags, zTTraceRayReport&report)									{XCALL(0x005FFE40)};
	
	virtual const zSTRING*	GetTriggerTarget		(const int i=0) const												{ XCALL(0x0043CCD0)						};	
	virtual void		ThisVobAddedToWorld			(zCWorld *homeWorld)												{XCALL(0x00601C80)};		
	virtual void		ThisVobRemovedFromWorld		(zCWorld *homeWorld)												{XCALL(0x00601CA0)};		
	virtual void		Archive						(zCArchiver &arc)													{XCALL(0x005FF140)};
	virtual void		Unarchive					(zCArchiver &arc)													{XCALL(0x005FFC70)};
public:
	void zVob(void)
	{
		XCALL(0x005FE1E0);
	};

	zCVob(void)
	{
		zVob();
	};

	zVEC3 GetPositionWorld(void)const 
	{
		XCALL(0x0052DC90);
	};

	zVEC3 GetAtVectorWorld(void)const 
	{
		XCALL(0x0052DCB0);
	};

	zVEC3 GetUpVectorWorld(void)const 
	{
		XCALL(0x0052DCD0);
	};

	zVEC3 GetRightVectorWorld(void)const 
	{
		XCALL(0x0052DCF0);
	};

	static void InitVobSystem(void)
	{
		XCALL(0x005FE6E0);
	};

	static void CleanupVobSystem(void)
	{
		XCALL(0x005FE800);
	};

	static void ResetIDCtr(void)
	{
		XCALL(0x005FE8C0);
	};

	static unsigned long GetNextFreeVobID(void)
	{
		XCALL(0x005FE8D0);
	};

	void SetVobID(unsigned long const&)
	{
		XCALL(0x005FE8E0);
	};

	void SetAI(zCAIBase*)
	{
		XCALL(0x005FE8F0);
	};

	void SetVobPresetName(zSTRING const&)
	{
		XCALL(0x005FE940);
	};

	zSTRING const& GetVobPresetName(void)const 
	{
		XCALL(0x005FE950);
	};

	zCRigidBody* GetRigidBody(void)
	{
		XCALL(0x005FE960);
	};

	void __fastcall ArchivePacked(zCArchiver&)
	{
		XCALL(0x005FE9D0);
	};

	void __fastcall ArchiveVerbose(zCArchiver&)
	{
		XCALL(0x005FEDB0);
	};

	void __fastcall UnarchivePacked(zCArchiver&,int)
	{
		XCALL(0x005FF200);
	};

	void __fastcall UnarchiveVerbose(zCArchiver&)
	{
		XCALL(0x005FF720);
	};

	void SetVobName(zSTRING const&)
	{
		XCALL(0x005FFDD0);
	};

	zCEventManager* __fastcall GetEM(const BOOL dontCreateIfNotPresent=FALSE)
	{
		XCALL(0x005FFE10);
	};

	zCOLOR CalcLightSampleAtOrigin(void)
	{
		XCALL(0x00600130);
	};

	zCOLOR GetLightColorStat(void)
	{
		XCALL(0x006001B0);
	};

	zCOLOR GetLightColorStatGroundPoly(void)
	{
		XCALL(0x00600440);
	};

	zCOLOR GetLightColorDyn(void)
	{
		XCALL(0x00600470);
	};

	int __fastcall CalcStaticLight(zVEC3&)const 
	{
		XCALL(0x00600650);
	};

	zSTRING const* GetSectorNameVobIsIn(void)const 
	{
		XCALL(0x00600AE0);
	};

	static void LoadGroundShadowMesh(void)
	{
		XCALL(0x00600B00);
	};

	static void DeleteGroundShadowMesh(void)
	{
		XCALL(0x00600C00);
	};

	void __fastcall SetGroundShadowSize(zVEC2 const&)
	{
		XCALL(0x00600C30);
	};

	zVEC2 __fastcall GetGroundShadowSize(void)const 
	{
		XCALL(0x00600C80);
	};

	void __fastcall RenderGroundShadow(zTRenderContext&)
	{
		XCALL(0x00600CD0);
	};

	zCVisual* GetClassHelperVisual(void)const 
	{
		XCALL(0x006011E0);
	};

	void CalcRenderAlpha(float,zCVisual*&,float&)
	{
		XCALL(0x006013E0);
	};

	zCOLOR GetLightColorAtCenter(void)const 
	{
		XCALL(0x00601AC0);
	};

	void RemoveVobFromWorld(void)
	{
		XCALL(0x00601C40);
	};

	void RemoveVobSubtreeFromWorld(void)
	{
		XCALL(0x00601C60);
	};

	void AddRefVobSubtree(zCTree<zCVob>* pVobTree = NULL,int unk = FALSE)
	{
		XCALL(0x00601CC0);
	};

	void ReleaseVobSubtree(zCTree<zCVob>* pVobTree = NULL)
	{
		XCALL(0x00601D40);
	};

	void RemoveWorldDependencies(int)
	{
		XCALL(0x00601DA0);
	};

	void RemoveVobFromGlobalVobTree(void)
	{
		XCALL(0x00601FF0);
	};

	void RemoveVobFromBspTree(void)
	{
		XCALL(0x006020E0);
	};

	zSTRING GetVobInfo(void)
	{
		XCALL(0x00602100);
	};

	void SetSleeping(int)
	{
		XCALL(0x00602930);
	};

	void UpdateVisualDependencies(int)
	{
		XCALL(0x00602B20);
	};

	void AddVobToWorld_CorrectParentDependencies(void)
	{
		XCALL(0x00602BB0);
	};

	void ResetOnTimer(void)
	{
		XCALL(0x00602BD0);
	};

	void SetOnTimer(float)
	{
		XCALL(0x00602BE0);
	};

	int IsOnTimer(void)const 
	{
		XCALL(0x00602C10);
	};

	void ProcessOnTimer(void)
	{
		XCALL(0x00602C30);
	};

	void DoFrameActivity(void)
	{
		XCALL(0x00602C60);
	};

	void CheckModelLimbCollision(zCModelNodeInst*,int,class zCList<zTModelLimbColl>&)
	{
		XCALL(0x00602ED0);
	};

	void CheckModelLimbCollisionLevel(zCModelNodeInst*,int,zCList<zTModelLimbColl>&)
	{
		XCALL(0x00603A80);
	};

	void CheckModelLimbCollisionPolys(zCModelNodeInst*,int,zCPolygon**,int const &,zCList<zTModelLimbColl>&)
	{
		XCALL(0x00604710);
	};

	zMAT4 GetTrafoModelNodeToWorld(zSTRING const&)
	{
		XCALL(0x00604960);
	};

	zMAT4 GetTrafoModelNodeToWorld(zCModelNodeInst*)
	{
		XCALL(0x00604A50);
	};

	zTBBox2D GetScreenBBox2D(void)
	{
		XCALL(0x00604AE0);
	};

	static void RepairIllegalFloats(zMAT4&)
	{
		XCALL(0x00604F10);
	};

	void PackStateBinary(zCBuffer&)const 
	{
		XCALL(0x00605110);
	};

	void UnpackStateBinary(zCBuffer&)
	{
		XCALL(0x006051C0);
	};

	int GetIsProjectile(void)const 
	{
		XCALL(0x00606C00);
	};

	zCVisual* GetVisual(void)const 
	{
		XCALL(0x00616B20);
	};

	static zCVob* GetAutoLinkParent(zCVob*)
	{
		XCALL(0x0061A6C0);
	};

	static int CanAutoLinkWith(zCVob*,zCVob*)
	{
		XCALL(0x0061A700);
	};

	static void CheckAutoLink(zCVob*,zCVob*)
	{
		XCALL(0x0061A840);
	};

	static void CheckAutoUnlink(zCVob*)
	{
		XCALL(0x0061AAC0);
	};

	void CalcGroundPoly(void)
	{
		XCALL(0x0061ACD0);
	};

	void CalcWaterVob(void)
	{
		XCALL(0x0061AE20);
	};

	void SetCollTypeDefaultFromVisual(void)
	{
		XCALL(0x0061AEF0);
	};

	void TouchMovement(void)
	{
		XCALL(0x0061B060);
	};

	zMAT4 const& GetNewTrafoObjToWorld(void)const 
	{
		XCALL(0x0061B080);
	};

	zMAT4& GetNewTrafoObjToWorld(void)
	{
		XCALL(0x0061B0A0);
	};

	void SetNewTrafoObjToWorld(zMAT4 const&)
	{
		XCALL(0x0061B0C0);
	};

	void SetBBox3DWorld(zTBBox3D const&)
	{
		XCALL(0x0061B0E0);
	};

	void SetBBox3DLocal(zTBBox3D const&)
	{
		XCALL(0x0061B140);
	};

	zTBBox3D GetBBox3DLocal(void)const 
	{
		XCALL(0x0061B1F0);
	};

	void Move(float,float,float)
	{
		XCALL(0x0061B2E0);
	};

	void MoveWorld(float,float,float)
	{
		XCALL(0x0061B350);
	};

	void MoveLocal(float,float,float)
	{
		XCALL(0x0061B3C0);
	};

	void SetRotationWorld(zCQuat const&)
	{
		XCALL(0x0061B4C0);
	};

	void RotateWorld(zVEC3 const&,float)
	{
		XCALL(0x0061B520);
	};

	void RotateLocal(zVEC3 const&,float)
	{
		XCALL(0x0061B610);
	};

	void RotateLocalX(float)
	{
		XCALL(0x0061B6B0);
	};

	void RotateLocalY(float)
	{
		XCALL(0x0061B720);
	};

	void RotateLocalZ(float)
	{
		XCALL(0x0061B790);
	};

	void RotateWorldX(float)
	{
		XCALL(0x0061B800);
	};

	void RotateWorldY(float)
	{
		XCALL(0x0061B830);
	};

	void RotateWorldZ(float)
	{
		XCALL(0x0061B860);
	};

	void GetPositionWorld(float&,float&,float&)const 
	{
		XCALL(0x0061B890);
	};

	void GetPositionLocal(float&,float&,float&)const 
	{
		XCALL(0x0061B8C0);
	};

	float GetDistanceToVob(zCVob&)
	{
		XCALL(0x0061B910);
	};

	float GetDistanceToVobApprox(zCVob&)
	{
		XCALL(0x0061B970);
	};

	float GetDistanceToVob2(zCVob&)
	{
		XCALL(0x0061BA40);
	};

	void SetPositionLocal(zVEC3 const&)
	{
		XCALL(0x0061BAA0);
	};

	void SetPositionWorld(zVEC3 const&)
	{
		XCALL(0x0061BB70);
	};

	void SetTrafo(zMAT4 const&)
	{
		XCALL(0x0061BBD0);
	};

	void SetTrafoObjToWorld(zMAT4 const&)
	{
		XCALL(0x0061BC80);
	};

	void ResetRotationsLocal(void)
	{
		XCALL(0x0061BCF0);
	};

	void ResetXZRotationsLocal(void)
	{
		XCALL(0x0061BE20);
	};

	void ResetRotationsWorld(void)
	{
		XCALL(0x0061C000);
	};

	void ResetXZRotationsWorld(void)
	{
		XCALL(0x0061C090);
	};

	void SetHeadingYLocal(zVEC3 const&)
	{
		XCALL(0x0061C1B0);
	};

	void SetHeadingYWorld(zVEC3 const&)
	{
		XCALL(0x0061C280);
	};

	void SetHeadingYWorld(zCVob*)
	{
		XCALL(0x0061C450);
	};

	void SetHeadingLocal(zVEC3 const&)
	{
		XCALL(0x0061C5E0);
	};

	void SetHeadingWorld(zVEC3 const&)
	{
		XCALL(0x0061C6B0);
	};

	void SetHeadingWorld(zCVob*)
	{
		XCALL(0x0061C780);
	};

	void SetHeadingAtLocal(zVEC3 const&)
	{
		XCALL(0x0061C860);
	};

	int HasParentVob(void)const 
	{
		XCALL(0x0061CBA0);
	};

	void SetHeadingAtWorld(zVEC3 const&)
	{
		XCALL(0x0061CBC0);
	};

	void __fastcall SetCollDetStat(int)
	{
		XCALL(0x0061CE50);
	};

	void __fastcall SetCollDetDyn(int)
	{
		XCALL(0x0061CF40);
	};

	void CorrectTrafo(void)
	{
		XCALL(0x0061D040);
	};

	void DoneWithTrafoLocal(void)
	{
		XCALL(0x0061D0B0);
	};

	void CreateTrafoLocal(void)const 
	{
		XCALL(0x0061D100);
	};

	void SetPhysicsEnabled(int)
	{
		XCALL(0x0061D190);
	};

	zVEC3 GetVelocity(void)
	{
		XCALL(0x0061D1C0);
	};

	void UpdatePhysics(void)
	{
		XCALL(0x0061D2D0);
	};

	int DetectCollision(zMAT4*)
	{
		XCALL(0x0061D890);
	};

	void __fastcall SetInMovement(int)
	{
		XCALL(0x0061D9D0);
	};

	void __fastcall SetInMovementMode(zTMovementMode)
	{
		XCALL(0x0061DA30);
	};

	void BeginMovement(void)
	{
		XCALL(0x0061DA80);
	};

	void ResetToOldMovementState(void)
	{
		XCALL(0x0061DC00);
	};

	void __fastcall UpdateTouchList(zCArray<zCVob*> const&)
	{
		XCALL(0x0061DC30);
	};

	void __fastcall CalcDestinationBBox3DWorld(zTBBox3D&)
	{
		XCALL(0x0061DEE0);
	};

	void AdoptCollObjResults(void)
	{
		XCALL(0x0061E020);
	};

	void SetCollisionObject(zCCollisionObject*)
	{
		XCALL(0x0061E5E0);
	};

	void SetCollisionClass(int*)
	{
		XCALL(0x0061E610);
	};

	zCCollisionObject* GetCollisionObject(void)const 
	{
		XCALL(0x0061E650);
	};

	void CreateCollisionObject(void)
	{
		XCALL(0x0061E660);
	};

	void ResetCollisionObjectState(void)
	{
		XCALL(0x0061E690);
	};

	void __fastcall DestroyCollisionObject(int)
	{
		XCALL(0x0061E6D0);
	};

	void CheckEmergencyPutToSleep(void)
	{
		XCALL(0x0061E710);
	};

	void __fastcall CollectCollisionContext_Vobs(zTBBox3D const&,zTCollisionContext&)
	{
		XCALL(0x0061E870);
	};

	void __fastcall CollectCollisionContext_Static(zTBBox3D const&,zCArray<zCCollisionObject*>&)
	{
		XCALL(0x0061EAD0);
	};

	void __fastcall CollectCollisionContext(zTCollisionContext&)
	{
		XCALL(0x0061EDC0);
	};

	void __fastcall CleanupCollisionContext(zTCollisionContext const&)
	{
		XCALL(0x0061EE40);
	};

	void __fastcall NotifyCollisionPair(zCCollisionReport*,zCArray<zCCollisionReport*> const&,int)
	{
		XCALL(0x0061EEB0);
	};

	void __fastcall ExecuteCollisionResponse(zCArray<zCCollisionReport*> const&,int&)
	{
		XCALL(0x0061EF80);
	};

	void CheckAndResolveCollisions(void)
	{
		XCALL(0x0061F060);
	};

	int IsColliding(void)
	{
		XCALL(0x0061F4F0);
	};

	static void SetShowHelperVisuals(int)
	{
		XCALL(0x00637110);
	};

	static int GetShowHelperVisuals(void)
	{
		XCALL(0x00637120);
	};

	static int GetAnimationsEnabled(void)
	{
		XCALL(0x00637130);
	};

	static void SetAnimationsEnabled(int)
	{
		XCALL(0x00637140);
	};

	zCWorld* GetHomeWorld(void)const 
	{
		XCALL(0x006742A0);
	};

	void SetStaticVob(int)
	{
		XCALL(0x006CFFB0);
	};

	zTVobType GetVobType(void)const 
	{
		XCALL(0x006CFFD0);
	};

	void SetDrawBBox3D(int)
	{
		XCALL(0x006CFFE0);
	};

	void SetCollDet(int)
	{
		XCALL(0x006D0000);
	};
};

class zCLensFlareFX : public zCObject	
{
	friend class zCVobLightData;
	friend class zCVobLensFlare;
	friend class zCSkyControler_Outdoor;
	class zTVobLightLensFlare			
	{
		friend class zCLensFlareFX;
		zCMaterial*		m_pMaterial;	
		zTFlareType		m_nType;		
		float			m_fSize;		
		float			m_fAlpha;		
		float			m_fRangeMin;	
		float			m_fRangeMax;	
		float			m_fPosScale;	
	public:
		void zVobLightLensFlare(void)
		{
			XCALL(0x00563020);
		};

		zTVobLightLensFlare(void)
		{
			zVobLightLensFlare();
		};
	};
	zCArray<zTVobLightLensFlare>	m_arrFlares;	
	int								m_nType;		
	static zCClassDef *classDef;
	static zCMesh*& zCLensFlareFX::s_lensFlareMesh;
	static zCMesh*& zCLensFlareFX::s_coronaMesh;
	static zCMesh*& zCLensFlareFX::s_glowMesh;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00562610);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00562AA0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00562BF0);
	};

	virtual ~zCLensFlareFX(void)
	{
		XCALL(0x005629F0);
	};

	static void LoadLensFlareScript(void)
	{
		XCALL(0x00562650);
	};

	static void ReleaseLensFlareScript(void)
	{
		XCALL(0x00562940);
	};

	void RenderLensFlares(zCVob*)
	{
		XCALL(0x00563040);
	};

	void RenderLensFlares(zVEC2&)
	{
		XCALL(0x00563880);
	};

	void SetAlpha(int)
	{
		XCALL(0x00563A10);
	};
};

class zCVobStair : public zCVob
{
public:
	static zCClassDef *classDef;
};



