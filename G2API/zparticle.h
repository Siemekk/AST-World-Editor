#pragma once

#include "zcvob.h"
#include "zcvisual.h"

class zCParser;
class zCPolyStrip;
class zCQuadMark;
class zCTexture;
class zCProgMeshProto;

enum zTRnd_AlphaBlendFunc;

enum zTPFX_EmitterShape {
	zPFX_EMITTER_SHAPE_POINT,
	zPFX_EMITTER_SHAPE_LINE,
	zPFX_EMITTER_SHAPE_BOX,	
	zPFX_EMITTER_SHAPE_CIRCLE,
	zPFX_EMITTER_SHAPE_SPHERE,
	zPFX_EMITTER_SHAPE_MESH
};

enum zTPFX_EmitterFOR {
	zPFX_FOR_WORLD,
	zPFX_FOR_OBJECT,
	zPFX_FOR_OBJECT_EACH_FRAME
};

enum zTPFX_EmitterDirMode {
	zPFX_EMITTER_DIRMODE_NONE,
	zPFX_EMITTER_DIRMODE_DIR,
	zPFX_EMITTER_DIRMODE_TARGET,
	zPFX_EMITTER_DIRMODE_MESH
};

enum zTPFX_EmitterVisOrient {
	zPFX_EMITTER_VISORIENT_NONE,
	zPFX_EMITTER_VISORIENT_VELO_ALIGNED,
	zPFX_EMITTER_VISORIENT_VOB_XZPLANE,
	zPFX_EMITTER_VISORIENT_VELO_ALIGNED3D,
};

enum zTPFX_DistribType {
	zPFX_EMITTER_DISTRIBTYPE_RAND,
	zPFX_EMITTER_DISTRIBTYPE_UNIFORM,
	zPFX_EMITTER_DISTRIBTYPE_WALK,
};

enum zTPFX_FlockMode
{
	zPFX_FLOCK_NONE,
	zPFX_FLOCK_WIND,
	zPFX_FLOCK_WIND_PLANTS,
};

typedef struct zSParticle
{
	struct zSParticle*	next;
	zVEC3				position;			
	zVEC3				positionWS;			
	zVEC3				vel;
	float				lifeSpan;
	float				alpha;
	float				alphaVel;
	zVEC2				size;
	zVEC2				sizeVel;
	zVEC3				color;
	zVEC3				colorVel;
	zCPolyStrip			*polyStrip;
} zTParticle;

class zCParticleEmitter		
{
	friend int CompareEmitterNames(zCParticleEmitter* const*, zCParticleEmitter* const*);
	friend class zCParticleFX;
	friend class zCSkyControler_Mid;
	friend class zCModel;
	friend class zCUnderwaterPFX;
	friend class oCVisualFX;
	friend class oCEmitterKey;
	friend class oCVisFX_Lightning;
	friend class zCAIPlayer;
	friend class zCSoundManager;
	friend class oCAIArrowBase;
	friend class oCParticleControl;
	friend class zCPar_OffsetTable_ParticleFX;

	
	
	

	
	float					ppsValue;
	zSTRING					ppsScaleKeys_S;
	int						ppsIsLooping;
	int						ppsIsSmooth;
	float					ppsFPS;
	zSTRING					ppsCreateEm_S;
	float					ppsCreateEmDelay;
	
	zSTRING					shpType_S;					
	zSTRING					shpFOR_S;					
	zSTRING					shpOffsetVec_S;				
	zSTRING					shpDistribType_S;			
	float					shpDistribWalkSpeed;		
	int						shpIsVolume;
	zSTRING					shpDim_S;					
	zSTRING					shpMesh_S;					
	int						shpMeshRender_B;
	zSTRING					shpScaleKeys_S;				
	int						shpScaleIsLooping;
	int						shpScaleIsSmooth;
	float					shpScaleFPS;
	
	zSTRING					dirMode_S;					
	zSTRING					dirFOR_S;					
	zSTRING					dirModeTargetFOR_S;
	zSTRING					dirModeTargetPos_S;			
	float					dirAngleHead;
	float					dirAngleHeadVar;
	float					dirAngleElev;
	float					dirAngleElevVar;
	float					velAvg;
	float					velVar;
	
