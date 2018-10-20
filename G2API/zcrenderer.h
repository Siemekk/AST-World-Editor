#pragma once


#include "ztypes.h"
#include "DX7\include\d3d.h"
#include "DX7\include\ddraw.h"

class zCTextureConvert;




const int DEFAULT_LEVEL_ZBIAS	=	0;
const int DEFAULT_VOB_ZBIAS		=   1;




class	zCPolygon;
class	zCTexture;
class	zCOLOR;
class	zVEC3;
class	zCTextureConvert;
class	zCShader;
class	zCVertexBuffer;
class	zCRenderLight;




enum zTRnd_PolySortMode
{	
	zRND_SORT_NONE, 
	zRND_SORT_ZBUFFER
};

enum zTRnd_ZBufferCmp
{	zRND_ZBUFFER_CMP_ALWAYS, 
	zRND_ZBUFFER_CMP_NEVER, 
	zRND_ZBUFFER_CMP_LESS,
	zRND_ZBUFFER_CMP_LESS_EQUAL,
};

enum zTRnd_PolyDrawMode
{	
	zRND_DRAW_MATERIAL, 
	zRND_DRAW_MATERIAL_WIRE,
	zRND_DRAW_FLAT, 
	zRND_DRAW_WIRE,
}; 

enum zTRnd_FogMode
{
	zRND_FOG_FALLOFF_LINEAR
};

enum zTRnd_AlphaBlendSource
{
	zRND_ALPHA_SOURCE_MATERIAL, 
	zRND_ALPHA_SOURCE_CONSTANT 
}; 

enum zTRnd_AlphaBlendFunc
{	
	zRND_ALPHA_FUNC_MAT_DEFAULT,			
	zRND_ALPHA_FUNC_NONE,					
	zRND_ALPHA_FUNC_BLEND,					
	zRND_ALPHA_FUNC_ADD,					
	zRND_ALPHA_FUNC_SUB,					
	zRND_ALPHA_FUNC_MUL,					
	zRND_ALPHA_FUNC_MUL2,					
	zRND_ALPHA_FUNC_TEST,					
	zRND_ALPHA_FUNC_BLEND_TEST				
};	 						

enum zTRnd_Capability
{	
	zRND_CAP_GUARD_BAND,					
	zRND_CAP_ALPHATEST,						
	zRND_CAP_MAX_BLEND_STAGES,				
	zRND_CAP_MAX_BLEND_STAGE_TEXTURES,		
	zRND_CAP_DIFFUSE_LAST_BLEND_STAGE_ONLY,	
	zRND_CAP_TNL,							
	zRND_CAP_TNL_HARDWARE,					
	zRND_CAP_TNL_MAXLIGHTS,					
	zRND_CAP_DEPTH_BUFFER_PREC,				
	zRND_CAP_BLENDDIFFUSEALPHA,				
};

enum zTRnd_RenderMode
{	
	zRND_MODE_1_PASS_VERT_LIGHT,
	zRND_MODE_1_PASS_MULTITEXTURE,
	zRND_MODE_2_PASS_TEXTURE,				
	zRND_MODE_2_PASS_LIGHTMAP,				
	zRND_MODE_DYN_POLYS_VERT_LIGHT
};

enum zTRnd_ScreenMode
{
	zRND_SCRMODE_FULLSCREEN,
	zRND_SCRMODE_WINDOWED,
	zRND_SCRMODE_HIDE 		
};

enum zTRnd_ClearTarget
{
	zRND_CLEAR_FRAMEBUFFER	= 1,			
	zRND_CLEAR_ZBUFFER		= 2,
	zRND_CLEAR_ALL			= (zRND_CLEAR_FRAMEBUFFER | zRND_CLEAR_ZBUFFER)
};

enum zTRnd_RenderStateType
{
	zRND_RENDERSTATE_CLIPPING		=0,		
	zRND_RENDERSTATE_TEXTUREFACTOR	,		
	zRND_RENDERSTATE_COUNT			,
};	

enum zTRnd_TextureFormat;




