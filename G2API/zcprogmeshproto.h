#pragma once

#include "ztypes.h"
#include "zcvisual.h"
#include "zcmesh.h"

class zCVertexBuffer;
class zCVertexBufferDyn;
class zCRenderLightContainer;


typedef WORD zPMINDEX;

#define zPMINDEX_NONE				(zPMINDEX(0xFFFF))


struct zTPMWedge
{
	zVEC3						normal;
	zVEC2						texUV;
	zPMINDEX					position;
};

struct zTPMTriangle
{
	zPMINDEX					wedge[3];				
};													

struct zTPMTriangleEdges
{
	zPMINDEX					edge[3];				
};													

struct zTPMEdge
{
	zPMINDEX					wedge[2];				
};													



struct zTPMVertexUpdate
{
	zPMINDEX					numNewTri;
	zPMINDEX					numNewWedge;
};



enum zTPMRenderFlags
{
	zPM_RENDER_FLAG_SW_TRAFO_VERTS		= 1,		
	zPM_RENDER_FLAG_PACK_DYNAMIC_VB		= 2,		
	zPM_RENDER_FLAG_DONT_SET_TRANSFROM	= 4,		
	zPM_RENDER_FLAG_MORPH				= 8
};

enum zTPMLightingMode
{ 
	zPM_LIGHTING_MODE_PRELIT			= 0,
	zPM_LIGHTING_MODE_EXACT
};

struct zTWedgeColl
{
	zTPMWedge			*wedgeFrom;
	zTPMWedge			*wedgeTo;
};

struct zTEdgeScore
{
	int		edgeIndex;
	float	score;
};

struct zTLazyMesh
{
	zCArray<int>				wedgePermut;			
	zCArray<int>				wedgeParent;			
	zCArray<zPMINDEX>			triMatIndexList;		
	zCArray<zPOINT3>			posList;				
	zCArray<zVEC3>				posNormalList;			

	zCArray<zCMaterial*>		matList;
	zCArray<zTPMTriangle>		triList;				
	zCArray<zTPMWedge>			wedgeList;				
	zCArray<float>				colorList;				
	zCArray<zPMINDEX>			wedgeMap;				
	zCArray<zTPMVertexUpdate>	vertexUpdates;			
	zCArray<zPMINDEX>			triPlaneIndexList;		
	zCArray<zTPlane>			triPlaneList;			
	zCArray<zTPMTriangleEdges>	triEdgeList;			
	zCArray<zTPMEdge>			edgeList;				
	zCArray<float>				edgeScoreList;			

	DWORD CalcSizeBytesFullMeshPart()
	{
		DWORD size=0;
		size += CalcArraySize (posList);
		size += CalcArraySize (posNormalList);
		return size;
	};
	DWORD CalcSizeBytes()
	{
		DWORD size=0;
		size += CalcArraySize (triList);
		size += CalcArraySize (wedgeList);
		size += CalcArraySize (colorList);
		size += CalcArraySize (wedgeMap);
		size += CalcArraySize (vertexUpdates);
		size += CalcArraySize (triPlaneIndexList);
		size += CalcArraySize (triPlaneList);
		size += CalcArraySize (triEdgeList);
		size += CalcArraySize (edgeList);
		size += CalcArraySize (edgeScoreList);
		return size;
	};
};

class zCProgMeshProto : public zCVisual				
{
public:
	zCLASS(zCProgMeshProto)
public:
	
	struct zTLODRenderArgs
	{
		float		vertPerc;
		int			numPos;					
		int			numMinMorphPos;
		float		morphFrac;
	};

	struct zTLODParams
	{
		float					strength;				
		float					zDisplace2;				
		float					morphPerc;				
		int						minVerts;				
	};
	struct zTLODRenderArgsSubMesh
	{
		int			m_nTriangleSize;	
		int			m_nCollapseSize;	
		int			m_nCollapzeStart;	
		int			m_nEdgesSize;		
	};
	class zCSubMesh
	{
	public:
		zCSubMesh(void)
		{
			XCALL(0x005C6A20);
		};

