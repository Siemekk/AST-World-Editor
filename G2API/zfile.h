#pragma once

#include "ztypes.h"
#include "zerror.h"
#include "ocobjectfactory.h"
class zCBuffer;
extern zCObjectFactory*&	zfactory;
enum PATH_ERROR_ID     // ab 5000
{
	zERR_PATH_UNKNOWN = 5000,
	zERR_PATH_CHANGEDIR,
	zERR_PATH_MAKEDIR,	
	zERR_PATH_NOTFOUND,
	zERR_PATHDLG_OK,
	zERR_PATHDLG_CANCEL,
	zERR_PATHDLG_ERROR

};

enum DSK_ERROR_ID      // ab 5100
{
	zERR_DSK_UNKNOWN = 5100,
	zERR_DSK_SHARE,
	zERR_DSK_EXISTS,
	zERR_DSK_INVAL,
	zERR_DSK_HANDLE,
	zERR_DSK_TOOMANY,
	zERR_DSK_NOFILE,
	zERR_DSK_EXEC,
	zERR_DSK_FULL,
	zERR_DSK_MOVE,
	zERR_DSK_NEWFILE
};

enum zTDATE_CONVERT
{
	zDATE_ALL,
	zDATE_DATE,
	zDATE_TIME
};
//
//
//

const	char	DIR_SEPARATOR			= '\\';

const int	zFILE_MAX_OPEN = 6;

class zDATE
{
public:
	unsigned int	year;
	unsigned short	month;
	unsigned short	day;	
	unsigned short	hour;
	unsigned short	minute;
	unsigned short	second;
};

class zFILE_STATS
{
public:
	zDATE			accessDate;		// Time of last access of file.
	zDATE			createDate;		// Time of creation of file.	
	zDATE			modifyDate;		// Time of last modification of file.	
	unsigned int	size;			// size of file
};

// ********************************************************************
// ********************************************************************
//
// File-Statistics
//
// ********************************************************************
// ********************************************************************
class zFILE_INFO
{
public: 
	zSTRING path;
	zSTRING name;

public:
	zFILE_INFO() 
	{ 
		name.Clear(); path.Clear(); 
	};
		
	zFILE_INFO(zSTRING& _path, zSTRING& _name)
	{
		Set(_path,_name);
	};

	void Set(zSTRING& _path, zSTRING& _name)
	{
		path = _path.Upper();		
		name = _name.Upper();		
	};

protected:
	
	zFILE_INFO(zFILE_INFO&);
	zFILE_INFO& operator=(zFILE_INFO&);
};

class zFILE
{
	bool write;
	// Buffering
	BOOL				buffering;
	zCBuffer*			buffer;	
public:
	virtual ~zFILE()			// destruct the file (will close it if still open)
	{
		XCALL(0x00442F50);
	};
//*********************************************************
// Setting ...
//*********************************************************
	// getting and setting some flags for various modes (for use in derived classes)
	virtual void SetMode(long modeflags) = 0;
	virtual long GetMode() = 0;

	///
	// Manipulating the file-path
	///

	// setting a (new) path to a file or directory
	// ! examples: "SAVEGAMES\", "SAVEGAMES\CURRENT\SURFACE.SAV"
	// ! This methods splits the path and stores it in the members drive, directory, filename, extension	
	// ! all not mentioned parts of a path will be set to zero 	
	virtual void SetPath(zSTRING xPath) = 0;			

	// setting the drive of the path
	// ! example: "C", without a colon (":")
	// ! all other parts of the path will be left as they are
	virtual void SetDrive(zSTRING xDrive) = 0;			
	
	// setting the directory  of the path. 
	// ! example "\SAVEGAMES\CURRENT\", last character must be a "\"	
	// ! all other parts of the path will be left as they are
	virtual void SetDir(zSTRING xDir) = 0;

	// setting both, filename and extension
	// ! example: "surface.sav"
	// ! This methods splits the filename and stores filename and extension
	// ! all other parts of the path will be left as they are
	virtual void SetFile(zSTRING xfilename) = 0;		

	// setting the filename-part of the path without its extension (see SetFile)	
	// ! example: "surface"	
	// ! all other parts of the path will be left as they are
	virtual void SetFilename(zSTRING xFilename) = 0;	
	
