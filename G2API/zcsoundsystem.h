#pragma once

#include "ztypes.h"
#include "zcobject.h"
#include "zcresource.h"

class zCSoundFX;
class zCActiveSnd;
class zCParser;
class zCVob;

enum zTReverbPreset
{
	zREVERB_GENERIC,			
	zREVERB_PADDEDCELL,			
	zREVERB_ROOM,				
	zREVERB_BATHROOM,			
	zREVERB_LIVINGROOM,			
	zREVERB_STONEROOM,			
	zREVERB_AUDITORIUM,			
	zREVERB_CONCERTHALL,		
	zREVERB_CAVE,				
	zREVERB_ARENA,				
	zREVERB_HANGAR,				
	zREVERB_CARPETEDHALLWAY,	
	zREVERB_HALLWAY,			
	zREVERB_STONECORRIDOR,		
	zREVERB_ALLEY,				
	zREVERB_FOREST,				
	zREVERB_CITY,				
	zREVERB_MOUNTAINS,			
	zREVERB_QUARRY,				
	zREVERB_PLAIN,				
	zREVERB_PARKINGLOT,			
	zREVERB_SEWERPIPE,			
	zREVERB_UNDERWATER,			
	zREVERB_DRUGGED,			
	zREVERB_DIZZY,				
	zREVERB_PSYCHOTIC			
};



const int	zSND_FREQ_DEFAULT		= -1;
const float zSND_PAN_DEFAULT		= -2;
const float zSND_PAN_LEFT			=-1.0F;
const float zSND_PAN_CENTER			= 0.0F;
const float zSND_PAN_RIGHT			= 1.0F;
const float	zSND_PAN_SURROUND		= 100.0F;
#define		zSND_VOL_DEFAULT		float(-1)
#define		zSND_RADIUS_DEFAULT		float(-1)
#define		zSND_PITCH_DEFAULT		float(-999999)
const int	zSND_SLOT_NONE			=  0;	
const int	zSND_SLOT_MAX			=  8;	

class zCSoundSystem
{
	friend class zCSndSys_MSS;
public:
	enum zTLoopType { zSND_LOOPING_DEFAULT=0, zSND_LOOPING_ENABLED, zSND_LOOPING_DISABLED };

	struct zTSound3DParams
	{
		float		obstruction;			
		float		volume;					
		float		radius;					
		zTLoopType	loopType;				
		float		coneAngleDeg;			
		float		reverbLevel;			
		BOOL		isAmbient3D;			
		float		pitchOffset;				

		void		SetDefaults()
		{ 
			obstruction		= 0; 
			volume			= 1;
			radius			= zSND_RADIUS_DEFAULT; 
			loopType		= zSND_LOOPING_DEFAULT;
			coneAngleDeg	= 0; 
			reverbLevel		= 1; 
			isAmbient3D		= FALSE; 
			pitchOffset		= zSND_PITCH_DEFAULT;
		};
	};

	virtual	~zCSoundSystem() {};

	virtual	zCSoundFX*			LoadSoundFX				(const zSTRING& fileName)			{ return 0; };	
	virtual	zCSoundFX*			LoadSoundFXScript		(const zSTRING& scriptIdentifier)	{ return 0; };
	virtual zCParser*			GetSFXParser			()									{ return 0; };
	virtual float				GetPlayingTimeMSEC		(const zSTRING& fileName)			{ return 0; };	

	virtual	void				SetSound3DDefaultRadius	(float defRad)	{ defaultRadius=defRad; };			
	virtual	float				GetSound3DDefaultRadius	() const		{ return defaultRadius; };

	virtual	void				SetMasterVolume			(float vol)		{};									
	virtual	float				GetMasterVolume			()				{ return 1.0F; };					

