//�������������������Ҫʵ��д���顢���ĵȹ���

#pragma once

#include <qstring>
#include <QObject> 
#include "NetworkAsio/TcpClient.h"
#include "Protocol.h"
#include "WRStruct.h"
#include "Timer/Timer.h"

using namespace kiiik;
using namespace network_asio;

class SubsTblModel;

class WRClient : public QObject, public SocketReaderSpi, public ReConnSpi, public TimerSpi
{
	Q_OBJECT

public:
	WRClient();
	virtual ~WRClient();

	// test
	void Testing();

	void Login(UserIdType id, PwdType pwd);
	void Logout();
	void TestTimerWrite(); // �ö�ʱ�����д for test
	void Quote(const CSymbol &);
	void Sub(std::vector<CSymbol> &inst_vec); // ����
	void UnSub(std::vector<CSymbol> &inst_vec);
	void CheckVersion();
	void DownloadVersion();
	//��update�ļ����µ��ļ�copy����ȷ��λ�á�
	void CopyFilesInUpdateFolder();

public slots:
	void GetSymbols(); // ���Լ�б�

private:
	virtual void OnReceive(TcpSession *tcp_sock, char* buf, int len);

	//�����һ�����ӡ� �������Ͽ�����successΪfalse
	virtual void SockConn(bool success);
	//����Ͽ�
	virtual void SockDisconn();
	//��������
	virtual void SockReConn();

	virtual void OnTimer();

	list<string> m_symbols; // �Ѿ����Ĺ���
	void Split(const std::string& s, const std::string delim,std::vector<std::string>* ret);
	void Trim(std::string &s);

	TcpClient *client_;
	bool is_login_;
	UserIdType id_;
	PwdType pwd_;

	string update_folder_;//���°汾�ͻ���
	string bin_folder_;//��VersionUpdate.exe

	// �������з��������˿�
	struct IP_PORT{
		string ip;
		string port;
	};
	vector<IP_PORT> ip_ports_;
	string config_file_;
	string version_cfg_file_;
	float version_; // �ͻ��˰汾��
	void readxml();

signals:
	void SignalNetErr(const QString &);//�������
	void SignalLogin(const QString &);
	void SignalSymbols(CSymbol *, int);
	void SignalQuote(const CQuotation *);
	void SignalTickRsp(const CQuotation *); // tick����
};

