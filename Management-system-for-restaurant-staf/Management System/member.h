#if !defined(AFX_MEMBER_H__FAE3D25B_05F6_4F1C_AAC7_64724E2E2B91__INCLUDED_)
#define AFX_MEMBER_H__FAE3D25B_05F6_4F1C_AAC7_64724E2E2B91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// member.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// member dialog

class member : public CDialog
{
// Construction
public:
	ADOConn m_AdoConn;
	_RecordsetPtr m_pRs;//用于获取结果集的指针
	BOOL flag;
	member(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(member)
	enum { IDD = IDD_member };
	CListCtrl	m_memberlist;
	CComboBox	m_memberID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(member)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(member)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSelchangeCOMBOmemberID();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMBER_H__FAE3D25B_05F6_4F1C_AAC7_64724E2E2B91__INCLUDED_)
