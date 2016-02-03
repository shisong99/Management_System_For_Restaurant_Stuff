// SelectDishes.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "SelectDishes.h"
#include "DishesNum.h"
#include "Register.h"
#include "DishesTotle.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectDishes dialog


CSelectDishes::CSelectDishes(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectDishes::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectDishes)
	m_tableID = _T("");
	//}}AFX_DATA_INIT
}


void CSelectDishes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectDishes)
	DDX_Control(pDX, IDR_MENU_pay, m_pay);
	DDX_Control(pDX, IDC_Cancel, m_sd_cancelb);
	DDX_Control(pDX, IDC_btnSelect, m_sd_select);
	DDX_Control(pDX, IDC_btnOK, m_sd_OK);
	DDX_Control(pDX, IDC_btnCancel, m_sd_cancel);
	DDX_Control(pDX, IDC_listSelect, m_listShowSelect);
	DDX_Control(pDX, IDC_listShowDishes, m_listShowDishes);
	DDX_Text(pDX, IDC_tablesID, m_tableID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectDishes, CDialog)
	//{{AFX_MSG_MAP(CSelectDishes)
	ON_BN_CLICKED(IDC_btnSelect, OnbtnSelect)
	ON_BN_CLICKED(IDC_btnCancel, OnbtnCancel)
	ON_BN_CLICKED(IDC_btnOK, OnbtnOK)
	ON_NOTIFY(HDN_ITEMCHANGED, IDC_listShowDishes, OnItemchangedlistShowDishes)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_Cancel, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectDishes message handlers

BOOL CSelectDishes::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_sd_OK.LoadBitmaps(IDB_BITMAPsd_OK1,IDB_BITMAPsd_OK2);   //载入  
    m_sd_OK.SizeToContent();   //使按钮适应图片大小
	m_sd_cancel.LoadBitmaps(IDB_BITMAPsd_cancel1,IDB_BITMAPsd_cancel2);   //载入  
    m_sd_cancel.SizeToContent();   //使按钮适应图片大小
	m_sd_cancelb.LoadBitmaps(IDB_BITMAPsd_cancelb1,IDB_BITMAPsd_cancelb2);   //载入  
    m_sd_cancelb.SizeToContent();   //使按钮适应图片大小
	m_pay.LoadBitmaps(IDB_BITMAPsd_pay1,IDB_BITMAPsd_pay2);   //载入  
    m_pay.SizeToContent();   //使按钮适应图片大小
	m_sd_select.LoadBitmaps(IDB_BITMAPsd_select2,IDB_BITMAPsd_select1);   //载入  
    m_sd_select.SizeToContent();   //使按钮适应图片大小
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_order)),TRUE);
	
	m_listShowDishes.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | \
	LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_listShowDishes.InsertColumn(0, "菜名");
	m_listShowDishes.InsertColumn(1, "菜价(元)");
	CRect rect;
	m_listShowDishes.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowDishes.SetColumnWidth(0, wide*4/6);
	m_listShowDishes.SetColumnWidth(1, wide*2/6);
	
//	CString strSql = "SELECT * FROM DishesInfo";
//	m_AdoConn.OnInitADOConn();
//	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

//	while (m_pRs->adoEOF == 0)
//	{
//		CString dishesName;
//		CString dishesPrice;
//		dishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
//		dishesPrice =(char*)(_bstr_t) m_pRs->GetCollect("DishesPrice");

//		m_listShowDishes.InsertItem(0, dishesName);
//		m_listShowDishes.SetItemText(0, 1, dishesPrice);
//		m_pRs->MoveNext();
	
//	}


	m_listShowSelect.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowSelect.InsertColumn(0, "菜名");
	m_listShowSelect.InsertColumn(1, "数量");
	m_listShowSelect.GetWindowRect(&rect);
	wide = rect.right - rect.left;
	m_listShowSelect.SetColumnWidth(0, wide*4/6);
	m_listShowSelect.SetColumnWidth(1, wide*2/6);

	//strSql.Format

	
	return TRUE;  
}

