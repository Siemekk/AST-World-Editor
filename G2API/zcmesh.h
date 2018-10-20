#pragma once

#include "ztypes.h"

class zCMaterial;
struct zTRenderContext;
class zCFileBIN;
class zCTexture;
class zCLightMap;
class zCVob;
class zCVobLight;
struct zTTraceRayReport;
class zCCollisionReport;
class zCWorld;
class zVEC3;




class zCVertFeature
{
public:
	zVEC3			vertNormal;
	zCOLOR			lightStat;
	zCOLOR			lightDyn;
	float			texu, texv;		
public:

	zCVertFeature(void)
	{
		XCALL(0x0056D760);
	};

	void SetMapping	(const zPOINT2& coord)	
	{
		texu = coord.n[VX];
		texv = coord.n[VY];
	};
};

class zCVertex
{
public:
	zPOINT3			position;
	union
	{
		struct
		{
			int             transformedIndex;
			int				myIndex;
		};
		unsigned int hackData; 
	};
};


enum zTPolyType : BYTE
{
	zTPOLY_NORMAL,		
	zTPOLY_PORTAL_SMALL,
	zTPOLY_PORTAL_BIG,	
	zTPOLY_PORTAL_PN	
};

class zCPolygon
{
public:
	struct zSPolySavedValues
	{
		zCPolygon* poly;
		zTPlane	   plane;
	};

	struct zSVertexSavedValues
	{
		zCVertex* vert;
		float	  offset;
	};

	struct zSFeatureSavedValues
	{
		zCVertFeature* feat;
		zCOLOR		   color;
		zVEC3		   mapping;
		zVEC3		   vertNormal;
	};
	zCVertex			**vertex;
public:
	zTFrameCtr			lastTimeDrawn;
	zTPlane				polyPlane;
	zCMaterial			*material;
	zCLightMap			*lightmap;


	zCVertex			**clipVert;
	zCVertFeature		**clipFeat;
	int					numClipVert;	

	zCVertFeature		**feature;
	BYTE				polyNumVert;

	enum zTPortalType
	{ 
		zPORTAL_TYPE_NONE		= 0, 
		zPORTAL_TYPE_SMALL		= 1, 
		zPORTAL_TYPE_BIG		= 2, 
		zPORTAL_TYPE_BIG_NOFADE	= 3 
	};

	#pragma pack (push, 1)
	struct TFlags
	{
		UINT8			portalPoly			: 2;		
		UINT8			occluder			: 1;		
		UINT8			sectorPoly			: 1;		
		UINT8			mustRelight			: 1;		
		UINT8			portalIndoorOutdoor	: 1;		
		UINT8			ghostOccluder		: 1;		
		UINT8			noDynLightNear		: 1;		
		UINT16			sectorIndex			: 16;		
	} flags;
	#pragma pack (pop)

public:
	
	zCPolygon(void)
	{
		XCALL(0x005B6FA0);
	};
	
	zVEC3 GetCenter(void)
	{
		XCALL(0x005BA2F0);
	};

	BOOL CalcNormal()
	{
		XCALL(0x005B8180);
	};

	void SetMapping (const zPOINT2& a, const zPOINT2& b, const zPOINT2& c) 
	{
		XCALL(0x005BA370);
	};

	void SetMapping (const int vertNr, const zPOINT2& texuv) 
	{
		XCALL(0x005BA3C0);
	};

	void SetVertices(zCVertex* a, zCVertex* b, zCVertex* c, zCVertex* d, zBOOL calcNormal=TRUE)
	{
		XCALL(0x005BB540);
	};


	void DrawPolygon();

	zVEC3 CheckRayPolyIntersection(zVEC3, zVEC3);
};

class zCVisual : public zCObject
{
public:
	zCLASS(zCVisual)

		zCVisual				*nextLODVisual;
	zCVisual				*prevLODVisual;
	float					lodFarDistance;
	float					lodNearFadeOutDistance;		
public:
	static zCClassDef*	classDef;

	virtual zCClassDef* _GetClassDef					(void)const												{XCALL(0x004CA040)};

