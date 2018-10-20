#pragma once

#include "zcvob.h"

enum zTReverbPreset;
class zCSoundFX;
enum oHEROSTATUS;
struct oCZoneMusicList;
class oCZoneMusicDefault;
class zCVob;


class zCZone : public zCVob			
{
	friend class zCWorld;
	friend class zCVobSound;
	friend class zCZoneZFogDefault;
	friend class zCZoneVobFarPlaneDefault;
	friend class oCZoneMusic;
	friend class zCVobSoundDaytime;
public:
	zCWorld*		m_pWorld;		
	static zCClassDef *classDef;
	void zZone(void)
	{
		XCALL(0x0063C050);
	};

	zCZone(void)
	{
		zZone();
	};

	float GetCamPosWeight(void)
	{
		XCALL(0x0063C1D0);
	};

	void SetZoneVobFlags(void)
	{
		XCALL(0x0063C390);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00639740);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063C3C0);
	};

	virtual ~zCZone()
	{
		XCALL(0x0063C0F0);
	};

	virtual void EndMovement(const BOOL a_bHintTrafoChanged=TRUE)
	{
		XCALL(0x0063C1A0);
	};

	virtual void SetVisual(zSTRING const&)
	{
		XCALL(0x00637160);
	};

	virtual void SetVisual(zCVisual*)
	{
		XCALL(0x00637150);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x0063C160);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x0063C180);
	};

	virtual zCClassDef* GetZoneMotherClass(void)const 
	{
		XCALL(0x00637170);
	};

	virtual zCClassDef* GetDefaultZoneClass(void)const 
	{
		XCALL(0x00639760);
	};

	virtual zSTRING GetDebugDescString(void)
	{
		XCALL(0x0063C400);
	};
};

class zCZoneReverb : public zCZone			
{
	friend class zCZoneReverbDefault;

	zTReverbPreset	m_Preset;			
	float			m_fReverbWeight;	
	float			m_fInnerRangePerc;	
public:
	static zCClassDef *classDef;
	void zZoneReverb(void)
	{
		XCALL(0x0063F3C0);
	};

	zCZoneReverb(void)
	{
		zZoneReverb();
	};

	float GetActiveWeight(void)
	{
		XCALL(0x0063F670);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00639790);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0063F7E0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063FA50);
	};

	virtual ~zCZoneReverb()
	{
		XCALL(0x0063F480);
	};

	virtual void ProcessZoneList(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&,zCWorld*)
	{
		XCALL(0x0063F6D0);
	};

	virtual zCClassDef* GetDefaultZoneClass(void)const 
	{
		XCALL(0x0063F6C0);
	};

	virtual zSTRING GetDebugDescString(void)
	{
		XCALL(0x0063F4F0);
	};
};

class zCZoneReverbDefault : public zCZoneReverb		
{
	friend class zCZoneReverb;
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00639A70);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063FB40);
	};

	virtual ~zCZoneReverbDefault()
	{
		XCALL(0x00639AC0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x0063FB00);
	};

	virtual void ProcessZoneList(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&,zCWorld*)
	{
		XCALL(0x00639A80);
	};
};

class zCZoneVobFarPlane : public zCZone			
{
	friend class zCZoneVobFarPlaneDefault;

	float		m_fVobFarPlaneZ;	
	float		m_fInnerRangePerc;	
public:
	static zCClassDef *classDef;
	void zZoneVobFarPlane(void)
	{
		XCALL(0x0063CE10);
	};

	zCZoneVobFarPlane(void)
	{
		zZoneVobFarPlane();
	};

	float GetActiveFarZ(float)
	{
		XCALL(0x0063CF40);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x00639E00);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0063D090);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063D0F0);
	};

	virtual ~zCZoneVobFarPlane()
	{
		XCALL(0x0063CED0);
	};

	virtual void ProcessZoneList(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&,zCWorld*)
	{
		XCALL(0x0063CFA0);
	};

	virtual zCClassDef* GetDefaultZoneClass(void)const 
	{
		XCALL(0x0063CF90);
	};
};

class zCZoneVobFarPlaneDefault : public zCZoneVobFarPlane	
{
	friend class zCZoneVobFarPlane;
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0063A0E0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063D1E0);
	};

	virtual ~zCZoneVobFarPlaneDefault()
	{
		XCALL(0x0063A120);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x0063D190);
	};
};

class zCZoneMusic : public zCZone				
{
	friend class oCZoneMusic;
public:
	static zCClassDef *classDef;
protected:
	static BOOL s_autochange;
	static BOOL s_canruleautochange;
public:
	static int SetAutochange(int)
	{
		XCALL(0x0063FC10);
	};

	static void GetAutochange(int*)
	{
		XCALL(0x0063FC30);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0063A450);
	};

	virtual ~zCZoneMusic()
	{
		XCALL(0x0063A490);
	};
};

class zCZoneZFog : public zCZone				
{
	friend class zCZoneZFogDefault;

