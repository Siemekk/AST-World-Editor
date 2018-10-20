#pragma once

#include "ztypes.h"
#include "zcvisual.h"


class zCModelAniEvent;
class zCModelNodeInst;
class zCMeshSoftSkin;
class zCModel;
class zCModelPrototype;
class zCViewBase;
class zCProgMeshProto;
class zCModelNode;
class zCModelPrototype;
class zCBuffer;
class zCModelAni;
class zCSoundFX;
class zCParticleEmitter;

struct zTAniAttachment;

enum zTMdl_AniDir
{
	zMDL_ANIDIR_FORWARD,
	zMDL_ANIDIR_REVERSE,
	zMDL_ANIDIR_ENDFASTEST
};	

enum zTMdl_AniEventType
{
	zMDL_EVENT_TAG,
	zMDL_EVENT_SOUND,				
	zMDL_EVENT_SOUND_GRND,			
	zMDL_EVENT_ANIBATCH,
	zMDL_EVENT_SWAPMESH,			
	zMDL_EVENT_HEADING,				
	zMDL_EVENT_PFX,
	zMDL_EVENT_PFX_GRND,
	zMDL_EVENT_PFX_STOP,
	zMDL_EVENT_SETMESH,
	zMDL_EVENT_MM_STARTANI,
	zMDL_EVENT_CAM_TREMOR,			
};

class zCModelAniEvent
{
public:
	zTMdl_AniEventType	aniEventType;

	enum
	{
		zMDL_ANIEVENT_MAXSTRING = 4
	};

	int							frameNr;
	zSTRING						tagString;
	zSTRING						string[zMDL_ANIEVENT_MAXSTRING];
	float						value1;
	float						value2;
	float						value3;
	float						value4;

	zCArray<zCSoundFX*>			soundList;			
	zCArray<zCParticleEmitter*>	pfxEmitterList;		

	zCModelAniEvent(void)
	{
		XCALL(0x00588280);
	};

	~zCModelAniEvent(void)
	{
		XCALL(0x00588320);
	};

	void Save(zCFileBIN&)const 
	{
		XCALL(0x00588400);
	};

	void Load(zCFileBIN&)
	{
		XCALL(0x00588560);
	};
};

enum zTModelProtoImportMAXFlags
{
	zMDL_MAX_IMPORT_ANI			= 1,	
	zMDL_MAX_IMPORT_MESH		= 2,	
	zMDL_MAX_IMPORT_TREE		= 4,	
	zMDL_MAX_IMPORT_PASS_ZCMESH	= 8,	
	zMDL_MAX_IMPORT_NO_LOD		= 16,	
};

class zCModelPrototype
{
public:
	struct zTMatIDList
	{
		zCPolygon	*poly;
		int			matID;
	};
	enum zTFileSourceType
	{
		zFROM_MDS,
		zFROM_ASC
	};

	zCModelPrototype			*next;
	zCModelPrototype			*prev;
	int							refCtr;

	
	zSTRING						modelProtoName;				
	zSTRING						modelProtoFileName;			
	zCTree<zCModelNode>			meshTree;					
	zCArraySort<zCModelAni*>	protoAnis;
	zCArray<zCModelAniEvent*>	modelEvents;
	zCArray<zCModelNode*>		nodeList;					
	DWORD						nodeListChecksum;			

	zCArray<zCMeshSoftSkin*>	meshSoftSkinList;
	zSTRING						hierarchySourceASC;

	zTBBox3D					bbox3D;						
	zTBBox3D					bbox3DCollDet;				
	zCModelPrototype			*baseModelProto;			
	zPOINT3						rootNodeTrans;				
	zTFileSourceType			fileSourceType;

	zCArray<zCMesh*>			sourceMeshSoftSkinList;		

	zCModelPrototype(void)
	{
		XCALL(0x00588610);
	};

	void Init(void)
	{
		XCALL(0x00588850);
	};

	~zCModelPrototype(void)
	{
		XCALL(0x00588A10);
	};

	void Clear(void)
	{
		XCALL(0x00588C50);
	};

	void ReleaseMeshSoftSkinList(void)
	{
		XCALL(0x00588DF0);
	};

	void ReleaseMeshes(void)
	{
		XCALL(0x00588E50);
	};

	int Release(void)
	{
		XCALL(0x00588EE0);
	};

	static int NumInList(void)
	{
		XCALL(0x00588F10);
	};

	zSTRING const& GetModelProtoFileName(void)const 
	{
		XCALL(0x00588F30);
	};

	void SetModelProtoName(zSTRING const&)
	{
		XCALL(0x00588F40);
	};

	void SetFileSourceType(zCModelPrototype::zTFileSourceType)
	{
		XCALL(0x005890D0);
	};

	static zCModelPrototype* Load(zSTRING const&,zCModelPrototype*)
	{
		XCALL(0x00589250);
	};

	int PrepareAsModelProtoOverlay(zCModelPrototype*)
	{
		XCALL(0x005894A0);
	};

	void CalcNodeListChecksum(void)
	{
		XCALL(0x00589870);
	};

	void CollectNodeMeshes(zCArray<zCModelNode*>&)
	{
		XCALL(0x005898D0);
	};

	static zCModelPrototype* SearchName(zSTRING)
	{
		XCALL(0x00589A30);
	};

	zCModelNode* SearchNode(zSTRING const&)
	{
		XCALL(0x00589AF0);
	};

	zCTree<zCModelNode>* FindMeshTreeNode(zSTRING const&,zCTree<zCModelNode>*)
	{
		XCALL(0x00589BA0);
	};

