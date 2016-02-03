// UserManage.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "UserManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog


CUserManage::CUserManage(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserManage)
	m_userName = _T("");
	m_userPwd = _T("");
	//}}AFX_DATA_INIT
}


void CUserManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserManage)
	DDX_Control(pDX, IDC_bntUpdate, m_usermanage_update);
	DDX_Control(pDX, IDC_bntDelete, m_usermanage_delete);
	DDX_Control(pDX, IDC_bntCancel, m_usermanage_cancel);
	DDX_Control(pDX, IDC_listShowInfo, m_listShowInfo);
	DDX_Text(pDX, IDC_username, m_userName);
	DDX_Text(pDX, IDC_userpwd, m_userPwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserManage, CDialog)
	//{{AFX_MSG_MAP(CUserManage)
	ON_NOTIFY(NM_CLICK, IDC_listShowInfo, OnClicklistShowInfo)
	ON_BN_CLICKED(IDC_bntUpdate, OnbntUpdate)
	ON_BN_CLICKED(IDC_bntDelete, OnbntDelete)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserManage message handlers

BOOL CUserManage::OnInitDialog() 
{
	CDialog::OnInitDialog(); 
    m_usermanage_update.LoadBitmaps(IDB_BITMAPusermanage_update1,IDB_BITMAPusermanage_update2);   //载入  
    m_usermanage_update.SizeToContent();   //使按钮适应图片大小
	m_usermanage_delete.LoadBitmaps(IDB_BITMAPusermanage_delete1,IDB_BITMAPusermanage_delete2);   //载入  
    m_usermanage_delete.SizeToContent();   //使按钮适应图片大小
	m_usermanage_cancel.LoadBitmaps(IDB_BITMAPusermanage_cancel1,IDB_BITMAPuseramanage_cancel2);   //载入  
    m_usermanage_cancel.SizeToContent();   //使按钮适应图片大小
	m_imageList.Create(32, 32, ILC_COLOR24 | ILC_MASK, 1, 0);
	m_imageList.Add( AfxGetApp()->LoadIcon(IDI_ICON_login));
	m_listShowInfo.SetImageList(&m_imageList, LVSIL_NORMAL);
	CString strSql;
	m_listShowInfo.InsertColumn(0, "用户名");
	CRect rect;
	m_listShowInfo.GetWindowRect(rect);
	int wide = rect.right - rect.left;
	m_listShowInfo.SetColumnWidth(0, wide);

	strSql.Format("SELECT * FROM Login");
	m_AdoConn.OnInitADOConn();
	m_pRs =	m_AdoConn.GetRecordSet((_bstr_t)strSql);
	while (m_pRs->adoEOF == 0)
	{
		CString userName ;
		userName = (char*)(_bstr_t)m_pRs->GetCollect("UserName");
		m_listShowInfo.InsertItem(0, userName);
		m_pRs->MoveNext();
	}



	
	return TRUE; 
}

void CUserManage::OnClicklistShowInfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	i = m_listShowInfo.GetSelectionMark();
	if (i == -1)
	{
		AfxMessageBox("请选择用户");
		return ;
	}
	CString userName;
	CString userPwd;
	userName = m_listShowInfo.GetItemText(i, 0);
	CString strSql;
	strSql.Format("SELECT * FROM Login WHERE UserName = '%s'", userName);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	userPwd = (char*)(_bstr_t)m_pRs->GetCollect("UserPasswd");
	m_userName = userName;
	m_userPwd  = userPwd;
	UpdateData(FALSE);
	*pResult = 0;
}

void CUserManage::OnbntUpdate() 
{
	UpdateData(TRUE);

	CString strSql;
	strSql.Format("UPDATE Login Set UserPasswd = '%s' WHERE UserName = '%s'", m_userPwd, m_userName);
	BOOL success =m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
	if ( success == TRUE)
	{
		AfxMessageBox("用户:"+ m_userName+ "更新成功!");
	}
	else
	{
		AfxMessageBox("操作失败");
		return;
	}
	
	m_userName.Empty();
	m_userPwd.Empty();
	UpdateData(FALSE);

	m_listShowInfo.DeleteAllItems();
	strSql.Format("SELECT * FROM Login");
	m_pRs =	m_AdoConn.GetRecordSet((_bstr_t)strSql);
	while (m_pRs->adoEOF == 0)
	{
		CString userName ;
		userName = (char*)(_bstr_t)m_pRs->GetCollect("UserName");
		m_listShowInfo.InsertItem(0, userName);
		m_pRs->MoveNext();
	}
}

void CUserManage::OnbntDelete() 
{
	UpdateData(TRUE);
	CString strSql;
	if (MessageBox("确定删除" + m_userName + "吗？他人不错哦", "提示", MB_YESNO) == IDYES)
	{
		
		strSql.Format("DELETE FROM Login WHERE UserName = '%s'", m_userName);
		BOOL success = m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		if ( success == TRUE)
		{
			AfxMessageBox("用户:"+ m_userName+ "删除成功!");
		}
		else
		{
			AfxMessageBox("操作失败");
			return;
		}
	}

	m_userName.Empty();
	m_userPwd.Empty();
	UpdateData(FALSE);

	m_listShowInfo.DeleteAllItems();
	strSql.Format("SELECT * FROM Login");
	m_pRs =	m_AdoConn.GetRecordSet((_bstr_t)strSql);
	while (m_pRs->adoEOF == 0)
	{
		CString userName ;
		userName = (char*)(_bstr_t)m_pRs->GetCollect("UserName");
		m_listShowInfo.InsertItem(0, userName);
		m_pRs->MoveNext();
	}

	
}

void CUserManage::OnbntCancel() 
{
	CDialog::OnCancel();
}


