// BuyGoods.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "BuyGoods.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBuyGoods dialog


CBuyGoods::CBuyGoods(CWnd* pParent /*=NULL*/)//初始化表管他
	: CDialog(CBuyGoods::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuyGoods)
	m_buyTime = _T("");
	//}}AFX_DATA_INIT
	totlePrice = 0;
}


void CBuyGoods::DoDataExchange(CDataExchange* pDX)//按钮ID与对应的变量成员
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBuyGoods)
	DDX_Control(pDX, IDC_bntReset, m_bntReset);
	DDX_Control(pDX, IDC_bntOK, m_bntOK);
	DDX_Control(pDX, IDC_goodsSub, m_goodssub);
	DDX_Control(pDX, IDC_goodsAdd, m_goodsadd);
	DDX_Control(pDX, IDC_bntCancel, m_buygoods_exit);
	DDX_Control(pDX, IDC_totlePrice, m_totlePrice);
	DDX_Control(pDX, IDC_listShowSelect, m_listShowSelect);
	DDX_Control(pDX, IDC_listShowGoods, m_listShowGoods);
	DDX_Control(pDX, IDC_goodsNum, m_goodsNum);
	DDX_Text(pDX, IDC_buyTime, m_buyTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBuyGoods, CDialog)//按钮ID与对应的响应函数
	//{{AFX_MSG_MAP(CBuyGoods)
	ON_BN_CLICKED(IDC_bntOK, OnbntOK)
	ON_BN_CLICKED(IDC_bntReset, OnbntReset)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	ON_BN_CLICKED(IDC_goodsAdd, OngoodsAdd)
	ON_BN_CLICKED(IDC_goodsSub, OngoodsSub)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBuyGoods message handlers

BOOL CBuyGoods::OnInitDialog() 
{


	CDialog::OnInitDialog();
	//////////////////////////////////////////////
m_buygoods_exit.LoadBitmaps(IDB_BITMAPbuygoods_exit1,IDB_BITMAPbuygoods_exit2);   //载入  
m_buygoods_exit.SizeToContent();   //使按钮适应图片大小
m_bntOK.LoadBitmaps(IDB_BITMAPbuygoods_ensure1,IDB_BITMAPbuygoods_ensure2);   //载入  
m_bntOK.SizeToContent();   //使按钮适应图片大小
m_bntReset.LoadBitmaps(IDB_BITMAPbuygoods_reset1,IDB_BITMAPbuygoods_reset2);   //载入  
m_bntReset.SizeToContent();   //使按钮适应图片大小
m_goodsadd.LoadBitmaps(IDB_BITMAPbuygoods_right1,IDB_BITMAPbuygoods_right2);   //载入  
m_goodsadd.SizeToContent();   //使按钮适应图片大小
m_goodssub.LoadBitmaps(IDB_BITMAPbuygoods_left1,IDB_BITMAPbuygoods_left2);   //载入  
m_goodssub.SizeToContent();   //使按钮适应图片大小
///////////////////////////////////////////////////
	CTime time;
	time = CTime::GetCurrentTime();
	m_buyTime = time.Format("%Y-%m-%d");
	UpdateData(FALSE);
	m_listShowGoods.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowGoods.InsertColumn(0, "商品名");
	m_listShowGoods.InsertColumn(1, "单价(元)");
	//m_listShowGoods.InsertColumn(2, "单价(元)");
	
	m_listShowGoods.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowGoods.SetColumnWidth(0, wide/2);
	m_listShowGoods.SetColumnWidth(1, wide/2);
	//m_listShowGoods.SetColumnWidth(2, wide/3);

	m_AdoConn.OnInitADOConn();
	CString strSql;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//关键的连接数据库的语句！！！！！！！找到啦~~~~
	strSql = "SELECT * FROM GoodsInfo";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)//没啥错误
	{
		CString GoodsName;
		CString GoodsPrice;
		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");//这是把数据嵌入列表的意思
		m_listShowGoods.SetItemText(0, 0, GoodsName);//这是指明数据嵌入列表何处的意思
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		m_pRs->MoveNext();//换行，也就是说这些事一个一个显示的
	}


	m_listShowSelect.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowSelect.InsertColumn(0, "商品名");
	m_listShowSelect.InsertColumn(1, "数量(斤)");
	m_listShowSelect.GetWindowRect(&rect);
	
	wide = rect.right - rect.left;
	m_listShowSelect.SetColumnWidth(0, wide/2);
	m_listShowSelect.SetColumnWidth(1, wide/2);
	m_totlePrice.SetWindowText("0");//这边都是默认的
	m_goodsNum.SetWindowText("1");

	return TRUE;  
}

void CBuyGoods::OnbntOK() 
{

	AfxMessageBox("货物更新成功");
	CDialog::OnOK();

	
}

void CBuyGoods::OnbntReset() 
{
	m_listShowSelect.DeleteAllItems();
	m_totlePrice.SetWindowText("0");
	totlePrice = 0;
	
}

void CBuyGoods::OnbntCancel() 
{
	CDialog::OnCancel();
	
}

