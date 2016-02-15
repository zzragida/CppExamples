#include <iostream>

#include "../algorithms/algorithms.h"
#include "../classes/classes.h"

int main()
{
  // algorithms
  std::cout << "algorithms " << std::endl;
  copy_range_of_elements();
  copy_values_in_range();
  sort_range_of_elements();
  swap_containers();
  swap_values();

  // classes
  std::cout << "classes " << std::endl;
  copy_and_swap();
  delegate_behavior_to_derived_classes();
  lexicographic_ordering();
  non_member_interface();
  pimpl();
  rule_of_five();
  rule_of_zero();
  virtual_constructor();
}
