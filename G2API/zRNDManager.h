#pragma once
#include "ztypes.h"
#include "zcrenderer.h"




class zCPolygon;
class zCMaterial;
class zCShader;
class zCVertexBuffer;
class zCVertexBufferDyn2;
class zCTexture;
class zCShaderStage;



class zCRenderManager
{
public:
	
	enum
	{
		zRENDERMAN_NUM_SHADER			= 64
	}; 
	enum
	{
		zRENDERMAN_NUM_SHADER_STAGES	= zRENDERMAN_NUM_SHADER * 4
	};
	
	DWORD						frameCtr;
	zCArray<zCMaterial*>		sceneMaterialList;
	zCArray<zCPolygon*>		    sceneSimpleAlphaPolyList;	
	int							overrideAlphaValue;			
	zTRnd_AlphaBlendFunc		overrideAlphaBlendFunc;
	int							hintLightning;					
	BOOL						rendererMaterialModified;
	friend class zCRndAlphaSortObject_WorldPoly;
};							





enum zTShaderWaveFunc
{
    zSHD_FUNC_CONST,
	zSHD_FUNC_SIN,
    zSHD_FUNC_TRIANGLE,
    zSHD_FUNC_SQUARE,
    zSHD_FUNC_SAWTOOTH,
    zSHD_FUNC_INVERSESAWTOOTH,
	zSHD_FUNC_NOISE
};


enum zTShaderRGBGen
{
	zSHD_RGBGEN_IDENTITY,
	zSHD_RGBGEN_VERTEX,		
	zSHD_RGBGEN_FACTOR,
	zSHD_RGBGEN_WAVE,	
};

enum zTShaderAlphaGen
{
	zSHD_ALPHAGEN_IDENTITY,
	zSHD_ALPHAGEN_VERTEX,
	zSHD_ALPHAGEN_FACTOR,
	zSHD_ALPHAGEN_DETAILFADE,
	zSHD_ALPHAGEN_FARFADE,
	zSHD_ALPHAGEN_WATER
};


enum zTShaderTCGen
{
	zSHD_TCGEN_BASE,
	zSHD_TCGEN_LIGHTMAP,	
	zSHD_TCGEN_ENVIRONMENT,	
	zSHD_TCGEN_ENVIRONMENT_FLAT,
};


enum zTShaderTCMod
{
	zSHD_TCMOD_NONE,
	zSHD_TCMOD_SCROLL,
	zSHD_TCMOD_ENVIRONMENT,
	zSHD_TCMOD_ROTATE,
	zSHD_TCMOD_SCALE,
	zSHD_TCMOD_STRETCH,
	zSHD_TCMOD_TRANSFORM,
	zSHD_TCMOD_TURB,
};


enum zTShaderDeformVertex
{
	zSHD_DEFORMVERT_NONE,
	zSHD_DEFORMVERT_WAVE,
	zSHD_DEFORMVERT_NORMAL,
	zSHD_DEFORMVERT_BULGE,	
	zSHD_DEFORMVERT_MOVE,	
	zSHD_DEFORMVERT_AUTOSPRITE,
	zSHD_DEFORMVERT_AUTOSPRITE2,
};


enum
{
	LF_NOMIPMAP=0x01,		
	LF_NOPICMIP=0x02,		
	LF_CLAMP=0x04,			
	LF_DETAIL=0x08,			
	LF_LIGHTMAP=0x10,		
	LF_HASTCMOD=0x20,
	LF_USENORMALS=0x40,
	LF_MULTITEX=0x80		
};


enum
{
	SF_NOMIPMAP=0x01,			
	SF_NOPICMIP=0x02,			
	SF_POLYGONOFFSET=0x04,		
	SF_PORTAL=0x08,				
	SF_HASLIGHTMAP=0x10,		
	SF_HASCOLORS=0x20,			
	SF_HASTCMOD=0x40,			
	SF_USENORMALS=0x80,			
	SF_MULTITEX=0x0100			
};

enum zTShaderFXMode
{
	zSHD_FX_NONE=0,
	zSHD_FX_BASETEX,
	zSHD_FX_LIGHTMAP,
	zSHD_FX_LIGHTMAP_DYN,
	zSHD_FX_DETAIL,
	zSHD_FX_MACRO,
	zSHD_FX_ENV,
	zSHD_FX_SPECULAR,
};

class zCShaderStage
{
public:
	zTShaderFXMode			shaderFXMode;
	zCTexture				*texture;
	zTRnd_AlphaBlendFunc	alphaFunc;
	zCOLOR					colorFactor;
	zCOLOR					avgTextureColor;		
	
	zTShaderAlphaGen		alphaGen;
	zTShaderRGBGen			rgbGen;
	zTShaderTCGen			tcGen;
	zTShaderTCMod			tcMod;
	float					tcModParams[2];			

	BOOL					multiTextureNext;
	void Clear				()
	{ 
		memset (this, 0, sizeof(*this));			
	};
};

class zCShader
{
public:
	int						GetNumStages		() const						{ return numStages;					};
	zCShaderStage*			GetStage			(int stageIndex) const			{ return stageList[stageIndex];		};
	void					AddStage			(zCShaderStage *stage)			{ stageList[numStages++] = stage;	};
	void					InsertStage			(int pos, zCShaderStage *stage);
	void					Clear				()								{ numStages=0; hasLightmap = hasTcGenEnv = baseTexCachedIn = FALSE; };
	BOOL					GetHasLightmap		() const						{ return hasLightmap;				};
	BOOL					GetBaseTexCachedIn	() const						{ return baseTexCachedIn;			};

	enum
	{
		MAX_STAGES = 4
	};
	int						numStages;
	zCShaderStage			*stageList[MAX_STAGES];
	BOOL					hasLightmap;
	BOOL					hasTcGenEnv;
	BOOL					inSector;
	BOOL					baseTexCachedIn;
};





class zCMapDetailTexture
{
public:
	struct zTMapDetailTextureEntry
	{
		zSTRING		detailTextureName;
		float		detailTextureScale;
	};
};