// DishesNum.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "DishesNum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDishesNum dialog


CDishesNum::CDishesNum(CWnd* pParent /*=NULL*/)
	: CDialog(CDishesNum::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDishesNum)
	m_dishesNum = _T("");
	//}}AFX_DATA_INIT
}


void CDishesNum::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDishesNum)
	DDX_Text(pDX, IDC_dishesNum, m_dishesNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDishesNum, CDialog)
	//{{AFX_MSG_MAP(CDishesNum)
	ON_BN_CLICKED(IDC_btnOK, OnbtnOK)
	ON_BN_CLICKED(IDC_btnBack, OnbtnBack)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDishesNum message handlers

void CDishesNum::OnbtnOK() 
{
	UpdateData(TRUE);

	if (m_dishesNum.IsEmpty() || m_dishesNum == "0")
	{
		AfxMessageBox("请选择菜的份量");
		return ;
	}
	
	CDialog::OnOK();
}

void CDishesNum::OnbtnBack() 
{
	CDialog::OnCancel();
	
}
