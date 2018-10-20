#pragma once

#include "ztypes.h"
#include "zceventmessage.h"

class zCCSCamera;
class zCCSCamera_EventMsg;
class zCCSCamera_EventMsgActivate;



enum zTCamTrj_KeyMotionType
{
	UNDEF,		
	SMOOTH,		
	LINEAR,		
	STEP,		
	SLOW,		
	FAST,		
	CUSTOM		
};

enum zTKeyFrameType
{
	zKEYFR_UNKNOWN,	
	zKEYFR_TARGET,	
	zKEYFR_CAMERA	
};

class zCCamTrj_KeyFrame : public zCVob	
{
	friend class zCCSCamera;
public:
	float					m_fTime;				
	float					m_fAngleRollDeg;		
	float					m_fCamFOVScale;			
	zTCamTrj_KeyMotionType	m_MotionType;			
	zTCamTrj_KeyMotionType	m_MotionTypeFOV;		
	zTCamTrj_KeyMotionType	m_MotionTypeRoll;		
	zTCamTrj_KeyMotionType	m_MotionTypeTimeScale;	
	BOOL					m_bTimeIsFixed;			
	float					m_fTension;				
	float					m_fBias;				
	float					m_fContinuity;			
	float					m_fTimeScale;			
	zMAT4					m_mOriginalPose;		
	zMAT4					m_mCurrentPose;			
	BOOL					m_bAdjusting;			
	zCCSCamera*				m_pCSCamera;			
	zTKeyFrameType			m_KeyType;				
	static zCClassDef *classDef;
	void zCamTrj_KeyFrame(void)
	{
		XCALL(0x004BDE00);
	};

	zCCamTrj_KeyFrame(void)
	{
		zCamTrj_KeyFrame();
	};

	void Changed(void)
	{
		XCALL(0x004BE390);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004BDED0);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x004BE100);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x004BE250);
	};

	virtual ~zCCamTrj_KeyFrame()
	{
		XCALL(0x004BDF10);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x004BDF90);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x004BDFA0);
	};
};



typedef float (*zTCamLerpFunc)(float, float);

class zCCSCamera : public zCVob			
{
	friend class zCAICamera;
	friend class zCMovementTracker;
	friend class zCCamTrj_KeyFrame;

	int							m_CamTrjFOR;				
	int							m_TargetTrjFOR;				
	int							m_LoopMode;					
	zTSplLerpMode				m_SplLerpMode;				
	BOOL						m_bIgnoreFORVobRotCam;		
	BOOL						m_bIgnoreFORVobRotTarget;	
	BOOL						m_bAdaptToSurroundings;		
	BOOL						m_bEaseToFirstKey;			
	BOOL						m_bEaseFromLastKey;			
	float						m_fTotalTime;				
	zSTRING						m_sAutoCamFocusVobName;		
	BOOL						m_bAutoCamPlayerMovable;	
	BOOL						m_bAutoCamUntriggerOnLastKey;		
	float						m_fAutoCamUntriggerOnLastKeyDelay;	
	zCVob*						m_pCameraRefVob;			
	zCVob*						m_pTargetRefVob;			
	zCArray<zCEventMessage*>	m_arrActiveMsg;				
	zCArray<zCCamTrj_KeyFrame*>	m_arrCameraKeys;			
	zCArray<zCCamTrj_KeyFrame*>	m_arrTargetKeys;			
	BOOL						m_bPaused;					
	BOOL						m_bOnTrigger;				
	BOOL						m_bOnUntrigger;				
	BOOL						m_bNoActiveCamera;			
	zCVob*						m_pTriggeredVob;			
	BOOL						m_bKFProcessed;				
	BOOL						m_bStarted;					
	BOOL						m_bGotoTimeMode;			
	BOOL						m_bInitialized;				
	BOOL						m_bPresentFirstKey;			
	BOOL						m_bPresentLastKey;			
	BOOL						m_bAICamera;				
	BOOL						m_bCamKeyInserted;			
	float						m_fAverageFPS;				
	int							m_nFrameCount;				
	float						m_fVelocityCam;				
	float						m_fCsTime;					
	float						m_fUntriggerTimer;			
	zMAT4						m_mRotTrafo;				
	float						m_fDirectCam;				
	float						m_fStepTime;				
	float						m_fVelocityTime;			
	zTKeyFrameType				m_PresentFOVScale;			
	zTKeyFrameType				m_PresentAngleRollDeg;		
	zTKeyFrameType				m_PresentTimeScale;			
	BOOL						m_bDisableModifyCamera;		
	zCPose						m_PoseCameraRefVob;			
	zCPose						m_PoseTargetRefVob;			
	zCKBSpline					m_SplineCamera;				
	zCKBSpline					m_SplineTarget;				
	zTCamLerpFunc				m_pfnLerpCamera;			
	zTCamLerpFunc				m_pfnLerpTarget;			
	zMAT4						m_mCameraRefVobTrafo;		
	zMAT4						m_mTargetRefVobTrafo;		
	zVEC3						m_vTargetPos;				
	static zCClassDef *classDef;
	static BOOL playing;
	static BOOL evaluateAvgFPS;
	static BOOL draw;

