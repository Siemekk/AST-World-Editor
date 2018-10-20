#pragma once

#include "ztypes.h"

class zFILE;



enum {	zPAR_TYPE_VOID,		zPAR_TYPE_FLOAT,		zPAR_TYPE_INT, 
		zPAR_TYPE_STRING,	zPAR_TYPE_CLASS,		zPAR_TYPE_FUNC,		
		zPAR_TYPE_PROTOTYPE,zPAR_TYPE_INSTANCE	};
		// Achtung : zPar_Type_Instance muss letzter Eintrag sein

enum {	zPAR_FLAG_CONST		= 1,zPAR_FLAG_RETURN = 2,	zPAR_FLAG_CLASSVAR=4,
		zPAR_FLAG_EXTERNAL	= 8,zPAR_FLAG_MERGED =16 };

// ******************************************************************************
// Operatoren ID's
// ******************************************************************************

enum { // * Operator Length = 1 *
		zPAR_OP_PLUS = 0,	zPAR_OP_MINUS = 1,		zPAR_OP_MUL		= 2,
		zPAR_OP_DIV	 = 3,	zPAR_OP_MOD	  = 4,		zPAR_OP_OR		= 5,	
		zPAR_OP_AND  = 6,	zPAR_OP_LOWER = 7,		zPAR_OP_HIGHER	= 8, 
		zPAR_OP_IS	 = 9,
		// * Operator Length = 2 *
		zPAR_OP_LOG_OR		= 11,		// "||"
		zPAR_OP_LOG_AND		= 12,		// "&&"
		zPAR_OP_SHIFTL		= 13,		// "<<"
		zPAR_OP_SHIFTR		= 14,		// ">>"
		zPAR_OP_LOWER_EQ	= 15,		// "<="
		zPAR_OP_EQUAL		= 16,		// "=="
		zPAR_OP_NOTEQUAL	= 17,		// "!="
		zPAR_OP_HIGHER_EQ	= 18,		// ">="
		zPAR_OP_ISPLUS		= 19,		// "+="
		zPAR_OP_ISMINUS		= 20,		// "-="
		zPAR_OP_ISMUL		= 21,		// "*="
		zPAR_OP_ISDIV		= 22,		// "/="
		// * Unary Operators *
		zPAR_OP_UNARY		= 30,		// ***************************
		zPAR_OP_UN_PLUS		= 30,		
		zPAR_OP_UN_MINUS	= 31,		
		zPAR_OP_UN_NOT		= 32,		// "!"
		zPAR_OP_UN_NEG		= 33,		// "~"
		zPAR_OP_MAX			= 33,			
		// * Weitere Tokens *
		zPAR_TOK_BRACKETON  = 40,
		zPAR_TOK_BRACKETOFF = 41,	
		zPAR_TOK_SEMIKOLON	= 42,
		zPAR_TOK_KOMMA		= 43,
		zPAR_TOK_SCHWEIF	= 44,
		zPAR_TOK_NONE		= 45,
		
		// * Weitere Tokens *
		zPAR_TOK_FLOAT		= 51,
		zPAR_TOK_VAR		= 52,			
		zPAR_TOK_OPERATOR	= 53,
		
		// * Befehls - Tokens *
		zPAR_TOK_RET		= 60,
		zPAR_TOK_CALL		= 61,
		zPAR_TOK_CALLEXTERN	= 62,
		zPAR_TOK_POPINT		= 63,
		zPAR_TOK_PUSHINT	= 64,
		zPAR_TOK_PUSHVAR	= 65,
		zPAR_TOK_PUSHSTR	= 66,
		zPAR_TOK_PUSHINST	= 67,
		zPAR_TOK_PUSHINDEX	= 68,
		zPAR_TOK_POPVAR		= 69,
		zPAR_TOK_ASSIGNSTR	= 70,
		zPAR_TOK_ASSIGNSTRP	= 71,
		zPAR_TOK_ASSIGNFUNC	= 72,
		zPAR_TOK_ASSIGNFLOAT= 73,
		zPAR_TOK_ASSIGNINST = 74,
		zPAR_TOK_JUMP		= 75,
		zPAR_TOK_JUMPF		= 76,
		