	// setting the extension-part of the path
	// ! example: "sav"	
	// ! all other parts of the path will be left as they are
	virtual void SetExt(zSTRING xExt) = 0;

	virtual FILE* GetFileHandle() = 0;

//*********************************************************
// ... and Getting
//*********************************************************
	
	// GetFullPath(): retrieving the full path including current virtual directory	and root-directory
	
	// example: if root-directory is "e:\dev\gothic\" 
	// and current virtual directory is "\data\worlds\"
	// and stored path "testlevel\testlevel_mobis.zen"
	// then this method will return "e:\dev\gothic\data\worlds\testlevel\testlevel_mobsi.zen"
	
	// if the current path has a leading slash "\data\textures\test.tga"
	// the current virtual directory will be ignored:
	// result ""e:\dev\gothic\data\textures\test.tga"	
	// Use this for direct access of files. 
	virtual zSTRING GetFullPath() = 0;

	// retrieving the full path stored in here (without root and virtual directory)	
	// example: "\data\textures\test.tga"	
	virtual zSTRING GetPath() = 0;	
		
	// retrieving the directory without filename and drive	
	// example: "c:\windows\system\"
	// Attention: See warning about virtual paths at beginning of this file
	virtual zSTRING GetDirectoryPath() = 0;
	
	///
	// Retriveing single informations from this class
	///
	/// Attention: See warning about virtual paths at beginning of this file

	virtual zSTRING GetDrive() = 0;						// getting the drive ("C")	
	virtual zSTRING GetDir() = 0;						// getting the drive ("\WINDOWS\DESKTOP\")
	virtual zSTRING GetFile() = 0;						// getting the filename with extension ("autoexec.bat")
	virtual zSTRING GetFilename() = 0;					// getting the filename ("autoexec") without extension
	virtual zSTRING GetExt() = 0;						// getting the files extension ("bat")		

//*********************************************************
// directory services
//*********************************************************
	
	// set the current directory as the new directory (filename and extension will be untouched)	
	// returns the new directory 
	virtual zSTRING SetCurrentDir() = 0;				
	
	// change to the stored path (ignoring filename and extension)
	// if parameter physical is set TRUE this metzhod will not change
	// only virtually but physically, too.
	virtual zERROR_ID ChangeDir(bool physical=false)=0;	
	
	// search for a given file (filename and extension)
	// The result will be stored in this file-object.
	virtual zERROR_ID SearchFile(const zSTRING& name, const zSTRING& searchDir, BOOL rec = TRUE) = 0;	


	// Files and directory-operations (Search, Create,  Move, Delete ...)
	virtual bool FindFirst(const zSTRING& _filter="*.*") = 0;	// start searching for files in the current directory	
	virtual bool FindNext() = 0;

	virtual bool DirCreate() = 0;
	virtual bool DirRemove() = 0;
	virtual bool DirExists() = 0;

	virtual bool FileMove(zSTRING path, bool follow = false) = 0;
	virtual bool FileCopy(zSTRING path, bool follow = false) = 0;

	virtual bool FileMove(zFILE* new_file) = 0;
	virtual bool FileCopy(zFILE* new_file) = 0;
	virtual bool FileDelete() = 0;
//*********************************************************
// file services
//*********************************************************	
	// open, create and close ...
	virtual bool		IsOpened() = 0;					// question if the file is opened	
	
	virtual zERROR_ID	Create() = 0;					// create a new file using the stored path	
	virtual zERROR_ID	Create(const zSTRING& s) = 0;	// create a new file using the given path	
	
	virtual zERROR_ID	Open(bool writeMode = false) = 0;				// open an existing file using the stored path	
	virtual zERROR_ID	Open(const zSTRING& s, bool writeMode = false) = 0;	// open an existing file using the given path	
	
	virtual bool		Exists() = 0;					// check if the the stored path points to an existing file	
	virtual bool		Exists(const zSTRING& s) = 0;	// check if the the given path points to an existing file	
	
	virtual zERROR_ID	Close() = 0;					// close the file (no effect if already closed)
	
