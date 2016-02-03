// ��������ϵͳDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��������ϵͳ.h"
#include "��������ϵͳDlg.h"
#include "Login.h"
#include "OpenTable.h"
#include "Register.h"
#include "DishesNum.h"
#include "DishesTotle.h"
#include "UpdateDishes.h"
#include "PayOrder.h"
#include "BuyGoods.h"
#include "GoodsInfo.h"
#include "DishesInfo.h"
#include "MonthIncome.h"
#include "GoodsSelect.h"
#include "ManagePower.h"
#include "UserManage.h"
#include "CopyDatabase.h"
#include "ReturnDatabase.h"
#include "cookermenu.h"
#include "member.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern  CMyApp theApp;
#define IDB_login		90000
#define IDB_open		90001
#define IDB_update		90002
#define IDB_payOrder	90003
#define IDB_dayIncome	90004
#define IDB_reg			90005
#define IDB_cancel		90006
#define IDB_cookermenu  90007




extern CMyApp theApp;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDR_MENU_update, m_my_change);
	DDX_Control(pDX, IDR_MENU_dayincome, m_my_count);
	DDX_Control(pDX, IDR_MENU_employeesManage, m_my_employ);
	DDX_Control(pDX, IDR_MENU_exit, m_my_exit);
	DDX_Control(pDX, IDR_MENU_login, m_my_login);
	DDX_Control(pDX, IDR_MENU_open, m_my_eat);
	//}}AFX_DATA_MAP

}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDR_MENU_login, OnMENUlogin)
	ON_COMMAND(IDR_MENU_about, OnMENUabout)
	ON_COMMAND(IDR_MENU_buygoods, OnMENUbuygoods)
	ON_COMMAND(IDR_MENU_copySQL, OnMENUcopySQL)
	ON_COMMAND(IDR_MENU_dayincome, OnMENUdayincome)
	ON_COMMAND(IDR_MENU_dishesInfo, OnMENUdishesInfo)
	ON_COMMAND(IDR_MENU_employeesManage, OnMENUemployeesManage)
	ON_COMMAND(IDR_MENU_goodsInfo, OnMENUgoodsInfo)
	ON_COMMAND(IDR_MENU_monthIncome, OnMENUmonthIncome)
	ON_COMMAND(IDR_MENU_newSQL, OnMENUnewSQL)
	ON_COMMAND(IDR_MENU_open, OnMENUopen)
	ON_COMMAND(IDR_MENU_pay, OnMENUpay)
	ON_COMMAND(IDR_MENU_power, OnMENUpower)
	ON_COMMAND(IDR_MENU_returnSQL, OnMENUreturnSQL)
	ON_COMMAND(IDR_MENU_update, OnMENUupdate)
	ON_COMMAND(IDR_MENU_goodsSelect, OnMENUgoodsSelect)
	ON_COMMAND(IDR_MEUNselectAccess, OnMEUNselectAccess)
	ON_COMMAND(IDR_MENUsql2005, OnMENUsql2005)
	ON_WM_CLOSE()
	ON_COMMAND(IDR_MENU_cookermenu, OnMENUcookermenu)
	ON_COMMAND(IDR_MENU_register,  OnMENURegister)
	ON_COMMAND(IDR_MENU_exit, OnCancel)
	ON_COMMAND(IDB_login, OnMENUlogin)
	ON_COMMAND(IDB_cancel, OnCancel)
	ON_COMMAND(IDB_update, OnMENUupdate)
	ON_COMMAND(IDB_open,   OnMENUopen)
	ON_COMMAND(IDB_reg,  OnMENURegister)
	ON_COMMAND(IDB_update, OnMENUupdate)
	ON_COMMAND(IDB_payOrder, OnMENUpay)
	ON_COMMAND(IDB_dayIncome,OnMENUdayincome)
	ON_COMMAND(IDR_menu_member, Onmenumember)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers
//CBitmapButton m_btnX1;

