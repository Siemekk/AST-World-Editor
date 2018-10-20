#pragma once

#include "zcsession.h"
#include "ocnpc.h"
#include "zcworld.h"

class zCView;
class zCWorld;
class oCWorld;
class oCWorldTimer;
class zCViewProgressBar;
class oCViewGothicProgressBar;
class oCViewProgressBar;
class oCSavegameManager;
class oCViewStatusBar;
class oCGameInfo;
class zCVobLight;    
class oCGuilds;                        
class oCInfoManager;               
class oCNewsManager;                 
class oCSVMManager;           
class oCTradeManager;               
class oCPortalRoomManager;
enum oHEROSTATUS;


enum zTRoutineType
{
	zROUTINE_MOB,		
	zROUTINE_OBJECT		
};

class oCSpawnManager
{
public:
	typedef struct oSSpawnNode
	{
		oCNpc*		npc;
		zVEC3		spawnPos;
		float		timer;
        oSSpawnNode():npc(NULL),spawnPos(0,0,0),timer(0){} 
	} oTSpawnNode;

	zCArray<oTSpawnNode*>	spawnList;
	BOOL					spawningEnabled;
	zVEC3					camPos;
	float					insertTime;


	int						spawnFlags;

	void oSpawnManager(void)
	{
		XCALL(0x00777730);
	};	

	oCSpawnManager(void)
	{
		oSpawnManager();
	};

	~oCSpawnManager(void)
	{
		XCALL(0x00777780);
	};

	static void SetInsertRange(float)
	{
		XCALL(0x00777820);
	};

	static float GetInsertRange(void)
	{
		XCALL(0x00777830);
	};

	static void SetRemoveRange(float)
	{
		XCALL(0x00777840);
	};

	static float GetRemoveRange(void)
	{
		XCALL(0x00777850);
	};

	static void SetSpawnTime(float)
	{
		XCALL(0x00777860);
	};

	static float GetSpawnTime(void)
	{
		XCALL(0x00777870);
	};

	void ClearList(void)
	{
		XCALL(0x00777880);
	};

	void InsertInList(void*)
	{
		XCALL(0x007778D0);
	};

	void RemoveFromList(void*)
	{
		XCALL(0x007779B0);
	};

	int IsSpawningEnabled(void)
	{
		XCALL(0x00777A20);
	};

	void SetSpawningEnabled(int)
	{
		XCALL(0x00777A30);
	};

	void SpawnImmediately(int)
	{
		XCALL(0x00777A40);
	};

	void CheckInsertNpcs(void)
	{
		XCALL(0x00777BE0);
	};

	void ShowDebugInfo(void)
	{
		XCALL(0x00777C70);
	};

	void CheckInsertNpc(void)
	{
		XCALL(0x007780B0);
	};

	void InitCameraPos(void)
	{
		XCALL(0x007788C0);
	};

	int InsertNpc(oCNpc*,zVEC3 const&)
	{
		XCALL(0x00778920);
	};

	oCNpc* SummonNpc(int,zVEC3 const&,float)
	{
		XCALL(0x00778A20);
	};

	oCNpc* SpawnNpc(int,zSTRING const&,float)
	{
		XCALL(0x00778B20);
	};

	void SpawnNpc(oCNpc*,zSTRING const&,float)
	{
		XCALL(0x00778BA0);
	};

	void SpawnNpc(oCNpc*,zVEC3 const&,float)
	{
		XCALL(0x00778E70);
	};

	void CheckForInvalidDialogCamPos(float,oCNpc*)
	{
		XCALL(0x00778FD0);
	};

	int UseDeadNpcRoutinePos(oCNpc*)
	{
		XCALL(0x007791B0);
	};

	int CanDeadNpcBeRemoved(oCNpc*)
	{
		XCALL(0x00779260);
	};

	int CheckRemoveNpc(oCNpc*)
	{
		XCALL(0x007792E0);
	};