	float					lspPartAvg;
	float					lspPartVar;
	
	
	zSTRING					flyGravity_S;
	int						flyCollDet_B;
	
	zSTRING					visName_S;					
	zSTRING					visOrientation_S;
	int						visTexIsQuadPoly;			
	float					visTexAniFPS;
	int						visTexAniIsLooping;			
	
	zSTRING					visTexColorStart_S;
	zSTRING					visTexColorEnd_S;
	
	zSTRING					visSizeStart_S;
	float					visSizeEndScale;
	
	zSTRING					visAlphaFunc_S;
	float					visAlphaStart;
	float					visAlphaEnd;
	
	float					trlFadeSpeed;
	zSTRING					trlTexture_S;
	float					trlWidth;
	
	float					mrkFadeSpeed;
	zSTRING					mrkTexture_S;
	float					mrkSize;
	
	zSTRING					m_flockMode_S;
	float					m_fFlockWeight;
	
	BOOL					m_bSlowLocalFOR;
	zSTRING					m_timeStartEnd_S;
	BOOL					m_bIsAmbientPFX;
	
	int						endOfDScriptPart;
	

	
	
	
	
	zSTRING					particleFXName;				

	
	zCArray<float>			ppsScaleKeys;
	zCParticleEmitter		*ppsCreateEmitter;
	
	zTPFX_EmitterShape		shpType;					
	float					shpCircleSphereRadius;
	zVEC3					shpLineBoxDim;
	zVEC3*					shpMeshLastPolyNormal;
	zCMesh					*shpMesh;
	zCProgMeshProto			*shpProgMesh;
	zCModel					*shpModel;

	zTPFX_EmitterFOR		shpFOR;
	zTPFX_DistribType		shpDistribType;
	zVEC3					shpOffsetVec;
	zCArray<float>			shpScaleKeys;				
	
	zTPFX_EmitterDirMode	dirMode;					
	zTPFX_EmitterFOR		dirFOR;						
	zTPFX_EmitterFOR		dirModeTargetFOR;
	zVEC3					dirModeTargetPos;			
	zTBBox3D				dirAngleBox;
	zVEC3					dirAngleBoxDim;
	
	
	zVEC3					flyGravity;
	
	zCTexture				*visTexture;
	zTPFX_EmitterVisOrient	visOrientation;
	
	zVEC2					visSizeStart;
	
	zVEC3					visTexColorRGBAStart;
	zVEC3					visTexColorRGBAEnd;
	
	zTRnd_AlphaBlendFunc	visAlphaFunc;
	
	zCTexture				*trlTexture;
	zCTexture				*mrkTexture;
	
	BOOL					 isOneShotFX;
	float					dirAngleHeadVarRad;
	float					dirAngleElevVarRad;
	zTPFX_FlockMode			m_flockMode;
	float					m_ooAlphaDist;
	float					m_startTime;
	float					m_endTime;

public:
	void zParticleEmitter(zCParticleEmitter const&)
	{
		XCALL(0x005AE140);
	};

	zCParticleEmitter(zCParticleEmitter const& em)
	{
		zParticleEmitter(em);
	};

	void zParticleEmitter(void)
	{
		XCALL(0x005B2860);
	};

	zCParticleEmitter(void)
	{
		zParticleEmitter();
	};

	~zCParticleEmitter(void)
	{
		XCALL(0x005B2B80);
	};

	void UpdateVelocity(void)
	{
		XCALL(0x005B2EE0);
	};

	void AddCompoundReferences(void)
	{
		XCALL(0x005B2EF0);
	};

	void ResetStrings(void)
	{
		XCALL(0x005B2F50);
	};

	void Reset(void)
	{
		XCALL(0x005B31F0);
	};

	static zVEC3 String2Vec3(zSTRING const&)
	{
		XCALL(0x005B3210);
	};

