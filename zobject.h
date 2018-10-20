#pragma once

extern oCNpc*&				player			;		// Pointer to hero object
extern zCObjectFactory*&	zfactory		;		// Pointer to G2 object factory
extern zCArchiverFactory*	zarcFactory		;		// Pointer to acrhiver factory
extern zCOption*&			zoptions		;		// Pointer to options game
extern zCOption*&			zgameoptions	;		// Pointer to zGameOpt
extern zCParser*			parser			;		// Pointer to script parser
extern zCTimer*				ztimer			;		// Pointer to game timer
extern oCGame*&				ogame			;		// Pointer to current game-info instance
extern zCView*&				screen			;		// Pointer to current viewport instance
extern zCInput*&			zinput			;		// Pointer to current input instance
extern zCRenderer*&			zrenderer		;		// Pointer to D3D ref instance
extern oCNpc*&				stealnpc		;		// Pointer to steal npc
extern CGameManager*&		gameMan			;		// Pointer to game manager
extern zCLineCache*			zlineCache		;		// Pointer to line buff
extern zERROR*				zerr			;		// Pointer to zerror
extern zCSoundSystem*&		zsound			;		// Pointer to sound manager

extern HINSTANCE&			hInstApp		;
extern HDC& 				dcScreen		;
extern HICON&				hIconApp		;
extern HWND&				hWndApp			;