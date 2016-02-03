// GoodsInfo.cpp : implementation file
//

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "GoodsInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGoodsInfo dialog


CGoodsInfo::CGoodsInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CGoodsInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGoodsInfo)
	m_goodsPrice = 0.0f;
	m_goodsName = _T("");
	//}}AFX_DATA_INIT
}


void CGoodsInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGoodsInfo)
	DDX_Control(pDX, IDC_bntUpdate, m_goodsinfo_update);
	DDX_Control(pDX, IDC_bntDelete, m_goodsinfo_delete);
	DDX_Control(pDX, IDC_bntCancel, m_goodsinfo_cancel);
	DDX_Control(pDX, IDC_bntADD, m_goodsinfo_add);
	DDX_Control(pDX, IDC_goodsName, m_goodsNameSelect);
	DDX_Control(pDX, IDC_listShowGoods, m_listShowGoods);
	DDX_Text(pDX, IDC_goodsPrice, m_goodsPrice);
	DDX_CBString(pDX, IDC_goodsName, m_goodsName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGoodsInfo, CDialog)
	//{{AFX_MSG_MAP(CGoodsInfo)
	ON_BN_CLICKED(IDC_bntADD, OnbntADD)
	ON_BN_CLICKED(IDC_bntUpdate, OnbntUpdate)
	ON_BN_CLICKED(IDC_bntDelete, OnbntDelete)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	ON_CBN_SELCHANGE(IDC_goodsName, OnSelchangegoodsName)
	ON_NOTIFY(NM_CLICK, IDC_listShowGoods, OnClicklistShowGoods)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGoodsInfo message handlers

BOOL CGoodsInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_goodsinfo_add.LoadBitmaps(IDB_BITMAPdishinfo_add1,IDB_BITMAPdishinfo_add2);   //载入  
    m_goodsinfo_add.SizeToContent();   //使按钮适应图片大小
	m_goodsinfo_update.LoadBitmaps(IDB_BITMAPdishinfo_update1,IDB_BITMAPdishinfo_update2);   //载入  
    m_goodsinfo_update.SizeToContent();   //使按钮适应图片大小
	m_goodsinfo_cancel.LoadBitmaps(IDB_BITMAPdishinfo_back1,IDB_BITMAPdishinfo_back2);   //载入  
    m_goodsinfo_cancel.SizeToContent();   //使按钮适应图片大小
	m_goodsinfo_delete.LoadBitmaps(IDB_BITMAPdishinfo_delete1,IDB_BITMAPdishinfo_delete2);   //载入  
    m_goodsinfo_delete.SizeToContent();   //使按钮适应图片大小
	m_listShowGoods.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowGoods.InsertColumn(0, "商品名");
	m_listShowGoods.InsertColumn(1, "单价(元)");
	CRect rect;
	m_listShowGoods.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowGoods.SetColumnWidth(0, wide/2);
	m_listShowGoods.SetColumnWidth(1, wide/2);

	m_AdoConn.OnInitADOConn();
	CString strSql;
	strSql = "SELECT * FROM GoodsInfo ";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		CString GoodsName;
		CString GoodsPrice;
		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");
		m_listShowGoods.SetItemText(0, 0, GoodsName);
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		m_goodsNameSelect.AddString(GoodsName);
		m_pRs->MoveNext();
	}

	return TRUE;  
}

void CGoodsInfo::OnbntADD() 
{
	UpdateData(TRUE);

	if (m_goodsName.IsEmpty())
	{
		AfxMessageBox("商品名不能为空");
		return ;
	}

	if(m_goodsPrice == 0)
	{
		AfxMessageBox("单价不能为空");
		return;
	}

	CString strSql;
	strSql.Format("SELECT * FROM GoodsInfo WHERE GoodsName = '%s'", m_goodsName);
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	if (m_pRs->adoEOF == 0)
	{
		AfxMessageBox("该商品已经有了，无需添加");
		return ;
	}

	
	strSql.Format("INSERT INTO GoodsInfo(GoodsName, GoodsPrice) VALUES('%s',%f)", m_goodsName, m_goodsPrice);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	m_goodsNameSelect.AddString(m_goodsName);
	AfxMessageBox(m_goodsName+"添加成功!");

	
	m_listShowGoods.DeleteAllItems();
	strSql = "SELECT * FROM GoodsInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	CString GoodsName;
	CString GoodsPrice;

	
	while (m_pRs->adoEOF == 0)
	{

		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");
		m_listShowGoods.SetItemText(0, 0, GoodsName);
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		
		m_pRs->MoveNext();
	}

	m_goodsPrice = 0;
	m_goodsName.Empty();
	UpdateData(FALSE);

}

