#pragma once
#include "zctexture.h"
#include "zRNDManager.h"
class oCBarrier;
struct zTRenderContext;
enum zTRnd_AlphaBlendFunc;
class zCSoundFX;

enum zESkyLayerMode
{
	zSKY_MODE_POLY,
	zSKY_MODE_BOX
};

enum zTWeather
{
	zTWEATHER_SNOW,
	zTWEATHER_RAIN
};
const int zSKY_NUM_LAYER = 2;

enum zTSkyStateEffect
{
	zSKY_STATE_EFFECT_SUN,
	zSKY_STATE_EFFECT_CLOUDSHADOW,
};

class zCOutdoorRainFX 
{
public:
	float					GetEffectWeight			() const				{ return m_effectWeight; };
	BOOL					AreParticlesActive		() const { return ((m_numImpactParticle>0) && (m_numFlyParticle<=0)); };
private:
	enum					{ zEFFECT_BOX_SIDES	= 2500		};
	enum					{ zEFFECT_BOX_HEIGHT	= 1000	};
	enum					{ zMAX_FLY_PARTICLE		= 1024	};
	enum					{ zMAX_IMPACT_PARTICLE	= 1024	};
	enum					{ zCACHE_SIZE			= 512	};		
	struct zSParticle
	{
		float				m_killTotalTime;		
		zVEC3				m_destPosition;
		zVEC3				m_destNormal;

		BOOL				IsActive				() const	{ return (m_killTotalTime<=1);	};
		void				SetInactive				()			{ m_killTotalTime=99;			};
		void				SetInFreeList			()			{ m_killTotalTime=100;			};
		BOOL				IsInFreeList			() const	{ return (m_killTotalTime>=100);};
	};

	zSParticle				m_flyParticleList		[zMAX_FLY_PARTICLE];
	zSParticle				m_impactParticleList	[zMAX_IMPACT_PARTICLE];
	int						m_numFlyParticle;
	int						m_numImpactParticle;
	zCArray<zSParticle*>	m_freeFlyParticleList;

	float					m_effectWeight;			
	int						m_numDestFlyParticle;		
	zVEC3					m_camPosLastFrame;
	zTWeather				m_enuWeather;

	
	struct zSCacheElement
	{
		zVEC3				m_position;
		zVEC3				m_normal;
	};
	zSCacheElement			m_cache[zCACHE_SIZE];
	int						m_currentCacheIndex;

	
	zCShader				m_shader;
	zCShaderStage			m_shaderStage;
	zCTexture*				m_raindropTexture;
	zCTexture*				m_rainTexture;
	zCMaterial*				m_rainMaterial;

	
	zCSoundFX*				m_soundEffect;
	zTSoundHandle			m_soundHandle;
	BOOL					m_soundActive;

	
	zVEC3					m_positionUpdateVector;
	float					m_velocityLen;
	float					m_timeLen;
	inline BOOL			IsInEffectBox			(const zVEC3& posRel)
	{
		const float zEFFECT_BOX_SIDES_SMALL		= zEFFECT_BOX_SIDES * float(0.7F);
		const float zEFFECT_BOX_HEIGHT_SMALL	= zEFFECT_BOX_HEIGHT* float(0.8F);

		return ((posRel[VX]<= zEFFECT_BOX_SIDES_SMALL)	&&
				(posRel[VX]>=-zEFFECT_BOX_SIDES_SMALL)	&&
				(posRel[VY]<= zEFFECT_BOX_HEIGHT_SMALL)	&&
				(posRel[VY]>=-zEFFECT_BOX_HEIGHT_SMALL)	&&
				(posRel[VZ]<= zEFFECT_BOX_SIDES_SMALL)	&&
				(posRel[VZ]>=-zEFFECT_BOX_SIDES_SMALL));
	};
};

class zCSkyControler : public zCObject
{
public:
	enum zTCamLocationHint
	{
		zCAM_OUTSIDE_SECTOR,
		zCAM_INSIDE_SECTOR_CANT_SEE_OUTSIDE,
		zCAM_INSIDE_SECTOR_CAN_SEE_OUTSIDE,
	};

