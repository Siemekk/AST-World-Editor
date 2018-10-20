#pragma once

#include "CViewAni.h"

enum T_BAR_MODE
{
	T_LEFT_2_RIGHT,
	T_AT_MIDDLE,
	T_RIGHT_2_LEFT
};

class CDynamicBar : public CViewAni
{
	
	

public:

	//
	// layer of bar
	//
	struct CLayer : public CViewAni
	{
		CDynamicBar* Parent										;
		zBOOL		 Animated									;
		
		zSTRING	m_sTexname 										;
		int32	m_nParm_cur										;
		int32	m_nParm_max										;

		int32	m_nOffset_l										;
		int32	m_nOffset_r										;
		int32	m_nOffset_u										;
		int32	m_nOffset_d										;

		ASTAPI			CLayer ()								;
		ASTAPI zVOID	Attach ()								;
		ASTAPI zVOID	SetParm(const int32& m_nParm_cur);
		ASTAPI zVOID	RedefineParms(
							const int32&	m_nParm_cur			,
							const int32&	m_nParm_max)		;

		ASTAPI zVOID SetOffset(
							const int32&	offset_l			,
							const int32&	offset_r			,
							const int32&	offset_u			,
							const int32&	offset_d)			;
	};




	//
	// base bar operations
	//
	ASTAPI	CDynamicBar ( const zSTRING& texname				,
							const int32& px						,
							const int32& py						, 
							const int32& w						, 
							const int32& h						,
							const T_BAR_MODE&)					;

	ASTAPI	static	CDynamicBar*Create(
							const zSTRING& texname				, 
							const zINT32& px					, 
							const zINT32& py					, 
							const zINT32& w						, 
							const zINT32& h						,
							const T_BAR_MODE& = T_LEFT_2_RIGHT)	;

	ASTAPI				zVOID		Resize(
										const zINT32&			, 
										const zINT32&)			;

	ASTAPI				zVOID			Show  ()				;
	ASTAPI				zVOID			Hide  ()				;

	//
	//	Layers
	//
	ASTAPI	 CLayer*	AddLayer(	
							const zSTRING&		texname			,
							const int32&		parm_cur		,
							const int32&		parm_max		,
							const zBOOL&		animated = 0)	;

	ASTAPI	 CLayer*	AddLayerEx(	
							const zSTRING&		texname			,
							const int32&		parm_cur		,
							const int32&		parm_max		,
							const int32&		offset_l = 0	,
							const int32&		offset_r = 0	,
							const int32&		offset_u = 0	,
							const int32&		offset_d = 0	,
							const zBOOL&		animated = 0)	;

	ASTAPI				zVOID		RemoveLayer(CLayer*)		;
	

protected:

	zCArray <CLayer*>		m_arrLayer							;
	zINT32					w, h, x, y							;
	T_BAR_MODE				view_mode							;

public:
	

	ASTAPI	 ~CDynamicBar ();
};

typedef CDynamicBar::CLayer CBarLayer;