void CSelectDishes::OnbtnSelect() 
{

	CDishesNum dlg;
	int i;
	i = m_listShowDishes.GetSelectionMark();

	if (i == -1)
	{
		AfxMessageBox("请选择您要点的菜");
		return ;
	}

	if (dlg.DoModal() == IDOK)
	{

		CString dishesName = m_listShowDishes.GetItemText(i, 0);
		CString strSql;
		
		int n = m_listShowSelect.GetItemCount();
		for (i=0; i<n; i++)
		{
			CString dishesNameSelect = m_listShowSelect.GetItemText(i, 0);
			if (dishesNameSelect == dishesName)
			{
				MessageBox(dishesName+"该菜能刚才已经点过了，如果想修改数量，请稍后到修改菜单表里面修改！", "系统提示", MB_YESNO);
				return ;
			}
		}
	
		m_listShowSelect.InsertItem(0, "");
		m_listShowSelect.SetItemText(0, 0, dishesName);
		m_listShowSelect.SetItemText(0, 1, dlg.m_dishesNum);
	
	}

	m_listShowDishes.SetSelectionMark(-1);

}

void CSelectDishes::OnbtnCancel() 
{
	int i;
	i = m_listShowSelect.GetSelectionMark();
	m_listShowSelect.DeleteItem(i);
	m_listShowSelect.SetSelectionMark(-1);
	/*UpdateData(TRUE);
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
m_listShowSelect.SetSelectionMark(-1);.*/

}

void CSelectDishes::OnbtnOK() 
{
	UpdateData(TRUE);
	CString strSql;
	int i = m_listShowSelect.GetItemCount();

	if (i == 0)
	{
		AfxMessageBox("请点菜");
		return;
	}

	 tableID = atoi(m_tableID);
	strSql.Format("UPDATE TableUse SET TableUseID = 1 WHERE TableID = %d",tableID);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
	CString dishesName;
	CString dishesNum;
	CString dishesPrice;
	CString strSql1;
	double totlePrice;
	
	int n;
	for (n=0; n<i; n++)
	{
		dishesName = m_listShowSelect.GetItemText(n, 0);
		dishesNum  = m_listShowSelect.GetItemText(n, 1);
		int num = atoi(dishesNum);
		strSql.Format("SELECT * FROM DishesInfo WHERE DishesName = '%s'",dishesName);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
		dishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		totlePrice = atof(dishesPrice) * num;
		CString totle;
		totle = (char*)(_bstr_t)totlePrice;

		
			
		strSql1.Format("INSERT INTO PayOrder (DishesName, UseTableID, DishesNum, Consumption,DishesUse) VALUES('%s', '%s', %d, %f,0)", dishesName, m_tableID, num, totlePrice);
		//strSql1 = "insert into PayOrder(, DishesName, DishesNum, Consumtion) values("+m_tableID+",'"+dishesName+"',"+dishesNum+","+totle+"";
		
		m_AdoConn.ExecuteSQL((_bstr_t)strSql1);
	//	strSql.Format(	"INSERT INTO StockInfo(StockTime, GoodsName, GoodsNum, GoodsPrice) VALUES('%s', '%s', %d, %f)",m_buyTime,GoodsName,atoi(GoodsNum),atof(GoodsPrice));

	}

	AfxMessageBox("点菜成功");
	CDialog::OnOK();

}

void CSelectDishes::OnCancel() 
{
	CDialog::OnCancel();
	
}

void CSelectDishes::OnItemchangedlistShowDishes(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;

	
	*pResult = 0;
}

