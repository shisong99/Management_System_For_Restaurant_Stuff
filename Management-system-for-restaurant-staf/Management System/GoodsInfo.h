#if !defined(AFX_GOODSINFO_H__4BBFC48B_61E0_4886_9471_D6E694687C66__INCLUDED_)
#define AFX_GOODSINFO_H__4BBFC48B_61E0_4886_9471_D6E694687C66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CGoodsInfo dialog

class CGoodsInfo : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CGoodsInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGoodsInfo)
	enum { IDD = IDD_GoodsInfo };
	CBitmapButton	m_goodsinfo_update;
	CBitmapButton	m_goodsinfo_delete;
	CBitmapButton	m_goodsinfo_cancel;
	CBitmapButton	m_goodsinfo_add;
	CComboBox	m_goodsNameSelect;
	CListCtrl	m_listShowGoods;
	float	m_goodsPrice;
	CString	m_goodsName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGoodsInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGoodsInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnbntADD();
	afx_msg void OnbntUpdate();
	afx_msg void OnbntDelete();
	afx_msg void OnbntCancel();
	afx_msg void OnSelchangegoodsName();
	afx_msg void OnClicklistShowGoods(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GOODSINFO_H__4BBFC48B_61E0_4886_9471_D6E694687C66__INCLUDED_)