	float		m_fFogRangeCenter;	
	float		m_fInnerRangePerc;	
	zCOLOR		m_FogColor;			
public:
	static zCClassDef *classDef;
	void zZoneZFog(void)
	{
		XCALL(0x0063C5B0);
	};

	zCZoneZFog(void)
	{
		zZoneZFog();
	};

	float GetActiveRange(float)
	{
		XCALL(0x0063C700);
	};

	float GetSkyFadeWeight(void)
	{
		XCALL(0x0063C750);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0063A7E0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0063CBB0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063CC40);
	};

	virtual ~zCZoneZFog()
	{
		XCALL(0x0063C690);
	};

	virtual void ProcessZoneList(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&,zCWorld*)
	{
		XCALL(0x0063C7A0);
	};

	virtual zCClassDef* GetDefaultZoneClass(void)const 
	{
		XCALL(0x0063C790);
	};
};

class zCZoneZFogDefault : public zCZoneZFog		
{
	friend class zCZoneZFog;
public:
	static zCClassDef *classDef;
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006371C0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063CD30);
	};

	virtual ~zCZoneZFogDefault()
	{
		XCALL(0x00638FD0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x0063CD00);
	};
};

enum zTVolumeType : DWORD
{
	zVOLUME_SPHERE,			
	zVOLUME_ELLIPSOID		
};

enum zTSoundMode
{
	zSOUND_MODE_LOOP,		
	zSOUND_MODE_ONCE,		
	zSOUND_MODE_RANDOM		
};

class zCVobSound : public zCZone		
{
	friend class oCGame;
	friend class zCVobSoundDaytime;
public:
	struct BIT_ARRAY
	{
		DWORD			tSndStartOn:1;		
		DWORD			tSndActive:1;		
		DWORD			tSndAmbient3D:1;	
		DWORD			tSndObstruction:1;	
		zTVolumeType	tSndVolType:1;		
		DWORD			tSndAllowedToRun:1;	
		DWORD			tSndIsRunning:1;	
	};
	zSTRING			m_sSndName;			
	float			m_fSndRadius;		
	zTSoundMode		m_SndMode;			
	union
	{
		DWORD		m_dbFlags;			
		BIT_ARRAY	f;
	};
	float			m_fSndRandDelay;	
	float			m_fSndRandDelayVar;	
	float			m_fSndVolume;		
	float			m_fSndConeAngle;	
	zCSoundFX*		m_pSndFX;			
	int				m_nHandle;			
	float			m_fSndTime;			
	float			m_fSndObstruction;	
	float			m_fSndObstrScale;	
	float			m_fSndObstrTime;	

	static zCClassDef *classDef;
	void zVobSound(void)
	{
		XCALL(0x0063D2B0);
	};

	zCVobSound(void)
	{
		zVobSound();
	};

	void SetSound(zSTRING const&)
	{
		XCALL(0x0063DA70);
	};

	zCSoundFX* LoadSound(zSTRING const&)
	{
		XCALL(0x0063DBB0);
	};

	void SetSoundVolume(float)
	{
		XCALL(0x0063DBF0);
	};

	void SetSoundRadius(float)
	{
		XCALL(0x0063DC00);
	};

	float CalcObstruction(void)
	{
		XCALL(0x0063DC80);
	};

	float CalcVolumeScale(void)
	{
		XCALL(0x0063DDE0);
	};

	void StartSound(int)
	{
		XCALL(0x0063E040);
	};

	void StopSound(void)
	{
		XCALL(0x0063E1D0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0063D4F0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0063E3D0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063E540);
	};

	virtual ~zCVobSound()
	{
		XCALL(0x0063D530);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x0063E350);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x0063E370);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x0063E3C0);
	};

	virtual void EndMovement(const BOOL a_bHintTrafoChanged=TRUE)
	{
		XCALL(0x0063D9D0);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x0063E9B0);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x0063E9D0);
	};

	virtual void ProcessZoneList(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&,zCWorld*)
	{
		XCALL(0x0063E8D0);
	};

	virtual zSTRING GetDebugDescString(void)
	{
		XCALL(0x0063D640);
	};

	virtual void DoSoundUpdate(float)
	{
		XCALL(0x0063E210);
	};
};

class zCVobSoundDaytime : public zCVobSound		
{
	float		m_fSndStartTime;	
	float		m_fSndEndTime;		
	zSTRING		m_sSndName2;		
	zCSoundFX*	m_pSndFX2;			
	int			m_nSection;			
public:
	static zCClassDef *classDef;
	void zVobSoundDaytime(void)
	{
		XCALL(0x0063EA30);
	};

	zCVobSoundDaytime(void)
	{
		zVobSoundDaytime();
	};

	void ActivateSection(int)
	{
		XCALL(0x0063EDE0);
	};

