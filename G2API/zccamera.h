#pragma once

#include "zcview.h"
#include "zbvolume.h"


class zCViewBase;
class zCPolygon;
class zCMesh;
class zCMaterial;
class zTPlane;
class zCVob;

enum zTShadeMode 
{
	zSHADE_NORMAL,
	zSHADE_NOTHING,
	zSHADE_CONSTANT,
	zSHADE_GOURAUD,
	zSHADE_LIGHTMAP
};

enum zTCam_DrawMode
{
	zCAM_DRAW_NORMAL,
	zCAM_DRAW_NOTHING,
	zCAM_DRAW_WIRE,
	zCAM_DRAW_FLAT,
	zCAM_DRAW_TEX
};

enum zPROJECTION
{
	PERSPECTIVE,
	ORTHOGONAL
};

enum zTCam_AlignType
{
	zCAM_ALIGN_NONE,
	zCAM_ALIGN_YAW,
	zCAM_ALIGN_FULL
};

enum zTCam_ClipType
{
	zCAM_CLIP_CROSS,
	zCAM_CLIP_INSIDE,
	zCAM_CLIP_OUTSIDE
};

enum zTCamTrafoType
{
	zCAM_TRAFO_ROTATE,
	zCAM_TRAFO_WORLD,
	zCAM_TRAFO_NORMAL,
	zCAM_TRAFO_LINEAR,
	zCAM_TRAFO_LINEAR_WORLD
};

class zCVertexTransform;

struct zTViewportData
{					
	int			xmin;					
	int			ymin;
	int			xdim;					
	int			ydim;
	float		xminFloat;				
	float		yminFloat;
	float		xmaxFloat;				
	float		ymaxFloat;
	float		xdimFloat;				
	float		ydimFloat;
	float		xdimFloatMinus1;
	float		ydimFloatMinus1;
	float		xcenter;			
	float		ycenter;			
};

template <class T, int SIZE> class zCMatrixStack {
    int		pos;
    T		stack[SIZE];
public:
    zCMatrixStack() : pos(0) {};
    void Push(const T& m)
	{
        
        stack[pos++] = m;
    };
    T Pop(void)
	{
        
        return stack[--pos];
    };
};

class zCCamera
{
public:
	
	enum
	{ 
		CLIP_FLAGS_FULL			= 63,
		CLIP_FLAGS_FULL_WO_FAR	= 15
	};

	enum
	{ 
		NUM_FRUSTUM_PLANES			=  6,
		NUM_FRUSTUM_PLANES_WO_FAR	=  4
	};

	
	zTPlane			frustumplanes	[NUM_FRUSTUM_PLANES];
	BYTE			signbits		[NUM_FRUSTUM_PLANES];						

	
	zTViewportData	vpData;
	zCViewBase		*targetView;

	
	zMAT4		camMatrix;				
	zMAT4		camMatrixInv;			
	
	struct zTCamVertSimple
	{
		float		x,y,z;		
		zVEC2		texuv;
		zCOLOR		color;
	};

	BOOL			tremorToggle;
	float			tremorScale;
	zVEC3			tremorAmplitude;
	zVEC3			tremorOrigin;
	float			tremorVelo;

	
	zMAT4		trafoView;
	zMAT4		trafoViewInv;
	zMAT4		trafoWorld;
	zCMatrixStack<zMAT4,8>	trafoViewStack;
	zCMatrixStack<zMAT4,8>	trafoWorldStack;
	zCMatrixStack<zMAT4,8>	trafoWorldViewStack;
	zMAT4		trafoProjection;

	
	enum
	{
		zTCAM_POLY_NUM_VERT = 4
	};

	zTCamVertSimple polyCamVerts[zTCAM_POLY_NUM_VERT];
	zCPolygon		*poly;
	zCMesh			*polyMesh;
	zCMaterial		*polyMaterial;

	
	BOOL			screenFadeEnabled;
	zCOLOR			screenFadeColor;
	zSTRING			screenFadeTexture;
	float			screenFadeTextureAniFPS;
	zTRnd_AlphaBlendFunc screenFadeTextureBlendFunc;
	BOOL			cinemaScopeEnabled;
	zCOLOR			cinemaScopeColor;

	
	zPROJECTION		projection;
	zTCam_DrawMode	drawMode;
	zTShadeMode		shadeMode;
	BOOL			drawWire;

	
	float			farClipZ;
	float			nearClipZ;
	float			viewDistanceX;
	float			viewDistanceY;
	float			viewDistanceXInv;
	float			viewDistanceYInv;
	BOOL			vobFarClipZ;
	float			fovH;				
	float			fovV;
	zCVob			*connectedVob;
	

