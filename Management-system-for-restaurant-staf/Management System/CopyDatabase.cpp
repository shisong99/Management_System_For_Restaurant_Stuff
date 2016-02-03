// CopyDatabase.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "CopyDatabase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCopyDatabase dialog

extern CMyApp theApp;
CCopyDatabase::CCopyDatabase(CWnd* pParent /*=NULL*/)
	: CDialog(CCopyDatabase::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCopyDatabase)
	m_copyWay = _T("");
	m_databaseName = _T("");
	//}}AFX_DATA_INIT
}


void CCopyDatabase::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCopyDatabase)
	DDX_Text(pDX, IDC_copyWay, m_copyWay);
	DDX_Text(pDX, IDC_DatabaseName, m_databaseName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCopyDatabase, CDialog)
	//{{AFX_MSG_MAP(CCopyDatabase)
	ON_BN_CLICKED(IDC_browse, Onbrowse)
	ON_BN_CLICKED(IDC_bntOK, OnbntOK)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCopyDatabase message handlers



void CCopyDatabase::Onbrowse() 
{
	CString strCopyPath;
	TCHAR  szPath[MAX_PATH];
	BROWSEINFO brow;
	brow.hwndOwner = NULL;
	brow.pidlRoot = NULL ;
	brow.lpszTitle=_T("请选择备份文件夹");
	brow.pszDisplayName=szPath;
	brow.ulFlags=BIF_RETURNONLYFSDIRS;
	brow.lpfn=NULL;
	brow.lParam=NULL;
	LPITEMIDLIST list=SHBrowseForFolder(&brow);

	if (list)
	{
		if (SHGetPathFromIDList(list, szPath))
		{
			strCopyPath = szPath;
		}
	}
	else
		strCopyPath = "";
	
	m_copyWay = strCopyPath;
	UpdateData(FALSE);

}

void CCopyDatabase::OnbntOK() 
{
	UpdateData(TRUE);
	CString strCopyPath;
	strCopyPath = m_copyWay + "\\" + m_databaseName + ".mdb";
	char buf[256];
	::GetCurrentDirectory(256, buf);
	strcat(buf, "\\Catering.mdb");
	CopyFile(buf, strCopyPath, FALSE);
	MessageBox("备份完成!", "系统提示", MB_OK | MB_ICONEXCLAMATION);
	CDialog::OnOK();

	
}

void CCopyDatabase::OnbntCancel() 
{
		CDialog::OnCancel();
	
}
