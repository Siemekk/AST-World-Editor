#pragma once

#include "ztypes.h"
#include "zcbsptree.h"
#include "zcvob.h"
#include "zcontainers.h"

#define zCWorld_DIMENSION 3
#define VOB_HASHTABLE_SIZE 2048

static bool bIsTraceWork;

class zCWorldPerFrameCallback	
{
public:
	virtual void DoWorldPerFrameCallback(zCWorld*, zCCamera*) = 0;
};


enum zTTraceRayFlags {
		// Flags for vobs (exclusive)
		zTRACERAY_VOB_IGNORE_NO_CD_DYN		= 1<<0,		// ignores vobs, if they have not set the flag for dynamic collision
		zTRACERAY_VOB_IGNORE				= 1<<1,		// ignores vobs
		zTRACERAY_VOB_BBOX					= 1<<2,		// only tests vob bounding boxes	(always available)
		zTRACERAY_VOB_OBB					= 1<<3,		// only tests vob oriented bbox		(if available)
//		zTRACERAY_VOB_POLY		 		 * DEFAULT *	// tests vob's polys				(if available)

		// Flags for static world (exclusive)
		zTRACERAY_STAT_IGNORE				= 1<<4,		// ignores static world geometry
//		zTRACERAY_STAT_INTERS			 * DEFAULT *	// reports poly intersections
		zTRACERAY_STAT_POLY					= 1<<5,		// reports poly intersections & pointer to poly
		zTRACERAY_STAT_PORTALS				= 1<<6,		// tests static world geometry portals (e.g. invisible/walkthru)

		// Misc Flags (not exclusive)
		zTRACERAY_POLY_NORMAL				= 1<<7,		// reports normals of found polys		(VOB/STAT, worldSpace)
		zTRACERAY_POLY_IGNORE_TRANSP		= 1<<8,		// ignores transparent polys			(VOB/STAT) [material-alpha or texture-alphaChannel]
		zTRACERAY_POLY_TEST_WATER			= 1<<9,		// tests water polys					(VOB/STAT)
		zTRACERAY_POLY_2SIDED				= 1<<10,	// reports front and backfacing polys	(VOB/STAT)
		zTRACERAY_VOB_IGNORE_CHARACTER		= 1<<11,	// ignores vobs that are characters 

//		zTRACERAY_NEARESTHIT			 * DEFAULT *	// searches for the nearest intersection to rayOrigin
		zTRACERAY_FIRSTHIT					= 1<<12,	// INTERNAL; stops at the first intersection: LOS existance problem (faster)
		zTRACERAY_VOB_TEST_HELPER_VISUALS	= 1<<13,	// INTERNAL; tests against helper visuals (for editor/spacer)
		zTRACERAY_VOB_IGNORE_PROJECTILES	= 1<<14,
};

class zCSkyControler;
class zCCSPlayer;
class zCWayNet;
class zCSkyControlerOutdoor;
class zCSession;
class zCViewProgressBar;
class zCPatchMap;
class zCRayCache;
class zCPlayerGroup;
class zFILE;

class zCWorld : public zCObject
{
public:
	zCLASS(zCWorld)
	
	zCTree<zCVob>		globalVobTree;				
	zTTraceRayReport	traceRayReport;
	
	enum zTWorldLoadMode
	{	zWLD_LOAD_GAME_STARTUP,			
		zWLD_LOAD_GAME_SAVED_DYN,		
		zWLD_LOAD_GAME_SAVED_STAT,		
		zWLD_LOAD_EDITOR_COMPILED,		
		zWLD_LOAD_EDITOR_UNCOMPILED,	
		zWLD_LOAD_MERGE
	};
	enum zTWorldSaveMode
	{	zWLD_SAVE_GAME_SAVED_DYN,		
		zWLD_SAVE_EDITOR_COMPILED,		
		zWLD_SAVE_EDITOR_UNCOMPILED,	
		zWLD_SAVE_COMPILED_ONLY			
	};
	enum zTWorldLoadMergeMode
	{	zWLD_LOAD_MERGE_ADD,					
		zWLD_LOAD_MERGE_REPLACE_ROOT_VISUAL     
	};
	
