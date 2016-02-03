#if !defined(AFX_GOODSSELECT_H__BB8FA956_3E64_43BF_B054_6D57030A29A6__INCLUDED_)
#define AFX_GOODSSELECT_H__BB8FA956_3E64_43BF_B054_6D57030A29A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CGoodsSelect dialog

class CGoodsSelect : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CGoodsSelect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGoodsSelect)
	enum { IDD = IDD_goodsSelect };
	CBitmapButton	m_goodsselect_query;
	CBitmapButton	m_goodsselect_cancel;
	CComboBox	m_stockYear;
	CComboBox	m_stockMonth;
	CComboBox	m_stockDay;
	CListCtrl	m_listShowGoods;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoodsSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoodsSelect)
	virtual BOOL OnInitDialog();
	afx_msg void OnbntQuery();
	afx_msg void OnbntCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOODSSELECT_H__BB8FA956_3E64_43BF_B054_6D57030A29A6__INCLUDED_)
