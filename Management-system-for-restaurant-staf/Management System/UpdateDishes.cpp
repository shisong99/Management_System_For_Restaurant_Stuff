// UpdateDishes.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "UpdateDishes.h"
#include "DishesNum.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUpdateDishes dialog


CUpdateDishes::CUpdateDishes(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdateDishes::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdateDishes)
	m_tableIDValue = _T("");
	//}}AFX_DATA_INIT
}


void CUpdateDishes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdateDishes)
	DDX_Control(pDX, IDC_bntSUB, m_ud_cancel);
	DDX_Control(pDX, IDC_bntCancel, m_ud_cancelb);
	DDX_Control(pDX, IDR_MENU_pay, m_ud_pay);
	DDX_Control(pDX, IDC_bntOK, m_ud_OK);
	DDX_Control(pDX, IDC_bntADD, m_ud_select);
	DDX_Control(pDX, IDC_tableID, m_tableID);
	DDX_Control(pDX, IDC_listShowSelect, m_listShowSelect);
	DDX_Control(pDX, IDC_listShowDishes, m_listShowDishes);
	DDX_CBString(pDX, IDC_tableID, m_tableIDValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUpdateDishes, CDialog)
	//{{AFX_MSG_MAP(CUpdateDishes)
	ON_CBN_SELCHANGE(IDC_tableID, OnSelchangetableID)
	ON_BN_CLICKED(IDC_bntADD, OnbntADD)
	ON_BN_CLICKED(IDC_bntSUB, OnbntSUB)
	ON_BN_CLICKED(IDC_bntOK, OnbntOK)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpdateDishes message handlers

BOOL CUpdateDishes::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_ud_OK.LoadBitmaps(IDB_BITMAPsd_OK1,IDB_BITMAPsd_OK2);   //载入  
    m_ud_OK.SizeToContent();   //使按钮适应图片大小
	m_ud_cancel.LoadBitmaps(IDB_BITMAPsd_cancel1,IDB_BITMAPsd_cancel2);   //载入  
    m_ud_cancel.SizeToContent();   //使按钮适应图片大小
	m_ud_cancelb.LoadBitmaps(IDB_BITMAPsd_cancelb1,IDB_BITMAPsd_cancelb2);   //载入  
    m_ud_cancelb.SizeToContent();   //使按钮适应图片大小
	m_ud_pay.LoadBitmaps(IDB_BITMAPsd_pay1,IDB_BITMAPsd_pay2);   //载入  
    m_ud_pay.SizeToContent();   //使按钮适应图片大小
	m_ud_select.LoadBitmaps(IDB_BITMAPsd_select2,IDB_BITMAPsd_select1);   //载入  
    m_ud_select.SizeToContent();   //使按钮适应图片大小	
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_update)),TRUE);
	
	m_listShowDishes.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | \
	LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_listShowDishes.InsertColumn(0, "菜名");
	m_listShowDishes.InsertColumn(1, "菜价(元)");
	CRect rect;
	m_listShowDishes.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowDishes.SetColumnWidth(0, wide*3/5);
	m_listShowDishes.SetColumnWidth(1, wide*2/5);
	
	CString strSql = "SELECT * FROM DishesInfo";
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		CString dishesName;
		CString dishesPrice;
		dishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		dishesPrice =(char*)(_bstr_t) m_pRs->GetCollect("DishesPrice");

		m_listShowDishes.InsertItem(0, dishesName);
		m_listShowDishes.SetItemText(0, 1, dishesPrice);
		m_pRs->MoveNext();
	
	}
	m_listShowSelect.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowSelect.InsertColumn(0, "菜名");
	m_listShowSelect.InsertColumn(1, "数量");
	m_listShowSelect.GetWindowRect(&rect);
	wide = rect.right - rect.left;
	m_listShowSelect.SetColumnWidth(0, wide*3/5);
	m_listShowSelect.SetColumnWidth(1, wide*2/5);

	strSql.Format("SELECT distinct UseTableID FROM PayOrder");
	//strSql.Format("SELECT distinct UseTableID FROM cookermenu");

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	while (m_pRs->adoEOF == 0)
	{
		CString tableID = (char*)(_bstr_t)m_pRs->GetCollect("UseTableID");
		m_tableID.AddString(tableID);
		m_pRs->MoveNext();
	}

	
	
	return TRUE;  
}

void CUpdateDishes::OnSelchangetableID() 
{
	CString tableID;
	int i = m_tableID.GetCurSel();
	m_tableID.GetLBText(i, tableID);
	CString strSql;
	strSql.Format("SELECT * FROM PayOrder WHERE UseTableID =%d",atoi(tableID));
	//strSql.Format("SELECT * FROM cookermenu WHERE UseTableID =%d",atoi(tableID));
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	m_listShowSelect.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		CString dishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		CString dishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
		//m_listShowSelect.InsertItem(0, "");
		//m_listShowSelect.SetItemText(0, 0, dishesName);
		m_listShowSelect.InsertItem(0, dishesName);
		m_listShowSelect.SetItemText(0, 1, dishesNum);
		
		m_pRs->MoveNext();
	}

}