BOOL CMyDlg::OnInitDialog()
{

	//SetDialogBkColor(RGB(205,231,232),RGB(106,57,6));
	CDialog::OnInitDialog();
m_my_eat.LoadBitmaps(IDB_BITMAPmy_eat1,IDB_BITMAPmy_eat2);   //����  
m_my_eat.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_my_employ.LoadBitmaps(IDB_BITMAPmy_employ1,IDB_BITMAPmy_employ2);   //����  
m_my_employ.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_my_login.LoadBitmaps(IDB_BITMAPmy_login1,IDB_BITMAPmy_login2);   //����  
m_my_login.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_my_exit.LoadBitmaps(IDB_BITMAPmy_exit1,IDB_BITMAPmy_exit2);   //����  
m_my_exit.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_my_count.LoadBitmaps(IDB_BITMAPmy_count1,IDB_BITMAPmy_count2);   //����  
m_my_count.SizeToContent();   //ʹ��ť��ӦͼƬ��С
m_my_change.LoadBitmaps(IDB_BITMAPmy_change1,IDB_BITMAPmy_change2);   //����  
m_my_change.SizeToContent();   //ʹ��ť��ӦͼƬ��С

	// Add "About..." menu item to system menu.

 
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CTime time;
	time = CTime::GetCurrentTime();
	CString strTime = time.Format("%Y-%m-%d");
	m_imageList.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_login));//����ѡ��״̬ͼ�� ������ͼ�ꡣ
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_open));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_update));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_payorder));	
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_dayincome));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_reg));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_cancel));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_cookermenu));



	UINT Array[8];
	int i;
	for(i=0;i<8;i++)
	{
		Array[i]=90000+i;
	}

	m_toolBar.Create(this);
	m_toolBar.SetButtons(Array,8);
	m_toolBar.SetButtonText(0,"ϵͳ��¼");
	m_toolBar.SetButtonText(1,"��    ̨");
	m_toolBar.SetButtonText(2,"��    ��");
	m_toolBar.SetButtonText(3,"��    ��");
	m_toolBar.SetButtonText(4,"��������");
	m_toolBar.SetButtonText(5,"Ա��ע��");
	m_toolBar.SetButtonText(7,"��ʦ�˵�");
	m_toolBar.SetButtonText(6,"�˳�ϵͳ");
	/************************************************************************
	CToolBarCtrl::SetButtonWidth
	BOOL SetButtonWidth( int cxMin, int cxMax );
	����ֵ������ɹ��򷵻ط���ֵ�����򷵻��㡣
	 cxMin �����ر�ʾ����С��ť��ȡ���������ť�Ŀ�Ȳ���С�����ֵ��  
	cxMax �����ر�ʾ�����ť��ȡ������ť�ı�̫����ؼ���ʡ�Եĵ�����ʽ����  

	***********************************************************************/
	m_toolBar.GetToolBarCtrl().SetButtonWidth(60,120);
	m_toolBar.GetToolBarCtrl().SetImageList(&m_imageList);//���ù�������ͼƬ���ѹ�������ͼ�����������
	
	CSize sizeButton(70,60);
	CSize sizeImage(28,40);
	m_toolBar.SetSizes(sizeButton,sizeImage);	

	for(i=0;i<4;i++)
	{
		Array[i]=10000+1;
	}

	m_statusBar.Create(this);
	m_statusBar.SetIndicators(Array,4);// //����ָʾ��ID
	
	for(i = 0; i < 3; i++)
	{
		m_statusBar.SetPaneInfo(i, Array[i], 0, 120);//����һ������������ָʾ��ID�����Ϳ��
	}

	m_statusBar.SetPaneInfo(1 , Array[1] , 0 , 200  );
	m_statusBar.SetPaneInfo(2 , Array[2] , 0 , 800  );
	m_statusBar.SetPaneText(2 , "��ǰʱ��" + strTime);
	m_statusBar.SetPaneText(0 , "�� �� �� �� �� ϵ ͳ");
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);//��ʾ������
	/*************************************************************
	
	 EnableButton �������ð�ť������   ��һ��������ʾ��ť��ID
	�ڶ��������ð�ť��״̬ FALSE��ʾ���ð�ť true��ʾ���������ť.

	*************************************************************/
	m_toolBar.GetToolBarCtrl().EnableButton(IDB_open     , false);
	m_toolBar.GetToolBarCtrl().EnableButton(IDB_payOrder , false);
	m_toolBar.GetToolBarCtrl().EnableButton(IDB_dayIncome, false);
	m_toolBar.GetToolBarCtrl().EnableButton(IDB_reg      , false);
	m_toolBar.GetToolBarCtrl().EnableButton(IDB_update   , false);

	/****************************************************************
	
	EnableMenuItem����������ָֹ���Ĳ˵���Ŀ
	MF_GRAYEDʹ�˵���Ч;  MF_BYPOSITION ָ�����������Ѵ��ڲ˵����λ�á�
	��һ�����ڵ�λ����0

	*****************************************************************/
	CMenu* pMenu=GetMenu();
	pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED); 
	pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED);
	pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED);

	CString strSql;
	strSql.Format("SELECT * FROM Income WHERE IncomeTime = '%s'", strTime);
	m_AdoConn.OnInitADOConn();
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);

	if(m_pRs->adoEOF)
	{
		strSql.Format("INSERT INTO Income(IncomeTime)  VALUES('%s')",strTime);
	
	}	

	return TRUE;  
	//////////////////////////////////////////////////////////////////////


}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
 CPaintDC dc(this); // device context for painting 
       CRect   rect;    
  GetClientRect(&rect);    
 CDC   dcMem;    
 dcMem.CreateCompatibleDC(&dc);    
CBitmap   bmpBackground;    
bmpBackground.LoadBitmap(IDB_BITMAP1);  

 //IDB_BITMAP�����Լ���ͼ��Ӧ��ID  
