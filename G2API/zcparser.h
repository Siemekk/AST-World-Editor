#pragma once

#include "zcpar_symbol.h"

#pragma warning(disable:4731) // -- suppress C4731:"frame pointer register 'ebp' modified by inline assembly code"


class zCViewProgressBar;
class zCView;
class zFILE;
class zDATE;

// узел дерева выражени€ скриптов при компил€ции
class zCPar_TreeNode				//sizeof 0x30
{
public:
	zSTRING					name;
	BYTE					token;
	union {
		int					value;
		float				fvalue;
	};
	int						info;
	zCPar_TreeNode*			left;
	zCPar_TreeNode*			right;
	zCPar_TreeNode*			next;

private:
	// TMP
	int cNr;
public:
	zCPar_TreeNode(void)
	{
		XCALL(0x00797980);
	};

	zCPar_TreeNode(int,int)
	{
		XCALL(0x007979C0);
	};

	zCPar_TreeNode(int,zSTRING&,int)
	{
		XCALL(0x00797A10);
	};

	~zCPar_TreeNode(void)
	{
		XCALL(0x00797BA0);
	};

	void SetLeft(zCPar_TreeNode*)
	{
		XCALL(0x00797C60);
	};

	void SetRight(zCPar_TreeNode*)
	{
		XCALL(0x00797C70);
	};

	void SetNext(zCPar_TreeNode*)
	{
		XCALL(0x00797C80);
	};

	static zCPar_TreeNode* SeekEndTree(zCPar_TreeNode*)
	{
		XCALL(0x00797C90);
	};

	static zCPar_TreeNode* MakeDyadicNode(zCPar_TreeNode*,int,zCPar_TreeNode*)
	{
		XCALL(0x00797CB0);
	};

	static zCPar_TreeNode* MakeMonadicNode(int,zCPar_TreeNode*)
	{
		XCALL(0x00797D20);
	};
};

// файл скриптов (*.d)
class zCPar_File
{
public:
	int						fileid;				// FileNumber
	zSTRING					name;				// Filename
	char*					begin_adr;			// Startadresse der Filedaten 
	int						size;				// Size of File in Bytes
	int						labels;				// Anzahl der Labels in diesem File
	zBOOL					treeload;			// Treeload activated
	zCPar_TreeNode*			tree;
public:

	zCPar_File(void)
	{
		XCALL(0x0078D020);
	};

	~zCPar_File(void)
	{
		XCALL(0x0078D050);
	};

	int IsNewerDate(zDATE&,zDATE&)
	{
		XCALL(0x0078D0F0);
	};

	int IsExactDate(zDATE&,zDATE&)
	{
		XCALL(0x0078D170);
	};

	void SetFileNumber(int)
	{
		XCALL(0x0078D1F0);
	};

	int GetFileNumber(void)
	{
		XCALL(0x0078D200);
	};

	zSTRING GetName(void)
	{
		XCALL(0x0078D210);
	};

	void EnableTreeLoad(int)
	{
		XCALL(0x0078D260);
	};

	int Load(zSTRING&,zCPar_SymbolTable&,zDATE&)
	{
		XCALL(0x0078D270);
	};

	char* GetStartAddress(void)
	{
		XCALL(0x0078D4F0);
	};

	char* GetEndAddress(void)
	{
		XCALL(0x0078D500);
	};

	void Dispose(void)
	{
		XCALL(0x0078D510);
	};

	void SetTree(zCPar_TreeNode*)
	{
		XCALL(0x0078D530);
	};

	zCPar_TreeNode* GetTree(void)
	{
		XCALL(0x0078D570);
	};

	void SetLabelCount(int)
	{
		XCALL(0x0078D580);
	};

	int GetLabelCount(void)
	{
		XCALL(0x0078D590);
	};

	void SaveTree(int,zCPar_Symbol*,zDATE&)
	{
		XCALL(0x0078D5A0);
	};

	void SaveTreeNode(zFILE*,zCPar_TreeNode*)
	{
		XCALL(0x0078D820);
	};

