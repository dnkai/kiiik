#ifndef MARKET_DEFINE_H_
#define MARKET_DEFINE_H_

#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include <iostream>
#include "Baselib/DateTime.h"


#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif

#ifdef WIN32
#include <float.h>
#include <Windows.h>
#define is_nan(x) _isnan(x)

#ifndef NAN
static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
#define NAN (*(const double *) __nan)
#endif

#elif defined __GNUG__
#include <math.h>
#include <sys/time.h>
#define is_nan(x) isnan(x)
#endif

using namespace std;

namespace kiiik {

typedef char TimeFieldType;	//ʱ����Ϊ���ʱ��ʾ��1900��ֻ��
typedef char String32[32];
typedef char String16[16];
typedef char InstrumentIdType[23];
typedef char InstrumentNameType[24];
typedef char StatusMsgType[81];
typedef char UserIdType[20];
typedef char PwdType[20];
typedef long long NumberIdType;
//typedef float MovePointType;		//��С����
typedef float REAL;
typedef double PriceType;	//�۸�����
typedef int VolumeType;	//������ �ڻ����֣���Ʊ����
typedef String16 UserStrategyIdType; // ���˺�&���Ժ�

/*
#define EXCHANGE_SSE		'0'	// �Ϻ�֤ȯ������			 
#define EXCHANGE_SZE		'1'	// ����֤ȯ������			 
#define EXCHANGE_CFFEX		'2'	// �й������ڻ�������		 
#define EXCHANGE_DCE		'3'	// ������Ʒ������			 
#define EXCHANGE_CZCE		'4'	// �й�֣����Ʒ������		 
#define EXCHANGE_SHFE		'5'	// �Ϻ��ڻ�������
#define EXCHANGE_INE		'6'	// �Ϻ�������Դ��������
#define EXCHANGE_HK			'7'	// �۽���
#define EXCHANGE_OTHER		'n' //
typedef char ExchangeIdType;	//����������

#define PRODUCT_STOCK		'0'
#define PRODUCT_FUTURE		'1'
#define PRODUCT_OPTION		'2'
#define PRODUCT_BOND		'3'
#define PRODUCT_FUND		'4'
#define PRODUCT_INDEX		'5' 
#define PRODUCT_OTHER		'n' 
typedef char ProdectIdType;		//Ʒ������

#define DIMENSION_SECOND	'0'
#define DIMENSION_MINUTE	'1'	
#define DIMENSION_HOUR		'2'	
#define DIMENSION_DAY		'3'
#define DIMENSION_WEEK		'4'
#define DIMENSION_MONTH		'5'
#define DIMENSION_YEAR		'6'
typedef char  DimensionType;	//K������

#define ORDER_STATUS_INVALID					'0'		/ **< ������Ч,��Ӧ�ڻ���δ֪ * /
#define ORDER_STATUS_WAIT_SUBMIT				'1'		/ **< ���� * /
#define ORDER_STATUS_BEEN_SUBMIT				'2'		/ **< �ѱ�(��Ʊ);δ�ɽ�(�ڻ�) * /
#define ORDER_STATUS_PART_TRADE					'3'		/ **< ���ֳɽ� * /
#define ORDER_STATUS_ALL_TRADE					'4'		/ **< ȫ���ɽ� * /
#define ORDER_STATUS_BEEN_SUBMIT_WAIT_CANCEL	'5'		/ **< �ѱ�����(��Ʊ) * /
#define ORDER_STATUS_PART_TRADE_WAIT_CANCEL		'6'		/ **< ���ɴ���(��Ʊ) * /
#define ORDER_STATUS_BEEN_CANCEL				'7'		/ **< �������ѳ�����Ʊ ���ڳ�����������(�ڻ�) * /
#define ORDER_STATUS_NOT_TOUCHED				'8'		/ **< ��������δ���� * /
#define ORDER_STATUS_TOUCHED					'9'		/ **< �������Ѵ��� * /
#define ORDER_STATUS_ERROR						'n'		/ **< �µ����� * /
#define CANCEL_ORDER_STATUS_ERROR				'm'		/ **< �������� * /
typedef char OrderStatus;								/ **< ����״̬ * /

#define ALL_DIRECTION		'0'		/ **< �飺���ֲ֣�ƽ�֣����˫�� * /
#define LONG_DIRECTION		'1'		/ **< ��� * /
#define SHORT_DIRECTION		'2'		/ **< ���� * /
typedef char OrderDirection;		/ **< �������� * /

#define OPEN_ORDER				'0'		/ **< ���� * /
#define CLOSE_ORDER				'1'		/ **< ƽ�� * /
#define CLOSE_TODAY_ORDER		'3'		/ **< ƽ��ֻ���ڻ� * /
#define CLOSE_YESTERDAY_ORDER	'4'		/ **< ƽ��ֻ���ڻ� * /
#define FORCE_CLOSE_ORDER		'5'		/ **< ǿƽ * /
typedef char OpenCloseFlag;				/ **< ��ƽ��־ * /

#define LIMIT_PRICE_ORDER			'0'		/ **< �޼� * /
#define MARKET_PRICE_ORDER			'1'		/ **< �м�,��ƱĿǰ��֧�� * /
#define SZ_DS_BEST_PRICE_ORDER		'2'		/ **< ����ַ����ż۸�ί�� * /
#define SZ_BF_BEST_PRICE_ORDER		'3'		/ **< ������ż۸�ί�� * /
#define SZ_CANCEL_PRICE_ORDER		'4'		/ **< �ʱ�ɽ�ʣ�೷��ί�� * /
#define HS_CANCEL_PRICE_ORDER		'5'		/ **< ���������嵵������ί�� * /
#define SZ_ALL_TRADE_PRICE_ORDER	'6'		/ **< ��ȫ��ɽ�����ί�� * /
#define SH_BEST_CHA_PRICE_ORDER		'7'		/ **< �������嵵��ת�޼�ί�� * /
typedef char OrderPriceFlag;				/ **< ί������ * /

#define MONEY_RMB				'0'		/ **< ����� * /
#define MONEY_HK				'1'		/ **< �۱� * /
#define MONEY_DOLLAR			'2'		/ **< ��Ԫ * /
typedef char MoneyType;					/ **< ��ֵ���� * /

#define NAN_PRICE_UNIT '\x80'	//�����ֵ

#define COMM_TICK_DATA			'0'
#define COMM_TICK_SET			'1'
#define COMM_KLINE_DATA			'2'
#define COMM_KLINE_SET			'3'
typedef char CommDataType;		//ͨ����������

#define HF_SPECULATION '1'		///Ͷ��
#define HF_ARBITRAGE '2'		///����
#define HF_HEGE '3'				///�ױ�
typedef char HedgeFlagType;

#define STK_STATUS_N '0'		///ͨ��״̬
#define STK_STATUS_T '1'		///ͣ��״̬
#define STK_STATUS_Z '2'		///����������
#define STK_STATUS_UNKNOWN 'n'	///δ֪
typedef char StockStatusType;	///��Ʊ״̬

#define ERROR_MSG_LEN		 80		/ **<�ر�������Ϣ���� * /
#define STRUCT_ALIGN_LEN      1		/ **< �ṹ����볤�� * /
#define PRICE_LEVEL_NUM       5
//#define COMM_IDENTIFY '\xff'	//ͨ�ű�־
#define NAN_SYMBOL Symbol(PRODUCT_OTHER, EXCHANGE_OTHER, "")
#define NAN_LOCAL_ORDER_ID -1

#define UserManualId "999999"

#pragma pack(STRUCT_ALIGN_LEN)


// �ڻ���Լ
struct Symbol
{
	ProdectIdType product;
	ExchangeIdType exchange;
	InstrumentIdType instrument;
	Symbol(char prod = PRODUCT_OTHER, char exch = EXCHANGE_OTHER, const char* inst = "") : product(prod), exchange(exch) { memcpy(instrument, inst, sizeof(InstrumentIdType)); }
	Symbol(const Symbol& other) : product(other.product), exchange(other.exchange) { memcpy(instrument, other.instrument, sizeof(InstrumentIdType)); }
	Symbol& operator=(const Symbol& other) {
		if (this != &other) {
			product = other.product;
			exchange = other.exchange;
			memcpy(instrument, other.instrument, sizeof(InstrumentIdType));
		}
		return *this;
	}

	Symbol& operator=(const char* inst)
	{
		memcpy(instrument, inst, sizeof(InstrumentIdType));
		return *this;
	}

	std::string Str() const 
	{
		char str[12] = {0};
		//sprintf(str, "%c%c_%s", product, exchange, instrument);
		sprintf(str, "%s", instrument);
		return str;
	}

	bool operator==(const Symbol& other) const 
	{
		if (product == PRODUCT_FUTURE)
		{
			return (product == other.product) && (strcmp(instrument, other.instrument) == 0);
		}
		return (product == other.product) && (exchange == other.exchange) && (strcmp(instrument, other.instrument) == 0);
	}

	bool operator!=(const Symbol& other) const 
	{
		return !(*this == other);
	}

	bool operator<(const Symbol& other) const 
	{
		if (product == PRODUCT_FUTURE)
		{
			return product < other.product  || (product == other.product && strcmp(instrument, other.instrument) < 0);
		}
		return product < other.product  || (product == other.product && exchange < other.exchange) ||
			(product == other.product && exchange == other.exchange && strcmp(instrument, other.instrument) < 0);
	}

	bool operator>(const Symbol& other) const 
	{
		if (product == PRODUCT_FUTURE)
		{
			return product > other.product  || (product == other.product && strcmp(instrument, other.instrument) > 0);
		}
		return product > other.product  || (product == other.product && exchange > other.exchange) ||
			(product == other.product && exchange == other.exchange && strcmp(instrument, other.instrument) > 0);
	}
	bool operator<=(const Symbol& other) const { return !(*this > other); }
	bool operator>=(const Symbol& other) const { return !(*this < other); }
};
//����Ʒ��(����Լ��)
struct SymbolEx : public Symbol 
{
	InstrumentNameType name;

	SymbolEx(char *_name = "") : Symbol() { memcpy(name, _name, sizeof(InstrumentNameType)); }

	void FromStr(const char* str)
	{
		InstrumentIdType inst = {0};
		InstrumentNameType na = {0};
		sscanf(str, "%c,%[^,],%s", &exchange, inst, na);
		strcpy(instrument, inst);
		strcpy(name, na);
	}
	std::string ToStr() const
	{
		char tmp[64] = {0};
		sprintf(tmp, "%c,%s,%s", exchange, instrument, name);
		return tmp;
	}
};

/ *
 * @brief OrderParamData ί�в����ṹ�� TODO:����ΪSubmitParam
 * /
struct OrderParamData
{
	Symbol symbol;							/ **< ���� * /
	OrderDirection direction;				/ **< �������� * /
	OpenCloseFlag open_close_flag;			/ **< ��ƽ��־(ר���ڻ�) * /
	OrderPriceFlag order_price_flag;		/ **< ί������ * /
	PriceType limit_price;					/ **< ί���޼� * /
	VolumeType volume;						/ **< �ܵ�ί���� * /
	HedgeFlagType hedge_flag;				/ **< Ͷ���ױ���־(ר���ڻ�) * /
	UserStrategyIdType user_tag;			/ **< �û����Զ����־ * /
	
	int	order_group;						/ **< ί������(ר��JZ��Ʊ) * /
	int entrust_id;							/ **< ��ͬ��(ר��JSD��Ʊ) * /

	OrderParamData() { memset(this, 0, sizeof(OrderParamData)); }
};

/ *
 * @brief OrderData ί�лر��ṹ��
 * /
struct OrderData 
{
	Symbol symbol;							/ **< ������� * /
	NumberIdType order_id;					/ **< ������ * /
	NumberIdType local_order_id;			/ **< ���ض����� * /
	UserStrategyIdType user_tag;			/ **< �û����Զ����־ * /
	OrderStatus status;						/ **< ����״̬ * /
	baselib::DateTime submit_time;			/ **< ί��ʱ�� * /
	baselib::DateTime update_time;			/ **< �������ʱ�� * /
	OrderDirection direction;				/ **< �������� * /
	OpenCloseFlag open_close_flag;			/ **< ��ƽ��־(ר���ڻ�) * /
	OrderPriceFlag order_price_flag;		/ **< ί������ * /
	PriceType limit_price;					/ **< ί���޼� * /
	VolumeType total_volume;				/ **< �ܵ�ί���� * /
	VolumeType trade_volume;				/ **< �ѳɽ����� * /
	HedgeFlagType hedge_flag;				/ **< Ͷ���ױ���־(ר���ڻ�) * /
	StatusMsgType status_msg;				/ **< ��ϸ״̬��Ϣ * /

	// Ϊ����֤ȯ
	int	order_group;						/ **< ί������ * /

	OrderData()
		: status(ORDER_STATUS_INVALID)
		, direction(LONG_DIRECTION)
		, open_close_flag(OPEN_ORDER)
		, order_price_flag(LIMIT_PRICE_ORDER)
		, limit_price(0)
		, total_volume(0)
		, trade_volume(0)
		, order_group(-1)
	{
		memset(user_tag, 0, sizeof(UserStrategyIdType));
		memset(status_msg, 0, sizeof(StatusMsgType));
	}
};

//struct CancelOrderParamData
//{
//	long long order_id;
//	ExchangeIdType exchange;
//	CancelOrderParamData() : order_id(0), exchange(EXCHANGE_SSE) {}
//};

struct CancelOrderData
{
	UserStrategyIdType user_tag;			/ **< �û����Զ����־ * /
	NumberIdType order_id;
	bool succed;
	char error[64];
	CancelOrderData() : succed(true) { memset(user_tag, 0, sizeof(UserStrategyIdType)); memset(error, 0, 64); }
};

struct BaseInstrumentInfo 
{
	SymbolEx symbol;						/ **< ������� * /
	double	price_tick;						/ **< ��С�䶯��λ * /

	BaseInstrumentInfo() : price_tick(0.0) {}
	virtual void FromStr(const char* str) = 0;
	virtual std::string ToStr() const = 0;
};

struct StockInstrumentInfo : public BaseInstrumentInfo 
{
	PriceType	max_rise_value;				/ **< ��ͣ�� * /
	PriceType	max_down_value;				/ **< ��ͣ�� * /
	VolumeType	max_qty;					/ **< ������� ��λ:�� * /
	VolumeType	min_qty;					/ **< ������� ��λ:�� * /
	VolumeType	buy_unit;					/ **< ������С��λ * /
	VolumeType	sell_unit;					/ **< ������С��λ * /
	StockStatusType	status;	

	void FromStr(const char* str)
	{
		symbol.product = PRODUCT_STOCK;
		InstrumentIdType instrument = {0};
		InstrumentNameType name = {0};
		sscanf(str, "%c,%[^,],%[^,],%lf,%lf,%lf,%d,%d,%d,%d,%c", &symbol.exchange, instrument, name,
			&price_tick, &max_rise_value, &max_down_value, &max_qty, &min_qty, &buy_unit, &sell_unit, &status);
		strcpy(symbol.instrument, instrument);
		strcpy(symbol.name, name);
	}
	std::string ToStr() const
	{
		char tmp[64] = {0};
		sprintf(tmp, "%c,%s,%s,%g,%g,%g,%d,%d,%d,%d,%c", symbol.exchange, symbol.instrument, symbol.name, 
			price_tick, max_rise_value, max_down_value, max_qty, min_qty, buy_unit, sell_unit, status);
		return tmp;
	}
};

// �ڻ���Լ��Ϣ
struct InstrumentInfoData : public BaseInstrumentInfo {
	int		vol_multi;						/ **< ��Լ�������� * /
	bool	is_trading;						/ **< ��ǰ�Ƿ��� * /
	// �ɽ��� * ��֤���� => ��֤�� ;  Ͷ��: ��������������ȡ��֤��������������˫��; 
	double	long_margin_ratio;				/ **< ��ͷ��֤���� * /
	double	short_margin_ratio;				/ **< ��ͷ��֤���� * /


	InstrumentInfoData() : BaseInstrumentInfo(), vol_multi(0), is_trading(true), long_margin_ratio(0.0), short_margin_ratio(0.0) {}
	void FromStr(const char* str)
	{
		symbol.product = PRODUCT_FUTURE;
		InstrumentIdType instrument = {0};
		InstrumentNameType name = {0};
		sscanf(str, "%c,%[^,],%[^,],%d,%lf,%d,%lf,%lf", &symbol.exchange, instrument, 
			name, &vol_multi, &price_tick, &is_trading, &long_margin_ratio, &short_margin_ratio);
		strcpy(symbol.instrument, instrument);
		strcpy(symbol.name, name);
	}
	std::string ToStr() const
	{
		char tmp[64] = {0};
		sprintf(tmp, "%c,%s,%s,%d,%g,%d,%g,%g", symbol.exchange, symbol.instrument, 
			symbol.name, vol_multi, price_tick, is_trading, long_margin_ratio, short_margin_ratio);
		return tmp;
	}
};

// ��֤��
struct MarginInfo {
	InstrumentIdType instrument;
	///��ͷ��֤����
	double	LongMarginRatioByMoney;
	///��ͷ��֤���
	double	LongMarginRatioByVolume;
	///��ͷ��֤����
	double	ShortMarginRatioByMoney;
	///��ͷ��֤���
	double	ShortMarginRatioByVolume;

	MarginInfo() { memset(this, 0, sizeof(MarginInfo)); }
	std::string FromStr(const char* str)
	{
		InstrumentIdType inst = {0};
		String16 date = {0};
		sscanf(str, "%[^,],%[^,],%lf,%lf,%lf,%lf", date, inst, &LongMarginRatioByMoney, &LongMarginRatioByVolume, 
			&ShortMarginRatioByMoney, &ShortMarginRatioByVolume);
		strcpy(instrument, inst);
		return date;
	}
	std::string ToStr() const
	{
		char tmp[64] = {0};
		sprintf(tmp, "%s,%g,%g,%g,%g", instrument, LongMarginRatioByMoney, LongMarginRatioByVolume,
			ShortMarginRatioByMoney, ShortMarginRatioByVolume);
		return tmp;
	}
};

// ������
struct CommisionInfo {
	InstrumentIdType instrument;
	///������������
	double	OpenRatioByMoney;
	///����������
	double	OpenRatioByVolume;
	///ƽ����������
	double	CloseRatioByMoney;
	///ƽ��������
	double	CloseRatioByVolume;
	///ƽ����������
	double	CloseTodayRatioByMoney;
	///ƽ��������
	double	CloseTodayRatioByVolume;

	CommisionInfo() { memset(this, 0, sizeof(CommisionInfo)); }
	std::string FromStr(const char* str)
	{
		String16 date = {0};
		InstrumentIdType inst = {0};		
		sscanf(str, "%[^,],%[^,],%lf,%lf,%lf,%lf,%lf,%lf", date, inst, &OpenRatioByMoney, &OpenRatioByVolume, 
			&CloseRatioByMoney, &CloseRatioByVolume, &CloseTodayRatioByMoney, &CloseTodayRatioByVolume);
		strcpy(instrument, inst);
		return date;
	}
	std::string ToStr() const
	{
		char tmp[64] = {0};
		sprintf(tmp, "%s,%g,%g,%g,%g,%g,%g", instrument, OpenRatioByMoney, OpenRatioByVolume,
			CloseRatioByMoney, CloseRatioByVolume, CloseTodayRatioByMoney, CloseTodayRatioByVolume);
		return tmp;
	}
};


/ *
 * @brief PositionData �ֲֽṹ��
 * @note �ֲֵ����¼ۡ��ֲ�ӯ�����ֲ���ֵ����ʵʱ���£������û�ȡʱ�ټ���
 * /
struct PositionData {
	UserStrategyIdType user_tag;			/ **< �û����Զ����־ * /
	Symbol symbol;							/ **< ������� * /
	PriceType last_price;					/ **< ���¼� * /
	PriceType open_price;					/ **< �ڻ������־���(����������)����Ʊ�� �ɱ���* /
	PriceType position_profit;				/ **< �ֲ�ӯ��(����ӯ��)  * /
	VolumeType open_volume;					/ **< �ֲܳ���=���յľ��ֲ���������λ����(�ڻ�)����(��Ʊ)�� * /
	PriceType position_cost;				/ **< �ֲ���ֵ����ֵ�� �ڻ�����Լ��ֵ���иܸˣ� ��Ʊ�����л��𡢹�Ʊ��ֵ  * /
	// �ڻ�����
	OrderDirection direction;				/ **< �������� * /	
	VolumeType today_volume;				/ **< ��� * /
	VolumeType yestd_volume;				/ **< ��� * /
	VolumeType enable_today_volume;			/ **< ���ý�� * /
	VolumeType enable_yestd_volume;			/ **< ������� * /
	PriceType using_margin;					/ **< ռ�ñ�֤�� * /
	// ����Ϊ��Ʊ����
	VolumeType current_volume;				/ **< ��ǰ���� * /
	VolumeType enable_volume;				/ **< �������� * /	

	PositionData() { memset(this, 0, sizeof(PositionData)); }
};

/ *
 * @brief TradeData �ɽ��ر��ṹ��
 * /
struct TradeData {
	Symbol symbol;							/ **< ������� * /
	NumberIdType order_id;					/ **< ������ * /
	NumberIdType local_order_id;			/ **< ���ض����� * /
	NumberIdType trade_id;					/ **< �ɽ��� * /
	UserStrategyIdType user_tag;			/ **< �û����Զ����־ * /
	baselib::DateTime trade_time;			/ **< �ɽ�ʱ�� * /
	OrderDirection direction;				/ **< �������� * /
	OpenCloseFlag open_close_flag;			/ **< ��ƽ��־ * /
	PriceType trade_price;					/ **< �ɽ��۸� * /
	VolumeType trade_volume;				/ **< �ɽ����� * /
	PriceType trade_commision;				/ **< ������(��Ʊ�Լ���) * /

	TradeData() { memset(this, 0, sizeof(TradeData)); }
};

/ *
 * @brief AccountData �ʽ��˻��ر��ṹ��
 * /
struct	AccountData 
{
	String16 account_id;				/ **< �ʽ��˺� * /
	String16 broker_id;					/ **< ���͹�˾�˺� * /
	MoneyType money_type;				/ **< ��ֵ���� * /
	PriceType asset_balance;			/ **< ���ʲ�,��Ӧ�ڻ��Ķ�̬Ȩ�� * /
	PriceType enable_balance;			/ **< �����ʽ� * /
	PriceType withdraw_balance;			/ **< ��ȡ�ʽ� * /
	PriceType frozen_balance;			/ **< �����ʽ𣨽�֤���ʽ����-�����ʽ� * /
	PriceType position_profit;			/ **< ����ӯ�������ݳֲ��Լ��㣩 * /
	PriceType close_profit;				/ **< ƽ��ӯ������Ʊ�Լ��㣩* /
	PriceType commision;				/ **< �����ѣ���Ʊ�Լ��㣩 * /

	//����Ϊ��Ʊ�ֶ�
	PriceType market_value;				/ **< ��Ʊ��ֵ * /
	PriceType fund_balance;				/ **< �ʽ������� * /

	//����Ϊ�ڻ��ֶ�
	PriceType static_balance;			/ **< ��̬Ȩ�� * /	
	PriceType margin_balance;			/ **< ռ�ñ�֤�� * /
	PriceType delivery_margin;			/ **< ���֤�� * /

	AccountData() { memset(this, 0, sizeof(AccountData)); money_type = MONEY_RMB; }
};

/ *
 * @brief MoneyFlowData �ʽ���ˮ�ṹ��
 * /
struct	MoneyFlowData {
	typedef char StringType[16];

	StringType account_id;			/ **< �ʽ��˺� * /
	StringType broker_id;			/ **< ���͹�˾�˺� * /
	char flow_id[20];				/ **< ��ˮ�� * /
	MoneyType money_type;			/ **< ��ֵ���ͣ� 1-���� 2-��Ԫ 3-�۱� * /
	char business_abstract[32];		/ **< ҵ��ժҪ * /
	char abstract_type[12];			/ **< ժҪ��� * /
	double change_value;			/ **< ������� * /
	double reserve_value;			/ **< ��� * /
	Symbol symbol;					/ **< ������� * /
	OrderDirection direction;		/ **< �������� * /
	double trade_price;				/ **< �ɽ��۸� * /
	int trade_volume;				/ **< �ɽ����� * /
	double trade_value;				/ **< �ɽ���� * /
	baselib::DateTime trade_time;	/ **< �ɽ�ʱ�� * /
	double commission;				/ **< Ӷ�� * /
	double transfer_fee;			/ **< ������ * /
	double stamp_tax;				/ **< ӡ��˰ * /
	double other_fee;				/ **< �������� * /
};


//������TICK���� (64B)
struct BaseTick
{
	Symbol symbol;						
	/ *Simple* /baselib::DateTime date_time;			
	PriceType last_price;
	VolumeType volume;	//������ܳɽ���
	double amount;		//������ܳɽ���
	//Ϊ��������ϵ�ļ򵥣���������ֶ�
	PriceType pre_close;
	PriceType today_open;
	PriceType today_high;
	PriceType today_low;
};

//��ƱTICK���� (114B)
struct StockTick : public BaseTick 
{
	PriceType up_limit;  //��ͣ��
	PriceType drop_limit; //��ͣ��
	PriceType buy_price[PRICE_LEVEL_NUM];	//��1~5��
	PriceType sell_price[PRICE_LEVEL_NUM];	//��1~5��
	VolumeType buy_volume[PRICE_LEVEL_NUM];		//1~5��������ί����
	VolumeType sell_volume[PRICE_LEVEL_NUM];	//1~5��������ί����
};

//��ȨTick����
struct OptionTick : public BaseTick 
{
	double position;			//�ֲ���
	VolumeType buy_volume;	
	VolumeType sell_volume;
	PriceType buy_price;	
	PriceType sell_price;
	//��Ȩ�ķ���ָ��
	REAL	delta;				//��Ȩ�۸�仯/��ļ۸�仯
	REAL	vega;				//
	REAL	bid_implied_volatility;
	REAL	ask_implied_volatility;
	PriceType	ref_last_price;	//���ۼ�
};

//�ڻ�TICK����
struct FutureTick : public BaseTick 
{
	PriceType up_limit;			//��ͣ��
	PriceType drop_limit;		//��ͣ��
	double position;			//�ֲ���
	PriceType pre_settlement;	//������
	VolumeType pre_open_interest; //�򿪲���
	VolumeType buy_volume;	
	VolumeType sell_volume;
	PriceType buy_price;	
	PriceType sell_price;
};
//ָ��TICK���� (72B)
struct IndexTick : public BaseTick 
{
	int advance_num;	//���Ǽ���
	int decline_num;	//�µ�����
};

#pragma pack()

class CErrorInfo
{
public:
	CErrorInfo():ErrorCode(0),ErrorMsg(""){}
	int    ErrorCode;
	std::string ErrorMsg;
};

/ *
 * @brief MarketDataCallback MarketDataApi�Ļص������ӿ�
 * /
class MarketDataSpi
{
public:
	/ *
	 * @brief OnMarketPrice �г�����ص�
	 * @param market_price �г�����ṹ��,�����صĽ��
	 * /
	virtual void OnMarketPrice(BaseTick* tick) = 0;

	/ *
	 * @brief OnError �������˷��ص�ʧ����Ϣ
	 * @param request_name �������������ĺ�������,common��ʾδ֪�ĺ�������
	 * @param error_msg ��ϸ������Ϣ
	 * @param request_id ��Ӧ������ID
	 * /
	virtual void OnError(const std::string& request_name, const std::string& error_msg, const std::string& request_id) {}

	/ *
	 * @brief OnDisconnect ��������Ͽ�����
	 * /
	virtual void OnDisconnect(const std::string& reson) {};

	/ *
	 * @brief OnReconnected �����������
	 * /
	virtual void OnConnect() {}
};

class TradeSpi
{
public:
	/ *
	 * @brief OnError �������˷��ص�ʧ����Ϣ
	 * @param error_msg ��ϸ������Ϣ
	 * @param request_id ��Ӧ������ID
	 * /
	virtual void OnError(int request_id, const std::string& error_msg) {}

	/ *
	 * @brief OnReconnected ��������Ͽ�����
	 * /
	virtual void OnConnect() {}

	/ *
	 * @brief OnDisconnect ��������Ͽ�����
	 * /
	virtual void OnDisconnect(const std::string& reson) {}

	/ *
	 * @brief OnOrder ί�ж����ر��������ر�
	 * /
	virtual void OnOrder(OrderData* order_data) {}

	/ *
	 * @brief OnOrderError ί�ж����ر����󡢳�������
	 * /
	virtual void OnOrderError(OrderData* order_data) {}	

	/ *
	 * @brief OnTrade �ɽ��ر�
	 * /
	virtual void OnTrade(TradeData* trade_data) {}

	/ *
	 * @brief OnOrder ��ѯί�лر�
	 * /
	virtual void OnQryOrder(int req_id, OrderData* order_data, const std::string& err, bool is_last) {}

	/ *
	 * @brief OnTrade �ɽ��ر�
	 * /
	virtual void OnQryTrade(int req_id, TradeData* trade_data, const std::string& err, bool is_last) {}

	/ *
	 * @brief OnAccount ��ѯ�ʽ�ر�
	 * /
	virtual void OnQryAccount(int req_id, AccountData* trade_data, const std::string& err, bool is_last) {}

	/ *
	 * @brief OnPosition ��ѯ�ֲֻر�
	 * /
	virtual void OnQryPosition(int req_id, PositionData* trade_data, const std::string& err, bool is_last) {}

	virtual void OnInstrumentInfo(const BaseInstrumentInfo& info, bool is_last) {}
	virtual void OnMarginInfo(const MarginInfo& info, bool is_last) {}
	virtual void OnCommisionInfo(const CommisionInfo& info, bool is_last) {}

};
*/

}

#endif	//EYEGLE_STRUCT_H_