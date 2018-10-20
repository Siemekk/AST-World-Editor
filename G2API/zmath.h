#pragma once

const double PI		= 3.14159265359;	
const double RAD	= PI / 180.0f;
const double DEGREE = 180.0 / PI;	

#pragma warning (disable: 4244)
const float RAD90	= 90.0f / DEGREE;
const float RAD180	= 180.0f / DEGREE;
const float RAD270	= 270.0f / DEGREE;

inline float SafeDiv(float f1, float f2)
{
	if (f1 == 0.00000f || f2 == 0.00000f)
		return 0.00000f;
	return f1 / f2;


	//static float fvalid = 0.001f; // what is the fuck lol
	//if(f1 < fvalid && f1 > -fvalid)
	//	return 0.0f;
	//if(f2 < fvalid && f2 > -fvalid)
	//	return 0.0f;
	//return f1 / f2;
}

#pragma warning (default: 4244)


#include "zstring.h"

class zVec2D;
class zVec3D;
class zVec4D;

inline int zFloat2Int (const float f)
{
	int i;
	__asm fld [f]
	__asm fistp [i]
	return i;
}

inline void zClamp(int& value, int bl, int bh)
{
	if(value < bl)
		value = bl;
	else if(value > bh)
		value = bh;
}


inline void zClamp(float& value, float bl, float bh)
{
	if(value < bl)
		value = bl;
	else if(value > bh)
		value = bh;
}


class zVEC2				
{
public:
	float		n[2];
public:

	operator zVec2D& ();

	zVEC2();
	
	zVEC2(float, float);
	zVEC2& operator+=(zVEC2 const&);
	zVEC2& operator-=(zVEC2 const&);
	zVEC2& operator*=(float);
	float& operator[](int);
	const float& operator[](int) const;
	zVEC2& operator/=(float);
	

	float Length2();
	
	zVEC2& Apply(float (*)(float));
	zSTRING GetDescription() const;
	void SetByDescription(zSTRING const&);
};


inline float& zVEC2::operator[](int index)
{
	return n[index];
}


inline const float& zVEC2::operator[](int index) const
{
	return n[index];
}




float operator*(zVEC2 const&, zVEC2 const&);

zVEC2 operator+(zVEC2 const&, zVEC2 const&);

zVEC2 operator-(zVEC2 const&, zVEC2 const&);

zVEC2 operator*(zVEC2 const&, float);

zVEC2 operator/(zVEC2 const&, float);

zVEC2 operator-(zVEC2 const&);




class zVEC3				
{
public:
	float		n[3];

	operator zVec3D& ();

	zVEC3();
	zVEC3(float);
	zVEC3(float, float, float);
	zVEC3& operator-=(zVEC3 const&);
	zVEC3& operator+=(zVEC3 const&);
	zVEC3& operator*=(float);
	zVEC3& operator/=(float);
	float& operator[](int);
	const float& operator[](int) const;
	float Length2() const;
	float Length() const;
	float LengthApprox() const;
	float Distance(const zVEC3&) const;
	float DistanceAbs(const zVEC3&) const;
	zVEC3& Normalize();
	zVEC3& NormalizeSafe();
	zVEC3& NormalizeApprox();
	BOOL IsEqualEps(zVEC3 const&) const;
	
	zSTRING GetString(void)const;
	void SetByDescription( const zSTRING& str );
	zVEC3& Apply(float (*)(float));
	float MultAbs(const zVEC3&) const;
	
	float GetX();
	float GetY();
	float GetZ();
	
	float Dot(const zVEC3& other) const
	{
		const zVEC3& va = *this;
		const zVEC3& vb = other;
		return va[0] * vb[0] + va[1] * vb[1] + va[2] * vb[2];
	};

	zVEC3 Cross(const zVEC3& other) const
	{
		const zVEC3& va = *this;
		const zVEC3& vb = other;
		return zVEC3(va[1] * vb[2] - va[2] * vb[1],
					 va[2] * vb[0] - va[0] * vb[2],
					 va[0] * vb[1] - va[1] * vb[0]);
	};
	float GetAngleXZ ();
	float GetAngleXY ();
	float GetAngleYZ ();

	zVEC3& RotateXZ (const float&);
	zVEC3& RotateXY (const float&);
	zVEC3& RotateYZ (const float&);
};


inline float& zVEC3::operator[](int index)
{
	return n[index];
}


inline const float& zVEC3::operator[](int index) const
{
	return n[index];
}


inline float zVEC3::Length2() const
{
	return n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
}


inline float zVEC3::Length() const
{
	return sqrt(Length2());
}



BOOL operator==(zVEC3 const&, zVEC3 const&);

zVEC3 operator+(zVEC3 const&, zVEC3 const&);

zVEC3 operator-(zVEC3 const&, zVEC3 const&);

zVEC3 operator^(zVEC3 const&, zVEC3 const&);

