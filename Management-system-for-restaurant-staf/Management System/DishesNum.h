#if !defined(AFX_DISHESNUM_H__A695AE0A_1EF9_4AB7_92E2_02330173763B__INCLUDED_)
#define AFX_DISHESNUM_H__A695AE0A_1EF9_4AB7_92E2_02330173763B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DishesNum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDishesNum dialog

class CDishesNum : public CDialog
{
// Construction
public:
	CDishesNum(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDishesNum)
	enum { IDD = IDD_dishesNum };
	CString	m_dishesNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDishesNum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDishesNum)

	afx_msg void OnbtnOK();
	afx_msg void OnbtnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISHESNUM_H__A695AE0A_1EF9_4AB7_92E2_02330173763B__INCLUDED_)