	int CalcTimeFrac(float,float,float,float&)
	{
		XCALL(0x0063EEC0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x0063B010);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x0063F270);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x0063F2E0);
	};

	virtual ~zCVobSoundDaytime(void)
	{
		XCALL(0x0063EAC0);
	};

	virtual zCClassDef* GetZoneMotherClass(void)const 
	{
		XCALL(0x0063B020);
	};

	virtual zSTRING GetDebugDescString(void)
	{
		XCALL(0x0063EC40);
	};

	virtual void DoSoundUpdate(float)
	{
		XCALL(0x0063EF50);
	};
};

class oCZoneMusic : public zCZone
{
public:
	BOOL			m_bEnabled;				
	BOOL			m_bLocalEnabled;		
	int				m_nPriority;			
	BOOL			m_bEllipsoid;			
	float			m_fReverbLevel;			
	float			m_fVolumeLevel;			
	BOOL			m_bLoop;				
	BOOL			m_bDayEntranceDone;		
	BOOL			m_bNightEntranceDone;	
public:
	static zCClassDef *classDef;	
	static BOOL s_daytime;
	static BOOL s_zonetime;
	static oHEROSTATUS s_herostatus;
	static oCZoneMusic*& s_musiczone;
	static oCZoneMusic*& s_oldmusiczone;
	static long s_lastzonechange;
	void oZoneMusic(void)
	{
		XCALL(0x006404C0);
	};

	oCZoneMusic(void)
	{
		oZoneMusic();
	};

	void SetEnabled(int)
	{
		XCALL(0x00641080);
	};

	int IsEnabled(void)const 
	{
		XCALL(0x00641090);
	};

	void SetPriority(int)
	{
		XCALL(0x006410A0);
	};

	int GetPriority(void)const 
	{
		XCALL(0x006410B0);
	};

	void SetEllipsoid(int)
	{
		XCALL(0x006410C0);
	};

	int IsEllipsoid(void)const 
	{
		XCALL(0x006410D0);
	};

	void SetReverb(float)
	{
		XCALL(0x006410E0);
	};

	float GetReverb(void)const 
	{
		XCALL(0x006410F0);
	};

	void SetVolume(float)
	{
		XCALL(0x00641100);
	};

	float GetVolume(void)const 
	{
		XCALL(0x00641110);
	};

	void SetLoop(int)
	{
		XCALL(0x00641120);
	};

	int IsLoop(void)const 
	{
		XCALL(0x00641130);
	};

	void SetDayEntranceDone(int)
	{
		XCALL(0x00641140);
	};

	int IsDayEntranceDone(void)const 
	{
		XCALL(0x00641150);
	};

	void SetNightEntranceDone(int)
	{
		XCALL(0x00641160);
	};

	int IsNightEntranceDone(void)const 
	{
		XCALL(0x00641170);
	};

	static void SetZonetime(int)
	{
		XCALL(0x00641180);
	};

	static void GetZonetime(int*)
	{
		XCALL(0x00641190);
	};

	float GetCamPosWeightElps(void)
	{
		XCALL(0x00641380);
	};

	static  oCZoneMusicList* BuildTempZoneList(oCZoneMusicDefault*,zCArraySort<zCZone*> const&)
	{
		XCALL(0x00641530);
	};

	static void ReleaseTempZoneList( oCZoneMusicList*)
	{
		XCALL(0x00641660);
	};

	static void SwitchInAndOutZones(zCArraySort<zCZone*> const&,zCArraySort<zCZone*> const&)
	{
		XCALL(0x00641690);
	};

	static oCZoneMusic* GetMusicZoneByName(oCZoneMusic*,zSTRING)
	{
		XCALL(0x00641B10);
	};

	static void GetNewTheme(zSTRING*)
	{
		XCALL(0x00641BA0);
	};

	static int PlayThemeVariation(zSTRING,int)
	{
		XCALL(0x00641F90);
	};

	static int IsDaytime(void)
	{
		XCALL(0x00642400);
	};

	static oHEROSTATUS GetHerostatus(void)
	{
		XCALL(0x00642420);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006401D0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x006411A0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x00641290);
	};

	virtual ~oCZoneMusic()
	{
		XCALL(0x00640550);
	};

	virtual zCClassDef* GetDefaultZoneClass(void)const 
	{
		XCALL(0x00641030);
	};

	virtual zSTRING GetDebugDescString(void)
	{
		XCALL(0x00641040);
	};

	virtual void OnTrigger(zCVob*)
	{
		XCALL(0x00641060);
	};

	virtual void OnUntrigger(zCVob*)
	{
		XCALL(0x00641070);
	};
};

class oCZoneMusicDefault : public oCZoneMusic
{
public:
	static zCClassDef *classDef;
	void oZoneMusicDefault(void)
	{
		XCALL(0x00642430);
	};

	oCZoneMusicDefault(void)
	{
		oZoneMusicDefault();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x006404B0);
	};

	virtual ~oCZoneMusicDefault(void)
	{
		XCALL(0x006424C0);
	};
};