enum zTRnd_TextureStageState
{
    zRND_TSS_COLOROP					= 0,	
    zRND_TSS_COLORARG1					,		
    zRND_TSS_COLORARG2					,		
    zRND_TSS_ALPHAOP					,		
    zRND_TSS_ALPHAARG1					,		
    zRND_TSS_ALPHAARG2					,		
    zRND_TSS_BUMPENVMAT00				,		
    zRND_TSS_BUMPENVMAT01				,		
    zRND_TSS_BUMPENVMAT10				,		
    zRND_TSS_BUMPENVMAT11				,		
    zRND_TSS_TEXCOORDINDEX				,		
    zRND_TSS_ADDRESS					,		
    zRND_TSS_ADDRESSU					,		
    zRND_TSS_ADDRESSV					,		
    zRND_TSS_BORDERCOLOR				,		
    zRND_TSS_MAGFILTER					,		
    zRND_TSS_MINFILTER					,		
    zRND_TSS_MIPFILTER					,		
    zRND_TSS_MIPMAPLODBIAS				,		
    zRND_TSS_MAXMIPLEVEL				,		
    zRND_TSS_MAXANISOTROPY				,		
    zRND_TSS_BUMPENVLSCALE				,		
    zRND_TSS_BUMPENVLOFFSET				,		
    zRND_TSS_TEXTURETRANSFORMFLAGS		,		

	zRND_TSS_COUNT						,
};

enum zTRnd_TextureStageOp
{
	zRND_TOP_DISABLE					= 0,  
	zRND_TOP_SELECTARG1					,  
	zRND_TOP_SELECTARG2					,  
	zRND_TOP_MODULATE					,  
	zRND_TOP_MODULATE2X					,  
	zRND_TOP_MODULATE4X					,		
	zRND_TOP_ADD						,  
	zRND_TOP_ADDSIGNED					,		
	zRND_TOP_ADDSIGNED2X				,		
	zRND_TOP_SUBTRACT					,		
	zRND_TOP_ADDSMOOTH					,		
	zRND_TOP_BLENDDIFFUSEALPHA			,	
	zRND_TOP_BLENDTEXTUREALPHA			,  
	zRND_TOP_BLENDFACTORALPHA			,  
	zRND_TOP_BLENDTEXTUREALPHAPM		,  
	zRND_TOP_BLENDCURRENTALPHA			,  
	zRND_TOP_PREMODULATE				,		
	zRND_TOP_MODULATEALPHA_ADDCOLOR		,		
	zRND_TOP_MODULATECOLOR_ADDALPHA		,		
	zRND_TOP_MODULATEINVALPHA_ADDCOLOR	,		
	zRND_TOP_MODULATEINVCOLOR_ADDALPHA  ,		
    zRND_TOP_BUMPENVMAP					,		
    zRND_TOP_BUMPENVMAPLUMINANCE		,		
    zRND_TOP_DOTPRODUCT3				,		

	zRND_TOP_COUNT						,
};

enum zTRnd_TextureStageArg
{
	zRND_TA_CURRENT						= 0,	
	zRND_TA_DIFFUSE						,		
	zRND_TA_SELECTMASK					,		
	zRND_TA_TEXTURE						,		
	zRND_TA_TFACTOR						,		
	zRND_TA_SPECULAR							
};

enum zTRnd_TextureStageTexCoord
{
	zRND_TSS_TCI_PASSTHRU						= 0x00000000,
	zRND_TSS_TCI_CAMERASPACENORMAL				= 0x00010000,
	zRND_TSS_TCI_CAMERASPACEPOSITION			= 0x00020000,
	zRND_TSS_TCI_CAMERASPACEREFLECTIONVECTOR	= 0x00030000,
};

enum zTRnd_TextureStageTexTransformFlags
{
	zRND_TTF_DISABLE					= 0,   
    zRND_TTF_COUNT1						= 1,   
    zRND_TTF_COUNT2						= 2,   
    zRND_TTF_COUNT3						= 3,   
    zRND_TTF_COUNT4						= 4,   

};




enum zTRnd_TrafoType 
{
	zRND_TRAFO_VIEW,
	zRND_TRAFO_PROJECTION,
	zRND_TRAFO_TEXTURE0,
	zRND_TRAFO_TEXTURE1,
	zRND_TRAFO_TEXTURE2,
	zRND_TRAFO_TEXTURE3,
};

enum zTRenderLightType
{
	zLIGHT_TYPE_POINT	= 1,
	zLIGHT_TYPE_SPOT	= 2,
	zLIGHT_TYPE_DIR		= 3,
	zLIGHT_TYPE_AMBIENT	= 4
};

class zCRenderLight {
public:
	
	zTRenderLightType	lightType;            
	zVEC3				colorDiffuse;				
	zVEC3				position;					
	zVEC3				direction;					
	float				range;									
	
	float				rangeInv;
	zVEC3				positionLS;					
	zVEC3				directionLS;				
	float				dir_approxFalloff;			
};