	int FindMeshTreeNodeIndex(zSTRING const&,zCTree<zCModelNode>*)
	{
		XCALL(0x00589C50);
	};

	int FindNodeListIndex(zSTRING const&)
	{
		XCALL(0x00589D10);
	};

	void AddAni(zCModelAni*)
	{
		XCALL(0x00589DB0);
	};

	int __fastcall SearchAniIndex(zSTRING const&)const 
	{
		XCALL(0x00589FC0);
	};

	zCModelAni* SearchAni(zSTRING const&)const 
	{
		XCALL(0x0058A090);
	};

	void DescribeTree(zCTree<zCModelNode>*,int)
	{
		XCALL(0x0058A0B0);
	};

	static unsigned long GetMDHFileVersion(void)
	{
		XCALL(0x0058A2F0);
	};

	int LoadMDH(zSTRING const&)
	{
		XCALL(0x0058A300);
	};

	int LoadMDH(zCFileBIN&)
	{
		XCALL(0x0058A560);
	};

	void SaveMDH(void)
	{
		XCALL(0x0058ABC0);
	};

	void SaveMDH(zCFileBIN&)
	{
		XCALL(0x0058ADC0);
	};

	void ConvertVec3(zVEC3&)
	{
		XCALL(0x0058B2E0);
	};

	void ConvertAngle(float&)
	{
		XCALL(0x0058B300);
	};

	void SkipBlock(void)
	{
		XCALL(0x0058B310);
	};

	void SkipBlockCmt(void)
	{
		XCALL(0x0058B390);
	};

	void ReadComment(void)
	{
		XCALL(0x0058B460);
	};

	void ReadScene(float&)
	{
		XCALL(0x0058B470);
	};

	zVEC3 ReadTriple(void)
	{
		XCALL(0x0058B810);
	};

	zMAT4 ReadNodeTM(zCModelNode*)
	{
		XCALL(0x0058BA00);
	};

	void ReadVertexList(zCMesh*,int)
	{
		XCALL(0x0058BEA0);
	};

	zTMatIDList* ReadFaceList(zCMesh*, int)
	{
		XCALL(0x0058C0D0);
	};

	zVEC2* ReadTVertexList(int)
	{
		XCALL(0x0058C5D0);
	};

	void ReadTFaceList(zCMesh*,zVEC2*,int)
	{
		XCALL(0x0058C7D0);
	};

	void ReadSoftSkinVertList(void)
	{
		XCALL(0x0058CA40);
	};

	
	
	
	

	zCMesh* ReadMesh(int,zCModelNode*,int)
	{
		XCALL(0x0058DC00);
	};

	void ReadMeshAnimation(zCModelNode*,int)
	{
		XCALL(0x0058DFE0);
	};

	void ReadPosTrack(zMAT4*)
	{
		XCALL(0x0058E160);
	};

	void ReadRotTrack(zMAT4*)
	{
		XCALL(0x0058E340);
	};

	void ReadTMAnimation(zCModelNode*,zMAT4*&)
	{
		XCALL(0x0058E5F0);
	};

	void LocalizeTrafos(zCTree<zCModelNode>*,zCTree<zCModelNode>*)
	{
		XCALL(0x0058EC30);
	};

	void ReadMapDiffuse(zCMaterial*)
	{
		XCALL(0x0058ED60);
	};

	zCMaterial* ReadMaterial(void)
	{
		XCALL(0x0058F1D0);
	};

	zCMaterial* ReadWireframeColor(void)
	{
		XCALL(0x0058F840);
	};

	void AssignMeshNodeMaterials(zCMesh*, zCModelPrototype::zTMatIDList*,int)
	{
		XCALL(0x0058FAE0);
	};

	void TransformNodeVisual(zCModelNode*,zMAT4 const&)
	{
		XCALL(0x0058FBD0);
	};

	void ProcessMeshNode(zCModelNode*,zCTree<zCModelNode>*,int,int,int&)
	{
		XCALL(0x0058FC30);
	};

	void ReadGeomobject(zMAT4*&,zCTree<zCModelNode>*&)
	{
		XCALL(0x00590040);
	};

	void ReadMaterialList(void)
	{
		XCALL(0x005915C0);
	};

	void Load3DSMAXAsc(zCModelAni*&,zSTRING const&,zSTRING const&,int,int,int,float)
	{
		XCALL(0x00591850);
	};

	void CalcAniBBox(zCModelAni*)
	{
		XCALL(0x005928D0);
	};

	void ResolveReferences(void)
	{
		XCALL(0x00592E00);
	};

	static unsigned long GetMDSFileVersion(void)
	{
		XCALL(0x005930F0);
	};

	void SkipBlockMDS(int)
	{
		XCALL(0x00593100);
	};

	int ReadMeshAndTreeMSB(int&,zCFileBIN&)
	{
		XCALL(0x00593180);
	};

	void ReadMeshAndTree(int&,zCFileBIN&)
	{
		XCALL(0x005935C0);
	};

	void RegisterMesh(zCFileBIN&)
	{
		XCALL(0x00593C40);
	};

	int ReadAniEnumMSB(int,zCFileBIN&)
	{
		XCALL(0x00593ED0);
	};

	void ReadAniEnum(int,zCFileBIN&)
	{
		XCALL(0x00596C00);
	};

	int ReadModelMSB(zCFileBIN&)
	{
		XCALL(0x0059D250);
	};

	void ReadModel(zCFileBIN&)
	{
		XCALL(0x0059D4C0);
	};

