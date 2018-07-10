//�������������������Ҫʵ��д���顢���ĵȹ���

#ifndef WR_CLIENT_H
#define WR_CLIENT_H

#include <memory>
#include "NetworkAsio/TcpClient.h"
#include "Protocol.h"
#include "wtpmduserapi/WtpMdApi.h"
#include "Baselib/QueueBuffer.h"
#include "RspMsg.h"

using namespace baselib;
using namespace network_asio;



class WRClient : public CWtpMdApi, public SocketReaderSpi, public ReConnSpi, public QueueBuffer<std::shared_ptr<RspMsgItem>, 50>
{

public:
	WRClient();
	virtual ~WRClient();

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release();	

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress);

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CWtpMdSpi *pSpi);

	///�û���¼����
	virtual int ReqUserLogin(CWtpReqUserLoginField *pReqUserLoginField);

	///�ǳ�����
	virtual int ReqUserLogout(CWtpUserLogoutField *pUserLogout);

	///��ѯ��Լ�б�
	virtual int ReqQrySymbol();

	///��ѯ������Լ�۸�
	virtual int ReqQryQuotation(CWtpSymbolField *pInstrumentID);

	///�������顣
	///@param vecInstrumentID ��ԼID  
	///@remark 
	virtual int ReqSubQuotation(CWtpSymbolField *pInstrumentID, int nCount);

	///�˶����顣
	///@param vecInstrumentID ��ԼID  
	///@remark 
	virtual int ReqUnSubQuotation(CWtpSymbolField *pInstrumentID, int nCount);
	

private:
	virtual void OnReceive(TcpSession *tcp_sock, char* buf, int len);

	//�����һ�����ӡ� �������Ͽ�����successΪfalse
	virtual void SockConn(bool success);
	//����Ͽ�
	virtual void SockDisconn();
	//��������
	virtual void SockReConn();

	virtual bool Consume(const std::shared_ptr<RspMsgItem>& val);

	list<string> m_symbols; // �Ѿ����Ĺ���
	void Split(const std::string& s, const std::string delim,std::vector<std::string>* ret);
	void Trim(std::string &s);

	TcpClient *client_;
	bool is_login_;
	UserIdType id_;
	PwdType pwd_;

	

	// �������з��������˿�
	struct IP_PORT{
		string ip;
		string port;
	};
	vector<IP_PORT> ip_ports_;
	
	
	CWtpMdSpi *spi_;
	int nRequestID_;

};

#endif // !WR_CLIENT_H