	zCOLOR						*polyLightCLUTPtr;
	float						cloudShadowScale;
	BOOL						m_bColorChanged;
	zTWeather					m_enuWeather;

public:
	
	
	zCOLOR						backgroundColor;
	BOOL						fillBackground;
	zCTexture*					backgroundTexture;
	zTFrameCtr					relightCtr;
	float						lastRelightTime;
	float						m_fRelightTime;

	static zCClassDef* classDef;
	void zSkyControler(void)
	{
		XCALL(0x005DF6B0);
	};

	zCSkyControler(void)
	{
		zSkyControler();
	};

	void ClearBackground( zCOLOR)
	{
		XCALL(0x005DF930);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005DF6A0);
	};

	virtual ~zCSkyControler()
	{
		XCALL(0x005DF8C0);
	};

	virtual float GetCloudShadowScale(void)const 
	{
		XCALL(0x005DF420);
	};

	virtual void SetCloudShadowScale(float)
	{
		XCALL(0x005DF430);
	};

	virtual void SetFillBackground(int)
	{
		XCALL(0x005DF440);
	};

	virtual int GetFillBackground(void)const 
	{
		XCALL(0x005DF450);
	};

	virtual void SetLightDirty(void)
	{
		XCALL(0x005DF460);
	};

	virtual void SetRelightTime(float)
	{
		XCALL(0x005DF470);
	};

	virtual int GetRelightCtr(void)
	{
		XCALL(0x005DF480);
	};

	virtual  zCOLOR GetDaylightColorFromIntensity(int)
	{
		XCALL(0x005DF490);
	};

	virtual int GetGlobalWindVec(zVEC3&,int)
	{
		XCALL(0x005DF4B0);
	};

	virtual void SetGlobalSkyScale(float)
	{
		XCALL(0x005DF4C0);
	};

	virtual float GetGlobalSkyScale(void)const 
	{
		XCALL(0x005DF4D0);
	};

	virtual int GetGlobalSkyScaleChanged(void)const 
	{
		XCALL(0x005DF4E0);
	};

	virtual void SetCameraLocationHint(zCSkyControler::zTCamLocationHint)
	{
		XCALL(0x005DF4F0);
	};

	virtual void SetWeatherType(zTWeather)
	{
		XCALL(0x005DF500);
	};

	virtual zTWeather GetWeatherType(void)const 
	{
		XCALL(0x005DF510);
	};

	static int zCSkyControler::s_skyEffectsEnabled;
	static zCSkyControler*& zCSkyControler::s_activeSkyControler;
};

class zCSkyLayerData
{
public:
	zESkyLayerMode	skyMode;
	zCTexture		*tex;
	zSTRING			texName;
	float			texAlpha;
	float			texScale;
	zVEC2			texSpeed;
	zCSkyLayerData(void)
	{
		XCALL(0x005E4200);
	};

	~zCSkyLayerData(void)
	{
		XCALL(0x005E4320);
	};
};

class zCSkyState			
{
public:
	float			time;
	zVEC3			polyColor;
	zVEC3			fogColor;
	zVEC3			domeColor1;
	zVEC3			domeColor0;
	float			fogDist;
	BOOL			sunOn;
	int				cloudShadowOn;
	zCSkyLayerData	layer[zSKY_NUM_LAYER];

	void PresetDay0(void)
	{
		XCALL(0x005E3790);
	};

	void PresetDay1(void)
	{
		XCALL(0x005E3920);
	};

	void PresetDay2(void)
	{
		XCALL(0x005E3AA0);
	};

	void PresetEvening(void)
	{
		XCALL(0x005E3B70);
	};

	void PresetNight0(void)
	{
		XCALL(0x005E3C40);
	};

	void PresetNight1(void)
	{
		XCALL(0x005E3E30);
	};

