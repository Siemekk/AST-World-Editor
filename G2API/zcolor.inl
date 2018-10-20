#pragma once

#ifndef INLINE
#ifdef _MSC_VER
#if (_MSC_VER >= 1200)
#define INLINE __forceinline
#else
#define INLINE __inline
#endif
#endif
#endif

///////////////////////////////////////////////////////////////////////////////
//
// zCOLOR
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// -- constructors

INLINE zCOLOR::zCOLOR() 
{ 
	Reset(); 
};

INLINE zCOLOR::zCOLOR(BYTE _r, BYTE _g, BYTE _b) 
{ 
	b = _b; 
	g = _g; 
	r = _r; 
	a = 255; 
};  

///////////////////////////////////////////////////////////////////////////////
// -- functions

INLINE void zCOLOR::SetRGBA(BYTE _r, BYTE _g, BYTE _b, BYTE _a) 
{ 
	r = _r; 
	g = _g; 
	b = _b; 
	a = _a; 
};

INLINE void zCOLOR::SetBGRA(BYTE _b, BYTE _g, BYTE _r, BYTE _a) 
{ 
	r = _r; 
	g = _g; 
	b = _b; 
	a = _a; 
};

INLINE void zCOLOR::SetR(BYTE _c) { r = _c; };
INLINE void zCOLOR::SetG(BYTE _c) { g = _c; };
INLINE void zCOLOR::SetB(BYTE _c) { b = _c; };
INLINE void zCOLOR::SetA(BYTE _c) { a = _c; };

INLINE BYTE zCOLOR::GetR(void) { return r; };
INLINE BYTE zCOLOR::GetG(void) { return g; };
INLINE BYTE zCOLOR::GetB(void) { return b; };
INLINE BYTE zCOLOR::GetA(void) { return a; };

INLINE BOOL zCOLOR::operator==(const zCOLOR& clr2) const
{
	const zCOLOR& clr1 = *this;
	return clr1.data == clr2.data;
}

INLINE BOOL zCOLOR::operator!=(const zCOLOR& clr2) const
{
	const zCOLOR& clr1 = *this;
	return clr1.data != clr2.data;
}