	int LoadModelScriptMSB(zSTRING const&)
	{
		XCALL(0x0059D7B0);
	};

	int LoadModelScript(zSTRING const&)
	{
		XCALL(0x0059DDD0);
	};

	int LoadModelASC(zSTRING const&)
	{
		XCALL(0x0059E760);
	};
};

class zCModelMeshLib : public zCObject
{
public:
	zCLASS(zCModelMeshLib)
		friend class zCModelTexAniState;
	friend class zCModel;
public:
	typedef struct
	{			
		zCVisual				*visual;			
		int						nodeIndex;			
	} zTNodeMesh;

	zCArray<zTNodeMesh>			meshNodeList;
	zCArray<zCMeshSoftSkin*>	meshSoftSkinList;
	static zCClassDef *classDef;

	void zModelMeshLib(void)
	{
		XCALL(0x00593B30);
	};

	zCModelMeshLib(void)
	{
		zModelMeshLib();
	};

	void ReleaseData(void)
	{
		XCALL(0x0059F090);
	};

	void AllocNumNodeVisuals(int)
	{
		XCALL(0x0059F100);
	};

	void AddMeshSoftSkin(zCMeshSoftSkin*)
	{
		XCALL(0x0059F170);
	};

	void AddNodeVisual(int,zCVisual*)
	{
		XCALL(0x0059F250);
	};

	void ApplyToModel(zCModel*)
	{
		XCALL(0x0059F350);
	};

	void ApplyToModel(zCModelPrototype*)
	{
		XCALL(0x0059F4C0);
	};

	void RemoveFromModel(zCModel*)
	{
		XCALL(0x0059F620);
	};

	void BuildFromModel(zCModelPrototype*)
	{
		XCALL(0x0059F710);
	};

	void BuildFromModel(zCModel*)
	{
		XCALL(0x0059F900);
	};

	static unsigned long GetMDMFileVersion(void)
	{
		XCALL(0x0059FB00);
	};

	void SaveMDM(zCModelPrototype*)
	{
		XCALL(0x0059FB30);
	};

	void SaveMDM(zCFileBIN&,zCModelPrototype*)
	{
		XCALL(0x0059FD40);
	};

	static int LoadMDM(zSTRING const&,zCModelPrototype*,zCModel*,zCModelMeshLib**)
	{
		XCALL(0x005A01D0);
	};

	static int LoadMDM_Try(zSTRING const&,zCModelPrototype*,zCModel*,zCModelMeshLib**)
	{
		XCALL(0x005A05A0);
	};

	static int LoadMDM(zCFileBIN&,zCModelPrototype*,zCModel*,zCModelMeshLib**)
	{
		XCALL(0x005A07A0);
	};

	static int ConvertMDM(zSTRING const&,zCModelPrototype*)
	{
		XCALL(0x005A12E0);
	};

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x0057EA30)};
	virtual ~zCModelMeshLib			()			{XCALL(0x0057EA40)};
};

enum zTNodeType
{
	zTNODE_USUAL,	
	zTNODE_MASTER,	
	zTNODE_FADE		
};

enum zTMdl_AniType
{
	zMDL_ANI_TYPE_NORMAL, 
	zMDL_ANI_TYPE_BLEND, 
	zMDL_ANI_TYPE_SYNC, 
	zMDL_ANI_TYPE_ALIAS, 
	zMDL_ANI_TYPE_BATCH,
	zMDL_ANI_TYPE_COMB,
	zMDL_ANI_TYPE_DISABLED
};

class zCModelTexAniState
{
public:
	friend class zCModel;
	
	enum
	{
		zMDL_MAX_ANI_CHANNELS = 2,
		zMDL_MAX_TEX = 4
	};
	int					numNodeTex;
	zCTexture			**nodeTexList;
	int					actAniFrames[zMDL_MAX_ANI_CHANNELS][zMDL_MAX_TEX];
public:
	void zModelTexAniState(void)
	{
		XCALL(0x00576D40);
	};

	zCModelTexAniState(void)
	{
		zModelTexAniState();
	};

	~zCModelTexAniState(void)
	{
		XCALL(0x00576D60);
	};

	void DeleteTexList(void)
	{
		XCALL(0x00576D80);
	};

	void UpdateTexList(void)
	{
		XCALL(0x00576DA0);
	};

	void SetChannelVariation(int,int,zSTRING*)
	{
		XCALL(0x00576DE0);
	};

	void BuildTexListFromMeshLib(zCModelMeshLib*)
	{
		XCALL(0x00576E50);
	};

	void BuildTexListFromMesh(zCMesh*)
	{
		XCALL(0x00576ED0);
	};

	void BuildTexListFromProgMesh(zCProgMeshProto*)
	{
		XCALL(0x00577060);
	};

	void AddTexListFromMeshLib(zCModelMeshLib*,zCArray<zCTexture*>&)
	{
		XCALL(0x005771D0);
	};

	void AddTexListFromMesh(zCMesh*,zCArray<zCTexture*>&)
	{
		XCALL(0x00577430);
	};

	void AddTexListFromProgMesh(zCProgMeshProto*,zCArray<zCTexture*>&)
	{
		XCALL(0x00577590);
	};

	void FinishTexList(zCArray<zCTexture*>&)
	{
		XCALL(0x005776E0);
	};
};

struct zTCacheEntry	
{
	int				m_nX1;		
	int				m_nY1;		
	int				m_nX2;		
	int				m_nY2;		
	zCOLOR			m_Color;	
};