zVEC3 operator*(zVEC3 const&, float);

zVEC3 operator/(zVEC3 const&, float);

float operator*(zVEC3 const&, zVEC3 const&);

zVEC3 operator-(zVEC3 const&);



inline float operator*(zVEC3 const& va, zVEC3 const& vb)
{
	return va[0] * vb[0] + va[1] * vb[1] + va[2] * vb[2];
}



class zVEC4					
{
public:
	float		n[4];
public:

	operator zVec4D& ();

	zVEC4();
	zVEC4(float);
	zVEC4(zVEC3 const&, float);
	zVEC4(float, float, float, float);
	zVEC4& operator+=(zVEC4 const&);
	zVEC4& operator-=(zVEC4 const&);
	zVEC4& operator*=(float);
	float& operator[](int);
	const float& operator[](int) const;
	float Length2() const;
	float LengthApprox() const;
	zVEC4& Normalize();
	zVEC4& Apply(float (*)(float));
};


inline float& zVEC4::operator[](int index)
{
	return n[index];
}


inline const float& zVEC4::operator[](int index) const
{
	return n[index];
}


inline float zVEC4::Length2() const
{
	return n[0] * n[0] + n[1] * n[1] + n[2] * n[2] + n[3] * n[3];
}


BOOL operator==(zVEC4 const&, zVEC4 const&);

zVEC4 operator*(zVEC4 const&, float);

float operator*(zVEC4 const&, zVEC4 const&);

zVEC4 operator+(zVEC4 const&, zVEC4 const&);

zVEC4 operator-(zVEC4 const&, zVEC4 const&);

zVEC4 operator-(zVEC4 const&);


inline float operator*(zVEC4 const& va, zVEC4 const& vb)
{
	return va[0] * vb[0] + va[1] * vb[1] + va[2] * vb[2]  + va[3] * vb[3];
}


class zMAT3					
{

	zVEC3		row[3];

public:
	zMAT3() {};
	zMAT3(zVEC3 const&, zVEC3 const&, zVEC3 const&);
	zMAT3(float);
	zMAT3& operator+=(zMAT3 const&);
	zMAT3& operator-=(zMAT3 const&);
	zMAT3& operator*=(float);
	zMAT3& operator/=(float);
	zVEC3& operator[](int);
	const zVEC3& operator[](int) const;
	zMAT3 Transpose() const;
	zMAT3 Inverse(float*);
	void SetAtVector(zVEC3 const&);
	zVEC3 GetAtVector() const;
	void SetUpVector(zVEC3 const&);
	zVEC3 GetUpVector() const;
	void SetRightVector(zVEC3 const&);
	zVEC3 GetRightVector() const;
	void MakeOrthonormal();
	zMAT3& Apply(float (*)(float));
};


inline zVEC3& zMAT3::operator[](int index)
{
	return row[index];
}


inline const zVEC3& zMAT3::operator[](int index) const
{
	return row[index];
}


zMAT3 operator-(zMAT3 const&);

zMAT3 operator+(zMAT3 const&, zMAT3 const&);

zMAT3 operator-(zMAT3 const&, zMAT3 const&);

zMAT3 operator*(zMAT3 const&, zMAT3 const&);

zVEC3 operator*(zMAT3 const&, zVEC3 const&);

zVEC2 operator*(zMAT3 const&, zVEC2 const&);

zMAT3 operator*(zMAT3 const&, float);

zMAT3 operator*(float, zMAT3 const&);

zMAT3 operator/(zMAT3 const&, float);

BOOL operator==(zMAT3 const&, zMAT3 const&);

BOOL operator!=(zMAT3 const&, zMAT3 const&);



class zMAT4				
{
public:
	zVEC4		row[4];
	
public:
	zMAT4() {};
	zMAT4(zVEC4 const&, zVEC4 const&, zVEC4 const&, zVEC4 const&);
	zMAT4(float);
	zMAT4& operator+=(zMAT4 const&);
	zMAT4& operator-=(zMAT4 const&);
	zMAT4& operator*=(float);
	zMAT4& operator/=(float);
	zVEC4& operator[](int);
	const zVEC4& operator[](int) const;
	zMAT4 Transpose() const;
	zMAT4 Inverse() const;
	zMAT4 InverseLinTrafo() const;
	zMAT4& Translate(zVEC3 const&);
	zMAT4& SetTranslation(zVEC3 const&);
	zVEC3 GetTranslation() const;
	void GetTranslation(zVEC3&) const;
	void SetAtVector(zVEC3 const&);
	zVEC3 GetAtVector() const;
	void SetUpVector(zVEC3 const&);
	zVEC3 GetUpVector() const;
	void SetRightVector(zVEC3 const&);
	zVEC3 GetRightVector() const;
	zVEC3 ExtractScaling() const;
	zMAT3 ExtractRotation();
	void MakeOrthonormal();
	zVEC3 Rotate(zVEC3 const&) const;
	void PostRotateX(float);
	void PostRotateY(float);
	void PostRotateZ(float);
	void PostScale(zVEC3 const&);
	void PreScale(zVEC3 const&);
	zVEC3 GetEulerAngles() const;
	void SetByEulerAngles(zVEC3);
	BOOL IsUpper3x3Orthonormal() const;
	zMAT4& Apply(float (*)(float));
	void LookAt(zVEC3);
};


