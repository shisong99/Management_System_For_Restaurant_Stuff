#if !defined(AFX_COPYDATABASE_H__7A66FFBD_EAE4_4F12_AC95_017F1A1854E9__INCLUDED_)
#define AFX_COPYDATABASE_H__7A66FFBD_EAE4_4F12_AC95_017F1A1854E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CCopyDatabase dialog

class CCopyDatabase : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CCopyDatabase(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCopyDatabase)
	enum { IDD = IDD_copySQL };
	CString	m_copyWay;
	CString	m_databaseName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCopyDatabase)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCopyDatabase)

	afx_msg void Onbrowse();
	afx_msg void OnbntOK();
	afx_msg void OnbntCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPYDATABASE_H__7A66FFBD_EAE4_4F12_AC95_017F1A1854E9__INCLUDED_)