void CGoodsInfo::OnbntUpdate() 
{
	UpdateData(TRUE);
	CString GoodsName;
	CString GoodsPrice;

	if (m_goodsName.IsEmpty())
	{
		AfxMessageBox("商品名不能为空");
		return ;
	}

	if(m_goodsPrice == 0)
	{
		AfxMessageBox("单价不能为空");
		return;
	}

	CString strSql;
	int i;
	i = m_goodsNameSelect.GetCurSel();
	m_goodsNameSelect.GetLBText(i, m_goodsName);
//	GoodsName = m_goodsName;
	strSql.Format("UPDATE GoodsInfo SET  GoodsPrice =%f WHERE GoodsName = '%s'", m_goodsPrice, m_goodsName);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	AfxMessageBox(m_goodsName+"更新成功!");

	m_listShowGoods.DeleteAllItems();
	strSql = "SELECT * FROM GoodsInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	

	
	while (m_pRs->adoEOF == 0)
	{

		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");
		m_listShowGoods.SetItemText(0, 0, GoodsName);
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		m_pRs->MoveNext();
	}

	m_goodsPrice = 0;
	m_goodsName.Empty();
	UpdateData(FALSE);

}

void CGoodsInfo::OnbntDelete() 
{
	UpdateData(TRUE);

	CString GoodsName;
	CString GoodsPrice;

	if (m_goodsName.IsEmpty())
	{
		AfxMessageBox("商品名不能为空");
		return ;
	}
	
	CString strSql;
	strSql.Format("DELETE FROM GoodsInfo WHERE GoodsName = '%s'", m_goodsName);
	m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	AfxMessageBox(m_goodsName+"删除成功!");
	
	
	m_listShowGoods.DeleteAllItems();
	strSql = "SELECT * FROM GoodsInfo";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);


	
	while (m_pRs->adoEOF == 0)
	{

		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");
		m_listShowGoods.SetItemText(0, 0, GoodsName);
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		
		m_pRs->MoveNext();
	}
	m_goodsNameSelect.DeleteString(m_goodsNameSelect.GetCurSel());
	m_goodsPrice = 0;
	m_goodsName.Empty();
	UpdateData(FALSE);
	
}

void CGoodsInfo::OnbntCancel() 
{
	CDialog::OnCancel();
}

void CGoodsInfo::OnSelchangegoodsName() 
{
	int i;
	i = m_goodsNameSelect.GetCurSel();
	CString GoodsName;
	m_goodsNameSelect.GetLBText(i, GoodsName);
	CString strGoodsPrice;

	CString strSql;
	strSql = "SELECT * FROM GoodsInfo WHERE GoodsName = '"+GoodsName+"'";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	strGoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");

	if (m_pRs->adoEOF == 0)
	{
		m_goodsPrice = atof(strGoodsPrice);
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox("不存在要删除的商品");
		return ;
	}
}

void CGoodsInfo::OnClicklistShowGoods(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int i=m_listShowGoods.GetSelectionMark();
	CString GoodsName=m_listShowGoods.GetItemText(i,0);
	CString strGoodsPrice=m_listShowGoods.GetItemText(i,1);
	double GoodsPrice;
	GoodsPrice = atof(strGoodsPrice);
	m_goodsName = GoodsName;
	m_goodsPrice = GoodsPrice;
	UpdateData(false);	

	*pResult = 0;
}

