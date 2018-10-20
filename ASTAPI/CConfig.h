#pragma once

// _TConfig_Parm::
#define TConfig(Parm) _CFG::HasParm(zTConfig_Parm::Parm)

enum zTConfig_Parm
{
	zT_Time						= 1 << 0,
	zT_FPS						= 1 << 1,
	zT_RcMonitor				= 1 << 2,
	zT_PostLoadScreen			= 1 << 3,
	zT_RandLoadScreen			= 1 << 4,
	zT_HelpDesc					= 1 << 5,
	zT_ScreenShotBind			= 1 << 6,
	zT_Quivers					= 1 << 7,
	zT_Scabbards				= 1 << 8,
	zT_DisableTakeAni			= 1 << 9,
	zT_Diagrams					= 1 << 10,
	zT_NonTarget				= 1 << 11
};

typedef int _BIT_ARRAY;
typedef struct _AST_CONFIGURATION_MANAGER
{

			  static _BIT_ARRAY _AST_CONFIG;
	ASTAPI static void EnableParm	(const zTConfig_Parm&);
	ASTAPI static void DisableParm	(const zTConfig_Parm&);
	ASTAPI static BOOL HasParm		(const zTConfig_Parm&);
	ASTAPI static void DisableAll	();	
	ASTAPI static void EnableAll		();	

} _CFG;