void CUpdateDishes::OnbntADD() 
{
	UpdateData(TRUE);
	
	
	CDishesNum dlg;
	int i = m_tableID.GetCurSel();

	if (i == -1)
	{
		AfxMessageBox("请选择要加菜的桌号");
		return;
	}

	CString tableID;
	m_tableID.GetLBText(i, tableID);


	if (dlg.DoModal() == IDOK)
	{
		int i;
		int num = atoi(dlg.m_dishesNum);
		i = m_listShowDishes.GetSelectionMark();
		if (i == -1)
		{
			AfxMessageBox("请选择要增加的菜");
			return;
		}
		CString dishesName = m_listShowDishes.GetItemText(i, 0);
		CString strSql;
		strSql.Format("SELECT * FROM DishesInfo WHERE DishesName = '%s'", dishesName);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
		CString	dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		
		float totle = atof(dishesPrice)*num;
		CString strTotle = (char*)(_bstr_t)totle;
	
		
		strSql.Format("SELECT * FROM PayOrder WHERE UseTableID = %d and DishesName = '%s'", atoi(tableID), dishesName);
	//	strSql.Format("SELECT * FROM cookermenu WHERE UseTableID = %d and DishesName = '%s'", atoi(tableID), dishesName);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
		if (m_pRs->adoEOF == 0)
		{	
			CString DishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
			AfxMessageBox(DishesPrice);
			CString DishesNum = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
		
			totle = atof(DishesPrice) + totle;
			strTotle = (char*)(_bstr_t)totle;
		
			num = num + atoi(DishesNum);
		
			
			strSql.Format("UPDATE PayOrder SET DishesNum = %d, Consumption = %f,DishesUse=0 WHERE UseTableID =%d AND DishesName = '%s'", num, totle, atoi(tableID), dishesName);
			//strSql.Format("UPDATE cookermenu SET DishesNum = %d,WHERE UseTableID =%d AND DishesName = '%s'", num, totle, atoi(tableID), dishesName);
		}
		else
		{
			strSql = "INSERT INTO PayOrder(UseTableID,DishesName,DishesNum,Consumption,DishesUse)values("+tableID+",'"+dishesName+"',"+dlg.m_dishesNum+","+strTotle+",0)";
			//strSql = "INSERT INTO cookermenu(UseTableID,DishesName,DishesNum)values("+tableID+",'"+dishesName+"',"+dlg.m_dishesNum+","+strTotle+")";
		}

	 m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	 strSql.Format("SELECT * FROM PayOrder WHERE UseTableID =%d",atoi(tableID));
     //strSql.Format("SELECT * FROM cookermenu WHERE UseTableID =%d",atoi(tableID));
   	 m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	 m_listShowSelect.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		CString dishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		CString dishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
		//m_listShowSelect.InsertItem(0, "");
		//m_listShowSelect.SetItemText(0, 0, dishesName);
		m_listShowSelect.InsertItem(0, dishesName);
		m_listShowSelect.SetItemText(0, 1, dishesNum);
		
		m_pRs->MoveNext();
	}
		
	}
	m_listShowSelect.SetSelectionMark(-1);
	
}

void CUpdateDishes::OnbntSUB() 
{
	UpdateData(TRUE);
	CDishesNum dlg;
	CString strSql;
	int i = m_tableID.GetCurSel();
	
	if (i == -1)
	{
		AfxMessageBox("请选择要加菜的桌号");
		return;
	}

	CString tableID;
	m_tableID.GetLBText(i, tableID);

	if (dlg.DoModal() == IDOK)
	{
		int num = atoi(dlg.m_dishesNum);
		int i = m_listShowSelect.GetSelectionMark();
		if (i == -1)
		{
			AfxMessageBox("请选择要删减的菜");
			return ;
		}
		CString dishesName = m_listShowSelect.GetItemText(i, 0);
		CString dishesNum  = m_listShowSelect.GetItemText(i, 1);
		strSql.Format("SELECT * FROM DishesInfo WHERE DishesName = '%s'", dishesName);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		CString	dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
	
		
		float totle = atof(dishesPrice)*num;
		CString strTotle = (char*)(_bstr_t)totle;
		int n = num - atoi(dishesNum);
	
		if (n == 0)
		{	
			strSql.Format("DELETE  FROM PayOrder WHERE UseTableID =%d AND DishesName ='%s'", atoi(tableID), dishesName);
			//strSql.Format("DELETE  FROM cookermenu WHERE UseTableID =%d AND DishesName ='%s'", atoi(tableID), dishesName);
		}
		else
		{
			strSql.Format("UPDATE PayOrder SET DishesNum = DishesNum - %d, Consumption = Consumption - %f WHERE UseTableID =%d AND DishesName = '%s'", num, totle, atoi(tableID), dishesName);
			//strSql.Format("UPDATE cookermenu SET DishesNum = DishesNum - %d,WHERE UseTableID =%d AND DishesName = '%s'", num, totle, atoi(tableID), dishesName);
		}

		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		strSql.Format("SELECT * FROM PayOrder WHERE UseTableID =%d",atoi(tableID));
		//strSql.Format("SELECT * FROM cookermenu WHERE UseTableID =%d",atoi(tableID));
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		m_listShowSelect.DeleteAllItems();
	
		while (m_pRs->adoEOF == 0)
		{
			CString dishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
			CString dishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
			m_listShowSelect.InsertItem(0, dishesName);
			m_listShowSelect.SetItemText(0, 1, dishesNum);
			m_pRs->MoveNext();

		}

}
m_listShowSelect.SetSelectionMark(-1);

}

void CUpdateDishes::OnbntOK() 
{

	int i = m_tableID.GetCurSel();
	


	CString tableID;
	m_tableID.GetLBText(i, tableID);
	AfxMessageBox(tableID+"号桌,菜单修改成功成功!");
	CDialog::OnOK();


	
}

void CUpdateDishes::OnbntCancel() 
{
	CDialog::OnCancel();
	
}
