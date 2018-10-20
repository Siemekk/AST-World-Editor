#pragma once


#include "zThread.h"
#include "zcrenderer.h"


#define scrSTATUS_Used			1
#define scrSTATUS_Free			0

#define MAXBUCKETS				256
#define MAXALPHAPOLYS			2048
#define ALPHAVERTEXBUFFERSIZE	1024
#define MAXTEXTURESTAGES		4
#define MAXRENDERSTATES			160

#define SURFACECACHECOUNTLIMIT	128
#define SURFACECACHETIMELIMIT	2000
#define RADIAL 1
#define LINEAR 2


#define d3dMIN(a,m)				(a>m ? a:m)
#define d3dMAX(a,m)				(a<m ? a:m)
#define d3dCLAMP(a, min,max)	(d3dMIN(d3dMAX(a,max),min))

class zCSurfaceCache_D3D;

class zCDXTCCache_D3D;


BOOL DXTryWarning( HRESULT hr, const char *info_str = NULL ) 
{ 
	XCALL(0x00644FF0);
}

enum zTRnd_DepthBufferLevel
{
	zRND_W32_BUFFER,
	zRND_W24_BUFFER,
	zRND_W16_BUFFER,
	zRND_Z32_BUFFER,
	zRND_Z24_BUFFER,
	zRND_Z16_BUFFER,
	zRND_UNKNOWN_BUFFER
};

class zCTex_D3D;
struct zD3D_savedTexture;
class zCVertexBuffer_D3D;


class zD3D_alphaPoly : public zCRndAlphaSortObject
{
	friend class zCRnd_D3D;
public:
	enum					{ zMAX_VERT	= 8 };

	void					Draw( int currentIndex )
	{
		XCALL(0x00650CF0);
	};

	BOOL					IsAlphaPoly() { return TRUE; };
protected:
	struct zD3D_vertexFormat
	{
		D3DVALUE a_sx;
		D3DVALUE a_sy;
		D3DVALUE a_sz;
		D3DVALUE a_rhw;
		D3DCOLOR a_color;
		D3DVALUE a_tu;
		D3DVALUE a_tv;
	};

	zTRnd_AlphaBlendFunc	alphafunc;
	zCTex_D3D				*tex;
	BOOL					wrap;
	unsigned long			zfunc;
	int						numVert;
	int						zBias;
	zD3D_vertexFormat		vertexList[zMAX_VERT];		

	
	
	
	
	
	
	
};



struct zD3D_savedTexture;
class zCMaterial;

class zCRnd_D3D : public zCRenderer		
{
public:
	struct zD3D_Status 
	{	
		int						modeNr;
		int						devnum;
		int						devmax;
		BOOL					texwrap;
		BOOL					filter;
		BOOL					dither;
		BOOL					fog;
		float					nearZ;
		float					farZ;
		zCOLOR					fogColor;
		zTRnd_FogMode			fogMode;
		zTRnd_AlphaBlendFunc	alphafunc;
		zTRnd_AlphaBlendSource	alphasrc;
		float					alphafactor;
		BOOL					zenable;
		BOOL					fenable;
		zTRnd_ZBufferCmp		zfunc;
		BOOL					zwrite;
		int						zbias;
		unsigned long			zd3dfunc;
		DDPIXELFORMAT			ddpf;
		float					gammavalue;
		BOOL					palsupported;
		zTRnd_RenderMode		renderMode;

		zD3D_Status()
		{
			modeNr			= 0;
			devnum			= 0;
			devmax			= 1;
			texwrap			= TRUE;
			filter			= TRUE;
			dither			= TRUE;
			fog				= FALSE;
			nearZ			= 0.0f;
			farZ			= 0.0f;
			fogColor.SetR( 0x00 );
			fogColor.SetG( 0x00 );
			fogColor.SetB( 0x00 );
			fogMode			= zRND_FOG_FALLOFF_LINEAR;
			alphafunc		= zRND_ALPHA_FUNC_MAT_DEFAULT;
			alphasrc		= zRND_ALPHA_SOURCE_MATERIAL; 
			alphafactor		= 1.0f;
			fenable			= TRUE;
			zbias			= 0;
			zfunc			= zRND_ZBUFFER_CMP_LESS;
			zwrite			= TRUE;
			zd3dfunc		= D3DCMP_LESSEQUAL;
			gammavalue		= 0.45f;
			palsupported	= FALSE;
			renderMode		= zRND_MODE_1_PASS_VERT_LIGHT;
		}
	};

