// *********************************
// Standard Voice Modul
// *********************************

#ifndef __OSVM__
#define __OSWM__

#include "g2api\zString.h"
#include "G2API\macros.h"

class oCSVM;

class oCSVMManager {
public :
	oCSVMManager		( ){XCALL(0x00779B70)};
	~oCSVMManager		( ){XCALL(0x00779E10)};

	int			GetOU	( const zSTRING& name, int voicenr ){XCALL(0x00779E50)};
private :
	int			svm_max;

	oCSVM*		sv_module;
};

class oCSVM {
public:
	oCSVM						( ){XCALL(0x0077A260)};
	~oCSVM						( ){XCALL(0x0077A270)};

	void		InitByScript	( int i ){XCALL(0x0077A290)};
	int			GetOU			( const zSTRING& id ){XCALL(0x0077A540)};

private:
	int			number;
	int			classindex;
	zSTRING*	entry;
};

#endif