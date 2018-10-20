#pragma once

typedef  void(__stdcall *AST_PLUGIN_INIT_FUNC) ();

class CPlugin
{
	static zCList<CPlugin> PluginList;

	LPCSTR							lpPluginDLL;
	HPLUGIN							hModule;

public:

	CPlugin();
	~CPlugin();

				static	void	LoadModules(zSTRING);
	ASTAPI	static	HPLUGIN	SearchPluginInst(zSTRING);

};