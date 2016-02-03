// MonthIncome.cpp : implementation file
//

#include "stdafx.h"
#include "��������ϵͳ.h"
#include "MonthIncome.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonthIncome dialog


CMonthIncome::CMonthIncome(CWnd* pParent /*=NULL*/)
	: CDialog(CMonthIncome::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonthIncome)
	//}}AFX_DATA_INIT
}


void CMonthIncome::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonthIncome)
	DDX_Control(pDX, IDC_bntFound, m_mi_enquery);
	DDX_Control(pDX, IDC_bntCancel, m_mi_cancel);
	DDX_Control(pDX, IDC_incomeYear, m_incomeYear);
	DDX_Control(pDX, IDC_incomeMonth, m_incomeMonth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonthIncome, CDialog)
	//{{AFX_MSG_MAP(CMonthIncome)
	ON_BN_CLICKED(IDC_bntFound, OnbntFound)
	ON_BN_CLICKED(IDC_bntCancel, OnbntCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonthIncome message handlers

void CMonthIncome::OnbntFound() 
{
	
	UpdateData(TRUE);
	CString strYear;
	CString strMonth;
	CString strDay;
	CString strTotleIncome;
	float totleIncome = 0;
	
	int i, j;
	i = m_incomeYear.GetCurSel();
	j = m_incomeMonth.GetCurSel();

	if (i == -1 || j == -1)
	{
		AfxMessageBox("��ѡ��Ҫ��ѯ������");
		return;
	}

	m_incomeYear.GetLBText(i, strYear);
	m_incomeMonth.GetLBText(j, strMonth);
	m_AdoConn.OnInitADOConn();

	CString strSql;
	strSql.Format("SELECT * FROM Income WHERE Year(IncomeTime)='%s' and Month(IncomeTime) ='%s'", strYear, strMonth);
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	while (m_pRs->adoEOF == 0)
	{
		strTotleIncome = (char*)(_bstr_t)m_pRs->GetCollect("DayIncome");
		
		totleIncome += atof(strTotleIncome);
		m_pRs->MoveNext();
	}

	//strTotleIncome = (char*)(_bstr_t)totleIncome;
	strTotleIncome.Format("%.2lf", totleIncome);
	MessageBox(strYear+"��"+strMonth+"�µ�����Ϊ:"+strTotleIncome+"Ԫ", "�������ѯ");
}

void CMonthIncome::OnbntCancel() 
{
	CDialog::OnCancel();
	
}

BOOL CMonthIncome::OnInitDialog() 
{
	CDialog::OnInitDialog();
m_mi_cancel.LoadBitmaps(IDB_BITMAPmonthincome_cancel1,IDB_BITMAPmonthincome_cancel2);   //����  

 m_mi_cancel.SizeToContent();   //ʹ��ť��ӦͼƬ��С	
 m_mi_enquery.LoadBitmaps(IDB_BITMAPmonthincome_enquery1,IDB_BITMAPmonthincome_enquery2);   //����  

 m_mi_enquery.SizeToContent();   //ʹ��ť��ӦͼƬ��С
	CString strSql;
	CString strYear;
	CString strMonth;
	
	strSql = "SELECT distinct  Year(IncomeTime) as ��� FROM Income";
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strYear = (char*)(_bstr_t)m_pRs->GetCollect("���");
		m_incomeYear.AddString(strYear);
		m_pRs->MoveNext();
	}

	strSql = "SELECT distinct Month(IncomeTime) as �·� FROM Income";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	while (m_pRs->adoEOF == 0)
	{
		strMonth = (char*)(_bstr_t)m_pRs->GetCollect("�·�");
		m_incomeMonth.AddString(strMonth);
		m_pRs->MoveNext();
	}
	

	
	return TRUE;  
}