	struct zD3D_Caps
	{	
		unsigned long			vidmemsize;
		unsigned long			vidmemfree;
		unsigned long			mintexsize;
		unsigned long			maxtexsize;
		BOOL					window;
		BOOL					gamma;
		BOOL					multitexture;
		BOOL					ztest;
		BOOL					guardband;
		float					guardbandleft;
		float					guardbandright;
		float					guardbandtop;
		float					guardbandbottom;
		
		BOOL					alphatest;
		int						num_stages;
		int						num_texstages;	
		BOOL					tnl;
		BOOL					tnl_hardware;
		BOOL					tnl_maxlights;
		BOOL					blendDiffuseAlpha;
		BOOL					hasStencil;

		zD3D_Caps()
		{
			vidmemsize			= 0;
			vidmemfree			= 0;
			mintexsize			= 0;
			maxtexsize			= 0;
			window				= FALSE;
			gamma				= FALSE;
			multitexture		= FALSE;
			ztest				= FALSE;
			guardband			= FALSE;
			guardbandleft		= 0.0f;
			guardbandright		= 0.0f;
			guardbandtop		= 0.0f;
			guardbandbottom		= 0.0f;
			alphatest			= FALSE;
			num_texstages		= 0;
			tnl					= FALSE;
			tnl_hardware		= FALSE;
			tnl_maxlights		= 0;
			hasStencil			= FALSE;
			blendDiffuseAlpha	= FALSE;
		}
	};

	int						fogType;

	DWORD					xd3d_actRenderState[MAXRENDERSTATES];
	DWORD					xd3d_actTexStageState[MAXTEXTURESTAGES][zRND_TSS_COUNT];
	zD3D_Status				xd3d_actStatus;
	zD3D_Caps				xd3d_Capabilities;
	DDDEVICEIDENTIFIER2		xd3d_deviceIdentifier;
	
	unsigned int			xd3d_numLightmapsUsedThisFrame;

	BOOL					xd3d_wBuffer;
	zTRnd_DepthBufferLevel	xd3d_zwBufferLevel;
	BOOL					xd3d_alphaTest;
	BOOL					xd3d_alphaBlendImmed;

	BOOL					xd3d_backlocked;

	IDirectDrawSurface7		*xd3d_pfrontBuffer;
	IDirectDrawSurface7		*xd3d_pbackBuffer;
	IDirectDrawSurface7		*xd3d_pzBuffer;
	IDirectDrawClipper		*xd3d_pclipper;
	IDirectDrawGammaControl	*xd3d_pgammacontrol;
	DDPIXELFORMAT			xd3d_pixelformat;

	BOOL					xd3d_deviceChange;


	zTRnd_ScreenMode		xd3d_scrMode; 
	int						xd3d_scrStatus;
	int						xd3d_scrWidth;
	int						xd3d_scrHeight;
	int						xd3d_scrBpp;

	int						xd3d_num;
	zTRnd_ScreenMode		xd3d_mode;
	int						xd3d_x; 
	int						xd3d_y;
	int						xd3d_bpp;
	
	float					xd3d_zMAX_from_Engine;
	float					xd3d_zMIN_from_Engine;
	float					xd3d_scale_A;
	float					xd3d_scale_B;
	float					xd3d_scale_C;

	zCMaterial				*xd3d_pactivematerial;
	zTMaterial				xd3d_actmaterial;

	zTRnd_Stats				xd3d_statistics;
	HWND					xd3d_newWinHandle;
	HWND					xd3d_winHandle;
	zTRnd_RenderMode		xd3d_renderMode;
	int						xd3d_tryDevnum;
	BOOL					xd3d_inScene;

	
	BOOL					xd3d_disableFog;
	BOOL					xd3d_enableRadialFog;

