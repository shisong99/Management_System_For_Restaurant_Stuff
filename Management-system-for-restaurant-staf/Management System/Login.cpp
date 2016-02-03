// Login.cpp : implementation file
//

#include "stdafx.h"
#include "��������ϵͳ.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMyApp theApp ; //����һ��ȫ�ֱ���theApp;
/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	count = 0;
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_btnCancel, m_CANCEL);
	DDX_Control(pDX, IDC_btnOK, m_OK);
	DDX_Control(pDX, IDC_userpwd, m_userpwd);
	DDX_Control(pDX, IDC_username, m_username);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_btnOK, OnbtnOK)
	ON_BN_CLICKED(IDC_btnCancel, OnbtnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

BOOL CLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
/////////////////////////////////////////////////////////////////////////////
m_OK.LoadBitmaps(IDB_BITMAPlogin_login1,IDB_BITMAPlogin_login2);   //����  

 m_OK.SizeToContent();   //ʹ��ť��ӦͼƬ��С
 m_CANCEL.LoadBitmaps(IDB_BITMAPlogin_cancel1,IDB_BITMAPlogin_cancel2);   //����  

 m_CANCEL.SizeToContent();   //ʹ��ť��ӦͼƬ��С
	/////////////////////////////////////////////////////////////////////////
	CString userName = "chenqiong";
	CString userPwd  = "1234";
	m_username.SetWindowText(userName);
	m_userpwd.SetWindowText(userPwd);
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_login)), TRUE);	
	//UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogin::OnbtnOK() 
{
	UpdateData(TRUE);

	CString userName;
	CString userPwd;

	m_username.GetWindowText(userName);
	m_userpwd.GetWindowText(userPwd);

	if ( !userName.IsEmpty() || !userPwd.IsEmpty() )
	{
		CString strSql;
		
		strSql.Format("SELECT * FROM Login WHERE UserName = '%s' and UserPasswd = '%s' ", userName, userPwd);
		try
		{
			m_AdoConn.OnInitADOConn();
			m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

			if (m_pRs->adoEOF)
			{
				AfxMessageBox("�û�������������");
				userName  = "chenqiong";
				userPwd   = "";
				count++;
				m_username.SetWindowText(userName);
				m_userpwd.SetWindowText(userPwd);
				
				if ( count == 3)
				{
					CDialog::OnCancel();
				}
			}
			else
			{
				theApp.m_userName = userName;
				theApp.m_userPwd  = userPwd;
				CDialog::OnOK();
				return ;
			}

		}
	   catch (_com_error exp)
		{
			CString strTemp;
			strTemp.Format("�������ݿ������Ϣ:%s", exp.ErrorMessage());
			AfxMessageBox(strTemp);
			return ;

		}
	}
	else
	{
		AfxMessageBox("�û������벻��Ϊ��");
	}
	
	m_AdoConn.ExitConn();

}

void CLogin::OnbtnCancel() 
{
	CDialog::OnCancel();
}
