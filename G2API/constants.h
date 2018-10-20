#pragma once



#include "ztypes.h"


const int ATR_HITPOINTS			=  0;
const int ATR_HITPOINTS_MAX		=  1;
const int ATR_MANA					=  2;
const int ATR_MANA_MAX				=  3;
const int ATR_STRENGTH				=  4;
const int ATR_DEXTERITY			=  5;
const int ATR_REGENERATEHP			=  6;
const int ATR_REGENERATEMANA		=  7; 

const int ATR_INDEX_MAX			=  8;


const int FMODE_NONE				=  0;
const int FMODE_FIST				=  1;
const int FMODE_MELEE				=  2;
const int FMODE_FAR				=  5;
const int FMODE_MAGIC				=  7;


const int NPC_RUN					=  0;
const int NPC_WALK					=  1;
const int NPC_SNEAK				=  2;
const int NPC_RUN_WEAPON			=  0 + 128;
const int NPC_WALK_WEAPON			=  1 + 128;
const int NPC_SNEAK_WEAPON			=  2 + 128;


const int WEAR_TORSO				=  1;		
const int WEAR_HEAD				=  2;		
const int WEAR_EFFECT				=  16;		














const int ITEM_KAT_NONE				= 1 << 0;  
const int ITEM_KAT_NF				= 1 << 1;  
const int ITEM_KAT_FF				= 1 << 2;  
const int ITEM_KAT_MUN				= 1 << 3;  
const int ITEM_KAT_ARMOR			= 1 << 4;  
const int ITEM_KAT_FOOD				= 1 << 5;  
const int ITEM_KAT_DOCS				= 1 << 6;  
const int ITEM_KAT_POTIONS			= 1 << 7;  
const int ITEM_KAT_LIGHT			= 1 << 8;  
const int ITEM_KAT_RUNE				= 1 << 9;  
const int ITEM_KAT_MAGIC			= 1 << 31; 
const int ITEM_KAT_KEYS				= ITEM_KAT_NONE;

const int ITEM_KNIFE				= 1 << 13;  
const int ITEM_SWD					= 1 << 14;  
const int ITEM_AXE					= 1 << 15;  
const int ITEM_2HD_SWD				= 1 << 16;  
const int ITEM_2HD_AXE				= 1 << 17;  
const int ITEM_SHIELD				= 1 << 18;  
const int ITEM_BOW					= 1 << 19;  
const int ITEM_CROSSBOW			= 1 << 20;  

const int ITEM_RING				= 1 << 11;  
const int ITEM_AMULET				= 1 << 22;  
const int ITEM_BELT				= 1 << 24;  

const int ITEM_DROPPED 			= 1 << 10;  
const int ITEM_MISSION 			= 1 << 12;  
const int ITEM_MULTI				= 1 << 21;  
const int ITEM_NFOCUS				= 1 << 23;  
const int ITEM_CREATEAMMO			= 1 << 25;  
const int ITEM_NSPLIT				= 1 << 26;  
const int ITEM_DRINK				= 1 << 27;  
const int ITEM_TORCH				= 1 << 28;  
const int ITEM_THROW				= 1 << 29;  
const int ITEM_EQUIP				= 1 << 30;  


const int GIL_NONE						= 0;	
const int GIL_HUMAN					= 1;	
const int GIL_PAL						= 1;	
const int GIL_MIL						= 2;	
const int GIL_VLK						= 3;	
const int GIL_KDF						= 4;	
const int GIL_NOV						= 5;	
const int GIL_DJG						= 6;	
const int GIL_SLD						= 7;	
const int GIL_BAU						= 8;	
const int GIL_BDT						= 9;	
const int GIL_STRF						= 10; 	
const int GIL_DMT						= 11;	
const int GIL_OUT						= 12; 	
const int GIL_PIR						= 13;	
const int GIL_KDW						= 14;	
const int GIL_EMPTY_D					= 15;	

const int GIL_PUBLIC					= 15; 	

