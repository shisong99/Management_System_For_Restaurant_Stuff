// 餐饮管理系统Dlg.h : header file
//

#if !defined(AFX_DLG_H__E6BAE45C_DDF4_4E67_9B92_A69BD7E77E92__INCLUDED_)
#define AFX_DLG_H__E6BAE45C_DDF4_4E67_9B92_A69BD7E77E92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ADOConn.h"

class CMyDlg : public CDialog
{
// Construction
public:
	////////////////////////////////////

	////////////////////////////////////
	void OnMENURegister();
	CImageList              m_imageList;  //图像列表控制
	CStatusBar              m_statusBar;
	_RecordsetPtr           m_pRs;
	ADOConn                 m_AdoConn;
	CToolBar                m_toolBar;
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CBitmapButton	m_my_change;
	CBitmapButton	m_my_count;
	CBitmapButton	m_my_employ;
	CBitmapButton	m_my_exit;
	CBitmapButton	m_my_login;
	CBitmapButton	m_my_eat;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMENUlogin();
	afx_msg void OnMENUabout();
	afx_msg void OnMENUbuygoods();
	afx_msg void OnMENUcopySQL();
	afx_msg void OnMENUdayincome();
	afx_msg void OnMENUdishesInfo();
	afx_msg void OnMENUemployeesManage();
	afx_msg void OnMENUgoodsInfo();
	afx_msg void OnMENUmonthIncome();
	afx_msg void OnMENUnewSQL();
	afx_msg void OnMENUopen();
	afx_msg void OnMENUpay();
	afx_msg void OnMENUpower();
	afx_msg void OnMENUreturnSQL();
	afx_msg void OnMENUupdate();
	afx_msg void OnMENUgoodsSelect();
	afx_msg void OnMEUNselectAccess();
	afx_msg void OnMENUsql2005();
	afx_msg void OnClose();
	afx_msg void OnMENUcookermenu();
	afx_msg void Onmenumember();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__E6BAE45C_DDF4_4E67_9B92_A69BD7E77E92__INCLUDED_)
