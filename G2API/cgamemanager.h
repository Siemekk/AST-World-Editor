#pragma once

#include "ztypes.h"
#include "zcinputcallback.h"

class oCGame;
class zCView;

class CGameManager : public zCInputCallback
{
public:
	int oldAlphaBlendFunc;  
	int sysContextHandle;   

	oCGame* m_pGame;
	oCGame* backLoop;
	int exitGame;
	int exitSession;
	int gameIdle;
	int lastWorldWasGame;
	int savegameManager;    

	zCArray<zSTRING>	lastDatFileList;


	zCArray<zSTRING>	lastWorldList;


	zSTRING backWorldRunning;    
	zSTRING backDatFileRunning;  

	zCView* vidScreen;              
	zCView* initScreen;             
public:
	// [AST]
	int HandleEvent_AST(unsigned int);
	// [/AST]
	virtual int HandleEvent(int)
	{
		XCALL(0x0042AD50);
	};

	virtual ~CGameManager()
	{
		XCALL(0x00424710);
	};
	CGameManager(void)
	{
		XCALL(0x004244E0);
	};

	void Tool_ConvertData(void)
	{
		XCALL(0x004248F0);
	};

	void Init( HWND__*&)
	{
		XCALL(0x00424C70);
	};

	void Done(void)
	{
		XCALL(0x004254E0);
	};

	int ExitGame(void)
	{
		XCALL(0x00425780);
	};

	int ExitSession(void)
	{
		XCALL(0x00425790);
	};

	void Run(void)
	{
		XCALL(0x00425830);
	};

	void InitScreen_Open(void)
	{
		XCALL(0x00425F60);
	};

	void InitScreen_Menu(void)
	{
		XCALL(0x00426210);
	};

	void InitScreen_Close(void)
	{
		XCALL(0x00426330);
	};

	void InitSettings(void)
	{
		XCALL(0x00426430);
	};

	void ShowSplashScreen(void)
	{
		XCALL(0x00426770);
	};

	void RemoveSplashScreen(void)
	{
		XCALL(0x004267B0);
	};

	void GameInit(void)
	{
		XCALL(0x004267D0);
	};

	void GameDone(void)
	{
		XCALL(0x00426CF0);
	};

	void GameSessionReset(void)
	{
		XCALL(0x00426D20);
	};

	void GameSessionInit(void)
	{
		XCALL(0x00426E10);
	};

	void GameSessionDone(void)
	{
		XCALL(0x00426F70);
	};

	void ShowIntro(void)
	{
		XCALL(0x00427070);
	};

	void ShowExtro(void)
	{
		XCALL(0x00427080);
	};

	void PreMenu(void)
	{
		XCALL(0x00427090);
	};

	void PostMenu(zSTRING)
	{
		XCALL(0x00427610);
	};

	void ApplySomeSettings(void)
	{
		XCALL(0x004276B0);
	};

	int GetPlaytimeSeconds(void)
	{
		XCALL(0x00429280);
	};

	void Menu(int)
	{
		XCALL(0x004292D0);
	};

	void Read_Savegame(int)
	{
		XCALL(0x0042A040);
	};

	void Write_Savegame(int)
	{
		XCALL(0x0042A2D0);
	};

	int HandleCancelKey(int)
	{
		XCALL(0x0042A700);
	};

	int MenuEnabled(int&)
	{
		XCALL(0x0042AAF0);
	};

	oCGame* GetGame(void)
	{
		XCALL(0x0042B1B0);
	};

	int IsIntroActive(void)
	{
		XCALL(0x0042B1C0);
	};

	void InsertMenuWorld(zSTRING&,zSTRING&)
	{
		XCALL(0x0042B1E0);
	};

	void RemoveMenuWorld(void)
	{
		XCALL(0x0042B1F0);
	};

	int IsGameRunning(void)
	{
		XCALL(0x0042B200);
	};

	int IntroduceChapter(void)
	{
		XCALL(0x0042B220);
	};

	int IntroduceChapter(zSTRING,zSTRING,zSTRING,zSTRING,int)
	{
		XCALL(0x0042B7E0);
	};

	int PlayVideo(zSTRING)
	{
		XCALL(0x0042B940);
	};

	int PlayVideoEx(zSTRING,short,int)
	{
		XCALL(0x0042BB10);
	};

	void ShowRealPlayTime(void)
	{
		XCALL(0x0042BDE0);
	};
};