	virtual	zTSoundHandle		PlaySound				(zCSoundFX*			sfx, int slot=zSND_SLOT_NONE)=0;
	virtual	zTSoundHandle		PlaySound				(zCSoundFX*			sfx, int slot, int freq, float vol, float pan)=0;
	virtual	zTSoundHandle		PlaySound3D				(zCSoundFX*			sfx,						
														 zCVob*				sourceVob, 
														 int				vobSlot=zSND_SLOT_NONE, 
														 zTSound3DParams	*sound3DParams=0)=0;
	virtual	zTSoundHandle		PlaySound3D				(const zSTRING&		soundName,					
														 zCVob*				sourceVob, 
														 int				vobSlot=zSND_SLOT_NONE, 
														 zTSound3DParams	*sound3DParams=0)=0;
	virtual	void				StopSound				(const zTSoundHandle& sfxHandle) {};
	virtual	void				StopAllSounds			()								 {};
	virtual	BOOL				GetSound3DProps			(const zTSoundHandle& sfxHandle, zTSound3DParams &sound3DParams)=0;
	virtual	BOOL				UpdateSound3D			(const zTSoundHandle& sfxHandle, zTSound3DParams *sound3DParams=0)=0;				
	virtual	void				GetSoundProps			(const zTSoundHandle& sfxHandle, int &freq, float &vol, float &pan) {};		
	virtual	void				UpdateSoundProps		(const zTSoundHandle& sfxHandle, int freq=zSND_FREQ_DEFAULT, float vol=zSND_VOL_DEFAULT, float pan=zSND_PAN_DEFAULT) {};
	virtual	BOOL				IsSoundActive			(const zTSoundHandle& sfxHandle) { return FALSE; };

	virtual	void				DoSoundUpdate			()=0;							
	virtual	void				SetListener				(zCVob* listenerVob) {};		

	
	
	
	virtual	void				SetGlobalReverbPreset	(int i, float weight)	{ };			
	virtual void				SetReverbEnabled		(const BOOL bReverbEn) { };
	virtual BOOL				GetReverbEnabled		()						{ return TRUE;	};

	
	virtual	int					GetNumProvider			()						{ return 1;		};
	virtual	const zSTRING*		GetProviderName			(int i)					{ return 0;		};
	virtual	BOOL				SetProvider				(int i)					{ return TRUE;	};

	
	enum zTSpeakerType
	{
		zSPEAKER_TYPE_2_SPEAKER=0,
		zSPEAKER_TYPE_HEADPHONE,
		zSPEAKER_TYPE_SURROUND,
		zSPEAKER_TYPE_4_SPEAKER,
		zSPEAKER_TYPE_51_SPEAKER,
		zSPEAKER_TYPE_71_SPEAKER,
		zMaxSpeakerType
	};
	virtual void				SetSpeakerType			(const zTSpeakerType speakerType)	{};
	virtual zTSpeakerType		GetSpeakerType			()									{ return zSPEAKER_TYPE_2_SPEAKER; };

	
	virtual void				SetGlobalOcclusion		(float occlusion)=0;			
	virtual	float				GetCPULoad				()		{ return -1.0F; };		
protected:
	float	defaultRadius;
};


class zCDrvProperties_MSS
{
	friend class zCSndSys_MSS;
public:

	static int	GetScriptClassSize()
	{
		zCDrvProperties_MSS tmp;
		return int(&tmp.dScriptEnd)-int(&tmp.volume);
	}

	int	ProviderNameToIndex(const zSTRING &n)
	{
		for (int i=0; i<numProviders; i++) if (provNames[i] == n) return i;
		return -1;
	}

	
	float	volume;
	int		bitResolution;
	int		sampleRate;
	int		useStereo;
	int		numSFXChannels;
	zSTRING use3dProvider;

	

	BYTE	dScriptEnd;

	
	PCMWAVEFORMAT   waveFormat;
	signed long		providers[20];			
	zSTRING			provNames[20];
	int				numProviders;
};

enum { zSND_CHANNEL_FRAME_RANDOM =-1 };

class zCSoundFX : public zCResource
{
public:
	static zCClassDef *classDef;
	void zSoundFX(void)
	{
		XCALL(0x004EDF50);
	};

