#include <utility>
#include <string>

int main()
{
  std::string s1 = "Hello";
  std::string s2 = "World";

  using std::swap;
  swap(s1, s2);
}