class zCRndAlphaSortObject
{
public:
			 zCRndAlphaSortObject() {};
	virtual ~zCRndAlphaSortObject() {};

	virtual void			Draw				(int currentIndex)=0;
	virtual BOOL			IsAlphaPoly			() { return FALSE; };	
	void					SetZValue			(const float zin)					{ zvalue = zin;					};
	float					GetZValue			() const							{ return zvalue;				};
	void					SetNext				(zCRndAlphaSortObject* sortObject)	{ nextSortObject = sortObject;	};
	zCRndAlphaSortObject*	GetNext				() const							{ return nextSortObject;		};

protected:
	zCRndAlphaSortObject	*nextSortObject;	
	float					zvalue;
};



struct zTRnd_TexFormatInfo
{
	float		bytesPerPixel;
	int			rPos, gPos, bPos, aPos;						
	int			rSize,gSize,bSize,aSize;					
	
};

struct zTRnd_DeviceInfo
{
	zSTRING		deviceName;
};

struct zTRnd_VidModeInfo
{
	int			xdim;
	int			ydim;
	int			bpp;
	BOOL		fullscreenOnly;
};


struct zTRnd_Stats
{	
	int			texMemUsed;			
	int			texMemFetched;		
	int			numTexturesFetched;	
	int			numTexturesUsed;	
	int			numLightmapsUsed;	
				
	int			numPolysRendered;	
	int			numTrisRendered;	

	int			numAlphaPolys;		
	int			numAlphaPolyBatches;
};

struct zTRndSimpleVertex
{
	zVEC2	pos;
	float	z;
	zVEC2	uv;
	zCOLOR	color;
};

struct zTRndSurfaceDesc
{
	void*	pSurface;
	DWORD	bytePitch ;
	DWORD	pixelWidth;
	DWORD	pixelHeight;
	DWORD	bitRGBCount;
	DWORD	bitRMask;
	DWORD	bitGMask;
	DWORD	bitBMask;
};

class zCRenderer
{
	zTRnd_PolySortMode				polySortMode;
	zTRnd_PolyDrawMode				polyDrawMode;

public:
	
	zTRnd_AlphaBlendFunc			AlphaBlendFuncStringToType	(const zSTRING& s) const;
	zSTRING							AlphaBlendFuncTypeToString	(const zTRnd_AlphaBlendFunc func) const;
	zTRnd_TexFormatInfo				GetTexFormatInfo			(const zTRnd_TextureFormat texFormat) const;
public:
	
									zCRenderer			() {};
	virtual							~zCRenderer			() {};						

	
	virtual void					BeginFrame			()=0;
	virtual void					EndFrame			()=0;				
	virtual void					FlushPolys			()=0;					
	
	
	virtual void					DrawPoly			(zCPolygon* poly)=0;
	virtual void					DrawLightmapList	(zCPolygon** polyList, int numPoly)		{};
	virtual void					DrawLine			(float x1, float y1, float x2, float y2, const zCOLOR col)=0;
	virtual void					DrawLineZ			(float x1Scr, float y1Scr, float z1CamSpaceInv, 
														 float x2Scr, float y2Scr, float z2CamSpaceInv, const zCOLOR col) {};
	virtual void					SetPixel			(float x, float y, const zCOLOR col)=0;
 
	
	void							DrawTile			(zCTexture		*texture,	
														 const zVEC2&	posMin,
														 const zVEC2&	posMax,
														 const float	zValue,
														 const zVEC2&	uvMin,
														 const zVEC2&	uvMax,
														 const zCOLOR	color) {XCALL(0x005D3CF0);};
	virtual void					DrawPolySimple		(zCTexture	*texture, zTRndSimpleVertex *vertex, int numVert) {};

	
	virtual void					SetFog				(const BOOL foggy)=0;
	virtual BOOL					GetFog				() const				{ return FALSE;				};
	virtual void					SetRadialFog		(const BOOL foggy)=0;
	virtual BOOL					GetRadialFog		() const				{ return FALSE;				};

	virtual void					SetFogColor			(const zCOLOR& col)=0;
	virtual zCOLOR					GetFogColor			() const				{ zCOLOR col; col.SetRGBA(0,0,0,255); return col;	};
	virtual void					SetFogRange			(const float nearz, const float farz, const zTRnd_FogMode falloff=zRND_FOG_FALLOFF_LINEAR)=0;
	virtual void					GetFogRange			(float& nearz, float& farz, zTRnd_FogMode& falloff) {};