	zD3D_alphaPoly			xd3d_alphaPolyPool[MAXALPHAPOLYS];
	int						xd3d_numAlphaPolys;
	zCRndAlphaSortObject	*xd3d_alphaSortBucket[MAXBUCKETS]; 
	float					xd3d_bucketSize;
	DWORD					alphaReference;
	
	BOOL					xd3d_vbclipping;
	DWORD					xd3d_texturefactor;
	BOOL					m_bAlphaLimitReached;
	BOOL					m_bSurfaceLost;

	zCTex_D3D				*xd3d_ptexture[MAXTEXTURESTAGES]; 
	IDirectDrawSurface7		*xd3d_pd3dtexture[MAXTEXTURESTAGES];
	unsigned int			xd3d_numTexturesUsedThisFrame;

	zD3D_savedTexture		*xd3d_savedTexture;

	BOOL					m_bCacheAlphaPolys;
	BOOL					m_bAnisotropicFilter;
	BOOL					m_bMustFlushOnAmbientColor;
	zD3D_alphaPoly			*immediateAlphaPolyRoot;
	zD3D_alphaPoly			*immediateAlphaPolyParent;

	static IDirectDraw7*& xd3d_pdd7;
	static IDirect3D7*& xd3d_pd3d7;
	static IDirect3DDevice7*& xd3d_pd3dDevice7;
	
	static BOOL xd3d_palsupp;
	static DWORD xd3d_actFrameNumber;
	static int zCRnd_D3D::xd3d_dd7inuse;

public:
	int XD3D_EnumerateModes(void)
	{
		XCALL(0x00643EE0);
	};

	int XD3D_InitPerDX(long,int,int,int,int)
	{
		XCALL(0x00643F20);
	};

	int XD3D_SetRenderState(_D3DRENDERSTATETYPE,unsigned long)
	{
		XCALL(0x00644EF0);
	};

	int XD3D_InitPort(int,int,int,int,int)
	{
		XCALL(0x00645150);
	};

	int XD3D_TestCapabilities(void)
	{
		XCALL(0x00647BB0);
	};

	int XD3D_SetDevice(int,int,int,int,zTRnd_ScreenMode)
	{
		XCALL(0x00648330);
	};

	void XD3D_ClearDevice(void)
	{
		XCALL(0x00648820);
	};

	int XD3D_TextureRescue(zCTex_D3D*)
	{
		XCALL(0x00648D10);
	};

	int XD3D_TextureRebuild(void)
	{
		XCALL(0x00648F00);
	};

	int XD3D_CreateWin(int,int,int)
	{
		XCALL(0x00649150);
	};

	void XD3D_CloseWin(void)
	{
		XCALL(0x006496C0);
	};

	zCRnd_D3D(void)
	{
		XCALL(0x00649800);
	};

	void EmergencyExit(void)
	{
		XCALL(0x0064A800);
	};

	void XD3D_PolyDrawOnePassVertLight(zCPolygon*)
	{
		XCALL(0x0064B470);
	};

	void XD3D_PolyDrawOnePassMultiTex(zCPolygon*)
	{
		XCALL(0x0064BA50);
	};

	void XD3D_PolyDrawTwoPassTexture(zCPolygon*)
	{
		XCALL(0x0064C110);
	};

	void XD3D_AlphaTestPoly(zCPolygon*)
	{
		XCALL(0x0064C840);
	};

	void XD3D_AlphaBlendPoly(zCPolygon*,zCMaterial*)
	{
		XCALL(0x0064C960);
	};

	void XD3D_PolyDrawTwoPassLightMap(zCPolygon*)
	{
		XCALL(0x0064D4E0);
	};

	int XD3D_SetTexture(unsigned long, IDirectDrawSurface7*)
	{
		XCALL(0x00650500);
	};

	int XD3D_DrawVertexBufferWire(zCVertexBuffer*,int,int,unsigned short*,unsigned long)
	{
		XCALL(0x00651720);
	};

	int XD3D_DrawVertexBufferFlat(zCVertexBuffer*,int,int,unsigned short*,unsigned long)
	{
		XCALL(0x006518D0);
	};

	void SetFogType(int)
	{
		XCALL(0x006520E0);
	};

	int SupportAlphaTesting(void)
	{
		XCALL(0x00652650);
	};

