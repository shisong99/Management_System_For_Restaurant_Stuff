// member.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "member.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// member dialog


member::member(CWnd* pParent /*=NULL*/)
	: CDialog(member::IDD, pParent)
{
	//{{AFX_DATA_INIT(member)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void member::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(member)
	DDX_Control(pDX, IDC_member, m_memberlist);
	DDX_Control(pDX, IDC_COMBOmemberID, m_memberID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(member, CDialog)
	//{{AFX_MSG_MAP(member)
	ON_CBN_SELCHANGE(IDC_COMBOmemberID, OnSelchangeCOMBOmemberID)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL member::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString strmemberID;
	CString strSql;
	strSql.Format("SELECT * FROM VIP" );

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)//有好多条
	{
		strmemberID = (char*)(_bstr_t)m_pRs->GetCollect("memberID");
		m_memberID.AddString(strmemberID);
		m_pRs->MoveNext();
	}
		m_memberlist.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_memberlist.InsertColumn(0, "会员号");
	m_memberlist.InsertColumn(1, "会员姓名");
	m_memberlist.InsertColumn(2, "会员级别");
	m_memberlist.InsertColumn(3, "会员折扣");

	CRect rect;
	m_memberlist.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_memberlist.SetColumnWidth(0, wide*1/4);
	m_memberlist.SetColumnWidth(1, wide*1/4);
	m_memberlist.SetColumnWidth(2, wide*1/4);
	m_memberlist.SetColumnWidth(3, wide*1/4);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////////////////////
// member message handlers

void member::OnOK() 
{
	// TODO: Add extra validation here
	AfxMessageBox("会员验证成功！");
	CDialog::OnOK();
}

void member::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void member::OnSelchangeCOMBOmemberID() 
{
	// TODO: Add your control notification handler code here
	CString strmemberID;
	CString strmemberName;
	CString strmemberLV;
	CString strmemberDiscount;
	m_memberlist.DeleteAllItems();
	int i = m_memberID.GetCurSel();
	m_memberID.GetLBText(i, strmemberID);
	CString strSql;
	strSql.Format("SELECT * FROM VIP WHERE memberID =%d",atoi(strmemberID));
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	m_memberlist.DeleteAllItems();
	while (m_pRs->adoEOF == 0)//没啥错误
	{
	//	CString strmemberID;
	//	CString strmemberName;
	//	CString strmemberLV;
		strmemberID = (char*)(_bstr_t)m_pRs->GetCollect("memberID");
		strmemberName = (char*)(_bstr_t)m_pRs->GetCollect("memberName");
		strmemberLV = (char*)(_bstr_t)m_pRs->GetCollect("memberLV");
		strmemberDiscount = (char*)(_bstr_t)m_pRs->GetCollect("memberDiscount");
		m_memberlist.InsertItem(0, "");//这是把数据嵌入列表的意思
		m_memberlist.SetItemText(0, 0, strmemberID);//这是指明数据嵌入列表何处的意思
		m_memberlist.SetItemText(0, 1, strmemberName);
		m_memberlist.SetItemText(0, 2, strmemberLV);
		m_memberlist.SetItemText(0, 3, strmemberDiscount);
		m_pRs->MoveNext();//换行，也就是说这些事一个一个显示的
	}
}
