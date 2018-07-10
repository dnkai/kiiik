#pragma once

#include <memory.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Baselib/QueueBuffer.h"
#include "Baselib/SpendTime.h"

#define APP_LOG(LEVEL) baselib::AppLogFinisher() = baselib::AppLogInput(baselib::LEVEL, __FILE__, __LINE__)

namespace baselib {

extern SpendTime spend_time;

/*
 * @brief LogLevel ��־�㼶ö��ֵ.
 * @note �رղ㼶�����ӡ�κζ�������־��ǰ���ʾֻ��ӡ��ǰ�����ϵĲ㼶����Ϣ.
 * �羯��㼶ֻ��ӡ����ʹ������־�����Բ㼶��ӡ������־��Ϣ.
 */
typedef enum {
	LOG_LEVEL_OFF         = 0,	/**< �رղ㼶 */
	LOG_LEVEL_ERROR       = 1,	/**< ����㼶 */
	LOG_LEVEL_WARN        = 2,	/**< ����㼶 */
	LOG_LEVEL_INFO		  = 3,	/**< ��Ϣ�㼶 */
	LOG_LEVEL_SUCCESS     = 4,	/**< �ɹ��㼶 */
	LOG_LEVEL_DEBUG		  = 5	/**< ���Բ㼶 */
} LogLevel;

struct LogData {
	LogLevel level;
	char file_name[128];
	int line;
	char message[128];

	LogData() : level(LOG_LEVEL_INFO), line(0) {
		memset(file_name, 0, 128);
		memset(message, 0, 128);
	}

	LogData(LogLevel l, const char* filename, int line_, const char* msg)
		: level(l)
		, line(line_)
	{
		memcpy(file_name, filename, 128);
		memcpy(message, msg, 128);
	}
};

class BASELIB_API AppLog : public QueueBuffer<LogData, 50> {
public:
	enum{
		DEFAULT_BUF_LEN			= 50,				/**< Ĭ�ϻ������ĳ��� */
		DEFAULT_LOG_MAX_SIZE	= 1000 * 1024,		/**< Ĭ����־����,1M */
		DEFAULT_LOG_MAX_NUM		= 10				/**< Ĭ����־���� */
	};

public:
	~AppLog();
	static AppLog* GetInstance();

	void set_level(LogLevel level) {
		if (m_is_running) { return; }	//��־�߳̿�ʼ���к����ٸı�ֵ.
		m_level = level;
	}

	LogLevel get_level() const {
		return m_level;
	}

	void set_max_size(int size) {
		if (m_is_running) { return; }	//��־�߳̿�ʼ���к����ٸı�ֵ.
		m_max_size = size > 0 ? size : m_max_size;	//����0����Ч.
	}

	int get_max_size() const {
		return m_max_size;
	}

	void set_max_num(int num) {
		if (m_is_running) { return; }	//��־�߳̿�ʼ���к����ٸı�ֵ.
		m_max_num = num > 0 ? num : m_max_num;	//����0����Ч.
	}

	int get_max_num() const {
		return m_max_num;
	}

	/*
	 * @brief InitLogConfig �������ļ���ʼ����־�ĸ�������.
	 * @param config �����ļ�����.
	 */
	void InitLog();

private:
	AppLog();

	virtual bool Consume(const LogData& val);

	LogLevel StringToLevel(const char* value);
	const char*  LevelToString(LogLevel level);

	/*
	 * @brief GetNowTime ��ȡ��ǰʱ��.
	 * @return ����ʱ���ʽ 2013-11-13 09:03:18.189
	 */
	std::string GetNowTime();

	void OpenLogFile();

	/*
	 * @brief RollLogFile ����ļ���С�������ã��������������־�ļ�.
	 */
	void RollLogFile();

private:
	static AppLog* m_instance;

	LogLevel m_level;			/**< ��־�㼶 */
	int m_max_size;				/**< ��־������� */
	int m_max_num;				/**< ѭ����־����������������������Զ�ɾ���������־�ļ� */
	FILE* m_file;				/**< ��־�ļ����� */
	bool m_is_running;			/**< ��־�߳��Ƿ��Ѿ������� */

	string m_file_path;
	string m_err_file_path;
	bool m_append_console; // �Ƿ��ӡ���ͻ���
};

class AppLogInput
{    
private:
	char m_file_name[128];
	int m_line;
	char m_message[128];
	LogLevel m_level;
public:
	AppLogInput(LogLevel l, const char* filename, int line) : m_level(l), m_line(line)
	{  
		memcpy(m_file_name, filename, 128);
		memset(m_message, 0, 128);
	};

	friend class AppLogFinisher;

	AppLogInput& operator<<(const string& msg) { 
		strcat(m_message, msg.c_str()); 
		return *this; 
	}

	AppLogInput& operator<<(const char* msg) { 
		strcat(m_message, msg); 
		return *this; 
	}

	AppLogInput& operator<<(char c) 
	{ 
		sprintf(m_message, "%s%c", m_message, c);
		return *this;
	}

	AppLogInput& operator<<(int n) {
		sprintf(m_message, "%s%d", m_message, n);
		return *this;
	}

	AppLogInput& operator<<(unsigned int n) {
		sprintf(m_message, "%s%d", m_message, n);
		return *this;
	}

	AppLogInput& operator<<(double d) {
		sprintf(m_message, "%s%f", m_message, d);
		return *this;
	}

	AppLogInput& operator<<(long l) {
		sprintf(m_message, "%s%ld", m_message, l);
		return *this;
	}

	AppLogInput& operator<<(long long l) {
		sprintf(m_message, "%s%ld", m_message, l);
		return *this;
	}
};

class AppLogFinisher
{
public:
	void operator=(AppLogInput& input) {
		AppLog::GetInstance()->Push(LogData(input.m_level, input.m_file_name, input.m_line, input.m_message));
	};
};

}