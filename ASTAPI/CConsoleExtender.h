#pragma once

#include "G2API\zcconsole.h"

typedef BOOL(* _EvalFunc)();

struct CConsoleExtender
{
	ASTAPI static zSTRING			m_sWord;
	ASTAPI static zSTRING			m_sReturn;
	ASTAPI static zCConsole*		m_pConsole;

	ASTAPI static void AddRef		(_EvalFunc);
	ASTAPI static void NewCommand	(zSTRING const&,	zSTRING const&);
	ASTAPI static BOOL WORD			(const zINT32&,		zSTRING const&);

	ASTAPI CConsoleExtender(_EvalFunc);
};

typedef CConsoleExtender CslInfo;
