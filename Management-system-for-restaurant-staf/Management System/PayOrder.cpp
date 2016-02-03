// PayOrder.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "PayOrder.h"
#include "member.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPayOrder dialog


CPayOrder::CPayOrder(CWnd* pParent /*=NULL*/)
	: CDialog(CPayOrder::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPayOrder)
	//}}AFX_DATA_INIT
}


void CPayOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPayOrder)
	DDX_Control(pDX, IDC_festivallist, m_festivallist);
	DDX_Control(pDX, IDC_afterdiscount, m_afterdiscount);
	DDX_Control(pDX, IDC_discount, m_discount);
	DDX_Control(pDX, IDC_bntOK, m_pay_OK);
	DDX_Control(pDX, IDC_receiver, m_receiver);
	DDX_Control(pDX, IDC_surplus, m_surplus);
	DDX_Control(pDX, IDC_payOrder, m_payOrder);
	DDX_Control(pDX, IDC_listShowOrder, m_listShowOrder);
	DDX_Control(pDX, IDC_tableID, m_tableID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPayOrder, CDialog)
	//{{AFX_MSG_MAP(CPayOrder)
	ON_BN_CLICKED(IDC_bntOK, OnbntOK)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	ON_CBN_SELCHANGE(IDC_tableID, OnSelchangetableID)
	ON_EN_CHANGE(IDC_receiver, OnChangereceiver)
	ON_CBN_EDITCHANGE(IDC_tableID, OnEditchangetableID)
	ON_EN_CHANGE(IDC_discount, OnChangediscount)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPayOrder message handlers

void CPayOrder::OnbntOK() 
{
	UpdateData();
	CString strSql;
	CString tableID;
	CString payOrder;//应收
	CString receiver;//实收
	CString strafterdiscount;
	CString strSurplus;//找零
	m_tableID.GetWindowText(tableID);
	
	strSql = "SELECT * FROM TableUse WHERE TableID = "+tableID+"";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	
	if (m_pRs->adoEOF)
	{
		AfxMessageBox("没有这张桌子");
		return;
	}
	
	CString tableUseID;
	tableUseID = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	if (tableUseID == "0")
	{
		AfxMessageBox("此桌已经付过");
		return ;
	}

	m_receiver.GetWindowText(receiver);
	if (receiver.IsEmpty())
	{
		AfxMessageBox("请您付款");
	}

	if (flag == TRUE)
		m_tableID.GetWindowText(tableID);
	else
		m_tableID.GetLBText(m_tableID.GetCurSel(), tableID);
	
	m_surplus.SetWindowText("");

	double surplus;
	double dayIncome = 0;
	m_receiver.GetWindowText(receiver);
	m_payOrder.GetWindowText(payOrder);
	m_afterdiscount.GetWindowText(strafterdiscount);
	dayIncome = atof(strafterdiscount);

	if (atof(strafterdiscount) > atof(receiver))
	{
		AfxMessageBox("所付金额不够");
		return ;
	}
	else
	{
		CTime time;
		time = CTime::GetCurrentTime();
		CString strTime = time.Format("%Y-%m-%d");
		surplus = atof(receiver) - atof(strafterdiscount);
		strSurplus.Format("%f",surplus);
		m_surplus.SetWindowText(strSurplus);//生成找零
		
		strSql.Format("UPDATE TableUse SET TableUseID = 0 WHERE TableID = %d", atoi(tableID) );
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
		CString strDayIncome;
		strDayIncome.Format("%0.2f", dayIncome);
		strSql.Format("SELECT * FROM Income WHERE IncomeTime = '%s'", strTime);
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

		if (m_pRs->adoEOF)
		{
			strSql.Format("INSERT INTO Income(DayIncome, IncomeTime) VALUES(%f, '%s')", dayIncome, strTime);

		}
		else
		{
			strSql = "UPDATE Income SET DayIncome = DayIncome +"+strDayIncome+" WHERE IncomeTime = '"+strTime+"'";
		}
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
		m_payOrder.SetWindowText("");
		m_receiver.SetWindowText("");
		m_surplus.SetWindowText ("");
		m_tableID.SetWindowText ("");
		m_tableID.DeleteString(m_tableID.GetCurSel());
		m_listShowOrder.DeleteAllItems();
		strSql.Format("DELETE FROM PayOrder WHERE UseTableID = %d", atoi(tableID));
		
		BOOL success = m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		if ( success == TRUE)
		{
			
			AfxMessageBox(tableID+"号桌客人付账成功,谢谢您的惠顾,欢迎再次光临!");
		}
		
	}

	


	


	
	
}

