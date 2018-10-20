#pragma once

#include "zkbspline.h"
#include "zparticle.h"
#include "zcmaterial.h"


class zCVob;
class zCWorld;
class zCConsole;
class zCOBBox3D;


const int MAX_SPL_LEVEL		= 20;

enum zTVFXState
{
	zVFXSTATE_UNDEF		= 0,
	zVFXSTATE_OPEN		= 1,
	zVFXSTATE_INIT		= 2,
	zVFXSTATE_INVESTNEXT= 3,
	zVFXSTATE_CAST		= 4,
	zVFXSTATE_STOP		= 5,
	zVFXSTATE_COLLIDE	= 6
};

enum TEmTrajectoryMode
{
	EM_TRJ_UNDEF		= 0,
	EM_TRJ_FIXED		= 1,		
	EM_TRJ_TARGET		= 2,		
	EM_TRJ_LINE			= 4,
	EM_TRJ_SPLINE		= 8,
	EM_TRJ_RANDOM		= 16,
	EM_TRJ_CIRCLE		= 32,
	EM_TRJ_FOLLOW		= 64,
	EM_TRJ_MISSILE		= 128
};

enum TTrjLoopMode
{
	TRJ_LOOP_NONE		= 0,
	TRJ_LOOP_RESTART	= 1,
	TRJ_LOOP_PINGPONG	= 2,
	TRJ_LOOP_HALT		= 3,
	TRJ_LOOP_PINGPONG_ONCE= 4
};

enum TEaseFunc
{
	TEASEFUNC_LINEAR  = 0,
	TEASEFUNC_SINE	  = 1,
	TEASEFUNC_EXP	  = 2
};

enum TActionColl
{
	TACTION_COLL_NONE	 = 0,
	TACTION_COLL_COLLIDE = 1,
	TACTION_COLL_BOUNCE  = 2,
	TACTION_COLL_CREATE  = 4,
	TACTION_COLL_CREATE_ONCE  = 8,
	TACTION_COLL_NORESP	 = 16,
	TACTION_COLL_CREATE_QUAD = 32
};

const int   VFX_MAX_POS_SAMPLES		= 10;
const int   VFX_NUM_USERSTRINGS		= 5;
const float VFX_LIFESPAN_FOREVER	= -1;

class zCPositionKey			
{
	friend class oCTrajectory;
	friend class zCKBSpline;

public:
    
    float		t;
    
    zVEC3		p;
	
	zCQuat		rot;
    
    float		tension, continuity, bias;
public:
	~zCPositionKey()
	{
		XCALL(0x0048ABE0);
	};

	void SetMat(zMAT4 const&)
	{
		XCALL(0x00490F20);
	};

	zMAT4 GetMat(void)
	{
		XCALL(0x00498AC0);
	};
};

class oCTrajectory
{
	zCArray<zCPositionKey*>	keyList;

	zCKBSpline				*spl;
	int						mode;
	float					length;
	zMAT4					res;
	int						lastKey;
public:
	void Calc(void)
	{
		XCALL(0x00487960);
	};

	void Changed(void)
	{
		XCALL(0x00487CF0);
	};

	zMAT4 Interpolate(float)
	{
		XCALL(0x00487D00);
	};

	zMAT4 InterpolateN(float)
	{
		XCALL(0x00488130);
	};

	void Draw(void)
	{
		XCALL(0x00488240);
	};

	void Clear(void)
	{
		XCALL(0x00488500);
	};

	zVEC3 RecalcByColl(zVEC3 const&,zVEC3 const&,zVEC3 const&,int)
	{
		XCALL(0x004885D0);
	};

	void ApplyGrav(float const&)
	{
		XCALL(0x00488A40);
	};

	void SetByList(zCArray<zCVob*>)
	{
		XCALL(0x00488AB0);
	};

	int VobCross(zCVob const*)
	{
		XCALL(0x00488C20);
	};

	~oCTrajectory(void)
	{
		XCALL(0x00489F50);
	};

	void InsertKey(zMAT4&)
	{
		XCALL(0x00490F50);
	};

	zMAT4 GetKey(int)
	{
		XCALL(0x00491060);
	};

