#include "AST.h"

void _cb_ZenGin_WinMain()
{

}

void _cb_Game_Init()
{
	
}

extern void PluginLoop ();
void _cb_Game_Loop()
{
	PluginLoop ();
}

// Загрузка новой игры
void _cb_Game_LoadBegin_NewGame()
{
	
}

void _cb_Game_LoadEnd_NewGame()
{
	
}

// Загрузка сейва
void _cb_Game_LoadBegin_SaveGame()
{
	
}

void _cb_Game_LoadEnd_SaveGame()
{
	
}

// Выбор уровння
void _cb_Game_LoadBegin_ChangeLevel()
{
	
}

void _cb_Game_LoadEnd_ChangeLevel()
{

}

// Выбор через триггер
void _cb_Game_LoadBegin_Trigger()
{
	
}

void _cb_Game_LoadEnd_Trigger()
{
	
}

void _cb_Game_Pause()
{
	
}

void _cb_Game_Unpause()
{
	
}

void _cb_Externals_Define()
{
	
}

void _cb_AST_Thread()
{
	
}

void _cb_AST_ScreenShot()
{
	
}

CApplication* pApplication = CApplication::CreateRefApplication (
	_cb_ZenGin_WinMain,
	_cb_Game_Init,
	_cb_Game_Loop,
	_cb_Game_LoadBegin_NewGame,
	_cb_Game_LoadEnd_NewGame,
	_cb_Game_LoadBegin_SaveGame,
	_cb_Game_LoadEnd_SaveGame,
	_cb_Game_LoadBegin_ChangeLevel,
	_cb_Game_LoadEnd_ChangeLevel,
	_cb_Game_LoadBegin_Trigger,
	_cb_Game_LoadEnd_Trigger,
	_cb_Game_Pause,
	_cb_Game_Unpause,
	_cb_Externals_Define,
	_cb_AST_Thread,
	_cb_AST_ScreenShot
);