	void PresetNight2(void)
	{
		XCALL(0x005E3FB0);
	};

	void PresetDawn(void)
	{
		XCALL(0x005E4130);
	};

	zCSkyState(void)
	{
		XCALL(0x005E43B0);
	};

	~zCSkyState(void)
	{
		XCALL(0x005E43E0);
	};
};

class zCSkyControlerMid : public zCSkyControler
{
public:
	BOOL						underwaterFX;
	zCOLOR						underwaterColor;
	float						underwaterFarZ;

	float						underwaterStartTime;
	float						oldFovX;
	float						oldFovY;

	
	zCVob						*vobUnderwaterPFX;

	zCPolygon					*scrPoly;
	zCMesh						*scrPolyMesh;
	int							scrPolyAlpha;
	zCOLOR						scrPolyColor;
	zTRnd_AlphaBlendFunc		scrPolyAlphaFunc;
	static zCClassDef* classDef;
	void zSkyControler_Mid(void)
	{
		XCALL(0x005DFBF0);
	};

	zCSkyControlerMid(void)
	{
		zSkyControler_Mid();
	};

	void InitUnderwaterPFX(void)
	{
		XCALL(0x005DFC90);
	};

	void InitScreenBlend(void)
	{
		XCALL(0x005E0310);
	};

	void RenderScreenBlend(void)
	{
		XCALL(0x005E0430);
	};

	void SetScreenBlendAlpha(int)
	{
		XCALL(0x005E05F0);
	};

	void SetScreenBlendColor( zCOLOR const&)
	{
		XCALL(0x005E0610);
	};

	void SetScreenBlendAlphaFunc(zTRnd_AlphaBlendFunc)
	{
		XCALL(0x005E0620);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005DF520);
	};

	virtual ~zCSkyControlerMid()
	{
		XCALL(0x005DFF20);
	};

	virtual float GetCloudShadowScale(void)const 
	{
		XCALL(0x005DF420);
	};

	virtual void SetCloudShadowScale(float)
	{
		XCALL(0x005DF430);
	};

	virtual void SetFillBackground(int)
	{
		XCALL(0x005DF440);
	};

	virtual int GetFillBackground(void)const 
	{
		XCALL(0x005DF450);
	};

	virtual void SetUnderwaterFX(int)
	{
		XCALL(0x005DFFE0);
	};

	virtual int GetUnderwaterFX(void)const 
	{
		XCALL(0x005E0050);
	};

	virtual void SetLightDirty(void)
	{
		XCALL(0x005DF460);
	};

	virtual void SetRelightTime(float)
	{
		XCALL(0x005DF470);
	};

	virtual int GetRelightCtr(void)
	{
		XCALL(0x005DF480);
	};

	virtual  zCOLOR GetDaylightColorFromIntensity(int)
	{
		XCALL(0x005DF490);
	};

	virtual void RenderSkyPre(void)
	{
		XCALL(0x005E0060);
	};

	virtual void RenderSkyPost(int)
	{
		XCALL(0x005E0130);
	};

	virtual int GetGlobalWindVec(zVEC3&,int)
	{
		XCALL(0x005DF4B0);
	};

	virtual void SetGlobalSkyScale(float)
	{
		XCALL(0x005DF4C0);
	};

	virtual float GetGlobalSkyScale(void)const 
	{
		XCALL(0x005DF4D0);
	};

	virtual int GetGlobalSkyScaleChanged(void)const 
	{
		XCALL(0x005DF4E0);
	};

	virtual void SetCameraLocationHint(zCSkyControler::zTCamLocationHint)
	{
		XCALL(0x005DF4F0);
	};

	virtual void SetWeatherType(zTWeather)
	{
		XCALL(0x005DF500);
	};

	virtual zTWeather GetWeatherType(void)const 
	{
		XCALL(0x005DF510);
	};
};

