#pragma once

// -- constructors
#ifndef INLINE
#ifdef _MSC_VER
#if (_MSC_VER >= 1200)
#define INLINE __forceinline
#else
#define INLINE __inline
#endif
#endif
#endif

#include "macros.h"
#include "zstring.h"


#pragma warning(disable : 4244)
#pragma warning(disable : 4305)

/** Insert description. 
*/
INLINE zVEC2::zVEC2()
{
	//XCALL(0x0052ED60);
}

/** Insert description.
????
*/
/*
INLINE zVEC2::zVEC2(float f)
{
	n[0] = f;
	n[1] = f;
}
*/
/** Insert description. 
*/
INLINE zVEC2::zVEC2(float x, float y)
{
	XCALL(0x004B4DC0);
}

/** Insert description. 
*/
INLINE zVEC2& zVEC2::operator+=(zVEC2 const& other)
{
	XCALL(0x005B02F0);
}

/** Insert description. 
*/
INLINE zVEC2& zVEC2::operator-=(zVEC2 const& other)
{
	XCALL(0x00691020);
}

/** Insert description. 
*/
INLINE zVEC2& zVEC2::operator*=(float fm)
{
	XCALL(0x00691040);
}

/** Insert description. 
*/
INLINE zVEC2& zVEC2::operator/=(float value)
{
	XCALL(0x004B4DE0);
}

/** Insert description. 
*/
/*
INLINE zVEC2& zVEC2::Normalize()
{
	double norm = 1.0 / sqrt(Length2());
	n[0] *= norm;
	n[1] *= norm;
	return *this;
}
*/

/** Insert description. 
*/
/*
INLINE BOOL zVEC2::IsEqualEps(zVEC2 const& other) const
{
	return (fabs(n[0] - other.n[0]) < 0.001)
		&& (fabs(n[1] - other.n[1]) < 0.001);
}
*/
/** Insert description. 
*/
/*
INLINE zVEC2& zVEC2::Apply(float (*func)(float))
{
	n[0] = func(n[0]);
	n[1] = func(n[1]);
	return *this;
}
*/

inline zSTRING zVEC2::GetDescription() const
{
	XCALL(0x00512A30);
}

inline void zVEC2::SetByDescription(zSTRING const& value)
{
	XCALL(0x00512C70);
}

/** Insert description. 
*/
inline float zVEC2::Length2()
{
	XCALL(0x004B4E00);
}

/** Insert description. 
*/
inline float operator*(zVEC2 const& va, zVEC2 const& vb)
{
	XCALL(0x004B4E20);
}

//.text:00514220 ; int __cdecl operator*(int, float, int)

/** Insert description. 
*/
INLINE zVEC2 operator+(zVEC2 const& va, zVEC2 const& vb)
{
	XCALL(0x0056CB80);
}

/** Insert description. 
*/
INLINE zVEC2 operator-(zVEC2 const& va, zVEC2 const& vb)
{
	XCALL(0x006011C0);
}

/** Insert description. 
*/
INLINE zVEC2 operator*(zVEC2 const& v, float fm)
{
	XCALL(0x00499480);
}

/** Insert description. 
*/
INLINE zVEC2 operator/(zVEC2 const& v, float fd)
{
	return zVEC2(v[0] / fd, v[1] / fd);
}

/** Insert description. 
*/
INLINE zVEC2 operator-(zVEC2 const& v)
{
	return zVEC2(-v[0], -v[1]);
}

/** Insert description. 
*/
INLINE float Alg_SqrtInvApprox(float value)
{
	static float kf1 = 0.5;
	static float kf2 = 1.5;
	float sqrtInv;
	_asm
	{
		fld     value
		fmul    kf1
		mov     eax, value
		mov     ecx, 5F3759DFh
		shr     eax, 1
		sub     ecx, eax
		mov     value, ecx
		fmul    value
		fld     value
		fmul    value
		fld     kf2
		fmul    value
		fxch    st(2)
		fmulp   st(1), st
		fsubp   st(1), st
		fstp	sqrtInv
	}
	return sqrtInv;
}

/** Insert description. 
*/
INLINE zVEC3::zVEC3()
{
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
}

/** Insert description. 
*/
INLINE zVEC3::zVEC3(float f)
{
	n[0] = f;
	n[1] = f;
	n[2] = f;
}

