#pragma once

#include "zcontainers.h"
#include "zmath.h"



class zCOLOR
{
public:
	
	BOOL operator ==(const zCOLOR& clr2) const;
	BOOL operator !=(const zCOLOR& clr2) const;
	union
	{
		DWORD data;
		struct
		{
			BYTE	b;
			BYTE	g;
			BYTE	r;
			BYTE	a;
		};
	};

	
	zCOLOR();
	zCOLOR(BYTE _r, BYTE _g, BYTE _b);
	zCOLOR(BYTE _r, BYTE _g, BYTE _b, BYTE _a)
	{
		XCALL(0x0078AEF0);
	};

	zCOLOR(DWORD _color)
	{
		XCALL(0x00401F20);
	};
	
	void SetRGBA(BYTE _r, BYTE _g, BYTE _b, BYTE _a);
	void SetBGRA(BYTE _b, BYTE _g, BYTE _r, BYTE _a);
	void SetR(BYTE _c);
	void SetG(BYTE _c);
	void SetB(BYTE _c);
	void SetA(BYTE _c);
	BYTE GetR(void);
	BYTE GetG(void);
	BYTE GetB(void);
	BYTE GetA(void);


	void Reset(void)
	{
		XCALL(0x00572900);
	};

	zSTRING GetDescription(void)const 
	{
		XCALL(0x005FABA0);
	};

	void SetByDescription(zSTRING const&)
	{
		XCALL(0x005FAF10);
	};

	zSTRING GetDescriptionRGB(void)const 
	{
		XCALL(0x005FB190);
	};

	void SetRGB(unsigned char,unsigned char,unsigned char)
	{
		XCALL(0x0062A740);
	};
};

#include "zcolor.inl"


enum zTPlaneClass
{
	zPLANE_0,
	zPLANE_1,
	zPLANE_2,
	zPLANE_3
};

class zTPlane
{
public:
	float		m_fD;		
	zVEC3		m_vNormal;	
public:

	int CalcSignbits(void)const 
	{
		XCALL(0x0054B1A0);
	};

	int ClassifyPointBSPBuild(zVEC3 const&)const 
	{
		XCALL(0x005FB440);
	};

	zSTRING Print(void)const 
	{
		XCALL(0x005FB490);
	};

	void Calc(zVEC3 const&,zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005FB870);
	};

	void GetOriginUpRight(zVEC3&,zVEC3&,zVEC3&)const 
	{
		XCALL(0x005FB950);
	};
};
