#pragma once

class CCursor : public CViewAni
{
	static	CCursor*	m_pActiveCursor;
			zVEC2		m_vPos;
			zVEC2		m_vPoint;
			zBOOL		isMoved;

	static	zVOID		Update();

public:

	ASTAPI								CCursor				();
	ASTAPI			static	zVOID		SetActiveCursor		(CCursor*&);
	ASTAPI			static	CCursor*	GetActiveCursor		();
	ASTAPI	virtual	const	zVEC2&		GetCursorPos		();
	ASTAPI	virtual			zVOID		SetTexture			(const zSTRING&);
	ASTAPI	virtual			zVOID		SetActionPoint		(const zINT32&, const zINT32&);
	ASTAPI	virtual			zVOID		Show				(const zBOOL& return_pos = FALSE);
	ASTAPI	virtual			zVOID		Hide				();
};