	virtual	BOOL			Render						(zTRenderContext& renderContext) = 0;												
	virtual	BOOL			IsBBox3DLocal				()														{ return TRUE; };			
	virtual zTBBox3D		GetBBox3D					() = 0;																				
	virtual zCOBBox3D*		GetOBBox3D					()														{ return 0; };				
	virtual zSTRING			GetVisualName				() = 0;
	virtual BOOL			GetVisualDied				()														{ return FALSE; };
	virtual void			SetVisualUsedBy				(zCVob* vob)											{};
	virtual void			DynLightVisual				(const zCArray<zCVobLight*>& vobLightList, zMAT4 *trafoObjToWorld=0) {};
	virtual DWORD			GetRenderSortKey			() const												{ return DWORD(this);	};	
	
	virtual BOOL			CanTraceRay					() const												{ return FALSE;			};	
	virtual BOOL			TraceRay					(const zVEC3&		rayOrigin, 
														 const zVEC3&		ray, 
														 const int			traceFlags, 
														 zTTraceRayReport	&report)							{XCALL(0x006068E0)};
	virtual void			HostVobRemovedFromWorld		(zCVob* hostVob, zCWorld* hostWorld)					{};	
	virtual void			HostVobAddedToWorld			(zCVob* hostVob, zCWorld* hostWorld)					{};	
	virtual const zSTRING*	GetFileExtension			(int i)													{ return 0; };						
	virtual void			GetLODVisualAndAlpha		(const float distToCam, zCVisual* &vis, float& alpha)	{XCALL(0x00606880)};
	
	virtual BOOL			GetAlphaTestingEnabled		()	const												{ return FALSE;	};
	virtual void			SetAlphaTestingEnabled		(const BOOL a_btest)									{ };
	
	virtual ~zCVisual()																							{XCALL(0x00606800)};			
	virtual zCVisual*		LoadVisualVirtual			(const zSTRING& visualName) const						{ return 0; };	

	void zVisual(void)
	{
		XCALL(0x00606660);
	};

	zCVisual(void)
	{
		zVisual();
	};

	void AddNextLODVisual(zCVisual*)
	{
		XCALL(0x00606820);
	};

	void AddEndLODVisual(zCVisual*)
	{
		XCALL(0x00606850);
	};

	static void InitVisualSystem(void)
	{
		XCALL(0x006068F0);
	};

	static void CleanupVisualSystem(void)
	{
		XCALL(0x00606A80);
	};

	static zCVisual* LoadVisual(zSTRING const&)
	{
		XCALL(0x00606AD0);
	};
};

class zCVisualAnimate : public zCVisual
{
public:
	zCLASS(zCVisualAnimate)
	static zCClassDef*	classDef;
	virtual zCClassDef* _GetClassDef			(void)const					{XCALL(0x00576580)};
	virtual void			StartAnimation		(const zSTRING& aniName)	=0;
	virtual void			StopAnimation		(const zSTRING& aniName)	=0;
	virtual BOOL			IsAnimationActive	(const zSTRING& aniName)	=0;
	virtual const zSTRING*	GetAnyAnimation		()							=0;
};

class zCMesh : public zCVisual
{
public:
	zCLASS(zCMesh)
		enum zTCalcVertNormalMode
	{
		zVERT_MODE_SMOOTH,
		zVERT_MODE_LINEAR,
		zVERT_MODE_NORMAL
	};
	int				numPoly;
	int				numVert;
	int             numFeat;

protected:
	zCVertex		**vertList;
	zCPolygon		**polyList;
	zCVertFeature   **featList;

	zCVertex        *vertArray;
	zCPolygon       *polyArray;
	zCVertFeature   *featArray;

public:
	zCVertex       *Vertex (int i) const { return vertList[i] ;}

	zTBBox3D		bbox3D;
	zCOBBox3D		obbox3D;
	zTFrameCtr		masterFrameCtr;
	zCMesh			*next;
	zCMesh			*prev;
	zSTRING			meshName;					
	BYTE			hasLightmaps;
	BOOL			m_bUsesAlphaTesting;

	int				numVertAlloc;
	int				numPolyAlloc;
public:

	virtual zCClassDef* _GetClassDef			(void)const															{XCALL(0x00567010)};
	virtual			~zCMesh						()																	{XCALL(0x005670E0)};
	
