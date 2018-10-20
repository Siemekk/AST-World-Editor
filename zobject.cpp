#include "AST.h"

oCNpc*&				player			= *(oCNpc**)			0x00AB2684;			// Pointer to hero object
zCObjectFactory*&	zfactory		= *(zCObjectFactory**)	0x008D8DF0;			// Pointer to G2 object factory
zCArchiverFactory*	zarcFactory		=  (zCArchiverFactory*)	0x008D472C;			// Pointer to acrhiver factory
zCOption*&			zoptions		= *(zCOption**)			0x008CD988;			// Pointer to options game
zCOption*&			zgameoptions	= *(zCOption**)			0x008CD98C;			// Pointer to zGameOpt
zCParser*			parser			=  (zCParser*)			0x00AB40C0;			// Pointer to script parser
zCTimer*			ztimer			=  (zCTimer*)			0x0099B3D4;			// Pointer to game timer
oCGame*&			ogame			= *(oCGame**)			0x00AB0884;			// Pointer to current game-info instance
zCView*&			screen			= *(zCView**)			0x00AB6468;			// Pointer to current viewport instance
zCInput*&			zinput			= *(zCInput**)			0x008D1650;			// Pointer to current input instance
zCRenderer*&		zrenderer		= *(zCRenderer**)		0x00982F08;			// Pointer to D3D ref instance
oCNpc*&				stealnpc		= *(oCNpc**)			0x00AB27D4;			// Pointer to steal npc
CGameManager*&		gameMan			= *(CGameManager**)		0x008C2958;			// Pointer to game manager
zCLineCache*		zlineCache		=  (zCLineCache*)		0x008D42F8;			// Pointer to line buff
zERROR*				zerr			=  (zERROR*)			0x008CDCD0;			// Pointer to zerror
zCSoundSystem*&		zsound			= *(zCSoundSystem**)	0x0099B03C;			// Pointer to sound manager

HINSTANCE&			hInstApp		=  *(HINSTANCE*)		0x008D4220;
HDC& 				dcScreen		=  *(HDC*)				0x008D4224;
HICON&				hIconApp		=  *(HICON*)			0x008D4228;
HWND&				hWndApp			=  *(HWND*)				0x008D422C;


#include "G2API\zcmorphmesh.h"
#include "G2API\zctrigger.h"
#include "G2API\ocsavegame.h"
#include "G2API\oviewtrade.h"
#include "G2API\zcskycontroller.h"

zCClassDef* zCSkyControlerMid::classDef = (zCClassDef*)0x0099ABB0;
zCClassDef*	zCObject::classDef			= (zCClassDef*)0x008D8CD8;
zCClassDef*	zCVisual::classDef			= (zCClassDef*)0x009A3708;
zCClassDef* zCVisualAnimate::classDef	= (zCClassDef*)0x009A3778;
zCClassDef*	zCMorphMesh::classDef		= (zCClassDef*)0x008D8C00;
zCClassDef* zCModel::classDef			= (zCClassDef*)0x008D8920;
zCClassDef *zCVob::classDef				= (zCClassDef*)0x009A34D8;
zCClassDef* oCVob::classDef				= (zCClassDef*)0x00AB3510;
zCClassDef* oCNpc::classDef				= (zCClassDef*)0x00AB1E20;
zCClassDef* oCItem::classDef			= (zCClassDef*)0x00AB1168;
zCClassDef*	oCMobMsg::classDef			= (zCClassDef*)0x00AB1618;
zCClassDef* oCVisualFX::classDef		= (zCClassDef*)0x008CE658;
zCClassDef* zCMaterial::classDef		= (zCClassDef*)0x008D8708;
zCClassDef*	zCProgMeshProto::classDef	= (zCClassDef*)0x00982B48;
zCClassDef* zCTexture::classDef			= (zCClassDef*)0x0099B250;
zCClassDef*	zCMover::classDef			= (zCClassDef*)0x009A3A60;
zCClassDef*	zCWorld::classDef			= (zCClassDef*)0x009A43A0;
zCClassDef*	zCVobLight::classDef		= (zCClassDef*)0x009A3810;
zCClassDef*	zCVobLightPreset::classDef	= (zCClassDef*)0x009A3628;
zCClassDef*	oCSavegameInfo::classDef	= (zCClassDef*)0x008C2D48;
zCClassDef*	zCEventMessage::classDef	= (zCClassDef*)0x009A3698;
zCClassDef*	oCNpcMessage::classDef		= (zCClassDef*)0x00AB2B60;
zCClassDef* oCMsgAttack::classDef		= (zCClassDef*)0x00AB2A70;
zCClassDef* oCMsgWeapon::classDef		= (zCClassDef*)0x00AB2CC0;
zCClassDef*	oCMsgManipulate::classDef	= (zCClassDef*)0x00AB2860;
zCClassDef*	oCMsgMagic::classDef		= (zCClassDef*)0x00AB2BE0;
zCClassDef*	oCMsgMovement::classDef		= (zCClassDef*)0x00AB2C50;
zCClassDef*	oCMsgConversation::classDef	= (zCClassDef*)0x00AB2980;
zCClassDef* oCMsgUseItem::classDef		= (zCClassDef*)0x00AB28E8;
zCClassDef*	zCEventManager::classDef	= (zCClassDef*)0x00AB3948;
zCClassDef*	zCEventCore::classDef		= (zCClassDef*)0x009A3548;