	zCPar_TreeNode* LoadTreeNode(zFILE*)
	{
		XCALL(0x0078D990);
	};

	int LoadTree(int&,zCPar_SymbolTable&)
	{
		XCALL(0x0078DAC0);
	};

	void DeleteTree(void)
	{
		XCALL(0x0078DE90);
	};

};

class zCParser
{
public:
	void					(*msgfunc)					( zSTRING  s );	// Messages from Parser
	// *** Vars ***
	zCArray <zCPar_File *>	file;						// Liste von eingebundenen Files
	zCPar_SymbolTable		symtab;						// Symboltable 
	zCPar_StringTable		stringtab;					// Alle Strings
	zCPar_Stack				stack;						// Pseudo-Code-Stack
	zCPar_DataStack			datastack;					// ExpressionStack
	zCPar_Symbol*			self;
	zSTRING					fname;						// Current Parsing - Files

	zSTRING					mainfile;
	zBOOL					compiled;
	zBOOL					treesave;
	zBOOL					datsave;		
	zBOOL					parse_changed;				// Wurden einzelne D-Files reparsed ?
	zBOOL					treeload;					// Treeload activated ?
	zBOOL					mergemode;
	int						linkingnr;					// Welches File wird gelinkt ?
	// ********************************
	// Parsing / Counter
	// ********************************
	int						linec;						// Aktuelle Zeile
	int						line_start;					// Filepos der letzten Zeile
	zBOOL					ext_parse;					// Anderer Parsemode : 2 Adr ueberschreibt 1.
	char*					pc_start;					// StartAdresse
	char*					pc,*oldpc;					// Aktuelle Fileposition ( Adresse )
	char*					pc_stop,*oldpc_stop;		// End Of File

	zBOOL					params;						// Parameterleiste abarbeiten
	int						in_funcnr;
	int						in_classnr;
	int						stringcount;				// Anzahl "loser" Strings (ab 10000)
	zCPar_Symbol*			in_func;					// Aktuelle Funktion
	zCPar_Symbol*			in_class;					// Aktuelle Klasse

	// ********************************
	// Error / MessageHandling
	// ********************************
	zBOOL					error;
	zBOOL					stop_on_error;
	int						errorline;

	// ********************************
	// Lexer / Scanner
	// ********************************
	char*					prevword_index[16];
	int						prevline_index[16];
	int						prevword_nr;
	zSTRING					aword;
	int						instance;
	int						instance_help;				// Wird benutzt, um Instanzen zu uebergeben

	// ********************************
	// Percentage
	// ********************************

	zCViewProgressBar*		progressBar;	

	// ********************************
	// Expressions
	// ********************************
	zCPar_TreeNode*			tree;
	zCPar_TreeNode*			treenode;

	// ********************************
	// Debugging
	// ********************************
	zCView*					win_code;
	zBOOL					debugmode;
	int						curfuncnr;		// Aktuelle Funktion	

	// ********************************
	// PseudoCode - Execution
	// ********************************
	int						labelcount;
	int*					labelpos;

	// *************************************************************************
	// Additional Vars -> Desktop - Items
	// *************************************************************************
	zCList <zSTRING>*		add_funclist;
	zSTRING					add_filename;
	zBOOL					add_created;
public:
	//
	// [AST]
	int LoadDat_AST(zSTRING&);
	static void Cpp2Script(int,zSTRING const&);
	static BOOL GetScriptOpt(zSTRING const&);
	static zSTRING GetScriptString(zSTRING const&);
	static void SetScriptString(zSTRING &,zSTRING &);
	void _DeclareAssign(zSTRING &s);
	void _DeclareInstance();



	// [/AST]
	//
	static void SetVersion(unsigned char)
	{
		XCALL(0x0078D000);
	};

	static unsigned char GetVersion(void)
	{
		XCALL(0x0078D010);
	};

	static zCParser* GetParser(void)
	{
		XCALL(0x0078DEC0);
	};

	zCParser(int)
	{
		XCALL(0x0078DED0);
	};

	~zCParser(void)
	{
		XCALL(0x0078DFF0);
	};

