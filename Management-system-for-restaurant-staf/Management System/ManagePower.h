#if !defined(AFX_MANAGEPOWER_H__2113CD9A_5BDF_4F38_A16B_3C81E172ECF0__INCLUDED_)
#define AFX_MANAGEPOWER_H__2113CD9A_5BDF_4F38_A16B_3C81E172ECF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"
/////////////////////////////////////////////////////////////////////////////
// CManagePower dialog

class CManagePower : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	int radioSelect;
	CManagePower(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CManagePower)
	enum { IDD = IDD_managePower };
	CBitmapButton	m_mangepower_OK;
	CBitmapButton	m_mangepower_cancel;
	CComboBox	m_userName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagePower)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManagePower)
	virtual BOOL OnInitDialog();
	afx_msg void Onmanager();
	afx_msg void Onforman();
	afx_msg void Onassistant();
	afx_msg void OnSelchangeusername();
	afx_msg void OnbntOK();
	afx_msg void OnbntCancel();
	afx_msg void Oncooker();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEPOWER_H__2113CD9A_5BDF_4F38_A16B_3C81E172ECF0__INCLUDED_)