zCClassDef* zCAIBase::classDef			= (zCClassDef*)0x008D43C8;
zCClassDef* oCAICamera::classDef		= (zCClassDef*)0x008CE950;
zCClassDef*	zCAIPlayer::classDef		= (zCClassDef*)0x008D4538;
zCClassDef* oCAniCtrl_Human::classDef	= (zCClassDef*)0x00AADB38;
zCClassDef*	oCAIHuman::classDef			= (zCClassDef*)0x00AAD468;
zCClassDef* oCAIVobMove::classDef		= (zCClassDef*)0x00AAD720;
zCClassDef* oCAIArrowBase::classDef		= (zCClassDef*)0x00AAD790;
zCClassDef* oCAIArrow::classDef			= (zCClassDef*)0x00AAD8C0;
zCClassDef* oCAISound::classDef			= (zCClassDef*)0x00AAD940;

zCClassDef*	 oCViewDialogInventory::classDef		= (zCClassDef*)0x00AACB98;
zCClassDef*	 oCViewDialogItem::classDef				= (zCClassDef*)0x00AACC10;
zCClassDef*	 oCViewDialogItemContainer::classDef	= (zCClassDef*)0x00AACC88;
zCClassDef*	 oCViewDialogStealContainer::classDef	= (zCClassDef*)0x00AACD90;
zCClassDef*	 oCViewDialogTrade::classDef			= (zCClassDef*)0x00AACE80;
zCClassDef*	 zCViewDialog::classDef					= (zCClassDef*)0x00AAD138;
zCClassDef*	 zCViewDialogChoice::classDef			= (zCClassDef*)0x00AAD1B0;
zCClassDef*	 zCViewDraw::classDef					= (zCClassDef*)0x00AAD228;
zCClassDef*	 zCViewFX::classDef						= (zCClassDef*)0x00AAD2A8;
zCClassDef*	 zCViewObject::classDef					= (zCClassDef*)0x00AAD320;
zCClassDef*	 zCViewPrint::classDef					= (zCClassDef*)0x00AAD398;

zCArraySort<zCClassDef*>*&	zCClassDef::classDefList			= *(zCArraySort<zCClassDef*>**)0x008D8DE0;


#include "G2API\zczone.h"

int					oCZoneMusic::s_zonetime			= *(int*)			0x008AB2DC;
int					oCZoneMusic::s_daytime			= *(int*)			0x008AB2E0;
long				oCZoneMusic::s_lastzonechange	= *(long*)			0x009A4A1C;
oHEROSTATUS			oCZoneMusic::s_herostatus		= *(oHEROSTATUS*)	0x009A4A20;
oCZoneMusic*&		oCZoneMusic::s_musiczone		= *(oCZoneMusic**)	0x009A4A24;
oCZoneMusic*&		oCZoneMusic::s_oldmusiczone		= *(oCZoneMusic**)	0x009A4A28;

#include "G2API\zcworld.h"

int		zCVobLevelCompo::unarcIgnoreVisuals = *(int*)0x009A37FC;

#include "G2API\zcvob.h"