	enum zTStaticWorldLightMode
	{	
		zWLD_LIGHT_VERTLIGHT_ONLY,
		zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_LOW_QUAL,
		zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_MID_QUAL,
		zWLD_LIGHT_VERTLIGHT_LIGHTMAPS_HI_QUAL
	};
	zCSession*					ownerSession;
	zCCSPlayer*					csPlayer;
								
	zSTRING						m_strlevelName;
	BOOL						compiled;
	BOOL						compiledEditorMode;
	BOOL						traceRayIgnoreVobFlag;
	BOOL						m_bIsInventoryWorld;
	zTWld_RenderMode			worldRenderMode;
	zCWayNet					*wayNet;
	zTFrameCtr					masterFrameCtr;
	float						vobFarClipZ;
	float						vobFarClipZScalability;		
	zCArray<zCVob*>				traceRayVobList;			
	zCArray<zCVob*>				traceRayTempIgnoreVobList;	
	BOOL						renderingFirstTime;
	BOOL						showWaynet;					
	BOOL						showTraceRayLines;			
	
	zCViewProgressBar			*progressBar;
	DWORD						unarchiveFileLen;			
	DWORD						unarchiveStartPosVobtree;	
	int							numVobsInWorld;
	zCArray<zCWorldPerFrameCallback*> perFrameCallbackList;

	
	zCSkyControler				*skyControlerIndoor;
	zCSkyControler				*skyControlerOutdoor;
	zCSkyControler				*activeSkyControler;
								
	
	zCArray<zCZone*>			zoneGlobalList;				
	zCArraySort<zCZone*>		zoneActiveList;
	zCArraySort<zCZone*>		zoneLastClassList;

	
	          int zoneBoxSorter_vtbl;     
	
	          int zoneBoxSorter_handles_array;         
	          int zoneBoxSorter_handles_numAlloc;      
	          int zoneBoxSorter_handles_numInArray;    
	
	
	          int zoneBoxSorter_nodeList0_array;         
	          int zoneBoxSorter_nodeList0_numAlloc;      
	          int zoneBoxSorter_nodeList0_numInArray;    
	          int zoneBoxSorter_nodeList0_compare;       
	
	          int zoneBoxSorter_nodeList1_array;         
	          int zoneBoxSorter_nodeList1_numAlloc;      
	          int zoneBoxSorter_nodeList1_numInArray;    
	          int zoneBoxSorter_nodeList1_compare;       
	
	          int zoneBoxSorter_nodeList2_array;         
	          int zoneBoxSorter_nodeList2_numAlloc;      
	          int zoneBoxSorter_nodeList2_numInArray;    
	          int zoneBoxSorter_nodeList2_compare;       
	          int zoneBoxSorter_sorted;                  

	
				int zoneActiveHandle_vtbl;                  
				int zoneActiveHandle_mySorter;              
	zTBBox3D bbox3D;

