#pragma once
#include "zcvob.h"
#include "zcmesh.h"

class zCMaterial;

enum zTEffectStage
{
	zTEFFECT_NONE,		
	zTEFFECT_VOLUME,	
	zTEFFECT_PLANAR,	
	zTEFFECT_START		
};

class zCQuadMark : public zCVisual		
{
	friend class zCParticleFX;
	friend class zCBspTree;
	friend class oCVisualFX;
	friend class zCAIPlayer;

	struct zTQuadMarkVert		
	{
		zVEC3		m_vPosition;	
		zVEC2		m_vUVMapping;	
	};
	struct zTQuadMarkPoly		
	{
		zCArray<zTQuadMarkVert>	m_arrVertex;	
		zCPolygon*				m_pPolygon;		
		zVEC3					m_vNormal;		
		~zTQuadMarkPoly(void)
		{
			XCALL(0x005D0B70);
		};
	};
	struct zTQuadMarkAniState	
	{
		int			m_nStartPolyIdx;	
		int			m_nEndPolyIdx;		
		float		m_fBaseAverage;		
		float		m_fAverage;			
		float		m_fScale;			
		float		m_fVelocity;		
		zVEC2		m_vUVMapping;		
		zVEC2		m_vApplyMapping;	
		int			m_nProcessPolyIdx;	
		float		m_fAlpha;			
	};
	struct zTEffectParams		
	{
		zTEffectStage	m_Stage;	
		float			m_fUVScale;	
		float			us8;
	};
	zCMesh*						m_pMesh;			
	zCVob*						m_pVob;				
	zCMaterial*					m_pMaterial;		
	zCMaterial*					m_pMarkMaterial;	
	float						m_fFadeSpeed;		
	BOOL						m_bNoApplyVob;		
	zCArray<zTQuadMarkAniState>	m_arrAniState;		
	zCPolygon**					m_ppPolygons;		
	int							m_nNumPolygons;		
	zCArray<const zCPolygon*>	m_arrProcessedPolys;
	zTQuadMarkPoly				m_FirstPoly;		
	static zCClassDef *classDef;
	void zQuadMark(void)
	{
		XCALL(0x005D0970);
	};

	zCQuadMark(void)
	{
		zQuadMark();
	};

	int ClipQuadPolyToPlane( zCQuadMark::zTQuadMarkPoly&, zCQuadMark::zTQuadMarkPoly&, zTPlane const&)
	{
		XCALL(0x005D0DB0);
	};

	void ClipQuadPolyToWorldPoly( zCQuadMark::zTQuadMarkPoly&,zCPolygon*,zCArray<int>&)
	{
		XCALL(0x005D0FF0);
	};

	void CalcQuadAxis(zCPolygon*,zVEC3&,zVEC3&)
	{
		XCALL(0x005D1250);
	};

	void InitFirstQuadPoly(zCPolygon*,zVEC3 const&,zVEC3 const&,zVEC3 const&, zCQuadMark::zTEffectParams*)
	{
		XCALL(0x005D1400);
	};

	void InitQuadPoly( zCQuadMark::zTQuadMarkPoly&,zCPolygon*)
	{
		XCALL(0x005D18D0);
	};

	void ProjectQuadPolyToPlane( zCQuadMark::zTQuadMarkPoly const&, zCQuadMark::zTQuadMarkPoly&, zTPlane const&)
	{
		XCALL(0x005D1950);
	};

	void AddQuadPolyToQuadMesh( zCQuadMark::zTQuadMarkPoly&,zCPolygon*)
	{
		XCALL(0x005D1A30);
	};

	zCPolygon* GetNextWorldPoly(zCVertex*,zCVertex*)
	{
		XCALL(0x005D1BB0);
	};

	void ProcessWorldPoly(zCPolygon*)
	{
		XCALL(0x005D1C40);
	};

	void CreateQuadMark(zVEC3 const&,zVEC3 const&,zVEC2 const&,zSTRING&, zCQuadMark::zTEffectParams*)
	{
		XCALL(0x005D1E00);
	};

	void CreateQuadMark(zVEC3 const&,zVEC3 const&,zVEC2 const&,zCMaterial*, zCQuadMark::zTEffectParams*)
	{
		XCALL(0x005D1F40);
	};

	void CreateQuadMark(zVEC3 const&,zVEC3 const&,zVEC2 const&, zCQuadMark::zTEffectParams*)
	{
		XCALL(0x005D1FD0);
	};

	void CreateQuadMark(zCPolygon*,zVEC3 const&,zVEC2 const&, zCQuadMark::zTEffectParams*)
	{
		XCALL(0x005D2030);
	};

	int GetNumActive(void)
	{
		XCALL(0x005D2620);
	};

	void ProcessAniTracker(void)
	{
		XCALL(0x005D2640);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005D0A90);
	};

	virtual ~zCQuadMark()
	{
		XCALL(0x005D0B90 );
	};

	virtual int Render( zTRenderContext&)
	{
		XCALL(0x005D0D00);
	};

	virtual int IsBBox3DLocal(void)
	{
		XCALL(0x005D0AA0);
	};

	virtual  zTBBox3D GetBBox3D(void)
	{
		XCALL(0x005D0CE0);
	};

	virtual zCOBBox3D* GetOBBox3D(void)
	{
		XCALL(0x004CA050);
	};

	virtual zSTRING GetVisualName(void)
	{
		XCALL(0x005D0AB0);
	};

	virtual int GetVisualDied(void)
	{
		XCALL(0x004CA060);
	};

	virtual void SetVisualUsedBy(zCVob*)
	{
		XCALL(0x005D0CB0);
	};

	virtual void DynLightVisual(zCArray<zCVobLight*> const&,zMAT4*)
	{
		XCALL(0x004CA070);
	};

	virtual unsigned long GetRenderSortKey(void)const 
	{
		XCALL(0x004CA080);
	};

	virtual int CanTraceRay(void)const 
	{
		XCALL(0x004CA090);
	};

	virtual int TraceRay(zVEC3 const&,zVEC3 const&,int, zTTraceRayReport&)
	{
		XCALL(0x006068E0);
	};

	virtual void HostVobRemovedFromWorld(zCVob*,zCWorld*)
	{
		XCALL(0x004CA0A0);
	};

	virtual void HostVobAddedToWorld(zCVob*,zCWorld*)
	{
		XCALL(0x004CA0B0);
	};

	virtual zSTRING const* GetFileExtension(int)
	{
		XCALL(0x004CA0C0);
	};

	virtual void GetLODVisualAndAlpha(float,zCVisual*&,float&)
	{
		XCALL(0x00606880);
	};

	virtual int GetAlphaTestingEnabled(void)const 
	{
		XCALL(0x004CA0D0);
	};

	virtual void SetAlphaTestingEnabled(int)
	{
		XCALL(0x004CA0E0);
	};

	virtual zCVisual* LoadVisualVirtual(zSTRING const&)const 
	{
		XCALL(0x004CA0F0);
	};
};

