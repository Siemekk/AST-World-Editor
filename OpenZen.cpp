#include "AST.h"
#include "CEditor.h"

zSTRING GetWorldName()
{
	char filename [ MAX_PATH ];
	OPENFILENAME ofn;
    ZeroMemory( &filename, sizeof( filename ) );
    ZeroMemory( &ofn,      sizeof( ofn ) );
    ofn.lStructSize  = sizeof( ofn );
    ofn.lpstrFilter  = "World .zen\0*.zen";
    ofn.lpstrFile    = filename;
    ofn.nMaxFile     = MAX_PATH;
    ofn.lpstrTitle   = "Select world";
	ofn.Flags        = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR ;
	ofn.hInstance	 = hInstApp; 
	if(GetOpenFileName(&ofn))
	{
		zSTRING hello(filename);
		int SplitPos = hello.Search("\\Worlds\\");
		if(SplitPos != -1)	hello = hello.Substr(SplitPos + zSTRING("\\Worlds\\").Length(), hello.Length());
		
		return hello;
	}

	return "";
}

void __fastcall hMenu(CGameManager*, void*, int);
CInvoke<void(__thiscall*)(CGameManager*, int)> pMenu(0x004292D0, hMenu, IVK_AUTO);
void __fastcall hMenu(CGameManager* mgr, void*, int bIsIngame)
{
	_CFG::DisableAll();
	if(!bIsIngame)	
	{
		zSTRING name = GetWorldName();
		editor = new CEditor;
		editor->LoadWorld(name, zCWorld::zTWorldLoadMode::zWLD_LOAD_EDITOR_COMPILED);
	}
}