#if !defined(AFX_USERMANAGE_H__2F79F010_AFDE_450D_8B7F_4D20A56F4A47__INCLUDED_)
#define AFX_USERMANAGE_H__2F79F010_AFDE_450D_8B7F_4D20A56F4A47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ADOConn.h"

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog

class CUserManage : public CDialog
{
// Construction
public:
	int i;
	CImageList m_imageList;
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	CUserManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserManage)
	enum { IDD = IDD_userManage };
	CBitmapButton	m_usermanage_update;
	CBitmapButton	m_usermanage_delete;
	CBitmapButton	m_usermanage_cancel;
	CListCtrl	m_listShowInfo;
	CString	m_userName;
	CString	m_userPwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnClicklistShowInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnbntUpdate();
	afx_msg void OnbntDelete();
	afx_msg void OnbntCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMANAGE_H__2F79F010_AFDE_450D_8B7F_4D20A56F4A47__INCLUDED_)