class zCLineCache	
{
	int				m_nSize;	
	int				m_nIndex;
	zTCacheEntry*	m_pEntry;
public:
	~zCLineCache(void)
	{
		XCALL(0x0050B310);
	};

	void Line(int,int,int,int, zCOLOR)
	{
		XCALL(0x0050B320);
	};

	void Flush(zCViewBase*)
	{
		XCALL(0x0050B3B0);
	};

	void Line3D(zVEC3 const&,zVEC3 const&, zCOLOR,int)
	{
		XCALL(0x0050B450);
	};

	void LineCS3D(zVEC3 const&,zVEC3 const&, zCOLOR)
	{
		XCALL(0x0050B850);
	};

	static zCLineCache* GetLine()
	{
		return *(zCLineCache**)0x008D42F8;
	};
};

inline void zCPolygon::DrawPolygon()
{
	for(int i = 0; i < polyNumVert; i ++)
	{
		zVEC3 vtx1 = vertex[i]->position;
		int next = i + 1 >= polyNumVert ? 0 : i + 1;
		zVEC3 vtx2 = vertex[next]->position;
		zCLineCache::GetLine()->Line3D(vtx1,vtx2,zCOLOR(255,255,255),0);
	}
};

#pragma pack (push, 1)
typedef struct zTMdl_AniSample
{
	WORD	rotation[3];		
	WORD	position[3];		
public:
	static void CalcSamplePosConstants(float,float)
	{
		XCALL(0x00584DD0);
	};

	static void SetSamplePosConstants(float,float)
	{
		XCALL(0x00584DF0);
	};

	void __fastcall Pack(zCQuat const&,zVEC3 const&)
	{
		XCALL(0x00584E10);
	};

	void __fastcall Unpack(zCQuat&,zVEC3&)const 
	{
		XCALL(0x00584ED0);
	};

	void __fastcall PackTrans(zVEC3 const&)
	{
		XCALL(0x00584F40);
	};

	void __fastcall UnpackTrans(zVEC3&)const 
	{
		XCALL(0x00584F90);
	};

	void __fastcall PackQuat(zCQuat const&)
	{
		XCALL(0x00584FF0);
	};

	void __fastcall UnpackQuat(zCQuat&)const 
	{
		XCALL(0x00585070);
	};
} zTMdl_AniSample;
#pragma pack (pop)

class zCModelAni : public zCObject
{
public:
	zCLASS(zCModelAni)
public:
	enum {	zMAN_VERS = (00*256 + 12 )	};
public:
	enum
	{
		zMDL_ANI_FLAG_VOB_ROT	= 1, 
		zMDL_ANI_FLAG_VOB_POS	= 2,
		zMDL_ANI_FLAG_END_SYNC	= 4,
		zMDL_ANI_FLAG_FLY		= 8,
		zMDL_ANI_FLAG_IDLE		= 16
	};
	zSTRING				aniName;		
	zSTRING				ascName;
	zTModelAniID		aniID;

	zSTRING				aliasName;
	zCList<zCModelAni>	combAniList;

	int					layer;
	float				blendInSpeed;				
	float				blendOutSpeed;
	zTBBox3D			aniBBox3DObjSpace;
	float				collisionVolumeScale;

	zCModelAni			*nextAni;
	zSTRING				nextAniName;
	zCModelAniEvent		*aniEvents;

	float				fpsRate;
	float				fpsRateSource;
	int					rootNodeIndex;

	zCArray<int>		nodeIndexList;	
	zCModelNode			**nodeList;
	zTMdl_AniSample		*aniSampleMatrix;
	float				samplePosRangeMin;
	float				samplePosScaler;

	struct
	{
		int				numFrames		: 16;
		int				numNodes		: 16;
		zTMdl_AniType	aniType			: 6;
		zTMdl_AniDir	aniDir			: 2;
		int				numAniEvents	: 6;
	};
	struct
	{
		UINT8			flagVobRot		: 1;
		UINT8			flagVobPos		: 1;
		UINT8			flagEndSync		: 1;
		UINT8			flagFly			: 1;
		UINT8			flagIdle		: 1;			
		UINT8			flagInPlace		: 1;			
		UINT8			flagStaticCycle	: 1;			
	} aniFlags;

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x005852C0)};
	virtual ~zCModelAni				()			{XCALL(0x005852D0)};
	void zModelAni(void)
	{
		XCALL(0x00585120);
	};

	zCModelAni(void)
	{
		zModelAni();
	};

	void PrecacheAniEventData(void)
	{
		XCALL(0x00585530);
	};

	float GetAniVelocity(void)const 
	{
		XCALL(0x00585600);
	};

	zVEC3 GetAniTranslation(void)const 
	{
		XCALL(0x00585780);
	};

	void AddTrafoMatrix(zMAT4**)
	{
		XCALL(0x005858C0);
	};

	zCQuat GetQuat(int,int)const 
	{
		XCALL(0x00585D60);
	};

	zVEC3 GetTrans(int,int)const 
	{
		XCALL(0x00585DC0);
	};

	void SetTrans(int,int,zVEC3 const&)
	{
		XCALL(0x00585E60);
	};

	void SetQuat(int,int,zCQuat const&)
	{
		XCALL(0x00585EE0);
	};

	void AddNodeList(zCTree<zCModelNode>**)
	{
		XCALL(0x00585F80);
	};

	void SetFlags(zSTRING const&)
	{
		XCALL(0x00585FF0);
	};

	void SetBlendingSec(float,float)
	{
		XCALL(0x005860A0);
	};

	void GetBlendingSec(float&,float&)const 
	{
		XCALL(0x00586100);
	};

	void CorrectRootNodeIdleMovement(void)
	{
		XCALL(0x00586160);
	};

	void CalcInPlaceFlag(void)
	{
		XCALL(0x005862C0);
	};

	int ResolveAlias(zCModelPrototype*)
	{
		XCALL(0x005864A0);
	};

	int ResolveComb(zCModelPrototype*)
	{
		XCALL(0x00586780);
	};

	void SaveMAN(zCModelPrototype*,zSTRING const&)
	{
		XCALL(0x00586E80);
	};

	int LoadMAN(zSTRING const&,zCModelPrototype*,zSTRING const&)
	{
		XCALL(0x00587740);
	};

	zSTRING const& GetAniName(void)const 
	{
		XCALL(0x0059D160);
	};

	zTMdl_AniType GetAniType(void)const 
	{
		XCALL(0x0059D170);
	};

	int GetAniID(void)const 
	{
		XCALL(0x006A9800);
	};
};