		zPAR_TOK_SETINSTANCE= 80,

		// * Parse - Tree - Tokens *
		zPAR_TOK_SKIP		= 90,
		zPAR_TOK_LABEL		= 91,
		zPAR_TOK_FUNC		= 92,
		zPAR_TOK_FUNCEND	= 93,
		zPAR_TOK_CLASS		= 94,
		zPAR_TOK_CLASSEND	= 95,
		zPAR_TOK_INSTANCE	= 96,
		zPAR_TOK_INSTANCEEND= 97,
		zPAR_TOK_NEWSTRING	= 98,

		// !!! Auf jeden Fall unter 128 halten !!!
		zPAR_TOK_FLAGARRAY	= zPAR_TOK_VAR + 128
};


class zCPar_StringTable
{
private :
	zCArray <zSTRING *> array;
public :
	
	zCPar_StringTable							(int nr = 0)	{XCALL(0x007A0EB0)};
	~zCPar_StringTable							()				{XCALL(0x007A0F50)};
	
	zSTRING*					Insert			(zSTRING &s)	{XCALL(0x007A1000)};
	zSTRING*					GetString		(int nr)		{XCALL(0x007A1160)};
	void						Save			(zSTRING &s)	{XCALL(0x007A1180)};
	void						Load			(zSTRING &s)	{XCALL(0x007A12A0)};
	void						Show			()				{XCALL(0x007A1500)};
	void						Clear			()				{XCALL(0x007A0FD0)};
	void						ShrinkToFit		()				{XCALL(0x007A1480)};
	int							GetLastEntry	()				{XCALL(0x007A1150)};
};

class zCPar_Symbol
{
public:
	static void SetUseInstance(zCPar_Symbol*)
	{
		XCALL(0x007A1550);
	};

	static void SetUseInstanceAdr(void*)
	{
		XCALL(0x007A1670);
	};

	static void* GetUseInstance(void)
	{
		XCALL(0x007A1680);
	};

	void zPar_Symbol(void)
	{
		XCALL(0x007A1690);
	};

	zCPar_Symbol(void)
	{
		zPar_Symbol();
	};

	~zCPar_Symbol(void)
	{
		XCALL(0x007A16F0);
	};

	void AllocSpace(void)
	{
		XCALL(0x007A17C0);
	};

	void* GetDataAdr(int)
	{
		XCALL(0x007A1A40);
	};

	void SetDataAdr(void*)
	{
		XCALL(0x007A1D40);
	};

	void SetFlag(int)
	{
		XCALL(0x007A1D50);
	};

	int HasFlag(int)
	{
		XCALL(0x007A1D80);
	};

	void SetParent(zCPar_Symbol*)
	{
		XCALL(0x007A1DA0);
	};

	zCPar_Symbol* GetParent(void)
	{
		XCALL(0x007A1DB0);
	};

	void* GetInstanceAdr(void)
	{
		XCALL(0x007A1DC0);
	};

	zCPar_Symbol* GetNext(void)
	{
		XCALL(0x007A1DD0);
	};

	int ArrayCheck(int)
	{
		XCALL(0x007A1DE0);
	};

	void GetStackPos(int&,int)
	{
		XCALL(0x007A1E10);
	};

	void SetStackPos(int,int)
	{
		XCALL(0x007A1E20);
	};

	void SetValue(int,int)
	{
		XCALL(0x007A1E30);
	};

	void SetValue(float,int)
	{
		XCALL(0x007A1E60);
	};

	void SetValue(zSTRING&,int)
	{
		XCALL(0x007A1E90);
	};

	void GetValue(int&,int)
	{
		XCALL(0x007A1FE0);
	};

