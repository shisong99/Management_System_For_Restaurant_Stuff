// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "餐饮管理系统.h"
#include "ADOConn.h"
#include <atlbase.h>	

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
/***************************************************************************
设置Integrated Security为 True 的时候，连接语句前面的 UserID, PW 
是不起作用的，即采用windows身份验证模式。
只有设置为 False 或省略该项的时候，才按照 UserID, PW 来连接。
Integrated Security 可以设置为: True, false, yes, no ，
这四个的意思很明白了，还可以设置为：sspi ，相当于 True，
建议用这个代替 True。
Integrated Security= SSPI这个表示以当前WINDOWS系统用户身去登录SQL SERVER服务器，
如果SQL SERVER服务器不支持这种方式登录时，就会出错
"Provider=SQLOLEDB.1;Persist Security Info=False;Initial Catalog=数据库名
;Data Source=192.168.0.1;User ID=sa;Password=密码"
initial catalog与database的区别是什么
Initial Catalog: 
DataBase: 
两者没有任何区别只是名称不一样，
就好像是人类的真实姓名与曾用名一样。。都可以叫你
**********************************************************************************/
#define  Provider "Provider=SQLOLEDB.1;Integrated Security=SSPI;\
Persist Security Info=False;Initial Catalog=Catering"

//#define Provider "Provider = SQLOLEDB.1;Integrated Security = SSPI;\
Persist Security Info = FALSE; Initial Catalog = Catering ;Data Source=FREESKYC-912C64;\
User ID =sa; Password = yangtingrui"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern CMyApp theApp;

ADOConn::ADOConn()
{
	m_databaseFlag = 0;
}

ADOConn::~ADOConn()
{

}


/**************************************
OnInitADOConn()该函数的功能是连接数据库

***************************************/
void ADOConn::OnInitADOConn()
{
	HRESULT hr;
	::CoInitialize(NULL);
	m_databaseFlag = theApp.m_databaseFlag;
	try
	{
		if (m_databaseFlag == 0)
		{	
			hr = m_pCon.CreateInstance("ADODB.Connection");
			if (SUCCEEDED(hr))
			 {
				m_pCon->ConnectionTimeout = 3;
				/////////////////////////////////////////////////////////////////////////
				//指定某个数据库
				m_pCon->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Catering.mdb","","",adModeUnknown);//接上CATERING数据库了
			}
			else
				AfxMessageBox("创建连接对象失败！");
	  }
	 else if (m_databaseFlag == 1)
		{
			hr = m_pCon.CreateInstance("ADODB.Connection");
			if (SUCCEEDED(hr))
			{
				m_pCon->ConnectionTimeout = 3;
				m_pCon->Open(_bstr_t(Provider),"", "", adModeUnknown);
			}
			else
				AfxMessageBox("创建连接对象失败！");
		}
	
	}
	
	catch ( _com_error exp)
	{
		AfxMessageBox("数据库未连接");
		AfxMessageBox(exp.Description());
	}
}



/**********************************
GetRecordSet(_bstr_t bstrSQL)
获得结果集。
**********************************/

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{	
	HRESULT hr ;
	try//如果出现异常就抛出异常，由catch接住
	{
		if (m_pCon == NULL)
			OnInitADOConn();

		hr = m_pRs.CreateInstance("ADODB.Recordset");
		if (SUCCEEDED(hr))
		{
			
			m_pRs->Open(bstrSQL, m_pCon.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);// m_pCon.GetInterfacePtr()获取库接库的IDispatch指针

		}
		else 
			AfxMessageBox("创建结果集失败");
		
	}
	catch (_com_error exp)
	{
		AfxMessageBox(exp.Description());
		AfxMessageBox("获得结果集失败");
	}

	return m_pRs;

}

/*************************************
ExecuteSQL(_bstr_t bstrSQL)
该函数的功能是执行SQL语句
***************************************/
BOOL ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if (m_pCon == NULL)
			OnInitADOConn();
		
		m_pCon->Execute(bstrSQL, NULL, adCmdText);
		
		return  true ;
	}
	catch (_com_error exp)
	{
		AfxMessageBox(exp.Description());
		AfxMessageBox("执行SQL语言失败");

		return false ;
	}
}

/*********************************
ExitConn()该函数的功能是退出数据库
**********************************/
void ADOConn::ExitConn()
{
	if (m_pRs != NULL)
		m_pRs->Close();

	m_pCon->Close();
}