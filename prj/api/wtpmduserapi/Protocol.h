#ifndef PROTOCOL_H
#define PROTOCOL_H


#include "wtpmduserapi/WtpUserApiStruct.h"


#define REQ_LOGIN '0'
#define REQ_QUOTE '1'// ѯ�� ������
#define REQ_WRITE '2' // д���� 
#define REQ_SUBSCRIBE '3'//����
#define REQ_UNSUB '4'//ȡ������
#define REQ_SYMBOLS '5'//���Լ�б�
#define REQ_VERSION '6' // 

#define RSP_LOGIN 'a'
#define RSP_SYMBOLS 'b'//���غ�Լ�б�
#define RSP_QUOTE_DATA 'c'//����һ��tick����,��CWtpQuotationField
#define RSP_SUB_DATA 'd'
//#define RSP_SUBSCRIBE 'c'
//#define RSP_WRITE 'd'
#define RSP_VERSION 'e'

typedef char ClientRequestType;
typedef char UserIdType[20];
typedef char PwdType[20];

#pragma pack(1)
struct ProtocolHead 
{
	ClientRequestType type;
	ProtocolHead (ClientRequestType t = '0') : type(t) {}
};

struct QuoteReq : public ProtocolHead{
	CWtpSymbolField sym;
	QuoteReq():ProtocolHead(REQ_QUOTE){}
};
struct WtiteReq : public ProtocolHead{
	CWtpQuotationField data;
	WtiteReq():ProtocolHead(REQ_WRITE){}
};
struct SubsReq : public ProtocolHead{
	int num;
	CWtpSymbolField sym[0];
	SubsReq():ProtocolHead(REQ_SUBSCRIBE), num(0) {}
};
struct UnsubReq : public ProtocolHead{
	int num;
	CWtpSymbolField sym[0];
	UnsubReq():ProtocolHead(REQ_UNSUB), num(0) {}
};
struct SymbolsReq : public ProtocolHead{
	SymbolsReq():ProtocolHead(REQ_SYMBOLS) {}
};

struct DataRsp : public ProtocolHead {
	CWtpQuotationField data;
	DataRsp():ProtocolHead(RSP_SUB_DATA){}
};
struct SymbolsRsp : public ProtocolHead {
	int num;
	CWtpSymbolField sym[0]; // ���غ�Լ�б�
	SymbolsRsp() : ProtocolHead(RSP_SYMBOLS), num(0) {}
};


struct LoginRequest : public ProtocolHead {
	UserIdType user_id;
	PwdType pwd;
	LoginRequest() : ProtocolHead(REQ_LOGIN) {}
};
struct LoginResponse : public ProtocolHead {
	bool succeed;
	char msg[32]; // 0"�˺Ų�����" \\ 1"�������";
	LoginResponse() : ProtocolHead(RSP_LOGIN), succeed(true) { memset(msg, 0, 32); }
};

#define IS_NEW_VERSION 0
#define WANT_TO_DOWNLOAD -1
#define UPDATE_END -2
struct VersionRequest : public ProtocolHead {
	float version; // ���ذ汾��
	VersionRequest(float v) : ProtocolHead(REQ_VERSION), version(v){}
};
struct VersionResponse : public ProtocolHead {
	char file_name[256];
	//�ֽ�����0��ʾ������¡�>0��ʾ�ڴ��ļ���-1��ʾ���ļ�������ϡ�
	int file_length;
	char content[0];
	VersionResponse() :ProtocolHead(RSP_VERSION){ }
};

#endif