int zCVob::s_renderVobs				= *(int*)0x008A7634;
int zCVob::s_enableAnimations		= *(int*)0x008A7638;
int zCVob::s_vobAlreadyInMovement	= *(int*)0x009A37E4;
zCMesh*& zCVob::s_shadowMesh		= *(zCMesh**)0x009A37E8;
unsigned long zCVob::s_nextFreeID	= *(unsigned long*)0x009A37EC;
int zCVob::s_ignoreVisuals			= *(int*)0x009A37F0;
int zCVob::s_showHelperVisuals		= *(int*)0x009A37F4;
zCCollisionDetector*& zCVob::s_poCollisionDetector= *(zCCollisionDetector**)0x009A37F8;


zCMesh*& zCLensFlareFX::s_lensFlareMesh = *(zCMesh**)0x008D8664;
zCMesh*& zCLensFlareFX::s_coronaMesh = *(zCMesh**)0x008D8668;
zCMesh*& zCLensFlareFX::s_glowMesh = *(zCMesh**)0x008D866C;

#include "G2API\zctexture.h"

char								zCTexture::s_useDefaultTex				= *(char*)								0x008A6AA8;
char								zCTexture::s_globalLoadTextures			= *(char*)								0x008A6AA9;
zTTexScaleSize						zCTexture::s_texScaleSize				= *(zTTexScaleSize*)					0x008A6AAC;
zTTexScaleBPP						zCTexture::s_texScaleBPP				= *(zTTexScaleBPP*)						0x008A6AB0;
float								zCTexture::s_texRefRAM					= *(float*)								0x008A6AB4;
zCTexture::zTTexFileDesiredBPP		zCTexture::s_texRefBPP					= *(zCTexture::zTTexFileDesiredBPP*)	0x008A6AB8;
zTRnd_TextureFormat*&				zCTexture::s_texDesiredBPPDefault		= *(zTRnd_TextureFormat**)				0x008A6ABC;
zSTRING								zCTexture::zTEX_DEFAULT_TEXTURE_FILE	= *(zSTRING*)							0x0099B2C0;
zSTRING*							zCTexture::s_texDesiredBPPSuffix		= *(zSTRING**)							0x0099B368;
unsigned long						zCTexture::s_texSupportedFormats		= *(unsigned long*)						0x0099B3B8;
unsigned long						zCTexture::s_texMaxPixelSize			= *(unsigned long*)						0x0099B3BC;
unsigned long						zCTexAniCtrl::masterFrameCtr			= *(unsigned long*)						0x008D8774;
unsigned char						zCMaterial::s_matUsageDefault			= *(unsigned char*)						0x008A2264;

#include "G2API\zcprogmeshproto.h"

int zCProgMeshProto::s_frameCtr							= *(int*)0x008A532C;
int zCProgMeshProto::s_subMeshRenderDir					= *(int*)0x008A5330;
float zCProgMeshProto::s_lodParamStrengthOverride		= *(float*)0x008A5334;
float zCProgMeshProto::s_lodParamStrengthModifier		= *(float*)0x008A5338;
unsigned short*& zCProgMeshProto::s_wedgeRemap			= *(unsigned short**)0x0095CA10;
zVEC3*& zCProgMeshProto::s_posCacheListLOD				= *(zVEC3**)0x0095EA10;
zVEC3*& zCProgMeshProto::s_posCacheList					= *(zVEC3**)0x0096AA78;
zVEC3*& zCProgMeshProto::s_posNormalCSList				= *(zVEC3**)0x00970B10;
int*& zCProgMeshProto::s_posCacheListLODIndices			= *(int**)0x00976B10;
zCArray<unsigned short> zCProgMeshProto::s_workIndexList = *(zCArray<unsigned short>*)0x00982B10;
//zCClassDef* zCProgMeshProto::classDef					= (zCClassDef*)0x00982B48;
int zCProgMeshProto::s_autoSubdivEnabled				= *(int*)0x00982BE8;
unsigned long zCProgMeshProto::s_classCtorCtr			= *(unsigned long*)0x00982BEC;
int zCProgMeshProto::s_posCacheCount					= *(int*)0x00982BF0;
int zCProgMeshProto::s_posCacheCountLOD					= *(int*)0x00982BF4;
int zCProgMeshProto::s_posCacheIndex					= *(int*)0x00982BF8;
int zCProgMeshProto::s_markMeshMaterials				= *(int*)0x00982C04;
zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferColor	= *(zCVertexBufferDyn**)0x00982C08;
zCVertexBufferDyn*& zCProgMeshProto::s_vertBufferNormal = *(zCVertexBufferDyn**)0x00982C0C;