	unsigned short GetTexturePortableBinaryVersion(void)
	{
		XCALL(0x00652A30);
	};

	int XD3D_SetMode(int,int,int)
	{
		XCALL(0x00658850);
	};

	~zCRnd_D3D()
	{
		XCALL(0x0064A570);
	};

	void BeginFrame(void)
	{
		XCALL(0x0064DD20);
	};

	void EndFrame(void)
	{
		XCALL(0x0064DF20);
	};

	void FlushPolys(void)
	{
		XCALL(0x0064DD10);
	};

	void DrawPoly(zCPolygon*)
	{
		XCALL(0x0064B260);
	};

	void DrawLightmapList(zCPolygon**,int)
	{
		XCALL(0x0064D660);
	};

	void DrawLineD3(float,float,float,float, zCOLOR)
	{
		XCALL(0x0064D8E0);
	};

	void DrawLineZ(float,float,float,float,float,float, const zCOLOR)
	{
		XCALL(0x0064DB00);
	};

	void SetPixel(float,float,const zCOLOR)
	{
		XCALL(0x0064D720);
	};

	void DrawPolySimple(zCTexture*, zTRndSimpleVertex*,int)
	{
		XCALL(0x0064AC30);
	};

	void SetFog(const int)
	{
		XCALL(0x00651E80);
	};

	int GetFog(void)const 
	{
		XCALL(0x00652070);
	};

	void SetRadialFog(const int)
	{
		XCALL(0x00652010);
	};

	int GetRadialFog(void)const 
	{
		XCALL(0x0064A400);
	};

	void SetFogColor( zCOLOR const&)
	{
		XCALL(0x00652080);
	};

	 zCOLOR GetFogColor(void)const 
	{
		XCALL(0x006521D0);
	};

	void SetFogRange(const float nearz, const float farz, const zTRnd_FogMode falloff=zRND_FOG_FALLOFF_LINEAR)
	{
		XCALL(0x006521E0);
	};

	void GetFogRange(float&,float&,zTRnd_FogMode&)
	{
		XCALL(0x006522D0);
	};

	zTRnd_PolyDrawMode GetPolyDrawMode(void)const 
	{
		XCALL(0x00652310);
	};

	void SetPolyDrawMode(zTRnd_PolyDrawMode const&)
	{
		XCALL(0x00652300);
	};

	virtual BOOL GetSurfaceLost() const
	{
		return m_bSurfaceLost;
	};

	virtual void SetSurfaceLost(const BOOL b)
	{
		m_bSurfaceLost = b;
	};

	virtual BOOL GetSyncOnAmbientCol() const
	{
		return m_bMustFlushOnAmbientColor;
	};

	virtual void SetSyncOnAmbientCol(const BOOL b)
	{
		m_bMustFlushOnAmbientColor = b;
	};

	void SetTextureWrapEnabled(const BOOL b)
	{
		XCALL(0x00652320);
	};

	int GetTextureWrapEnabled(void)const 
	{
		XCALL(0x00652330);
	};

	void SetBilerpFilterEnabled(const BOOL b)
	{
		XCALL(0x00652340);
	};

	int GetBilerpFilterEnabled(void)const 
	{
		XCALL(0x006523D0);
	};

	void SetDitherEnabled(const BOOL b)
	{
		XCALL(0x006523E0);
	};

	int GetDitherEnabled(void)const 
	{
		XCALL(0x006523F0);
	};

	zTRnd_PolySortMode GetPolySortMode(void)const 
	{
		XCALL(0x006524D0);
	};

	void SetPolySortMode(zTRnd_PolySortMode const&)
	{
		XCALL(0x00652400);
	};

	int GetZBufferWriteEnabled(void)const 
	{
		XCALL(0x00652520);
	};

	void SetZBufferWriteEnabled(const int)
	{
		XCALL(0x006524E0);
	};

	void SetZBias(const int)
	{
		XCALL(0x006529E0);
	};

	int GetZBias(void)const 
	{
		XCALL(0x006529D0);
	};

	zTRnd_ZBufferCmp GetZBufferCompare(void)
	{
		XCALL(0x006525C0);
	};

	void SetZBufferCompare(zTRnd_ZBufferCmp const&)
	{
		XCALL(0x00652530);
	};