	void DeleteNpc(oCNpc*)
	{
		XCALL(0x00779690);
	};

	void DeleteAllSummoned(void)
	{
		XCALL(0x00779720);
	};

	void Archive(zCArchiver&)
	{
		XCALL(0x007797F0);
	};

	void Unarchive(zCArchiver&)
	{
		XCALL(0x00779890);
	};
};

class oCGame : public zCSession
{
public:
	
	
	
	typedef 
	enum oEGameDialogView
	{
		GAME_VIEW_SCREEN		,
		GAME_VIEW_CONVERSATION	,		
		GAME_VIEW_AMBIENT		,		
		GAME_VIEW_CINEMA		,		
		GAME_VIEW_CHOICE		,
		GAME_VIEW_NOISE			,
		GAME_VIEW_MAX
	}
	oTGameDialogView;
	
	float					cliprange;
	float					fogrange;

	BOOL					inScriptStartup;
	BOOL					inLoadSaveGame;
	BOOL					inLevelChange;

	
	zCView*					array_view			[ oTGameDialogView :: GAME_VIEW_MAX ];
	BOOL					array_view_visible	[ oTGameDialogView :: GAME_VIEW_MAX ];
	BOOL					array_view_enabled	[ oTGameDialogView :: GAME_VIEW_MAX ];

	oCSavegameManager*		savegameManager;
	zCView*					game_text;
	zCView					*load_screen, *save_screen, *pause_screen;		
	oCViewStatusBar*		hpBar;
	oCViewStatusBar*		swimBar;
	oCViewStatusBar*		manaBar;
	oCViewStatusBar*		focusBar;
	BOOL					showPlayerStatus;
	
	BOOL					game_drawall;
	BOOL					game_frameinfo;
	BOOL					game_showaniinfo;
	BOOL					game_showwaynet;
	BOOL					game_testmode;	
	BOOL					game_editwaynet;
	BOOL					game_showtime;
	BOOL					game_showranges;
	BOOL					drawWayBoxes;
	BOOL					scriptStartup;
	BOOL					showFreePoints;
	oCNpc*					showRoutineNpc;

	
	BOOL					loadNextLevel;
	zSTRING					loadNextLevelName;
	zSTRING					loadNextLevelStart;	

	
	zVEC3					startpos;
	oCGameInfo*				gameInfo;
	zCVobLight*				pl_light;
	float					pl_lightval;

	
	oCWorldTimer*			wldTimer;
	float					timeStep;
	BOOL					singleStep;	

	
	oCGuilds*				guilds;
	oCInfoManager*			infoman;
	oCNewsManager*			newsman;
	oCSVMManager*			svmman;
	oCTradeManager*			trademan;
	oCPortalRoomManager*	portalman;
	oCSpawnManager*			spawnman;
	
	
	float					music_delay;
	oCNpc*					watchnpc;

	
	BOOL					m_bWorldEntered;
	float					m_fEnterWorldTimer;

	int						initial_hour, initial_minute;

	zCArray<zCVob*>			debugInstances;
	int						debugChannels;
	BOOL					debugAllInstances;
private:

	
	
	
	typedef struct {
		
		void		Release()		{ delete(this); };

		zSTRING		objName;
		int			stateNum;
		int			hour1,min1;
		int			type;
	} TObjectRoutine;

public:

	int							oldRoutineDay;
	zCListSort<TObjectRoutine>	objRoutineList;
	zCListSort<TObjectRoutine>* currentObjectRoutine;
	zCViewProgressBar*			progressBar;
	zCArray   <zCVisual*>		visualList;

public:
	// [AST]
	void UpdatePlayerStatus_AST();
	void WriteSavegame_AST(int slot, BOOL bSaveGlobalVars);
	void LoadSavegame_AST(int slot, int);
	// [/AST]
	virtual int HandleEvent(int)
	{
		XCALL(0x006FC170);
	};