/** Insert description. 
*/
INLINE zVEC3::zVEC3(float x, float y, float z)
{
	n[0] = x;
	n[1] = y;
	n[2] = z;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::operator+=(zVEC3 const& other)
{
	n[0] += other.n[0];
	n[1] += other.n[1];
	n[2] += other.n[2];
	return *this;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::operator-=(zVEC3 const& other)
{
	n[0] -= other.n[0];
	n[1] -= other.n[1];
	n[2] -= other.n[2];
	return *this;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::operator*=(float fm)
{
	n[0] *= fm;
	n[1] *= fm;
	n[2] *= fm;
	return *this;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::operator/=(float fm)
{
	n[0] /= fm;
	n[1] /= fm;
	n[2] /= fm;
	return *this;
}

/** Insert description. 
*/
//INLINE float zVEC3::LengthApprox() const
//{
//	XCALL(0x00490E10)
//}

template <class T>
inline void zSwap (T& a, T& b) {
	const T tmp	= a;
	a			= b;
	b			= tmp;
}

inline zREAL zVEC3::LengthApprox () const {
	// Quelle: Gems4, dist_fast.c
	zREAL ix = (fabs (zREAL(n[VX])));
	zREAL iy = (fabs (zREAL(n[VY])));
	zREAL iz = (fabs (zREAL(n[VZ])));
	
	// needs only two comparisons
	if (ix<iy) zSwap (ix, iy);
	if (ix<iz) zSwap (ix, iz);
	
	// now ix is the largest
	const zREAL t = iy + iz;
	return zREAL((ix - (ix*(1.0 / 16.0)) + (t*(1.0 / 4.0)) + (t*(1.0 / 8.0))));
}; 

/** Insert description. 
*/
INLINE float zVEC3::Distance(const zVEC3& other) const
{
	zVEC3 d;
	d[0] = n[0] - other[0];
	d[1] = n[1] - other[1];
	d[2] = n[2] - other[2];
	return sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

/** Insert description. 
*/
INLINE float zVEC3::DistanceAbs(const zVEC3& other) const
{
	zVEC3 d;
	d[0] = fabs(n[0] - other[0]);
	d[1] = fabs(n[1] - other[1]);
	d[2] = fabs(n[2] - other[2]);
	return d[0] + d[1] + d[2];
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::Normalize()
{
	double norm = 1.0 / sqrt(Length2());
	n[0] *= norm;
	n[1] *= norm;
	n[2] *= norm;
	return *this;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::NormalizeSafe()
{
	double length = sqrt(Length2());
	double norm = 1.0 / (length ? length : 1.0e-6);
	n[0] *= norm;
	n[1] *= norm;
	n[2] *= norm;
	return *this;
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::NormalizeApprox()
{
	double norm = Alg_SqrtInvApprox(Length2());
	n[0] *= norm;
	n[1] *= norm;
	n[2] *= norm;
	return *this;
}

/** Insert description. 
*/
INLINE BOOL zVEC3::IsEqualEps(zVEC3 const& other) const
{
	return (fabs(n[0] - other.n[0]) < 0.001) 
		&& (fabs(n[1] - other.n[1]) < 0.001) 
		&& (fabs(n[2] - other.n[2]) < 0.001);
}

INLINE zSTRING zVEC3::GetString() const
{
		XCALL(0x005375D0);

};

INLINE void zVEC3::SetByDescription(zSTRING const& value)
{
	n[0] = atof(value.PickWord(1, ""," "));
	n[1] = atof(value.PickWord(2, ""," "));
	n[2] = atof(value.PickWord(2, ""," "));
}

/** Insert description. 
*/
INLINE zVEC3& zVEC3::Apply(float (*func)(float))
{
	n[0] = func(n[0]);
	n[1] = func(n[1]);
	n[2] = func(n[2]);
	return *this;
}

/** Insert description. 
*/
INLINE float zVEC3::MultAbs(const zVEC3& other) const
{
	return fabs(n[0] * other[0]) + fabs(n[1] * other[1]) + fabs(n[2] * other[2]);
}

/** Insert description. 
*/
INLINE BOOL operator==(zVEC3 const& va, zVEC3 const& vb)
{
	return (va[0] == vb[0]) && (va[1] == vb[1]) && (va[2] == vb[2]);
}

/** Insert description. 
*/
INLINE zVEC3 operator+(zVEC3 const& va, zVEC3 const& vb)
{
	return zVEC3(va[0] + vb[0], va[1] + vb[1], va[2] + vb[2]);
}

/** Insert description. 
*/
INLINE zVEC3 operator-(zVEC3 const& va, zVEC3 const& vb)
{
	return zVEC3(va[0] - vb[0], va[1] - vb[1], va[2] - vb[2]);
}

/** Insert description. 
*/
INLINE zVEC3 operator^(zVEC3 const& va, zVEC3 const& vb)
{
	return zVEC3(va[1] * vb[2] - va[2] * vb[1],
		va[2] * vb[0] - va[0] * vb[2],
		va[0] * vb[1] - va[1] * vb[0]);
}

/** Insert description. 
*/
INLINE zVEC3 operator*(zVEC3 const& v, float fm)
{
	return zVEC3(v[0] * fm, v[1] * fm, v[2] * fm);
}

/** Insert description. 
*/
INLINE zVEC3 operator/(zVEC3 const& v, float fd)
{
	return zVEC3(v[0] / fd, v[1] / fd, v[2] / fd);
}

/** Insert description. 
*/
INLINE zVEC3 operator-(zVEC3 const& v)
{
	return zVEC3(-v[0], -v[1], -v[2]);
}

INLINE zVEC3 String2Vec3(zSTRING const& str)
{
	float v1 = atof(str.PickWord(0, " "," "));
	float v2 = atof(str.PickWord(1, " "," "));
	float v3 = atof(str.PickWord(2, " "," "));
	return zVEC3(v1, v2, v3);
}

/* Get ALL coord*/
//INLINE float *Get3V()
//{
//	return zVEC3::coord;
//}

INLINE float zVEC3::GetX()
{
	return n[0];
}

/* Get Y coord*/
INLINE float zVEC3::GetY()
{
	return n[1];
}

/* Get Z Coord */
INLINE float zVEC3::GetZ()
{
	return n[2];
}

/** Insert description. 
*/
INLINE zVEC4::zVEC4()
{
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
}

/** Insert description. 
*/
INLINE zVEC4::zVEC4(float f)
{
	n[0] = f;
	n[1] = f;
	n[2] = f;
	n[3] = f;
}

/** Insert description. 
*/
INLINE zVEC4::zVEC4(zVEC3 const& v, float t)
{
	n[0] = v[0];
	n[1] = v[1];
	n[2] = v[2];
	n[3] = t;
}

/** Insert description. 
*/
INLINE zVEC4::zVEC4(float x, float y, float z, float t)
{
	n[0] = x;
	n[1] = y;
	n[2] = z;
	n[3] = t;
}

/** Insert description. 
*/
INLINE zVEC4& zVEC4::operator+=(zVEC4 const& other)
{
	n[0] += other.n[0];
	n[1] += other.n[1];
	n[2] += other.n[2];
	n[3] += other.n[3];
	return *this;
}

/** Insert description. 
*/
INLINE zVEC4& zVEC4::operator-=(zVEC4 const& other)
{
	n[0] -= other.n[0];
	n[1] -= other.n[1];
	n[2] -= other.n[2];
	n[3] -= other.n[3];
	return *this;
}

/** Insert description. 
*/
INLINE zVEC4& zVEC4::operator*=(float fm)
{
	n[0] *= fm;
	n[1] *= fm;
	n[2] *= fm;
	n[3] *= fm;
	return *this;
}

/** Insert description. 
*/
INLINE float zVEC4::LengthApprox() const
{
	float tmp;
	float v0 = fabs(n[0]);
	float v1 = fabs(n[1]);
	float v2 = fabs(n[2]);
	float v3 = fabs(n[3]);
	if(v0 < v1)
	{
		tmp = v0;
		v0 = v1;
		v1 = tmp;
	}
	if(v2 < v3)
	{
		tmp = v2;
		v2 = v3;
		v3 = tmp;
	}
	if(v0 < v2)
	{
		tmp = v0;
		v0 = v2;
		v2 = tmp;
	}
	if(v1 < v3)
	{
		tmp = v1;
		v1 = v3;
		v3 = tmp;
	}
	if(v1 < v2)
	{
		tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	v1 += v2;
	return v0 / 60.0 + v1 * 25.0 + v2 * 19.0 + v3 * 16.0;
}

/** Insert description. 
*/
INLINE zVEC4& zVEC4::Normalize()
{
	double norm = 1.0 / sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2] + n[3] * n[3]);
	n[0] *= norm;
	n[1] *= norm;
	n[2] *= norm;
	n[3] *= norm;
	return *this;
}

/** Insert description. 
*/
INLINE zVEC4& zVEC4::Apply(float (*func)(float))
{
	n[0] = func(n[0]);
	n[1] = func(n[1]);
	n[2] = func(n[2]);
	n[3] = func(n[3]);
	return *this;
}

/** Insert description. 
*/
INLINE BOOL operator==(zVEC4 const& va, zVEC4 const& vb)
{
	return (va[0] == vb[0]) && (va[1] == vb[1]) && (va[2] == vb[2]) && (va[3] == vb[3]);
}

/** Insert description. 
*/
INLINE zVEC4 operator+(zVEC4 const& va, zVEC4 const& vb)
{
	return zVEC4(va[0] + vb[0], va[1] + vb[1], va[2] + vb[2], va[3] + vb[3]);
}

/** Insert description. 
*/
INLINE zVEC4 operator-(zVEC4 const& va, zVEC4 const& vb)
{
	return zVEC4(va[0] - vb[0], va[1] - vb[1], va[2] - vb[2], va[3] - vb[3]);
}

/** Insert description. 
*/
INLINE zVEC4 operator*(zVEC4 const& v, float f)
{
	return zVEC4(v[0] * f, v[1] * f, v[2] * f, v[3] * f);
}

/** Insert description. 
*/
INLINE zVEC4 operator-(zVEC4 const& v)
{
	return zVEC4(-v[0], -v[1], -v[2], -v[3]);
}

/** Insert description. 
*/
INLINE zMAT3::zMAT3(zVEC3 const& v0, zVEC3 const& v1, zVEC3 const& v2)
{
	row[0] = v0;
	row[1] = v1;
	row[2] = v2;
}

/** Insert description. 
*/
INLINE zMAT3::zMAT3(float f)
{
	row[0] = f;
	row[1] = f;
	row[2] = f;
}

/** Insert description. 
*/
INLINE zMAT3& zMAT3::operator+=(zMAT3 const& m)
{
	row[0] += m.row[0];
	row[1] += m.row[1];
	row[2] += m.row[2];
	return *this;
}

/** Insert description. 
*/
INLINE zMAT3& zMAT3::operator-=(zMAT3 const& m)
{
	row[0] -= m.row[0];
	row[1] -= m.row[1];
	row[2] -= m.row[2];
	return *this;
}

/** Insert description. 
*/
INLINE zMAT3& zMAT3::operator*=(float f)
{
	row[0] *= f;
	row[1] *= f;
	row[2] *= f;
	return *this;
}

/** Insert description. 
*/
INLINE zMAT3& zMAT3::operator/=(float f)
{
	row[0] /= f;
	row[1] /= f;
	row[2] /= f;
	return *this;
}

/** Insert description. 
*/
INLINE zMAT3 zMAT3::Transpose() const
{
	return zMAT3(zVEC3(row[0][0], row[1][0], row[2][0]),
		zVEC3(row[0][1], row[1][1], row[2][1]),
		zVEC3(row[0][2], row[1][2], row[2][2]));
}

/** Insert description. 
*/
INLINE zMAT3 zMAT3::Inverse(float* pf)
{
	float kf = (row[1] ^ row[2]) * row[0];
	if(pf)
		*pf = kf;
	kf = 1.0 / kf;
	zVEC3 v0 = zVEC3(
		row[2][2] * row[1][1] - row[2][1] * row[1][2],
		row[2][1] * row[0][2] - row[2][2] * row[0][1],
		row[1][2] * row[0][1] - row[1][1] * row[0][2]);
	zVEC3 v1 = zVEC3(
		row[2][0] * row[1][2] - row[2][1] * row[1][0],
		row[2][2] * row[0][0] - row[2][0] * row[0][2],
		row[1][0] * row[0][2] - row[1][2] * row[0][0]);
	zVEC3 v2 = zVEC3(
		row[2][1] * row[1][0] - row[2][0] * row[1][2],
		row[2][0] * row[0][1] - row[2][1] * row[0][1],
		row[1][1] * row[0][0] - row[1][0] * row[0][1]);
	return kf * zMAT3(v0, v1, v2);
}

/** Insert description. 
*/
INLINE void zMAT3::SetAtVector(zVEC3 const& v)
{
	row[0][2] = v[0];
	row[1][2] = v[1];
	row[2][2] = v[2];
}

/** Insert description. 
*/
INLINE zVEC3 zMAT3::GetAtVector() const
{
	return zVEC3(row[0][2], row[1][2], row[2][2]);
}

/** Insert description. 
*/
INLINE void zMAT3::SetUpVector(zVEC3 const& v)
{
	row[0][1] = v[0];
	row[1][1] = v[1];
	row[2][1] = v[2];
}

/** Insert description. 
*/
INLINE zVEC3 zMAT3::GetUpVector() const
{
	return zVEC3(row[0][1], row[1][1], row[2][1]);
}

/** Insert description. 
*/
INLINE void zMAT3::SetRightVector(zVEC3 const& v)
{
	row[0][0] = v[0];
	row[1][0] = v[1];
	row[2][0] = v[2];
}

/** Insert description. 
*/
INLINE zVEC3 zMAT3::GetRightVector() const
{
	return zVEC3(row[0][0], row[1][0], row[2][0]);
}

/** Insert description. 
*/
INLINE void zMAT3::MakeOrthonormal()
{
	zVEC3 v1 = GetAtVector();
	v1.NormalizeSafe();
	zVEC3 vec = v1 * -(v1 * GetUpVector());
	zVEC3 v2 = vec + GetUpVector();
	v2.NormalizeSafe();
	vec = v2 ^ v1;
	SetAtVector(v1);
	SetUpVector(v2);
	SetRightVector(vec);
}

/** Insert description. 
*/
INLINE zMAT3& zMAT3::Apply(float (*func)(float))
{
	row[0].Apply(func);
	row[1].Apply(func);
	row[2].Apply(func);
	return *this;
}

/** Insert description. 
*/
INLINE zMAT3 operator-(zMAT3 const& m)
{
	return zMAT3(-m[0], -m[1], -m[2]);
}

/** Insert description. 
*/
INLINE zMAT3 operator+(zMAT3 const& ma, zMAT3 const& mb)
{
	return zMAT3(ma[0] + mb[0], ma[1] + mb[1], ma[2] + mb[2]);
}

/** Insert description. 
*/
INLINE zMAT3 operator-(zMAT3 const& ma, zMAT3 const& mb)
{
	return zMAT3(ma[0] - mb[0], ma[1] - mb[1], ma[2] - mb[2]);
}

/** Insert description. 
*/
INLINE zMAT3 operator*(zMAT3 const& ma, zMAT3 const& mb)
{
	zVEC3 v0 = zVEC3(
		mb[0][0] * ma[0][0] + mb[1][0] * ma[0][1] + mb[2][0] * ma[0][2],
		mb[0][1] * ma[0][0] + mb[1][1] * ma[0][1] + mb[2][1] * ma[0][2],
		mb[0][2] * ma[0][0] + mb[1][2] * ma[0][1] + mb[2][2] * ma[0][2]);
	zVEC3 v1 = zVEC3(
		mb[0][0] * ma[1][0] + mb[1][0] * ma[1][1] + mb[2][0] * ma[1][2],
		mb[0][1] * ma[1][0] + mb[1][1] * ma[1][1] + mb[2][1] * ma[1][2],
		mb[0][2] * ma[1][0] + mb[1][2] * ma[1][1] + mb[2][2] * ma[1][2]);
	zVEC3 v2 = zVEC3(
		mb[0][0] * ma[2][0] + mb[1][0] * ma[2][1] + mb[2][0] * ma[2][2],
		mb[0][1] * ma[2][0] + mb[1][1] * ma[2][1] + mb[2][1] * ma[2][2],
		mb[0][2] * ma[2][0] + mb[1][2] * ma[2][1] + mb[2][2] * ma[2][2]);
	return zMAT3(v0, v1, v2);
}

/** Insert description. 
*/
INLINE zVEC3 operator*(zMAT3 const& m, zVEC3 const& v)
{
	return zVEC3(m[0] * v, m[1] * v, m[2] * v);
}

/** Insert description. 
*/
INLINE zVEC2 operator*(zMAT3 const& m, zVEC2 const& v)
{
	zVEC2 vr(m[0][0] * v[0] + m[0][1] * v[1] + m[0][2], m[1][0] * v[0] + m[1][1] * v[1] + m[1][2]);
	float scale = 1.0 / (m[2][0] * v[0] + m[2][1] * v[1] + m[2][2]);
	return vr * scale;
}

/** Insert description. 
*/
INLINE zMAT3 operator*(zMAT3 const& m, float f)
{
	return zMAT3(m[0] * f, m[1] * f, m[2] * f);
}

/** Insert description. 
*/
INLINE zMAT3 operator*(float f, zMAT3 const& m)
{
	return zMAT3(m[0] * f, m[1] * f, m[2] * f);
}

/** Insert description. 
*/
INLINE zMAT3 operator/(zMAT3 const& m, float f)
{
	return zMAT3(m[0] / f, m[1] / f, m[2] / f);
}

/** Insert description. 
*/
INLINE BOOL operator==(zMAT3 const& ma, zMAT3 const& mb)
{
	return (ma[0] == mb[0]) && (ma[1] == mb[1]) && (ma[2] == mb[2]);
}

/** Insert description. 
*/
INLINE BOOL operator!=(zMAT3 const& ma, zMAT3 const& mb)
{
	return ((ma[0] == mb[0]) && (ma[1] == mb[1]) && (ma[2] == mb[2])) == FALSE;
}

/** Insert description. 
*/
INLINE zMAT4::zMAT4(zVEC4 const& v0, zVEC4 const& v1, zVEC4 const& v2, zVEC4 const& v3)
{
	row[0] = v0;
	row[1] = v1;
	row[2] = v2;
	row[3] = v3;
}

/** Insert description. 
*/
INLINE zMAT4::zMAT4(float f)
{
	row[0] = f;
	row[1] = f;
	row[2] = f;
	row[3] = f;
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::operator+=(zMAT4 const& m)
{
	row[0] += m.row[0];
	row[1] += m.row[1];
	row[2] += m.row[2];
	row[3] += m.row[3];
	return *this;
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::operator-=(zMAT4 const& m)
{
	row[0] -= m.row[0];
	row[1] -= m.row[1];
	row[2] -= m.row[2];
	row[3] -= m.row[3];
	return *this;
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::operator*=(float f)
{
	row[0] *= f;
	row[1] *= f;
	row[2] *= f;
	row[3] *= f;
	return *this;
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::operator/=(float f)
{
	row[0] *= 1.0 / f;
	row[1] *= 1.0 / f;
	row[2] *= 1.0 / f;
	row[3] *= 1.0 / f;
	return *this;
}

/** Insert description. 
*/
INLINE zMAT4 zMAT4::Transpose() const
{
	return zMAT4(zVEC4(row[0][0], row[1][0], row[2][0], row[3][0]),
		zVEC4(row[0][1], row[1][1], row[2][1], row[3][1]),
		zVEC4(row[0][2], row[1][2], row[2][2], row[3][2]),
		zVEC4(row[0][3], row[1][3], row[2][3], row[3][3]));
}

/** Insert description. 
*/
INLINE zMAT4 zMAT4::Inverse() const
{
	XCALL(0x000515500);
}

/** Insert description. 
*/
INLINE zMAT4 zMAT4::InverseLinTrafo() const
{
	/*
	zMAT4 mat(zVEC4(row[0][0], row[1][0], row [2][0], 0),
		zVEC4(row[0][1], row[1][1], row[2][1], 0),
		zVEC4(row[0][2], row[1][2], row[2][2], 0),
		zVEC4(row[3][0], row[3][1], row[3][2], row[3][3]));
	zVEC3 vec(row[0][0] * -row[0][3] + row[1][0] * -row[1][3] + row[2][0] * -row[2][3],
		row[0][1] * -row[0][3] + row[1][1] * -row[1][3] + row[2][1] * -row[2][3],
		row[0][2] * -row[0][3] + row[1][2] * -row[1][3] + row[2][2] * -row[2][3]);
	mat.SetTranslation(vec);
	return mat;
	*/
	XCALL(0x00515340);
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::Translate(zVEC3 const& v)
{
	row[0][3] += v[0];
	row[1][3] += v[1];
	row[2][3] += v[2];
	return (*this);
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::SetTranslation(zVEC3 const& v)
{
XCALL(0x00487C50)
}

/** Insert description. 
//.text:00408EE0 ; public: class zVEC3 __thiscall zMAT4::GetTranslation(void)const
*/
INLINE zVEC3 zMAT4::GetTranslation() const
{
	XCALL(0x00408EE0);
}

/** Insert description. 
*/
INLINE void zMAT4::GetTranslation(zVEC3& v) const
{
	v[0] = row[0][3];
	v[1] = row[1][3];
	v[2] = row[2][3];
}

/** Insert description. 
*/
INLINE void zMAT4::SetAtVector(zVEC3 const& v)
{
	XCALL(0x0056B960)
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::GetAtVector() const
{
	return zVEC3(row[0][2], row[1][2], row[2][2]);
}

/** Insert description. 
*/
INLINE void zMAT4::SetUpVector(zVEC3 const& v)
{
XCALL(0x004B9D90)
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::GetUpVector() const
{
	return zVEC3(row[0][1], row[1][1], row[2][1]);
}

/** Insert description. 
*/
INLINE void zMAT4::SetRightVector(zVEC3 const& v)
{
	row[0][0] = v[0];
	row[1][0] = v[1];
	row[2][0] = v[2];
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::GetRightVector() const
{
	return zVEC3(row[0][0], row[1][0], row[2][0]);
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::ExtractScaling() const
{
	return zVEC3(sqrt(GetRightVector().Length2()), sqrt(GetUpVector().Length2()), sqrt(GetAtVector().Length2()));
}

/** Insert description. 
*/
INLINE zMAT3 zMAT4::ExtractRotation()
{
	zVEC3 vscale = ExtractScaling();
	zMAT4 m(zVEC4(1.0 / vscale[0], 0, 0, 0), zVEC4(0, 1.0 / vscale[1], 0, 0),
		zVEC4(0, 0, 1.0 / vscale[2], 0), zVEC4(0, 0, 0, 1.0));
	zMAT4 mr = *this * m;
	zMAT3 mrot(zVEC3(mr[0][0], mr[0][1], mr[0][2]), zVEC3(mr[1][0], mr[1][1], mr[1][2]), zVEC3(mr[2][0], mr[2][1], mr[2][2]));
	return mrot;
}

/** Insert description. 
*/
INLINE void zMAT4::MakeOrthonormal()
{
	XCALL(0x00517330)
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::Rotate(zVEC3 const& v) const
{
	return zVEC3(zVEC3(row[0][0], row[0][1], row[0][2]) * v,
		zVEC3(row[1][0], row[1][1], row[1][2]) * v,
		zVEC3(row[2][0], row[2][1], row[2][2]) * v);
}

/** Insert description. 
.text:00517730 ; int __stdcall zMAT4__PostRotateX(float)
*/
INLINE void zMAT4::PostRotateX(float angle)
{
	XCALL(0x00517730);
}

/** Insert description. 
.text:00517780 ; int __stdcall zMAT4__PostRotateY(float)
*/
INLINE void zMAT4::PostRotateY(float angle)
{
	XCALL(0x00517780);
}

/** Insert description. 
.text:005177D0 ; int __stdcall zMAT4__PostRotateZ(float)
*/
INLINE void zMAT4::PostRotateZ(float angle)
{
	XCALL(0x005177D0);
}

/** Insert description. 
.text:00517820 ; public: void __thiscall zMAT4::PostScale(class zVEC3 const &)
*/
INLINE void zMAT4::PostScale(zVEC3 const& scale)
{
	XCALL(0x00517820);
}

/** Insert description. 
.text:00517840 ; public: void __thiscall zMAT4::PreScale(class zVEC3 const &)
*/
INLINE void zMAT4::PreScale(zVEC3 const& scale)
{
	XCALL(0x00517840);
}

/** Insert description. 
*/
INLINE zVEC3 zMAT4::GetEulerAngles() const
{
	zCQuat qt;
	qt.Matrix4ToQuat(*this);
	zVEC3 veul;
	qt.QuatToEuler(veul);
	return veul;
}

/** Insert description. 
*/
INLINE void zMAT4::SetByEulerAngles(zVEC3 veul)
{
	zCQuat qt;
	qt.EulerToQuat(veul);
	qt.QuatToMatrix4(*this);
}

/** Insert description. 
*/
INLINE BOOL zMAT4::IsUpper3x3Orthonormal() const
{
	zVEC3 vright = GetRightVector();
	zVEC3 vat = GetAtVector();
	if(fabs(vright * vat) > 0.01)
		return FALSE;
	zVEC3 vup = GetUpVector();
	if(fabs(vup * vat) > 0.01)
		return FALSE;
	if(fabs(vright * vup) > 0.01)
		return FALSE;
	float dst = sqrt(vat.Length2());
	if((dst < 0.99) || (dst > 1.01))
		return FALSE;
	dst = sqrt(vup.Length2());
	if((dst < 0.99) || (dst > 1.01))
		return FALSE;
	dst = sqrt(vright.Length2());
	if((dst < 0.99) || (dst > 1.01))
		return FALSE;
	return TRUE;
}

/** Insert description. 
*/
INLINE zMAT4& zMAT4::Apply(float (*func)(float))
{
	row[0].Apply(func);
	row[1].Apply(func);
	row[2].Apply(func);
	row[3].Apply(func);
	return *this;
}

/** Insert description. 
*/
INLINE zMAT4 operator-(zMAT4 const& m)
{
	return zMAT4(-m[0], -m[1], -m[2], -m[3]);
}

/** Insert description. 
*/
INLINE zMAT4 operator+(zMAT4 const& ma, zMAT4 const& mb)
{
	return zMAT4(ma[0] + mb[0], ma[1] + mb[1], ma[2] + mb[2], ma[3] + mb[3]);
}

/** Insert description. 
*/
INLINE zMAT4 operator-(zMAT4 const& ma, zMAT4 const& mb)
{
	return zMAT4(ma[0] - mb[0], ma[1] - mb[1], ma[2] - mb[2], ma[3] - mb[3]);
}

/** Insert description. 
*/
INLINE zMAT4 operator*(zMAT4 const& ma, zMAT4 const& mb)
{
	zVEC4 v0 = zVEC4(
		mb[0][0]*ma[0][0] + mb[1][0]*ma[0][1] + mb[2][0]*ma[0][2] + mb[3][0]*ma[0][3],
		mb[0][1]*ma[0][0] + mb[1][1]*ma[0][1] + mb[2][1]*ma[0][2] + mb[3][1]*ma[0][3],
		mb[0][2]*ma[0][0] + mb[1][2]*ma[0][1] + mb[2][2]*ma[0][2] + mb[3][2]*ma[0][3],
		mb[0][3]*ma[0][0] + mb[1][3]*ma[0][1] + mb[2][3]*ma[0][2] + mb[3][3]*ma[0][3]);
	zVEC4 v1 = zVEC4(
		mb[0][0]*ma[1][0] + mb[1][0]*ma[1][1] + mb[2][0]*ma[1][2] + mb[3][0]*ma[1][3],
		mb[0][1]*ma[1][0] + mb[1][1]*ma[1][1] + mb[2][1]*ma[1][2] + mb[3][1]*ma[1][3],
		mb[0][2]*ma[1][0] + mb[1][2]*ma[1][1] + mb[2][2]*ma[1][2] + mb[3][2]*ma[1][3],
		mb[0][3]*ma[1][0] + mb[1][3]*ma[1][1] + mb[2][3]*ma[1][2] + mb[3][3]*ma[1][3]);
	zVEC4 v2 = zVEC4(
		mb[0][0]*ma[2][0] + mb[1][0]*ma[2][1] + mb[2][0]*ma[2][2] + mb[3][0]*ma[2][3],
		mb[0][1]*ma[2][0] + mb[1][1]*ma[2][1] + mb[2][1]*ma[2][2] + mb[3][1]*ma[2][3],
		mb[0][2]*ma[2][0] + mb[1][2]*ma[2][1] + mb[2][2]*ma[2][2] + mb[3][2]*ma[2][3],
		mb[0][3]*ma[2][0] + mb[1][3]*ma[2][1] + mb[2][3]*ma[2][2] + mb[3][3]*ma[2][3]);
	zVEC4 v3 = zVEC4(
		mb[0][0]*ma[3][0] + mb[1][0]*ma[3][1] + mb[2][0]*ma[3][2] + mb[3][0]*ma[3][3],
		mb[0][1]*ma[3][0] + mb[1][1]*ma[3][1] + mb[2][1]*ma[3][2] + mb[3][1]*ma[3][3],
		mb[0][2]*ma[3][0] + mb[1][2]*ma[3][1] + mb[2][2]*ma[3][2] + mb[3][2]*ma[3][3],
		mb[0][3]*ma[3][0] + mb[1][3]*ma[3][1] + mb[2][3]*ma[3][2] + mb[3][3]*ma[3][3]);
	return zMAT4(v0, v1, v2, v3);
}

/** Insert description. 
*/
INLINE zVEC3 operator*(zMAT4 const& m, zVEC3 const& v)
{
	return zVEC3(
		m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3],
		m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3],
		m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3]);
}

/** Insert description. 
*/
INLINE zMAT4 operator*(zMAT4 const& m, float f)
{
	return zMAT4(m[0] * f, m[1] * f, m[2] * f, m[3] * f);
}

/** Insert description. 
*/
INLINE zMAT4 operator*(float f, zMAT4 const& m)
{
	return zMAT4(m[0] * f, m[1] * f, m[2] * f,  m[3] * f);
}

/** Insert description. 
*/
INLINE zMAT4 operator/(zMAT4 const& m, float f)
{
	return zMAT4(m[0] * (1.0 / f), m[1] * (1.0 / f), m[2] * (1.0 / f),  m[3] * (1.0 / f));
}

/** Insert description. 
*/
INLINE BOOL operator==(zMAT4 const& ma, zMAT4 const& mb)
{
	return (ma[0] == mb[0]) && (ma[1] == mb[1]) && (ma[2] == mb[2]) && (ma[3] == mb[3]);
}

/** Insert description. 
*/
INLINE BOOL operator!=(zMAT4 const& ma, zMAT4 const& mb)
{
	return ((ma[0] == mb[0]) && (ma[1] == mb[1]) && (ma[2] == mb[2]) && (ma[3] == mb[3])) == FALSE;
}

/** Insert description. 
*/
INLINE void zCQuat::Unit()
{
	qt.Normalize();
}

/** Insert description. 
*/
INLINE void zCQuat::QuatToMatrix3(zMAT3& mat) const
{
	mat[0][0] = qt[0] * qt[0] + qt[3] * qt[3] - qt[1] * qt[1] - qt[2] * qt[2];
	mat[0][1] = (qt[0] * qt[1] + qt[2] * qt[3]) * 2;
	mat[0][2] = (qt[0] * qt[2] - qt[1] * qt[3]) * 2;

	mat[1][0] = (qt[0] * qt[1] - qt[2] * qt[3]) * 2;
	mat[1][1] = qt[3] * qt[3] - qt[0] * qt[0] + qt[1] * qt[1] - qt[2] * qt[2];
	mat[1][2] = (qt[1] * qt[2] + qt[0] * qt[3]) * 2;

	mat[2][0] = (qt[0] * qt[2] + qt[1] * qt[3]) * 2;
	mat[2][1] = (qt[1] * qt[2] - qt[0] * qt[3]) * 2;
	mat[2][2] = qt[3] * qt[3] - qt[0] * qt[0] - qt[1] * qt[1] + qt[2] * qt[2];
}

/** Insert description. 
*/
INLINE void zCQuat::QuatToMatrix4(zMAT4& mat) const
{
	mat[0][0] = qt[0] * qt[0] + qt[3] * qt[3] - qt[1] * qt[1] - qt[2] * qt[2];
	mat[0][1] = (qt[0] * qt[1] + qt[2] * qt[3]) * 2;
	mat[0][2] = (qt[0] * qt[2] - qt[1] * qt[3]) * 2;

	mat[1][0] = (qt[0] * qt[1] - qt[2] * qt[3]) * 2;
	mat[1][1] = qt[3] * qt[3] - qt[0] * qt[0] + qt[1] * qt[1] - qt[2] * qt[2];
	mat[1][2] = (qt[1] * qt[2] + qt[0] * qt[3]) * 2;

	mat[2][0] = (qt[0] * qt[2] + qt[1] * qt[3]) * 2;
	mat[2][1] = (qt[1] * qt[2] - qt[0] * qt[3]) * 2;
	mat[2][2] = qt[3] * qt[3] - qt[0] * qt[0] - qt[1] * qt[1] + qt[2] * qt[2];
}

/** Insert description. 
*/
INLINE void zCQuat::Matrix3ToQuat(zMAT3 const& mat)
{
	float dig = mat[0][0] + mat[1][1] + mat[2][2];
	if(dig > 0)
	{
		float kf = sqrt(dig + 1.0);
		qt[3] = kf * 0.5;
		kf = 0.5 / kf;
		qt[0] = (mat[1][2] - mat[2][1]) * kf;
		qt[1] = (mat[2][0] - mat[0][2]) * kf;
		qt[2] = (mat[0][1] - mat[1][0]) * kf;
		return;
	}
	int k = 0;
	if(mat[1][1] > mat[0][0])
		k = 1;
	if(mat[2][2] > mat[k][k])
		k = 2;
	int r[3] = { 1, 2, 0 };
	float kf = sqrt(mat[k][k] - (mat[r[r[k]]][r[r[k]]] + mat[r[k]][r[k]]) + 1.0);
	qt[k] = kf * 0.5;
	if(kf != 0)
		kf = 0.5 / kf;
	qt[3] = (mat[r[k]][r[r[k]]] - mat[r[r[k]]][r[k]]) * kf;
	qt[r[k]] = (mat[k][r[k]] + mat[r[k]][k]) * kf;
	qt[r[r[k]]] = (mat[k][r[r[k]]] + mat[r[r[k]]][k]) * kf;
}

/** Insert description. 
*/
INLINE void zCQuat::Matrix4ToQuat(zMAT4 const& mat)
{
	float dig = mat[0][0] + mat[1][1] + mat[2][2];
	if(dig > 0)
	{
		float kf = sqrt(dig + 1.0);
		qt[3] = kf * 0.5;
		kf = 0.5 / kf;
		qt[0] = (mat[1][2] - mat[2][1]) * kf;
		qt[1] = (mat[2][0] - mat[0][2]) * kf;
		qt[2] = (mat[0][1] - mat[1][0]) * kf;
		return;
	}
	int k = 0;
	if(mat[1][1] > mat[0][0])
		k = 1;
	if(mat[2][2] > mat[k][k])
		k = 2;
	int r[3] = { 1, 2, 0 };
	float kf = sqrt(mat[k][k] - (mat[r[r[k]]][r[r[k]]] + mat[r[k]][r[k]]) + 1.0);
	qt[k] = kf * 0.5;
	if(kf != 0)
		kf = 0.5 / kf;
	qt[3] = (mat[r[k]][r[r[k]]] - mat[r[r[k]]][r[k]]) * kf;
	qt[r[k]] = (mat[k][r[k]] + mat[r[k]][k]) * kf;
	qt[r[r[k]]] = (mat[k][r[r[k]]] + mat[r[r[k]]][k]) * kf;
}

/** Insert description. 
*/
INLINE void zCQuat::QuatToEuler(zVEC3& veu) const
{
	float angle = -(qt[0] * qt[2] - qt[1] * qt[3]) * 2;
	if(fabs(angle) > 1.0)
	{
		veu[0] = atan2f((qt[1] * qt[1] + qt[3] * qt[3]) * 2 - 1.0, -(qt[1] * qt[2] - qt[0] * qt[3]) * 2);
		veu[1] = (angle > 0) ? 3.141592653589793 / 2 : -3.141592653589793 / 2;
		veu[2] = 0;
	}
	else
	{
		veu[0] = atan2f((qt[2] * qt[2] + qt[3] * qt[3]) * 2 - 1.0, (qt[1] * qt[2] + qt[0] * qt[3]) * 2);
		veu[1] = asin(angle);
		veu[2] = atan2f((qt[1] * qt[1] + qt[3] * qt[3]) * 2 - 1.0, (qt[0] * qt[1] + qt[2] * qt[3]) * 2);
	}
}

/** Insert description. 
*/
INLINE void zCQuat::EulerToQuat(zVEC3 const& veu)
{
	float sn0 = sin(veu[0] * 0.5);
	float cs0 = cos(veu[0] * 0.5);
	float sn1 = sin(veu[1] * 0.5);
	float cs1 = cos(veu[1] * 0.5);
	float sn2 = sin(veu[2] * 0.5);
	float cs2 = cos(veu[2] * 0.5);
	qt[3] = sn0 * sn1 * sn2 + cs0 * cs1 * cs2;
	qt[0] = sn0 * cs1 * cs2 - cs0 * sn1 * sn2;
	qt[1] = cs0 * sn1 * cs2 + sn0 * cs1 * sn2;
	qt[2] = cs0 * cs1 * sn2 - sn0 * sn1 * cs2;
}

/** Insert description. 
*/
INLINE void zCQuat::QuatToAxisAngle(zVEC3& vAxis, float& fAngle) const
{
	float fSqrLength = qt[0] * qt[0] + qt[1] * qt[1] + qt[2] * qt[2];
	if(fSqrLength > 1.0e-6)
	{
		float fInvLength = 1.0 / fSqrLength;
		vAxis[0] = qt[0] * fInvLength;
		vAxis[1] = qt[1] * fInvLength;
		vAxis[2] = qt[2] * fInvLength;
		fAngle = 2.0 * acos(qt[3]);
	}
	else
	{
		// angle is 0 (mod 2*pi), so any axis will do
		vAxis[0] = 0.0;
		vAxis[1] = 0.0;
		vAxis[2] = 1.0;
		fAngle = 0.0;
	}
}

/** Insert description. 
*/
INLINE void zCQuat::QuatToAngAxis(zVEC3& vAxis, float& fAngle) const
{
    // The quaternion representing the rotation is
	// q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k)
	float fSqrLength = qt[0] * qt[0] + qt[1] * qt[1] + qt[2] * qt[2];
	if(fSqrLength > 0.0)
	{
		fAngle = 2.0 * acos(qt[3]);
		float fInvLength = 1.0 / sqrt(fSqrLength);
		vAxis[0] = -qt[0] * fInvLength;
		vAxis[1] = -qt[1] * fInvLength;
		vAxis[2] = -qt[2] * fInvLength;
	}
	else
	{
		// angle is 0 (mod 2*pi), so any axis will do
		fAngle = 0.0;
		vAxis[0] = 0.0;
		vAxis[1] = 1.0;
		vAxis[2] = 0.0;
	}
}

/** Insert description. 
*/
INLINE void zCQuat::Slerp(float fT, const zCQuat& rkP, const zCQuat& rkQ)
{
	float fCos = 0.0f;
	for(int j = 0; j < 4; j++)
		fCos += rkP[j] * rkQ[j];

	float fAngle;
	if(-1.0f < fCos)
    {
        if(fCos < 1.0f)
            fAngle = acos(fCos);
        else
            fAngle = 0.0f;
    }
    else
    {
		static float fPi = 4.0f * atan(1.0f);
		fAngle = fPi;
    } 
    if(fabs(fAngle) < 1e-3f)
	{
		for(int j = 0; j < 4; j++)
			qt[j] = rkP[j];
	}
	else
	{
		float fSin = sin(fAngle);
		float fInvSin = 1.0f / fSin;
	    float fCoeff0 = sin((1.0f - fT) * fAngle) * fInvSin;
		float fCoeff1 = sin(fT * fAngle) * fInvSin;
		if(fCos < 0.0f)
			fCoeff0 = -fCoeff0;
		for(int j = 0; j < 4; j++)
			qt[j] = fCoeff0 * rkP[j] + fCoeff1 * rkQ[j];
	}
}

/** Insert description. 
*/
INLINE void zCQuat::Lerp(float fT, zCQuat const& rkP, zCQuat const& rkQ)
{
	zVEC4 vq = rkQ.qt * fT;
	zVEC4 vp = rkP.qt * (1.0 / fT);
	if(rkQ.qt * rkP.qt < 0)
		qt = vp - vq;
	else
		qt = vp + vq;
}

/** Insert description. 
*/
INLINE void zCQuat::Squad(float fT, zCQuat const& sQ0, zCQuat const& sQ1, zCQuat const& sQ2, zCQuat const& sQ3)
{
	zCQuat qt0, qt1;
	qt0.Slerp(fT, sQ0, sQ1);
	qt0.Unit();
	qt1.Slerp(fT, sQ2, sQ3);
	qt1.Unit();
	Slerp((1.0 - fT) * fT * 2, qt0, qt1);
}

INLINE void zMAT4::LookAt(const zVEC3 target) 
{
	zVEC3 f = GetTranslation() - target;
	f.Normalize();
	zVEC3 s = f.Cross(zVEC3(0, 1, 0));
	s.Normalize();
	zVEC3 v = s.Cross(f);

	f *= -1; //negate?

			 //build V matrix;
	row[0][0] = s[0];
	row[1][0] = s[1];
	row[2][0] = s[2];

	row[0][1] = v[0];
	row[1][1] = v[1];
	row[2][1] = v[2];

	row[0][2] = f[0];
	row[1][2] = f[1];
	row[2][2] = f[2];
}

