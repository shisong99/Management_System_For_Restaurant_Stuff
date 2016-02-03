#if !defined(AFX_OPENTABLE_H__E3F02624_0E04_4AEF_AE17_E70F8819557E__INCLUDED_)
#define AFX_OPENTABLE_H__E3F02624_0E04_4AEF_AE17_E70F8819557E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenTable.h : header file
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// COpenTable dialog

class COpenTable : public CDialog
{
// Construction
public:
	int tableID;
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CString m_strTableID;
	//int tableID;
	COpenTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenTable)
	enum { IDD = IDD_openTable };
	CBitmapButton	m_ot_select;
	CBitmapButton	m_ot_back;
	CEdit	m_tableID;
	CListCtrl	m_listShow;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenTable)
	virtual BOOL OnInitDialog();
	afx_msg void OnbtnSelectTable();
	afx_msg void OnbtnBack();
	afx_msg void OnClicklistShow(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENTABLE_H__E3F02624_0E04_4AEF_AE17_E70F8819557E__INCLUDED_)