		~zCSubMesh(void)
		{
			XCALL(0x005C6A70);
		};

		
		zCMaterial*						material;
		zCArrayAdapt<zTPMTriangle>		triList;
		zCArrayAdapt<zTPMWedge>			wedgeList;
		zCArrayAdapt<float>				colorList;				
		zCArrayAdapt<WORD>				triPlaneIndexList;		
		zCArrayAdapt<zTPlane>			triPlaneList;			
		zCArrayAdapt<zTPMTriangleEdges>	triEdgeList;
		zCArrayAdapt<zTPMEdge>			edgeList;
		zCArrayAdapt<float>				edgeScoreList;
		
		
		zCArrayAdapt<WORD>				wedgeMap;				
		zCArrayAdapt<zTPMVertexUpdate>	vertexUpdates;			
		int								vbStartIndex;			
	};
public:
	
	zCArrayAdapt<zVEC3>			posList;
	zCArrayAdapt<zVEC3>			posNormalList;			
	
	enum						{ NUM_WEDGE_CACHE	= 4096 };	
	enum						{ NUM_POS_CACHE		= 2048 };
	enum						{ NUM_LOD_CACHE		= 4096 };
	
	zTBBox3D					bbox3D;
	zCOBBox3D					obbox3D;

	
	zCVertexBuffer*				vertexBufferStatic;

	
	zCSubMesh*					subMeshList;
	int							numSubMeshes;

	
	BYTE						*dataPool;				
	DWORD						dataSize;
	float						avgTriArea;
	BOOL						m_bUsesAlphaTesting;

	BOOL						HasSubdivData			() const { return ((numSubMeshes>0) && (subMeshList[0].triEdgeList.GetNum()>0)); };
	
	zTLODParams					lodParams;
	zTPMLightingMode			lightingMode; 
	DWORD						pmeshID;
	DWORD						renderSortKey;
	static zCClassDef			*classDef;
	static int s_frameCtr;
	static int s_subMeshRenderDir;
	static float s_lodParamStrengthOverride;
	static float s_lodParamStrengthModifier;
	static unsigned short*& s_wedgeRemap;
	static zVEC3*& s_posCacheListLOD;
	static zVEC3*& s_posCacheList;
	static zVEC3*& s_posNormalCSList;
	static int*& s_posCacheListLODIndices;
	static zCArray<unsigned short> s_workIndexList;
	static int s_autoSubdivEnabled;
	static unsigned long s_classCtorCtr;
	static int s_posCacheCount;
	static int s_posCacheCountLOD;
	static int s_posCacheIndex;
	static int s_markMeshMaterials;
	static zCVertexBufferDyn*& s_vertBufferColor;
	static zCVertexBufferDyn*& s_vertBufferNormal;
public:
	virtual zCClassDef* _GetClassDef				()const {XCALL(0x005C6C40);};
	
	BOOL						Render				(zTRenderContext& renderContext);
	BOOL						IsBBox3DLocal		() { return TRUE;		};				
	zTBBox3D					GetBBox3D			() { return bbox3D;		};				
	zCOBBox3D*					GetOBBox3D			() { return &obbox3D;	};				
	zSTRING						GetVisualName		() {XCALL(0x005C7130);};
	void						DynLightVisual		(const zCArray<zCVobLight*>& vobLightList, zMAT4 *trafoObjToWorld=0) {};
	inline DWORD				GetRenderSortKey	() const { return renderSortKey; };	

	
	BOOL						CanTraceRay			() const		{ return TRUE; };	
	BOOL					 	TraceRay			(	const zVEC3&		rayOrigin, 
														const zVEC3&		ray, 
														const int			traceFlags, 
														zTTraceRayReport	&report){XCALL(0x005C81A0);};
	virtual BOOL				Save				(zCFileBIN& file){XCALL(0x005CCE10);};
	virtual BOOL				Load				(zCFileBIN& file){XCALL(0x005CD270);};
	
	virtual BOOL				GetAlphaTestingEnabled		()	const						{ return m_bUsesAlphaTesting;	};
	virtual void				SetAlphaTestingEnabled		(const BOOL a_btest)			{ m_bUsesAlphaTesting = a_btest; };
	
