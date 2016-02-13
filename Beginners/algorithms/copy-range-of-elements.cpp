#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

std::vector<int> target2(5);
std::vector<int> target3;

template <typename RangeOfInts>
void foo(RangeOfInts source)
{
  std::vector<int> target1{std::begin(source),
                           std::end(source)};

  std::copy(std::begin(source), std::end(source),
            std::begin(target2));

  std::copy(std::begin(source), std::end(source),
            std::back_inserter(target3));
}

void copy_range_of_elements()
{
  std::vector<int> vec = {5, 4, 3, 2, 1};  
  foo(vec);
}
