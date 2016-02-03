// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__835C5B4D_31ED_4B02_8D3A_03C1DD796777__INCLUDED_)
#define AFX_ADOCONN_H__835C5B4D_31ED_4B02_8D3A_03C1DD796777__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"no_namespace rename("EOF", "adoEOF")
class ADOConn  
{
public:

	ADOConn();
	virtual ~ADOConn();

public:
	int m_databaseFlag;
	_ConnectionPtr m_pCon;
	_RecordsetPtr  m_pRs;
	void ExitConn();
	void OnInitADOConn();
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);


};

#endif // !defined(AFX_ADOCONN_H__835C5B4D_31ED_4B02_8D3A_03C1DD796777__INCLUDED_)
