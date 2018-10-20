#pragma once
#include "ztypes.h"
#include "zcrenderer.h"

class zCBspSector;





enum zTFFT
{
	zTFFT_NONE,
	zTFFT_SLOW,
	zTFFT_NORMAL,
	zTFFT_FAST
};

enum zTMat_Group
{	zMAT_GROUP_UNDEF	= 0	, 
	zMAT_GROUP_METAL		, 
	zMAT_GROUP_STONE		, 
	zMAT_GROUP_WOOD			, 
	zMAT_GROUP_EARTH		, 
	zMAT_GROUP_WATER		,
	zMAT_GROUP_SNOW			,
	zMAT_NUM_MAT_GROUP
}; 

enum zTWaveAniMode
{
	zWAVEANI_NONE = 0,
	zWAVEANI_GROUND_AMBIENT,
	zWAVEANI_GROUND,
	zWAVEANI_WALL_AMBIENT,
	zWAVEANI_WALL,
	zWAVEANI_ENV,
	zWAVEANI_WIND_AMBIENT,
	zWAVEANI_WIND
};


enum zTMat_AlphaFunc
{
	RND_ALPHA_FUNC_MAT_DEFAULT,
	RND_ALPHA_FUNC_NONE,           
	RND_ALPHA_FUNC_BLEND,          
	RND_ALPHA_FUNC_ADD,                    
	RND_ALPHA_FUNC_SUB,                    
	RND_ALPHA_FUNC_MUL,                    
	RND_ALPHA_FUNC_MUL2,                   
	RND_ALPHA_FUNC_TEST,           
	RND_ALPHA_FUNC_BLEND_TEST      
};

enum zTMat_MapMode
{
	zTMap_NONE,			
	zTMap_LINEAR			
};

class zCTexAniCtrl		
{
public:
	int			m_nTexAnimatedChannel;	
	float		m_fCurrentFrame;		
	float		m_fTexAniFPS;			
	ULONG		m_nFrameCtr;			
	BOOL		m_bNoLoopTexAni;		
	static unsigned long zCTexAniCtrl::masterFrameCtr;
	zCTexAniCtrl(void)
	{
		XCALL(0x00565D30);
	};

	void AdvanceAni(zCTexture*)
	{
		XCALL(0x00565D50);
	};
};

class zCMaterial : public zCObject
{
public:
	zCLASS(zCMaterial)
	zCArray<zCPolygon*>		polyList;
	DWORD					polyListTimeStamp;	
						
	zCTexture				*texture;
	zCOLOR					color;								
	float					smoothAngle;
	zTMat_Group				matGroup;
	zCBspSector				*bspSectorFront;					
	zCBspSector				*bspSectorBack;						
	zCTexAniCtrl			texAniCtrl; 
	zSTRING					*detailObjectVisualName;
	
	float					kambient;
	float					kdiffuse;
	float					m_bEnvironmentalMappingStrength;

	struct
	{
		UINT8				smooth					: 1;
		UINT8				dontUseLightmaps		: 1;
		UINT8				texAniMap				: 1;
		UINT8				lodDontCollapse			: 1;
		UINT8				noCollDet				: 1;
		UINT8				forceOccluder			: 1;
		UINT8				m_bEnvironmentalMapping	: 1;
		UINT8				polyListNeedsSort		: 1;
		UINT8				matUsage				: 8;
		UINT8				libFlag					: 8;
		zTRnd_AlphaBlendFunc rndAlphaBlendFunc		: 8;
		UINT8				m_bIgnoreSun			: 1;
	};

	zTWaveAniMode			m_enuWaveMode;
	zTFFT					m_enuWaveSpeed;
	float					m_fWaveMaxAmplitude;
	float					m_fWaveGridSize;
	zCTexture				*detailTexture;
	float					detailTextureScale;
	zVEC2					texAniMapDelta;

	zVEC2					default_mapping;
	zVEC2					texScale;

	static zCClassDef*		classDef;
	static unsigned char zCMaterial::s_matUsageDefault;
	zSTRING const& GetName(void)const 
	{
		XCALL(0x0055FF10);
	};

	void zMaterial(void)
	{
		XCALL(0x00563E00);
	};

	void zMaterial(zSTRING const&)
	{
		XCALL(0x00563EE0);
	};

	void zMaterial(zCMaterial const&)
	{
		XCALL(0x00563FA0);
	};

	zCMaterial(void)
	{
		zMaterial();
	};

	zCMaterial(zSTRING const& name)
	{
		zMaterial(name);
	};

	zCMaterial(zCMaterial const& pMat)
	{
		zMaterial(pMat);
	};

	zCMaterial& operator=(zCMaterial const&)
	{
		XCALL(0x00564050);
	};

	void InitThisByMaterial(zCMaterial const&)
	{
		XCALL(0x00564130);
	};

	void InitValues(void)
	{
		XCALL(0x00564260);
	};

	void SetDetailObjectVisual(zSTRING const&)
	{
		XCALL(0x00564370);
	};

	zSTRING const& GetDetailObjectVisual(void)const 
	{
		XCALL(0x005644F0);
	};

	void ApplyTexAniMapping(zCPolygon*)
	{
		XCALL(0x00564500);
	};

	zVEC3 GetTexAniVector(zCPolygon*)
	{
		XCALL(0x00564590);
	};

	int IsPortalMaterial(void)const 
	{
		XCALL(0x005648D0);
	};

	void SetTexAniMappingDir(zVEC2 const&)
	{
		XCALL(0x005649C0);
	};

	void SetTexture(zSTRING&)
	{
		XCALL(0x005649E0);
	};

	void SetTexture(zCTexture*)
	{
		XCALL(0x00564B20);
	};

	void SetDetailTexture(zSTRING&)
	{
		XCALL(0x00564CD0);
	};

	void SetDetailTexture(zCTexture*)
	{
		XCALL(0x00564DD0);
	};

	void AutoAssignDetailTexture(void)
	{
		XCALL(0x00564E20);
	};

	zVEC2 GetTexScale(void)
	{
		XCALL(0x00564FC0);
	};

	void SetTexScale(zVEC2)
	{
		XCALL(0x00565020);
	};

	void RemoveTexture(void)
	{
		XCALL(0x00565040);
	};

	static zSTRING const& GetMatGroupString(zTMat_Group)
	{
		XCALL(0x00565110);
	};

	zSTRING const& GetMatGroupString(void)const 
	{
		XCALL(0x00565170);
	};

	void SetMatGroupByString(zSTRING const&)
	{
		XCALL(0x005651D0);
	};

	void RefreshAvgColorFromTexture(void)
	{
		XCALL(0x005653D0);
	};

	static zCMaterial* SearchName(zSTRING&)
	{
		XCALL(0x00565E30);
	};

	zCTexture* GetAniTexture(void)
	{
		XCALL(0x0064BA20);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00563DF0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x00565420);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00565780);
	};

	virtual ~zCMaterial()
	{
		XCALL(0x00564070);
	};	
};