	zCSoundFX(void)
	{
		zSoundFX();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004EDF40);
	};

	virtual ~zCSoundFX()
	{
		XCALL(0x004EDF70);
	};

	const zSTRING&				GetName					() const					{ return GetObjectName(); };
																					
	
	virtual int					GetNumChannels			() const					{ return 0; };
	virtual int					GetNumChannelFrames		(int channel) const			{ return 0; };
	virtual	void				GetChannelFrame			(int channel, int frameNr) const {};
	virtual	void				SetChannelFrame			(int channel, int frameNr)	{};

	virtual float				GetPlayingTimeMSEC		() const					{ return 0; };	
	virtual	float				GetPan					() const					{ return 0; };
	virtual	void				SetPan					(float pan)					{};
	virtual	float				GetVolume				() const					{ return 0; };
	virtual	void				SetVolume				(float vol)					{};
	virtual	int					GetFrequency			() const					{ return 0; };
	virtual	void				SetFrequency			(int freq)					{};
																					
	virtual	void				SetLooping				(BOOL b)					{};
	virtual	BOOL				IsLooping				() const					{ return FALSE; };

	
	virtual	void				SetIsFixed				(BOOL b)					{};
	virtual	BOOL				GetIsFixed				() const					{ return FALSE; };


	
	virtual void				GetCacheConfig			(DWORD &cacheOutTimeMSec, DWORD &cacheSizeMaxBytes)
	{
		XCALL(0x005EC090);
	};
};












enum zTMus_TransType	{ 
	zMUS_TR_DEFAULT		= 0, 
	zMUS_TR_NONE		= 1,
	zMUS_TR_GROOVE		= 2,
	zMUS_TR_FILL		= 3, 
	zMUS_TR_BREAK		= 4, 
	zMUS_TR_INTRO	    = 5, 
	zMUS_TR_END			= 6,
	zMUS_TR_ENDANDINTRO = 7
};


enum zTMus_TransSubType  { 
	zMUS_TRSUB_DEFAULT  = 0,
	zMUS_TRSUB_IMMEDIATE= 1, 
	zMUS_TRSUB_BEAT		= 2, 
	zMUS_TRSUB_MEASURE	= 3
};

enum zTMus_EventType {
	zMUS_EVENT_THEME_CHG = 1,
	zMUS_EVENT_BEAT		 = 2,
	zMUS_EVENT_MEASURE	 = 4,
	zMUS_EVENT_TRANSITION= 8
};


const float zMUS_JINGLE_VOL_DEFAULT = -1;
const float zMUS_THEME_VOL_DEFAULT  = -1;


class zCMusicTheme {
protected:
	zSTRING			    fileName;
	float				vol;
	zBOOL				loop;
	float				reverbMix;		
	float				reverbTime;		
	zTMus_TransType		trType;
	zTMus_TransSubType	trSubType;
	BYTE				dScriptEnd;
	zSTRING				name;
public:	
	
	static int  GetScriptClassSize	 ()									{
		zCMusicTheme tmp;
		return int(&tmp.dScriptEnd)-int(&tmp.fileName);
	}

			 zCMusicTheme () {};
	virtual ~zCMusicTheme () {};

	const zSTRING&		GetName				 ()		   { return name;	   };
	const zSTRING&		GetFileName			 ()		   { return fileName;};
	zTMus_TransType		GetTransitionType	 () const  { return trType;    };
	zTMus_TransSubType  GetTransitionSubType () const  { return trSubType; };
	zBOOL				GetIsLooping		 () const  { return loop;	   };
	float				GetVolume			 () const  { return vol;	   };	
	float				GetReverbMix		 () const  { return reverbMix; };	
	float				GetReverbTime	     () const  { return reverbTime;};	

	void SetName			 ( const zSTRING &id   )			{ name		= id;	 };
	void SetFileName		 ( const zSTRING &name  )			{ fileName	= name;  };
	void SetTransitionType	 ( const zTMus_TransType &tr )		{ trType	= tr;    };
	void SetTransitionSubType( const zTMus_TransSubType &trSub ){ trSubType	= trSub; };
	void SetIsLooping		 ( const zBOOL b )					{ loop		= b;     };
	void SetVolume			 ( const float v )					{ vol		= v;	 };			
	void SetReverbMix		 ( const float r )					{ reverbMix = r;	 };	
	void SetReverbTime	     ( const float r )					{ reverbTime = r;	 };	
	
		
	
	virtual zBOOL	IsActive ()	const			   { return FALSE;	   };
};



typedef int zTMus_JingleHandle;

class zCMusicJingle {
			
protected:
	zSTRING			   fileName;
private:
	zBOOL			   loop;
	float			   vol;
	zTMus_TransSubType trSubType;	
	BYTE			   dScriptEnd;
protected:
	int				   refCtr;
	zSTRING			   name;

public:	

