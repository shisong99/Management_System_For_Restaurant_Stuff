#if !defined(AFX_COOKERMENU_H__653B54AD_1347_4D25_8834_E55EEDF49F31__INCLUDED_)
#define AFX_COOKERMENU_H__653B54AD_1347_4D25_8834_E55EEDF49F31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cookermenu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccookermenu dialog

class Ccookermenu : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;
	BOOL flag;
	Ccookermenu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccookermenu)
	enum { IDD = IDD_cookermenu };
	CBitmapButton	m_cookermenu_fresh;
	CBitmapButton	m_cookermenu_delete;
	CBitmapButton	m_cookermenu_clear;
	CComboBox	m_tableID;
	CListCtrl	m_listcookerdishes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccookermenu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccookermenu)
	afx_msg void Oncookerdeletedishes();
	afx_msg void Oncookerdeletealldishes();
	afx_msg void Onupdatecookermenu();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditcookerdishes();
	afx_msg void OnSelchangecookerdishes();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COOKERMENU_H__653B54AD_1347_4D25_8834_E55EEDF49F31__INCLUDED_)
