#if !defined(AFX_RETURNDATABASE_H__31274F09_EF83_4A18_85A9_42C00F47CA13__INCLUDED_)
#define AFX_RETURNDATABASE_H__31274F09_EF83_4A18_85A9_42C00F47CA13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnDatabase.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturnDatabase dialog

class CReturnDatabase : public CDialog
{
// Construction
public:
	char buf[256];
	CReturnDatabase(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnDatabase)
	enum { IDD = IDD_returnSQL };
	CBitmapButton	m_rs_r;
	CBitmapButton	m_rs_browse;
	CBitmapButton	m_rs_cancel;
	CString	m_databasePath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnDatabase)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnDatabase)
	afx_msg void OnbntCheck();
	afx_msg void OnbntReturn();
	afx_msg void OnbntCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNDATABASE_H__31274F09_EF83_4A18_85A9_42C00F47CA13__INCLUDED_)
