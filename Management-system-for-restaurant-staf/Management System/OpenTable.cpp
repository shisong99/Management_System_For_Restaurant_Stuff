// OpenTable.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "OpenTable.h"
#include "SelectDishes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenTable dialog


COpenTable::COpenTable(CWnd* pParent /*=NULL*/)
	: CDialog(COpenTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COpenTable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenTable)
	DDX_Control(pDX, IDC_btnSelectTable, m_ot_select);
	DDX_Control(pDX, IDC_btnBack, m_ot_back);
	DDX_Control(pDX, IDC_tableID, m_tableID);
	DDX_Control(pDX, IDC_listShow, m_listShow);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpenTable, CDialog)
	//{{AFX_MSG_MAP(COpenTable)
	ON_BN_CLICKED(IDC_btnSelectTable, OnbtnSelectTable)
	ON_BN_CLICKED(IDC_btnBack, OnbtnBack)
	ON_NOTIFY(NM_CLICK, IDC_listShow, OnClicklistShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenTable message handlers

BOOL COpenTable::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_ot_back.LoadBitmaps(IDB_BITMAPot_back1,IDB_BITMAPot_back2);   //载入  
    m_ot_back.SizeToContent();   //使按钮适应图片大小
	m_ot_select.LoadBitmaps(IDB_BITMAPot_select1,IDB_BITMAPot_select2);   //载入  
    m_ot_select.SizeToContent();   //使按钮适应图片大小
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_open)), TRUE);
	m_listShow.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | \
	LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_listShow.InsertColumn(0, "桌号");
	m_listShow.InsertColumn(1, "状态");
	RECT rect;
	m_listShow.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShow.SetColumnWidth(0, wide/2);
	m_listShow.SetColumnWidth(1, wide/2);

	CString strSql;
	strSql = "SELECT * FROM TableUse WHERE TableUseID = 0";
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	int i = 0;
	while(m_pRs->adoEOF == 0)
	{	
		//_variant_t strTableIDTemp = m_pRs->GetCollect("TableID");
		//int tableID = strTableID.intVal;

		//CString strTableID = (PSTR)strTableIDTemp.bstrVal;
		
		CString strTableID = (char*)(_bstr_t)m_pRs->GetCollect("TableID");
		_variant_t strTableUseID = m_pRs->GetCollect("TableUseID");
		int tableUseID = strTableUseID.intVal;
		m_listShow.InsertItem(i, "");
		m_listShow.SetItemText(i, 0, strTableID);
		
		//m_listShow.InsertItem(i,str);
		if (tableUseID == 0)
			m_listShow.SetItemText(i, 1, "空闲");
		if (tableUseID == 1)
			m_listShow.SetItemText(i, 1, "有人");
		
		i++;
		m_pRs->MoveNext();
	}

	return TRUE;  
}

void COpenTable::OnbtnSelectTable() 
{
	UpdateData();

	CString tableID;
	m_tableID.GetWindowText(tableID);
	
	if (tableID.IsEmpty())
	{
		AfxMessageBox("请您选择桌号");
		
	}
	else
	{
		CString strSql;
		strSql = "SELECT * FROM TableUse WHERE TableUseID = 1";
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		
		while (m_pRs->adoEOF == 0)
		{
			m_strTableID = (char*)(_bstr_t)m_pRs->GetCollect("TableID");

			if ( tableID == m_strTableID)
			{
				AfxMessageBox("此桌有人了,请选择其他桌号");
				tableID.Empty();
				m_tableID.SetWindowText(tableID);
				return ;

			}

			m_pRs->MoveNext();
		}
		
		m_pRs = NULL;
		
		
		strSql.Format("SELECT * FROM TableUse WHERE TableID = %d", atoi(tableID));
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		
		if (m_pRs->adoEOF)
		{
				AfxMessageBox("抱歉，没有此桌号");
				tableID.Empty();
				m_tableID.SetWindowText(tableID);
				
				return ;
		}

		m_AdoConn.ExitConn();
		m_pRs = NULL;
		CSelectDishes dlg;
		dlg.m_tableID = tableID;
		dlg.DoModal();
		CDialog::OnOK();

	}
}

void COpenTable::OnbtnBack() 
{
	CDialog::OnCancel();
	
}

void COpenTable::OnClicklistShow(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i;

	i = m_listShow.GetSelectionMark();
	m_strTableID = m_listShow.GetItemText(i, 0);
	m_tableID.SetWindowText(m_strTableID);

	*pResult = 0;
}