inline zVEC4& zMAT4::operator[](int index)
{
	return row[index];
}


inline const zVEC4& zMAT4::operator[](int index) const
{
	return row[index];
}


zMAT4 operator-(zMAT4 const&);

zMAT4 operator+(zMAT4 const&, zMAT4 const&);

zMAT4 operator-(zMAT4 const&, zMAT4 const&);

zMAT4 operator*(zMAT4 const&, zMAT4 const&);

zVEC3 operator*(zMAT4 const&, zVEC3 const&);

zMAT4 operator*(zMAT4 const&, float);

zMAT4 operator*(float, zMAT4 const&);

zMAT4 operator/(zMAT4 const&, float);

BOOL operator==(zMAT4 const&, zMAT4 const&);

BOOL operator!=(zMAT4 const&, zMAT4 const&);


class zCQuat			
{
	zVEC4		qt;
public:
	zCQuat() {};
	float& operator[](int);
	const float& operator[](int) const;
	void Unit();
	void QuatToMatrix3(zMAT3&) const;
	void QuatToMatrix4(zMAT4&) const;
	void Matrix3ToQuat(zMAT3 const&);
	void Matrix4ToQuat(zMAT4 const&);
	void QuatToEuler(zVEC3&) const;
	void EulerToQuat(zVEC3 const&);
	void QuatToAxisAngle(zVEC3&, float&) const;
	void QuatToAngAxis(zVEC3&, float&) const;
    void Slerp(float, zCQuat const&, zCQuat const&);
	void Lerp(float, zCQuat const&, zCQuat const&);
	void Squad(float, zCQuat const&, zCQuat const&, zCQuat const&, zCQuat const&);
};


inline const float& zCQuat::operator [](int nIndex) const
{
	return qt[nIndex];
}


inline float& zCQuat::operator [](int nIndex)
{
	return qt[nIndex];
}

 
inline zMAT4 Alg_Identity3D(void)
{
	XCALL(0x00517B50);
};



static float Alg_AngleUnitRad(const zVEC3& va, const zVEC3& vb)
{
	float c = va * vb;
	if(c > 1.0)
		return 0;
	if(c < -1.0)
		return (float)PI;
	return acos(c);
}



static float Alg_AngleUnit(const zVEC3& va, const zVEC3& vb)
{
	return (float)(Alg_AngleUnitRad(va, vb) * DEGREE);
}


static float Alg_AngleRad(const zVEC3& va, const zVEC3& vb)
{
	zVEC3 va2 = va;
	va2.NormalizeSafe();
	zVEC3 vb2 = vb;
	vb2.NormalizeSafe();
	return (float)Alg_AngleUnitRad(va2, vb2);
}


static float Alg_Angle(const zVEC3& va, const zVEC3& vb)
{
	return (float)(Alg_AngleRad(va, vb) * DEGREE);
}

#include "zmath.inl"

#define sqr(v) (v*v)

class zVec2D				
{
public:

	float coord[2];


	operator zVEC2& ()
	{
		return *reinterpret_cast<zVEC2*>(this);
	}

	zVec2D () {
		coord[0] = 0.0f;
		coord[1] = 0.0f;
	};

	zVec2D (const zVec2D& v) {
		coord[0] = v[0];
		coord[1] = v[1];
	};

	zVec2D (const float& f) {
		coord[0] = f;
		coord[1] = f;
	};

	zVec2D (const float& x, const float& y) {
		coord[0] = x;
		coord[1] = y;
	};

	zREAL& operator [] (int i) {
		return coord[i];
	};

	const zREAL& operator [] (int i) const {
		return coord[i];
	};

	// ---------------------------------------------;

	zVec2D operator + (const zVec2D& v) const {
		return zVec2D(coord[0] + v.coord[0], coord[1] + v.coord[1]);
	};

	zVec2D operator - (const zVec2D& v) const {
		return zVec2D(coord[0] - v.coord[0], coord[1] - v.coord[1]);
	};

	zVec2D operator * (const zVec2D& v) const {
		return zVec2D(coord[0] * v.coord[0], coord[1] * v.coord[1]);
	};

	zVec2D operator / (const zVec2D& v) const {
		return zVec2D(coord[0] / v.coord[0], coord[1] / v.coord[1]);
	};

	// ---------------------------------------------;

	zVec2D operator + (const float& v) const {
		return zVec2D(coord[0] + v, coord[1] + v);
	};