	static int  GetScriptClassSize	 ()									{
		zCMusicJingle tmp;
		return int(&tmp.dScriptEnd)-int(&tmp.fileName);
	}

			 zCMusicJingle() {  refCtr = 1; };
	virtual ~zCMusicJingle() {};
	
	const	zSTRING&		GetName					() const	{ return name;       };
	const	zSTRING&		GetFileName				() const	{ return fileName; };
	zTMus_TransSubType		GetTransitionSubType	() const	{ return trSubType;  };
	int						GetRefCtr				() const	{ return refCtr;     };

	void					SetName					( const zSTRING &n    )				{ name = n; };
	void					SetFileName				( const zSTRING &name )				{ fileName = name;	 };
	void					SetTransitionSubType    ( const zTMus_TransSubType &trSub ) { trSubType = trSub; };

	virtual zCMusicJingle*	AddRef					()			{ ++refCtr; return this; };
	virtual int				Release					()			{ delete this; return 0; };
	zBOOL					GetIsLooping			() const	{ return loop;	   };
	virtual zBOOL			IsPlaying			    () const    { return FALSE;  };
	virtual void			StopPlaying				()			{};

	virtual	void			CacheIn					() {};
	virtual	void			CacheOut				() {};
};



class zCMusicSystem {
protected:
	float volume;
	float reverb; 

	static zBOOL s_musicSystemDisabled;
public:

	static void		DisableMusicSystem(zBOOL disable=TRUE);
	static zBOOL	IsMusicSystemDisabled()					{ return s_musicSystemDisabled; };

    virtual ~zCMusicSystem(){}; 

	
	virtual void		  PlayThemeByScript( const zSTRING &id, const int manipulate = 0, zBOOL *done = NULL )				{};	

	
	virtual zCMusicTheme *LoadThemeByScript( const zSTRING &id )				{	return 0;	};
	virtual zCMusicTheme *LoadTheme		   ( const zSTRING &file )				{	return 0;	};
	virtual void		  PlayTheme		   ( zCMusicTheme		*theme,
										     const float				&volume = zMUS_THEME_VOL_DEFAULT,
										     const zTMus_TransType		&tr		= zMUS_TR_DEFAULT,
										     const zTMus_TransSubType	&trSub  = zMUS_TRSUB_DEFAULT )	{};

	virtual zCMusicTheme  *GetActiveTheme ()									{	return 0;	};

	

	
	
	virtual zTMus_JingleHandle PlayJingleByScript( const zSTRING &id   )			{   return 0;   };
	virtual void		   StopJingleByScript( const zSTRING &id   )			{};

	
	virtual zCMusicJingle *LoadJingleByScript( const zSTRING &id   )			{	return 0;	};
	virtual zCMusicJingle *LoadJingle		 ( const zSTRING &file )			{	return 0;	};
	
	virtual zTMus_JingleHandle PlayJingle	 ( const zCMusicJingle	*jingle,
										   const float				&volume = zMUS_JINGLE_VOL_DEFAULT,
										   const zTMus_TransSubType &trSub  = zMUS_TRSUB_DEFAULT ) { return 0; };

	virtual	void		   StopJingle	 (const zTMus_JingleHandle& jHandle) {};
	virtual	zBOOL		   IsJingleActive(const zTMus_JingleHandle& jHandle) { return FALSE; };

	virtual	void		   DoMusicUpdate	 ()=0;	

	
	virtual void	AddEventCallBackFunc	( const zTMus_EventType &flags, void (*ev)(const zTMus_EventType &occuredEvents) ) {};
	virtual void	RemoveEventCallBackFunc ( void (*ev)(const zTMus_EventType &occuredEvents) ) {};

	virtual void	Mute()										{};
	virtual void	Stop()										{};

	virtual void	SetVolume		  ( const float v )			{ volume = v; };   
	virtual float	GetVolume		  ( )	const				{ return volume; };
	virtual zBOOL	IsAvailable		  ( const zSTRING &id )		{ return FALSE; }; 

};

class zCSndSys_MSS : public zCSoundSystem
{
public:
	static zCDrvProperties_MSS	prefs;
	zTSpeakerType				speakerType;
	int							globalReverbPreset;
	zBOOL						m_bReverbEnabled;
};