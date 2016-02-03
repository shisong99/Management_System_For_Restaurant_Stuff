#if !defined(AFX_LOGIN_H__5A14B71E_338B_420A_818F_AAFAF0293E77__INCLUDED_)
#define AFX_LOGIN_H__5A14B71E_338B_420A_818F_AAFAF0293E77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

class CLogin : public CDialog
{
// Construction
public:
	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;
	int count;
	CLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_login };
	CBitmapButton	m_CANCEL;
	CBitmapButton	m_OK;
	CEdit	m_userpwd;
	CEdit	m_username;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
	virtual BOOL OnInitDialog();
	afx_msg void OnbtnOK();
	afx_msg void OnbtnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__5A14B71E_338B_420A_818F_AAFAF0293E77__INCLUDED_)