	static zVEC2 String2Vec2(zSTRING const&)
	{
		XCALL(0x005B3490);
	};

	void UpdateInternals(void)
	{
		XCALL(0x005B36B0);
	};

	void SetOutputDir(zVEC3 const&)
	{
		XCALL(0x005B45F0);
	};

	void ConvertAnglesIntoBox(void)
	{
		XCALL(0x005B4830);
	};

	zVEC3 GetPosition(void)
	{
		XCALL(0x005B4880);
	};

	zVEC3 __fastcall GetVelocity( zSParticle*,zCParticleFX*)
	{
		XCALL(0x005B5060);
	};

	zCParticleEmitter& operator=(zCParticleEmitter const&)
	{
		XCALL(0x00770750);
	};
};

class zCParticleEmitterVars
{
public:
	
	float			ppsScaleKeysActFrame;
	float			ppsNumParticlesFraction;
	float			ppsTotalLifeTime;
	BOOL			ppsDependentEmitterCreated;
	
	float			shpScaleKeysActFrame;
	float			uniformValue;
	float			uniformDelta;
};

class zCParticleFX : public zCVisual
{
public:
	class zCStaticPfxList
	{
		zCParticleFX	*pfxListHead;
		zCParticleFX	*pfxListTail;
		int				numInList;
	public:
		zCStaticPfxList();
		void InsertPfxHead(zCParticleFX*)
		{
			XCALL(0x005AD280);
		};

		void RemovePfx(zCParticleFX*)
		{
			XCALL(0x005AD2C0);
		};

		void TouchPfx(zCParticleFX*)
		{
			XCALL(0x005AD330);
		};

		void ProcessList(void)
		{
			XCALL(0x005AD3F0);
		};

		BOOL IsInList(zCParticleFX*)
		{
			XCALL(0x005ADB70);
		};
	};

	friend class zCVob;
	friend class zCStaticPfxList;
	friend class zCPFXPerFrameCallback;
	friend class zCPFXControler;
	friend class zCSkyControler_Mid;
	friend class zCSkyControler_Outdoor;
	friend class zCParticleEmitter;
	friend class zCBspTree;
	friend class zCModel;
	friend class zCUnderwaterPFX;
	friend class oCVisualFX;
	friend class oCEmitterKey;
	friend class oCVisFX_Lightning;
	friend class zCAIPlayer;
	friend class zCTouchDamage;
	friend BOOL zDieter_ConsoleEval(zSTRING const&, zSTRING&);
	friend class oCAIArrowBase;
	friend class oCNpc;
	friend class oCParticleControl;

protected:
	zTParticle			*firstPart;
	zCParticleEmitterVars emitterVars;
	zCParticleEmitter	*emitter;

	zTBBox3D			bbox3DWorld;
	zCVob				*connectedVob;
	int					bboxUpdateCtr;
	struct
	{
		UINT8			emitterIsOwned			: 1;
		UINT8			dontKillPFXWhenDone		: 1;
		UINT8			dead					: 1;
		UINT8			isOneShotFX				: 1;	
		UINT8			forceEveryFrameUpdate	: 1;	
		UINT8			renderUnderWaterOnly	: 1;
	};

	friend class		zCStaticPfxList;
	friend class		zCPFXPerFrameCallback;

	zCParticleFX		*nextPfx;
	zCParticleFX		*prevPfx;
	float				privateTotalTime;	
	float				lastTimeRendered;	

	float				timeScale;
	float				localFrameTimeF;
	zCQuadMark			*quadMark;
	zTBBox3D			quadMarkBBox3DWorld;
	float				m_BboxYRangeInv;
	BOOL				m_bVisualNeverDies;
public:
	static zCClassDef *classDef;

	static int s_bAmbientPFXEnabled;
	static zCArraySort<zCParticleEmitter*>* s_emitterPresetList;
	static zCParticleEmitter* s_emitterDummyDefault;
	static zCStaticPfxList* s_pfxList;
	static int s_globNumPart;
	static zSParticle*& s_globPartList;
	static zSParticle*& s_globFreePart;
	static zCMesh*& s_partMeshTri;
	static zCMesh*& s_partMeshQuad;
	static zCParser*& s_pfxParser;
	static int s_showDebugInfo;
	virtual zCClassDef* _GetClassDef				()const									{XCALL(0x005AD070);};
	
