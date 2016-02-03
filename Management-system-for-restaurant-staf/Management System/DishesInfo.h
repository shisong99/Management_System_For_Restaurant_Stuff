#if !defined(AFX_DISHESINFO_H__2EFB3B13_436F_46AB_9775_95249AB038E9__INCLUDED_)
#define AFX_DISHESINFO_H__2EFB3B13_436F_46AB_9775_95249AB038E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CDishesInfo dialog

class CDishesInfo : public CDialog
{
// Construction
public:
	void ShowDishesInfo();
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CDishesInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDishesInfo)
	enum { IDD = IDD_dishesInfo };
	CBitmapButton	m_dishinfo_update;
	CBitmapButton	m_dishinfo_delete;
	CBitmapButton	m_dishinfo_cancel;
	CBitmapButton	m_dishinfo_add;
	CComboBox	m_dishesNameSelect;
	CListCtrl	m_listShowDishes;
	CString	m_dishesName;
	float	m_dishesPrice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDishesInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDishesInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedishesName();
	afx_msg void OnbntADD();
	afx_msg void OnbntUpdate();
	afx_msg void OnbntDelete();
	afx_msg void OnbntCancel();
	afx_msg void OnClicklistShowDishes(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISHESINFO_H__2EFB3B13_436F_46AB_9775_95249AB038E9__INCLUDED_)