	const zSTRING*				GetFileExtension	(int i)									{XCALL(0x005C7100);};
	zCVisual*					LoadVisualVirtual	(const zSTRING& visualName) const		{XCALL(0x005C7120);};
	virtual ~zCProgMeshProto								()								{XCALL(0x005C6C80);};	
	void CopySubMeshData(unsigned char*&, zTLazyMesh const&,zCSubMesh*)
	{
		XCALL(0x005C2940);
	};

	zCProgMeshProto(void)
	{
		XCALL(0x005C6AF0);
	};

	void CalcRenderSortKey(void)
	{
		XCALL(0x005C6D70);
	};

	static void SetLODParamStrengthModifier(float)
	{
		XCALL(0x005C6DB0);
	};

	static float GetLODParamStrengthModifier(void)
	{
		XCALL(0x005C6E10);
	};

	void PackStaticVertexBuffers(void)
	{
		XCALL(0x005C6E30);
	};

	static zCVisual* Load(zSTRING const&)
	{
		XCALL(0x005C7180);
	};

	static int BuildProgMeshProto(zCMesh*,zCProgMeshProto*,zCArray<int>*,int)
	{
		XCALL(0x005C7B90);
	};

	int __fastcall CheckRayPolyIntersection(zCSubMesh*,int,zVEC3 const&,zVEC3 const&,zVEC3&,float&)const 
	{
		XCALL(0x005C7BF0);
	};

	int __fastcall CheckRayPolyIntersection2Sided(zCSubMesh*,int,zVEC3 const&,zVEC3 const&,zVEC3&,float&)const 
	{
		XCALL(0x005C7EE0);
	};

	int GetNumTri(void)const 
	{
		XCALL(0x005C8380);
	};

	zCPolygon* GetPolygon(int)
	{
		XCALL(0x005C83A0);
	};

	zCMesh* GetMesh(int)
	{
		XCALL(0x005C8530);
	};

	int GetLowestLODNumPolys(void)
	{
		XCALL(0x005C89B0);
	};

	zVEC3* GetLowestLODPoly(int,zVEC3*&)
	{
		XCALL(0x005C89D0);
	};

	static void InitProgMeshProto(void)
	{
		XCALL(0x005C8BA0);
	};

	static int CreateDynamicVertexBuffer(void)
	{
		XCALL(0x005C8D20);
	};

	static void CleanupProgMeshProto(void)
	{
		XCALL(0x005C8D80);
	};

	float __fastcall CalcLODRenderVertPerc( zTRenderContext const&)
	{
		XCALL(0x005C8DF0);
	};

	int __fastcall CalcLODRenderArgs( zTRenderContext const&, zTLODRenderArgs&)
	{
		XCALL(0x005C8FA0);
	};

	int __fastcall CalcLODRenderArgsMin( zTRenderContext const&, zTLODRenderArgs&)
	{
		XCALL(0x005C91E0);
	};

	int __fastcall CalcLODRenderArgsSubMesh( zTRenderContext const&, zTLODRenderArgs const&,zCSubMesh const*, zTLODRenderArgsSubMesh&)
	{
		XCALL(0x005C93E0);
	};

	int __fastcall RenderProgMesh( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*,float,float)
	{
		XCALL(0x005C9680);
	};

	int __fastcall RenderStatic( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*)
	{
		XCALL(0x005C9C50);
	};

	int __fastcall RenderStaticLOD( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*)
	{
		XCALL(0x005C9E30);
	};

	void __fastcall SoftwareTransformVerts(int, zTLODRenderArgs*,float,float)
	{
		XCALL(0x005CA170);
	};

	int __fastcall RenderDynamicLOD( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*,float,float)
	{
		XCALL(0x005CAF50);
	};

	void __fastcall CalcSubdiv(int, zTLODRenderArgs const*)
	{
		XCALL(0x005CB820);
	};

	void __fastcall CalcNumSubdivEdges(zCSubMesh*, zTLODRenderArgs const*, zTLODRenderArgsSubMesh&)
	{
		XCALL(0x005CB8E0);
	};