	// size and cursor-positioning ...

	virtual zERROR_ID	Reset() = 0;					// reset file (file-cursor is set to the beginning of the file)	
	virtual void		Append() = 0;					// sets the cursor to the end of file to append some data	
	virtual long		Size() = 0;						// retrieve the file's size in bytes	
	virtual long		Pos() = 0;						// get the current position of the file-cursor	
	virtual zERROR_ID	Seek(long fpos) = 0;			// set the cursor to the given absolut position	
	virtual bool		Eof() = 0;						// check if the cursor is at the end of the file (no more data can be read)
	
	// file-information ... 

	virtual zERROR_ID	GetStats(zFILE_STATS& stats) = 0;		// retrieve some stasticts of the file
		
	// writing and reading ...

	virtual zERROR_ID	Write(const char *s) = 0;				// write the given string to the file	
	virtual zERROR_ID	Write(const zSTRING &s) = 0;			// write the given string to the file	
	virtual long		Write(const void *scr, long bytes) = 0;	// write the given buffer to the file	

	virtual long		Read (void *scr, long bytes) = 0;		// read [bytes] bytes from the file and store the data in the buffer [scr].	
	virtual zERROR_ID	Read (char *s) = 0;						// read the next line from the file (CR and LF will be truncated)	
	virtual zERROR_ID	Read (zSTRING &s) = 0;					// read the next line from the file (CR and LF will be truncated)	
	virtual zERROR_ID	ReadChar (char& ch) = 0;				// read one character from the file

	// special highlevel-functions
	virtual zSTRING		SeekText(const zSTRING &s) = 0;
	virtual zSTRING		ReadBlock(long pos, long oldlen) = 0;
	virtual zERROR_ID	UpdateBlock(const zSTRING& s, long pos, long oldlen) = 0;

	virtual long int    GetFreeDiskSpace();	
	
	void				SetBuffering(BOOL bufferOn)	{ buffering=bufferOn; };
	BOOL				IsBuffering	()					{ return buffering; };
	virtual long		FlushBuffer	() = 0;
	
	static bool InitFileSystem(void)
	{
		XCALL(0x004485E0);
	};

	static bool DeinitFileSystem(void)
	{
		XCALL(0x00448650);
	};
};

class zFILE_FILE : public zFILE
///
// comments for methods see base-class!
///
{

};

class zPATH
{	

public:
	enum zCOLLECT_MODE { CURRENT_ONLY, RECURSIVE };


public:	
	
	zPATH();				
	zPATH(zSTRING s);
	virtual ~zPATH()				{ delete path; path=0;  };	
	
	zSTRING GetDirectoryPath()		{ return path->GetDirectoryPath(); };
	zSTRING GetPath()				{ return path->GetPath(); };
	zSTRING GetDrive()				{ return path->GetDrive(); };
	zSTRING GetDir()				{ return path->GetDir(); };
	zSTRING GetFilename()			{ return path->GetFilename(); }	
	zSTRING GetFile()				{ return path->GetFile(); }	
	zSTRING GetExt()				{ return path->GetExt(); }	

	void SetPath(zSTRING s)			{ path->SetPath(s); };	
	void SetDrive(zSTRING s)		{ path->SetDrive(s); };	
	void SetDir(zSTRING s)			{ path->SetDir(s); };	
	void SetFilename(zSTRING s)		{ path->SetFilename(s); }
	void SetExt(zSTRING s)		    { path->SetExt(s); }
	void SetFile(zSTRING s)			{ path->SetFile(s); }
	

	// these methods will delete filename and extension-informations:	

	zSTRING		SetCurrentDir()			{ return path->SetCurrentDir(); };
	zERROR_ID	ChangeDir(bool physical = false)	{ return path->ChangeDir(physical); }
	zERROR_ID	SearchFile(const zSTRING& s, const zSTRING& searchDir, zBOOL rec = TRUE){ return path->SearchFile(s, searchDir, rec); };	

	// GUI
	zERROR_ID Dialog(char* filter);	

protected:
	
	//zPATH(zPATH&);	
	//zPATH& operator=(zPATH&);

private:
	zFILE* path;

};



