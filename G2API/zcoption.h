#pragma once

#include "zFile.h"

enum zTOptionPaths
{		
	
	DIR_SYSTEM,
	DIR_WEB,
	DIR_SAVEGAMES,
	
	DIR_DATA,				
	DIR_ANIMS,
	DIR_CUTSCENES,
	DIR_OUTPUTUNITS,
	DIR_MESHES,
	DIR_SCRIPTS,	
	DIR_SOUND,
	DIR_VIDEO,
	DIR_MUSIC,
	DIR_TEX,
	DIR_TEX_DESKTOP,
	DIR_WORLD,	
	DIR_PRESETS,	
	DIR_TOOLS_DATA,	
	
	DIR_COMPILED_ANIMS,
	DIR_COMPILED_MESHES,
	DIR_COMPILED_SCRIPTS,
	DIR_COMPILED_TEXTURES,
	
	DIR_TOOLS_CONFIG,
	
	SUBDIR_INTERN,
	
	NUM_PATHS,		

	DIR_ROOT,		
	DIR_EXECUTABLE,	

	NUM_ENTRIES		
};

enum zTOptionWriteMode
{
	zOPTMODE_WRITE_TO_CURRENT_AND_APPLIED = 0,
	zOPTMODE_WRITE_TO_CURRENT_ONLY        = 1,
	zOPTMODE_WRITE_DEFAULT                = zOPTMODE_WRITE_TO_CURRENT_AND_APPLIED
};

enum zTOptionReadMode
{
	zOPTMODE_READ_APPLIED = 0,
	zOPTMODE_READ_CURRENT = 1,
	zOPTMODE_READ_DEFAULT = zOPTMODE_READ_CURRENT
};


class zCOptionEntry
{
	friend class zCOption;
	friend class zCOptionSection;

	typedef BOOL (*EntryChangeHandler)( zCOptionEntry &newValue );	
	BOOL changed;
	zCArray <EntryChangeHandler> ccbList;
	
	zSTRING varName;
	zSTRING varValue;	
	zSTRING varValueTemp;
	int		varFlag;
public:
	void zOptionEntry(zSTRING const&,zSTRING const&)
	{
		XCALL(0x0045FE00);
	};

	zCOptionEntry(const zSTRING& sOptionName, const zSTRING& sOptionValue)
	{
		zOptionEntry(sOptionName,sOptionValue);
	};

	~zCOptionEntry(void)
	{
		XCALL(0x004606F0);
	};
};

class zCOptionSection
{
	friend class zCOption;
	zSTRING secName;	
	zCArray<zCOptionEntry*> entryList;
public:
	zCOptionSection(zSTRING const&)
	{
		XCALL(0x00460080);
	};

	~zCOptionSection(void)
	{
		XCALL(0x00460240);
	};
};

class zCOption
{
	BOOL		m_bReadTemp;
	zCArray<zCOptionSection*> sectionList;
	zFILE*		(directory)[NUM_ENTRIES];
	zSTRING		dir_string[NUM_ENTRIES];
	zSTRING		commandline;
public:
	~zCOption()
	{
		XCALL(0x00460570);
	}

	void zOption()
	{
		XCALL(0x00460350);
	}

	zCOption(void)
	{
		zOption();
	};

	unsigned short GetNumEntries(zCOptionSection*)
	{
		XCALL(0x00462A20);
	};

	zCOptionEntry* GetEntry(zCOptionSection*,int)
	{
		XCALL(0x00462A40);
	};

	void SetFlag(zSTRING const&,char const*,int)
	{
		XCALL(0x00462C10);
	};

	zCOptionEntry* GetEntryByName(zCOptionSection*,zSTRING const&,int)
	{
		XCALL(0x00462D10);
	};

	zCOptionSection* GetSectionByName(zSTRING const&,int)
	{
		XCALL(0x00463000);
	};

	unsigned short GetNumSections(void)
	{
		XCALL(0x00463270);
	};

	zCOptionSection* GetSection(int)
	{
		XCALL(0x00463280);
	};

	void InsertChangeHandler(zSTRING const&,char const*,int (__cdecl*)(zCOptionEntry&))
	{
		XCALL(0x00463310);
	};

	int AddParameters(zSTRING)
	{
		XCALL(0x00463B00);
	};

	void ChangeDir(zTOptionPaths)
	{
		XCALL(0x00465160);
	};

	zFILE* GetDir(zTOptionPaths)
	{
		XCALL(0x00465250);
	};

	zSTRING& GetDirString(zTOptionPaths)
	{
		XCALL(0x00465260);
	};

	int Load(zSTRING file)
	{
		XCALL(0x004607B0);
	};

	int Save(zSTRING file)
	{
		XCALL(0x004616C0);
	};