	zVec2D operator - (const float& v) const {
		return zVec2D(coord[0] - v, coord[1] - v);
	};

	zVec2D operator * (const float& v) const {
		return zVec2D(coord[0] * v, coord[1] * v);
	};

	zVec2D operator / (const float& v) const {
		return zVec2D(coord[0] / v, coord[1] / v);
	};

	// ---------------------------------------------;

	zVec2D& operator += (const zVec2D& v) {
		 coord[0] += v.coord[0]; 
		 coord[1] += v.coord[1];
		 return *this;
	};

	zVec2D& operator -= (const zVec2D& v) {
		 coord[0] -= v.coord[0]; 
		 coord[1] -= v.coord[1];
		 return *this;
	};

	zVec2D& operator *= (const zVec2D& v) {
		 coord[0] *= v.coord[0]; 
		 coord[1] *= v.coord[1];
		 return *this;
	};

	zVec2D& operator /= (const zVec2D& v) {
		 coord[0] /= v.coord[0]; 
		 coord[1] /= v.coord[1];
		 return *this;
	};

	zVec2D SafeDiv (const zVec2D& v) {
		return zVec2D (	::SafeDiv (coord[0], v.coord[0]),
						::SafeDiv (coord[1], v.coord[1]));

	}

	// ---------------------------------------------;

	zVec2D& operator += (const float& v) {
		 coord[0] += v; 
		 coord[1] += v;
		 return *this;
	};

	zVec2D& operator -= (const float& v) {
		 coord[0] -= v; 
		 coord[1] -= v;
		 return *this;
	};

	zVec2D& operator *= (const float& v) {
		 coord[0] *= v; 
		 coord[1] *= v;
		 return *this;
	};

	zVec2D& operator /= (const float& v) {
		 coord[0] /= v; 
		 coord[1] /= v;
		 return *this;
	};

	// ---------------------------------------------;

	zBOOL operator == (const zVec2D& v) {
		return (coord[0] == v[0] && coord[1] == v[1]);
	};

	zBOOL operator != (const zVec2D& v) {
		return (coord[0] != v[0] || coord[1] != v[1]);
	};

	// ---------------------------------------------;

	zREAL Length ()	{
		return sqrtf ( sqr(coord[0]) + sqr(coord[1]) );
	};

	zREAL Length_sqr ()	{
		return sqr(coord[0]) + sqr(coord[1]);
	};

	zVec2D& Normalize () {
		return *this /= Length();
	};

	zVec2D& NormalizeSafe () {
		float len = Length();
		return len ? *this /= Length() : *this = 0.0f;
	};

	zSTRING ToString () {
		return zSTRING(coord[0], 8) + " " + zSTRING(coord[1], 8);
	};

	zVec2D& SetByString (const zSTRING& str) {
		coord[0] = str.PickWord (1, "", " ").ToFloat();
		coord[1] = str.PickWord (2, "", " ").ToFloat();
	};

	zREAL Distance (const zVec2D& v) {
		return (v - *this).Length();
	};

	zREAL DistanceAbs (const zVec2D& v) {
		return abs(Distance(v));
	};

	// ---------------------------------------------;

	float		ANGLE (int bCCS_correct = 1);
	zVec2D		ROTATE(float ang);
	
	float	GetAngleXY	();
	zVec2D& RotateXY	(const float& rad);
	zVec2D& InclineX	(const float& rad);
	zVec2D& InclineY	(const float& rad);
};

inline float zVec2D::ANGLE(int bCCS_correct)
{
	float ang = atan(::SafeDiv(coord[0], coord[1]));	//  1˙ ÷ĺňâĺđňü (áŕçîâŕ˙)

	if(bCCS_correct == 1)	// Ďîďđŕâęŕ íŕ äĺęŕđň
	{
		if(coord[0] >= 0.0f && coord[1] <= 0.0f)		//  2˙ ÷ĺňâĺđňü
			ang = RAD90  + (RAD90 + ang);
		else if(coord[0] <= 0.0f && coord[1] <= 0.0f)	//  3˙ ÷ĺňâĺđňü
			ang = RAD180 + ang;
		else if(coord[0] <= 0.0f && coord[1] >= 0.0f)	//  4˙ ÷ĺňâĺđňü
			ang = RAD270 + (RAD90 + ang);
	}
		
	if(bCCS_correct == 2)	// Ďîďđŕâęŕ íŕ äĺęŕđň
	{
		if(coord[0] >= 0.0f && coord[1] <= 0.0f)		//  2˙ ÷ĺňâĺđňü
			ang = RAD90  + (RAD90 + ang);
		else if(coord[0] <= 0.0f && coord[1] <= 0.0f)	//  3˙ ÷ĺňâĺđňü
			ang = RAD180 - (RAD90 - ang);
		else if(coord[0] <= 0.0f && coord[1] >= 0.0f)	//  4˙ ÷ĺňâĺđňü
			ang = RAD90 - ang;
	}
		
	return ang;
}