enum { zMDL_MAX_ANIS_PARALLEL		= 6 };
enum { zMDL_MAX_MESHLIBS_PARALLEL	= 4 };

class zCModelAniActive
{
public:
	zCModelAni			*protoAni;
	zCModelAni			*nextAni;
	int					advanceDir;			
	float				actFrame;			
	int					actAniEvent;		
	float				combAniX, combAniY;
	BOOL				isFadingOut;
	BOOL				isFirstTime;
	zCModelAni			*nextAniOverride;	
	float				blendInOverride;
	float				blendOutOverride;
	
	zPOINT3				lastPos;			
	zPOINT3				thisPos;
	zCQuat				lastRotQuat;		
	zCQuat				thisRotQuat;
	zCQuat				freezeRotQuat;		
	BOOL				rotFirstTime;
	float				transWeight;		
	
	zTAniAttachment		*aniAttachment;
	float				randAniTimer;
	void				SetNextAni			(zCModelAni* modelAni)		{ nextAni = modelAni;					};
	zCModelAniActive(void)
	{
		XCALL(0x00576B00);
	};

	~zCModelAniActive(void)
	{
		XCALL(0x00576BF0);
	};

	void SetDirection(zTMdl_AniDir)
	{
		XCALL(0x00576C10);
	};

	float GetProgressPercent(void)const 
	{
		XCALL(0x00576C60);
	};

	void SetProgressPercent(float)
	{
		XCALL(0x00576CA0);
	};

	void SetActFrame(float)
	{
		XCALL(0x00576CF0);
	};

	void DoCombineAni(zCModel*,int,int)
	{
		XCALL(0x0057FDB0);
	};
};

class zCModelNode
{
public:
	zCModelNode			*parentNode;
	zSTRING				nodeName;
	zCVisual			*visual;
	zMAT4				trafo;
	zVEC3				nodeRotAxis;		
	float				nodeRotAngle;		
	zPOINT3				translation;		
	zMAT4				trafoObjToWorld;	
	zMAT4				*nodeTrafoList;		
	zCModelNodeInst		*lastInstNode;

	zCModelNode(void)
	{
		XCALL(0x005849C0);
	};

	zCModelNode(zCModelNode const&)
	{
		XCALL(0x00584B00);
	};

	~zCModelNode(void)
	{
		XCALL(0x00584C90);
	};

	void SetNodeVisualS(zCVisual*)
	{
		XCALL(0x00584D30);
	};
};

#pragma pack (push, 1)
class zCModelNodeInst
{
public:
	zCModelNodeInst		*parentNode;
	zCModelNode			*protoNode;
	zCVisual			*nodeVisual;
	zMAT4				trafo;
	zMAT4				trafoObjToCam;
	zCModelTexAniState	texAniState;
	
	enum
	{ 
		zMDL_BLEND_STATE_FADEIN,
		zMDL_BLEND_STATE_CONST,
		zMDL_BLEND_STATE_FADEOUT
	};
	struct zTNodeAni
	{
		zCModelAniActive*modelAni;									
		float			weight;										
		float			weightSpeed;								
		int				blendState;									
		zCQuat			quat;										
	};
	zTNodeAni			nodeAniList [zMDL_MAX_ANIS_PARALLEL];		
	int					numNodeAnis;								
	int					masterAni;									
	float				masterAniSpeed;								

	zCModelNodeInst(void)
	{
		XCALL(0x00577870);
	};

	zCModelNodeInst(zCModelNode*)
	{
		XCALL(0x00577940);
	};

	~zCModelNodeInst(void)
	{
		XCALL(0x00577A30);
	};

	void Init(void)
	{
		XCALL(0x00577AB0);
	};

	void InitByModelProtoNode(zCModelNode*)
	{
		XCALL(0x00577B40);
	};

	void SetNodeVisualS(zCVisual*,int)
	{
		XCALL(0x00577BF0);
	};

	void AddNodeAni(zCModelAniActive*)
	{
		XCALL(0x0057EAF0);
	};

	void RemoveAllNodeAnis(void)
	{
		XCALL(0x0057ED20);
	};

	void RemoveNodeAni(zCModelAniActive*)
	{
		XCALL(0x0057ED30);
	};

	void FindMasterAni(void)
	{
		XCALL(0x0057EE20);
	};

	void FadeOutNodeAni(zCModelAniActive*)
	{
		XCALL(0x0057EE90);
	};

	void CalcWeights(zCModel*)
	{
		XCALL(0x0057F470);
	};

	void AddToNodeAniWeight(int,float)
	{
		XCALL(0x0057F6B0);
	};