#include "G2API\zparticle.h"

zCClassDef*							zCParticleFX::classDef					=  (zCClassDef*)						0x008D91A8;
int									zCParticleFX::s_bAmbientPFXEnabled		= *(int*)								0x008A4E48;
zCArraySort<zCParticleEmitter*>*	zCParticleFX::s_emitterPresetList		=  (zCArraySort<zCParticleEmitter*>*)	0x008D8E0C;
zCParticleEmitter*					zCParticleFX::s_emitterDummyDefault		=  (zCParticleEmitter*)					0x008D8E20;
zCParticleFX::zCStaticPfxList*		zCParticleFX::s_pfxList					=  (zCParticleFX::zCStaticPfxList*)		0x008D9214;
int									zCParticleFX::s_globNumPart				= *(int*)								0x008D9220;
zSParticle*&						zCParticleFX::s_globPartList			= *(zSParticle**)						0x008D9224;
zSParticle*&						zCParticleFX::s_globFreePart			= *(zSParticle**)						0x008D9228;
zCMesh*&							zCParticleFX::s_partMeshTri				= *(zCMesh**)							0x008D922C;
zCMesh*&							zCParticleFX::s_partMeshQuad			= *(zCMesh**)							0x008D9230;
zCParser*&							zCParticleFX::s_pfxParser				= *(zCParser**)							0x008D9234;
int									zCParticleFX::s_showDebugInfo			= *(int*)								0x08D9238;

#include "G2API\zcmodel.h"

int zCModel::s_bSmoothRootNode = *(int*)0x008A2D50;
//int* zCModel::s_iNumSoftSkinPoly  = *(int**)0x008D8A20;	
int zCModel::s_drawSkeleton  = *(int*)0x008D8A84;

#include "G2API\zccscamera.h"

int zCCSCamera::playing			= *(int*)0x008D11B0;
int zCCSCamera::draw			= *(int*)0x008D11B4;
int zCCSCamera::evaluateAvgFPS	= *(int*)0x008D11B8;

zVEC3 zCCamera::activeCamPos	= *(zVEC3*)0x008D7F88;
zCCamera*& zCCamera::activeCam	= *(zCCamera**)0x008D7F94;
zMAT4 zCOBBox3D::trafoB2ToThis	= *(zMAT4*)0x008D7F08;

#include "G2API\ocnpc.h"

//zFocus
oCNpcFocus*& oCNpcFocus::focus = *(oCNpcFocus**)0x00AB0738;
oCVisualFX*& oCNpcFocus::highLightFX = *(oCVisualFX**)0x00AB0740;
oCNpcFocus**& oCNpcFocus::focuslist = *(oCNpcFocus***)0x00AB06F8;
BOOL oCNpcFocus::s_bHighlightInteractFocus = *(BOOL*)0x008B20F4;
BOOL oCNpcFocus::s_iHightlightMeleeFocus = *(BOOL*)0x00AB073C;
BOOL oCNpcFocus::isHighLighted = *(BOOL*)0x00AB0744;