void CBuyGoods::OngoodsAdd() 
{
	
	UpdateData(TRUE);
	
	int n = -1;
	n= m_listShowGoods.GetSelectionMark();//读取是否选择，n取0~*

	

	if (n == -1)
	{
		AfxMessageBox("请选择商品");
		return ;
	}

	CString GoodsName;
	CString GoodsPrice;
	CString GoodsNum;
	GoodsName = m_listShowGoods.GetItemText(n, 0);//是行号和列号
	GoodsPrice = m_listShowGoods.GetItemText(n, 1);
	
	
	m_goodsNum.GetWindowText(GoodsNum);
	
	if (GoodsNum.IsEmpty() || GoodsNum == "0")
	{
		AfxMessageBox("请选择商品");
		return ;
	}
	
	CString strSql;
	strSql.Format("SELECT * FROM StockInfo WHERE GoodsName = '%s' AND StockTime ='%s' ", GoodsName, m_buyTime);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	if (m_pRs->adoEOF)
	{
		strSql.Format(	"INSERT INTO StockInfo(StockTime, GoodsName, GoodsNum, GoodsPrice) VALUES('%s', '%s', %d, %f)",m_buyTime,GoodsName,atoi(GoodsNum),atof(GoodsPrice));
	}
	else
	{
		strSql.Format("UPDATE StockInfo SET GoodsNum = GoodsNum + %d WHERE GoodsName = '%s' AND StockTime = '%s'", atoi(GoodsNum), GoodsName, m_buyTime);
	}

	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	m_listShowSelect.DeleteAllItems();
	strSql.Format("SELECT * FROM StockInfo WHERE StockTime = '%s'", m_buyTime);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	double totlePrice = 0;
	
	while (m_pRs->adoEOF == 0)
	{
		GoodsName  =  (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsNum   =  (char*)(_bstr_t)m_pRs->GetCollect("GoodsNum");
		GoodsPrice =  (char*)(_bstr_t) m_pRs->GetCollect("GoodsPrice");
		totlePrice += atof(GoodsPrice)*atoi(GoodsNum);
		
		m_listShowSelect.InsertItem(0, "");
		m_listShowSelect.SetItemText(0, 0, GoodsName);
		m_listShowSelect.SetItemText(0, 1, GoodsNum);
		
		m_pRs->MoveNext();
	}


	CString strTotlePrice;
	strTotlePrice.Format("%0.2f",totlePrice);
	m_totlePrice.SetWindowText(strTotlePrice);

	m_listShowGoods.SetSelectionMark(-1);
	m_listShowGoods.GetWindowRect(&rect);
	m_listShowGoods.InvalidateRect(&rect, FALSE);
	UpdateData(FALSE);



}

void CBuyGoods::OngoodsSub() 
{
	UpdateData(TRUE);

	CString strTotlePrice;
	m_totlePrice.GetWindowText(strTotlePrice);
	totlePrice = atof(strTotlePrice);
	int n = m_listShowSelect.GetSelectionMark();
	CString GoodsName = m_listShowSelect.GetItemText(n, 0);
	CString GoodsNum = m_listShowSelect.GetItemText(n, 1);
	CString strGoodsNum ;
	m_goodsNum.GetWindowText(strGoodsNum);
	
	CString strSql;

	CString GoodsPrice;
	int count ;
	count = atoi(GoodsNum) - atoi(strGoodsNum) ;

	if (count <= 0)
	{
		AfxMessageBox(GoodsName);
		strSql.Format("DELETE FROM StockInfo WHERE StockTime = '%s' AND GoodsName = '%s' ", m_buyTime, GoodsName);

	}
	else
	{	
		strSql.Format("UPDATE StockInfo SET GoodsNum = %d WHERE StockTime = '%s' AND GoodsName = '%s' ", count, m_buyTime, GoodsName);

	}
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	
	m_listShowSelect.DeleteAllItems();
	
	strSql.Format("SELECT * FROM StockInfo WHERE StockTime = '%s'", m_buyTime);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	double totlePrice = 0;
	while (m_pRs->adoEOF == 0)
	{
		GoodsName  =  (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsNum   =  (char*)(_bstr_t)m_pRs->GetCollect("GoodsNum");
		GoodsPrice =  (char*)(_bstr_t) m_pRs->GetCollect("GoodsPrice");
		totlePrice += atof(GoodsPrice)*atoi(GoodsNum);
		
		m_listShowSelect.InsertItem(0, "");
		m_listShowSelect.SetItemText(0, 0, GoodsName);
		m_listShowSelect.SetItemText(0, 1, GoodsNum);
		
		m_pRs->MoveNext();
	}
	
	
	strTotlePrice.Format("%0.2f",totlePrice);
	m_totlePrice.SetWindowText(strTotlePrice);

	m_listShowSelect.SetSelectionMark(-1);
	m_listShowSelect.GetWindowRect(&rect);
	m_listShowSelect.InvalidateRect(&rect, FALSE);
	UpdateData(FALSE);


	
}
