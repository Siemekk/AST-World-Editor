#pragma once

#include "zctexture.h"
#include "zRndD3D_SurfaceCache.h"

struct zD3D_savedTexture;

class zCTex_D3D : public zCTexture							
{
	friend class zCRnd_D3D;
	friend class zD3D_alphaPoly;

	struct BIT_ARRAY
	{
		DWORD			ut0:17;				
		DWORD			tDXTCSurfaces:1;	
		DWORD			tLock:1;			
		DWORD			tPalette:1;			
		DWORD			tUseSurfaces:12;	
	};
	int								m_nCreateCode;			
	union
	{
		DWORD			m_dwFlags;							
		BIT_ARRAY		ff;
	};
	zCTextureInfo					m_TexInfo;				
	zCSurfaceCache_D3D::zCSlotIndex	m_SlotIndex;			
	zTTexPalette*					m_pPaletteBuf;			
	IDirectDrawPalette*				m_pddPalette;			
	int								m_nTexIndex;			
	BOOL							m_bAlphaModulate;		
	IDirectDrawSurface7*			m_pddSurfaces[12];		
	IDirectDrawSurface7*			m_pddDXTCSurfaces[12];	
	int								m_nActFrameNumber;		
	BYTE*							m_pTextureBuf;			
public:
	virtual ~zCTex_D3D()
	{
		XCALL(0x00653930);
	};

	virtual int Lock(int)
	{
		XCALL(0x00653AA0);
	};

	virtual int Unlock(void)
	{
		XCALL(0x00653AF0);
	};

	virtual int SetTextureInfo(zCTextureInfo const&)
	{
		XCALL(0x00653DC0);
	};

	virtual void* GetPaletteBuffer(void)
	{
		XCALL(0x006546F0);
	};

	virtual int GetTextureBuffer(int,void*&,int&)
	{
		XCALL(0x006547F0);
	};

	virtual zCTextureInfo GetTextureInfo(void)
	{
		XCALL(0x00653D70);
	};

	virtual int CopyPaletteDataTo(void*)
	{
		XCALL(0x006545E0);
	};

	virtual int CopyTextureDataTo(int,void*,int)
	{
		XCALL(0x006540A0);
	};

	virtual int HasAlpha(void)
	{
		XCALL(0x005F3410);
	};

	virtual zVEC4 GetRGBAAtTexel(float,float)
	{
		XCALL(0x005F8340);
	};

	zCTex_D3D(void)
	{
		XCALL(0x00653830);
	};

	void GetPixelSize(int&,int&)
	{
		XCALL(0x00653F90);
	};

	int XTEX_BuildSurfaces(int)
	{
		XCALL(0x006552A0);
	};

	void InsertTexture(int,int)
	{
		XCALL(0x00656120);
	};

	int PreloadTexture(void)
	{
		XCALL(0x00656370);
	};

	int SetTexture(int)
	{
		XCALL(0x006563A0);
	};

	int RemoveTexture(void)
	{
		XCALL(0x00656590);
	};

	int RescueTexture( zD3D_savedTexture*)
	{
		XCALL(0x00656710);
	};

	int RebuildTexture( zD3D_savedTexture*)
	{
		XCALL(0x00656750);
	};
};

struct zD3D_savedTexture		
{
	zCTex_D3D*			m_pTexture;		
	zCTextureConvert*	m_pTexConv;		
	zD3D_savedTexture*	m_pPrev;		
};