
// mfc_test0.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cmfctest0App:
// See mfc_test0.cpp for the implementation of this class
//

class Cmfctest0App : public CWinApp
{
public:
	Cmfctest0App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cmfctest0App theApp;