	virtual ~oCGame()
	{
		XCALL(0x006BFEA0);
	};

	virtual void Init(void)
	{
		XCALL(0x006C1060);
	};

	virtual void Done(void)
	{
		XCALL(0x006C0D80);
	};

	virtual void Render(void)
	{
		XCALL(0x006C86A0);
	};

	virtual void RenderBlit(void)
	{
		XCALL(0x006CA910);
	};

	virtual void CamInit(zCVob*,zCCamera*)
	{
		XCALL(0x006C05D0);
	};

	virtual void CamInit(void)
	{
		XCALL(0x006C05C0);
	};

	virtual void SetCamera(zCCamera*)
	{
		XCALL(0x005DE780);
	};

	virtual zCCamera* GetCamera(void)const 
	{
		XCALL(0x005DE790);
	};

	virtual zCAICamera* GetCameraAI(void)const 
	{
		XCALL(0x005DE7A0);
	};

	virtual zCVob* GetCameraVob(void)const 
	{
		XCALL(0x005DE7B0);
	};

	virtual zCView* GetViewport(void)const 
	{
		XCALL(0x005DE7C0);
	};

	virtual zCWorld* GetWorld(void)
	{
		XCALL(0x005DECF0);
	};

	virtual void SaveWorld(zSTRING const&,zCWorld::zTWorldSaveMode,int,int)
	{
		XCALL(0x006C4EF0);
	};

	virtual int LoadWorld(zSTRING const&,zCWorld::zTWorldLoadMode)
	{
		XCALL(0x006C4EA0);
	};

	virtual zCCSManager* GetCutsceneManager(void)
	{
		XCALL(0x005DE7D0);
	};

	virtual void SetTime(int,int,int)
	{
		XCALL(0x006C4DE0);
	};

	virtual void GetTime(int&,int&,int&)
	{
		XCALL(0x006C4E70);
	};

	virtual void SetWorld(zCWorld*)
	{
		XCALL(0x005DED40);
	};

	virtual void DesktopInit(void)
	{
		XCALL(0x006C0680);
	};

	virtual void CutsceneSystemInit(void)
	{
		XCALL(0x005DE9E0);
	};

	virtual void EnterWorld(oCNpc*,int,zSTRING const&)
	{
		XCALL(0x006C96F0);
	};

	virtual void Pause(int)
	{
		XCALL(0x006C8AD0);
	};

	virtual void Unpause(void)
	{
		XCALL(0x006C8D50);
	};

	virtual void SetDrawWaynet(int)
	{
		XCALL(0x006BFE30);
	};

	virtual int GetDrawWaynet(void)
	{
		XCALL(0x006BFE40);
	};

	virtual void RenderWaynet(void)
	{
		XCALL(0x006C7F70);
	};

	virtual void EnvironmentInit(void)
	{
		XCALL(0x006C4A60);
	};

	virtual void SetRanges(void)
	{
		XCALL(0x006C4710);
	};

	virtual void SetRangesByCommandLine(void)
	{
		XCALL(0x006C4760);
	};

	virtual zVEC3 GetStartPos(void)
	{
		XCALL(0x006BFE50);
	};

	virtual void SetGameInfo(oCGameInfo*)
	{
		XCALL(0x006C1C20);
	};

	virtual int LoadParserFile(zSTRING const&)
	{
		XCALL(0x006C4BE0);
	};

	virtual void TriggerChangeLevel(zSTRING const&,zSTRING const&)
	{
		XCALL(0x006C7AF0);
	};

	virtual oCWorld* GetGameWorld(void)
	{
		XCALL(0x006C2C30);
	};

	virtual oCGameInfo* GetGameInfo(void)
	{
		XCALL(0x006C2CE0);
	};

	virtual zCView* GetTextView(void)
	{
		XCALL(0x006C2C70);
	};

