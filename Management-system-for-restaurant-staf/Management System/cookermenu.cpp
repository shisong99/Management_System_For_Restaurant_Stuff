// cookermenu.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "cookermenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccookermenu dialog


Ccookermenu::Ccookermenu(CWnd* pParent /*=NULL*/)
	: CDialog(Ccookermenu::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccookermenu)
	//}}AFX_DATA_INIT
}


void Ccookermenu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccookermenu)
	DDX_Control(pDX, IDC_updatecookermenu, m_cookermenu_fresh);
	DDX_Control(pDX, IDC_cookerdeletedishes, m_cookermenu_delete);
	DDX_Control(pDX, IDC_cookerdeletealldishes, m_cookermenu_clear);
	DDX_Control(pDX, IDC_tableID, m_tableID);
	DDX_Control(pDX, IDC_listcookerdishes, m_listcookerdishes);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccookermenu, CDialog)
	//{{AFX_MSG_MAP(Ccookermenu)
	ON_BN_CLICKED(IDC_cookerdeletedishes, Oncookerdeletedishes)
	ON_BN_CLICKED(IDC_cookerdeletealldishes, Oncookerdeletealldishes)
	ON_BN_CLICKED(IDC_updatecookermenu, Onupdatecookermenu)
	ON_CBN_EDITCHANGE(IDC_tableID, OnEditcookerdishes)
	ON_CBN_SELCHANGE(IDC_tableID, OnSelchangecookerdishes)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccookermenu message handlers

void Ccookermenu::Oncookerdeletedishes() 
{
	// TODO: Add your control notification handler code here
	int j = m_tableID.GetCurSel();
	CString tableID;
	m_tableID.GetLBText(j, tableID);
	int i;
	i = m_listcookerdishes.GetSelectionMark();
	CString dishesName = m_listcookerdishes.GetItemText(i, 1);
	CString strSql;
	strSql="UPDATE PayOrder SET PayOrder.DishesUse=1 WHERE dishesName=PayOrder.DishesName";
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	CString dishesNum  = m_listcookerdishes.GetItemText(i, 2);
	strSql.Format("SELECT * FROM DishesInfo WHERE DishesName = '%s'", dishesName);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	CString	dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
	strSql.Format("UPDATE PayOrder SET DishesUse=1 WHERE UseTableID =%d AND DishesName = '%s'", atoi(tableID), dishesName);
	//m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
//	CString	dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
//	strSql.Format("UPDATE PayOrder SET DishesNum = %d, DishesUse=1 ");

	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" and DishesUse=0";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listcookerdishes.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		//strConsumption = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
			if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
	//	strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
	//	consumption = atof(strConsumption);
	//	consumptionTemp += consumption;
		
		
	//	strConsumption.Format("%0.2f", consumption);
		m_listcookerdishes.InsertItem(0, "");
		m_listcookerdishes.SetItemText(0, 0, strTableID);
		m_listcookerdishes.SetItemText(0, 1, strDishesName);
		m_listcookerdishes.SetItemText(0, 2, strDishesNum );
		
		//m_listShowOrder.SetItemText(0, 3, strConsumption);
		m_pRs->MoveNext();
	}
	
//	strTotleConsumption.Format("%0.2f", consumptionTemp);
//	m_payOrder.SetWindowText(strTotleConsumption);
	flag = TRUE;
	UpdateData(false);



	
}

void Ccookermenu::Oncookerdeletealldishes() 
{
	// TODO: Add your control notification handler code here
	int i;
	i = m_listcookerdishes.GetSelectionMark();
	CString dishesName = m_listcookerdishes.GetItemText(i, 1);
	CString strSql;
	strSql.Format("UPDATE PayOrder SET DishesUse=1 WHERE PayOrder.DishesName=dishesName") ;
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	//m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
//	CString	dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
//	strSql.Format("UPDATE PayOrder SET DishesNum = %d, DishesUse=1 ");

	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" and DishesUse=0";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listcookerdishes.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		//strConsumption = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
			if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
	//	strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
	//	consumption = atof(strConsumption);
	//	consumptionTemp += consumption;
		
		
	//	strConsumption.Format("%0.2f", consumption);
		m_listcookerdishes.InsertItem(0, "");
		m_listcookerdishes.SetItemText(0, 0, strTableID);
		m_listcookerdishes.SetItemText(0, 1, strDishesName);
		m_listcookerdishes.SetItemText(0, 2, strDishesNum );
		
		//m_listShowOrder.SetItemText(0, 3, strConsumption);
		m_pRs->MoveNext();
	}
	
