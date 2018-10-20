#pragma once

#include "zcvob.h"
#include "zcvisual.h"

class zCMaterial;
class zCVertex;

enum zTPolyStrip_AlignMode
{
	
	zPOLYSTRIP_ALIGN_NONE        = 0,

	
	zPOLYSTRIP_ALIGN_SINGLE_DIR  = 1,

	
	zPOLYSTRIP_ALIGN_MULTI_DIR   = 2
};


class zCPolyStrip : public zCVisual		
{
public:
	zCLASS(zCPolyStrip)
	friend class zCParticleFX;
	friend class zCBspTree;
	friend class oCBarrier;
	friend class oCVisualFX;
	friend class zCFlash;
	
	enum zTCamAlign
	{
		zCAM_ALIGN_NONE,	
		zCAM_ALIGN_STRIP,	
		zCAM_ALIGN_POLY		
	};
public:
	zCMaterial			*material;				
				
	zCVertex			*vertList;
	zCPolygon			*polyList;
	int					numPoly;
	int					numVert;	
	zVEC3				*centerPointList;
	float				*alphaList;
	float				width;
	zCVob				*connectedVob;
	zTBBox3D			bbox3D;
	zTCamAlign			camAlign;
	BOOL				heightCheck;
	BOOL				everyFrameUpdate;
	float				heightBound;
	
	int					firstSeg;
	int					lastSeg;
	int					numSeg;
	
	float				visLastFrac;
	float				visFirstFrac;
	
	float				alphaFadeSpeed;
	float				newAlphaFadeSpeed;
	float				newAlpha;
	int					lastDirSeg;					
	zVEC3				lastDirNormal;
	struct
	{
		UINT8			localFOR			: 1;
	};

	static zCClassDef *classDef;

	virtual zCClassDef* _GetClassDef			()const							{XCALL(0x004CA100);};
	
	BOOL				Render					(zTRenderContext& renderContext){XCALL(0x005BDC70);};
	BOOL				IsBBox3DLocal			()								{XCALL(0x005BD590);};
	zTBBox3D			GetBBox3D				()								{XCALL(0x005BD5A0);};
	zSTRING				GetVisualName			()								{XCALL(0x004CA110);};
	void				SetVisualUsedBy			(zCVob* vob)					{XCALL(0x005BD840);};
	virtual void		FreeResources			()								{XCALL(0x005BDAE0);};
	virtual				~zCPolyStrip			()								{XCALL(0x005BD480);};


	void zPolyStrip(void)
	{
		XCALL(0x005BD300);
	};

	zCPolyStrip(void)
	{
		zPolyStrip();
	};

	void CalcBBox3D(void)
	{
		XCALL(0x005BD6C0);
	};

	void EmptyEffect(void)
	{
		XCALL(0x005BD860);
	};

	void AllocateResources(int)
	{
		XCALL(0x005BD890);
	};

	void SetVisibleSegments(float,float)
	{
		XCALL(0x005BDB90);
	};

	void AddSegment(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005BE2B0);
	};

	void AddSegment(zVEC3 const&)
	{
		XCALL(0x005BE430);
	};

	void AddSegmentSmart(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005BE500);
	};

	void UpdateSegment(int,zVEC3 const&,zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005BE760);
	};

	void UpdateSegmentAlpha(int,float)
	{
		XCALL(0x005BE7E0);
	};

	void AlignToCamera(void)
	{
		XCALL(0x005BE800);
	};

	void ProjectToSphere( zTBSphere3D const&)
	{
		XCALL(0x005BEC90);
	};

	void Lightning0Subdivide(zVEC3 const&,zVEC3 const&,float,int)
	{
		XCALL(0x005BEDB0);
	};

	void GenerateCPLightning0(zVEC3 const&,zVEC3 const&,float)
	{
		XCALL(0x005BEF40);
	};

	void GenerateCircle( zTBSphere3D const&,zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005BF090);
	};
};