	int GetNumKeys(void)
	{
		XCALL(0x004910E0);
	};
};

struct zSVisualFXColl		
{
	zCVob*	foundVob;
	zVEC3 foundContactPoint;
	zVEC3	foundNormal;
};

class zCDecal : public zCVisual
{
public:
	zCMaterial		*decalMaterial;
	float			xdim;	
	float			ydim;
	float			xoffset;
	float			yoffset;
	BOOL			decal2Sided;
	BOOL			ignoreDayLight;
	BOOL			m_bOnTop;
	static zCClassDef*	classDef;
public:

	virtual zCClassDef* _GetClassDef			()const																{XCALL(0x00556550);};
	
	BOOL			Render						(zTRenderContext& renderContext)									{XCALL(0x00556990);};	
	BOOL			IsBBox3DLocal				()																	{ return TRUE; };		
	zTBBox3D		GetBBox3D					()																	{XCALL(0x00556B30);};
	zSTRING			GetVisualName				()																	{XCALL(0x00556B80);};
	void			SetVisualUsedBy				(zCVob* vob)														{XCALL(0x00556B10);};
	void			DynLightVisual				(const zCArray<zCVobLight*>& vobLightList, zMAT4 *trafoObjToWorld=0){XCALL(0x00556C60);};
	DWORD			GetRenderSortKey			()const																{XCALL(0x00556940);};
	
	virtual BOOL	GetAlphaTestingEnabled		()const																{XCALL(0x00556BE0);};
	virtual	~zCDecal()																								{XCALL(0x00556640);};		
	
	virtual void	Archive				(zCArchiver &arc)															{XCALL(0x00556D70);};
	virtual void	Unarchive			(zCArchiver &arc)															{XCALL(0x00556E60);};
	
	const zSTRING*	GetFileExtension	(int i)																		{XCALL(0x005567A0);};
	zCVisual*		LoadVisualVirtual	(const zSTRING& visualName) const											{XCALL(0x00556800);};
	
	void zDecal(void)
	{
		XCALL(0x00556570);
	};

	zCDecal(void)
	{
		zDecal();
	};

	static void CleanupDecals(void)
	{
		XCALL(0x005566B0);
	};

	static void CreateDecalMeshes(void)
	{
		XCALL(0x00556730);
	};

	void SetTexture(zSTRING&)
	{
		XCALL(0x00556950);
	};

	void SetTexture(zCTexture*)
	{
		XCALL(0x00556960);
	};

	void SetDecalDim(float,float)
	{
		XCALL(0x00556970);
	};
};

class zCEffect : public zCVob		
{
public:
	virtual zCClassDef* _GetClassDef() const
	{
		XCALL(0x00489F40);
	};

	virtual ~zCEffect()
	{
		XCALL(0x0048A220);
	};													
};

class oCVisualFX : public zCEffect
{
public:

	zSTRING			  visName_S;
	zSTRING			  visSize_S;
	float			  visAlpha;
	zSTRING			  visAlphaBlendFunc_S;
	float			  visTexAniFPS;
	int				  visTexAniIsLooping;
	zSTRING			  emTrjMode_S;
	zSTRING			  emTrjOriginNode_S;
	zSTRING			  emTrjTargetNode_S;
	float			  emTrjTargetRange;
	float			  emTrjTargetAzi;
	float			  emTrjTargetElev;
	int				  emTrjNumKeys;
	int				  emTrjNumKeysVar;
	float			  emTrjAngleElevVar;
	float			  emTrjAngleHeadVar;
	float			  emTrjKeyDistVar;
	zSTRING			  emTrjLoopMode_S;
	zSTRING			  emTrjEaseFunc_S;
	float			  emTrjEaseVel;					
	float			  emTrjDynUpdateDelay;
	int				  emTrjDynUpdateTargetOnly;
	zSTRING			  emFXCreate_S;
	zSTRING			  emFXInvestOrigin_S;
	zSTRING			  emFXInvestTarget_S;
	float			  emFXTriggerDelay;
	int				  emFXCreatedOwnTrj;
	zSTRING			  emActionCollDyn_S;			
	zSTRING			  emActionCollStat_S;			
	zSTRING			  emFXCollStat_S;
	zSTRING			  emFXCollDyn_S;
	zSTRING			  emFXCollDynPerc_S;
	zSTRING			  emFXCollStatAlign_S;			
	zSTRING			  emFXCollDynAlign_S;
	float			  emFXLifeSpan;
	int				  emCheckCollision;
	int				  emAdjustShpToOrigin;
	float			  emInvestNextKeyDuration;
	float			  emFlyGravity;
	zSTRING			  emSelfRotVel_S;
	zSTRING			  userString[VFX_NUM_USERSTRINGS];