void CSelectDishes::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void CSelectDishes::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	/*m_listShowDishes.DeleteItem(2);
	m_listShowDishes.DeleteItem(1);
	m_listShowDishes.DeleteItem(0);
	m_listShowDishes.InsertItem(0, "汉堡");
	m_listShowDishes.SetItemText(0, 1, "10");
	m_listShowDishes.InsertItem(1, "薯条");
	m_listShowDishes.SetItemText(1, 1, "8");
	m_listShowDishes.InsertItem(2, "土豆泥");
	m_listShowDishes.SetItemText(2, 1, "8");*/
	/////////////////////////////////////////////////////////////
	m_listShowDishes.DeleteAllItems();
	CString strSql;
	// tableID = atoi(m_tableID);
	strSql.Format("SELECT * FROM DishesInfo WHERE DishType = %d",1);
//	strSql.Format("SELECT * FROM VIP WHERE memberID =%d",atoi(strmemberID));
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	CString strdishesName;
	//CString strdishesNum;
	CString strdishesPrice;
	while (m_pRs->adoEOF == 0)//没啥错误
	{
	//	CString strmemberID;
	//	CString strmemberName;
	//	CString strmemberLV;
		strdishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strdishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");//这是把数据嵌入列表的意思
		m_listShowDishes.SetItemText(0, 0, strdishesName);//这是指明数据嵌入列表何处的意思
		m_listShowDishes.SetItemText(0, 1, strdishesPrice);
		m_pRs->MoveNext();//换行，也就是说这些事一个一个显示的
	}
//UpdateData(true);
}


void CSelectDishes::OnRadio2() 
{
	// TODO: Add your control notification handler code here
/*	m_listShowDishes.DeleteItem(2);
	m_listShowDishes.DeleteItem(1);
	m_listShowDishes.DeleteItem(0);
	m_listShowDishes.InsertItem(0, "圣代");
	m_listShowDishes.SetItemText(0, 1, "8");	*/
//UpdateData(true);
		m_listShowDishes.DeleteAllItems();
	CString strSql;
	// tableID = atoi(m_tableID);
	strSql.Format("SELECT * FROM DishesInfo WHERE DishType = %d",3);
//	strSql.Format("SELECT * FROM VIP WHERE memberID =%d",atoi(strmemberID));
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	CString strdishesName;
	//CString strdishesNum;
	CString strdishesPrice;
	while (m_pRs->adoEOF == 0)//没啥错误
	{
	//	CString strmemberID;
	//	CString strmemberName;
	//	CString strmemberLV;
		strdishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strdishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");//这是把数据嵌入列表的意思
		m_listShowDishes.SetItemText(0, 0, strdishesName);//这是指明数据嵌入列表何处的意思
		m_listShowDishes.SetItemText(0, 1, strdishesPrice);
		m_pRs->MoveNext();//换行，也就是说这些事一个一个显示的
	}
}

void CSelectDishes::OnRadio3() 
{
/*	m_listShowDishes.DeleteItem(2);
	m_listShowDishes.DeleteItem(1);
	m_listShowDishes.DeleteItem(0);
	m_listShowDishes.InsertItem(0, "可乐");
	m_listShowDishes.SetItemText(0, 1, "7");	*/

//UpdateData(true);
		m_listShowDishes.DeleteAllItems();
	CString strSql;
	// tableID = atoi(m_tableID);
	strSql.Format("SELECT * FROM DishesInfo WHERE DishType = %d",2);
//	strSql.Format("SELECT * FROM VIP WHERE memberID =%d",atoi(strmemberID));
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	CString strdishesName;
	//CString strdishesNum;
	CString strdishesPrice;
	while (m_pRs->adoEOF == 0)//没啥错误
	{
	//	CString strmemberID;
	//	CString strmemberName;
	//	CString strmemberLV;
		strdishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strdishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		m_listShowDishes.InsertItem(0, "");//这是把数据嵌入列表的意思
		m_listShowDishes.SetItemText(0, 0, strdishesName);//这是指明数据嵌入列表何处的意思
		m_listShowDishes.SetItemText(0, 1, strdishesPrice);
		m_pRs->MoveNext();//换行，也就是说这些事一个一个显示的
	}
}
