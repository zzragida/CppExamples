#include <tuple>

class foo
{
public:
  foo(int n_, char c_, double d_) : n{n_}, c{c_}, d{d_}
  {
  }

  friend bool operator<(const foo& lh, const foo& rh)
  {
    return std::tie(lh.n, lh.c, lh.d) < 
           std::tie(rh.n, rh.c, rh.d);
  }

private:
  int n;
  char c;
  double d;
};

void lexicographic_ordering()
{
  foo f1(1, 'a', 3.14);
  foo f2(1, 'b', 2.78);

  if (f1 < f2)
  {
    return;
  }
}