BITMAP   bitmap;    
bmpBackground.GetBitmap(&bitmap);    
CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);    
dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  
// Do not call CDialog::OnPaint() for painting messages 
	///////////////////////////////////
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CDialog::OnPaint();

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnMENUlogin() 
{
	CLogin loginDlg;
	CString strSql;

	if (loginDlg.DoModal() == IDOK)
	{
		
		strSql.Format("SELECT * FROM Login WHERE UserName = '%s'",theApp.m_userName);
		m_AdoConn.OnInitADOConn();
		m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
		CString strPower;
		strPower = (char*)(_bstr_t)m_pRs->GetCollect("UserPower");
		int power =  atoi(strPower);
		
		if (power == 0)
		{	
			CMenu* pMenu = GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED );
			

			m_toolBar.GetToolBarCtrl().EnableButton(IDB_open,      TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_payOrder,  TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_dayIncome, TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_reg,       TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_update,    TRUE);

		
		}

		if (power == 1)
		{
			CMenu* pMenu=GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(1)->EnableMenuItem(3,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
		
			
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_open,       TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_payOrder,   TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_dayIncome,  TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_reg,        TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_update,     TRUE);
		
		}
		
		if (power == 2)
		{
			CMenu* pMenu=GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0,MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0,MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1,MF_BYPOSITION | MF_GRAYED );
			
			
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_open     ,        TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_payOrder ,        TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_dayIncome,        TRUE);
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_update   ,        TRUE);
		
		}
		if(power==3)
		{
			CMenu* pMenu = GetMenu();
			pMenu->GetSubMenu(1)->EnableMenuItem(0, MF_BYPOSITION | MF_ENABLED );
			pMenu->GetSubMenu(1)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(2)->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(3)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(0)->EnableMenuItem(2, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(0)->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_GRAYED );
			pMenu->GetSubMenu(1)->GetSubMenu(0)->EnableMenuItem(3, MF_BYPOSITION | MF_GRAYED );
			m_toolBar.GetToolBarCtrl().EnableButton(IDB_cookermenu,     TRUE);
			
		}

		m_statusBar.SetPaneText(1, "��ǰ�û�:"+theApp.m_userName);
		SetWindowText("��������ϵͳ            ��ǰ��¼�û�:"+theApp.m_userName);
		
	}

	if (loginDlg.count == 3)
		CDialog::OnCancel();



	
	
}

void CMyDlg::OnMENUabout() 
{
	// TODO: Add your command handler code here
	MessageBox("�����ˣ���Ԭ ������ ���� ʰ��");
}

void CMyDlg::OnMENUbuygoods() 
{
	CBuyGoods dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUcopySQL() 
{
	CCopyDatabase dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUdayincome() 
{
	CTime time;
	time = CTime::GetCurrentTime();
	CString strTime;
	strTime = time.Format("%Y-%m-%d");
	m_AdoConn.OnInitADOConn();
	CString strSql;

	strSql = "SELECT * FROM Income WHERE IncomeTime = '"+strTime+"'";
	m_pRs = m_AdoConn.GetRecordSet((_bstr_t)strSql);
	
	while(!m_pRs->adoEOF)
	{
		CString dayValue=(char*)(_bstr_t)m_pRs->GetCollect("DayIncome");		
		MessageBox("����Ӫҵ��Ϊ��"+dayValue+"Ԫ","������");
		return;
	}

	
}

void CMyDlg::OnMENUdishesInfo() 
{
	CDishesInfo dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUemployeesManage() 
{
	CUserManage dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUgoodsInfo() 
{
	CGoodsInfo dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUmonthIncome() 
{
	CMonthIncome dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUnewSQL() 
{
	m_AdoConn.OnInitADOConn();

	if (MessageBox("ȷ��Ҫ��ʼ�����ݿ���?", "��ʾ", MB_YESNO) == IDYES)
	{
		CString strSql = "DELETE FORM DisehesInfo";
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		strSql = "DELETE FROM StockInfo";
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		 strSql = "DELETE FROM GoodsInfo";
		 m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		strSql = "DELETE FROM Income";
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
		strSql = "DELETE FROM PayOrder";
		m_AdoConn.ExecuteSQL((_bstr_t)strSql);
	}
	
}

void CMyDlg::OnMENUopen() 
{
	COpenTable dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUpay() 
{
	CPayOrder dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUpower() 
{
	CManagePower dlg;
	dlg.DoModal();
}

void CMyDlg::OnMENUreturnSQL() 
{
	CReturnDatabase dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUupdate() 
{
	CUpdateDishes dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENUgoodsSelect() 
{
	CGoodsSelect dlg;
	dlg.DoModal();
	
}

void CMyDlg::OnMENURegister()
{
	CRegister dlg;
	dlg.DoModal();

}

void CMyDlg::OnMEUNselectAccess() 
{
	theApp.m_databaseFlag = 0;
	
}

void CMyDlg::OnMENUsql2005() 
{
	theApp.m_databaseFlag = 1;
	
}

void CMyDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(AfxMessageBox("ȷ��Ҫ�˳���",MB_YESNO)==IDYES)	
		CDialog::OnClose();
	

}

void CMyDlg::OnMENUcookermenu() 
{
	Ccookermenu dlg;
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}



void CMyDlg::Onmenumember() 
{
	// TODO: Add your command handler code here
	member dlg;
	dlg.DoModal();
}
