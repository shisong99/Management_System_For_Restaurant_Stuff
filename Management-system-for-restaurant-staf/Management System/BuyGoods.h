#if !defined(AFX_BUYGOODS_H__C173BD94_D9F2_4280_A590_ADAE72A80D38__INCLUDED_)
#define AFX_BUYGOODS_H__C173BD94_D9F2_4280_A590_ADAE72A80D38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CBuyGoods dialog

class CBuyGoods : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	double totlePrice;
	CRect rect;
	CBuyGoods(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBuyGoods)
	enum { IDD = IDD_buyGoods };
	CBitmapButton	m_bntReset;
	CBitmapButton	m_bntOK;
	CBitmapButton	m_goodssub;
	CBitmapButton	m_goodsadd;
	CBitmapButton	m_buygoods_exit;
	CEdit	m_totlePrice;
	CListCtrl	m_listShowSelect;
	CListCtrl	m_listShowGoods;
	CEdit	m_goodsNum;
	CString	m_buyTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBuyGoods)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBuyGoods)
	virtual BOOL OnInitDialog();
	afx_msg void OnbntOK();
	afx_msg void OnbntReset();
	afx_msg void OnbntCancel();
	afx_msg void OngoodsAdd();
	afx_msg void OngoodsSub();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUYGOODS_H__C173BD94_D9F2_4280_A590_ADAE72A80D38__INCLUDED_)