class zCSkyControlerIndoor : public zCSkyControlerMid
{
	float						userFarZ;
	float						userFarZScalability;
	float						time;
public:
	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005DF550);
	};

	virtual ~zCSkyControlerIndoor()
	{
		XCALL(0x005DF5E0);
	};

	virtual void SetTime(float)
	{
		XCALL(0x005E06D0);
	};

	virtual float GetTime(void)const 
	{
		XCALL(0x005DF560);
	};

	virtual void ResetTime(void)
	{
		XCALL(0x005DF570);
	};

	virtual void SetFarZ(float)
	{
		XCALL(0x005E0770);
	};

	virtual float GetFarZ(void)const 
	{
		XCALL(0x005E0780);
	};

	virtual void SetFarZScalability(float)
	{
		XCALL(0x005E0790);
	};

	virtual float GetFarZScalability(void)const 
	{
		XCALL(0x005E07E0);
	};

	virtual void SetBackgroundColor( zCOLOR)
	{
		XCALL(0x005E07F0);
	};

	virtual  zCOLOR GetBackgroundColor(void)const 
	{
		XCALL(0x005E0800);
	};

	virtual  zCOLOR GetBackgroundColorDef(void)const 
	{
		XCALL(0x005E0810);
	};

	virtual void SetOverrideColor(zVEC3)
	{
		XCALL(0x005DF580);
	};

	virtual void SetOverrideColorFlag(int)
	{
		XCALL(0x005DF590);
	};

	virtual float GetCloudShadowScale(void)const 
	{
		XCALL(0x005DF420);
	};

	virtual void SetCloudShadowScale(float)
	{
		XCALL(0x005DF430);
	};

	virtual void SetFillBackground(int)
	{
		XCALL(0x005DF440);
	};

	virtual int GetFillBackground(void)const 
	{
		XCALL(0x005DF450);
	};

	virtual void SetUnderwaterFX(int)
	{
		XCALL(0x005DFFE0);
	};

	virtual int GetUnderwaterFX(void)const 
	{
		XCALL(0x005E0050);
	};

	virtual void UpdateWorldDependencies(void)
	{
		XCALL(0x005DF5A0);
	};

	virtual void SetLightDirty(void)
	{
		XCALL(0x005DF460);
	};

	virtual void SetRelightTime(float)
	{
		XCALL(0x005DF470);
	};

	virtual int GetRelightCtr(void)
	{
		XCALL(0x005DF480);
	};

	virtual  zCOLOR GetDaylightColorFromIntensity(int)
	{
		XCALL(0x005DF490);
	};

	virtual void RenderSkyPre(void)
	{
		XCALL(0x005E0820);
	};

	virtual void RenderSkyPost(int)
	{
		XCALL(0x005E08C0);
	};

	virtual int GetGlobalWindVec(zVEC3&,int)
	{
		XCALL(0x005DF4B0);
	};

	virtual void SetGlobalSkyScale(float)
	{
		XCALL(0x005DF4C0);
	};

	virtual float GetGlobalSkyScale(void)const 
	{
		XCALL(0x005DF4D0);
	};

	virtual int GetGlobalSkyScaleChanged(void)const 
	{
		XCALL(0x005DF4E0);
	};

	virtual void SetCameraLocationHint(zCSkyControler::zTCamLocationHint)
	{
		XCALL(0x005DF4F0);
	};

	virtual void SetWeatherType(zTWeather)
	{
		XCALL(0x005DF500);
	};

	virtual zTWeather GetWeatherType(void)const 
	{
		XCALL(0x005DF510);
	};
};

class zCSkyLayer
{
public:
	zCMesh*			skyPolyMesh;
	zCPolygon*		skyPoly;
	zVEC2			skyTexOffs;
	zCMesh*			skyDomeMesh;
	zESkyLayerMode	skyMode;
};

class zCSkyPlanet
{
public:
	zCMesh					*mesh;
	zVEC4					color0;
	zVEC4					color1;
	float					size;
	zVEC3					pos;
	zVEC3					rotAxis;

