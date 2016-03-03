#include <new>

class MemoryDemo
{
public:
	MemoryDemo() {}
	virtual ~MemoryDemo() {}

	void* operator new(std::size_t size);
	void operator delete(void* ptr) noexcept;
	void* operator new[](std::size_t size);
	void operator delete[](void* ptr) noexcept;
	void* operator new(std::size_t size, const std::nothrow_t&) noexcept;
	void operator delete(void* ptr, const std::nothrow_t&) noexcept;
	void* operator new[](std::size_t size, const std::nothrow_t&) noexcept;
	void operator delete[](void* ptr, const std::nothrow_t&) noexcept;

	void* operator new(std::size_t size, int extra);
	void operator delete(void* ptr, int extra) noexcept;
};
