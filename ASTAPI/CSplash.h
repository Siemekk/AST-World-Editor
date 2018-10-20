#pragma once

#define __THREAD	DWORD	CALLBACK
#define __WINPROC	LRESULT	CALLBACK
#define __TIMERPROC	VOID	CALLBACK

typedef HINSTANCE	HPLUGIN;
typedef UINT		IRESOURCE;
typedef HANDLE		HTHREAD;

class CSplash
{

	static	HPLUGIN		hModule											;
	static	IRESOURCE	nResource										;
	static	HBITMAP		hBitMap											;
	static	UINT32		nAlphaColor										;

			WNDCLASS	winc;
			PCHAR		sWinName										;
			HWND		hWindow											;
			DWORD		dThreadId										;
			HTHREAD		hthread											;

			BYTE		m_bTransparency									;
			BOOL		m_bExec											;

	static	__THREAD	tSplashTread	(PVOID						)	;
	static	__WINPROC	tWinProc		(HWND, UINT, WPARAM, LPARAM	)	;
	static	__TIMERPROC	tFadeIn			(HWND, UINT, UINT,	 DWORD	)	;
	static	__TIMERPROC	tFadeOut		(HWND, UINT, UINT,	 DWORD	)	;

protected:

	static zCArray<CSplash*> m_arrSplash;

public:

	ASTAPI CSplash()															;
	ASTAPI static	void		SetHandle		(HPLUGIN = 0, IRESOURCE = 0	)	;
	ASTAPI static	void		SetAlphaColor	(UINT32  = 0				)	;
	ASTAPI			void		CreateProc		(BOOL    = FALSE			)	;
	ASTAPI			void		RemoveProc		(BOOL    = FALSE			)	;
	ASTAPI			BOOL		IsExec			(							)	;
	ASTAPI static	CSplash*	GetIdentity		(HWND						)	;
	ASTAPI ~CSplash()															;
};