inline zVec2D zVec2D::ROTATE(float ang)
{
	zVec2D vec2 = zVec2D(coord[0], coord[1]);				// Ďîëó÷ŕĺě äĺęŕđňîâóţ ěîäĺëü ďîâîđŕ÷čâŕĺěîé ďëîńęîńňč
	float fLength = vec2.Length();							// Ďîëó÷ŕĺě äëčíó âĺęňîđŕ

	if(fLength < 0.00001f && fLength > -0.00001f)			// Îńňŕíŕâëčâŕĺě ĺńëč âĺęňîđ íóëĺâîé
		return vec2;

	vec2.Normalize();										// Íîđěŕëčçóĺě âĺęňîđ
	float fang = ANGLE(1) + ::SafeDiv(ang, (float)DEGREE);	// Ďîëó÷ŕĺě ńóěěŕđíűé óăîë
	zVec2D vang = zVec2D(sin(fang), cos(fang));				// Ďîëó÷ŕĺě íîâűé íîđěŕëčçîâŕííűé âĺęňîđ
	vang *= fLength;										// Ďđčâîäčě äëčíó
	return vang;
}

class zCOLOR;
class CLine
{
public:

	zVec2D coord[2];
	void Draw(zCOLOR);

	CLine(){};
	CLine(zVec2D,zVec2D);
	CLine(int,int,int,int);

	zVec2D&	operator []		(int i);			// Ďîëó÷ĺíčĺ óęŕçŕňĺë˙ íŕ ęîîđäčíŕňó
	BOOL	TraceRay		(CLine&, zVec2D&, float);	// Ďîëó÷ĺíčĺ ňî÷ęč ďĺđĺńĺ÷ĺíč˙ âĺęňîđîâ
	zVec2D	GetVector		();
	zVec2D	GetPos			();
	CLine&	Rotate			(zVec2D pivot, float ang);
	CLine&	InvertVector	();
	CLine&	operator *=		(float);

};


inline CLine::CLine(zVec2D aa, zVec2D ab)
{
	coord[0] = aa;
	coord[1] = ab;
}

inline CLine::CLine(int aa, int ab, int ac, int ad)
{
	coord[0] = zVec2D(aa,ab);
	coord[1] = zVec2D(ac,ad);
}

inline zVec2D& CLine::operator[](int i)
{
	if(i > 1)
		i = 1;
	else if(i < 0)
		i = 0;
	return coord[i];
}

inline zVec2D CLine::GetVector()
{
	return coord[1] - coord[0];
}

inline zVec2D CLine::GetPos()
{
	return coord[0];
}

inline CLine& CLine::Rotate(zVec2D pivot, float ang)
{
	zVec2D v1 = coord[0] - pivot;
	zVec2D v2 = coord[1] - pivot;

	coord[0] = pivot + v1.RotateXY(ang);
	coord[1] = pivot + v2.RotateXY(ang);

	return *this;
}

inline CLine& CLine::InvertVector ()
{
	zVec2D vector = GetVector();
	coord [1]	  = coord [0] - vector;
	return *this;
}

inline CLine& CLine::operator *= (float mul)
{
	zVec2D vector = (GetVector() *= mul);
	coord[1] = coord[0] + vector;
	return *this;
}







class zVec3D				
{

	float coord[3];

public:

	operator zVEC3& ()
	{
		return *reinterpret_cast<zVEC3*>(this);
	}

	zVec3D () {
		coord[0] = 0.0f;
		coord[1] = 0.0f;
		coord[2] = 0.0f;
	};

	zVec3D (const zVec3D& v) {
		coord[0] = v[0];
		coord[1] = v[1];
		coord[2] = v[2];
	};

	zVec3D (const float& f) {
		coord[0] = f;
		coord[1] = f;
		coord[2] = f;
	};

	zVec3D (const float& x, const float& y, const float& z) {
		coord[0] = x;
		coord[1] = y;
		coord[2] = z;
	};

	zREAL& operator [] (int i) {
		return coord[i];
	};

	const zREAL& operator [] (int i) const {
		return coord[i];
	};

	// ---------------------------------------------;

	zVec3D operator + (const zVec3D& v) const {
		return zVec3D(
			coord[0] + v.coord[0], 
			coord[1] + v.coord[1],
			coord[2] + v.coord[2]);
	};

	zVec3D operator - (const zVec3D& v) const {
		return zVec3D(
			coord[0] - v.coord[0], 
			coord[1] - v.coord[1],
			coord[2] - v.coord[2]);
	};

	zVec3D operator * (const zVec3D& v) const {
		return zVec3D(
			coord[0] * v.coord[0], 
			coord[1] * v.coord[1],
			coord[2] * v.coord[2]);
	};

	zVec3D operator / (const zVec3D& v) const {
		return zVec3D(
			coord[0] / v.coord[0], 
			coord[1] / v.coord[1],
			coord[2] / v.coord[2]);
	};

