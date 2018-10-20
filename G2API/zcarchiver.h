#pragma once

#include "ztypes.h"
#include "ocobjectfactory.h"

class zCBuffer;


enum zTArchiveMode		{ zARC_MODE_BINARY,						// supported by zCArchiverGeneric
						  zARC_MODE_ASCII,						// supported by zCArchiverGeneric
						  zARC_MODE_ASCII_PROPS,				// supported by zCArchiverGeneric
						  zARC_MODE_BINARY_SAFE,				// supported by zCArchiverBinSafe

						  zARC_MODE_COUNT,
						};
enum zTArchiveFlags		{ zARC_FLAG_WRITE_BRIEF_HEADER	=	1,	// keeps archive header short (only neccessary infos)
						  zARC_FLAG_NO_SPY_MESSAGES		=   2	// silent, absolutely no spy output
						};

enum zTArchiveDataMode
{
	zARCH_NONE,				
	zARCH_READ,				
	zARCH_WRITE				
};

enum zTArchiveTypeID
{
	zTYPE_NULL,				
	zTYPE_STRING,			
	zTYPE_INT,				
	zTYPE_FLOAT,			
	zTYPE_BYTE,				
	zTYPE_WORD,				
	zTYPE_BOOL,				
	zTYPE_VEC3,				
	zTYPE_COLOR,			
	zTYPE_RAW,				
	zTYPE_10,				
	zTYPE_11,				
	zTYPE_12,				
	zTYPE_13,				
	zTYPE_14,				
	zTYPE_15,				
	zTYPE_FLOAT_RAW,		
	zTYPE_ENUM,				
	zTYPE_18				
};



class zCArchiver : public zCObject {
public:
	enum		zTArchiveMedium		{ zARC_MEDIUM_FILE, 
									  zARC_MEDIUM_BUFFER 
									};
	zCArchiver() {};
	virtual ~zCArchiver() {};
	
	virtual void		__fastcall		WriteInt			(const char* entryName, const int		value)=0;
	virtual void		__fastcall		WriteByte			(const char* entryName, const BYTE		value)=0;
	virtual void		__fastcall		WriteWord			(const char* entryName, const WORD		value)=0;
	virtual void		__fastcall		WriteFloat			(const char* entryName, const float		value)=0;
	virtual void		__fastcall		WriteBool			(const char* entryName, const BOOL		value)=0;
	virtual void		__fastcall		WriteString			(const char* entryName, const zSTRING&	value)=0;
	virtual void		__fastcall		WriteVec3			(const char* entryName, const zVEC3&	value)=0;
	virtual void		__fastcall		WriteColor			(const char* entryName, const zCOLOR&	value)=0;
	virtual void		__fastcall		WriteRaw			(const char* entryName, void* buffer, const DWORD size)=0;
	virtual void		__fastcall		WriteRawFloat		(const char* entryName, void* buffer, const DWORD size)=0;
	virtual void		__fastcall		WriteEnum			(const char* entryName, const char* enumChoices, const int value)=0;	
	virtual void		__fastcall		WriteObject			(zCObject* object)=0;								
	virtual void		__fastcall		WriteObject			(const char* chunkName, zCObject* object)=0;		
	virtual void		__fastcall		WriteChunkStart		(const char* chunkName, WORD chunkVersion=0)=0;	
	virtual void		__fastcall		WriteChunkEnd		()=0;
	virtual void		__fastcall		WriteGroupBegin		(const char* groupName)=0;		
	virtual void		__fastcall		WriteGroupEnd		(const char* groupName)=0;

	

	
	
	virtual void		__fastcall		ReadInt				(const char* entryName, int&		value)=0;
	virtual void		__fastcall		ReadByte			(const char* entryName, BYTE&		value)=0;
	virtual void		__fastcall		ReadWord			(const char* entryName, WORD&		value)=0;
	virtual void		__fastcall		ReadFloat			(const char* entryName, float&		value)=0;
	virtual void		__fastcall		ReadBool			(const char* entryName, BOOL&		value)=0;
	virtual void		__fastcall		ReadString			(const char* entryName, zSTRING&	value)=0;
	virtual void		__fastcall		ReadVec3			(const char* entryName, zVEC3&		value)=0;
	virtual void		__fastcall		ReadColor			(const char* entryName, zCOLOR&		value)=0;
	virtual void		__fastcall		ReadEnum			(const char* entryName, int&		value)=0;
	virtual void		__fastcall		ReadRaw				(const char* entryName, void* buffer, const DWORD size)=0;
	virtual void		__fastcall		ReadRawFloat		(const char* entryName, void* buffer, const DWORD size)=0;

