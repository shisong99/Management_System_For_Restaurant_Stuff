// GoodsSelect.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "GoodsSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoodsSelect dialog


CGoodsSelect::CGoodsSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CGoodsSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoodsSelect)
	//}}AFX_DATA_INIT
}


void CGoodsSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoodsSelect)
	DDX_Control(pDX, IDC_bntQuery, m_goodsselect_query);
	DDX_Control(pDX, IDC_bntCancel, m_goodsselect_cancel);
	DDX_Control(pDX, IDC_stockYear, m_stockYear);
	DDX_Control(pDX, IDC_stockMonth, m_stockMonth);
	DDX_Control(pDX, IDC_stockDay, m_stockDay);
	DDX_Control(pDX, IDC_listShowGoods, m_listShowGoods);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoodsSelect, CDialog)
	//{{AFX_MSG_MAP(CGoodsSelect)
	ON_BN_CLICKED(IDC_bntQuery, OnbntQuery)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsSelect message handlers

BOOL CGoodsSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_goodsselect_cancel.LoadBitmaps(IDB_BITMAPgoodsselect_cancel1,IDB_BITMAPgoodsselect_cancel2);   //载入  
    m_goodsselect_cancel.SizeToContent();   //使按钮适应图片大小
	m_goodsselect_query.LoadBitmaps(IDB_BITMAPgoodsselect_query1,IDB_BITMAPgoodsselect_query2);   //载入  
    m_goodsselect_query.SizeToContent();   //使按钮适应图片大小
	CString strSql;
	CString strYear;
	CString strMonth;
	CString strDay;

	strSql = "SELECT distinct Year(StockTime) as 年份 FROM StockInfo";
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strYear = (char*)(_bstr_t)m_pRs->GetCollect("年份");
		m_stockYear.AddString(strYear);
		m_pRs->MoveNext();
	}

	strSql.Format("SELECT distinct Month(StockTime) as 月份 FROM StockInfo");
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strMonth = (char*)(_bstr_t)m_pRs->GetCollect("月份");
		m_stockMonth.AddString(strMonth);
		m_pRs->MoveNext();
	}

	strSql.Format("SELECT distinct Day(StockTime) as 日期 FROM StockInfo");
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strDay = (char*)(_bstr_t)m_pRs->GetCollect("日期");
		m_stockDay.AddString(strDay);
		m_pRs->MoveNext();
	}
	
	m_listShowGoods.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowGoods.InsertColumn(0, "商品名");
	m_listShowGoods.InsertColumn(1, "数量(斤)");
	m_listShowGoods.InsertColumn(2, "价格(元)");
	
	CRect rect;
	m_listShowGoods.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowGoods.SetColumnWidth(0, wide/3);
	m_listShowGoods.SetColumnWidth(1, wide/3);
	m_listShowGoods.SetColumnWidth(2, wide/3);

	return TRUE;  
}

void CGoodsSelect::OnbntQuery() 
{
	UpdateData();

	m_listShowGoods.DeleteAllItems();
	CString strYear;
	CString strMonth;
	CString strDay;
	CString strTotleIncome;
	CString strGoodsName;
	CString strGoodsNum;
	CString strGoodsPrice;


	int i;
	int j;
	int k;
	i = m_stockYear. GetCurSel();
	j = m_stockMonth.GetCurSel();
	k = m_stockDay.  GetCurSel();

	if (i == -1 || j == -1 || k == -1)
	{
		AfxMessageBox("您还没有选择好时间呢");
		return ;
	
	}

	m_stockYear.GetLBText (i,  strYear);
	m_stockMonth.GetLBText(j, strMonth);
	m_stockDay.GetLBText  (k,   strDay);

	CString strSql;
	strSql.Format("SELECT * FROM StockInfo WHERE Year(StockTime) = '%s'AND Month(StockTime) = '%s'AND Day(StockTime) = '%s'",\
		strYear, strMonth, strDay);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strGoodsName  = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName" );
		strGoodsNum   = (char*)(_bstr_t)m_pRs->GetCollect( "GoodsNum" );
		strGoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");

		m_listShowGoods.InsertItem(0, strGoodsName);
		m_listShowGoods.SetItemText(0, 1, strGoodsNum);
		m_listShowGoods.SetItemText(0, 2, strGoodsPrice);
		m_pRs->MoveNext();

	}


}

void CGoodsSelect::OnbntCancel() 
{
		CDialog::OnCancel();
	
}