	void SetMessageFunc(void (__cdecl*)(zSTRING))
	{
		XCALL(0x0078E250);
	};

	void SetStopOnError(int)
	{
		XCALL(0x0078E260);
	};

	void Error(zSTRING&,int nLine = -1)
	{
		XCALL(0x0078E270);
	};

	void Message(zSTRING&)
	{
		XCALL(0x0078E5F0);
	};

	int Error(void)
	{
		XCALL(0x0078E730);
	};

	int SaveDat(zSTRING&)
	{
		XCALL(0x0078E740);
	};

	int LoadDat(zSTRING&)
	{
		XCALL(0x0078E900);
	};

	int Parse(zSTRING)
	{
		XCALL(0x0078EBA0);
	};

	int ParseSource(zSTRING&)
	{
		XCALL(0x0078EE20);
	};

	int ParseFile(zSTRING&)
	{
		XCALL(0x0078F660);
	};

	void ParseBlock(void)
	{
		XCALL(0x0078FE30);
	};

	void CreatePCode(void)
	{
		XCALL(0x007900E0);
	};

	void ShowSymbols(void)
	{
		XCALL(0x00790810);
	};

	void PushTree(zCPar_TreeNode*)
	{
		XCALL(0x00790820);
	};

	zCPar_TreeNode* PushOnStack(zCPar_TreeNode*)
	{
		XCALL(0x00790840);
	};

	void SolveLabels(zCPar_TreeNode*)
	{
		XCALL(0x007915F0);
	};

	int MergeFile(zSTRING&)
	{
		XCALL(0x00791650);
	};

	int PopDataValue(void)
	{
		XCALL(0x007918B0);
	};

	float PopFloatValue(void)
	{
		XCALL(0x007918E0);
	};

	int* PopVarAddress(void)
	{
		XCALL(0x00791910);
	};

	zSTRING* PopString(void)
	{
		XCALL(0x00791940);
	};

	void DoStack(int)
	{
		XCALL(0x00791960);
	};

	void* CallFunc(zSTRING const&)
	{
		XCALL(0x007929D0);
	};

	void* CallFunc(int,...)
	{
		XCALL(0x007929F0);
	};

	int GetCurrentFunc(void)
	{
		XCALL(0x00792F10);
	};

	int CreateInstance(zSTRING&,void*)
	{
		XCALL(0x00792F20);
	};

	int CreateInstance(int,void*)
	{
		XCALL(0x00792FA0);
	};

	int CreatePrototype(zSTRING&,void*)
	{
		XCALL(0x00793010);
	};

	int CreatePrototype(int,void*)
	{
		XCALL(0x00793090);
	};

	void Reset(void)
	{
		XCALL(0x00793100);
	};

	void SetPercentDone(int)
	{
		XCALL(0x00793270);
	};

	void CreateHelpers(void)
	{
		XCALL(0x007932D0);
	};

	void EnableTreeSave(int)
	{
		XCALL(0x00793440);
	};

	void EnableDatSave(int)
	{
		XCALL(0x00793450);
	};

	void EnableTreeLoad(int)
	{
		XCALL(0x00793460);
	};

	int GetIndex(zSTRING const&)
	{
		XCALL(0x00793470);
	};

	int MatchClass(int,zSTRING const&)
	{
		XCALL(0x00793530);
	};

	int GetBaseClass(zCPar_Symbol*)
	{
		XCALL(0x007935B0);
	};

	int GetBaseClass(int)
	{
		XCALL(0x00793610);
	};

	int GetBase(int)
	{
		XCALL(0x00793670);
	};

	int GetPrototype(int,int)
	{
		XCALL(0x007936C0);
	};

	int GetInstance(int,int)
	{
		XCALL(0x00793730);
	};

	zSTRING GetSymbolInfo(int,int& type,int&)
	{
		XCALL(0x007937F0);
	};

	zCPar_Symbol* GetSymbolInfo(int)
	{
		XCALL(0x007938B0);
	};

	zCPar_Symbol* GetSymbol(int)
	{
		XCALL(0x007938C0);
	};

