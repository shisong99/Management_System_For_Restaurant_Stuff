#if !defined(AFX_DISHESTOTLE_H__5455DA58_E06F_4BBE_BE3F_9B11B36F7D4C__INCLUDED_)
#define AFX_DISHESTOTLE_H__5455DA58_E06F_4BBE_BE3F_9B11B36F7D4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DishesTotle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDishesTotle dialog

class CDishesTotle : public CDialog
{
// Construction
public:
	CDishesTotle(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDishesTotle)
	enum { IDD = IDD_dishesTotle };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDishesTotle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDishesTotle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISHESTOTLE_H__5455DA58_E06F_4BBE_BE3F_9B11B36F7D4C__INCLUDED_)
