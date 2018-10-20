#pragma once

#include "zCProgMeshProto.h"
#include "zfile.h"

enum zTMorphAniPhase
{
	zTMANI_BLEND_IN,
	zTMANI_ANIMATE,
	zTMANI_BLEND_OUT
};

class zCMorphMeshAni
{

	friend class zCMorphMeshProto;
	friend class zCMorphMesh;

	zSTRING				m_sNameAni;				
	zSTRING				m_sNameSource;			
	float				m_fBlendIn;				
	float				m_fBlendOut;			
	float				m_fTimeToPlay;			
public:
	int					m_nLayer;				
private:
	float				m_fRateFPS;				
	struct BIT_ARRAY
	{
		BOOL tDistributeFramesRandomly:1;	
		BOOL tLoopInfinitely:1;				
		BOOL tShiftVertPos:1;				
		BOOL tReferenceAni:1;				
	};
	union
	{
		BYTE			m_sbFlags;				
		BIT_ARRAY       f;
	};
	int					m_nNumVertices;			
	int*				m_pVertIndices;			
	int					m_nNumFrames;			
	zVEC3*				m_pVertexPosData;		
public:
	void zMorphMeshAni(void)
	{
		XCALL(0x005A3100);
	};

	zCMorphMeshAni(void)
	{
		zMorphMeshAni();
	};

	~zCMorphMeshAni(void)
	{
		XCALL(0x005A3160);
	};

	void SetBlending(float,float)
	{
		XCALL(0x005A3220);
	};

	void Load(zCFileBIN&)
	{
		XCALL(0x005A3290);
	};

	void Save(zCFileBIN&)
	{
		XCALL(0x005A33A0);
	};

	void SetFlagsByString(zSTRING const&)
	{
		XCALL(0x005A50B0);
	};
};

class zCMorphMeshProto				
{
	friend class zCMorphMesh;

	zCMorphMeshProto*				m_pPrevProto;	
	zCMorphMeshProto*				m_pNextProto;	
	int								m_nRefCtr;		
	zSTRING							m_sNameProto;	
	zCProgMeshProto*				m_pProgMProto;	
	zVEC3*							m_pPoint;		
	zCArraySort<zCMorphMeshAni*>	m_arrMeshAni;	
	int								m_nLevel;
public:
	void zMorphMeshProto(void)
	{
		XCALL(0x005A34B0);
	};

	zCMorphMeshProto(void)
	{
		zMorphMeshProto();
	};

	~zCMorphMeshProto(void)
	{
		XCALL(0x005A3600);
	};

	int Release(void)
	{
		XCALL(0x005A3860);
	};

	static zCMorphMeshProto* SearchName(zSTRING const&)
	{
		XCALL(0x005A3890);
	};

	static zCMorphMeshProto* Load(zSTRING const&)
	{
		XCALL(0x005A3900);
	};

	zCMorphMeshAni* SearchAni(zSTRING const&)
	{
		XCALL(0x005A3AE0);
	};

	int LoadMMB(zSTRING const&)
	{
		XCALL(0x005A3B90);
	};

	void SaveMMB(zSTRING const&)
	{
		XCALL(0x005A42E0);
	};

	zCMorphMeshAni* GenerateMorphAni(zCMesh*,zCArray<int> const&,int)
	{
		XCALL(0x005A46F0);
	};

	zCMesh* Load3DSMAXAsc(zSTRING const&,float&,int,int)
	{
		XCALL(0x005A4BF0);
	};

	void ReadMorphRef(zCArray<int>&)
	{
		XCALL(0x005A4E50);
	};

	void ReadMorphAni(zCArray<int> const&)
	{
		XCALL(0x005A5160);
	};

	void LoadMorphScript(zSTRING const&)
	{
		XCALL(0x005A59C0);
	};
};

class zCMorphMesh : public zCVisualAnimate
{
public:
	struct zTMorphAniEntry
		{
		zCMorphMeshAni		*ani;
		float				weight;
		float				weightDest;
		float				actFrame;
		int					actFrameInt;
		int					nextFrameInt;
		float				frac;
		float				blendInSpeed;
		float				blendOutSpeed;
		float				holdTime;
		int					blendState;
	};
	zCMorphMeshProto		*morphProto;
	zCProgMeshProto			*morphMesh;
	zCMorphMeshAni			*refShapeAni;
	zCModelTexAniState		texAniState;
	enum
	{
		zMORPH_BLEND_STATE_FADEIN,
		zMORPH_BLEND_STATE_CONST,
		zMORPH_BLEND_STATE_FADEOUT
	};