	void GetValue(float&,int)
	{
		XCALL(0x007A2010);
	};

	void GetValue(zSTRING&,int)
	{
		XCALL(0x007A2040);
	};

	void SetLineData(int,int,int,int)
	{
		XCALL(0x007A2190);
	};

	void GetLineData(int&,int&,int&,int&)
	{
		XCALL(0x007A2550);
	};

	void SetFileNr(int)
	{
		XCALL(0x007A2590);
	};

	void Save(zFILE*)
	{
		XCALL(0x007A2720);
	};

	void SaveFull(zFILE*)
	{
		XCALL(0x007A2940);
	};

	void LoadFull(zFILE*)
	{
		XCALL(0x007A2BA0);
	};

	void Load(zFILE*)
	{
		XCALL(0x007A2D70);
	};

	void SetOffset(int)
	{
		XCALL(0x007A2F20);
	};

	int GetOffset(void)
	{
		XCALL(0x007A2F30);
	};

	void SetClassOffset(int)
	{
		XCALL(0x007A2F40);
	};

	int GetClassOffset(void)
	{
		XCALL(0x007A2F50);
	};

public:
	
	// Members
	zSTRING					name;				// Name of Symbol

	zCPar_Symbol*			next;				// Naechtes Symbol in Einfuege-Reihenfolge

private :
	
	union {
		void*				adr;				// Datenwerte fuer jeweilige Variable
		int*				intdata;
		float*				floatdata;
		zSTRING*			stringdata;
        
        int                 single_intdata;
        float               single_floatdata;
	};

	int						offset;				// Offset bei KlassenVars 
												// Data-Adresse bei Instances												// Return type bei Functions

    // hoffentlich können die folgenden Elemente etwas gepackt werden

public:
	unsigned int    		ele:12;				// Number of Elements
	unsigned int			type:4;				// Type of Elements
	unsigned int			flags:6;			// flags ( CONSTANTS )
	// Temps Debuggen
	zBOOL					space:1;
private:

	// Line and File-Positions
	unsigned int			filenr:19;			// Filenummer
	unsigned int			line:19;			// Linenummer
	unsigned int			line_anz:19;		// Wieviele Zeilen ?
	unsigned int			pos_beg:24;			// Anfangsposition	(Datei -> Bytes)
	unsigned int			pos_anz:24;

	zCPar_Symbol*			parent;				// Parent-Verweis
};

class zCPar_SymbolTable
{
	// preallocated symbols (Memory Pool)
    zCPar_Symbol           *preAllocatedSymbols;
    int                     nextPreAllocated;
	zCArray<zCPar_Symbol*>	table;
	zCArraySort<int>		tablesort;
	zCPar_Symbol*			lastsym;
	zCPar_Symbol*			firstsym;
public:
	zCPar_SymbolTable()
	{
		
	};

	zCPar_SymbolTable(int)
	{
		XCALL(0x007A2F60);
	};

	~zCPar_SymbolTable(void)
	{
		XCALL(0x007A3090);
	};

	void Clear(void)
	{
		XCALL(0x007A3100);
	};

	void PreAlloc(int)
	{
		XCALL(0x007A31F0);
	};

	static int Compare(void const*,void const*)
	{
		XCALL(0x007A3260);
	};

	void Save(zFILE*)
	{
		XCALL(0x007A32E0);
	};

	void Load(zFILE*)
	{
		XCALL(0x007A3460);
	};

	int IsIn(zCPar_Symbol*)
	{
		XCALL(0x007A3850);
	};

	int IsIn(zSTRING const&)
	{
		XCALL(0x007A3960);
	};

	int GetIndex(zCPar_Symbol*)
	{
		XCALL(0x007A3A70);
	};

	int GetIndex(zSTRING const&)
	{
		XCALL(0x007A3B60);
	};

	int GetIndex(zSTRING const&,int)
	{
		XCALL(0x007A3C50);
	};