//oCNpc
oCNpc::oEBloodMode oCNpc::modeBlood		= *(oEBloodMode*)0x008B0404;
BOOL oCNpc::ai_baseEnabled				= *(BOOL*)0x008B8110;
BOOL oCNpc::isEnabledTalkBox			= *(BOOL*)0x008B8114;
BOOL oCNpc::isEnabledTalkBoxPlayer		= *(BOOL*)0x008B8118;
int oCNpc::angle_near					= *(int*)0x008B8120;
int oCNpc::angle_far_up					= *(int*)0x008B8124;
int oCNpc::angle_far_side				= *(int*)0x008B8128;
BOOL oCNpc::isEnabledDamageDebug		= *(BOOL*)0x00AAC60C;
zSTRING*& oCNpc::FightAIInstances		= *(zSTRING**)0x00AAC698;
int*& oCNpc::bodyStateList				= *(int**)0x00AB1FE0;
BOOL oCNpc::godmode						= *(BOOL*)0x00AB2660;
BOOL oCNpc::ai_disabled					= *(BOOL*)0x00AB2664;
float oCNpc::ai_messagesSkip			= *(float*)0x00AB2668;
float oCNpc::ai_messagesSkipTimer		= *(float*)0x00AB266C;
float oCNpc::ai_scriptStateSkip			= *(float*)0x00AB2670;
float oCNpc::ai_scriptStateSkipTimer	= *(float*)0x00AB2674;
BOOL oCNpc::isEnabledTalkBoxAmbient		= *(BOOL*)0x00AB2678;
BOOL oCNpc::isEnabledTalkBoxNoise		= *(BOOL*)0x00AB267C;
BOOL oCNpc::s_bTargetLocked				= *(BOOL*)0x00AB2680;
BOOL oCNpc::s_bEnabledDialogCamStop		= *(BOOL*)0x00AB2688;
oCNpc*& oCNpc::dontArchiveThisNpc		= *(oCNpc**)0x00AB268C;
zMAT4 oCNpc::s_playerPositionMatrix		= *(zMAT4*)0x00AB26D8;
int oCNpc::game_mode					= *(int*)0x00AB27D0;
oCStealContainer*& oCNpc::stealcontainer = *(oCStealContainer**)0x00AB27DC;

#include "G2API\ocmob.h"

zCClassDef*	 oCMobWheel::classDef		= (zCClassDef*)0x00AB1430;
zCClassDef*	 oCMobBed::classDef			= (zCClassDef*)0x00AB14A0;
zCClassDef*	 oCMobDoor::classDef		= (zCClassDef*)0x00AB1518;
zCClassDef*	 oCMobLockable::classDef	= (zCClassDef*)0x00AB1598;
zCClassDef*	 oCMobFire::classDef		= (zCClassDef*)0x00AB1698;
zCClassDef*	 oCMobItemSlot::classDef	= (zCClassDef*)0x00AB1730;
zCClassDef*	 oCMobSwitch::classDef		= (zCClassDef*)0x00AB17C0;
zCClassDef*	 oCMobLadder::classDef		= (zCClassDef*)0x00AB1840;
zCClassDef*	 oCMobContainer::classDef	= (zCClassDef*)0x00AB18B0;
zCClassDef*	 oCMobInter::classDef		= (zCClassDef*)0x00AB19A0;
zCClassDef*	 oCMob::classDef			= (zCClassDef*)0x00AB1A10;

//oCGame
BOOL s_bUseQuickSave = *(int*)0x008B21D0;
BOOL s_bUsePotionKeys= *(int*)0x008B21CC;

#include "G2API\zcskycontroller.h"

int					zCSkyControler::s_skyEffectsEnabled		= *(int*)0x008A5DB0;
zCSkyControler*&	zCSkyControler::s_activeSkyControler	= *(zCSkyControler**)0x0099AC8C;


#include "G2API\ocanictrl_human.h"


BOOL					zCAIPlayer::s_bShowWeaponTrails			= *(BOOL*)0x0089EC90;
zMAT4					zCPose::tmpMat							= *(zMAT4*)0x008D1DF0;
zSTRING					oCAIHuman::Cam_Run						= *(zSTRING*)0x00AAD560;
zSTRING					oCAIHuman::Cam_Fight					= *(zSTRING*)0x00AAD5E4;
zSTRING					oCAIHuman::Cam_Normal					= *(zSTRING*)0x00AAD5F8;


int						zCAICamera::bCamChanges					= *(int*)0x00897B94;
short					zCAICamera::s_iLookAroundSgn			= *(short*)0x00897BA0;
zCClassDef*				zCAICamera::classDef					= (zCClassDef*)0x008CE950;
zCArray<zCCSCamera*>*	zCAICamera::dialogCamList				= (zCArray<zCCSCamera*>*)0x008CE9BC;
zCAICamera*&			zCAICamera::current						= *(zCAICamera**)0x008CEAB8;
int						zCAICamera::bCreated					= *(int*)0x008CEABC;
float					zCAICamera::lookingCamLastAzi			= *(float*)0x008CEAC0;
int						zCAICamera::lookingCamAziGoalReached	= *(int*)0x008CEAC4;


