#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> numbers = {1, 2, 3, 5, 6, 3, 4, 1};

  int count = std::count(std::begin(numbers),
                         std::end(numbers),
                         3);
}
