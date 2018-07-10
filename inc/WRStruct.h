#pragma once

#include <vector>
#include "MarketDefine.h"
#include "Baselib/DateTime.h"

namespace kiiik {


/*
������SHFE��DCE��CZCE�������ĸ��ַ�
Ʒ��CU��ZN��AL���֣�һ�������ַ�
����һ����λ����
--- ��ͦ
*/
struct CSymbol
{
	char	m_ExchangeId[9];					/// ���������룬���磺'SHFE' / 'DCE' / 'CZCE'
	char	m_ProductId[31];					/// Ʒ�ִ��룬���磺'CU' / 'AL' / 'ZN'
	int		m_ContractDays;						/// Լ��������0Ϊ���֣�������Ϊ�ع�

	CSymbol() { memset(this, 0, sizeof(CSymbol)); }
	CSymbol(const char *ExchangeId, const char *ProductId, int ContractDays){
		strcpy(m_ExchangeId, ExchangeId);
		strcpy(m_ProductId, ProductId);
		m_ContractDays = ContractDays;
	}
	std::string Str() const
	{
		char day[8] = { 0 };
		sprintf(day, "%d", m_ContractDays);
		return (string)m_ExchangeId + "_" + m_ProductId+"_"+day;
	}
	bool operator==(const CSymbol& other) const
	{
		return (strcmp(m_ExchangeId, other.m_ExchangeId) == 0) && (strcmp(m_ProductId, other.m_ProductId) == 0) && m_ContractDays == other.m_ContractDays;
	}
	bool operator!=(const CSymbol& other) const
	{
		return !(*this == other);
	}

	bool operator<(const CSymbol& other) const
	{
		return strcmp(m_ExchangeId, other.m_ExchangeId) < 0 || 
			(strcmp(m_ExchangeId, other.m_ExchangeId) == 0 && strcmp(m_ProductId, other.m_ProductId) < 0) ||
			(strcmp(m_ExchangeId, other.m_ExchangeId) == 0 && strcmp(m_ProductId, other.m_ProductId) == 0 && m_ContractDays<other.m_ContractDays);
	}

	bool operator>(const CSymbol& other) const
	{
		return strcmp(m_ExchangeId, other.m_ExchangeId) > 0 ||
			(strcmp(m_ExchangeId, other.m_ExchangeId) == 0 && strcmp(m_ProductId, other.m_ProductId) > 0) ||
			(strcmp(m_ExchangeId, other.m_ExchangeId) == 0 && strcmp(m_ProductId, other.m_ProductId) == 0 && m_ContractDays>other.m_ContractDays);
	}
	bool operator<=(const CSymbol& other) const { return !(*this > other); }
	bool operator>=(const CSymbol& other) const { return !(*this < other); }
};

// �ֵ�����
struct CQuotation
{
	CSymbol symbol;
	///
	long	m_SystemDate;						/// ϵͳ����
	long	m_SystemTime;						/// ϵͳʱ��
	long	m_MinuteDate;						/// ������������
	long	m_MinuteTime;						/// ��������ʱ��
	long	m_FinestDate;						/// �����������
	long	m_FinestTime;						/// �������ʱ��
	///
	long	m_ContractDate;						/// ��ع�����
	long	m_DeadlineDate;						/// �����ع���ֹ����
	long	m_DeliveryDate;						/// ��Ч��������
	char	m_AlphaInstrumentId[31];			/// ��һ�ڻ���Լ
	char	m_BravoInstrumentId[31];			/// �ڶ��ڻ���Լ
	double	m_AlphaLastPrice;					/// ��һ�ڻ����¼�
	double	m_BravoLastPrice;					/// �ڶ��ڻ����¼�
	///
	double	m_DiscountRatio;					/// ���ֱ���
	double	m_PosiRepoRatio;					/// ���ع�����
	double	m_ReveRepoRatio;					/// ������ع�����
	double	m_FlexReveRepoRatio;				/// �����ع�����
	double	m_DiscountPrice;					/// ���ּ۸�
	double	m_PosiRepoPrice;					/// ���ع��۸�
	double	m_FlexReveRepoPrice;				/// �����ع��۸�

	CQuotation() { memset(this, 0, sizeof(CQuotation)); }
};


/*
���ݿ����(DBaaS) �� �ṩȫ�����ݿ⹦�ܡ�

���ݷ���(DaaS) �� �Լ��������ݣ�ͨ��API��internet�������ݣ���ִ��sql��
*/

}