	zCSkyPlanet()
	{
		mesh = 0;
	};
	~zCSkyPlanet()
	{
		zRELEASE (mesh);
	};
};

class zCSkyControlerOutdoor : public zCSkyControlerMid
{
public:
	BOOL						initDone;
	float						masterTime;
	float						masterTimeLast;
	zCSkyState					masterState;
	zCSkyState*					state0;
	zCSkyState*					state1;
	zCArray<zCSkyState*>		stateList;
	zCOLOR						polyLightCLUT[256];
	float						dayCounter;				
	zCArray<zVEC3>				fogColorDayVariations;
	zCArray<zVEC3>				fogColorDayVariations2;
	float						m_fSkyScale;
	BOOL						m_bSkyScaleChanged;
	zVEC3						m_overrideColor;
	BOOL						m_bOverrideColorFlag;
	BOOL						m_bDontRain;
	BOOL						m_bLevelChanged;
	BOOL						m_bDarkSky;	

								
	
	float						resultFogScale;
	float						heightFogMinY;
	float						heightFogMaxY;
	float						userFogFar;
	float						resultFogNear;
	float						resultFogFar;
	float						resultFogSkyNear;
	float						resultFogSkyFar;
	zCOLOR						resultFogColor;
	zCOLOR						resultFogColorOverride;
	float						userFarZScalability;
								
	zCSkyState*					skyLayerState[2];
	zCSkyLayer					skyLayer[2];
	zCSkyLayer					skyLayerRainClouds;
	zCTexture*					skyCloudLayerTex;


	
	enum
	{
		NUM_PLANETS = 2
	};
	zCSkyPlanet					planets[NUM_PLANETS];
	BOOL						m_bSunVisible;
	float						m_fFadeScale;
								
	
	zCVob						*vobSkyPFX;
	float						skyPFXTimer;

	
	BOOL						m_bIsMainControler;				
	zVEC3						m_bWindVec;

	
	struct zTRainFX
	{
		zCOutdoorRainFX			*outdoorRainFX;
		zTCamLocationHint		camLocationHint;
		float					outdoorRainFXWeight;				
		float					soundVolume;						
		float					timerInsideSectorCantSeeOutside;	
		float					timeStartRain;
		float					timeStopRain;
		BOOL					renderLightning;
		BOOL					m_bRaining;							
		int						m_iRainCtr;							

	} rainFX;
public:
	void zSkyControlerOutdoor(int)
	{
		XCALL(0x005E6220);
	};

	zCSkyControlerOutdoor()
	{
		zSkyControlerOutdoor(0);
	};

	void Init(void)
	{
		XCALL(0x005E6A00);
	};

	int GetStateTextureSearch(int,int,int)
	{
		XCALL(0x005E7310);
	};

	void ApplyStateTexToLayer(int,int)
	{
		XCALL(0x005E7360);
	};

	void RenderPlanets(float)
	{
		XCALL(0x005E7830);
	};

	void ReadFogColorsFromINI(void)
	{
		XCALL(0x005E7EA0);
	};

	void __fastcall ApplyFogColorsFromINI(int)
	{
		XCALL(0x005E85F0);
	};

	void CreateDefault(void)
	{
		XCALL(0x005E86D0);
	};

	void Interpolate(void)
	{
		XCALL(0x005E8C20);
	};

	void CalcPolyLightCLUT(zVEC3 const&,zVEC3 const&)
	{
		XCALL(0x005E93C0);
	};

	void InitSkyPFX(void)
	{
		XCALL(0x005E94E0);
	};

	void CalcFog(void)
	{
		XCALL(0x005E96C0);
	};

	void RenderSkyPFX(void)
	{
		XCALL(0x005E9ED0);
	};

	void CalcGlobalWind(void)
	{
		XCALL(0x005EA210);
	};

	void ProcessRainFX(void)
	{
		XCALL(0x005EAF30);
	};

	void SetRainFXWeight(float,float)
	{
		XCALL(0x005EB230);
	};