	zSTRING			  lightPresetName;
	zSTRING			  sfxID;
	BOOL			  sfxIsAmbient;
	int				  sendAssessMagic;
	float			  secsPerDamage;

	BYTE			  dScriptEnd;
	

	zVEC3			  visSize;
	int				  emTrjMode;
	int				  emActionCollDyn;
	int				  emActionCollStat;
	zVEC3			  emSelfRotVel;
	TEaseFunc		  emTrjEaseFunc;
	TTrjLoopMode	  emTrjLoopMode;
	zTVFXState		  fxState;

	

	static zCParser*		fxParser;
	static oCVisualFX*		actFX;

	oCVisualFX*				root;
	oCVisualFX*				parent;
	oCVisualFX*				fxInvestOrigin;
	oCVisualFX*				fxInvestTarget;
	void*					ai; 
	zCArray <oCVisualFX *>	fxList;
	zCArray <oCVisualFX *>	childList; 
	zCArray <oCEmitterKey*> emKeyList;  
	zCArray <zCVob*>		vobList;
	zCArray <zCVob*>		ignoreVobList;
	zCArray <zCVob*>		allowedCollisionVobList;
	zCArray <zCVob*>		collidedVobs;
	zCArray <zSVisualFXColl>queuedCollisions;
	oCTrajectory			trajectory;
	void*					earthQuake; 
	void*					screenFX;   
	float					screenFXTime;
	int						screenFXDir;
	
	zCModelNodeInst*		orgNode;
	zCModelNodeInst*		targetNode;

	zCVisual*				lastSetVisual;
	zCVob*					origin;
	zCVob*					inflictor;
	zCVob*					target;
	zCVobLight*				light;
	float					lightRange;
	zCSoundFX*				sfx;
	zTSoundHandle			sfxHnd;

	zSTRING					fxName;

	oCEmitterKey*			fxBackup;
	oCEmitterKey*			lastSetKey;
	oCEmitterKey*			actKey;
	float					frameTime;
	float					collisionTime;
	float					deleteTime;
	float					damageTime;

	zVEC3					targetPos;
	zVEC3					lastTrjDir;
	zVEC3					keySize;
	zVEC3					actSize;
	zVEC3					castEndSize;

	float					nextLevelTime;
	float					easeTime;
	float					age;
	float					trjUpdateTime;
	float					emTrjDist;
	float					trjSign;
	float					levelTime;
	float					lifeSpanTimer;
	float					fxStartTime;
	float					oldFovX, oldFovY;

	BOOL					collisionOccured			: 1;				
	BOOL					showVisual					: 1;
	BOOL					isChild						: 1;
	BOOL					isDeleted					: 1;
	BOOL					initialized					: 1;
	BOOL					shouldDelete				: 1;
	BOOL					lightning					: 1;
	BOOL					fxInvestOriginInitialized	: 1;
	BOOL					fxInvestTargetInitialized	: 1;
	BOOL					fxInvestStopped				: 1;
	BOOL					timeScaled					: 1;
	int						fovMorph					: 2;
	int						level						: 5;
	int						collisionCtr				: 3;					
	int						queueSetLevel				: 5;
	float					damage;
	int						damageType;

	int						spellType;
	int						spellCat;
	int						spellTargetTypes;
	float					savePpsValue;
	zVEC2					saveVisSizeStart;
	zVEC3					transRing[VFX_MAX_POS_SAMPLES];
	int						ringPos;
	BOOL					emTrjFollowHitLastCheck;
	BOOL					bIsProjectile;
	BOOL					bPfxMeshSetByVisualFX;
	BOOL					m_bAllowMovement;
	float					m_fSleepTimer;