	void CalcBlending(zCModel*)
	{
		XCALL(0x0057F720);
	};

	int GetNodeAniListIndex(zCModelAniActive const*)const 
	{
		XCALL(0x0057F8B0);
	};
};
#pragma pack (pop)

struct zTRandAni
{
	zTModelAniID			randAniProtoID;
	int						prob;
};

struct zTAniAttachment
{
	
	zTModelAniID			aniID;

	
	zCArray<zTRandAni>		randAniList;
	float					randAniFreq;
	int						randAniProbSum;
};

class zCModel : public zCVisualAnimate
{
public:
	zCLASS(zCModel)
public:
	
	typedef struct
	{
		zCVob				*vob;
		zCModelNodeInst		*mnode;
	} zTMdl_NodeVobAttachment;		

	typedef struct
	{				
		zCVob				*vob;
		float				vobFXHandle;
	} zTMdl_StartedVobFX;			

	typedef struct
	{				
		zCModelAniActive	*ani;
		zCModelMeshLib		*meshLib;
	} zTAniMeshLibEntry;			

	
	typedef struct
	{				
		zCModelTexAniState	texAniState;
		zCModelMeshLib		*meshLib;
	} zTMeshLibEntry;

	int								numActiveAnis;								
	zCModelAniActive				*aniChannels	[zMDL_MAX_ANIS_PARALLEL];	
	zCModelAniActive				*activeAniList;	
	zCArray<zTSoundHandle>			m_listOfVoiceHandles;
	zCVob							*homeVob;
	zCArray<zCModelPrototype*>		modelProtoList;
	zCArray<zCModelNodeInst*>		nodeList;								
	zCArray<zCMeshSoftSkin*>		meshSoftSkinList;
	zCArraySort<zTAniAttachment*>	aniAttachList;
	zCArray<zTMdl_NodeVobAttachment>attachedVobList;
	zCArray<zTMdl_StartedVobFX>		startedVobFX;
	zCArray<zTAniMeshLibEntry>		aniMeshLibList;
	zCArray<zTMeshLibEntry*>		meshLibList;
	zTFrameCtr						lastTimeBBox3DTreeUpdate;
	zCArray<zCModelAniEvent*>		occuredAniEvents;			
	zTBBox3D						bbox3D;									
	zTBBox3D						bbox3DLocalFixed;						
	zTBBox3D						bbox3DCollDet;							
	float							modelDistanceToCam;
	BOOL							n_bIsInMobInteraction;				
	
	float							fatness;
	zVEC3							modelScale;
	
	zVEC3							aniTransScale;
	zPOINT3							rootPosLocal;
	zPOINT3							vobTrans;
	zPOINT3							vobTransRing;
	BOOL							newAniStarted;
	BOOL							m_bSmoothRootNode;
	float							relaxWeight;
	
	BOOL							m_bDrawHandVisualsOnly;
	zCQuat							vobRot;
	zVEC3							modelVelocity;
	enum
	{
		zMDL_VELRING_SIZE = 8
	};
	int								actVelRingPos;
	zVEC3							modelVelRing[zMDL_VELRING_SIZE];
	enum				{ zMDL_STARTANI_DEFAULT, zMDL_STARTANI_ISNEXTANI, zMDL_STARTANI_FORCE };
	struct
	{						
		UINT8						isVisible				: 1;
		UINT8						isFlying				: 1;
		UINT8						randAnisEnabled			: 1;
		UINT8						lerpSamples				: 1;
		UINT8						modelScaleOn			: 1;
		UINT8						doVobRot				: 1;
		UINT8						nodeShadowEnabled		: 1;
		UINT8						dynLightMode			: 1;
	};
	float							timeScale;		
	enum
	{ 
		MAX_ANIHISTORY = 16
	};
	zCModelAni			**aniHistoryList;
	static zCClassDef*	classDef;
	static int s_bSmoothRootNode;
	
	static int s_drawSkeleton;
public:

	virtual zCClassDef* _GetClassDef(void)const {XCALL(0x005765B0)};

	virtual ~zCModel				()			{XCALL(0x00576720)};

	
	BOOL				Render					(zTRenderContext& renderContext)	{XCALL(0x0057A4E0)};
	BOOL				IsBBox3DLocal			() { return TRUE; };				
	zTBBox3D			GetBBox3D				()									{XCALL(0x0057DF20)};
	zSTRING				GetVisualName			()									{XCALL(0x0057DF60)};
	void				SetVisualUsedBy			(zCVob* vob)						{XCALL(0x005786C0)};
	DWORD				GetRenderSortKey		() const							{XCALL(0x005827E0)};
	
	BOOL				CanTraceRay				() const		{ return TRUE; };	
	BOOL				TraceRay				(	const zVEC3&		rayOrigin, 
		const zVEC3&		ray, 
		const int			traceFlags, 
		zTTraceRayReport	&report)	{XCALL(0x00582800)};
	void				HostVobRemovedFromWorld	(zCVob* hostVob, zCWorld* hostWorld){XCALL(0x0057B7E0)};

	
	void				StartAnimation			(const zSTRING& aniName)	{ StartAni (aniName, zMDL_STARTANI_DEFAULT);};
	void				StopAnimation			(const zSTRING& aniName)	{ StopAni	(GetAniIDFromAniName(aniName));	};
	BOOL				IsAnimationActive		(const zSTRING& aniName)	{ return IsAniActive (aniName);				};
	const zSTRING*		GetAnyAnimation			();
	