	void RenderSetup(void)
	{
		XCALL(0x005EB360);
	};

	void RenderSky(void)
	{
		XCALL(0x005EB3D0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005E66E0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x005EB640);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x005EB730);
	};

	virtual ~zCSkyControlerOutdoor(void)
	{
		XCALL(0x005E67F0);
	};

	virtual void SetTime(float)
	{
		XCALL(0x005E9350);
	};

	virtual float GetTime(void)const 
	{
		XCALL(0x005E66F0);
	};

	virtual void ResetTime(void)
	{
		XCALL(0x005E9380);
	};

	virtual void SetFarZ(float)
	{
		XCALL(0x005E9E50);
	};

	virtual float GetFarZ(void)const 
	{
		XCALL(0x005E9E60);
	};

	virtual void SetFarZScalability(float)
	{
		XCALL(0x005E9E70);
	};

	virtual float GetFarZScalability(void)const 
	{
		XCALL(0x005E9EC0);
	};

	virtual void SetBackgroundColor( zCOLOR)
	{
		XCALL(0x005E6700);
	};

	virtual  zCOLOR GetBackgroundColor(void)const 
	{
		XCALL(0x005E6710);
	};

	virtual  zCOLOR GetBackgroundColorDef(void)const 
	{
		XCALL(0x005E6740);
	};

	virtual void SetOverrideColor(zVEC3)
	{
		XCALL(0x005E6750);
	};

	virtual void SetOverrideColorFlag(int)
	{
		XCALL(0x005E6770);
	};

	virtual float GetCloudShadowScale(void)const 
	{
		XCALL(0x005EA7F0);
	};

	virtual void SetCloudShadowScale(float)
	{
		XCALL(0x005EA810);
	};

	virtual void SetFillBackground(int)
	{
		XCALL(0x005DF440);
	};

	virtual int GetFillBackground(void)const 
	{
		XCALL(0x005DF450);
	};

	virtual void SetUnderwaterFX(int)
	{
		XCALL(0x005DFFE0);
	};

	virtual int GetUnderwaterFX(void)const 
	{
		XCALL(0x005E0050);
	};

	virtual void UpdateWorldDependencies(void)
	{
		XCALL(0x005E72C0);
	};

	virtual void SetLightDirty(void)
	{
		XCALL(0x005DF460);
	};

	virtual void SetRelightTime(float)
	{
		XCALL(0x005DF470);
	};

	virtual int GetRelightCtr(void)
	{
		XCALL(0x005DF480);
	};

	virtual  zCOLOR GetDaylightColorFromIntensity(int)
	{
		XCALL(0x005E93A0);
	};

	virtual void RenderSkyPre(void)
	{
		XCALL(0x005EA850);
	};

	virtual void RenderSkyPost(int)
	{
		XCALL(0x005EB580);
	};

	virtual int GetGlobalWindVec(zVEC3&,int)
	{
		XCALL(0x005EA7B0);
	};

	virtual void SetGlobalSkyScale(float)
	{
		XCALL(0x005E7290);
	};

	virtual float GetGlobalSkyScale(void)const 
	{
		XCALL(0x005E67A0);
	};

	virtual int GetGlobalSkyScaleChanged(void)const 
	{
		XCALL(0x005E67B0);
	};

	virtual void SetCameraLocationHint(zCSkyControler::zTCamLocationHint)
	{
		XCALL(0x005E6790);
	};

	virtual void SetWeatherType(zTWeather)
	{
		XCALL(0x005EB830);
	};

	virtual zTWeather GetWeatherType(void)const 
	{
		XCALL(0x005DF510);
	};

	virtual int GetRenderLightning(void)const 
	{
		XCALL(0x005E6780);
	};
};

class oCSkyControler_Barrier : public zCSkyControlerOutdoor		
{
public:
	oCBarrier *barrier;
	BOOL       bFadeInOut;
public:
	
	void RenderSkyPre_AST(void);
	void oSkyControler_Barrier(void)
	{
		XCALL(0x006BB7B0);
	};