	// ---------------------------------------------;

	zVec3D operator + (const float& v) const {
		return zVec3D(
			coord[0] + v, 
			coord[1] + v,
			coord[2] + v);
	};

	zVec3D operator - (const float& v) const {
		return zVec3D(
			coord[0] - v, 
			coord[1] - v,
			coord[2] - v);
	};

	zVec3D operator * (const float& v) const {
		return zVec3D(
			coord[0] * v,
			coord[1] * v,
			coord[2] * v);
	};

	zVec3D operator / (const float& v) const {
		return zVec3D(
			coord[0] / v, 
			coord[1] / v,
			coord[2] / v);
	};

	// ---------------------------------------------;

	zVec3D& operator += (const zVec3D& v) {
		 coord[0] += v.coord[0]; 
		 coord[1] += v.coord[1];
		 coord[2] += v.coord[2];
		 return *this;
	};

	zVec3D& operator -= (const zVec3D& v) {
		 coord[0] -= v.coord[0]; 
		 coord[1] -= v.coord[1];
		 coord[2] -= v.coord[2];
		 return *this;
	};

	zVec3D& operator *= (const zVec3D& v) {
		 coord[0] *= v.coord[0]; 
		 coord[1] *= v.coord[1];
		 coord[2] *= v.coord[2];
		 return *this;
	};

	zVec3D& operator /= (const zVec3D& v) {
		 coord[0] /= v.coord[0]; 
		 coord[1] /= v.coord[1];
		 coord[2] /= v.coord[2];
		 return *this;
	};

	// ---------------------------------------------;

	zVec3D& operator += (const float& v) {
		 coord[0] += v; 
		 coord[1] += v;
		 coord[2] += v;
		 return *this;
	};

	zVec3D& operator -= (const float& v) {
		 coord[0] -= v; 
		 coord[1] -= v;
		 coord[2] -= v;
		 return *this;
	};

	zVec3D& operator *= (const float& v) {
		 coord[0] *= v; 
		 coord[1] *= v;
		 coord[2] *= v;
		 return *this;
	};

	zVec3D& operator /= (const float& v) {
		 coord[0] /= v; 
		 coord[1] /= v;
		 coord[2] /= v;
		 return *this;
	};

	// ---------------------------------------------;

	zBOOL operator == (const zVec3D& v) {
		return (
			coord[0] == v[0] && 
			coord[1] == v[1] && 
			coord[2] == v[2]);
	};

	zBOOL operator != (const zVec3D& v) {
		return (
			coord[0] != v[0] || 
			coord[1] != v[1] || 
			coord[2] != v[2]);
	};

	// ---------------------------------------------;

	zREAL Length ()	{
		return sqrtf ( sqr(coord[0]) + sqr(coord[1]) + sqr(coord[2]));
	};

	zREAL Length_sqr ()	{
		return sqr(coord[0]) + sqr(coord[1]) + sqr(coord[2]);
	};

	zVec3D& Normalize () {
		return *this /= Length();
	};

	zVec3D& NormalizeSafe () {
		float len = Length();
		return len ? *this /= Length() : *this = 0.0f;
	};

	zSTRING ToString () {
		return 
			zSTRING(coord[0], 8) + " " + 
			zSTRING(coord[1], 8) + " " + 
			zSTRING(coord[2], 8);
	};

	zVec3D& SetByString (const zSTRING& str) {
		coord[0] = str.PickWord (1, "", " ").ToFloat();
		coord[1] = str.PickWord (2, "", " ").ToFloat();
		coord[2] = str.PickWord (3, "", " ").ToFloat();
	};

	zREAL Distance (const zVec3D& v) {
		return (v - *this).Length();
	};

	zREAL DistanceAbs (const zVec3D& v) {
		return abs(Distance(v));
	};

	zVec3D& Apply(float (*func)(float));
};

static zVec3D operator - (zVec3D& vec)
{
	return zVec3D (-vec[0], -vec[1], -vec[2]);
}






class zVec4D					
{

	float coord[4];

public:

	operator zVEC4& ()
	{
		return *reinterpret_cast<zVEC4*>(this);
	}

	zVec4D () {
		coord[0] = 0.0f;
		coord[1] = 0.0f;
		coord[2] = 0.0f;
		coord[3] = 0.0f;
	};

	zVec4D (const zVec4D& v) {
		coord[0] = v[0];
		coord[1] = v[1];
		coord[2] = v[2];
		coord[3] = v[3];
	};

	zVec4D (const float& f) {
		coord[0] = f;
		coord[1] = f;
		coord[2] = f;
		coord[3] = f;
	};

	zVec4D (const float& x, const float& y, const float& z, const float& a) {
		coord[0] = x;
		coord[1] = y;
		coord[2] = z;
		coord[3] = a;
	};

	zREAL& operator [] (int i) {
		return coord[i];
	};

