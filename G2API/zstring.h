#pragma once

#include <limits.h>
#include <string>

class zSTRING;

enum zEnumStringAlign
{
	zTSTR_ALIGN_END,
	zTSTR_ALIGN_MID,
	zTSTR_ALIGN_HOME
};
enum zTSTR_KIND
{
	zDELETE_TOKEN,
	zDELETE_PREV,
	zDELETE_NEXT,
	zDELETE_PREV_INCLUDE,
	zDELETE_NEXT_INCLUDE
};




class zSTRING
{
public:
	int _vtbl;
	int _allocater;
	int ptr;
	int len;
	int res;

	zSTRING Substr(unsigned int pos, unsigned long ) const;
	zSTRING& operator+=(zSTRING const&);
	operator LPCTSTR() const;
	int Compare(LPCTSTR) const;
	int Compare(zSTRING&);
	wchar_t* toWChar()const ;
	char &operator[](unsigned int);
public:
	
	int Delete(zSTRING const &, zTSTR_KIND)
	{
		XCALL(0x0046BCF0);
	};
	
	void TrimLeft(char)
	{
		XCALL(0x0046C630);
	};
	
	void TrimRight(char)
	{
		XCALL(0x0046C770);
	};
	
	zSTRING Inserted(unsigned int,zSTRING const &)const 
	{
		XCALL(0x0046B520);
	};
	
	zSTRING PickWord(unsigned int, zSTRING const &, zSTRING const &)const
	{
		XCALL(0x0046AF80);
	};
	
	zSTRING(double, int)
	{
		XCALL(0x00454680);
	};
	
	zSTRING()
	{
		XCALL(0x00402AF0);
	};
	
	zSTRING(const char* lpStr)
	{
		XCALL(0x004010C0);
	};
	
	zSTRING(zSTRING & zstr)
	{
		XCALL(0x00416500);
	};
	
	zSTRING(const zSTRING* zstr)
	{
		XCALL(0x007928D0);
	};
	
	
	zSTRING(float f, int precision)
	{
		XCALL(0x00435970);
	};
	zSTRING(int str)
	{
		XCALL(0x00435870);
	};
	
	zSTRING(char str)
	{
		XCALL(0x0051AC80);
	};
	
	zSTRING & operator=(LPCSTR p1)
	{
		XCALL(0x004CFAF0);
	};
	
	zSTRING & operator=(const zSTRING & p1)
	{
		XCALL(0x0059CEB0);
	};
	
	zSTRING & Align(zEnumStringAlign nAlighMode, int nNewLength, TCHAR ch)
	{
		XCALL(0x0046AD60);
	};
	
	zSTRING & operator+=(char const * str)
	{
		XCALL(0x0067A7B0);
	};
	
	
	void Clear(void)
	{
		XCALL(0x0059D010);
	};
	
	void Delete(unsigned int pos1, unsigned long pos2)
	{
		XCALL(0x0046BAA0);	
	};
	
	void DeleteRight(unsigned int pos)
	{
		XCALL(0x0046B990);
	};
	
	int Insert(unsigned int pos, const zSTRING & p2)
	{
		XCALL(0x0046B400);
	};
	
	bool IsEmpty(void)
	{
		XCALL(0x00674210)	
	};
	
	int Length(void)const
	{
		XCALL(0x0059D0E0)
	};
	
	zSTRING & Lower(void)
	{
		XCALL(0x0046A9F0)
	};
	
	int Overwrite(unsigned int pos, const zSTRING & p2)
	{
		XCALL(0x0046B6A0);
	};
	
	int Search(char const * p1, unsigned int p2 = 1)
	{
		XCALL(0x0059D110);
	};
	
	int Search(class zSTRING const & p1, unsigned int p2 = 1)
	{
		XCALL(0x00492680);
	};
	
	zSTRING Copied(unsigned int, unsigned long)const
	{
		XCALL(0x0046C170);
	};
	
	int Search(int, char const *, unsigned int)const
	{
		XCALL(0x0046C920);
	};
	
	int SearchRev(class zSTRING const & p1, unsigned int p2)
	{
		XCALL(0x0046CA20);	
	};
	
	zSTRING & Upper(void)
	{
		XCALL(0x0046AB00);	
	};
	
	zSTRING & UpperFirstLowerRest(void)
	{
		XCALL(0x0046AC10);
	};
	
	char* ToChar(void)const 
	{
		XCALL(0x004639D0);
	};
	
	float ToFloat(void)
	{
		XCALL(0x004936C0);
	};
	
	long ToInt(void)
	{
		XCALL(0x0059D0F0);
	};
	
	zSTRING & Append(zSTRING & str)
	{
		Insert(Length(), zSTRING(str));
		return *this;
	};
	
	char& GetChar(unsigned int)
	{
		XCALL(0x00445A20);
	};


};


inline zSTRING Spaces(int)
{
	XCALL(0x0046A980);
};

inline wchar_t* zSTRING::toWChar()const
{

	size_t newsize = Length();
    wchar_t * wcstring = new wchar_t[newsize];
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, wcstring, newsize,ToChar(), _TRUNCATE);
	return wcstring;
};

inline zSTRING zSTRING::Substr(unsigned int pos, unsigned long npos = -1) const
{
	std::string s = this->ToChar();
	std::string s1;
	s1 = s.substr(pos, npos);
	zSTRING tmp = s1.c_str();
	return tmp;
}

inline zSTRING::operator LPCTSTR() const
{
	return ToChar();
}


inline zSTRING& zSTRING::operator+=(zSTRING const& zstr)
{
	std::string s = this->ToChar();
	s += zstr.ToChar();
	return (*this);
}

inline BOOL operator==(zSTRING const &, char const * const)
{
	XCALL(0x006CFF50);
};
 
inline BOOL operator==( zSTRING const &, zSTRING const &)
{
	XCALL(0x00674220);
};

inline zSTRING operator+(zSTRING const &, zSTRING const &)
{
	XCALL(0x004045C0);
};

inline zSTRING operator+(char const *, zSTRING const &)
{
	XCALL(0x00404710);
};

inline zSTRING operator+(zSTRING const &, char const *)
{
	XCALL(0x00404880);
};

inline zSTRING operator+(zSTRING const &, char)
{
	XCALL(0x00445DD0);
};

inline zSTRING operator+(char, class zSTRING const &)
{
	XCALL(0x0044A190);
};

inline int zSTRING::Compare(zSTRING& other) 
{
	if(strcmp(this->ToChar(),other.ToChar()) == 0)
		return 0;
	else
		return 1;
}


inline int zSTRING::Compare(LPCTSTR lpsz) const
{
	std::string s = this->ToChar();
	return s.compare(lpsz);
}

inline char& zSTRING::operator[](unsigned int)
{
	XCALL(0x00445A20);
};

inline zSTRING Characters(char c, int num)
{
	XCALL(0x0046A8F0);
};