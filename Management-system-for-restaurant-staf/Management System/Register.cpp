// Register.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "Register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegister dialog


CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegister)
	//}}AFX_DATA_INIT
}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegister)
	DDX_Control(pDX, IDC_btnRegister, m_register_register);
	DDX_Control(pDX, IDC_bntCancel, m_register_cancel);
	DDX_Control(pDX, IDC_reapetPwd, m_repeatPwd);
	DDX_Control(pDX, IDC_userPasswnd, m_userPasswnd);
	DDX_Control(pDX, IDC_username, m_userName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	//{{AFX_MSG_MAP(CRegister)
	ON_BN_CLICKED(IDC_btnRegister, OnbtnRegister)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

BOOL CRegister::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_register_register.LoadBitmaps(IDB_BITMAPregister_register1,IDB_BITMAPregister_register2);   //载入  
    m_register_register.SizeToContent();   //使按钮适应图片大小	
	m_register_cancel.LoadBitmaps(IDB_BITMAPregister_cancel1,IDB_BITMAPregister_cancel2);   //载入  
    m_register_cancel.SizeToContent();   //使按钮适应图片大小	
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_reg)),TRUE);
	
	return TRUE;  
}

void CRegister::OnbtnRegister() 
{
	UpdateData(TRUE);
	CString userName;
	CString userPwd;
	CString repeatPwd;

	m_userName.GetWindowText(userName);
	m_userPasswnd.GetWindowText(userPwd);
	m_repeatPwd.GetWindowText(repeatPwd);

	if ( userName.IsEmpty() || userPwd.IsEmpty() || repeatPwd.IsEmpty() )
	{
		AfxMessageBox("用户所填信息都不能为空，请输入完成在提交");
		return;
	}

	if (userPwd != repeatPwd)
	{
		AfxMessageBox("两次输入密码不一致，请确定后在输入");
		return;
	}

	m_AdoConn.OnInitADOConn();
	CString strSql;
	strSql.Format("SELECT * FROM Login WHERE UserName = '%s'", userName);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	if (m_pRs->adoEOF)
	{
		strSql.Format("INSERT INTO Login(UserName, UserPasswd, UserPower) VALUES('%s','%s', %d)",\
			userName, userPwd,2);
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
	}
	else
	{
		AfxMessageBox("该用户已经存在，请输入其他名字");
		return ;
	}

	strSql.Format("SELECT * FROM Login WHERE UserName = '%s'", userName);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	if (!m_pRs->adoEOF)
	{
		CString strInformation;
		strInformation = "恭喜你"+userName+"注册成功!";
		AfxMessageBox(strInformation);
		CDialog::OnOK();
	}

	m_AdoConn.ExitConn();
}

void CRegister::OnbntCancel() 
{
	
	CString userName;
	CString userPwd;
	CString repeatPwd;
	userName.Empty();
	userPwd.Empty();
	repeatPwd.Empty();
	m_userName.SetWindowText(userName);
	m_userPasswnd.SetWindowText(userPwd);
	m_repeatPwd.SetWindowText(repeatPwd);
	CDialog::OnCancel();

}