	virtual BOOL		Render						(zTRenderContext& renderContext)		{XCALL(0x005B0310);};	
	BOOL				IsBBox3DLocal				() { return FALSE; };				
	zTBBox3D			GetBBox3D					()										{XCALL(0x005AEFA0);};
	zSTRING				GetVisualName				()										{XCALL(0x005ADD30);};
	BOOL				GetVisualDied				()						{ return dead; };
	BOOL				GetVisualNeverDies			()const					{ return m_bVisualNeverDies; };
	void				SetVisualNeverDies			(const BOOL m_b)		{ m_bVisualNeverDies = m_b;  };

	void				SetVisualUsedBy				(zCVob* vob)			{XCALL(0x005ADC80);};
	DWORD				GetRenderSortKey			() const				{ return DWORD(emitter); };	
	void				HostVobRemovedFromWorld		(zCVob* hostVob, zCWorld* hostWorld){XCALL(0x005AD270);};	
	void				HostVobAddedToWorld			(zCVob* hostVob, zCWorld* hostWorld){XCALL(0x005AD250);};	
	
	virtual	~zCParticleFX							()									{XCALL(0x005AD0E0);};						
	
	const zSTRING*		GetFileExtension			(int i)								{XCALL(0x005ADBA0);};
	zCVisual*			LoadVisualVirtual			(const zSTRING& visualName) const	{XCALL(0x005ADC00);};

	static void ParseParticleFXScript(void)
	{
		XCALL(0x005AC560);
	};

	static void InitParticleFX(void)
	{
		XCALL(0x005ACB50);
	};

	static void CleanupParticleFX(void)
	{
		XCALL(0x005ACEB0);
	};

	void zParticleFX(void)
	{
		XCALL(0x005ACF70);
	};

	zCParticleFX(void)
	{
		zParticleFX();
	};

	void InitEmitterVars(void)
	{
		XCALL(0x005ADC10);
	};

	void FreeParticles(void)
	{
		XCALL(0x005ADC30);
	};

	static zCParticleEmitter* SearchParticleEmitter(zSTRING const&)
	{
		XCALL(0x005ADDE0);
	};

	void RemoveEmitter(void)
	{
		XCALL(0x005ADFA0);
	};

	int SetEmitter(zCParticleEmitter*,int)
	{
		XCALL(0x005ADFE0);
	};

	int SetEmitter(zSTRING const&,int)
	{
		XCALL(0x005AEB40);
	};

	int SetAndStartEmitter(zSTRING const&,int)
	{
		XCALL(0x005AED40);
	};

	int SetAndStartEmitter(zCParticleEmitter*,int)
	{
		XCALL(0x005AED70);
	};

	void StopEmitterOutput(void)
	{
		XCALL(0x005AEDA0);
	};

	void RestoreEmitterOutput(void)
	{
		XCALL(0x005AEDB0);
	};

	static zCParticleFX* Load(zSTRING const&)
	{
		XCALL(0x005AEDF0);
	};

	int CalcIsDead(void)
	{
		XCALL(0x005AF0D0);
	};

	static float PartRand(void)
	{
		XCALL(0x005AF140);
	};

	void UpdateParticleFX(void)
	{
		XCALL(0x005AF160);
	};

	void CreateParticlesUpdateDependencies(void)
	{
		XCALL(0x005AF240);
	};

	void UpdateParticle( zSParticle*)
	{
		XCALL(0x005AF500);
	};

	float GetShapeScaleThisFrame(void)
	{
		XCALL(0x005B1920);
	};

	int GetNumParticlesThisFrame(void)
	{
		XCALL(0x005B1A90);
	};

	void CheckDependentEmitter(void)
	{
		XCALL(0x005B1C30);
	};

	void CreateParticles(void)
	{
		XCALL(0x005B1DD0);
	};
};