	const zSTRING*		GetFileExtension		(int i)								{XCALL(0x00578740)};
	zCVisual*			LoadVisualVirtual		(const zSTRING& visualName) const	{XCALL(0x00578760)};



	int GetAniIDFromAniName(zSTRING const&)const 
	{
		XCALL(0x00612070);
	};

	zCModelAni* GetAniFromAniID(int)const 
	{
		XCALL(0x00472F50);
	};

	int IsAniActive(zCModelAni*ani)
	{
		XCALL(0x00472F90);
	};
	inline BOOL IsAniActive (zTModelAniID aniID)
	{
		return IsAniActive (GetAniFromAniID (aniID));
	};
	inline zCModelAni* GetAniFromAniName (const zSTRING& aniName) const
	{
		return GetAniFromAniID (GetAniIDFromAniName(aniName));
	};
	inline zCModelAni* GetNextAni (zCModelAni* modelAni) const
	{
		
		if (!modelAni->nextAni)	
		{
			
			if (modelAni->GetAniName().Length()<=0) return 0;

			
			
			
			
			
			const zTModelAniID aniID= modelAni->GetAniID();
			modelAni				= modelProtoList[0]->protoAnis[aniID];
			if (!modelAni->nextAni)	return 0;
		};

		return GetAniFromAniID (modelAni->nextAni->GetAniID());
	};
	inline BOOL IsAniActive (const zSTRING& aniName)
	{
		return IsAniActive (GetAniFromAniName(aniName));
	};


	void Init(void)
	{
		XCALL(0x00577FD0);
	};

	zCModel()
	{
		Init();
	};

	zCModel(zCModelPrototype*)
	{
		XCALL(0x00578240);
	};

	void CopyProtoNodeList(void)
	{
		XCALL(0x00578400);
	};

	int ApplyModelProtoOverlay(zSTRING const&)
	{
		XCALL(0x005787F0);
	};

	int ApplyModelProtoOverlay(zCModelPrototype*)
	{
		XCALL(0x00578840);
	};

	int HasAppliedModelProtoOverlay(zCModelPrototype*)const 
	{
		XCALL(0x00578A90);
	};

	int HasAppliedModelProtoOverlay(zSTRING const&)const 
	{
		XCALL(0x00578AC0);
	};

	void RemoveModelProtoOverlay(zSTRING const&)
	{
		XCALL(0x00578C40);
	};

	void RemoveModelProtoOverlay(zCModelPrototype*)
	{
		XCALL(0x00578E40);
	};

	void CalcNodeListBBoxWorld(void)
	{
		XCALL(0x00578FC0);
	};

	zTBBox3D GetBBox3DNodeWorld(zCModelNodeInst*)
	{
		XCALL(0x005790F0);
	};

	zVEC3 GetNodePositionWorld(zCModelNodeInst*)
	{
		XCALL(0x00579140);
	};

	void CalcModelBBox3DWorld(void)
	{
		XCALL(0x00579170);
	};

	void SetNodeVisual(zCModelNodeInst*,zCVisual*,int)
	{
		XCALL(0x005792A0);
	};

	void SetDynLightMode(int)
	{
		XCALL(0x005792D0);
	};

	void __fastcall SetupLowestLOD( zTRenderContext&)
	{
		XCALL(0x005792F0);
	};

	int GetLowestLODNumPolys(void)
	{
		XCALL(0x00579490);
	};

	zVEC3* GetLowestLODPoly(int,zVEC3*&)
	{
		XCALL(0x005794B0);
	};

	zCMaterial* GetMaterial(int)
	{
		XCALL(0x005794F0);
	};

	int GetNumMaterials(void)const 
	{
		XCALL(0x00579530);
	};

	void __fastcall RenderNodeList( zTRenderContext&,zCArray<zMAT4*>&,int&,int)
	{
		XCALL(0x00579560);
	};

	void CheckNodeCollisionList(zCOBBox3D const&,zMAT4&)
	{
		XCALL(0x0057A7D0);
	};

	void CheckNodeCollision(zCModel*,zCModelNodeInst*,zMAT4&,zCList<zCModelNodeInst>&)
	{
		XCALL(0x0057A870);
	};

	zMAT4 GetTrafoNodeToModel(zCModelNodeInst*)
	{
		XCALL(0x0057A9C0);
	};

	void SetRandAnisEnabled(int)
	{
		XCALL(0x0057AAF0);
	};

	zCModelAniActive* GetActiveAni(int)const 
	{
		XCALL(0x0057AB60);
	};

	zCModelAniActive* GetActiveAni(zCModelAni*)const 
	{
		XCALL(0x0057ABA0);
	};

	void StopAni(int)
	{
		XCALL(0x0057ABE0);
	};

	void StopAni(zCModelAni*)
	{
		XCALL(0x0057AC60);
	};

	void StopAni(zCModelAniActive*)
	{
		XCALL(0x0057ACB0);
	};

	zVEC3 GetAniTransLerp(zCModelAni*,float,int)const 
	{
		XCALL(0x0057AE70);
	};

	void StartAni(zSTRING const&,int)
	{
		XCALL(0x0057AF70);
	};

	void StartAni(zTModelAniID aniID, const int startMode = zMDL_STARTANI_DEFAULT) 
	{
		XCALL(0x0057B070);
	};

	void StartAni(zCModelAni*,int)
	{
		XCALL(0x0057B0C0);
	};

	void AssertActiveAniListAlloced(void)
	{
		XCALL(0x0057B770);
	};

	void DoAniEvents(zCModelAniActive*)
	{
		XCALL(0x0057B890);
	};

