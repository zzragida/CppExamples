#include <memory>
#include <utility>

class Base
{
public:
  virtual ~Base()
  {
  }

  virtual Base* clone() const = 0;
};

class Derived : public Base
{
public:
  Derived* clone() const override
  {
    return new Derived(*this);
  }
};

void foo(std::unique_ptr<Base> original)
{
  std::unique_ptr<Base> copy{ original->clone() };
}

void virtual_constructor()
{
  std::unique_ptr<Base> p = std::make_unique<Derived>();
  foo(std::move(p));
}