	virtual void OpenLoadscreen(bool,zSTRING)
	{
		XCALL(0x006C2690);
	};

	virtual void OpenSavescreen(bool)
	{
		XCALL(0x006C2250);
	};

	virtual void CloseLoadscreen(void)
	{
		XCALL(0x006C2BD0);
	};

	virtual void CloseSavescreen(void)
	{
		XCALL(0x006C2630);
	};

	virtual void ChangeLevel(zSTRING const&,zSTRING const&)
	{
		XCALL(0x006C7290);
	};

	virtual void LoadWorldStartup(zSTRING const&)
	{
		XCALL(0x006C9C10);
	};

	virtual void LoadWorldStat(zSTRING)
	{
		XCALL(0x006CA010);
	};

	virtual void LoadWorldDyn(zSTRING const&)
	{
		XCALL(0x006CA280);
	};

	virtual void InitWorldSavegame(int&,zSTRING&)
	{
		XCALL(0x006C9530);
	};

	virtual int CheckIfSavegameExists(zSTRING const&)
	{
		XCALL(0x006C7D40);
	};

	virtual void CompileWorld(void)
	{
		XCALL(0x006C9A50);
	};

	virtual void WorldInit(void)
	{
		XCALL(0x006C02F0);
	};

	virtual void NpcInit(zCTree<zCVob>*)
	{
		XCALL(0x006C0D30);
	};

	virtual void NpcInit(void)
	{
		XCALL(0x006C0D00);
	};

	virtual void SetAsPlayer(zSTRING const&)
	{
		XCALL(0x006C3D20);
	};


	
	oCGame(void)
	{
		XCALL(0x006BF810);
	};

	void SetCameraPosition(void)
	{
		XCALL(0x006C05E0);
	};

	void UpdateViewSettings(void)
	{
		XCALL(0x006C0C60);
	};

	void CallScriptStartup(void)
	{
		XCALL(0x006C1C70);
	};

	void CallScriptInit(void)
	{
		XCALL(0x006C1F60);
	};

	oCNpc* GetSelfPlayerVob(void)
	{
		XCALL(0x006C2C60);
	};

	oCWorldTimer* GetWorldTimer(void)
	{
		XCALL(0x006C2C80);
	};

	oCInfoManager* GetInfoManager(void)
	{
		XCALL(0x006C2C90);
	};

	oCNewsManager* GetNewsManager(void)
	{
		XCALL(0x006C2CA0);
	};

	oCSVMManager* GetSVMManager(void)
	{
		XCALL(0x006C2CB0);
	};

	oCTradeManager* GetTradeManager(void)
	{
		XCALL(0x006C2CC0);
	};

	oCGuilds* GetGuilds(void)
	{
		XCALL(0x006C2CD0);
	};

	oCPortalRoomManager* GetPortalRoomManager(void)
	{
		XCALL(0x006C2CF0);
	};

	oCSpawnManager* GetSpawnManager(void)
	{
		XCALL(0x006C2D00);
	};

	oHEROSTATUS GetHeroStatus(void)
	{
		XCALL(0x006C2D10);
	};

	void SetShowNews(oCNpc*)
	{
		XCALL(0x006C2D50);
	};

	void SetShowPlayerStatus(int)
	{
		XCALL(0x006C2D90);
	};

	int GetShowPlayerStatus(void)
	{
		XCALL(0x006C2DF0);
	};

	void UpdateScreenResolution(void)
	{
		XCALL(0x006C2E00);
	};

	void UpdatePlayerStatus(void)
	{
		XCALL(0x006C3140);
	};

	void RemoveHelperVobs(zCTree<zCVob>*)
	{
		XCALL(0x006C3C10);
	};

	void CreateVobList(zCList<zCVob>&,zCTree<zCVob>*,zTVobType)
	{
		XCALL(0x006C3CD0);
	};

	void SetupPlayers(oCNpc*&,zSTRING const&)
	{
		XCALL(0x006C3FA0);
	};