	void __fastcall AdvanceAni(zCModelAniActive*,int&)
	{
		XCALL(0x0057C7D0);
	};

	void AdvanceAnis(void)
	{
		XCALL(0x0057CA90);
	};

	void SetModelScale(zVEC3 const&)
	{
		XCALL(0x0057DC30);
	};

	int IsStateActive(zCModelAni const*)const 
	{
		XCALL(0x0057DDA0);
	};

	zCModelNodeInst* SearchNode(zSTRING const&)
	{
		XCALL(0x0057DFF0);
	};

	int SetNodeMeshTexture(zSTRING const&,int,int,zSTRING*)
	{
		XCALL(0x0057E0A0);
	};

	int SetMeshLibTexture(zSTRING const&,int,int,zSTRING*)
	{
		XCALL(0x0057E1D0);
	};

	void RemoveMeshLibAll(void)
	{
		XCALL(0x0057E3D0);
	};

	int RemoveMeshLib(zSTRING const&)
	{
		XCALL(0x0057E400);
	};

	int ApplyMeshLib(zSTRING const&)
	{
		XCALL(0x0057E610);
	};

	void UpdateMeshLibTexAniState(void)
	{
		XCALL(0x0057EA70);
	};

	void FadeOutAni(int)
	{
		XCALL(0x0057EF50);
	};

	void FadeOutAni(zCModelAni*)
	{
		XCALL(0x0057EFE0);
	};

	void FadeOutAni(zCModelAniActive*)
	{
		XCALL(0x0057F020);
	};

	void FadeOutAnisLayerRange(int,int)
	{
		XCALL(0x0057F1F0);
	};

	void StopAnisLayerRange(int,int)
	{
		XCALL(0x0057F240);
	};

	float GetProgressPercent(zSTRING const&)const 
	{
		XCALL(0x0057F290);
	};

	float GetProgressPercent(int)const 
	{
		XCALL(0x0057F340);
	};

	void SetCombineAniXY(int,float,float)const 
	{
		XCALL(0x0057F3B0);
	};

	int GetCombineAniXY(int,float&,float&)const 
	{
		XCALL(0x0057F400);
	};

	void CalcNodeListAniBlending(void)
	{
		XCALL(0x0057F880);
	};

	void CalcTransBlending(void)
	{
		XCALL(0x0057F8E0);
	};

	void AttachChildVobToNode(zCVob*,zCModelNodeInst*)
	{
		XCALL(0x005806A0);
	};

	void RemoveChildVobFromNode(zCVob*)
	{
		XCALL(0x005807F0);
	};

	zCVob* GetAttachedNodeVob(zCModelNodeInst*)
	{
		XCALL(0x00580870);
	};

	void RemoveAllChildVobsFromNode(void)
	{
		XCALL(0x005808B0);
	};

	void UpdateAttachedVobs(void)
	{
		XCALL(0x00580900);
	};

	void RemoveStartedVobFX(zCVob*)
	{
		XCALL(0x00580A50);
	};

	zVEC3 GetVelocityRing(void)const 
	{
		XCALL(0x00580B00);
	};

	void ResetVelocity(void)
	{
		XCALL(0x00580B60);
	};

	void GetAniMinMaxWeight(zCModelAniActive*,float&,float&)
	{
		XCALL(0x00580BF0);
	};

	void PrintStatus(int,int)
	{
		XCALL(0x00580E90);
	};

	int CorrectAniFreezer(void)
	{
		XCALL(0x005815E0);
	};

	void psb_WriteAniBlock(zCBuffer&,int,int)const 
	{
		XCALL(0x00581850);
	};

	void psb_ReadAniBlock(zCBuffer&,int,zCModelAniActive*)
	{
		XCALL(0x005819E0);
	};

	void PackStateBinary(zCBuffer&)
	{
		XCALL(0x00581C30);
	};

	void UnpackStateBinary(zCBuffer&)
	{
		XCALL(0x00581F80);
	};

	void ShowAniListAdd(zCModelAni*)
	{
		XCALL(0x00582700);
	};

	void ShowAniList(int)
	{
		XCALL(0x00582770);
	};

	static int AniAttachmentCompare(void const*,void const*)
	{
		XCALL(0x00583370);
	};

	zTAniAttachment* SearchAniAttachList(int)const 
	{
		XCALL(0x005833A0);
	};

	void RemoveAniAttachment(int)
	{
		XCALL(0x00583420);
	};

	void RemoveAllAniAttachments(void)
	{
		XCALL(0x00583570);
	};

	void RemoveAllVobFX(void)
	{
		XCALL(0x005835C0);
	};

	zTAniAttachment* GetCreateAniAttachment(int)
	{
		XCALL(0x00583650);
	};

	void DeleteRandAniList(int)
	{
		XCALL(0x005838A0);
	};

	void InsertRandAni(int,int,int)
	{
		XCALL(0x00583930);
	};

	float GetRandAniFreq(int)const 
	{
		XCALL(0x00583A30);
	};

	void SetRandAniFreq(int,float)
	{
		XCALL(0x00583AC0);
	};

	void __fastcall RecalcRootPosLocal(int)
	{
		XCALL(0x00583AE0);
	};

	zCModelNodeInst* SearchNodeA(zSTRING & node)
	{
		node.Upper();
		for(int i = 0; i < nodeList.GetNum(); i++)
			if(!nodeList[i]->protoNode->nodeName.Compare(node))
				return nodeList[i];
		return NULL;
	};
	// [AST]
	void DoAniEvents_AST(zCModel* _this,zCModelAniActive* pActive);
	// [/AST]
};







