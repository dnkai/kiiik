/////////////////////////////////////////////////////////////////////////
///@system �ֵ��ۺϽ�����ϵͳ
///@company ��������������ι�˾
///@file WtpMdCApi.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20161122	��ͦ�����		�������ļ�
/////////////////////////////////////////////////////////////////////////

#ifndef WTP_MD_C_API_H
#define WTP_MD_C_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include "wtpmduserapi/WtpUserApiStruct.h"

	//! ���ӡ��Ͽ�����Ӧ
	typedef void(__stdcall *fnOnFrontConnected)();
	typedef void(__stdcall *fnOnFrontDisconnected)();

	typedef void(__stdcall *fnOnRspUserLogin)(CWtpRspUserLoginField *pRspUserLogin, CWtpRspInfoField *pRspInfo);//��½��Ӧ
	typedef void(__stdcall *fnOnRspUserLogout)(CWtpUserLogoutField *pUserLogout, CWtpRspInfoField *pRspInfo);//�ǳ���Ӧ

	//! ������Ϣ
	typedef void(__stdcall *fnOnRspError)(CWtpRspInfoField *pRspInfo);

	//! ���ݵ��������Ļص�����
	typedef void(__stdcall *fnOnRspQrySymbol)(CWtpSymbolField *pSymbol, int nCount);//���Լ�б���Ӧ
	typedef void(__stdcall *fnOnRspQryQuotation)(CWtpQuotationField *pQuotation);//�鵥����Լ��Ӧ
	typedef void(__stdcall *fnOnRtnQuotation)(CWtpQuotationField *pQuotation);//����������Ӧ



	/*!	\brief ע������ص� ***********************************************************************************/
	MD_API_EXPORT void __stdcall WTP_RegOnFrontConnected(fnOnFrontConnected);
	MD_API_EXPORT void __stdcall WTP_RegOnFrontDisconnected(fnOnFrontDisconnected);
	MD_API_EXPORT void __stdcall WTP_RegOnRspUserLogin(fnOnRspUserLogin);
	MD_API_EXPORT void __stdcall WTP_RegOnRspUserLogout(fnOnRspUserLogout);
	MD_API_EXPORT void __stdcall WTP_RegOnRspError(fnOnRspError);
	MD_API_EXPORT void __stdcall WTP_RegOnRspQrySymbol(fnOnRspQrySymbol);
	MD_API_EXPORT void __stdcall WTP_RegOnRspQryQuotation(fnOnRspQryQuotation);
	MD_API_EXPORT void __stdcall WTP_RegOnRtnQuotation(fnOnRtnQuotation);


	/*!	\brief ����ӿ� ***********************************************************************************/

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	MD_API_EXPORT void __stdcall RegisterFront(char *pszFrontAddress);
	///�û���¼����
	MD_API_EXPORT int __stdcall ReqUserLogin(CWtpReqUserLoginField *pReqUserLoginField);
	///�ǳ�����
	MD_API_EXPORT int __stdcall ReqUserLogout(CWtpUserLogoutField *pUserLogout);
	///��ѯ��Լ�б�
	MD_API_EXPORT int __stdcall ReqQrySymbol();
	///��ѯ������Լ�۸�
	MD_API_EXPORT int __stdcall ReqQryQuotation(CWtpSymbolField *pSymbol);
	///�������顣
	///@param pSymbol �ֵ����׺�Լ  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	MD_API_EXPORT int __stdcall ReqSubQuotation(CWtpSymbolField *pSymbol, int nCount);
	///�˶����顣
	///@param pSymbol �ֵ����׺�Լ   
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	MD_API_EXPORT int __stdcall ReqUnSubQuotation(CWtpSymbolField *pSymbol, int nCount);

	MD_API_EXPORT void __stdcall Release();

#ifdef __cplusplus
}
#endif

#endif