void CPayOrder::OnbntCancel() 
{
	CDialog::OnCancel();
	
}

BOOL CPayOrder::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pay_OK.LoadBitmaps(IDB_BITMAPpay_OK1,IDB_BITMAPpay_OK2);   //载入  
    m_pay_OK.SizeToContent();   //使按钮适应图片大小

	SetIcon(LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_payorder)),TRUE);
	CString tableID;
	CString strSql;
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
	m_listShowOrder.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_listShowOrder.InsertColumn(0, "菜名");
	m_listShowOrder.InsertColumn(1, "菜价");
	m_listShowOrder.InsertColumn(2, "数量");
	m_listShowOrder.InsertColumn(3, "消费(元)");

	CRect rect;
	m_listShowOrder.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowOrder.SetColumnWidth(0, wide*2/6);
	m_listShowOrder.SetColumnWidth(1, wide*1/6);
	m_listShowOrder.SetColumnWidth(2, wide*1/6);
	m_listShowOrder.SetColumnWidth(3, wide*2/6);
	flag = FALSE;
/////////////////////////////////////////////////
	m_festivallist.SetExtendedStyle(LVS_EX_FLATSB | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_festivallist.InsertColumn(0, "月");
	m_festivallist.InsertColumn(1, "日");
	m_festivallist.InsertColumn(2, "节日名");
	m_festivallist.InsertColumn(3, "KFC温馨提示");
    m_festivallist.InsertColumn(4, "折扣");

	m_festivallist.GetWindowRect(&rect);
	wide = rect.right - rect.left;
	m_festivallist.SetColumnWidth(0, wide*1/10);
	m_festivallist.SetColumnWidth(1, wide*1/10);
	m_festivallist.SetColumnWidth(2, wide*1/10);
	m_festivallist.SetColumnWidth(3, wide*6/10);
	m_festivallist.SetColumnWidth(4, wide*1/10);
	////////////////////////////////////////////////////////////////////////////////////
    CTime time;
	time = CTime::GetCurrentTime();
	int month=time.GetMonth();
	int day=time.GetDay();
    strSql.Format("SELECT * FROM festival WHERE Month = %d and Day = %d", month, day);
	m_pRs1 = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	CString strmonth;
	CString strday;
	CString strname;
	CString strdescription;
	CString strfdiscount;
	while (m_pRs1->adoEOF == 0)
	{
	strmonth = (char*)(_bstr_t)m_pRs1->GetCollect("Month");
	strday = (char*)(_bstr_t)m_pRs1->GetCollect("Day");
	strname = (char*)(_bstr_t)m_pRs1->GetCollect("Name");
	strdescription = (char*)(_bstr_t)m_pRs1->GetCollect("Description");
	strfdiscount = (char*)(_bstr_t)m_pRs1->GetCollect("FDiscount");
	m_festivallist.InsertItem(0, "");
	m_festivallist.SetItemText(0, 0, strmonth);
	m_festivallist.SetItemText(0, 1, strday);
	m_festivallist.SetItemText(0, 2, strname );
	m_festivallist.SetItemText(0, 3, strdescription);
	m_festivallist.SetItemText(0, 4, strfdiscount);
	m_pRs1->MoveNext();
	}
	return TRUE;  
}

void CPayOrder::OnSelchangetableID() 
{
	UpdateData(TRUE);

	CString strTableID;
	CString strDishesName;
	CString strDishesNum;
	CString strConsumption;
	CString strTotleConsumption;
	CString strDishesPrice;
	double  consumption = 0;
	double  consumptionTemp = 0;

	m_tableID.GetLBText(m_tableID.GetCurSel(), strTableID);
	CString strSql;
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" ";

	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	m_listShowOrder.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		
		strConsumption = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
			if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PayOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
		strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		consumption = atof(strConsumption);
		consumptionTemp += consumption;//累加
		
		
		strConsumption.Format("%0.2f", consumption);//保留两位小数
		m_listShowOrder.InsertItem(0, "");
		m_listShowOrder.SetItemText(0, 0, strDishesName);
		m_listShowOrder.SetItemText(0, 1, strDishesPrice);
		m_listShowOrder.SetItemText(0, 2, strDishesNum );
		
		m_listShowOrder.SetItemText(0, 3, strConsumption);
		m_pRs->MoveNext();
	}//这个是分菜种的单种总价
	//////////////////////
	CTime time;
	time = CTime::GetCurrentTime();
	int month=time.GetMonth();
	int day=time.GetDay();
	strSql.Format("SELECT * FROM festival WHERE Month = %d and Day = %d", month, day);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	//CString strmonth;
	//CString strday;
	//CString strname;
	//CString strdescription;
	CString strfdiscount;
	//strmonth = (char*)(_bstr_t)m_pRs->GetCollect("Month");
	//strday = (char*)(_bstr_t)m_pRs->GetCollect("Day");
	//strname = (char*)(_bstr_t)m_pRs->GetCollect("Name");
	//strdescription = (char*)(_bstr_t)m_pRs->GetCollect("Description");
	strfdiscount = (char*)(_bstr_t)m_pRs->GetCollect("FDiscount");
	double discount=atof(strfdiscount);
	////////////////////////
	strTotleConsumption.Format("%0.2f", discount*consumptionTemp);//这才是总价
	m_payOrder.SetWindowText(strTotleConsumption);//m_payOrder现在就是总价了。会自动显示在那个Cedit里面
	flag = TRUE;
	UpdateData(false);


}

