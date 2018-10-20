#pragma once

#define force(a) for(int nT=0; nT<a; nT++)

enum zTTimerMode
{
	zTM_LINEAR	 = 1,
	zTM_PRIMARY	 = 2,
	zTM_EXACT	 = 4,
};

enum zTTimerFlags
{
	zTF_ACTIVE	 = 1,
	zTF_SUSPEND	 = 2,
	zTF_UNDELETE = 4
};

const zINT32 zTNone = -2;
const zINT32 zTOnce = -1;

typedef class CTimer
{
public:
	struct CTimerPtr
	{
		CTimerPtr()				;
		uint32		m_nId		;
		int32		m_nDelay	;
		byte		m_nMode		;
		byte		m_nFlags	;
		uint32		m_nStatus	;
		uint32		m_nNext		;
		byte		m_nSuspend	;
		CTimer*		m_tChild	;
		~CTimerPtr()			;
	};

public:

	zCArray<CTimerPtr*>		m_arrTimer																								;

	ASTAPI					CTimer		()																							;
	ASTAPI			zVOID	Attach		()																							;
	ASTAPI			CTimer&	operator []	(const uint32& id)																			;
	ASTAPI			zBOOL	operator ()	(const uint32& id, const int32& = zTNone, const byte& = zTM_LINEAR, const byte& = 0)		;
	ASTAPI			zBOOL	IsExist		(const uint32&)																				;
	ASTAPI			zVOID	Delete		(const uint32&)																				;
	ASTAPI	static	uint32	GetTime		()																							;
	ASTAPI			zVOID	Suspend		(const uint32&, const byte&)																;
	ASTAPI			zVOID	Static		(const uint32&, const byte&)																;
	ASTAPI					~CTimer		()																							;
	
	ASTAPI			zVOID	DebugInfo	(uint32 id)																					;

} TIMER, *PTIMER;