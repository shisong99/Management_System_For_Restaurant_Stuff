// DishesTotle.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "DishesTotle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDishesTotle dialog


CDishesTotle::CDishesTotle(CWnd* pParent /*=NULL*/)
	: CDialog(CDishesTotle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDishesTotle)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDishesTotle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDishesTotle)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDishesTotle, CDialog)
	//{{AFX_MSG_MAP(CDishesTotle)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDishesTotle message handlers
