#if !defined(AFX_MONTHINCOME_H__E685939F_C8F6_4079_A6D0_5AD808E11C94__INCLUDED_)
#define AFX_MONTHINCOME_H__E685939F_C8F6_4079_A6D0_5AD808E11C94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CMonthIncome dialog

class CMonthIncome : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CMonthIncome(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMonthIncome)
	enum { IDD = IDD_monthIncome };
	CBitmapButton	m_mi_enquery;
	CBitmapButton	m_mi_cancel;
	CComboBox	m_incomeYear;
	CComboBox	m_incomeMonth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonthIncome)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMonthIncome)
	virtual BOOL OnInitDialog();
	afx_msg void OnbntFound();
	afx_msg void OnbntCancel();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONTHINCOME_H__E685939F_C8F6_4079_A6D0_5AD808E11C94__INCLUDED_)
