#pragma once 

#include "zThread.h"
#include "..\DX7\include\d3dx.h"

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
		IDirectDrawSurface7*	m_pSurface;		
		BOOL					m_bLocked;		
		zD3D_Entry*				m_pNextEntry;	
	};
	struct zD3D_SlotHeader		
	{
		zD3D_Entry*				m_pFirstEntry;		
	};
	IDirectDrawSurface7* XDXTC_CreateSurface(int,int,int, zCDXTCCache_D3D::zD3D_Entry*)
	{
		XCALL(0x00643470);
	};
private:
	int					xdxtc_cacheentryCounter;	
	zD3D_SlotHeader		xdxtc_list[288];			
	
};
