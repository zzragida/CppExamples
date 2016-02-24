#include <boost/atomic.hpp>

class spinLock
{
public:
	spinLock() : state_(Unlocked) {}

	void lock()
	{
		while (state_.exchange(Locked, boost::memory_order_acquire) == Locked)
		{
		}
	}

	void unlock()
	{
		state_.store(Unlocked, boost::memory_order_release);
	}

private:
	typedef enum { Locked, Unlocked } LockState;
	boost::atomic<LockState> state_;
};

int main()
{
	spinLock s;
	s.lock();

	s.unlock();
	return 0;
}
