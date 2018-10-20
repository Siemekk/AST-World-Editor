#pragma once

#include "CInvoke.h"

class CCallBack
{
	static zCArray <CHookInfo*> m_arrFuncs;

public:

	ASTAPI static zBOOL		Attach		(CHookInfo&);
	ASTAPI static zBOOL		Detach		(CHookInfo&);
	ASTAPI static zBOOL		DetachTree	(CHookInfo&);
	ASTAPI static zBOOL		Redefine	(CHookInfo&);

	ASTAPI static zVOID		Commit		();
	ASTAPI static zBOOL		Commit		(CHookInfo&);
	ASTAPI static zUINT32	Auto		(const zUINT32&);
	ASTAPI static zVOID		Protect		(CHookInfo&);
	ASTAPI static zVOID		Unprotect	(CHookInfo&);
	
	ASTAPI static zBOOL		IsExist		(const zUINT32&);
	ASTAPI static zBOOL		IsExist		(CHookInfo&);
	ASTAPI static zBOOL		IsProtected	(const zUINT32&);
	ASTAPI static zBOOL		IsHooked	(CHookInfo&);

	ASTAPI static CHookInfo* FindHook	(const zUINT32&);
};