	virtual zTRnd_PolyDrawMode		GetPolyDrawMode		() const								{ return polyDrawMode;		};
	virtual void					SetPolyDrawMode		(const zTRnd_PolyDrawMode& drawMode)	{ polyDrawMode = drawMode;	};

	
	virtual BOOL					GetSurfaceLost		() const								{ return FALSE;				};
	virtual void					SetSurfaceLost		(const BOOL b)							{ };

	
	virtual BOOL					GetSyncOnAmbientCol () const								{ return FALSE;				};
	virtual void					SetSyncOnAmbientCol (const BOOL b)							{ };


	virtual void					SetTextureWrapEnabled(const BOOL b)						{ };
	virtual BOOL					GetTextureWrapEnabled() const								{ return TRUE; };

	virtual void					SetBilerpFilterEnabled(const BOOL b)=0;
	virtual BOOL					GetBilerpFilterEnabled() const=0;

	virtual void					SetDitherEnabled	(const BOOL b)							{ };
	virtual BOOL					GetDitherEnabled	() const								{ return TRUE; };

	
	virtual zTRnd_PolySortMode		GetPolySortMode		() const								{ return polySortMode;		};
	virtual void					SetPolySortMode		(const zTRnd_PolySortMode& smode)		{ polySortMode = smode;		};
	virtual	BOOL					GetZBufferWriteEnabled() const								{ return TRUE; };
	virtual	void					SetZBufferWriteEnabled(const BOOL)							{};
	virtual void					SetZBias			(const int zBias)						{};
	virtual int						GetZBias			() const								{ return 0;	};
	virtual	zTRnd_ZBufferCmp		GetZBufferCompare	()										{ return zRND_ZBUFFER_CMP_LESS; };
	virtual	void					SetZBufferCompare	(const zTRnd_ZBufferCmp& zcmp)			{};
	virtual	BOOL					GetPixelWriteEnabled() const								{ return TRUE; };
	virtual	void					SetPixelWriteEnabled(const BOOL)							{};

	
	virtual	void					SetAlphaBlendSource	(const zTRnd_AlphaBlendSource &src)		{};
	virtual	zTRnd_AlphaBlendSource	GetAlphaBlendSource	() const								{ return zRND_ALPHA_SOURCE_MATERIAL; };
	virtual	void					SetAlphaBlendFunc	(const zTRnd_AlphaBlendFunc &mode)		{};
	virtual	zTRnd_AlphaBlendFunc	GetAlphaBlendFunc	() const								{ return zRND_ALPHA_FUNC_MAT_DEFAULT;};
	virtual	float					GetAlphaBlendFactor	() const								{ return 1.0F; };
	virtual	void					SetAlphaBlendFactor	(const float &percentage)				{};	
	virtual void					SetAlphaReference		(const DWORD a_alphaReference)		{ };
	virtual DWORD					GetAlphaReference		()	const							{ return 0;	};

	virtual	BOOL					GetCacheAlphaPolys	() const								{ return TRUE; };	
	virtual	void					SetCacheAlphaPolys	(const BOOL)							{};	
	virtual	BOOL					GetAlphaLimitReached() const								{ return FALSE;	};

	virtual	void					AddAlphaPoly		(const zCPolygon* poly)					{};
	virtual void					FlushAlphaPolys		()										{};

	
	virtual void					SetRenderMode		(const zTRnd_RenderMode rmode)			{};
	virtual zTRnd_RenderMode		GetRenderMode		() const								{ return zRND_MODE_1_PASS_VERT_LIGHT; };
	virtual int						HasCapability		(const zTRnd_Capability) const			{ return FALSE; };
	virtual void					GetGuardBandBorders	(float& guardBandLeft, float& guardBandTop, float& guardBandRight, float& guardBandBottom) {};
	virtual void					ResetZTest			()										{};
	virtual int						HasPassedZTest		()										{ return TRUE;	};

	
	
	
	virtual zCTexture*				CreateTexture		()=0;
	virtual zCTextureConvert*		CreateTextureConvert() { return 0;		};

	
	
	
	virtual int						GetTotalTextureMem	()=0;					
	virtual BOOL					SupportsTextureFormat(const zTRnd_TextureFormat texFormat) { return FALSE; };			
	virtual BOOL					SupportsTextureFormatHardware(const zTRnd_TextureFormat texFormat) { return FALSE; };	
	virtual int						GetMaxTextureSize	() { return 256;	};

	
	virtual void					GetStatistics		(zTRnd_Stats &stat) =0;
	virtual void					ResetStatistics		()=0;

	
	
	