	float			topBottomSin, topBottomCos;
	float			leftRightSin, leftRightCos;
public:
	static zVEC3 activeCamPos;
	static zCCamera*& activeCam;
public:
	zPOINT3				Transform				(const zPOINT3& point) const	{ return camMatrix * point; };
	void Project(zVEC3 const* const,float&,float&)const 
	{
		XCALL(0x00530030);
	};

	zCCamera(void)
	{
		XCALL(0x00549E60);
	};

	~zCCamera(void)
	{
		XCALL(0x0054A290);
	};

	void PushTransform(zTCamTrafoType)
	{
		XCALL(0x0054A370);
	};

	void PopTransform(zTCamTrafoType)
	{
		XCALL(0x0054A400);
	};

	void SetTransform(zTCamTrafoType,zMAT4 const&)
	{
		XCALL(0x0054A540);
	};

	zMAT4 const& GetTransform(zTCamTrafoType)
	{
		XCALL(0x0054A6A0);
	};

	void Activate(void)
	{
		XCALL(0x0054A700);
	};

	void CreateProjectionMatrix(zMAT4&,float,float,float,float)
	{
		XCALL(0x0054A810);
	};

	void UpdateProjectionMatrix(void)
	{
		XCALL(0x0054A890);
	};

	float GetFOV(void)const 
	{
		XCALL(0x0054A8E0);
	};

	void GetFOV(float&,float&)const 
	{
		XCALL(0x0054A8F0);
	};

	void SetFOV(float)
	{
		XCALL(0x0054A920);
	};

	void SetFOV(float,float)
	{
		XCALL(0x0054A960);
	};

	void UpdateViewport(void)
	{
		XCALL(0x0054AA90);
	};

	void SetRenderTarget(zCViewBase*)
	{
		XCALL(0x0054ABD0);
	};

	void SetRenderScreenFadeTex(zSTRING)
	{
		XCALL(0x0054ABF0);
	};

	void SetUpFrustum(void)
	{
		XCALL(0x0054AD20);
	};

	void SetFarClipZ(float)
	{
		XCALL(0x0054B200);
	};

	zTCam_ClipType BBox3DInFrustum( zTBBox3D const&)
	{
		XCALL(0x0054B3B0);
	};

	zTCam_ClipType BBox3DInFrustum( zTBBox3D const&,int&)
	{
		XCALL(0x0054B410);
	};

	void StopTremor(void)
	{
		XCALL(0x0054B650);
	};

	void AddTremor(zVEC3 const&,float,float,zVEC3 const&)
	{
		XCALL(0x0054B660);
	};

	void PreRenderProcessing(void)
	{
		XCALL(0x0054B7D0);
	};

	void PostRenderProcessing(void)
	{
		XCALL(0x0054B920);
	};

	void GetCamPos(zVEC3&)const 
	{
		XCALL(0x0054B960);
	};

	void InitDrawPolySimple(void)
	{
		XCALL(0x0054B990);
	};

	void CleanupDrawPolySimple(void)
	{
		XCALL(0x0054BA50);
	};

	void DrawPolySimple( zCCamera::zTCamVertSimple*,int,zCMaterial*,int)
	{
		XCALL(0x0054BAB0);
	};

	void SetRenderScreenFade( zCOLOR)
	{
		XCALL(0x0054BBC0);
	};

	void SetRenderScreenFadeTexAniFPS(float)
	{
		XCALL(0x0054BBE0);
	};

	void SetRenderScreenFadeTexBlendFunc(zTRnd_AlphaBlendFunc)
	{
		XCALL(0x0054BC10);
	};

	void SetRenderCinemaScope( zCOLOR)
	{
		XCALL(0x0054BC20);
	};

	void RenderScreenFade(void)
	{
		XCALL(0x0054BC40);
	};

	void RenderCinemaScope(void)
	{
		XCALL(0x0054BD30);
	};

	int __fastcall ScreenProjectionTouchesPortalRough( zTBBox3D const&, zTBBox2D const&)
	{
		XCALL(0x0054BE80);
	};

	int __fastcall ScreenProjectionTouchesPortal( zTBBox3D const&, zTBBox2D const&)
	{
		XCALL(0x0054C100);
	};

	void ProjectClamp(zCVertexTransform*,float)const 
	{
		XCALL(0x0056BD00);
	};

	void Project(zVEC3 const* const,int&,int&)
	{
		XCALL(0x0057A440);
	};

	void Project(zVEC3 const* const,float,float&,float&)const 
	{
		XCALL(0x00604ED0);
	};

	zCVob* GetCamVob()
	{
		return *(zCVob**)(((char *)this) + 0x920); 
	};

	float GetFarClipZ()
	{
		return *(float*)(((char *)this) + 0x8FC); 
	};

	// [AST]
	void SetFOV_AST(float);
	void SetFOV_AST(float, float);
	// [/AST]
};