void CPayOrder::OnChangereceiver() //IDC_receiver如果实收款改变了就调用这个函数实收款
{

	double surplus;
	CString strReceiver;
	CString strPayOrder;
	CString strafterdiscount;
	m_receiver.GetWindowText(strReceiver);//取实收款
	m_payOrder.GetWindowText(strPayOrder);//取应收款
	m_afterdiscount.GetWindowText(strafterdiscount);//取应收款
	surplus = atof(strReceiver) - atof(strafterdiscount);//计算找零
	CString strSurplus;
	strSurplus.Format("%0.2f", surplus);//把双精度变成字符串
	m_surplus.SetWindowText(strSurplus);//显示找零款
}

void CPayOrder::OnEditchangetableID() 
{
	UpdateData(TRUE);
	
	CString strTableID;
	CString strDishesName;
	CString strDishesNum;
	CString strConsumption;
	CString strTotleConsumption;
	CString strDishesPrice;
	double  consumption = 0;
	double  consumptionTemp = 0;
	m_listShowOrder.DeleteAllItems();
	m_payOrder.SetWindowText("");
	m_tableID.GetWindowText(strTableID);
	CString strSql;
	strSql = "SELECT * FROM PayOrder,DishesInfo WHERE DishesInfo.DishesName=PayOrder.DishesName and UseTableID = "+strTableID+" ";
	AfxMessageBox("dd");
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	AfxMessageBox("dda");
	m_listShowOrder.DeleteAllItems();
	
	while (m_pRs->adoEOF == 0)
	{
		strConsumption = (char*)(_bstr_t)m_pRs->GetCollect("Consumption");
		if (m_AdoConn.m_databaseFlag == 0)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("PaytOrder.DishesName");
		if (m_AdoConn.m_databaseFlag == 1)
			strDishesName = (char*)(_bstr_t)m_pRs->GetCollect("DishesName");
		strDishesNum  = (char*)(_bstr_t)m_pRs->GetCollect("DishesNum");
		strDishesPrice = (char*)(_bstr_t)m_pRs->GetCollect("DishesPrice");
		consumption = atof(strConsumption);
		consumptionTemp += consumption;
		strConsumption.Format("%0.2f", consumption);
		m_listShowOrder.InsertItem(0, "");
		m_listShowOrder.SetItemText(0, 0, strDishesName);
		m_listShowOrder.SetItemText(0, 1, strDishesPrice);
		m_listShowOrder.SetItemText(0, 2, strDishesNum );
		
		m_listShowOrder.SetItemText(0, 3, strConsumption);
		m_pRs->MoveNext();
	}
	
	strTotleConsumption.Format("%0.2f", consumptionTemp);
	m_payOrder.SetWindowText(strTotleConsumption);
	flag = TRUE;
	UpdateData(false);
}

void CPayOrder::OnOK()
{
	OnbntOK();
}



void CPayOrder::OnChangediscount() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString strdiscount;
	CString strpayOrder;
	CString strtotalPrice;
	double discount;
	double payOrder;
	double totalPrice;
	// TODO: Add your control notification handler code here
	m_discount.GetWindowText(strdiscount);//把输入的字符串读到编辑框变量里，就可以显示了
	m_payOrder.GetWindowText(strpayOrder);
    discount=atof(strdiscount);//把字符串格式转换成双精度型
	payOrder=atof(strpayOrder);
	totalPrice=payOrder*discount;
	strtotalPrice.Format("%0.2f", totalPrice);
	m_afterdiscount.SetWindowText(strtotalPrice);
}
