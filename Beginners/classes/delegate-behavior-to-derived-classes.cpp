
template<typename derived>
class base
{
public:
  void do_something()
  {
    static_cast<derived*>(this)->do_something_impl();
  }

private:
  void do_something_impl()
  {
  }
};

class foo : public base<foo>
{
public:
  void do_something_impl()
  {
  }
};

class bar : public base<bar>
{
};

template<typename derived>
void use(base<derived>& b)
{
  b.do_something();
}

void delegate_behavior_to_derived_classes()
{
  foo f;
  use(f);

  bar b;
  use(b);
}
