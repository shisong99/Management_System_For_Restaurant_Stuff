#if !defined(AFX_UPDATEDISHES_H__2B836DB6_AAA6_40A7_A505_52402FEAFAF1__INCLUDED_)
#define AFX_UPDATEDISHES_H__2B836DB6_AAA6_40A7_A505_52402FEAFAF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CUpdateDishes dialog

class CUpdateDishes : public CDialog
{
// Construction
public:
	int i;
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	
	CUpdateDishes(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdateDishes)
	enum { IDD = IDD_updateDishes };
	CBitmapButton	m_ud_cancel;
	CBitmapButton	m_ud_cancelb;
	CBitmapButton	m_ud_pay;
	CBitmapButton	m_ud_OK;
	CBitmapButton	m_ud_select;
	CComboBox	m_tableID;
	CListCtrl	m_listShowSelect;
	CListCtrl	m_listShowDishes;
	CString	m_tableIDValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdateDishes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUpdateDishes)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangetableID();
	afx_msg void OnbntADD();
	afx_msg void OnbntSUB();
	afx_msg void OnbntOK();
	afx_msg void OnbntCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATEDISHES_H__2B836DB6_AAA6_40A7_A505_52402FEAFAF1__INCLUDED_)
