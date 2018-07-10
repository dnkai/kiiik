#pragma once

#include <map>
#include <list>
#include "WRStruct.h"
#include "Baselib/SpinLock.h"
#include "Protocol.h"
#include "NetworkAsio/TcpSession.h"

namespace kiiik {

using namespace network_asio;
using namespace baselib;

// ������ĳ��symbol��session��
class SessionContainer
{
public:
	SessionContainer():tick_(NULL){}

	void Append(TcpSession*);
	void Remove(TcpSession*);

	void SetTick(CQuotation*);
	CQuotation* GetTick() ;

	void Send(char *buf, int len);

private:
	CQuotation *tick_;
	SpinLock tick_mutex_;

	list<TcpSession*> sub_sessions_; // �����˵�session
	SpinLock sub_sess_mutex_;
};

typedef map<CSymbol, SessionContainer*> Symbol2Sessions;
typedef map<TcpSession*, list<CSymbol> > Session2Symbols;

class RWDataService
{
public:
	RWDataService(void);
	~RWDataService(void);

	void OnAccept(TcpSession* sock);
	void OnDiscon(TcpSession *tcp_sock);

	void HandleQuoteReq(QuoteReq*,TcpSession*);
	void HandleWriteReq(WtiteReq *,TcpSession*);
	void HandleSubsReq(SubsReq*,TcpSession*);
	void HandleUnsubsReq(UnsubReq*,TcpSession*);
	void HandleSymbosReq(TcpSession*);

private:
	void Subscribe(const CSymbol& _Sym, TcpSession *_Sess);
	void UnSubscribe(const CSymbol& _Sym, TcpSession *_Sess);

	SessionContainer* GetSessionContainer(const CSymbol& _Sym, bool _Wri_Sub = true);

	//map<CSymbol, CQuotation> ticks_; // ���µı���
	//baselib::SpinLock ticks_mutex_;

	Symbol2Sessions sub_sym_sessions_;// ������ĳ��symbol��session��
	baselib::SpinLock sub_sym_sessions_mutex_;

	Session2Symbols sess_symbols_;//ÿ��socketά��һ�������б���socket�Ͽ�ʱ�ܿ���ȡ�����ĸ�socket������
	baselib::SpinLock sess_symbols_mutex;
};

}