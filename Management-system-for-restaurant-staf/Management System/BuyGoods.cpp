// BuyGoods.cpp : implementation file
//

#include "stdafx.h"
#include "��������ϵͳ.h"
#include "BuyGoods.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBuyGoods dialog


CBuyGoods::CBuyGoods(CWnd* pParent /*=NULL*/)//��ʼ�������
	: CDialog(CBuyGoods::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBuyGoods)
	m_buyTime = _T("");
	//}}AFX_DATA_INIT
	totlePrice = 0;
}


void CBuyGoods::DoDataExchange(CDataExchange* pDX)//��ťID���Ӧ�ı�����Ա
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


BEGIN_MESSAGE_MAP(CBuyGoods, CDialog)//��ťID���Ӧ����Ӧ����
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
m_buygoods_exit.LoadBitmaps(IDB_BITMAPbuygoods_exit1,IDB_BITMAPbuygoods_exit2);   //����  
m_buygoods_exit.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_bntOK.LoadBitmaps(IDB_BITMAPbuygoods_ensure1,IDB_BITMAPbuygoods_ensure2);   //����  
m_bntOK.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_bntReset.LoadBitmaps(IDB_BITMAPbuygoods_reset1,IDB_BITMAPbuygoods_reset2);   //����  
m_bntReset.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_goodsadd.LoadBitmaps(IDB_BITMAPbuygoods_right1,IDB_BITMAPbuygoods_right2);   //����  
m_goodsadd.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_goodssub.LoadBitmaps(IDB_BITMAPbuygoods_left1,IDB_BITMAPbuygoods_left2);   //����  
m_goodssub.SizeToContent();   //ʹ��ť��ӦͼƬ��С
///////////////////////////////////////////////////
	CTime time;
	time = CTime::GetCurrentTime();
	m_buyTime = time.Format("%Y-%m-%d");
	UpdateData(FALSE);
	m_listShowGoods.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowGoods.InsertColumn(0, "��Ʒ��");
	m_listShowGoods.InsertColumn(1, "����(Ԫ)");
	//m_listShowGoods.InsertColumn(2, "����(Ԫ)");
	
	m_listShowGoods.GetWindowRect(&rect);
	int wide = rect.right - rect.left;
	m_listShowGoods.SetColumnWidth(0, wide/2);
	m_listShowGoods.SetColumnWidth(1, wide/2);
	//m_listShowGoods.SetColumnWidth(2, wide/3);

	m_AdoConn.OnInitADOConn();
	CString strSql;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�ؼ����������ݿ����䣡�������������ҵ���~~~~
	strSql = "SELECT * FROM GoodsInfo";
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)//ûɶ����
	{
		CString GoodsName;
		CString GoodsPrice;
		GoodsName = (char*)(_bstr_t)m_pRs->GetCollect("GoodsName");
		GoodsPrice = (char*)(_bstr_t)m_pRs->GetCollect("GoodsPrice");
		m_listShowGoods.InsertItem(0, "");//���ǰ�����Ƕ���б����˼
		m_listShowGoods.SetItemText(0, 0, GoodsName);//����ָ������Ƕ���б�δ�����˼
		m_listShowGoods.SetItemText(0, 1, GoodsPrice);
		m_pRs->MoveNext();//���У�Ҳ����˵��Щ��һ��һ����ʾ��
	}


	m_listShowSelect.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_listShowSelect.InsertColumn(0, "��Ʒ��");
	m_listShowSelect.InsertColumn(1, "����(��)");
	m_listShowSelect.GetWindowRect(&rect);
	
	wide = rect.right - rect.left;
	m_listShowSelect.SetColumnWidth(0, wide/2);
	m_listShowSelect.SetColumnWidth(1, wide/2);
	m_totlePrice.SetWindowText("0");//��߶���Ĭ�ϵ�
	m_goodsNum.SetWindowText("1");

	return TRUE;  
}

void CBuyGoods::OnbntOK() 
{

	AfxMessageBox("������³ɹ�");
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
	n= m_listShowGoods.GetSelectionMark();//��ȡ�Ƿ�ѡ��nȡ0~*

	

	if (n == -1)
	{
		AfxMessageBox("��ѡ����Ʒ");
		return ;
	}

	CString GoodsName;
	CString GoodsPrice;
	CString GoodsNum;
	GoodsName = m_listShowGoods.GetItemText(n, 0);//���кź��к�
	GoodsPrice = m_listShowGoods.GetItemText(n, 1);
	
	
	m_goodsNum.GetWindowText(GoodsNum);
	
	if (GoodsNum.IsEmpty() || GoodsNum == "0")
	{
		AfxMessageBox("��ѡ����Ʒ");
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