	const zREAL& operator [] (int i) const {
		return coord[i];
	};

	// ---------------------------------------------;

	zVec4D operator + (const zVec4D& v) const {
		return zVec4D(
			coord[0] + v.coord[0], 
			coord[1] + v.coord[1],
			coord[2] + v.coord[2],
			coord[3] + v.coord[3]);
	};

	zVec4D operator - (const zVec4D& v) const {
		return zVec4D(
			coord[0] - v.coord[0], 
			coord[1] - v.coord[1],
			coord[2] - v.coord[2],
			coord[3] - v.coord[3]);
	};

	zVec4D operator * (const zVec4D& v) const {
		return zVec4D(
			coord[0] * v.coord[0], 
			coord[1] * v.coord[1],
			coord[2] * v.coord[2],
			coord[3] * v.coord[3]);
	};

	zVec4D operator / (const zVec4D& v) const {
		return zVec4D(
			coord[0] / v.coord[0], 
			coord[1] / v.coord[1],
			coord[2] / v.coord[2],
			coord[3] / v.coord[3]);
	};

	// ---------------------------------------------;

	zVec4D operator + (const float& v) const {
		return zVec4D(
			coord[0] + v, 
			coord[1] + v,
			coord[2] + v,
			coord[3] + v);
	};

	zVec4D operator - (const float& v) const {
		return zVec4D(
			coord[0] - v, 
			coord[1] - v,
			coord[2] - v,
			coord[3] - v);
	};

	zVec4D operator * (const float& v) const {
		return zVec4D(
			coord[0] * v,
			coord[1] * v,
			coord[2] * v,
			coord[3] * v);
	};

	zVec4D operator / (const float& v) const {
		return zVec4D(
			coord[0] / v, 
			coord[1] / v,
			coord[2] / v,
			coord[3] / v);
	};

	// ---------------------------------------------;

	zVec4D& operator += (const zVec4D& v) {
		 coord[0] += v.coord[0]; 
		 coord[1] += v.coord[1];
		 coord[2] += v.coord[2];
		 coord[3] += v.coord[3];
		 return *this;
	};

	zVec4D& operator -= (const zVec4D& v) {
		 coord[0] -= v.coord[0]; 
		 coord[1] -= v.coord[1];
		 coord[2] -= v.coord[2];
		 coord[3] -= v.coord[3];
		 return *this;
	};

	zVec4D& operator *= (const zVec4D& v) {
		 coord[0] *= v.coord[0]; 
		 coord[1] *= v.coord[1];
		 coord[2] *= v.coord[2];
		 coord[3] *= v.coord[3];
		 return *this;
	};

	zVec4D& operator /= (const zVec4D& v) {
		 coord[0] /= v.coord[0]; 
		 coord[1] /= v.coord[1];
		 coord[2] /= v.coord[2];
		 coord[3] /= v.coord[3];
		 return *this;
	};

	// ---------------------------------------------;

	zVec4D& operator += (const float& v) {
		 coord[0] += v; 
		 coord[1] += v;
		 coord[2] += v;
		 coord[3] += v;
		 return *this;
	};

	zVec4D& operator -= (const float& v) {
		 coord[0] -= v; 
		 coord[1] -= v;
		 coord[2] -= v;
		 coord[3] -= v;
		 return *this;
	};

	zVec4D& operator *= (const float& v) {
		 coord[0] *= v; 
		 coord[1] *= v;
		 coord[2] *= v;
		 coord[3] *= v;
		 return *this;
	};

	zVec4D& operator /= (const float& v) {
		 coord[0] /= v; 
		 coord[1] /= v;
		 coord[2] /= v;
		 coord[3] /= v;
		 return *this;
	};

	// ---------------------------------------------;

	zBOOL operator == (const zVec4D& v) {
		return (
			coord[0] == v[0] && 
			coord[1] == v[1] && 
			coord[2] == v[2] &&
			coord[3] == v[3]);
	};

	zBOOL operator != (const zVec4D& v) {
		return (
			coord[0] != v[0] || 
			coord[1] != v[1] || 
			coord[2] != v[2] ||
			coord[3] != v[3]);
	};

	// ---------------------------------------------;

	zREAL Length ()	{
		return sqrtf ( sqr(coord[0]) + sqr(coord[1]) + sqr(coord[2]) + sqr(coord[3]));
	};

	zREAL Length_sqr ()	{
		return sqr(coord[0]) + sqr(coord[1]) + sqr(coord[2]) + sqr(coord[3]);
	};

	zVec4D& Normalize () {
		return *this /= Length();
	};

	zVec4D& NormalizeSafe () {
		float len = Length();
		return len ? *this /= Length() : *this = 0.0f;
	};

	zSTRING ToString () {
		return 
			zSTRING(coord[0], 8) + " " + 
			zSTRING(coord[1], 8) + " " + 
			zSTRING(coord[2], 8) + " " + 
			zSTRING(coord[3], 8);
	};

