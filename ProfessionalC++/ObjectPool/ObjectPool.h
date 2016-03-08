#include <queue>
#include <stdexcept>
#include <memory>

using std::queue;
using std::shared_ptr;

template <typename T>
class ObjectPool
{
public:
	ObjectPool(size_t chunkSize = kDefaultChunkSize)
		throw(std::invalid_argument, std::bad_alloc);
	shared_ptr<T> acquireObject();
	void releaseObject(shared_ptr<T> obj);

protected:
	queue<shared_ptr<T>> mFreeList;
	size_t mChunkSize;
	static const size_t kDefaultChunkSize = 10;

	void allocateChunk();

private:
	ObjectPool(const ObjectPool<T>& src);
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs);
};
