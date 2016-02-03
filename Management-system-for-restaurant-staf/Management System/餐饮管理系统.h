// 餐饮管理系统.h : main header file for the 餐饮管理系统 application
//

#if !defined(AFX__H__B947ABBC_F9BB_4022_A775_B8BF54DB9E3C__INCLUDED_)
#define AFX__H__B947ABBC_F9BB_4022_A775_B8BF54DB9E3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See 餐饮管理系统.cpp for the implementation of this class
#include "ADOConn.h"

class CMyApp : public CWinApp
{
public:
	CString m_userName;
	CString m_userPwd;
	ADOConn m_AdoConn;
	int m_databaseFlag;
	CMyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();

	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__H__B947ABBC_F9BB_4022_A775_B8BF54DB9E3C__INCLUDED_)