	BOOL					m_bUsesAlphaTesting;

	zCArraySort<zTMorphAniEntry*>aniChannels;

	
	struct zTRandAni
	{ 
		float				randAniTimer;
		zCMorphMeshAni		*randAni;
		float				randAniTimeMin;
		float				randAniTimeMinVar;
		float				randAniTimeMax;
		float				randAniTimeMaxVar;
		float				randAniProbMin;
	};
	zCArray<zTRandAni>		randAniList;
public:
	static zCClassDef*	classDef;

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x005A2DA0);};
	
	BOOL					Render				(zTRenderContext& renderContext);
	BOOL					IsBBox3DLocal		() { return TRUE; };				
	zTBBox3D				GetBBox3D			();
	zCOBBox3D*				GetOBBox3D			() { return 0; };					
	zSTRING					GetVisualName		();
	DWORD					GetRenderSortKey	() const				{ return DWORD(morphProto) | 0xD0000000; };	

	
	virtual BOOL			GetAlphaTestingEnabled()	const			{ return m_bUsesAlphaTesting;	};
	virtual void			SetAlphaTestingEnabled(const BOOL a_btest)	{ m_bUsesAlphaTesting = a_btest; };

	
	BOOL					CanTraceRay			() const				{ return TRUE; };	
	BOOL					TraceRay			(	const zVEC3&		rayOrigin, 
													const zVEC3&		ray, 
													const int			traceFlags, 
													zTTraceRayReport	&report);

	
	void					StartAnimation		(const zSTRING& aniName)	{ StartAni	(aniName); };
	void					StopAnimation		(const zSTRING& aniName)	{ StopAni	(aniName); };
	BOOL					IsAnimationActive	(const zSTRING& aniName)	{ return IsAniActive (aniName); };
	const zSTRING*			GetAnyAnimation		();
	void					StartAnyAnimation	();			

	virtual					~zCMorphMesh		()						{XCALL(0x005A6030);};



	void Init(void)
	{
		XCALL(0x005A5F30);
	};
	void zMorphMesh(zCMorphMeshProto*)
	{
		XCALL(0x005A5F50);
	};

	zCMorphMesh(zCMorphMeshProto* pMeshProto)
	{
		zMorphMesh(pMeshProto);
	};

	static zCMorphMesh* Load(zSTRING const&)
	{
		XCALL(0x005A6120);
	};

	zCMorphMeshAni* SearchAni(zSTRING const&)
	{
		XCALL(0x005A62C0);
	};

	int Render(zTRenderContext&,void*,float,float)
	{
		XCALL(0x005A63F0);
	};

	void CalcVertPositions(void)
	{
		XCALL(0x005A6480);
	};

	void AdvanceAnis(void)
	{
		XCALL(0x005A6830);
	};

	int IsAniActive(zSTRING const&)
	{
		XCALL(0x005A6A40);
	};

	int IsAniActive(zCMorphMeshAni*)
	{
		XCALL(0x005A6B20);
	};

	void StopAni(zSTRING const&)
	{
		XCALL(0x005A6B60);
	};

	void StopAni(zCMorphMeshAni*)
	{
		XCALL(0x005A6C80);
	};

	void FadeOutAni(zSTRING const&)
	{
		XCALL(0x005A6D00);
	};

	void FadeOutAni(zCMorphMeshAni*)
	{
		XCALL(0x005A6DF0);
	};

	void StartAni(zSTRING const&, float intensity=float(1.0F), float holdTime=float(-2))
	{
		XCALL(0x005A6E60);
	};

	void StartAni(zCMorphMeshAni*,float,float)
	{
		XCALL(0x005A6F30);
	};

	void RemoveRandAni(zCMorphMeshAni*)
	{
		XCALL(0x005A70F0);
	};

	void AddRandAni(zCMorphMeshAni*,float,float,float,float,float)
	{
		XCALL(0x005A7160);
	};

	void ProcessRandAnis(void)
	{
		XCALL(0x005A72D0);
	};

	void SetTextureVar(int,int,zSTRING*)
	{
		XCALL(0x005A73E0);
	};

	void PrintStatus(int,int)
	{
		XCALL(0x005A7410);
	};
};