	zCCamTrj_KeyFrame* GetCamKey(int)
	{
		XCALL(0x004B4250);
	};

	zCCamTrj_KeyFrame* GetTargetKey(int)
	{
		XCALL(0x004B4270);
	};

	static zCVob* GetPlayerVob(void)
	{
		XCALL(0x004BE400);
	};

	void zCSCamera(void)
	{
		XCALL(0x004BE410);
	};

	zCCSCamera(void)
	{
		zCSCamera();
	};

	void InsertCamKey(zCCamTrj_KeyFrame*)
	{
		XCALL(0x004BE9F0);
	};

	void InsertCamKeyAtPos(zCCamTrj_KeyFrame*,int)
	{
		XCALL(0x004BEB20);
	};

	void RemoveCamKey(zCCamTrj_KeyFrame*)
	{
		XCALL(0x004BEC70);
	};

	void InsertTargetKey(zCCamTrj_KeyFrame*)
	{
		XCALL(0x004BED40);
	};

	void InsertTargetKeyAtPos(zCCamTrj_KeyFrame*,int)
	{
		XCALL(0x004BEE70);
	};

	void RemoveTargetKey(zCCamTrj_KeyFrame*)
	{
		XCALL(0x004BEFC0);
	};

	void Refresh(void)
	{
		XCALL(0x004BF090);
	};

	void Draw(void)
	{
		XCALL(0x004BF1D0);
	};

	int EV_Play(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C0480);
	};

	int EV_Resume(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C0930);
	};

	int EV_Pause(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C0960);
	};

	int EV_Stop(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C0A20);
	};

	int EV_GotoKey(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C0F20);
	};

	int EV_SetDuration(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C13D0);
	};

	int EV_SetTime(zCCSCamera_EventMsg*)
	{
		XCALL(0x004C1410);
	};

	int EV_Deactivate(zCCSCamera_EventMsgActivate*)
	{
		XCALL(0x004C1430);
	};

	int EV_SetCamReference(zCCSCamera_EventMsgActivate*)
	{
		XCALL(0x004C14B0);
	};

	int EV_SetTargetReference(zCCSCamera_EventMsgActivate*)
	{
		XCALL(0x004C1550);
	};

	void DeleteEvMsgOfSubType(int)
	{
		XCALL(0x004C15F0);
	};

	void RecalcTrajectories(void)
	{
		XCALL(0x004C3D40);
	};

	int CheckAndResetAdjustedKeys(void)
	{
		XCALL(0x004C3E80);
	};

	int CheckAndCorrectKey(int)
	{
		XCALL(0x004C3F40);
	};

	int CheckAndCorrectPose(zMAT4&)
	{
		XCALL(0x004C3FF0);
	};

	void PreKFProcessing(void)
	{
		XCALL(0x004C41D0);
	};

	void PostKFProcessing(void)
	{
		XCALL(0x004C4FF0);
	};

	void AutoSetKeyTimes(zCArray<zCCamTrj_KeyFrame*>&)
	{
		XCALL(0x004C5020);
	};

	void Changed(void)
	{
		XCALL(0x004C5510);
	};

	void Initialize(void)
	{
		XCALL(0x004C5540);
	};

	void Reset(void)
	{
		XCALL(0x004C6190);
	};

	void CalcPrevNextActKeyOfTime(float const&,zCArray<zCCamTrj_KeyFrame*>&,int&,int&,int&)
	{
		XCALL(0x004C6210);
	};

	int IsPointNearWall(zVEC3 const&)
	{
		XCALL(0x004C6300);
	};

	zVEC3 GetPolyNearestPoint(zCPolygon*,zVEC3 const&)const 
	{
		XCALL(0x004C64A0);
	};

	int AdjustCenterSphere(zVEC3&,zVEC3 const&,float)
	{
		XCALL(0x004C69D0);
	};

	static void SetDrawEnabled(int)
	{
		XCALL(0x004C76D0);
	};

	virtual zCClassDef* _GetClassDef(void)const 
	{
		XCALL(0x004BE790);
	};

	virtual void Archive(zCArchiver&)
	{
		XCALL(0x004BF9A0);
	};

	virtual void Unarchive(zCArchiver&)
	{
		XCALL(0x004BFBC0);
	};

	virtual ~zCCSCamera()
	{
		XCALL(0x004BE7E0);
	};

	virtual void OnTrigger(zCVob*,zCVob*)
	{
		XCALL(0x004C3270);
	};

	virtual void OnUntrigger(zCVob*,zCVob*)
	{
		XCALL(0x004C3AC0);
	};

	virtual void OnMessage(zCEventMessage*,zCVob*)
	{
		XCALL(0x004C0180);
	};

	virtual void OnTick(void)
	{
		XCALL(0x004C1690);
	};

	virtual void ThisVobAddedToWorld(zCWorld*)
	{
		XCALL(0x004C0000);
	};

	virtual void ThisVobRemovedFromWorld(zCWorld*)
	{
		XCALL(0x004C0010);
	};
};