	zCPar_Symbol* GetSymbol(zSTRING const&)
	{
		XCALL(0x007938D0);
	};

	zSTRING GetClassVarInfo(int,int,int&,int&)
	{
		XCALL(0x00793990);
	};

	void GetClassVarInfo(int,zSTRING&,int&,int&)
	{
		XCALL(0x00793BB0);
	};

	zSTRING GetText(zSTRING&,int)
	{
		XCALL(0x00793D70);
	};

	zSTRING GetText(int,int)
	{
		XCALL(0x00793DB0);
	};

	int GetInt(int,int)
	{
		XCALL(0x00793E90);
	};

	zSTRING GetInstanceValue(zSTRING&,int,void*,int)
	{
		XCALL(0x00793EE0);
	};

	zSTRING GetInstanceValue(int,int,void*,int)
	{
		XCALL(0x00793FD0);
	};

	int IsValid(zSTRING&,void*,zSTRING&)
	{
		XCALL(0x007942E0);
	};

	int CheckClassSize(zSTRING&,int)
	{
		XCALL(0x00794450);
	};

	int CheckClassSize(int,int)
	{
		XCALL(0x00794470);
	};

	void AddClassOffset(zSTRING&,int)
	{
		XCALL(0x00794730);
	};

	int SetInstance(zSTRING const&,void*)
	{
		XCALL(0x00794870);
	};

	int SetInstance(int,void*)
	{
		XCALL(0x00794910);
	};

	int AutoCompletion(zSTRING&)
	{
		XCALL(0x00794950);
	};

	int GetNumFiles(void)
	{
		XCALL(0x00794B60);
	};

	zSTRING GetFileName(int)
	{
		XCALL(0x00794B70);
	};

	int IsStackFull(void)
	{
		XCALL(0x00794C10);
	};

	int GetLastErrorLine(void)
	{
		XCALL(0x00794C20);
	};

	void Reparse(zSTRING&)
	{
		XCALL(0x00794C30);
	};

	int SaveInstance(zSTRING&,void*)
	{
		XCALL(0x00794D40);
	};

	int SaveInstance(int,void*)
	{
		XCALL(0x00794D70);
	};

	void CloseViews(void)
	{
		XCALL(0x00795A30);
	};

	void ShowCode(int)
	{
		XCALL(0x00795A60);
	};

	void SaveInfoFile(zSTRING)
	{
		XCALL(0x00795BB0);
	};

	void SetInfoFile(zCList<zSTRING>*,zSTRING const&)
	{
		XCALL(0x00796200);
	};

	int IsInAdditionalInfo(zSTRING const&)
	{
		XCALL(0x00796390);
	};

	int WriteAdditionalInfo(zSTRING&,int,int)
	{
		XCALL(0x00796540);
	};

	int ClearAllInstanceRefs(void)
	{
		XCALL(0x007968D0);
	};

	int ClearInstanceRefs(void*)
	{
		XCALL(0x00796940);
	};

	int ResetGlobalVars(void)
	{
		XCALL(0x007969C0);
	};

	void CreateVarReferenceList(zSTRING const&,zCArray<int>&)
	{
		XCALL(0x00796A40);
	};

	void ResetWithVarReferenceList(zCArray<int>&,void*)
	{
		XCALL(0x00796BC0);
	};

	int SaveGlobalVars(zCArchiver&)
	{
		XCALL(0x00796C40);
	};

	int LoadGlobalVars(zCArchiver&)
	{
		XCALL(0x00797170);
	};

	void GetOperatorString(int,zSTRING&)
	{
		XCALL(0x00797D80);
	};

	void FindNext(char*)
	{
		XCALL(0x00798310);
	};

	void PrevWord(void)
	{
		XCALL(0x00798480);
	};

	void ReadWord(zSTRING&)
	{
		XCALL(0x007984B0);
	};

	void Match(zSTRING&)
	{
		XCALL(0x00798720);
	};

	int ReadVarType(void)
	{
		XCALL(0x007988B0);
	};

	int ReadFuncType(void)
	{
		XCALL(0x00798AE0);
	};