	virtual zCObject*	__fastcall		ReadObject			(zCObject* objectUseThis=0)=0;						
	virtual zCObject*	__fastcall		ReadObject			(const char* chunkName, zCObject* objectUseThis=0)=0;	

	virtual zCObject*	__fastcall		ReadObjectAccount	(const char *file, int line, zCObject* objectUseThis=0); 
	virtual zCObject*	__fastcall		ReadObjectAccount	(const char *file, int line, const char* chunkName, zCObject* objectUseThis=0);	 
																												
	virtual	BOOL		__fastcall		ReadChunkStart		(zSTRING& chunkName, WORD& chunkVersion)=0;			
	virtual BOOL		__fastcall		ReadChunkStartNamed (const char* chunkName, WORD& chunkVersion)=0;		
	virtual void		__fastcall		SkipOpenChunk		()=0;
	virtual WORD		__fastcall		GetCurrentChunkVersion()=0;												
	
	virtual int			__fastcall		ReadInt				(const char* entryName)=0;
	virtual BYTE		__fastcall		ReadByte			(const char* entryName)=0;
	virtual WORD		__fastcall		ReadWord			(const char* entryName)=0;
	virtual float		__fastcall		ReadFloat			(const char* entryName)=0;
	virtual BOOL		__fastcall		ReadBool			(const char* entryName)=0;
	virtual zSTRING		__fastcall		ReadString			(const char* entryName)=0;
	virtual zVEC3		__fastcall		ReadVec3			(const char* entryName)=0;
	virtual zCOLOR		__fastcall		ReadColor			(const char* entryName)=0;
	virtual int			__fastcall		ReadEnum			(const char* entryName)=0;
	
	virtual zFILE*						GetFile				() const=0;												
	virtual void		__fastcall		GetBufferString		(zSTRING& result)=0;									
	virtual zCBuffer*	__fastcall		GetBuffer			()=0;													
	virtual BOOL		__fastcall		EndOfArchive		()=0;
	
	virtual void						Close				()=0;				
	
	virtual void						SetStringEOL		(const zSTRING& eol)=0;
	virtual zSTRING						GetStringEOL		() const=0;
	virtual BOOL						IsStringValid		(const char* string)=0;	
	virtual BOOL						GetChecksumEnabled	() const=0;
	virtual void						SetChecksumEnabled	(const BOOL b)=0;
	virtual void						SetNoReadSearchCycles(const BOOL b)=0;
	virtual BOOL						InProperties		() const=0;
	virtual BOOL						InSaveGame			() const=0;
	virtual BOOL						InBinaryMode		() const=0; 

	
	virtual zCObject*	__fastcall		GetParentObject		()=0;

	typedef void (zTTestClassCallback)	(zCObject *object, int currentCtr, zCClassDef *classDef, int& numLoops);

public:
	struct zTChunkRecord
	{
		DWORD					startPos;		
		DWORD					size;			
		WORD					version;
		DWORD					objectIndex;
		zSTRING					name;		
		zSTRING					className;
	};

	enum zTAccessMode
	{
		zARC_CLOSED,
		zARC_READ,
		zARC_WRITE
	};

	
	zTArchiveMedium				medium;
	zTArchiveMode				mode;
	
	
	virtual BOOL						OpenWriteBuffer		(zCBuffer*		buffer   , zTArchiveMode arcMode, BOOL saveGame=FALSE, int arcFlags=0, BOOL arcOwnsMedium=FALSE)=0; 
	virtual void						OpenWriteFile		(zFILE*			fileWrite, zTArchiveMode arcMode, BOOL saveGame=FALSE, int arcFlags=0, BOOL arcOwnsMedium=FALSE)=0;

	virtual void		__fastcall		WriteChunkStart		(const char* chunkName, const char* className, WORD classVersion, DWORD objectIndex)=0;
	virtual void		__fastcall		WriteObject			(const char* chunkName, zCObject& object)=0;
	virtual void		__fastcall		WriteHeader			(const int arcFlags=0)=0;
	virtual void		__fastcall		WriteHeaderNumObj	()=0;
	virtual void		__fastcall		WriteASCIILine		(const char* entryName, const char* typeName, const zSTRING& value)=0;
	virtual void		__fastcall		StoreBuffer			(void* buffer, const DWORD size)=0;
	virtual void		__fastcall		StoreString			(const char* string)=0;
	virtual void		__fastcall		StoreStringEOL		(const char* string)=0;
	virtual DWORD		__fastcall		StoreGetPos			()=0;
	virtual void		__fastcall		StoreSeek			(const DWORD newPos)=0;

	
	virtual	BOOL						OpenReadBuffer		(zCBuffer&		buffer	, zTArchiveMode arcMode, BOOL saveGame=FALSE, int arcFlags=0)=0;
	virtual void						OpenReadFile		(zFILE*			fileRead, zTArchiveMode arcMode, BOOL saveGame=FALSE, int arcFlags=0, BOOL deleteFileOnClose=FALSE)=0;

