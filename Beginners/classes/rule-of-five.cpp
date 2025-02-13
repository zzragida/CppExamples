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

  foo(foo& other) : p{other.p}
  {
    other.p = nullptr;
  }

  foo& operator=(const foo& other)
  {
    if (&other != this)
    {
      delete p;
      p = nullptr;
      p = new resource{*(other.p)};
    }
    return *this;
  }

  foo& operator=(foo&& other)
  {
    if (&other != this)
    {
      delete p;
      p = other.p;
      other.p = nullptr;
    }
    return *this;
  }

  ~foo()
  {
    delete p;
  }

private:
  resource* p;
};

void rule_of_five()
{
  foo f;
}
