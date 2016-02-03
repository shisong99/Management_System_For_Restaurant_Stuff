// ManagePower.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "ManagePower.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMyApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CManagePower dialog


CManagePower::CManagePower(CWnd* pParent /*=NULL*/)
	: CDialog(CManagePower::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManagePower)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CManagePower::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManagePower)
	DDX_Control(pDX, IDC_bntOK, m_mangepower_OK);
	DDX_Control(pDX, IDC_bntCancel, m_mangepower_cancel);
	DDX_Control(pDX, IDC_username, m_userName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManagePower, CDialog)
	//{{AFX_MSG_MAP(CManagePower)
	ON_BN_CLICKED(IDC_manager, Onmanager)
	ON_BN_CLICKED(IDC_forman, Onforman)
	ON_BN_CLICKED(IDC_assistant, Onassistant)
	ON_CBN_SELCHANGE(IDC_username, OnSelchangeusername)
	ON_BN_CLICKED(IDC_bntOK, OnbntOK)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	ON_BN_CLICKED(IDC_cooker, Oncooker)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagePower message handlers

BOOL CManagePower::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_mangepower_OK.LoadBitmaps(IDB_BITMAPmangepower_set1,IDB_BITMAPmangepower_set2);   //载入  

 m_mangepower_OK.SizeToContent();   //使按钮适应图片大小
 m_mangepower_cancel.LoadBitmaps(IDB_BITMAPlogin_cancel1,IDB_BITMAPlogin_cancel2);   //载入  

 m_mangepower_cancel.SizeToContent();   //使按钮适应图片大小
	CString strSql;
	CString userName;
	strSql.Format("SELECT * FROM Login WHERE UserName <> '%s'", theApp.m_userName);
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		userName = (char*)(_bstr_t)m_pRs->GetCollect("UserName");
		m_userName.AddString(userName);
		m_pRs->MoveNext();
	}

	
	return TRUE; 
}

void CManagePower::Onmanager() 
{
	radioSelect = 0;
	
}

void CManagePower::Onforman() 
{
	radioSelect = 1;
	
}

void CManagePower::Onassistant() 
{
	radioSelect = 2;
	
}





void CManagePower::OnSelchangeusername() 
{
		UpdateData();
		
		CString strSql;
		CButton* manager   = (CButton*)GetDlgItem(IDC_manager);
		CButton* forman    = (CButton*)GetDlgItem(IDC_forman);
		CButton* assistant = (CButton*)GetDlgItem(IDC_assistant);
		CButton* cooker = (CButton*)GetDlgItem(IDC_cooker);


		int i;
		CString userName;
		i = m_userName.GetCurSel();
		m_userName.GetLBText(i, userName);
		
		strSql.Format("SELECT * FROM Login WHERE UserName = '%s'", userName);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		CString strPower;

		strPower = (char*)(_bstr_t)m_pRs->GetCollect("UserPower");
		radioSelect = atoi(strPower);

		if (radioSelect == 0)
		{
			manager->SetCheck(1);
			forman->SetCheck(0);
			assistant->SetCheck(0);
			cooker->SetCheck(0);
		}
		
		if (radioSelect == 1)
		{
			manager->SetCheck(0);
			forman->SetCheck(1);
			assistant->SetCheck(0);
			cooker->SetCheck(0);
		}
		
		if (radioSelect == 2)
		{
			manager->SetCheck(0);
			forman->SetCheck(0);
			assistant->SetCheck(1);
			cooker->SetCheck(0);
		}
		if(radioSelect==3)
		{ 
			manager->SetCheck(0);
			forman->SetCheck(0);
			assistant->SetCheck(0);
			cooker->SetCheck(1);
		}


		UpdateData(FALSE);


		




}

void CManagePower::OnbntOK() 
{
	UpdateData(TRUE);

	CString userName;
	
	int i = m_userName.GetCurSel() ;
	if (i == -1)
	{
		AfxMessageBox("请选择要设置权限的用户");
		return;
	}

	m_userName.GetLBText(i, userName);
	CString strSql;
	strSql.Format("UPDATE Login SET UserPower =%d WHERE UserName = '%s'", radioSelect, userName);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	AfxMessageBox("权限设置成功!");
		
}

void CManagePower::OnbntCancel() 
{
	CDialog::OnCancel();	
}

void CManagePower::Oncooker() 
{
	// TODO: Add your control notification handler code here
	radioSelect = 3;
	
}