	static zCClassDef*		classDef;
public:
	virtual zCClassDef* _GetClassDef()const													{XCALL(0x0048A010);};
	virtual ~oCVisualFX				()														{XCALL(0x0048A260);};

	virtual void	OnTick			()														{XCALL(0x00499A20);};
	
	
	virtual void	Open			()														{XCALL(0x004918E0);};
	virtual void    SetOrigin		( zCVob *orgVob,		const BOOL recalcTrj = TRUE	)	{XCALL(0x004910F0);};
	virtual void    SetTarget		( zCVob *targetVob,		const BOOL recalcTrj = TRUE	)	{XCALL(0x004912E0);};
	virtual void    SetInflictor	( zCVob *inflictorVob)									{XCALL(0x00491220);};
	virtual void    SetTarget		( zPOINT3 &targetPos,	const BOOL recalcTrj = TRUE	)	{XCALL(0x00491450);};
	virtual zCVob*  GetOrigin		()														{ return origin;	};
	virtual zCVob*  GetTarget		()														{ return target;	};
	virtual zCVob*  GetInflictor	()														{ return inflictor; };
	virtual void	Init			( const zCVob *orgVob, const zPOINT3 &targetPos)		{XCALL(0x00491E10);};	
	virtual void	Init			( const zCVob *orgVob = 0, const zCVob *trgtVob = 0, const zCVob* inflictorVob = 0 ){XCALL(0x00491F20);};  
	virtual void	Init			( const zCArray <zCVob *> &trajectoryVobs		)		{XCALL(0x004926A0);};  
	virtual void	InvestNext		()														{XCALL(0x00492830);};  
	virtual void	SetLevel		( int level, BOOL force=FALSE )							{XCALL(0x00492CB0);};  
	virtual int		GetLevel		()	const												{XCALL(0x00493150);};
	virtual void	Cast			( const BOOL killAfterDone = TRUE )						{XCALL(0x00493160);};  
	virtual void	Stop			( const BOOL killAfterDone = TRUE )						{XCALL(0x00493BE0);};  
	virtual void	Kill			()														{XCALL(0x00493F70);};
	virtual void	Play			( const float keyCycleTime = 0,const zMAT4 *orgTrafo = 0, const zMAT4 *targetTrafo=0 )	{};
	virtual BOOL	CanBeDeleted	()														{XCALL(0x004942B0);};
	virtual BOOL	IsFinished		()														{XCALL(0x004942F0);};
	virtual BOOL	IsLooping		()														{XCALL(0x00494370);};
	virtual void	SetByScript		( const zSTRING &id )									{XCALL(0x0048D4B0);};
	virtual void	SetDuration		( const float fSecDuration )				{ emFXLifeSpan = fSecDuration; };
	virtual void	Reset			()														{XCALL(0x00491C20);};
	virtual void	ResetForEditing	()														{XCALL(0x0049E950);};
	virtual void	ReportCollision			(const zCCollisionReport& collisionReport)		{XCALL(0x00494E80);};
	virtual void	SetCollisionEnabled		(const BOOL en)									{XCALL(0x0048D330);};
	virtual void	SetCollisionCandidates	(zCArray <zCVob *> collisionVobs)				{XCALL(0x004968E0);};
	virtual void	GetCollisionCandidates	(zCArray <zCVob *> &collisionVobs)	{ collisionVobs = allowedCollisionVobList;	 };
	virtual int		GetNumCollisionCandidates()									{ return allowedCollisionVobList.GetNum();	 };
	virtual BOOL	GetCollidedCandidates	(zCArray <zCVob *> &collidedVobs)				{XCALL(0x00496A00);};
	virtual BOOL	CanThisCollideWith		(zCVob* vob)									{XCALL(0x00496AC0);};
	
	virtual	void	SetDamage		( const float dam     )						{ damage	 = dam;		};
	virtual	void	SetDamageType	( const int   damType )						{ damageType = damType;	};
	virtual float	GetDamage		() const									{ return damage;		};
	virtual int		GetDamageType	() const									{ return damageType;	};
	
