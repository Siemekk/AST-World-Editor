#pragma once

#include "ztypes3D.h"
#include "zcobject.h"

class zCVertexBuffer;
class zCVertexTransform;



enum zTVBufferPrimitiveType : BYTE
{
	zBPT_TRIANGLELIST,		
	zBPT_TRIANGLESTRIP,		
	zBPT_TRIANGLEFAN,		
	zBPT_POINTLIST,			
	zBPT_LINELIST,			
	zBPT_LINESTRIP			
};

enum zTVBufferVertexType : BYTE
{
	zBVT_NORMAL,			
	zBVT_DIFFUSE,			
	zBVT_XYZRHW				
};



struct zTVBCallback			
{
	BOOL (*m_pfProg)(zCVertexBuffer*, void*);		
	void*		m_pObject;							
};



enum zTVBufferVertexComponent
{
	zBVC_BASE    = 0,
	zBVC_XYZ     = 1,
	zBVC_XYZRHW  = 2,
	zBVC_NORMAL  = 3,
	zBVC_DIFFUSE = 4,
	zBVC_TEX1    = 5,
	zBVC_TEX2    = 6,
	zBVC_TEX3    = 7,
	zBVC_TEX4    = 8,
	zBVC_MAX     = 9
};



class zCVertexBuffer : public zCObject						
{
	ULONG					m_nNumVertsAlloc;				
	ULONG					m_nVertexFullSize;				
	VOID*					m_pVertexComponent[zBVC_MAX];	
	ULONG					m_nNumVertsInUse;				
	ULONG					m_nVBCaps;						
	zCArray<zTVBCallback>	m_arrVBCallback;				
	DWORD					m_nCtorCtr;						
public:
	static zCClassDef *classDef;
	static DWORD s_classCtorCtr; 
	void SetXYZ(unsigned long,zVEC3 const&)
	{
		XCALL(0x005CCDA0);
	};

	zCVertexBuffer(void)
	{
		XCALL(0x005FBD40);
	};

	void AddRecreateLostVBCallback(int (__cdecl*)(zCVertexBuffer*,void*),void*)
	{
		XCALL(0x005FBFF0);
	};

	void RemoveRecreateLostVBCallback(int (__cdecl*)(zCVertexBuffer*,void*),void*)
	{
		XCALL(0x005FC100);
	};

	int CallRecreateLostVBCallbacks(void)
	{
		XCALL(0x005FC160);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005FBE60);
	};

	virtual ~zCVertexBuffer(void)
	{
		XCALL(0x005FBF50);
	};

	virtual int Create(unsigned long,unsigned long,unsigned long)
	{
		XCALL(0x005FBE70);
	};

	virtual int Destroy(void)
	{
		XCALL(0x005FBE80);
	};

	virtual int Lock(unsigned long)
	{
		XCALL(0x005FBE90);
	};

	virtual int Unlock(void)
	{
		XCALL(0x005FBEA0);
	};

	virtual int IsLocked(void)
	{
		XCALL(0x005FBEB0);
	};

	virtual int Optimize(void)
	{
		XCALL(0x005FBEC0);
	};

	virtual int SetPrimitiveType(zTVBufferPrimitiveType)
	{
		XCALL(0x005FBED0);
	};

	virtual zTVBufferPrimitiveType GetPrimitiveType(void)
	{
		XCALL(0x005FBEE0);
	};

	virtual unsigned long GetVertexFormat(void)
	{
		XCALL(0x005FBEF0);
	};

	virtual zTVBufferVertexType GetVertexType(void)
	{
		XCALL(0x005FBF00);
	};

	virtual int SetIndexList(zCArray<unsigned short> const&)
	{
		XCALL(0x005FBF10);
	};

	virtual int SetIndexListSize(unsigned long)
	{
		XCALL(0x005FBF20);
	};

	virtual unsigned long GetIndexListSize(void)
	{
		XCALL(0x005FBF30);
	};

	virtual unsigned short* GetIndexListPtr(void)
	{
		XCALL(0x005FBF40);
	};	
};



#define zVFORMAT_XYZ			0x1
#define zVFORMAT_XYZRHW			0x2
#define zVFORMAT_NORMAL			0x4
#define zVFORMAT_DIFFUSE		0x8
#define zVFORMAT_TEX1			0x10
#define zVFORMAT_TEX2			0x20
#define zVFORMAT_TEX3			0x40
#define zVFORMAT_TEX4			0x80

#define zVCAPS_DONOTCLIP		0x1
#define zVCAPS_SYSTEMMEMORY		0x4
#define zVCAPS_WRITEONLY		0x8

#define zVLOCK_READONLY			0x1
#define zVLOCK_WAIT				0x4
#define zVLOCK_WRITEONLY		0x8
#define zVLOCK_DISCARDCONTENTS	0x10
#define zVLOCK_NOOVERWRITE		0x20
#define zVLOCK_NOSYSLOCK		0x40

#define ALPHAVERTEXBUFFERSIZE			1024
#define zPM_NUM_VBUFFER_VERT			4096

class zCVertexBufferDyn			
{
	zCVertexBuffer*		m_pVertBuf;			
	DWORD				m_dwFlagsVB;		
	DWORD				m_nNumVertsAlloc;	
	DWORD				m_nVertexFullSize;	
	DWORD				m_nNumVertInUse;	
	BOOL				m_bLock;			
	BOOL				m_bOverflow;		
public:
	zCVertexBufferDyn(unsigned long,unsigned long)
	{
		XCALL(0x005FC2C0);
	};

	~zCVertexBufferDyn(void)
	{
		XCALL(0x005FC310);
	};

	void* Lock(unsigned long,unsigned long&)
	{
		XCALL(0x005FC350);
	};

	void Unlock(void)
	{
		XCALL(0x005FC3D0);
	};
};



class zCVertexBufferDyn2		
{
	zCVertexBuffer*		m_pVertBuf;		
	DWORD				m_dwFlagsVB;	
	DWORD				m_nNumVertsAlloc;		
	DWORD				m_nVertexFullSize;	
	DWORD				m_nNumVertsInUse;	
	BOOL				m_bLock;		
	BOOL				m_bOverflow;	
public:
	zCVertexBufferDyn2(unsigned long,unsigned long)
	{
		XCALL(0x005FC3F0);
	};

	~zCVertexBufferDyn2(void)
	{
		XCALL(0x005FC440);
	};

	void ReserveVerts(unsigned long)
	{
		XCALL(0x005FC490);
	};

	void* Lock(unsigned long&)
	{
		XCALL(0x005FC4B0);
	};

	void Unlock(unsigned long)
	{
		XCALL(0x005FC510);
	};
};



class zCVertexBufferManager
{
	zCArray<zCVertexBuffer*>	m_arrOpenVB;		
	zCArray<zCVertexBuffer*>	m_arrOptimizeVB;	
	BOOL						m_bPrealloc;		
public:
	zCVertexBufferManager(void)
	{
		XCALL(0x005FC570);
	};

	~zCVertexBufferManager(void)
	{
		XCALL(0x005FC5A0);
	};

	zCVertexBuffer* AcquireVertexBuffer(unsigned long,unsigned long,unsigned long,unsigned long,int&)
	{
		XCALL(0x005FC600);
	};

	int ReleaseVertexBuffer(zCVertexBuffer*)
	{
		XCALL(0x005FC970);
	};

	void UnlockOpenVertexBuffers(void)
	{
		XCALL(0x005FCA30);
	};

	void StartChangeWorld(void)
	{
		XCALL(0x005FCC30);
	};

	void EndChangeWorld(void)
	{
		XCALL(0x005FCC40);
	};
};






