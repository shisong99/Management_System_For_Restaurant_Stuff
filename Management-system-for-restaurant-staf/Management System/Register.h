#if !defined(AFX_REGISTER_H__75A81B41_2A4E_401F_894E_DD1CE8C07062__INCLUDED_)
#define AFX_REGISTER_H__75A81B41_2A4E_401F_894E_DD1CE8C07062__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog

class CRegister : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CRegister(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegister)
	enum { IDD = IDD_register };
	CBitmapButton	m_register_register;
	CBitmapButton	m_register_cancel;
	CEdit	m_repeatPwd;
	CEdit	m_userPasswnd;
	CEdit	m_userName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegister)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegister)
	virtual BOOL OnInitDialog();
	afx_msg void OnbtnRegister();
	afx_msg void OnbntCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__75A81B41_2A4E_401F_894E_DD1CE8C07062__INCLUDED_)