	oCNpc* RemovePlayerFromWorld(void)
	{
		XCALL(0x006C5020);
	};

	void InsertPlayerIntoWorld(oCNpc*,zMAT4&)
	{
		XCALL(0x006C5070);
	};

	void PreSaveGameProcessing(int)
	{
		XCALL(0x006C5120);
	};

	void PostSaveGameProcessing(void)
	{
		XCALL(0x006C51C0);
	};

	void WriteSavegame(int,int)
	{
		XCALL(0x006C5250);
	};

	int CheckObjectConsistency(int)
	{
		XCALL(0x006C5B50);
	};

	void ClearGameState(void)
	{
		XCALL(0x006C5ED0);
	};

	void InitNpcAttitudes(void)
	{
		XCALL(0x006C61D0);
	};

	void RecurseCacheVobs(zCTree<zCVob>*)
	{
		XCALL(0x006C6240);
	};

	void CacheVisualsIn(void)
	{
		XCALL(0x006C62D0);
	};

	void CacheVisualsOut(void)
	{
		XCALL(0x006C6530);
	};

	void LoadGame(int,zSTRING const&)
	{
		XCALL(0x006C65A0);
	};

	void LoadSavegame(int,int)
	{
		XCALL(0x006C67D0);
	};

	void ShowDebugInfos(void)
	{
		XCALL(0x006C7FB0);
	};

	void DeleteNpcs(oCNpc*,oCNpc*,float)
	{
		XCALL(0x006C8E80);
	};

	void LoadWorld(int,zSTRING const&)
	{
		XCALL(0x006C90B0);
	};

	int IsInWorld(zSTRING const&)
	{
		XCALL(0x006CA770);
	};

	static int Sort_Routine( oCGame::TObjectRoutine*, oCGame::TObjectRoutine*)
	{
		XCALL(0x006CA930);
	};

	void InsertObjectRoutine(int,zSTRING const&,int,int,int)
	{
		XCALL(0x006CA960);
	};

	void ResetObjectRoutineList(void)
	{
		XCALL(0x006CAB20);
	};

	void ClearObjectRoutineList(void)
	{
		XCALL(0x006CAB40);
	};

	void CheckObjectRoutines(void)
	{
		XCALL(0x006CABB0);
	};

	void SetObjectRoutineTimeChange(int,int,int,int)
	{
		XCALL(0x006CACB0);
	};

	void ToggleShowFreePoints(void)
	{
		XCALL(0x006CB270);
	};

	void ShowFreePoints(void)
	{
		XCALL(0x006CB290);
	};

	void RefreshNpcs(void)
	{
		XCALL(0x006CB5F0);
	};

	void DeleteTorches(void)
	{
		XCALL(0x006CB640);
	};

	static int ConsoleEvalFunc(zSTRING const&,zSTRING&)
	{
		XCALL(0x006CC0A0);
	};

	int IsDebuggingChannel(int)
	{
		XCALL(0x006D3B90);
	};

	int IsDebuggingInstance(zCVob*)
	{
		XCALL(0x006D3BB0);
	};

	int IsDebuggingAllInstances(void)
	{
		XCALL(0x006D3BF0);
	};

	int OpenView(oCGame::oEGameDialogView)
	{
		XCALL(0x006D3C00);
	};

	int CloseView(oCGame::oEGameDialogView)
	{
		XCALL(0x006D3C30);
	};

	void DefineExternals_Ulfi(zCParser*)
	{
		XCALL(0x006D4780);
	};

	void SwitchCamToNextNpc(void)
	{
		XCALL(0x006FBF40);
	};

	int TestKeys(int)
	{
		XCALL(0x006FD560);
	};

	int IA_TestWay(int)
	{
		XCALL(0x007000E0);
	};

	void OpenLoadscreenAST (bool, zSTRING);
	void CloseLoadscreenAST(void);
};

