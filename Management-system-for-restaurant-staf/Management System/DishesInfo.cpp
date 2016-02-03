// DishesInfo.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "DishesInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDishesInfo dialog


CDishesInfo::CDishesInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDishesInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDishesInfo)
	m_dishesName = _T("");
	m_dishesPrice = 0.0f;
	//}}AFX_DATA_INIT
}


void CDishesInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDishesInfo)
	DDX_Control(pDX, IDC_bntUpdate, m_dishinfo_update);
	DDX_Control(pDX, IDC_bntDelete, m_dishinfo_delete);
	DDX_Control(pDX, IDC_bntCancel, m_dishinfo_cancel);
	DDX_Control(pDX, IDC_bntADD, m_dishinfo_add);
	DDX_Control(pDX, IDC_dishesName, m_dishesNameSelect);
	DDX_Control(pDX, IDC_listShowDishes, m_listShowDishes);
	DDX_CBString(pDX, IDC_dishesName, m_dishesName);
	DDX_Text(pDX, IDC_dishesPrice, m_dishesPrice);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDishesInfo, CDialog)
	//{{AFX_MSG_MAP(CDishesInfo)
	ON_CBN_SELCHANGE(IDC_dishesName, OnSelchangedishesName)
	ON_BN_CLICKED(IDC_bntADD, OnbntADD)
	ON_BN_CLICKED(IDC_bntUpdate, OnbntUpdate)
	ON_BN_CLICKED(IDC_bntDelete, OnbntDelete)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	ON_NOTIFY(NM_CLICK, IDC_listShowDishes, OnClicklistShowDishes)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDishesInfo message handlers

BOOL CDishesInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_dishinfo_add.LoadBitmaps(IDB_BITMAPdishinfo_add1,IDB_BITMAPdishinfo_add2);   //载入  
    m_dishinfo_add.SizeToContent();   //使按钮适应图片大小
	m_dishinfo_update.LoadBitmaps(IDB_BITMAPdishinfo_update1,IDB_BITMAPdishinfo_update2);   //载入  
    m_dishinfo_update.SizeToContent();   //使按钮适应图片大小
	m_dishinfo_cancel.LoadBitmaps(IDB_BITMAPdishinfo_back1,IDB_BITMAPdishinfo_back2);   //载入  
    m_dishinfo_cancel.SizeToContent();   //使按钮适应图片大小
	m_dishinfo_delete.LoadBitmaps(IDB_BITMAPdishinfo_delete1,IDB_BITMAPdishinfo_delete2);   //载入  
    m_dishinfo_delete.SizeToContent();   //使按钮适应图片大小
	m_listShowDishes.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowDishes.InsertColumn(0, "菜名");
	m_listShowDishes.InsertColumn(1, "价格(元/盘)");
	CRect rect;
	m_listShowDishes.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowDishes.SetColumnWidth(0, wide/2);
	m_listShowDishes.SetColumnWidth(1, wide/2);

	m_AdoConn.OnInitADOConn();
	CString strSql;
	strSql = "SELECT * FROM DishesInfo ";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		CString DishesName;
		CString DishesPrice;
		DishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		DishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");
		m_listShowDishes.SetItemText(0, 0, DishesName);
		m_listShowDishes.SetItemText(0, 1, DishesPrice);
		m_dishesNameSelect.AddString(DishesName);
		m_pRs->MoveNext();
	}
	
	return TRUE;  
}

void CDishesInfo::OnSelchangedishesName() 
{
	int i;
	i = m_dishesNameSelect.GetCurSel();
	CString DishesName;
	m_dishesNameSelect.GetLBText(i, DishesName);
	CString strDishesPrice;

	CString strSql;
	strSql = "SELECT * FROM DishesInfo WHERE DishesName = '"+DishesName+"'";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");

	if (m_pRs->adoEOF == 0)
	{
		m_dishesPrice = atof(strDishesPrice);
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox("不存在要删除的商品");
		return ;
	}
	
}

