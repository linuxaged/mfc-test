#pragma once
#include "afxdialogex.h"


// dlg2 dialog

class dlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(dlg2)

public:
	dlg2(CWnd* pParent = nullptr);   // standard constructor
	virtual ~dlg2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