				int zoneActiveHandle_indexBegin [zCWorld_DIMENSION]; 
				int zoneActiveHandle_indexEnd   [zCWorld_DIMENSION]; 
	zCArray<zCVob*>				activeList;
	BOOL						addZonesToWorld;
	BOOL						showZonesDebugInfo;

	
	zCCBspTree					*cbspTree;						
	zCBspTree					bspTree;						
															
	
	zCArray<zCVob*>				activeVobList;					
	zCArray<zCVob*>				walkList;						
	enum						{ zNUM_VOB_HASH	= 2048 };
	zCArray<zCVob*>				vobHashTable[zNUM_VOB_HASH];	
	static zCClassDef*		classDef;
public:

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00620040);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00627890);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x006269D0);
	};

	virtual ~zCWorld()
	{
		XCALL(0x00620080);
	};

	virtual int LoadWorld(const zSTRING& fileName, const zTWorldLoadMode loadMode)
	{
		XCALL(0x006270D0);
	};

	virtual int SaveWorld(const zSTRING& fileName, const zTWorldSaveMode saveMode, const BOOL	writeBinary=FALSE, const BOOL _saveLevelMesh=FALSE)
	{
		XCALL(0x00627BB0);
	};

	virtual zCVob* MergeVobSubtree(zSTRING const&,zCVob*,zCWorld::zTWorldLoadMergeMode)
	{
		XCALL(0x006273E0);
	};

	virtual int SaveVobSubtree(zSTRING const&,zCVob*,int,int)
	{
		XCALL(0x00627E50);
	};

	virtual void DisposeWorld(void)
	{
		XCALL(0x00623D30);
	};

	virtual int DisposeVobs(zCTree<zCVob>*)
	{
		XCALL(0x00623960);
	};

	virtual int DisposeVobsDbg(zCTree<zCVob>*)
	{
		XCALL(0x00623AF0);
	};

	virtual void DisposeStaticWorld(void)
	{
		XCALL(0x00623C80);
	};

	virtual zCTree<zCVob>* AddVobAsChild(zCVob*,zCTree<zCVob>*)
	{
		XCALL(0x006245A0);
	};

	virtual void RemoveVob(zCVob*)
	{
		XCALL(0x00624B70);
	};

	virtual void RemoveVobSubtree(zCVob*)
	{
		XCALL(0x00624D60);
	};

	virtual void MoveVobSubtreeTo(zCVob*,zCTree<zCVob>*)
	{
		XCALL(0x00624DB0);
	};

	virtual zCPlayerGroup* GetPlayerGroup(void)
	{
		XCALL(0x00620050);
	};

	virtual zCVob* SearchVob(zCVob*,zCTree<zCVob>*)
	{
		XCALL(0x00623F10);
	};

	virtual zCVob* SearchVobByID(const unsigned long vobID	, zCTree<zCVob>* vobNode=0)
	{
		XCALL(0x00623F60);
	};

	virtual zCVob* SearchVobByName(zSTRING const&)
	{
		XCALL(0x00623FB0);
	};

	virtual void SearchVobListByName(zSTRING const&,zCArray<zCVob*>&)
	{
		XCALL(0x00624090);
	};

	virtual void SearchVobListByClass(zCClassDef*,zCArray<zCVob*>&,zCTree<zCVob>*)
	{
		XCALL(0x00624250);
	};

	virtual void SearchVobListByBaseClass(zCClassDef*,zCArray<zCVob*>&,zCTree<zCVob>*)
	{
		XCALL(0x00624320);
	};

	virtual void VobAddedToWorld(zCVob*)
	{
		XCALL(0x00624830);
	};

	virtual void VobRemovedFromWorld(zCVob*)
	{
		XCALL(0x00624970);
	};

	virtual void RenderWaynet(zCCamera*)
	{
		XCALL(0x00620450);
	};

	void zWorld(void)
	{
		XCALL(0x0061FA40);
	};

	zCWorld(void)
	{
		XCALL(0x0061FA40);
	};

	zCSkyControler* GetActiveSkyControler(void)
	{
		XCALL(0x006203A0);
	};
	public:
	void SetSkyControlerIndoor(zCSkyControler*)
	{
		XCALL(0x006203D0);
	};

	void SetSkyControlerOutdoor(zCSkyControler*)
	{
		XCALL(0x00620410);
	};

	static int ActiveZoneListCompare(void const*,void const*)
	{
		XCALL(0x00620470);
	};

	void AddZone(zCZone*)
	{
		XCALL(0x006204C0);
	};

	void RemoveZone(zCZone*)
	{
		XCALL(0x00620630);
	};

	void RemoveAllZones(void)
	{
		XCALL(0x00620770);
	};

	void UpdateZone(zCZone*)
	{
		XCALL(0x006207E0);
	};

	void ProcessZones(void)
	{
		XCALL(0x006207F0);
	};

	void ShowZonesDebugInfo(void)
	{
		XCALL(0x00620E60);
	};

	void ShowTextureStats(void)
	{
		XCALL(0x00621280);
	};

	void Render(zCCamera&)
	{
		XCALL(0x00621700);
	};

	int __fastcall TraceRayFirstHit(zVEC3 const&,zVEC3 const&,zCArray<zCVob*> const*,int)
	{
		XCALL(0x00621960);
	};

	int __fastcall TraceRayNearestHit(zVEC3 const&,zVEC3 const&,zCArray<zCVob*> const*,int)
	{
		XCALL(0x00621B80);
	};

	int __fastcall TraceRayFirstHit(zVEC3 const&,zVEC3 const&,zCVob*,int)
	{
		XCALL(0x00621E70);
	};

	int __fastcall TraceRayNearestHit(zVEC3 const&,zVEC3 const&,zCVob*,int)
	{
		XCALL(0x00621FA0);
	};

	int __fastcall TraceRayFirstHitCache(zVEC3 const&,zVEC3 const&,zCArray<zCVob*> const*,int,zCRayCache*)
	{
		XCALL(0x006220D0);
	};

	int __fastcall TraceRayFirstHitCache(zVEC3 const&,zVEC3 const&,zCVob*,int,zCRayCache*)
	{
		XCALL(0x00622230);
	};

	int __fastcall TraceRayNearestHitCache(zVEC3 const&,zVEC3 const&,zCArray<zCVob*> const*,int,zCRayCache*)
	{
		XCALL(0x006223F0);
	};

	int __fastcall TraceRayNearestHitCache(zVEC3 const&,zVEC3 const&,zCVob*,int,zCRayCache*)
	{
		XCALL(0x00622550);
	};

	int __fastcall PickScene(zCCamera&,int,int,float)
	{
		XCALL(0x00622710);
	};

	int TraverseBsp(zCCBspTree*,zCTree<zCVob>*,int)
	{
		XCALL(0x00622980);
	};

	int TraverseBspAddVobsToMesh(zCCBspTree*,zCTree<zCVob>*)
	{
		XCALL(0x00622A80);
	};

	void SaveBspTreeMesh3DS(zSTRING const&)
	{
		XCALL(0x00622E90);
	};

	void CompileWorld(zTBspTreeMode const&,float,int,int,zCArray<zCPolygon*>*)
	{
		XCALL(0x00622EC0);
	};

	void SearchZoneListByClass(zCClassDef*,zCArray<zCZone*>&)
	{
		XCALL(0x00624400);
	};

	zCZone* SearchZoneDefaultByClass(zCClassDef*)
	{
		XCALL(0x00624530);
	};

	int ShouldAddThisVobToBsp(zCVob*)const 
	{
		XCALL(0x006247B0);
	};

	zCTree<zCVob>* AddVobAsChild(zCVob*,zCVob*)
	{
		XCALL(0x006247F0);
	};

	zCTree<zCVob>* AddVob(zCVob*)
	{
		XCALL(0x00624810);
	};

	void RemoveVob(zCTree<zCVob>*)
	{
		XCALL(0x00624BA0);
	};

	void RemoveVobSubtree_r(zCTree<zCVob>*,int)
	{
		XCALL(0x00624BC0);
	};

	void RemoveVobSubtree(zCTree<zCVob>*)
	{
		XCALL(0x00624D90);
	};

	void MoveVobSubtreeTo(zCVob*,zCVob*)
	{
		XCALL(0x00624E70);
	};

	void MoveVobSubtreeToWorldSpace(zCVob*)
	{
		XCALL(0x00624E90);
	};

	void RemoveVobFromLists(zCVob*)
	{
		XCALL(0x00624EB0);
	};

	void PrintStatus(void)
	{
		XCALL(0x00625080);
	};

	void PrintGlobalVobTree(zCTree<zCVob>*,int)
	{
		XCALL(0x00625AE0);
	};

	void PrintActiveVobs(void)
	{
		XCALL(0x00625DA0);
	};

	void UpdateVobTreeBspDependencies(zCTree<zCVob>*)
	{
		XCALL(0x00625FE0);
	};

	void MoveVobs(void)
	{
		XCALL(0x00626050);
	};

	void AdvanceClock(float)
	{
		XCALL(0x006260E0);
	};

	void SaveBspTree(zFILE&)
	{
		XCALL(0x00626120);
	};

	int LoadBspTree(zFILE&,int)
	{
		XCALL(0x006262A0);
	};

	void DebugMarkOccluderPolys(void)
	{
		XCALL(0x006263D0);
	};

	void __fastcall UnarcTraverseVobs(zCArchiver&,zCTree<zCVob>*)
	{
		XCALL(0x00626570);
	};

	zCViewProgressBar* GetProgressBar(void)const 
	{
		XCALL(0x006269C0);
	};

	void __fastcall ArcTraverseVobs(zCArchiver&,zCTree<zCVob>*,int)
	{
		XCALL(0x006274A0);
	};

	void TraverseVobTree(zCVobCallback&,void*,zCTree<zCVob>*)
	{
		XCALL(0x00627F10);
	};

	unsigned long GetVobHashIndex(zSTRING const&)
	{
		XCALL(0x00627F70);
	};

	unsigned long GetVobHashIndex(zCVob*)
	{
		XCALL(0x00627FA0);
	};

	void InsertVobHashTable(zCVob*)
	{
		XCALL(0x00627FE0);
	};

	void RemoveVobHashTable(zCVob*)
	{
		XCALL(0x00628100);
	};

	zCVob* SearchVobHashTable(zSTRING const&)
	{
		XCALL(0x00628190);
	};

	void SearchVobListHashTable(zSTRING const&,zCArray<zCVob*>&)
	{
		XCALL(0x00628270);
	};

	void SetOwnerSession(zCSession*)
	{
		XCALL(0x00628430);
	};

	zCSession* GetOwnerSession(void)
	{
		XCALL(0x00628480);
	};

	void ResetCutscenePlayer(void)
	{
		XCALL(0x00628490);
	};

	void RegisterPerFrameCallback(zCWorldPerFrameCallback*)
	{
		XCALL(0x006284E0);
	};

	void UnregisterPerFrameCallback(zCWorldPerFrameCallback*)
	{
		XCALL(0x00628610);
	};

	void LightWorldStaticUncompiled(zCTree<zCVob>*)
	{
		XCALL(0x00629B30);
	};

	void LightWorldStaticCompiled(void)
	{
		XCALL(0x00629F70);
	};

	void GenerateStaticVertexLighting(void)
	{
		XCALL(0x0062A760);
	};

	int LightingTestRay(zVEC3 const&,zVEC3 const&,zVEC3&,zCPolygon*&)
	{
		XCALL(0x0062AA70);
	};

	int GetSurfaceLightmapBBox2D(zCArray<zCPolygon*>&, zTBBox2D&,int* const)
	{
		XCALL(0x0062AB30);
	};

	zVEC3 GetPhongNormal(zCPolygon*,zVEC3 const&)
	{
		XCALL(0x0062AF90);
	};

	zCPatchMap* GeneratePatchMapFromSurface(zCArray<zCPolygon*>&)
	{
		XCALL(0x0062B350);
	};

	void GenerateLightmapFromPatchMap(zCPatchMap*)
	{
		XCALL(0x0062C1B0);
	};

	void LightPatchMap(zCPatchMap*)
	{
		XCALL(0x0062D4C0);
	};

	void GenerateSurfaces(int, zTBBox3D*)
	{
		XCALL(0x0062D970);
	};

	void MakeTransfers(void)
	{
		XCALL(0x0062E800);
	};

	void GenerateLightmapsRadiosity( zTBBox3D*)
	{
		XCALL(0x0062F150);
	};

	void GenerateLightmaps(zCWorld::zTStaticWorldLightMode const&, zTBBox3D*)
	{
		XCALL(0x0062F3A0);
	};

	void GenerateStaticWorldLighting(zCWorld::zTStaticWorldLightMode const&, zTBBox3D*)
	{
		XCALL(0x0062FB70);
	};

	void MakeVobLightingDirty(void)
	{
		XCALL(0x0062FE60);
	};

	static int GetWaveAnisEnabled(void)
	{
		XCALL(0x006371D0);
	};

	static void SetWaveAnisEnabled(int)
	{
		XCALL(0x006371E0);
	};

	static int GetShowTextureStats(void)
	{
		XCALL(0x006371F0);
	};

	static void SetShowTextureStats(int)
	{
		XCALL(0x00637200);
	};

	void SetVobFarClipZScalability(float)
	{
		XCALL(0x00637210);
	};

	zCBspTree* GetBspTree(void)
	{
		XCALL(0x006D0020);
	};
	void				CollectVobsInBBox3D		(zCArray<zCVob*>& resVobList, const zTBBox3D& inbbox3D) { bspTree.GetRoot()->CollectVobsInBBox3D(resVobList,inbbox3D); };
};

class zCVobLevelCompo : public zCVob	
{
public:
	zCLASS(zCVobLevelCompo)
	static zCClassDef *classDef;
	static BOOL unarcIgnoreVisuals;
	void zVobLevelCompo(void)
	{
		XCALL(0x00605280);
	};

	zCVobLevelCompo(void)
	{
		zVobLevelCompo();
	};

	int HasIdentityTrafo(void)const 
	{
		XCALL(0x006052E0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005FDC30);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00605360);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00605410);
	};

	virtual ~zCVobLevelCompo()
	{
		XCALL(0x005FDC70);
	};

	virtual void SetVisual(zSTRING const&)
	{
		XCALL(0x00605520);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x006054E0);
	};
	
};