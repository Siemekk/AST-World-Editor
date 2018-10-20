#pragma once

class zVEC2;
class zVEC3;
class zVEC4;
class zMAT3;
class zMAT4;




typedef char		signed		zINT8,   *zPINT8;							
typedef char		unsigned	zUINT8,  *zPUINT8;							
typedef short		signed		zINT16,  *zPINT16;							
typedef short		unsigned	zUINT16, *zPUINT16;							
typedef int			signed		zINT32,  *zPINT32;							
typedef int			unsigned	zUINT32, *zPUINT32;							
typedef long long	signed		zINT64,  *zPINT64;							
typedef long long	unsigned	zUINT64, *zPUINT64;							
typedef float					zFLOAT,	 *zPFLOAT,	zREAL,	 *zPREAL;		
typedef double					zDOUBLE, *zPDOUBLE,	zREAL64, *zPREAL64;		
typedef	void					zVOID,	 *zPVOID,	*__ptr64 zPVOID64;		

typedef long		signed		zLONG,   *zPLONG;							
typedef long		unsigned	zULONG,  *zPULONG,	zDWORD,  *zPDWORD;		



typedef bool		zBOOL8	;		
typedef zINT32		zBOOL	;		
typedef zUINT16		zNUMBER	;		
typedef	long		zVALUE	;		
typedef	zVEC2		zPOINT2	;		
typedef	zVEC3		zPOINT3	;		
typedef	zVEC4		zPOINT4	;		
typedef char*		zPSTR	;		




typedef zVEC3 zPOINT3;
typedef signed   short int	zINT;
typedef int	zTFrameCtr;
typedef int	zTModelAniID;
typedef int	zTSoundHandle;
enum {VX, VY, VZ, VW};		    
enum {VA, VB, VC, VD};          
enum {PA, PB, PC, PD};		    
enum {RED, GREEN, BLUE};	    
enum {KA, KD, KS, ES};		    



#include "macros.h"
#include "zmath.h"
#include "zbvolume.h"
#include "zstring.h"
#include "zcobject.h"
#include "zerror.h"
#include <assert.h>




template <class T>
class AI_TYPE
{
	__declspec(dllexport) static float	rate;	
	T									value;	
public :
	operator T()			{ return rate == 1.0f ? value : (T)((float)value * rate); };
	AI_TYPE (int n)			{ value = n;  };
	void SetAITimer(float)	{ rate = val; };
};

template <class T>
float AI_TYPE<T>::rate = 1.0f;

typedef AI_TYPE<zREAL>		zAI_REAL32;		
typedef AI_TYPE<zREAL64>	zAI_REAL64;		