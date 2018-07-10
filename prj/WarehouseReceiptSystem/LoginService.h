#pragma once

#include <vector>
#include <map>
#include "MarketDefine.h"
//#include "Baselib/IniConfig.h"
#include "Protocol.h"
#include "NetworkAsio/TcpSession.h"

#include "Baselib/Global.h"

namespace kiiik {

using namespace std;
using namespace baselib;

enum E_Authority // �û���Ȩ��
{
	E_Read = 0,//˭�����Բ顢����
	E_Write, //
	E_Admin, //���ã������޸������ļ�
};

class LoginService
{
public:
	LoginService();
	~LoginService(void);

	void OnDiscon(network_asio::TcpSession *tcp_sock);//����map_session_authority_

	void HandleReq( LoginRequest *,  network_asio::TcpSession *);
	void HandleReq(VersionRequest *, network_asio::TcpSession *);

	bool CanWrite(network_asio::TcpSession *);//Ҫ��д��Ȩ�޲���

private:

	bool loginSuccess(UserIdType, PwdType, string&, network_asio::TcpSession *);

	void readVersionXml();//����������ʱ��һ�μ���
	void readLoginXml();//ÿ�����µĿͻ���������ʱ��
	void writexml();

	map<network_asio::TcpSession *, E_Authority> map_session_authority_;

	struct xmlAccDetail 
	{
		string user;
		string password;
		E_Authority authority;//"admin" "read" "write"
	};
	vector<xmlAccDetail> acc_details_;
	string acc_cofig_file_;
	string version_cfg_file_;
	string update_folder_; // �°�ͻ���Ŀ¼
	float version_; // �ͻ������°汾��
};

}
