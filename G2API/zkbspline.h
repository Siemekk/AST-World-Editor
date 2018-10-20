#pragma once

#include "ztypes.h"
class zCPositionKey;



enum zTSplLerpMode
{
	zLERP_UNDEFINE,			
	zLERP_PATH,				
	zLERP_PATH_IGNOREROLL,	
	zLERP_PATH_ROT_SAMPLES	
};



class zCCubicPolynomial		
{
	friend class zCKBSpline;

	zVEC3		m_vPositions[4];	
	float		m_fStartTime;		
	float		m_fEndTime;			
	float		m_fLifeTime;		
public:
	void zCubicPolynomial(void)
	{
		XCALL(0x004D61D0);
	};	

	zCCubicPolynomial(void)
	{
		zCubicPolynomial();
	};

	~zCCubicPolynomial(void)
	{
		XCALL(0x004D61E0);
	};

	void Interpolate1(float,zVEC3&)
	{
		XCALL(0x004D6310);
	};

	float Speed(float)
	{
		XCALL(0x004D6E10);
	};

	float Length(float)
	{
		XCALL(0x004D6F30);
	};

	void Interpolate0(float,zVEC3&)
	{
		XCALL(0x004D8970);
	};

};



class zCKBSpline			
{
	friend class oCTrajectory;
	friend class oCVisualFX;

	zCCubicPolynomial*		m_pCubics;		
	int						m_nNumCubics;	
	float*					m_pLengths;		
	float					m_fTotalLenght;	
	int						m_nIndexPos;	
	zCArray<zCPositionKey*>	m_arrKeys;		
	BOOL					m_bRemoveKeys;	
public:

	void InitVars(void)
	{
		XCALL(0x00487CD0);
	};

	~zCKBSpline(void)
	{
		XCALL(0x00488570);
	};

	void InterpolateN(float,zMAT4&,zTSplLerpMode)
	{
		XCALL(0x00498B40);
	};

	void Initialize(zCArray<zCPositionKey*>&,int)
	{
		XCALL(0x004D5B30);
	};

	void Changed(void)
	{
		XCALL(0x004D6240);
	};

	void Terminate(void)
	{
		XCALL(0x004D6290);
	};

	void ComputeIAndU(float,int&,float&)
	{
		XCALL(0x004D63F0);
	};

	void Interpolate0(float,zVEC3&)
	{
		XCALL(0x004D64A0);
	};

	void Interpolate0(float,zMAT4&,zTSplLerpMode)
	{
		XCALL(0x004D65C0);
	};

	void Interpolate1(float,zMAT4&,zTSplLerpMode)
	{
		XCALL(0x004D6970);
	};

	void Interpolate1(float,zVEC3&)
	{
		XCALL(0x004D6C30);
	};

	void Interpolate2(float,zVEC3&)
	{
		XCALL(0x004D6D30);
	};

	void ComputeArcLength(void)
	{
		XCALL(0x004D70C0);
	};

	void InvertIntegral(float,int&,float&)
	{
		XCALL(0x004D7290);
	};

	void Interpolate0_AL(float,zVEC3&)
	{
		XCALL(0x004D7630);
	};

	void Interpolate0_AL(float,zMAT4&,zTSplLerpMode)
	{
		XCALL(0x004D7740);
	};

	void Interpolate1_AL(float,zMAT4&,zTSplLerpMode)
	{
		XCALL(0x004D7A70);
	};

	void Interpolate1_AL(float,zVEC3&)
	{
		XCALL(0x004D7D60);
	};

	void Interpolate2_AL(float,zVEC3&)
	{
		XCALL(0x004D7E60);
	};

	float Length(float)
	{
		XCALL(0x004D7F40);
	};

	void DrawControlPolygon(zCOLOR)
	{
		XCALL(0x004D80D0);
	};

	void Draw(zCOLOR,float)
	{
		XCALL(0x004D8380);
	};

	float GetTime(float)
	{
		XCALL(0x004D8A50);
	};

};