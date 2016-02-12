#include <utility>

class resource 
{
  int x = 0;
};

class foo
{
public:
  foo() : p {new resource{}}
  {
  }

  foo(const foo& other) : p {new resource{*(other.p)}}
  {
  }

  foo(foo& other) : p {other.p}
  {
    other.p = nullptr;
  }

  foo& operator=(foo other)
  {
    swap(*this, other);
    return *this;
  }

  ~foo()
  {
    delete p;
  }

  friend void swap(foo& first, foo& second)
  {
    using std::swap;
    swap(first.p, second.p);
  }

private
  resource* p;
};


int main()
{
  foo f1, f2, f3;
  f2 = f1;
  f3 = std::move(f1);

  swap(f2, f3);
}