class zCFileBIN
{
private:
	int		lastStart;
	int		nextStart;
	BOOL	externalFile;
public:
	zFILE*		file;
	BOOL	BinEof		()									{ assert(file); return (nextStart>=file->Size()); }			// ??
	BOOL	BinExists	()									{ assert(file); return file->Exists(); };
	void	BinOpen		(const zSTRING& name="")			{ if (!file) file = zfactory->CreateZFile (name);file->Open();lastStart	= nextStart = -1; };
	void BinClose		()									{ BinEndChunk(); if(!externalFile){file->Close(); delete file; }; file =0; };
	void BinWrite		(const void* ptr, const int num)	{ assert (file); file->Write (ptr, num);	  };
	void BinWriteFloat  (const float  f)					{ assert (file); file->Write (&f, sizeof(f)); };
	void BinWriteInt    (const int    f)					{ assert (file); file->Write (&f, sizeof(f)); };
	void BinWriteDWord  (const DWORD f)						{ assert (file); file->Write (&f, sizeof(f)); };
	void BinWriteWord   (const WORD  f)						{ assert (file); file->Write (&f, sizeof(f)); };
	void BinWriteByte	(const BYTE  f)						{ assert (file); file->Write (&f, sizeof(f)); };
	void BinWriteString (const zSTRING& s)					{ assert (file); file->Write (s+"\n");		};
	void BinSetFile		(zFILE* inFile)						{ file=inFile; lastStart = nextStart = -1; externalFile=TRUE; };
	void BinRead		(void* ptr, const int num)			{ assert (file); file->Read (ptr, num); };
	void BinReadFloat	(float   &f)						{ assert (file); file->Read (&f, sizeof(f)); };
	void BinReadInt		(int     &f)						{ assert (file); file->Read (&f, sizeof(f)); };
	void BinReadDWord	(DWORD  &f)							{ assert (file); file->Read (&f, sizeof(f)); };
	void BinReadWord	(WORD   &f)							{ assert (file); file->Read (&f, sizeof(f)); };
	void BinReadByte	(BYTE   &f)							{ assert (file); file->Read (&f, sizeof(f)); };
	void BinReadString	(zSTRING &f)						{ assert (file); file->Read (f); };
	void BinOpenChunk (WORD& id, LONG& len)
	{
		if (file==0) return;
		file->Read (&id , sizeof(id));
		if (file->Eof()) { id = 0; return; };
		file->Read (&len, sizeof(len));
		int actPos = file->Pos();
		nextStart  = actPos + len;
	};
	void BinSkipChunk ()
	{
		if (file==0) return;
		if (nextStart>=file->Size()) return;
		file->Seek (nextStart);
	};
	BOOL BinSeekChunk (const WORD id)
	{
		if (file==0) return FALSE;
		WORD fid;
		LONG flen;
		BinOpenChunk (fid, flen);
		while ( (!file->Eof()) && (fid!=id))
		{
			BinSkipChunk ();
			BinOpenChunk (fid, flen);
		};
		return ((fid==id) && (!file->Eof()));
	};
	// write
	void BinCreate	(const zSTRING& name)
	{
		file		= zfactory->CreateZFile(name);
		file->Create();
		lastStart	= -1;
	};
	void BinStartChunk	(const WORD id)
	{
		if (file==0) return;
		// close last chunk: write len
		if (lastStart!=-1) {
			int actPos = file->Pos();
			int len    = actPos-lastStart-6; //6
			file->Seek  (lastStart+sizeof(id));
			file->Write (&len, sizeof(len));
			file->Seek  (actPos);
		};
		// write header-frame for new chunk
		LONG len = 0;
		lastStart = file->Pos();
		file->Write (&id , sizeof(id));
		file->Write (&len, sizeof(len));
	};
	void BinEndChunk	()
	{
		// close last chunk: write len
		// 'lastStart' ist nur im WriteMode !=-1 !
		if (lastStart!=-1)
		{
			int actPos = file->Pos();
			int len    = actPos-lastStart-6; //6
			file->Seek  (lastStart+sizeof(WORD));
			file->Write (&len    , sizeof(len));
			file->Seek  (actPos);
		};
	};
};