	virtual zCClassDef* __fastcall		GetClassDefByString (const zSTRING& className)=0;
	virtual zCObject*	__fastcall		CreateObject		(const zSTRING& className)=0;
	virtual void		__fastcall		SkipChunk			(const BOOL removeFromChunkStack)=0;
	virtual BOOL		__fastcall		ReadChunkStart		(const char* chunkName)=0;							
	virtual void		__fastcall		ReadChunkStartASCII (const char* chunkName, zSTRING& resultLine)=0;	
	virtual void		__fastcall		ReadChunkEnd		()=0;
	virtual BOOL		__fastcall		ReadEntryASCII		(const char* entryName, zSTRING& resultValue)=0;
	virtual void		__fastcall		ReadHeader			()=0;
	virtual void		__fastcall		RestoreBuffer		(void* buffer, const DWORD size)=0;
	virtual void		__fastcall		RestoreStringEOL	(zSTRING& string)=0;
	virtual void		__fastcall		RestoreString0		(zSTRING& string)=0;
	virtual DWORD		__fastcall		RestoreGetPos		()=0;
	virtual void		__fastcall		RestoreSeek			(const DWORD newPos)=0;

	virtual void		__fastcall		DeleteBuffer		()=0;
};

class zCArchiverFactory
{
public:
	zCArchiver* CreateArchiverRead	(const zSTRING&	fileNameRead, int arcFlags=0)												{XCALL(0x0051A120);};
	zCArchiver* CreateArchiverRead	(zFILE*			fileRead	, int arcFlags=0)												{XCALL(0x0051A0B0);};
	zCArchiver* CreateArchiverRead	(zCBuffer*		buffer		, int arcFlags=0)												{XCALL(0x0051A020);};
	zCArchiver* CreateArchiverWrite	(const zSTRING&	fileNameWrite,zTArchiveMode arcMode, zBOOL saveGame=FALSE, int arcFlags=0)	{XCALL(0x0051AF20);};
	zCArchiver* CreateArchiverWrite	(zFILE*			fileWrite	, zTArchiveMode arcMode, zBOOL saveGame=FALSE, int arcFlags=0)	{XCALL(0x0051AFA0);};
	zCArchiver* CreateArchiverWrite	(							  zTArchiveMode arcMode, zBOOL saveGame=FALSE, int arcFlags=0)	{XCALL(0x0051AF00);};
	zCArchiver* CreateArchiverWrite	(zCBuffer*		buffer		, zTArchiveMode arcMode, zBOOL saveGame=FALSE, int arcFlags=0)	{XCALL(0x0051ADB0);};

	int EndOfArchive(zCBuffer* buffer, zFILE* file)									{XCALL(0x00519650);};
	void ReadLine(zSTRING& line, zCBuffer* buffer, zFILE* file)						{XCALL(0x005196C0);};
	void ReadLineArg(zSTRING& line, zSTRING& arg, zCBuffer* buffer, zFILE* file)	{XCALL(0x005198D0);};
	void					ReadHeader				(int			arcFlags,	// in
													 zCBuffer*		buffer,		// in
													 zFILE*			file,		// in
													 zCArchiver*	&arc,		// out
													 zTArchiveMode	&arcMode,	// out
													 zBOOL			&inSaveGame	// out	
													 )																			{XCALL(0x00519B50);};
	void WriteLine(const zSTRING& line, zCBuffer* buffer, zFILE* file)															{XCALL(0x0051A290);};
	void WriteLine(const char* const line, zCBuffer* buffer, zFILE* file)														{XCALL(0x0051A390);};
	void WriteHeader(zCArchiver *arc, zTArchiveMode arcMode, zBOOL saveGame, int arcFlags, zCBuffer* buffer, zFILE* file)		{XCALL(0x0051A490);};
	zCArchiver* CreateArchiverFromMode(zTArchiveMode arcMode)																	{XCALL(0x0051ACD0);};
};


extern zCArchiverFactory*	zarcFactory;