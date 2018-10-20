#pragma comment (lib, "AST.lib")

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)
#define ASTAPI DllImport

typedef	void * __ptr32			void32;
typedef	void * __ptr64			void64;
typedef	long					int32 ;
typedef	long long				int64 ;
typedef	unsigned long			uint32;
typedef	unsigned long long		uint64;

#include "zobject.h"

#include "ASTAPI\CConfig.h"

#include "ASTAPI\CConsoleExtender.h"
#include "ASTAPI\CCallback.h"
#include "ASTAPI\CScreenShot.h"
#include "ASTAPI\CTimer.h"

#include "ASTAPI\CViewAni.h"

#include "ASTAPI\CViewAction.h"
#include "ASTAPI\CCursor.h"

#include "ASTAPI\CQuiver.h"
#include "ASTAPI\CScabbard.h"
#include "ASTAPI\CDynamicBar.h"
#include "ASTAPI\CLightDetector.h"
#include "ASTAPI\CDiagram.h"
#include "ASTAPI\CTriggerFunc.h"
#include "ASTAPI\CApplication.h"
#include "ASTAPI\CLoadScreen.h"
#include "ASTAPI\CMessage.h"
#include "ASTAPI\CSplash.h"
#include "ASTAPI\CPlugin.h"

#include "ASTAPI\Extra\Extra.h"