	zVec4D& SetByString (const zSTRING& str) {
		coord[0] = str.PickWord (1, "", " ").ToFloat();
		coord[1] = str.PickWord (2, "", " ").ToFloat();
		coord[2] = str.PickWord (3, "", " ").ToFloat();
		coord[3] = str.PickWord (4, "", " ").ToFloat();
	};

	zREAL Distance (const zVec4D& v) {
		return (v - *this).Length();
	};

	zREAL Distance_abs (const zVec4D& v) {
		return abs(Distance(v));
	};
};


INLINE zVEC2::operator zVec2D & ()
{
	return *reinterpret_cast<zVec2D*>(this);
}

INLINE zVEC3::operator zVec3D & ()
{
	return *reinterpret_cast<zVec3D*>(this);
}

INLINE zVEC4::operator zVec4D & ()
{
	return *reinterpret_cast<zVec4D*>(this);
}


// test again))
#define CALCANGLE(a,b)						\
	float angle = atan (::SafeDiv(a, b));	\
	if (a >= 0 && b < 0)					\
	angle = 180.0f / DEGREE + angle;		\
	else if (a <= 0 && b < 0)				\
	angle = 180.0f / DEGREE + angle;		\
	else if (a <= 0 && b > 0)				\
	angle = 360.0f / DEGREE + angle;		\
	return angle;


#define ROTANGLE(a,b,c)							\
	float radAngle	 = GetAngle##c();			\
	float length	 = sqrt(sqr(a) + sqr(b));	\
	if (length == 0.0000f) return *this;		\
	radAngle		+= rad;						\
	a				 = sinf(radAngle) * length;	\
	b				 = cosf(radAngle) * length;	\
	return *this;

#define INCLINEX(a,b,c)							\
	float radAngle	 = GetAngle##c();			\
	float length	 = sqrt(sqr(a) + sqr(b));	\
	if (length == 0.0000f) return *this;		\
	radAngle		+= rad;						\
	a				 = sinf(radAngle) * length;	\
	return *this;

#define INCLINEY(a,b,c)							\
	float radAngle	 = GetAngle##c();			\
	float length	 = sqrt(sqr(a) + sqr(b));	\
	if (length == 0.0000f) return *this;		\
	radAngle		+= rad;						\
	b				 = cosf(radAngle) * length;	\
	return *this;


// -------------------------------------- 

inline float zVEC3::GetAngleXZ ()
{
	CALCANGLE(n[0], n[2]);
}

inline float zVEC3::GetAngleXY ()
{
	CALCANGLE(n[0], n[1]);
}

inline float zVEC3::GetAngleYZ ()
{
	CALCANGLE(n[1], n[2]);
};

// --------------------------------------

inline zVEC3& zVEC3::RotateXZ (const float& rad)
{
	ROTANGLE (n[0], n[2], XZ);
};

inline zVEC3& zVEC3::RotateXY (const float& rad)
{
	ROTANGLE (n[0], n[1], XY);
};

inline zVEC3& zVEC3::RotateYZ (const float& rad)
{
	ROTANGLE (n[1], n[2], YZ);
};







inline float zVec2D::GetAngleXY ()
{
	CALCANGLE(coord[0], coord[1]);
}

inline zVec2D& zVec2D::RotateXY (const float& rad)
{
	ROTANGLE(coord[0], coord[1], XY);
}


inline zVec2D& zVec2D::InclineX (const float& rad)
{
	INCLINEX(coord[0], coord[1], XY);
}

inline zVec2D& zVec2D::InclineY (const float& rad)
{
	INCLINEY(coord[0], coord[1], XY);
}


inline BOOL CLine::TraceRay(CLine& vline, zVec2D& intersec, float dim)
{
	float angle = this->GetVector().GetAngleXY();

	CLine line1 = CLine(*this).Rotate(coord[0]+1, -angle);
	CLine line2 = CLine(vline).Rotate(coord[0]+1, -angle);

	float line_width = line1[1][1] - line1[0][1];
	float mat_width  = line2[0][1] - line1[0][1];
	float multiplier = 1.0f / line_width * mat_width;
	intersec = coord[0] + GetVector() * multiplier;

	zVec2D vmin (
			vline[0][0] < vline[1][0] ? vline[0][0]-dim : vline[1][0]-dim,
			vline[0][1] < vline[1][1] ? vline[0][1]-dim : vline[1][1]-dim);

	zVec2D vmax (
			vline[0][0] >= vline[1][0] ? vline[0][0]+dim : vline[1][0]+dim,
			vline[0][1] >= vline[1][1] ? vline[0][1]+dim : vline[1][1]+dim);

	return 
		intersec[0] >= vmin[0] && intersec[0] <= vmax[0] &&
		intersec[1] >= vmin[1] && intersec[1] <= vmax[1];
}