const int GIL_SEPERATOR_HUM			= 16;

const int GIL_MEATBUG					= 17;
const int GIL_SHEEP					= 18;
const int GIL_GOBBO					= 19; 	
const int GIL_GOBBO_SKELETON			= 20;
const int GIL_SUMMONED_GOBBO_SKELETON 	= 21;
const int GIL_SCAVENGER				= 22; 	
const int GIL_GIANT_RAT				= 23;
const int GIL_GIANT_BUG				= 24;
const int GIL_BLOODFLY					= 25;
const int GIL_WARAN					= 26; 	
const int GIL_WOLF						= 27; 	
const int GIL_SUMMONED_WOLF			= 28;
const int GIL_MINECRAWLER				= 29; 	
const int GIL_LURKER					= 30;
const int GIL_SKELETON					= 31;
const int GIL_SUMMONED_SKELETON		= 32;
const int GIL_SKELETON_MAGE			= 33;
const int GIL_ZOMBIE					= 34;
const int GIL_SNAPPER					= 35; 	
const int GIL_SHADOWBEAST				= 36;	
const int GIL_SHADOWBEAST_SKELETON		= 37;
const int GIL_HARPY					= 38;
const int GIL_STONEGOLEM				= 39;
const int GIL_FIREGOLEM				= 40;
const int GIL_ICEGOLEM					= 41;
const int GIL_SUMMONED_GOLEM			= 42;
const int GIL_DEMON					= 43;
const int GIL_SUMMONED_DEMON			= 44;
const int GIL_TROLL					= 45; 	
const int GIL_SWAMPSHARK				= 46; 	
const int GIL_DRAGON					= 47; 	
const int GIL_MOLERAT					= 48; 	

const int GIL_ALLIGATOR				= 49;
const int GIL_SWAMPGOLEM				= 50;
const int GIL_Stoneguardian			= 51;
const int GIL_Gargoyle					= 52;
const int GIL_Empty_A					= 53;
const int GIL_SummonedGuardian			= 54;
const int GIL_SummonedZombie			= 55;
const int GIL_EMPTY_B					= 56;
const int GIL_EMPTY_C					= 57;

const int GIL_SEPERATOR_ORC			= 58;	

const int GIL_ORC						= 59;	
const int GIL_FRIENDLY_ORC				= 60;	
const int GIL_UNDEADORC				= 61;
const int GIL_DRACONIAN				= 62;

const int GIL_EMPTY_X					= 63;
const int GIL_EMPTY_Y					= 64;
const int GIL_EMPTY_Z					= 65;

const int GIL_MAX						= 66;


const int NPC_TALENT_UNKNOWN			= 0;


const int NPC_TALENT_1H				= 1;
const int NPC_TALENT_2H				= 2;
const int NPC_TALENT_BOW				= 3;
const int NPC_TALENT_CROSSBOW			= 4;

const int NPC_TALENT_PICKLOCK			= 5;	
const int NPC_TALENT_PICKPOCKET		= 6;	


const int NPC_TALENT_MAGE				= 7;


const int NPC_TALENT_SNEAK				= 8;
const int NPC_TALENT_REGENERATE		= 9;	
const int NPC_TALENT_FIREMASTER		= 10;	
const int NPC_TALENT_ACROBAT			= 11;


const int NPC_TALENT_PICKPOCKETG2		= 12;
const int NPC_TALENT_SMITH				= 13;
const int NPC_TALENT_RUNES				= 14;
const int NPC_TALENT_ALCHEMY			= 15;
const int NPC_TALENT_TAKEANIMALTROPHY	= 16;

const int NPC_TALENT_FOREIGNLANGUAGE	= 17;
const int NPC_TALENT_WISPDETECTOR		= 18;
const int NPC_TALENT_C					= 19;
const int NPC_TALENT_D					= 20;
const int NPC_TALENT_E					= 21;

const int NPC_TALENT_MAX				= 22;	





