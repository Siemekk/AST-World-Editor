#pragma once

typedef void(*_cdeclfnc)();

class CApplication
{
	/*	_________________info_________________
		0.	Called from start engine
		1.	Called from game init
		2.  Called from G2 perframe loop
		3.  Called from load new game begin
		4.  Called from load new game end
		5.  Called from load save game begin
		6.  Called from load save game end
		7.  Called from change level begin
		8.  Called from change level end
		9.  Called from change from trigger begin
		10. Called from change from trigger end
		11. Called from set pause
		12. Called from set unpause
		13. Called from registered externals
		14. Called from AST thread
		15. Called from create screenshot
	*/
	_cdeclfnc* cb_events;
	
public:

	ASTAPI static CApplication* CreateRefApplication(void*, ...);

	// ------------------------------------------------------------------------------------;

	ASTAPI static char* CmdLine;	
	ASTAPI static char* GetPath_Gothic();
	ASTAPI static char* GetPath_System();
	ASTAPI static char* GetPath_Exe();
};