	int __fastcall Search(zSTRING const&,int,int)
	{
		XCALL(0x007A3D60);
	};

	zCPar_Symbol* GetSymbol(zSTRING const&)
	{
		XCALL(0x007A3E40);
	};

	zCPar_Symbol* GetSymbol(int)
	{
		XCALL(0x007A3EE0);
	};

	int Insert(zCPar_Symbol*)
	{
		XCALL(0x007A3F00);
	};

	void InsertEnd(zCPar_Symbol*)
	{
		XCALL(0x007A4140);
	};

	void ShrinkToFit(void)
	{
		XCALL(0x007A4350);
	};

	void SetSize(int)
	{
		XCALL(0x007A4430);
	};

	int GetNumInList(void)
	{
		XCALL(0x007A44E0);
	};

	zCPar_Symbol* GetLastSymbol(void)
	{
		XCALL(0x007A44F0);
	};

	zCPar_Symbol* GetFirstSymbol(void)
	{
		XCALL(0x007A4500);
	};

	void Show(void)
	{
		XCALL(0x007A4510);
	};
};

class zCPar_Stack
{
public:
	BYTE*			stack;						// Stackbeginn
	union {
		BYTE*		stackptr;					// Aktuelle Pos auf Stack	( Pop  / Read  )
		WORD*		stackptr_w;
		int*		stackptr_i;
	};
	union {
		BYTE*		stacklast;					// Aktuelles Ende des Stack	( Push / Write )
		WORD*		stacklast_w;
		int*		stacklast_i;
	};
	int				stacksize;					// Stackgroesse in Bytes

	zCPar_Stack()
	{

	};

	zCPar_Stack(int)
	{
		XCALL(0x007A4AC0);
	};

	~zCPar_Stack(void)
	{
		XCALL(0x007A4AF0);
	};

	int GetPopPos(void)
	{
		XCALL(0x007A4B10);
	};

	void SetPopPos(int)
	{
		XCALL(0x007A4B20);
	};

	int GetDynSize(void)
	{
		XCALL(0x007A4B30);
	};

	int GetStatSize(void)
	{
		XCALL(0x007A4B40);
	};

	void PushByte(unsigned char)
	{
		XCALL(0x007A4B50);
	};

	void PushWord(unsigned short)
	{
		XCALL(0x007A4B70);
	};

	void PushInt(int)
	{
		XCALL(0x007A4B90);
	};

	void PushString(zSTRING&)
	{
		XCALL(0x007A4BB0);
	};

	unsigned char PopByte(void)
	{
		XCALL(0x007A4C20);
	};

	unsigned short PopWord(void)
	{
		XCALL(0x007A4C30);
	};

	int PopInt(void)
	{
		XCALL(0x007A4C40);
	};

	void PopString(zSTRING&)
	{
		XCALL(0x007A4C50);
	};

	void CheckOverflow(int)
	{
		XCALL(0x007A4E10);
	};

	void Set(int,int)
	{
		XCALL(0x007A4E80);
	};

	int ReachedEnd(void)
	{
		XCALL(0x007A4E90);
	};

	void Clear(void)
	{
		XCALL(0x007A4EA0);
	};

	void Save(zFILE*)
	{
		XCALL(0x007A4EB0);
	};

	void Load(zFILE*)
	{
		XCALL(0x007A4EF0);
	};
};

class zCPar_DataStack
{
public:
	int				stack[2048];
	int				sptr;

	zCPar_DataStack(void)
	{
		XCALL(0x007A4F50);
	};

	~zCPar_DataStack(void)
	{
		XCALL(0x007A4F70);
	};

	void Push(int)
	{
		XCALL(0x007A4F80);
	};

	int Pop(void)
	{
		XCALL(0x007A5070);
	};

	float PopFloat(void)
	{
		XCALL(0x007A5090);
	};

	int IsEmpty(void)
	{
		XCALL(0x007A5170);
	};

	void Clear(void)
	{
		XCALL(0x007A5180);
	};
};