#pragma once

#include "ztypes.h"

class zCBspNode;
class zCBspLeaf;
class zCBspSector;
class zCCBspTree;
class zCVob;
class zCVobLight;
class zCBspSector;
class zCBspBase;
class zCMesh;
class zCPolygon;
class zTPlane;

enum zTBspTreeMode    
{   
	zBSP_MODE_INDOOR, 
	zBSP_MODE_OUTDOOR, 
	zBSP_MODE_FORCEINT	= 0x7FFFFFFF
};


enum zTWld_RenderMode
{ 
	zWLD_RENDER_MODE_VERT_LIGHT,        
	zWLD_RENDER_MODE_LIGHTMAPS,
	zWLD_RENDER_MODE_FORCEINT	= 0x7FFFFFFF
};

enum zTBspType
{
	zTBSP_NODE,		
	zTBSP_LEAF		
};

class zCBspBase							
{
	zCBspBase*		m_pParentBase;		
	zTBBox3D		m_bbVolume;			
	zCPolygon**		m_ppPolygon;		
	int				m_nNumberPolys;		
	zTBspType		m_BspType;			
public:
	void	__fastcall		CollectVobsInBBox3D			(zCArray<zCVob*>& resVobList, const zTBBox3D& inbbox3D) const
	{
		XCALL(0x00531110);
	};
};


class zCCBspNode						
{
    float				distance;
    zVEC3				normal;
	zCCBspNode*			m_pFrontNode;	
	zCCBspNode*			m_pBackNode;	
	zCCBspNode*			m_pOwnerNode;	
	zTBBox3D			m_bbVolume;		
	zTBBox3D			m_bbCell;		
	int					m_lstPolyNodes;	
	int					m_nLODNodes;	
};


class zCBspLeaf	: public zCBspBase	
{
public:
	int						us28;
	zCArray<zCVob*>			m_arrVobs;		
	zCArray<zCVobLight*>	m_arrVobLight;	
	int						m_nFrameIndex;	
	WORD					m_nSectorIndex;	
	WORD					m_nRefPluecker;	
	void*					m_pPluecker;	
	zVEC3					m_vLightPos;	
};


class zCCBspTree : public zCCBspNode	
{
public:
	zCMesh*					m_pMesh;		
	zTBspTreeMode			m_RenderMode;	
	zCArray<zCBspSector*>	m_arrSectors;	
	int						s6C;
	int						us70;
	int						us74;
	int						s78;
	float					m_fBuildFactor;	
	float					s80;
	float					s84;
	float					s88;
	BOOL					m_bPortalize;	
	zCMesh* GetBspMesh()
	{
		return *(zCMesh**)(((char *)this) + 0x54);
	};

};


class zCBspTree
{
public:
	zCBspNode*				actNodePtr;
	zCBspLeaf*				actLeafPtr;

	zCBspBase*				bspRoot;
	zCMesh*					m_pMesh;
	zCPolygon**				m_ppTreePolyList;
	zCBspNode*				nodeList;
	zCBspLeaf*				m_pLeafList;
	int						numNodes;   
	int						m_nLeafSize;     
	int						m_nNumPolys;       

	zCArray<zCVob*>			renderVobList;
	zCArray<zCVobLight*>    renderLightList;
	zCArray<zCBspSector*>	sectorList;
	zCArray<zCPolygon*>     portalList;                                                

	zTBspTreeMode			bspTreeMode; 
	zTWld_RenderMode		worldRenderMode;
	float					vobFarClipZ;             

	struct zTPlane
	{
		float distance;
		zVEC3 normal;
	};

	zTPlane					vobFarPlane;
	int						vobFarPlaneSignbits;                       
	int 					drawVobBBox3D;            
	int 					leafsRendered;                  
	int 					vobsRendered;                
	int 					m_bRenderedFirstTime;        
	zTFrameCtr 				masterFrameCtr;
	zCPolygon** 			actPolyPtr;
	int 					compiled;
	zCBspBase*				GetRoot					() const				{ return bspRoot; };
};