	void __fastcall CalcSubdivSubMesh(zCSubMesh*,zCVertexBuffer*, zTLODRenderArgs const*,zCRenderLightContainer*, zTLODRenderArgsSubMesh&)
	{
		XCALL(0x005CB940);
	};

	int __fastcall RenderDynamicSubdiv( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*,float,float)
	{
		XCALL(0x005CBC60);
	};

	int __fastcall RenderStaticLODShadow( zTRenderContext&,int, zTLODRenderArgs*,zCRenderLightContainer*)
	{
		XCALL(0x005CC2F0);
	};

	static unsigned short GetFileVersion(void)
	{
		XCALL(0x005CCE00);
	};

	static void InitSetupLowestLOD(void)
	{
		XCALL(0x005CF510);
	};

	static void SetLODParamStrength(float)
	{
		XCALL(0x006370E0);
	};

	// [AST]
	int SaveMesh_AST(zCFileBIN& file);
	// [/AST]
};

class zCMeshSoftSkin : public zCProgMeshProto				
{
public:

	friend class zCModelNodeInst;
	friend class zCModelPrototype;
	friend class zCModel;
public:
#pragma pack (push, 1)
	struct zTWeightEntry
	{					
		float			weight;
		zVEC3			vertPosOS;
		BYTE			nodeIndex;			
		zTWeightEntry(void)
		{
			XCALL(0x0058DBF0);
		};
	};
#pragma pack (pop)

	typedef int zTNumWeightEntry;

	
	
	
	
	
	zCArray<int>		nodeIndexList;			
	zCArray<zCOBBox3D*>	nodeOBBList;

	struct zTNodeWedgeNormal {
		zVEC3			normal;
		int				nodeIndex;
	};
	zCArray<zTNodeWedgeNormal>	nodeWedgeNormalList;		
private:
	BYTE					*vertWeightStream;
	BYTE					*iterator;
public:
	static zCClassDef classDef;
	zCMeshSoftSkin(void)
	{
		XCALL(0x005CDBD0);
	};

	void AllocVertWeightStream(int,int)
	{
		XCALL(0x005CDD70);
	};

	void DeleteVertWeightStream(void)
	{
		XCALL(0x005CDDC0);
	};

	void AddNumWeightEntry(int const&)
	{
		XCALL(0x005CDDF0);
	};

	void AddWeightEntry( zCMeshSoftSkin::zTWeightEntry const&)
	{
		XCALL(0x005CDE10);
	};

	void ResetVertWeightIterator(void)
	{
		XCALL(0x005CDE50);
	};

	int GetVertWeightStreamSize(void)
	{
		XCALL(0x005CDE60);
	};

	void BuildNodeIndexList(void)
	{
		XCALL(0x005CDEA0);
	};

	void DeleteNodeOBBList(void)
	{
		XCALL(0x005CE050);
	};

	void BuildNodeOBBList(void)
	{
		XCALL(0x005CE0C0);
	};

	static unsigned short GetFileVersion(void)
	{
		XCALL(0x005CE660);
	};

	int __fastcall RenderSoftSkin( zTRenderContext&,zCArray<zMAT4*> const&,zCRenderLightContainer*,float)
	{
		XCALL(0x005CEEA0);
	};

	void __fastcall SetupLowestLOD( zTRenderContext&,zCArray<zMAT4*> const&,float,int&)
	{
		XCALL(0x005CF530);
	};

	int GetLowestLODNumPolys(void)
	{
		XCALL(0x005CFFC0);
	};

	zVEC3* GetLowestLODPoly(int,zVEC3*&)
	{
		XCALL(0x005CFFD0);
	};

	virtual zCClassDef* _GetClassDef				()const				{XCALL(0x005C6950);};
	virtual BOOL			Save					(zCFileBIN& file)	{XCALL(0x005CE930);};	
	virtual BOOL			Load					(zCFileBIN& file)	{XCALL(0x005CE670);};
	virtual ~zCMeshSoftSkin							()					{XCALL(0x005CDC60);};
};