	int GetPixelWriteEnabled(void)const 
	{
		XCALL(0x006525E0);
	};

	void SetPixelWriteEnabled(const int)
	{
		XCALL(0x006525D0);
	};

	void SetAlphaBlendSource(zTRnd_AlphaBlendSource const&)
	{
		XCALL(0x006525F0);
	};

	zTRnd_AlphaBlendSource GetAlphaBlendSource(void)const 
	{
		XCALL(0x00652600);
	};

	void SetAlphaBlendFunc(zTRnd_AlphaBlendFunc const&)
	{
		XCALL(0x00652610);
	};

	zTRnd_AlphaBlendFunc GetAlphaBlendFunc(void)const 
	{
		XCALL(0x00652620);
	};

	float GetAlphaBlendFactor(void)const 
	{
		XCALL(0x00652640);
	};

	void SetAlphaBlendFactor(float const&)
	{
		XCALL(0x00652630);
	};

	void SetAlphaReference(const unsigned long)
	{
		XCALL(0x0064A420);
	};

	unsigned long GetAlphaReference(void)const 
	{
		XCALL(0x0064A430);
	};

	int GetCacheAlphaPolys(void)const 
	{
		XCALL(0x0064A450);
	};

	void SetCacheAlphaPolys(const int)
	{
		XCALL(0x0064A460);
	};

	int GetAlphaLimitReached(void)const 
	{
		XCALL(0x0064A440);
	};

	void AddAlphaPoly(zCPolygon const*)
	{
		XCALL(0x0064CD60);
	};

	void FlushAlphaPolys(void)
	{
		XCALL(0x0064D400);
	};

	void SetRenderMode(const zTRnd_RenderMode)
	{
		XCALL(0x00652660);
	};

	zTRnd_RenderMode GetRenderMode(void)const 
	{
		XCALL(0x00652840);
	};

	int HasCapability(const zTRnd_Capability)const 
	{
		XCALL(0x00652850);
	};

	void GetGuardBandBorders(float&,float&,float&,float&)
	{
		XCALL(0x00652A40);
	};

	void ResetZTest(void)
	{
		XCALL(0x006529B0);
	};

	int HasPassedZTest(void)
	{
		XCALL(0x006529C0);
	};

	zCTexture* CreateTexture(void)
	{
		XCALL(0x00653650);
	};

	zCTextureConvert* CreateTextureConvert(void)
	{
		XCALL(0x006537D0);
	};

	int GetTotalTextureMem(void)
	{
		XCALL(0x006536D0);
	};

	int SupportsTextureFormat(const zTRnd_TextureFormat)
	{
		XCALL(0x006536E0);
	};

	int SupportsTextureFormatHardware(const zTRnd_TextureFormat)
	{
		XCALL(0x00653770);
	};

	int GetMaxTextureSize(void)
	{
		XCALL(0x006537C0);
	};

	void GetStatistics( zTRnd_Stats&)
	{
		XCALL(0x00652AB0);
	};

	void ResetStatistics(void)
	{
		XCALL(0x00652B00);
	};

	void Vid_Blit(int, tagRECT*, tagRECT*)
	{
		XCALL(0x00657670);
	};

	void Vid_Clear( zCOLOR&,int)
	{
		XCALL(0x00657E20);
	};

	int Vid_Lock( zTRndSurfaceDesc&)
	{
		XCALL(0x00657950);
	};

	int Vid_Unlock(void)
	{
		XCALL(0x00657A00);
	};

	int Vid_IsLocked(void)
	{
		XCALL(0x0064A4B0);
	};

	int Vid_GetFrontBufferCopy(zCTextureConvert&)
	{
		XCALL(0x00657A40);
	};

	int Vid_GetNumDevices(void)
	{
		XCALL(0x00657EA0);
	};

	int Vid_GetActiveDeviceNr(void)
	{
		XCALL(0x00657EB0);
	};

	int Vid_SetDevice(int)
	{
		XCALL(0x00657EC0);
	};

	int Vid_GetDeviceInfo( zTRnd_DeviceInfo&,int)
	{
		XCALL(0x00658190);
	};

	int Vid_GetNumModes(void)
	{
		XCALL(0x006583B0);
	};