	oCSkyControler_Barrier(void)
	{
		oSkyControler_Barrier();
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x005E66E0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x005EB640);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x005EB730);
	};

	virtual ~oCSkyControler_Barrier()
	{
		XCALL(0x006BB860);
	};

	virtual void SetTime(float)
	{
		XCALL(0x005E9350);
	};

	virtual float GetTime(void)const 
	{
		XCALL(0x005E66F0);
	};

	virtual void ResetTime(void)
	{
		XCALL(0x005E9380);
	};

	virtual void SetFarZ(float)
	{
		XCALL(0x005E9E50);
	};

	virtual float GetFarZ(void)const 
	{
		XCALL(0x005E9E60);
	};

	virtual void SetFarZScalability(float)
	{
		XCALL(0x005E9E70);
	};

	virtual float GetFarZScalability(void)const 
	{
		XCALL(0x005E9EC0);
	};

	virtual void SetBackgroundColor( zCOLOR)
	{
		XCALL(0x005E6700);
	};

	virtual  zCOLOR GetBackgroundColor(void)const 
	{
		XCALL(0x005E6710);
	};

	virtual  zCOLOR GetBackgroundColorDef(void)const 
	{
		XCALL(0x005E6740);
	};

	virtual void SetOverrideColor(zVEC3)
	{
		XCALL(0x005E6750);
	};

	virtual void SetOverrideColorFlag(int)
	{
		XCALL(0x005E6770);
	};

	virtual float GetCloudShadowScale(void)const 
	{
		XCALL(0x005EA7F0);
	};

	virtual void SetCloudShadowScale(float)
	{
		XCALL(0x005EA810);
	};

	virtual void SetFillBackground(int)
	{
		XCALL(0x005DF440);
	};

	virtual int GetFillBackground(void)const 
	{
		XCALL(0x005DF450);
	};

	virtual void SetUnderwaterFX(int)
	{
		XCALL(0x005DFFE0);
	};

	virtual int GetUnderwaterFX(void)const 
	{
		XCALL(0x005E0050);
	};

	virtual void UpdateWorldDependencies(void)
	{
		XCALL(0x005E72C0);
	};

	virtual void SetLightDirty(void)
	{
		XCALL(0x005DF460);
	};

	virtual void SetRelightTime(float)
	{
		XCALL(0x005DF470);
	};

	virtual int GetRelightCtr(void)
	{
		XCALL(0x005DF480);
	};

	virtual  zCOLOR GetDaylightColorFromIntensity(int)
	{
		XCALL(0x005E93A0);
	};

	virtual void RenderSkyPre(void)
	{
		XCALL(0x006BB8D0);
	};

	virtual void RenderSkyPost(int)
	{
		XCALL(0x005EB580);
	};

	virtual int GetGlobalWindVec(zVEC3&,int)
	{
		XCALL(0x005EA7B0);
	};

	virtual void SetGlobalSkyScale(float)
	{
		XCALL(0x005E7290);
	};

	virtual float GetGlobalSkyScale(void)const 
	{
		XCALL(0x005E67A0);
	};

	virtual int GetGlobalSkyScaleChanged(void)const 
	{
		XCALL(0x005E67B0);
	};

	virtual void SetCameraLocationHint(zCSkyControler::zTCamLocationHint)
	{
		XCALL(0x005E6790);
	};

	virtual void SetWeatherType(zTWeather)
	{
		XCALL(0x005EB830);
	};

	virtual zTWeather GetWeatherType(void)const 
	{
		XCALL(0x005DF510);
	};

	virtual int GetRenderLightning(void)const 
	{
		XCALL(0x005E6780);
	};
};

enum zTThunderSector
{
	zTHUNDER_0,
	zTHUNDER_1,
	zTHUNDER_2,
	zTHUNDER_3,
	zTHUNDER_4
};

struct myVert			
{
	int		m_nIndex;			
	int		m_nIndexVert[8];	
	int		m_nSizeVert;		
	int		m_nIndexPoly[50];	
	int		m_nSizePoly;		

