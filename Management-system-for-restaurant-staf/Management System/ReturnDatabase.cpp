// ReturnDatabase.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "ReturnDatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnDatabase dialog


CReturnDatabase::CReturnDatabase(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnDatabase::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnDatabase)
	m_databasePath = _T("");
	//}}AFX_DATA_INIT
}


void CReturnDatabase::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnDatabase)
	DDX_Control(pDX, IDC_bntReturn, m_rs_r);
	DDX_Control(pDX, IDC_bntCheck, m_rs_browse);
	DDX_Control(pDX, IDC_bntCancel, m_rs_cancel);
	DDX_Text(pDX, IDC_databasePath, m_databasePath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturnDatabase, CDialog)
	//{{AFX_MSG_MAP(CReturnDatabase)
	ON_BN_CLICKED(IDC_bntCheck, OnbntCheck)
	ON_BN_CLICKED(IDC_bntReturn, OnbntReturn)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnDatabase message handlers

void CReturnDatabase::OnbntCheck() 
{
	CFileDialog  fileDlg(TRUE, "mdb", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "(*.mdb) | *.mdb", NULL);

	if (fileDlg.DoModal() == IDOK)
	{
		CString str;
		m_databasePath = fileDlg.GetPathName();
		UpdateData(FALSE);
	}
	
	
}

void CReturnDatabase::OnbntReturn() 
{
	UpdateData(TRUE);
	CopyFile(m_databasePath, buf, FALSE);
	MessageBox("还原完成！","系统提示",MB_OK|MB_ICONEXCLAMATION);
	
}

void CReturnDatabase::OnbntCancel() 
{
	CDialog::OnCancel();
	
}

BOOL CReturnDatabase::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_rs_browse.LoadBitmaps(IDB_BITMAPrs_browse1,IDB_BITMAPrs_browse2);   //载入  
    m_rs_browse.SizeToContent();   //使按钮适应图片大小
		m_rs_r.LoadBitmaps(IDB_BITMAPrs_r1,IDB_BITMAPrs_r2);   //载入  
    m_rs_r.SizeToContent();   //使按钮适应图片大小	
		m_rs_cancel.LoadBitmaps(IDB_BITMAPrs_cancel1,IDB_BITMAPrs_cancel2);   //载入  
    m_rs_cancel.SizeToContent();   //使按钮适应图片大小	
	::GetCurrentDirectory(256, buf);
	strcat(buf, "\\Catering.mdb");
	
	return TRUE;  
}