	zSTRING			GetVisualName				()																	{ return meshName; };
	void			DynLightVisual				(const zCArray<zCVobLight*>& vobLightList, zMAT4 *trafoObjToWorld=0){XCALL(0x00569330)};
	BOOL			Render						(zTRenderContext& renderContext)									{XCALL(0x0056B190)}; 
	zTBBox3D		GetBBox3D					()																	{ return bbox3D;		};
	zCOBBox3D*		GetOBBox3D					()																	{ return &obbox3D;		};
	BOOL			CanTraceRay					() const															{ return TRUE; };	
	BOOL			TraceRay					(const zVEC3&		rayOrigin, 
												 const zVEC3&		ray, 
												 const int			traceFlags, 
												 zTTraceRayReport	&report)										{XCALL(0x00569C60)};
	
	virtual BOOL	GetAlphaTestingEnabled		()	const															{ return m_bUsesAlphaTesting;	};
	virtual void	SetAlphaTestingEnabled		(const BOOL a_btest)												{ m_bUsesAlphaTesting = a_btest; };
	
	const zSTRING*	GetFileExtension			(int i)																{XCALL(0x00567250)};
	zCVisual*		LoadVisualVirtual			(const zSTRING& visualName) const									{XCALL(0x00567270)};
	
	zCMesh(void)
	{
		XCALL(0x00566D90);
	};

	void DeleteAll(void)
	{
		XCALL(0x00567290);
	};

	static zCMesh* SearchName(zSTRING const&)
	{
		XCALL(0x00567590);
	};

	static zCMesh* Load(zSTRING const&,int)
	{
		XCALL(0x00567600);
	};

	static void S_InitVertexMergeCache(zCMesh*)
	{
		XCALL(0x005680A0);
	};

	static void S_DeleteVertexMergeCache(void)
	{
		XCALL(0x00568320);
	};

	zCVertex* VertexInMesh(zVEC3 const&)
	{
		XCALL(0x00568350);
	};

	void AllocVerts(int)
	{
		XCALL(0x00568500);
	};

	void AllocPolys(int)
	{
		XCALL(0x005685F0);
	};

	zCVertex* AddVertex(zCVertex*)
	{
		XCALL(0x005686B0);
	};

	zCVertex* AddVertex(zVEC3&)
	{
		XCALL(0x005688F0);
	};

	zCVertex* AddVertexSmart(zVEC3&)
	{
		XCALL(0x00568B80);
	};

	zCPolygon* AddPoly(zVEC3&,zVEC3&,zVEC3&,zVEC2&,zVEC2&,zVEC2&)
	{
		XCALL(0x00568C10);
	};

	zCPolygon* AddPoly(zCVertex*,zCVertex*,zCVertex*)
	{
		XCALL(0x00568EA0);
	};

	zCPolygon* AddPoly(zCVertex*,zCVertex*,zCVertex*,zCVertex*)
	{
		XCALL(0x00568FB0);
	};

	zCPolygon* AddPoly(zCPolygon*)
	{
		XCALL(0x005690C0);
	};

	zCPolygon* AddPoly(void)
	{
		XCALL(0x00569170);
	};

	void DeletePoly(zCPolygon*)
	{
		XCALL(0x00569250);
	};

	void DynLightScalePrelit( zCOLOR)
	{
		XCALL(0x00569340);
	};

	void PrelightMesh(zMAT4*)
	{
		XCALL(0x00569350);
	};

	zCPolygon* SharePoly(int)const 
	{
		XCALL(0x00569760);
	};

	zCPolygon* CheckRayPolyIntersection(zVEC3 const&,zVEC3 const&,zVEC3&)
	{
		XCALL(0x00569780);
	};

	zCPolygon* CheckRayPolyIntersection(int&,int,int,zVEC3&)
	{
		XCALL(0x005697E0);
	};

	zCPolygon* PickPolygon(zVEC3 const&,zVEC3 const&,zVEC3&)
	{
		XCALL(0x00569990);
	};

	zCPolygon* PickPolygon(int&,int,int,zVEC3&)
	{
		XCALL(0x00569A60);
	};

	void CalcVertexNormals(zCMesh::zTCalcVertNormalMode,void*)
	{
		XCALL(0x00569DE0);
	};

	void UnSmoothMesh(void)
	{
		XCALL(0x0056A4E0);
	};

	void SetDefaultPlanarMapping(float,float)
	{
		XCALL(0x0056A580);
	};

	void CalcBBox3D(int)
	{
		XCALL(0x0056A610);
	};

	void Center(void)
	{
		XCALL(0x0056A7A0);
	};

