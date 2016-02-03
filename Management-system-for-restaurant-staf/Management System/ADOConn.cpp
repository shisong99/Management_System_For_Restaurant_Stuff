// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "��������ϵͳ.h"
#include "ADOConn.h"
#include <atlbase.h>	

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
/***************************************************************************
����Integrated SecurityΪ True ��ʱ���������ǰ��� UserID, PW 
�ǲ������õģ�������windows�����֤ģʽ��
ֻ������Ϊ False ��ʡ�Ը����ʱ�򣬲Ű��� UserID, PW �����ӡ�
Integrated Security ��������Ϊ: True, false, yes, no ��
���ĸ�����˼�������ˣ�����������Ϊ��sspi ���൱�� True��
������������� True��
Integrated Security= SSPI�����ʾ�Ե�ǰWINDOWSϵͳ�û���ȥ��¼SQL SERVER��������
���SQL SERVER��������֧�����ַ�ʽ��¼ʱ���ͻ����
"Provider=SQLOLEDB.1;Persist Security Info=False;Initial Catalog=���ݿ���
;Data Source=192.168.0.1;User ID=sa;Password=����"
initial catalog��database��������ʲô
Initial Catalog: 
DataBase: 
����û���κ�����ֻ�����Ʋ�һ����
�ͺ������������ʵ������������һ�����������Խ���
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
OnInitADOConn()�ú����Ĺ������������ݿ�

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
				//ָ��ĳ�����ݿ�
				m_pCon->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=Catering.mdb","","",adModeUnknown);//����CATERING���ݿ���
			}
			else
				AfxMessageBox("�������Ӷ���ʧ�ܣ�");
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
				AfxMessageBox("�������Ӷ���ʧ�ܣ�");
		}
	
	}
	
	catch ( _com_error exp)
	{
		AfxMessageBox("���ݿ�δ����");
		AfxMessageBox(exp.Description());
	}
}



/**********************************
GetRecordSet(_bstr_t bstrSQL)
��ý������
**********************************/

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{	
	HRESULT hr ;
	try//��������쳣���׳��쳣����catch��ס
	{
		if (m_pCon == NULL)
			OnInitADOConn();

		hr = m_pRs.CreateInstance("ADODB.Recordset");
		if (SUCCEEDED(hr))
		{
			
			m_pRs->Open(bstrSQL, m_pCon.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);// m_pCon.GetInterfacePtr()��ȡ��ӿ��IDispatchָ��

		}
		else 
			AfxMessageBox("���������ʧ��");
		
	}
	catch (_com_error exp)
	{
		AfxMessageBox(exp.Description());
		AfxMessageBox("��ý����ʧ��");
	}

	return m_pRs;

}

/*************************************
ExecuteSQL(_bstr_t bstrSQL)
�ú����Ĺ�����ִ��SQL���
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
		AfxMessageBox("ִ��SQL����ʧ��");

		return false ;
	}
}

/*********************************
ExitConn()�ú����Ĺ������˳����ݿ�
**********************************/
void ADOConn::ExitConn()
{
	if (m_pRs != NULL)
		m_pRs->Close();

	m_pCon->Close();
}