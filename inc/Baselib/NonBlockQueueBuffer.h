#pragma once

#include "Baselib/Thread.h"
#include <deque>

namespace baselib{

// ���д�С�����ޣ�Push���������� 

template <class T>
class NonBlockQueueBuffer : public Thread 
{
public:
	NonBlockQueueBuffer() {}

	virtual void Consume(T& item) = 0;

	virtual void Push(const T& item)
	{
		Locker locker(&queue_lock_);
		eve_queue_.push_back(item);
		cond_.Signal();
	}

	virtual void Terminate()
	{
		Stop();
		cond_.Signal();
	}

private:
	virtual void OnRun() 
	{
		//������ʱ���ȼ����û������
		if (IsRuning())
		{
			T item;
			while (PopEvent(item))
			{
				Consume(item);
			}
		}

		while (IsRuning()) 
		{
			mutex_.Lock();
			cond_.Wait(&mutex_);
			mutex_.Unlock();
			if (!IsRuning()) { break; }

			T item;
			while (PopEvent(item))
			{
				Consume(item);
			}
		}
	}

	bool PopEvent(T& item)
	{
		Locker locker(&queue_lock_);
		if (eve_queue_.size() == 0)
		{
			return false;
		} 
		else
		{
			item = eve_queue_.front();
			eve_queue_.pop_front();
			return true;
		}
	}

protected:
	Mutex mutex_;
	Condition cond_;
	std::deque<T> eve_queue_;
	SpinLock queue_lock_;
};

}