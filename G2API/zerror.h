#pragma once

#include "ztypes.h"
#include "zstring.h"


typedef int zERROR_ID;

const zERROR_ID zERR_NONE    = 0; 
const zERROR_ID zERR_NO      = 1; 
const zERROR_ID zERR_UNKNOWN = 2; 

enum zERROR_TYPE
{ 
	zERR_TYPE_OK,
	zERR_TYPE_INFO,
	zERR_TYPE_WARN,
	zERR_TYPE_FAULT,
	zERR_TYPE_FATAL
};

enum zERROR_LEVEL
{
	zERR_OK,
	zERR_INFO,
	zERR_WARN,
	zERR_FAULT,
	zERR_FATAL
};

enum
{
	zERR_TARGET_SPY			= 1<<0,
	zERR_TARGET_FILE		= 1<<1
};

enum
{	
	zERR_BEGIN		= 1<<0,
	zERR_END		= 1<<1
};

const int	zERR_LV_NONE			= -1;

const int	zERR_LV_SECTION			=  1;	
const int	zERR_LV_SUBSECTION		=  3;						

const int	zERR_LV_LOADSECTION		=  2;
const int	zERR_LV_LOADFILE1		=  3;	
const int	zERR_LV_LOADFILE2		=  4;	
const int	zERR_LV_LOADFILE3		=  5;	

const int	zERR_LV_ROUTINE1		=  4;	
const int	zERR_LV_ROUTINE2		=  5;	
const int	zERR_LV_ROUTINE3		=  6;	

const int	zERR_LV_NEWOBJECT		=  8;	
const int	zERR_LV_FUNCENTER		=  9;	
const int	zERR_LV_FUNCLEAVE		= 10;	

const int	zERR_LV_DETAIL			= 10;	
const int	zERR_LV_IMPORTANT		=  1;	
const int	zERR_LV_DEFAULT			=  5;	

#define zERR_MESSAGE(level, flag, text)		((level)<=zerr->GetFilterLevel()) ? zerr->Report(zERR_TYPE_INFO,  0, text, level, flag, __LINE__,  __FILE__, 0 ) : zERR_NONE
#define zERR_WARNING(text)					zerr->Report(zERR_TYPE_WARN,  0, text, 0, 0, __LINE__,  __FILE__, 0 )
#define zERR_FAULT(text)					zerr->Report(zERR_TYPE_FAULT, 0, text, 0, 0, __LINE__,  __FILE__, 0 )
#define zERR_FATAL(text)					zerr->Report(zERR_TYPE_FATAL, 0, text, -1, 0, __LINE__,  __FILE__, 0 )
#define zERR_FAULT_ONCE(text)				{static bool ignore=false;if (!ignore) zerr->Report(zERR_TYPE_FAULT, 0, text, 0, 0, __LINE__,  __FILE__, 0 );ignore=true; };
#define zERR_FUNC_ENTER(level,funcname) zERR_MESSAGE(level, zERR_LV_FUNCENTER, funcname)
#define zERR_FUNC_LEAVE(level,funcname) zERR_MESSAGE(level, zERR_LV_FUNCLEAVE, funcname)

class zFILE;

class zERROR
{
	void (*onexit)();		
	zSTRING			filter_authors;
	unsigned int	filter_flag;
	signed char	filter_level;
	int				target;
	zERROR_TYPE		ack_type;
	zFILE*			log_file;
	BYTE			indent_depth;
	HWND			spyHandle;
	void*			spyMutex;
public:

	virtual ~zERROR()
	{
		XCALL(0x0044C650);
	};

	void _zERROR()
	{
		XCALL(0x0044BD40);
	};

	zERROR(void)
	{
		_zERROR();
	};

	void Init(zSTRING)
	{
		XCALL(0x0044BFA0);
	};
	 
	zERROR_ID Report(zERROR_TYPE xLevel,zERROR_ID xId,const zSTRING& xMessage, signed char level=5, unsigned int flag=0, int line =0, char* file=0, char* function=0)
	{
		XCALL(0x0044C8D0);
	};

	zERROR_ID Report(zERROR_LEVEL xLevel,zERROR_ID xId,const zSTRING& xMessage, signed char level=5, unsigned int flag=0, int line =0, char* file=0, char* function=0)
	{
		XCALL(0x0044C8C0);
	};

	

	void BlockBegin(char*,int)
	{
		XCALL(0x0044D060);
	};

	void BlockEnd(char*,int)
	{
		XCALL(0x0044D290);
	};

	void Separator(zSTRING)
	{
		XCALL(0x0044D6B0);
	};

	void ShowSpy(int)
	{
		XCALL(0x0044D8C0);
	};

	int Message1(zSTRING const&)
	{
		XCALL(0x0044DA10);
	};

	int Warning(zSTRING const&)
	{
		XCALL(0x0044DA50);
	};

	int Fatal(zSTRING const&)
	{
		XCALL(0x0044DA80);
	};

	int Fault(zSTRING const&)
	{
		XCALL(0x0044DAB0);
	};

	void SetFilterFlags(unsigned long)
	{
		XCALL(0x0044DAE0);
	};

	void SetFilterAuthors(zSTRING)
	{
		XCALL(0x0044DC00);
	};

	void SetFilterLevel(int)
	{
		XCALL(0x0044DDA0);
	};

	void SetTarget(int)
	{
		XCALL(0x0044DF50);
	};

	zSTRING GetTargetDescription(void)
	{
		XCALL(0x0044E1D0);
	};

	zSTRING GetFilterFlagDescription(void)
	{
		XCALL(0x0044E3F0);
	};

	zSTRING GetFilterAuthors(void)
	{
		XCALL(0x0044E5F0);
	};

	bool SearchForSpy(void)
	{
		XCALL(0x0044E640);
	};

	int GetFilterLevel(void)
	{
		XCALL(0x0059D130);
	};
};

extern zERROR *zerr;