void CDishesInfo::OnbntADD() 
{
	UpdateData(TRUE);
	CString DishesName;
	CString DishesPrice;

	if (m_dishesName.IsEmpty())
	{
		AfxMessageBox("菜式名不能为空");
		return ;
	}

	if(m_dishesPrice == 0)
	{
		AfxMessageBox("单价不能为空");
		return;
	}

	CString strSql;
	strSql.Format("SELECT * FROM DishesInfo WHERE DishesName = '%s'", m_dishesName);
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	if (m_pRs->adoEOF == 0)
	{
		AfxMessageBox("该菜式已经有了，无需添加");
		return ;
	}

	
	strSql.Format("INSERT INTO DishesInfo(DishesName, DishesPrice) VALUES('%s',%f)", m_dishesName, m_dishesPrice);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	m_dishesNameSelect.AddString(m_dishesName);
	m_listShowDishes.DeleteAllItems();
	AfxMessageBox(m_dishesName+"添加成功!");
/*	strSql = "SELECT * FROM DishesInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);


	
	while (m_pRs->adoEOF == 0)
	{

		DishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		DishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");
		m_listShowDishes.SetItemText(0, 0, DishesName);
		m_listShowDishes.SetItemText(0, 1, DishesPrice);
		
		m_pRs->MoveNext();
	}*/

	ShowDishesInfo();

	m_dishesPrice = 0;
	m_dishesName.Empty();
	UpdateData(FALSE);
	
	
}

void CDishesInfo::OnbntUpdate() 
{
	UpdateData(TRUE);
	CString DishesName;
	CString DishesPrice;

	if (m_dishesName.IsEmpty())
	{
		AfxMessageBox("菜式名不能为空");
		return ;
	}

	if(m_dishesPrice == 0)
	{
		AfxMessageBox("单价不能为空");
		return;
	}

	CString strSql;
	int i;
	i = m_dishesNameSelect.GetCurSel();
	m_dishesNameSelect.GetLBText(i, m_dishesName);
//	GoodsName = m_goodsName;
	strSql.Format("UPDATE DishesInfo SET  DishesPrice =%f WHERE DishesName = '%s'", m_dishesPrice, m_dishesName);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	m_listShowDishes.DeleteAllItems();
	AfxMessageBox(m_dishesName+"更新成功!");
	
	ShowDishesInfo();
/*	strSql = "SELECT * FROM DishesInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	while (m_pRs->adoEOF == 0)
	{
		
		 DishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		AfxMessageBox("单价不能为空");
		 DishesPrice =(char*)(_bstr_t) m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");
		m_listShowDishes.SetItemText(0, 0, DishesName);
		m_listShowDishes.SetItemText(0, 1, DishesPrice);
		
		m_pRs->MoveNext();
	}
*/
	m_dishesPrice = 0;
	m_dishesName.Empty();
	UpdateData(FALSE);

}

void CDishesInfo::OnbntDelete() 
{
	UpdateData(TRUE);
	CString DishesName;
	CString DishesPrice;

	if (m_dishesName.IsEmpty())
	{
		AfxMessageBox("菜式名不能为空");
		return ;
	}

	CString strSql;
	strSql.Format("DELETE FROM DishesInfo WHERE DishesName = '%s'", m_dishesName);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	m_listShowDishes.DeleteAllItems();

	AfxMessageBox(m_dishesName+"删除成功!");
	/*strSql = "SELECT * FROM DishesInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	
	while (m_pRs->adoEOF == 0)
	{

		DishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		DishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");
		m_listShowDishes.SetItemText(0, 0, DishesName);
		m_listShowDishes.SetItemText(0, 1, DishesPrice);
		
		m_pRs->MoveNext();
	}*/
	ShowDishesInfo();
	m_dishesPrice = 0;
	int i;
	i = m_dishesNameSelect.GetCurSel();
	m_dishesNameSelect.DeleteString(i);
	m_dishesName.Empty();
	UpdateData(FALSE);
	
}

void CDishesInfo::OnbntCancel() 
{
	CDialog::OnCancel();
	
}

void CDishesInfo::OnClicklistShowDishes(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i=m_listShowDishes.GetSelectionMark();
	CString DishesName=m_listShowDishes.GetItemText(i,0);
	CString strDishesPrice=m_listShowDishes.GetItemText(i,1);
	double DishesPrice;
	DishesPrice = atof(strDishesPrice);
	m_dishesName = DishesName;
	m_dishesPrice = DishesPrice;
	UpdateData(false);

	*pResult = 0;
}

void CDishesInfo::ShowDishesInfo()
{
	CString strSql;
	CString DishesName;
	CString DishesPrice;
	strSql = "SELECT * FROM DishesInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	
	while (m_pRs->adoEOF == 0)
	{

		DishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		DishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");
		m_listShowDishes.SetItemText(0, 0, DishesName);
		m_listShowDishes.SetItemText(0, 1, DishesPrice);
		
		m_pRs->MoveNext();
	}

}
