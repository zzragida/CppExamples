#include <memory>

namespace ns
{
<<<<<<< HEAD
	class foo
	{
	public:
		foo();
		~foo();

		foo(foo&&);
		foo& operator=(foo&&);

	private:
		class impl;
		std::unique_ptr<impl> pimpl;
	};

	class foo::impl
	{
	public:
		void do_internal_work()
		{
			internal_data = 5;
		}

	private:
		int internal_data = 0;
	};

	foo::foo() : pimpl{std::make_unique<impl>()}
	{
		pimpl->do_internal_work();
	}

	foo::~foo() = default;
	foo::foo(foo&&) = default;
	foo& foo::operator=(foo&&) = default;
}


void pimpl()
{
  ns::foo f;
=======
    class foo
    {
    public:
        foo();
        ~foo();
        foo(foo&&);
        foo& operator=(foo&&);

    private:
        class impl;
        std::unique_ptr<impl> pimpl;
    };

    class foo::impl
    {
    public:
        void do_internal_work()
        {
            internal_data = 5;
        }

    private:
        int internal_data = 0;
    };

    foo::foo() : pimpl{ std::make_unique<impl>() }
    {
        pimpl->do_internal_work();
    }

    foo::~foo() = default;
    foo::foo(foo&&) = default;
    foo& foo::operator=(foo&&) = default;
}

void pimpl()
{
    ns::foo f;
>>>>>>> 8505a6b837e3110b37f52de576ea1f36384decdd
}