//	strTotleConsumption.Format("%0.2f", consumptionTemp);
//	m_payOrder.SetWindowText(strTotleConsumption);
	flag = TRUE;
	UpdateData(false);



	
	
}

void Ccookermenu::Onupdatecookermenu() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;
	CString strSql;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" and DishesUse=0";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listcookerdishes.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		
			if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
	
		
		

		m_listcookerdishes.InsertItem(0, "");
		m_listcookerdishes.SetItemText(0, 0, strTableID);
		m_listcookerdishes.SetItemText(0, 1, strDishesName);
		m_listcookerdishes.SetItemText(0, 2, strDishesNum );
		
		
		m_pRs->MoveNext();
	}
	

	flag = TRUE;
	UpdateData(false);

	
}


BOOL Ccookermenu::OnInitDialog() 
{
	CDialog::OnInitDialog();
m_cookermenu_clear.LoadBitmaps(IDB_BITMAPcookermenu_clear1,IDB_BITMAPcookermenu_clear2);   //载入  
m_cookermenu_clear.SizeToContent();   //使按钮适应图片大小
m_cookermenu_delete.LoadBitmaps(IDB_BITMAPcookermenu_delete1,IDB_BITMAPcookermenu_delete2);   //载入  
m_cookermenu_delete.SizeToContent();   //使按钮适应图片大小
m_cookermenu_fresh.LoadBitmaps(IDB_BITMAPcookermenu_fresh1,IDB_BITMAPcookermenu_fresh2);   //载入  
m_cookermenu_fresh.SizeToContent();   //使按钮适应图片大小	
	// TODO: Add extra initialization here
	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_cookermenu)),TRUE);
	CString tableID;
	CString strSql;
	CString strDishesUse;
	strSql.Format("SELECT * FROM TableUse WHERE TableUseID = %d", 1);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	if (m_pRs->GetRecordCount() == 0)
		return true;
	if (m_pRs->GetRecordCount() == 1)
	{
		tableID = (char*)(_bstr_t)m_pRs->GetCollect("TableID");
		m_tableID.AddString(tableID);
		return true;
	}

	while (m_pRs->adoEOF == 0)
	{
		tableID = (char*)(_bstr_t)m_pRs->GetCollect("TableID");
		m_tableID.AddString(tableID);
		m_pRs->MoveNext();
	}

	m_pRs = NULL;
	m_listcookerdishes.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_listcookerdishes.InsertColumn(0, "桌号");
	m_listcookerdishes.InsertColumn(1, "菜名");
	m_listcookerdishes.InsertColumn(2, "数量");

	CRect rect;
	m_listcookerdishes.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listcookerdishes.SetColumnWidth(0, wide*1/6);
	m_listcookerdishes.SetColumnWidth(1, wide*2/6);
	m_listcookerdishes.SetColumnWidth(2, wide*1/6);
	flag = FALSE;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Ccookermenu::OnEditcookerdishes() 
{
	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;
	CString strDishesUse;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	CString strSql;
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" ";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listcookerdishes.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
	
		
		m_listcookerdishes.InsertItem(0, "");
		m_listcookerdishes.SetItemText(0, 0, strTableID);
		m_listcookerdishes.SetItemText(0, 1, strDishesName);
		m_listcookerdishes.SetItemText(0, 2, strDishesNum );
		m_pRs->MoveNext();
	}
	flag = TRUE;
	UpdateData(false);// TODO: Add your control notification handler code here
	
}

void Ccookermenu::OnSelchangecookerdishes() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	CString strSql;
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" and DishesUse=0";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listcookerdishes.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		//strConsumption = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
			if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
	//	strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
	//	consumption = atof(strConsumption);
	//	consumptionTemp += consumption;
		
		
	//	strConsumption.Format("%0.2f", consumption);
		m_listcookerdishes.InsertItem(0, "");
		m_listcookerdishes.SetItemText(0, 0, strTableID);
		m_listcookerdishes.SetItemText(0, 1, strDishesName);
		m_listcookerdishes.SetItemText(0, 2, strDishesNum );
		
		//m_listShowOrder.SetItemText(0, 3, strConsumption);
		m_pRs->MoveNext();
	}
	
//	strTotleConsumption.Format("%0.2f", consumptionTemp);
//	m_payOrder.SetWindowText(strTotleConsumption);
	flag = TRUE;
	UpdateData(false);


	
}