	int ReadInt(void)
	{
		XCALL(0x00798D00);
	};

	float ReadFloat(void)
	{
		XCALL(0x00798FA0);
	};

	void ReadString(zSTRING&)
	{
		XCALL(0x007992E0);
	};

	int ReadArray(void)
	{
		XCALL(0x007995C0);
	};

	zCPar_TreeNode* CreateLeaf(int,zCPar_TreeNode*)
	{
		XCALL(0x007997C0);
	};

	zCPar_TreeNode* CreateStringLeaf(void)
	{
		XCALL(0x00799820);
	};

	zCPar_TreeNode* CreateFloatLeaf(void)
	{
		XCALL(0x00799A70);
	};

	int GetNextToken(void)
	{
		XCALL(0x00799C10);
	};

	zCPar_TreeNode* Parse_Expression_Primary(int&)
	{
		XCALL(0x0079A390);
	};

	zCPar_TreeNode* Parse_Expression(int&,int)
	{
		XCALL(0x0079A940);
	};

	zCPar_TreeNode* ParseExpressionEx(zSTRING&)
	{
		XCALL(0x0079AB50);
	};

	zCPar_TreeNode* ParseExpression(void)
	{
		XCALL(0x0079ABC0);
	};

	int EvalLeaf(zCPar_TreeNode*,int)
	{
		XCALL(0x0079ABE0);
	};

	void DeclareVar(int)
	{
		XCALL(0x0079B0A0);
	};

	void DeclareClass(void)
	{
		XCALL(0x0079C3D0);
	};

	void DeclareInstance(void)
	{
		XCALL(0x0079C5A0);
	};

	void DeclarePrototype(void)
	{
		XCALL(0x0079CD80);
	};

	void DeclareIf(void)
	{
		XCALL(0x0079D270);
	};

	void DeclareAssign(zSTRING&)
	{
		XCALL(0x0079D6D0);
	};

	void DeclareAssignFunc(zSTRING&)
	{
		XCALL(0x0079DE50);
	};

	void DeclareFunc(void)
	{
		XCALL(0x0079E140);
	};

	void DeclareReturn(void)
	{
		XCALL(0x0079E5D0);
	};

	void DeclareFuncCall(zSTRING&,int typematch=0 )
	{
		XCALL(0x0079E7B0);
	};

	zCPar_Symbol* SearchFuncWithStartAddress(int)
	{
		XCALL(0x0079F180);
	};

	void GetNextCommand(zSTRING&)
	{
		XCALL(0x0079F1F0);
	};

	void ShowPCodeSpy(zSTRING&)
	{
		XCALL(0x0079FE10);
	};

	void ShowPCode(int,zCView*,int)
	{
		XCALL(0x0079FF40);
	};

	void DefineExternal(zSTRING const&,int (__cdecl*)(void),int,int,...)
	{
		XCALL(0x007A0190);
	};

	void DefineExternalVar(zSTRING const&,void*,int,int)
	{
		XCALL(0x007A0550);
	};

	void GetParameter(int&)
	{
		XCALL(0x007A0760);
	};

	void GetParameter(float&)
	{
		XCALL(0x007A0770);
	};

	void GetParameter(zSTRING&)
	{
		XCALL(0x007A07B0);
	};

	void* GetInstance(void)
	{
		XCALL(0x007A08F0);
	};

	void* GetInstanceAndIndex(int&)
	{
		XCALL(0x007A0920);
	};

	void SetReturn(int)
	{
		XCALL(0x007A0960);
	};

	void SetReturn(float)
	{
		XCALL(0x007A0980);
	};

	void SetReturn(void*)
	{
		XCALL(0x007A09A0);
	};

	void SetReturn(zSTRING&)
	{
		XCALL(0x007A09D0);
	};

	int FindInstanceVar(zSTRING&)
	{
		XCALL(0x007A09F0);
	};

	int GetLastInstance(void)
	{
		XCALL(0x007A0BD0);
	};

	int FindIndex(zSTRING&)
	{
		XCALL(0x007A0BE0);
	};
};