	void TransformAllVerts(zMAT4 const&,int)
	{
		XCALL(0x0056A8F0);
	};

	void MergeMesh(zCMesh*,zMAT4 const&)
	{
		XCALL(0x0056A9B0);
	};

	void CalcNormals(void)
	{
		XCALL(0x0056AE90);
	};

	void SetMaterial(zCMaterial*)
	{
		XCALL(0x0056AEC0);
	};

	void ScaleXZ(float,float)
	{
		XCALL(0x0056AF20);
	};

	void Scale(float,float,float)
	{
		XCALL(0x0056AF90);
	};

	void CheckForMaterials(void)const 
	{
		XCALL(0x0056B050);
	};

	int Render( zTRenderContext&, zCOLOR*)
	{
		XCALL(0x0056B210);
	};

	int RenderHorizon( zTRenderContext&,float)
	{
		XCALL(0x0056B4F0);
	};

	void RenderDecal(float,float,float,int)
	{
		XCALL(0x0056B7A0);
	};

	void RenderDecalHorizon(float,float,float,float)
	{
		XCALL(0x0056B980);
	};

	void RenderDecal( zTRenderContext&,int)
	{
		XCALL(0x0056BDA0);
	};

	void ResetStaticLight(void)
	{
		XCALL(0x0056C000);
	};

	void SetStaticLight( zCOLOR)
	{
		XCALL(0x0056C040);
	};

	void SetLightDyn( zCOLOR)
	{
		XCALL(0x0056C080);
	};

	void SetLightStatAlpha(unsigned char)
	{
		XCALL(0x0056C0C0);
	};

	void ResetLightDynToLightStat(void)
	{
		XCALL(0x0056C100);
	};

	void AddToLightDyn( zCOLOR)
	{
		XCALL(0x0056C140);
	};

	static zCMesh* CreateQuadMesh(int)
	{
		XCALL(0x0056C180);
	};

	static zCMesh* CreateTriMesh(void)
	{
		XCALL(0x0056C4D0);
	};

	static int CheckTexUVOnPlane(zCArray<zCVertex*> const&,zCArray<zCVertFeature> const&)
	{
		XCALL(0x0056C6A0);
	};

	static void ConvertTrisToNPolys(zCPolygon**,int,zCMesh*,int)
	{
		XCALL(0x0056CBA0);
	};

	static unsigned short GetFileVersion(void)
	{
		XCALL(0x0056D780);
	};

	void SaveMSH(zCFileBIN&)
	{
		XCALL(0x0056D790);
	};

	void SaveMSH(zSTRING const&)
	{
		XCALL(0x0056D7B0);
	};

	static void SaveMSH(zCFileBIN&,zCPolygon**,int,zCMesh*)
	{
		XCALL(0x0056D940);
	};

	int LoadMSH(zCFileBIN&,int)
	{
		XCALL(0x005700E0);
	};

	int LoadMSH(zSTRING const&,int)
	{
		XCALL(0x005716B0);
	};

	void CreateListsFromArrays(void)const 
	{
		XCALL(0x00571980);
	};

	void ClearLists(void)const 
	{
		XCALL(0x00571A50);
	};

	void ArraysToLists(void)const 
	{
		XCALL(0x00571AB0);
	};

	void ShareFeatures(void)
	{
		XCALL(0x00571B90);
	};

	void UnshareFeatures(void)
	{
		XCALL(0x00572970);
	};

	void FlipPolys(void)
	{
		XCALL(0x00572A90);
	};

	void SortPolysByMaterial(void)
	{
		XCALL(0x00572D10);
	};

	void SortPolysByList(zCPolygon**,int)
	{
		XCALL(0x00572DC0);
	};

	void DeletePolyAndVerts(zCPolygon*)
	{
		XCALL(0x00573650);
	};

	void DeletePolyAndVerts(unsigned long)
	{
		XCALL(0x005736E0);
	};

	void RemoveDegeneratePolys(void)
	{
		XCALL(0x00573860);
	};

	void CombineLightmaps(void)
	{
		XCALL(0x00573A90);
	};

	void LightMesh(zCVobLight&,zMAT4&,zCWorld*)
	{
		XCALL(0x00629A50);
	};
	int GetNumPoly()
	{
		return *(int*)(((char *)this) + 0x34);

	};
};