	myVert() 
	{ 
		
		m_nIndex = 0; 
		m_nSizeVert = 0; 
		m_nSizePoly = 0; 
	}
};

class zCPolyStrip;

struct myThunder		
{
	zVEC3			m_vPosition;		
	myThunder*		m_pSubThunders;		
	int				m_nNumSubThunders;	
	float			m_fSubStartSeg[3];	
	zCPolyStrip*	m_pPolyStrip;		
	int				m_nNumSegments;		
	BOOL			m_bActive;			
	float			m_nStartVisSeg;		
	float			m_nEndVisSeg;		
	int				m_nIndex;			
	int				us40;
	BOOL			m_bIsSubThunder;		
	zTThunderSector	m_Sector;			
	~myThunder(void)
	{
		XCALL(0x006B8F90);
	};

	myThunder(void)
	{
		XCALL(0x006B9CD0);
	};
};



class oCBarrier 
{
public:
	zCMesh*		m_pMesh;				
	int			myPolyList;				
	myVert*		m_pVert;				
	int			m_nSizeVert;			
	int			m_nSizePoly;			
	void*		m_pThunder;				
	int			m_nMaxThunders;			
	int			m_nNumThunders;			
	int			actualIndex;			
	int			rootBoltIndex;       
	int			m_nIndexThunder1[10];
	int			m_nSizeThunder1;
	int			m_nIndexThunder2[10];
	int			m_nSizeThunder2;
	int			m_nIndexThunder3[10];
	int			m_nSizeThunder3;	
	int			m_nIndexThunder4[10];
	int			m_nSizeThunder4;     
	int			m_nCurrentIndex;     
	int			m_bFadeCycle;    
	int			m_nAlphaFade;	
	int			m_bUpFade;      
	int			m_bDownFade;      
	int			bFlashing;  
	int			fFlashTime;
	void*		m_pSfxThunder1;
	int			m_nHandleThunder1;
	void*		m_pSfxThunder2;
	int			m_nHandleThunder2;
	void*		m_pSfxThunder3;
	int			m_nHandleThunder3;
	void*		m_pSfxThunder4;
	int			m_nHandleThunder4;
	void*		m_pDecal;
	BOOL		m_bThunder1;
	BOOL		m_bThunder2;
	BOOL		m_bThunder3;
	BOOL		m_bThunder4;		   
	zVEC2*		m_pTexUVs;
	// [AST]
	void Fading_AST(zTRenderContext &,BOOL bFade);
	void Initialise_AST();
	void RenderLayer_AST(zTRenderContext& cont, int layer);
	// [/AST]
	oCBarrier(void)
	{
		XCALL(0x006B8FC0);
	};

	~oCBarrier(void)
	{
		XCALL(0x006B9190);
	};

	void Init(void)
	{
		XCALL(0x006B9440);
	};

	void Initialise(int)
	{
		XCALL(0x006B9BF0);
	};

	void AddTremor( zTRenderContext&)
	{
		XCALL(0x006B9CE0);
	};

	void RenderLayer( zTRenderContext&,int,int&)
	{
		XCALL(0x006B9CF0);
	};

	int Render( zTRenderContext&,int,int)
	{
		XCALL(0x006B9F30);
	};

	void InitThunder( myThunder*)
	{
		XCALL(0x006BA9C0);
	};

	void RemoveThunder( myThunder*)
	{
		XCALL(0x006BA9F0);
	};

	int AddThunderSub( myThunder*,int,int,int,int)
	{
		XCALL(0x006BAAA0);
	};

	int AddThunder(int,int,float,zTThunderSector)
	{
		XCALL(0x006BADE0);
	};

	int RenderThunder( myThunder*, zTRenderContext&)
	{
		XCALL(0x006BB4B0);
	};

	void RenderThunderList( zTRenderContext&)
	{
		XCALL(0x006BB770);
	};

	
};


