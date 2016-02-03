#if !defined(AFX_SELECTDISHES_H__3B70B2E7_AE91_4F93_B878_ECECE36A8B07__INCLUDED_)
#define AFX_SELECTDISHES_H__3B70B2E7_AE91_4F93_B878_ECECE36A8B07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectDishes.h : header file
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CSelectDishes dialog

class CSelectDishes : public CDialog
{
// Construction
public:
	int tableID;
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CSelectDishes(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectDishes)
	enum { IDD = IDD_selectDishes };
	CBitmapButton	m_pay;
	CBitmapButton	m_sd_cancelb;
	CBitmapButton	m_sd_select;
	CBitmapButton	m_sd_OK;
	CBitmapButton	m_sd_cancel;
	CListCtrl	m_listShowSelect;
	CListCtrl	m_listShowDishes;
	CString	m_tableID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectDishes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectDishes)
	virtual BOOL OnInitDialog();
	afx_msg void OnbtnSelect();
	afx_msg void OnbtnCancel();
	afx_msg void OnbtnOK();
	afx_msg void OnCancel();
	afx_msg void OnItemchangedlistShowDishes(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTDISHES_H__3B70B2E7_AE91_4F93_B878_ECECE36A8B07__INCLUDED_)