	virtual	BOOL	IsASpell		()											{ return sendAssessMagic; };
	virtual	void	SetSpellType	(const int _type)							{ spellType	= _type;		};
	virtual int		GetSpellType	()	const									{ return spellType;		};
	virtual	void	SetSpellCat		(const int cat)								{ spellCat	= cat;		};
	virtual int		GetSpellCat		()	const									{ return spellCat;		};
	virtual int		GetSpellTargetTypes() const									{ return spellTargetTypes;	};
	virtual void	SetSpellTargetTypes(const int types)						{ spellTargetTypes = types;	};
	virtual BOOL	GetSendsAssessMagic()										{XCALL(0x0048B350);};
	virtual void	SetSendsAssessMagic(const BOOL a_bSendAssessMagic)			{XCALL(0x0048B2C0);};
	virtual void	Archive			(zCArchiver &)								{XCALL(0x00499B40);};
	virtual void	Unarchive		(zCArchiver &)								{XCALL(0x00499B50);};
	virtual BOOL	GetIsProjectile ()											{ return bIsProjectile;	};
	virtual void 	SetIsProjectile (const BOOL b)								{ bIsProjectile = b;	};
	virtual void	SetVisualByString( const zSTRING &visName )					{XCALL(0x0048C220);};
	virtual void	CalcTrajectory	 ( const BOOL &updateTargetOnly=FALSE )		{XCALL(0x0048F620);};
	virtual void    Collide			 ( const BOOL killAfterDone = TRUE		)	{XCALL(0x00493A00);}; 
	virtual void	CollisionResponse( const zVEC3& collisionNormal, BOOL alignCollNormal ){XCALL(0x00496380);};

	static void SetupAIForAllFXInWorld(void)
	{
		XCALL(0x004898B0);
	};

	static void RemoveInstancesOfClass(zCClassDef&,int)
	{
		XCALL(0x00489A10);
	};

	static void PreSaveGameProcessing(int)
	{
		XCALL(0x00489A80);
	};

	static void PostSaveGameProcessing(void)
	{
		XCALL(0x00489A90);
	};
	void oVisualFX(void)
	{
		XCALL(0x00489AA0);
	};

	oCVisualFX(void)
	{
		oVisualFX();
	};

	void CleanUpCriticalFX(void)
	{
		XCALL(0x0048AC00);
	};

	void CreateHierachy(void)
	{
		XCALL(0x0048ADF0);
	};

	void DisposeHierachy(void)
	{
		XCALL(0x0048B0B0);
	};

	static void InitParser(void)
	{
		XCALL(0x0048B3F0);
	};

	static void ExitParser(void)
	{
		XCALL(0x0048B7F0);
	};

	void InitValues(void)
	{
		XCALL(0x0048B820);
	};

	void ParseStrings(void)
	{
		XCALL(0x0048BE60);
	};

	void UpdateFXByEmitterKey(oCEmitterKey*)
	{
		XCALL(0x0048DDC0);
	};

	void CreateBackup(void)
	{
		XCALL(0x0048E5F0);
	};

	int FindKey(zSTRING const&)
	{
		XCALL(0x0048E600);
	};

	static oCVisualFX* CreateAndPlay(const zSTRING &id,const zCVob *org,	  const zCVob *target=0, const int level = 1, const float damage = 0, const int damageType = 0, const BOOL bIsProjectile = FALSE)
	{
		XCALL(0x0048E760);
	};

	static oCVisualFX* CreateAndPlay(const zSTRING &id,const zVEC3 &orgPos, const zCVob *target=0, const int level = 1, const float damage = 0, const int damageType = 0, const BOOL bIsProjectile = FALSE)
	{
		XCALL(0x0048EA80);
	};

	oCVisualFX* CreateAndCastFX(zSTRING const&,zCVob const*,zCVob const*)
	{
		XCALL(0x0048EE80);
	};

	oCVisualFX* CreateAndCastFX(zSTRING const&,zMAT4 const&)
	{
		XCALL(0x0048F1E0);
	};

	void CreateInvestFX(void)
	{
		XCALL(0x00491510);
	};

	void InitInvestFX(void)
	{
		XCALL(0x00491690);
	};

	void StopInvestFX(void)
	{
		XCALL(0x00491830);
	};