	int Vid_GetModeInfo( zTRnd_VidModeInfo&,int)
	{
		XCALL(0x006583C0);
	};

	int Vid_GetActiveModeNr(void)
	{
		XCALL(0x00658600);
	};

	int Vid_SetMode(int, HWND__**)
	{
		XCALL(0x00658610);
	};

	void Vid_SetScreenMode(zTRnd_ScreenMode)
	{
		XCALL(0x00658BA0);
	};

	zTRnd_ScreenMode Vid_GetScreenMode(void)
	{
		XCALL(0x00658FB0);
	};

	void Vid_SetGammaCorrection(float,float,float)
	{
		XCALL(0x00658FC0);
	};

	float Vid_GetGammaCorrection(void)
	{
		XCALL(0x00659610);
	};

	void Vid_BeginLfbAccess(void)
	{
		XCALL(0x00651D90);
	};

	void Vid_EndLfbAccess(void)
	{
		XCALL(0x0064A4C0);
	};

	void Vid_SetLfbAlpha(int)
	{
		XCALL(0x0064A4D0);
	};

	void Vid_SetLfbAlphaFunc(zTRnd_AlphaBlendFunc const&)
	{
		XCALL(0x0064A4E0);
	};

	int SetTransform(zTRnd_TrafoType,zMAT4 const&)
	{
		XCALL(0x0064ED50);
	};

	int SetViewport(int,int,int,int)
	{
		XCALL(0x0064F100);
	};

	int SetLight(unsigned long,zCRenderLight*)
	{
		XCALL(0x0064F700);
	};

	int GetMaterial( zCRenderer::zTMaterial&)
	{
		XCALL(0x006504B0);
	};

	int SetMaterial( zCRenderer::zTMaterial const&)
	{
		XCALL(0x006503B0);
	};

	int SetTexture(unsigned long,zCTexture*)
	{
		XCALL(0x00650560);
	};

	int SetTextureStageState(unsigned long,zTRnd_TextureStageState,unsigned long)
	{
		XCALL(0x00650630);
	};

	int SetAlphaBlendFuncImmed(const zTRnd_AlphaBlendFunc)
	{
		XCALL(0x006506D0);
	};

	int SetRenderState(zTRnd_RenderStateType,unsigned long)
	{
		XCALL(0x006508F0);
	};

	unsigned long GetRenderState(zTRnd_RenderStateType)
	{
		XCALL(0x00650960);
	};

	void AddAlphaSortObject(zCRndAlphaSortObject*)
	{
		XCALL(0x00650990);
	};

	void RenderAlphaSortList(void)
	{
		XCALL(0x00650A60);
	};

	int DrawVertexBuffer(zCVertexBuffer*,int,int,unsigned short*,unsigned long)
	{
		XCALL(0x006519F0);
	};

	zCVertexBuffer* CreateVertexBuffer(void)
	{
		XCALL(0x00651DD0);
	};
};

class zCSurfaceCache_D3D
{
	friend class zCRnd_D3D;
	friend class zCTex_D3D;
protected:
	struct zCSlotIndex
	{
		int						dynamic;
		int						pixelformat;
		int						mipmaps;
		int						width;
		int						height;
	};

	struct zD3D_Entry
	{
		IDirectDrawSurface7		*surface;
		unsigned long			frameNumber;
		zD3D_Entry				*nextEntry;
	};

	struct zD3D_SlotHeader
	{
		zD3D_Entry				*firstEntry;
		zD3D_Entry				*lastEntry;
	};

public:
	static void ResetSurfaceList(void)
	{
		XCALL(0x00647760);
	};

	zCSurfaceCache_D3D(void)
	{
		XCALL(0x00652B50);
	};

	~zCSurfaceCache_D3D(void)
	{
		XCALL(0x00652B80);
	};

	int CacheInSurface( IDirectDrawSurface7*,zCSlotIndex*)
	{
		XCALL(0x00652B90);
	};

	IDirectDrawSurface7* CacheOutSurface(zCSlotIndex*)
	{
		XCALL(0x00652F40);
	};

	void ClearCache(void)
	{
		XCALL(0x006532D0);
	};
private:
	int						xsc_cacheentryCounter;
	zD3D_SlotHeader			xsc_slot[2][6][12][12][12];