	int		vid_xdim ,vid_ydim	,vid_bpp ,vid_pitch;		
	int		vid_rpos ,vid_gpos	,vid_bpos;					
	int		vid_rsize,vid_gsize	,vid_bsize;					

	
	virtual void					Vid_Blit				(BOOL forceFlip=TRUE,  RECT *sourceRect=NULL, RECT *destRect=NULL)=0;		
	virtual void					Vid_Clear				(zCOLOR &col, int clearTarget = zRND_CLEAR_ALL)=0;	
	virtual BOOL					Vid_Lock				(zTRndSurfaceDesc &surfdesc)=0;		
	virtual BOOL					Vid_Unlock				()=0;								
	virtual BOOL					Vid_IsLocked			()=0;								
	virtual BOOL					Vid_GetFrontBufferCopy	(zCTextureConvert &frontcopy)=0;

	
	virtual int						Vid_GetNumDevices		()=0;												
	virtual int						Vid_GetActiveDeviceNr	()=0;												
	virtual BOOL					Vid_SetDevice			(int deviceNr)=0;									
	virtual BOOL					Vid_GetDeviceInfo		(zTRnd_DeviceInfo& deviceInfo, int deviceNr)=0;
	virtual int						Vid_GetNumModes			()=0;												
	virtual BOOL					Vid_GetModeInfo			(zTRnd_VidModeInfo& modeInfo, int modeNr)=0;
	virtual int						Vid_GetActiveModeNr		()=0;
	
	virtual BOOL					Vid_SetMode				(int modeNr, void* initContextHandle=0)=0;
			BOOL					Vid_SetMode				(int newXDim, int newYDim, int newBpp, void* initContextHandle=0); 

	
	virtual void					Vid_SetScreenMode		(zTRnd_ScreenMode scrmode)=0;
	virtual zTRnd_ScreenMode		Vid_GetScreenMode		()=0;
								
	virtual void					Vid_SetGammaCorrection	(float gamma = 0.5f, float contrast = 0.5f, float brightness = 0.5f)=0; 
	virtual float					Vid_GetGammaCorrection  ()=0;
									

									
	
	virtual void					Vid_BeginLfbAccess		()=0;
	virtual void					Vid_EndLfbAccess		()=0;
	virtual	void					Vid_SetLfbAlpha			(int opacity)=0;						
	virtual void					Vid_SetLfbAlphaFunc		(const zTRnd_AlphaBlendFunc &func)=0;

	

	
	struct zTMaterial
	{
		zVEC4		diffuseRGBA;
		zVEC4		ambientRGBA;
	};
	virtual BOOL					SetTransform			(zTRnd_TrafoType transformType, const zMAT4& matrix){ return FALSE; };
	virtual BOOL					SetViewport				(int x0, int y0, int xdim, int ydim)				{ return FALSE; };
	virtual BOOL					SetLight				(DWORD lightIndex, zCRenderLight *light)			{ return FALSE; };
	virtual BOOL					GetMaterial				(zTMaterial &material)								{ return FALSE; };
	virtual BOOL					SetMaterial				(const zTMaterial &material)						{ return FALSE; };
									
	
	virtual BOOL					SetTexture				(DWORD stage, zCTexture *texture)					 { return FALSE; };
	virtual BOOL					SetTextureStageState	(DWORD stage, zTRnd_TextureStageState state, DWORD value)  { return FALSE; };
	virtual	BOOL					SetAlphaBlendFuncImmed	(const zTRnd_AlphaBlendFunc afunc)					{ return FALSE; };

	
	virtual BOOL					SetRenderState			(zTRnd_RenderStateType renderStateType, DWORD renderState) { return FALSE; };
	virtual DWORD					GetRenderState			(zTRnd_RenderStateType renderStateType)						{ return FALSE; };
	
	
	virtual void					AddAlphaSortObject		(zCRndAlphaSortObject *alphaSortObject) {};
	virtual void					RenderAlphaSortList		() {};

	
	virtual BOOL					DrawVertexBuffer		(zCVertexBuffer *vertexBuffer, 
															 int			firstVert	= 0, 
															 int			numVert		=-1, 
															 WORD			*indexList	= 0, 
															 DWORD			numIndex	= 0)=0;	

	virtual zCVertexBuffer*			CreateVertexBuffer		()=0;
};

