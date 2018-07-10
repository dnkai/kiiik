/////////////////////////////////////////////////////////////////////////
///@system �ֵ��ۺϽ�����ϵͳ
///@company ��������������ι�˾
///@file WtpUserApiStruct.h
///@brief �����˿ͻ��˽ӿ�ʹ�õ�ҵ�����ݽṹ
///@history 
///20161122	��ͦ�����		�������ļ�
/////////////////////////////////////////////////////////////////////////

#if !defined(WTP_STRUCT_H)
#define WTP_STRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "wtpmduserapi/WtpUserApiDataType.h"

#if defined(WIN32)
#ifdef LIB_MD_API_EXPORT
#define MD_API_EXPORT __declspec(dllexport)
#else
#define MD_API_EXPORT __declspec(dllimport)
#endif
#else
#define MD_API_EXPORT 
#endif

/// �ֵ����׺�Լ
struct CWtpSymbolField
{
	/// ���������룬���磺'SHFE' / 'DCE' / 'CZCE'
	TWtpExchangeIdType		m_ExchangeId;
	/// ����Ʒ�ִ��룬���磺'CU' / 'AL' / 'ZN'
	TWtpProductIdType		m_ProductId;
	/// ����/�ع���������	��0Ϊ���֣�������Ϊ�ع�
	TWtpDaysType			m_ContractDays;
};

/// �ֵ�����
struct CWtpQuotationField
{
	/// �ֵ����׺�Լ
	CWtpSymbolField			m_Symbol;
	/// ϵͳ����
	TWtpDateType			m_SystemDate;
	/// ϵͳʱ��						
	TWtpTimeType			m_SystemTime;
	/// ������������						
	TWtpDateType			m_MinuteDate;
	/// ��������ʱ��						
	TWtpTimeType			m_MinuteTime;
	/// �����������						
	TWtpDateType			m_FinestDate;
	/// �������ʱ��						
	TWtpTimeType			m_FinestTime;						
	/// ��ع�����
	TWtpDateType			m_ContractDate;
	/// �����ع���ֹ����						
	TWtpDateType			m_DeadlineDate;
	/// ��Ч��������					
	TWtpDateType			m_DeliveryDate;
	/// ��һ�ڻ���Լ						
	TWtpInstrumentIdType	m_AlphaInstrumentId;
	/// �ڶ��ڻ���Լ			
	TWtpInstrumentIdType	m_BravoInstrumentId;
	/// ��һ�ڻ����¼�			
	TWtpPriceType			m_AlphaLastPrice;
	/// �ڶ��ڻ����¼�					
	TWtpPriceType			m_BravoLastPrice;
	/// ���ֱ���
	TWtpRatioType			m_DiscountRatio;
	/// ���ع�����					
	TWtpRatioType			m_PosiRepoRatio;
	/// ������ع�����					
	TWtpRatioType			m_ReveRepoRatio;
	/// �����ع�����					
	TWtpRatioType			m_FlexReveRepoRatio;
	/// ���ּ۸�				
	TWtpPriceType			m_DiscountPrice;
	/// ���ع��۸�					
	TWtpPriceType			m_PosiRepoPrice;
	/// �����ع��۸�					
	TWtpPriceType			m_FlexReveRepoPrice;
};

/// ������Ϣ
struct CWtpRspInfoField {
	int						m_ErrId;
	TWtpStatusMsgType		m_ErrMsg;
};

/// �û���¼����
struct CWtpReqUserLoginField {
	TWtpUserIdType			m_UserId;
	TWtpPasswordType		m_Password;
};

/// �û���¼��Ӧ
struct CWtpRspUserLoginField {
	bool					m_Success;
};

/// �û��ǳ�����/��Ӧ
struct CWtpUserLogoutField {
	TWtpUserIdType			m_UserID;
};

#endif
