#include "AST.h"
#include "G2API\zcskycontroller.h"
#include "CEditor.h"

extern void CameraMovement();
void  PluginLoop ()
{
		//zCCamera::activeCam->SetFOV(35);
	float fx, fy;
	zCCamera::activeCam->GetFOV(fx, fy);


	screen->Print(100, 2000, "AST-World Editor");
	screen->Print(100, 2200, "World name: " + ogame->GetWorld()->m_strlevelName);
	editor->Attach();


	// Draw crosshair 
	screen->Line(SCREEN_MID - zpixelx(10), SCREEN_MID, SCREEN_MID + zpixelx(10), SCREEN_MID, zCOLOR(255, 255, 255, 255));
	screen->Line(SCREEN_MID, SCREEN_MID - zpixely(10), SCREEN_MID, SCREEN_MID  + zpixely(10), zCOLOR(255, 255, 255, 255));
	
}

void __fastcall _CallScriptInit(oCGame*);
CInvoke<void(__thiscall*)(oCGame*)>pCallScriptInit(0x006C1F60, _CallScriptInit, IVK_AUTO);
void __fastcall _CallScriptInit(oCGame* _this)
{
	pCallScriptInit(_this);
}