	static  zD3D_SlotHeader** xsc_listofsurfaces; 
	
	
	

	static int xsc_listposition;
	
	
	

	void XSC_ClearSlot(zD3D_SlotHeader*)
	{
		XCALL(0x006533D0);
	};

	void XSC_KillLastSurfaceInSlot(zD3D_SlotHeader*)
	{
		XCALL(0x00653500);
	};
};


class zCDXTCCache_D3D
{
public:

	zCDXTCCache_D3D(void)
	{
		XCALL(0x00642F10);
	};

	~zCDXTCCache_D3D(void)
	{
		XCALL(0x00642F40);
	};

	IDirectDrawSurface7* Lock(int,int,int)
	{
		XCALL(0x00642F50);
	};

	int Unlock(int,int,int, IDirectDrawSurface7*)
	{
		XCALL(0x00643040);
	};

	void ClearCache(void)
	{
		XCALL(0x00643170);
	};

private:
	struct zD3D_Entry
	{
		IDirectDrawSurface7		*surface;
		BOOL					locked;
		zD3D_Entry				*nextEntry;
	};
	struct zD3D_SlotHeader
	{
		zD3D_Entry				*firstEntry;
		zD3D_Entry				*lastEntry;
	};

	int						xdxtc_cacheentryCounter;
	zD3D_SlotHeader			xdxtc_slot[2][12][12];

	IDirectDrawSurface7* XDXTC_CreateSurface(int,int,int, zCDXTCCache_D3D::zD3D_Entry*)
	{
		XCALL(0x00643470);
	};
};


struct zD3D_savedTexture
{
	zCTex_D3D				*texture;
	zCTextureConvert*		texCon;
	zD3D_savedTexture		*next; 
}; 


class zCTex_D3D : public zCTexture 
{
public:
	zCTex_D3D();
	~zCTex_D3D();

	BOOL					Lock					( int m=0 );
	BOOL					Unlock					();
	void					InsertTexture			( BOOL palsupp, int stage = 0 );
	BOOL					RemoveTexture			();
	void					ReleaseData				();
	void					GetPixelSize			( int& xdim, int &ydim );
	BOOL					SetTextureInfo			( const zCTextureInfo& texInfo );
	BOOL					GetTextureBuffer		( int mipMapNr, void* &buffer, int &pitchXBytes );

	void*					GetPaletteBuffer		();
	zCTextureInfo			GetTextureInfo			();
	BOOL					CopyPaletteDataTo		( void* destBuffer );
	BOOL					CopyTextureDataTo		( int mipMapNr, void* destBuffer, int destPitchXBytes );
	BOOL					HasAlpha				() const	{ return xtex_alphaTex; };			

	BOOL					PreloadTexture			();
	BOOL					SetTexture				( int stage );

	inline unsigned long	GetLastFrameUsed		() const	{ return xtex_lastFrameUsed;							};	
	void					SetLastFrameUsed		()			{ xtex_lastFrameUsed = zCRnd_D3D::xd3d_actFrameNumber;	};	

	BOOL					RescueTexture			( zD3D_savedTexture *slm );
	BOOL					RebuildTexture			( zD3D_savedTexture *slm );

private:
	unsigned int			xtex_textureflag;
	struct
	{
		int											: 17; 
		BOOL			xtex_decompress				: 1;
		BOOL			xtex_locked					: 1;
		BOOL			xtex_palsupport				: 1;
		unsigned int	xtex_miplocked				: 12;
	};
	zCTextureInfo			xtex_texinfo;
	zCSurfaceCache_D3D::zCSlotIndex	
							xtex_slotindex;
	unsigned char			*xtex_pPalettePtr;
	IDirectDrawPalette		*xtex_pddpal;
	int						xtex_internalnumber;
	BOOL					xtex_alphaTex;
	IDirectDrawSurface7		*xtex_pddtex[12];
	IDirectDrawSurface7		*xtex_pddtemporarytex[12]; 
	unsigned long			xtex_lastFrameUsed;
	void					*xtex_buffer;

	BOOL					XTEX_BuildSurfaces( BOOL decompressBuild );
};

