
class CString
{

	PCHAR	data;
	zUINT32	len;

public:

	ASTAPI operator zSTRING ();
	ASTAPI CString ();
	ASTAPI CString (const zSTRING&);
	ASTAPI CString (const CString&);
	ASTAPI CString (const CHAR&);
	ASTAPI CString (const CHAR*);
	ASTAPI CString (const zINT32&);
	ASTAPI CString (const zUINT32&);
	ASTAPI CString (const zREAL&, const zUINT32& = 3);
	ASTAPI CString (const zREAL64&, const zUINT32& = 5);
	ASTAPI BOOL Compare (const CString&);
	ASTAPI CString&	operator  = (const CString&);
	ASTAPI CString&	operator += (const CString&);
	ASTAPI CString	operator +  (const CString&);
	ASTAPI BOOL		operator == (const CString&);
	ASTAPI 		char& operator [] (const zINT32&);
	ASTAPI const char& operator [] (const zINT32&) const;
	ASTAPI operator const char* () const;
	ASTAPI BOOL		IsEmpty		();
	ASTAPI zINT32	Search		(const CString&, const zINT32& = 0, const BOOL& = FALSE);
	ASTAPI BOOL		HasWord		(const CString&);
	ASTAPI zUINT32	CountWords	(const CString&);
	ASTAPI CString	GetWord		(const CString&, const zINT32&);
	ASTAPI CString	GetPattern	(const CString&, const CString&, const zINT32&);
	ASTAPI static zUINT32		GetVectorLength (const char*);
	ASTAPI static CString	TransNotation	(const zINT32&, const zUINT32&);
	ASTAPI zUINT32	Length	() const;
	ASTAPI CString&	Reverse	();
	ASTAPI void		Clear	();
	ASTAPI CString	Copy	(const zUINT32&,  const zUINT32&);
	ASTAPI CString&	Cut		(const zUINT32&,  const zUINT32&);
	ASTAPI CString&	Put		(const CString&,  const zUINT32&);
	ASTAPI int		ToInt	();
	ASTAPI float		ToFloat	();
	ASTAPI double	ToDouble();
	ASTAPI CString&	Upper	();
	ASTAPI CString&	Lower	();
	ASTAPI ~CString ();
};

static CString operator + (char* c, CString s)
{
	return (CString)c + s;
}

static CString operator + (CString& s, const char* c)
{
	return s + (CString)c;
}

static CString operator + (CString& s1, const zSTRING& s2)
{
	return s1 + (CString)s2;
}

static CString operator + (CString& s, const char& c)
{
	return s + (CString)c;
}

static CString operator + (CString& s, const int& v)
{
	return s + (CString)v;
}

static CString operator + (CString& s, const unsigned int& v)
{
	return s + (CString)v;
}

static CString operator + (CString& s, const float& v)
{
	return s + (CString)v;
}

static CString operator + (CString& s, const double& v)
{
	return s + (CString)v;
}