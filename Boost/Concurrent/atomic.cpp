#include <boost/intrusive_ptr.hpp>
#include <boost/atomic.hpp>

class X
{
public:
	typedef boost::intrusive_ptr<X> pointer;
	X() : refcount_(0) {}

private:
	mutable boost::atomic<int> refcount_;

	friend void intrusive_ptr_and_ref(const X* x)
	{
		x->refcount_.fetch_add(1, boost::memory_order_relaxed);
	}

	friend void intrusive_ptr_release(const X* x)
	{
		if (x->refcount_.fetch_sub(1, boost::memory_order_release) == 1)
		{
			boost::atomic_thread_fence(boost::memory_order_acquire);
			delete x;
		}
	}
};

int main()
{
	X::pointer x = new X;
	return 0;
}
