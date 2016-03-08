#include "ObjectPool.h"

using namespace std;

template <typename T>
const size_t ObjectPool<T>::kDefaultChunkSize;

template <typename T>
ObjectPool<T>::ObjectPool(size_t chunkSize) throw(invalid_argument, bad_alloc)
{
	if (chunkSize == 0) {
		throw invalid_argument("");
	}
	mChunkSize = chunkSize;
	allocateChunk();
}

template <typename T>
void ObjectPool<T>::allocateChunk()
{
	for (size_t i = 0; i < mChunkSize; ++i) {
		mFreeList.push(make_shared<T>());
	}
}

template <typename T>
shared_ptr<T> ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		allocateChunk();
	}
	auto obj = mFreeList.front();
	mFreeList.pop();
	return obj;
}

template <typename T>
void ObjectPool<T>::releaseObject(shared_ptr<T> obj)
{
	mFreeList.push(obj);
}