	int Init(zSTRING cmd, bool extra_infos = true)
	{
		XCALL(0x00463C20);
	};

	int SectionExists(const zSTRING& section)
	{
		XCALL(0x00463250);
	};

	int RemoveSection(const zSTRING& section)
	{
		XCALL(0x004632B0);
	};

	int EntryExists(const zSTRING& section, const char* entry)
	{
		XCALL(0x00462950);
	};

	int RemoveEntry(const zSTRING& section, const char* entry)
	{
		XCALL(0x00462A70);
	};

	int WriteBool(const zSTRING& section, const char* entry, BOOL value, int p1 = 0)
	{
		XCALL(0x00461DE0);
	};

	int WriteDWord(const zSTRING& section, const char* entry, DWORD value, int p1 = 0)
	{
		XCALL(0x00461E60);
	};

	int WriteInt(const zSTRING& section, const char* entry, int value, int p1 = 0)
	{
		XCALL(0x00461E30);
	};

	int WriteRaw(const zSTRING& section, const char* entry, void* buffer, int size, int p1 = 0)
	{
		XCALL(0x004634E0);
	};

	int Writefloat(const zSTRING& section, const char* entry, float value, int p1 = 0)
	{
		XCALL(0x00461F90);
	};

	int WriteString(const zSTRING& section, const char* entry, zSTRING value, int p1 = 0)
	{
		XCALL(0x00461FD0);
	};

	int WriteBool(const zSTRING& section, const zSTRING& entry, BOOL value, int p1 = 0)
	{
		XCALL(0x004638A0);
	};

	int WriteDWord(const zSTRING& section, const zSTRING& entry, DWORD value, int p1 = 0)
	{
		XCALL(0x004638E0);
	};

	int WriteInt(const zSTRING& section, const zSTRING& entry, int value, int p1 = 0)
	{
		XCALL(0x004638C0);
	};

	int WriteRaw(const zSTRING& section, const zSTRING& entry, void* buffer, int size, int p1 = 0)
	{
		XCALL(0x004639E0);
	};

	int Writefloat(const zSTRING& section, const zSTRING& entry, float value, int p1 = 0)
	{
		XCALL(0x00463900);
	};

	int WriteString(const zSTRING& section, const zSTRING& entry, zSTRING value, int p1 = 0)
	{
		XCALL(0x00463930);
	};

	BOOL ReadBool(const zSTRING& section, const char* entry, int default = false)
	{
		XCALL(0x00462160);
	};

	DWORD ReadDWord(const zSTRING& section, const char* entry, DWORD default = 0)
	{
		XCALL(0x004624F0);
	};

	int ReadInt(const zSTRING& section, const char* entry, int default = 0)
	{
		XCALL(0x00462390);
	};

	int ReadRaw(const zSTRING& section, const char* entry, void*& buffer, void* default = NULL, int defaultsize = 0)
	{
		XCALL(0x004636C0);
	};

	float Readfloat(const zSTRING& section, const char* entry, float default = 0.0f)
	{
		XCALL(0x00462650);
	};

	zSTRING ReadString(const zSTRING& section, const char* entry, const char* default = "")
	{
		XCALL(0x004627E0);
	};

	BOOL ReadBool(const zSTRING& section, const zSTRING& entry, int default = 0)
	{
		XCALL(0x00463A00);
	};

	DWORD ReadDWord(const zSTRING& section, const zSTRING& entry, DWORD default = 0)
	{
		XCALL(0x00463A40);
	};

	int ReadInt(const zSTRING& section, const zSTRING& entry, int default = 0)
	{
		XCALL(0x00463A20);
	};

	int ReadRaw(const zSTRING& section, const zSTRING& entry, void* default = NULL, int defaultsize = 0)
	{
		XCALL(0x00463AD0);
	};

	float Readfloat(const zSTRING& section, const zSTRING& entry, float default = 0.0f)
	{
		XCALL(0x00463A60);
	};

	zSTRING Readfloat(const zSTRING& section, const zSTRING& entry, const char* default = "")
	{
		XCALL(0x00463A90);
	};

	int Parm(const zSTRING& param)
	{
		XCALL(0x00465270);
	};

	zSTRING ParmValue(const zSTRING& param)
	{
		XCALL(0x00465380);
	};

	float ParmValueFloat(const zSTRING& param)
	{
		XCALL(0x00465940);
	};

	zSTRING & GetDirString(int)
	{
		XCALL(0x00465260);
	};

	int ParmValueInt(const zSTRING& param)
	{
		XCALL(0x00465780);
	};

	zSTRING ParmValueRaw(const zSTRING& param)
	{
		XCALL(0x00465580);
	};

	inline static zCOption* GetOptionGame() { return *(zCOption**)0x008CD98C; };
	inline static zCOption* GetOption() { return *(zCOption**)0x008CD988; };
};