	void InitEffect(void)
	{
		XCALL(0x004943E0);
	};

	void EndEffect(int)
	{
		XCALL(0x00494C80);
	};

	void SetShowVisual(int)
	{
		XCALL(0x00494D20);
	};

	int ProcessQueuedCollisions(void)
	{
		XCALL(0x00495830);
	};

	int ProcessCollision( zSVisualFXColl&)
	{
		XCALL(0x004958D0);
	};

	int CheckDeletion(void)
	{
		XCALL(0x00496CF0);
	};

	void UpdateActKey(void)
	{
		XCALL(0x00497300);
	};

	void DoMovements(void)
	{
		XCALL(0x00497550);
	};

	int CheckDelayedTrigger(void)
	{
		XCALL(0x00498B70);
	};

	void AdjustShapeToOrigin(void)
	{
		XCALL(0x00498EE0);
	};

	void UpdateEffects(void)
	{
		XCALL(0x004994A0);
	};

	void CalcPFXMesh(void)
	{
		XCALL(0x00499B60);
	};

	void ReleasePFXMesh(void)
	{
		XCALL(0x00499D10);
	};

	void SetPFXShapeVisual(zCVisual*,int)
	{
		XCALL(0x00499DF0);
	};

	static zCObject* _CreateNewInstance(void)
	{
		XCALL(0x0049A230);
	};

	void Edit(void)
	{
		XCALL(0x0049A820);
	};

	static void CreateNewScriptFX(zSTRING const&)
	{
		XCALL(0x0049ADB0);
	};

	static void FxConsole_ParameterChanged(zSTRING const&)
	{
		XCALL(0x0049B620);
	};

	static void EmConsole_ParameterChanged(zSTRING const&)
	{
		XCALL(0x0049C290);
	};

	static int FxConsole_EvalFunc(zSTRING const&,zSTRING&)
	{
		XCALL(0x0049C4D0);
	};

	static int EmConsole_EvalFunc(zSTRING const&,zSTRING&)
	{
		XCALL(0x0049D180);
	};

	void SetupEmitterKeysByVisual(void)
	{
		XCALL(0x0049E8B0);
	};

	static void* operator new(unsigned int)
	{
		XCALL(0x006742D0);
	};

	static void operator delete(void*)
	{
		XCALL(0x00474E50);
	};

	zSTRING const& GetName(void)const 
	{
		XCALL(0x006742F0);
	};
};

class oCParticleControl
{
	zCParticleFX*	partFX;
	zCVob*			pfxVob;
	DWORD			pfxVobID;
	zSTRING			pfxName;
	zVEC3			startpos;
	BOOL			IsInEditMode;

	zCWorld*		rnd_world;
	zCConsole*		part_edit;	
public:

	oCParticleControl(void)
	{
		XCALL(0x0076FF90);
	};

	oCParticleControl(zCWorld*)
	{
		XCALL(0x00770040);
	};

	~oCParticleControl(void)
	{
		XCALL(0x00770230);
	};

	zCVob* GetPFXVob(void)
	{
		XCALL(0x007702C0);
	};

	void SelectActivePFX(void)
	{
		XCALL(0x007702D0);
	};

	void EditActivePFX(void)
	{
		XCALL(0x00770660);
	};

	void SetStartPos(zVEC3&)
	{
		XCALL(0x00771330);
	};

	void StartActivePFX(zCVob*,zSTRING&)
	{
		XCALL(0x00771350);
	};

	void StartActivePFX(void)
	{
		XCALL(0x00771550);
	};

	void CreateNewPFX(zSTRING&)
	{
		XCALL(0x00771700);
	};

	void SetPFXName(zSTRING&)
	{
		XCALL(0x00771930);
	};

	void SetWorld(zCWorld*)
	{
		XCALL(0x00771A90);
	};

	void BeginEditActive(void (__cdecl*)(zSTRING const&))
	{
		XCALL(0x00771AE0);
	};

	void DeleteLastPFX(void)
	{
		XCALL(0x00771BB0);
	};

	void UpdateInternals(void)
	{
		XCALL(0x00771CA0);
	};

	void EndEditActive(void)
	{
		XCALL(0x00771CB0);
	};
};
