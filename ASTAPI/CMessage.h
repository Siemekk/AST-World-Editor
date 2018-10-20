#pragma once

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms645505(v=vs.85).aspx

typedef struct CMessage
{
	ASTAPI static int Box(
		HWND,
		zSTRING, 
		zSTRING = "AST",
		UINT	= 0);


	ASTAPI static void Box(
		zSTRING, 
		zSTRING = "AST",
		bool TopMost = false);


	ASTAPI static void Error(
		zSTRING, 
		zSTRING = "AST :: Error",
		bool TopMost = true);


	ASTAPI static void Warning(
		zSTRING, 
		zSTRING = "AST :: Warning",
		bool TopMost = false);


	ASTAPI static BOOL Choice(
		zSTRING, 
		zSTRING = "AST :: Choice",
		bool TopMost = false);


	ASTAPI static BOOL Question(
		zSTRING msg, 
		zSTRING title = "ST :: Question",
		bool TopMost = false);


	ASTAPI static void Fatal(
		zSTRING, 
		zSTRING = "AST :: Fatal",
		bool TopMost = true);

} Message, Say;