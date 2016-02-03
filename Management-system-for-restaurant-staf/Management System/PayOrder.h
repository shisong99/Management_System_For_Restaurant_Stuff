#if !defined(AFX_PAYORDER_H__18A3EC58_521F_4C27_AF61_61778B358649__INCLUDED_)
#define AFX_PAYORDER_H__18A3EC58_521F_4C27_AF61_61778B358649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"


/////////////////////////////////////////////////////////////////////////////
// CPayOrder dialog

class CPayOrder : public CDialog
{
// Construction
public:
	virtual void OnOK();
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	_RecordsetPtr m_pRs1;
	BOOL flag;
	CPayOrder(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPayOrder)
	enum { IDD = IDD_payorder };
	CListCtrl	m_festivallist;
	CEdit	m_afterdiscount;
	CEdit	m_discount;
	CBitmapButton	m_pay_OK;
	CEdit	m_receiver;
	CEdit	m_surplus;
	CEdit	m_payOrder;
	CListCtrl	m_listShowOrder;
	CComboBox	m_tableID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPayOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPayOrder)
	afx_msg void OnbntOK();
	afx_msg void OnbntCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangetableID();
	afx_msg void OnChangereceiver();
	afx_msg void OnEditchangetableID();
	afx_msg void OnChangediscount();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYORDER_H__18A3EC58_521F_4C27_AF61_61778B358649__INCLUDED_)
