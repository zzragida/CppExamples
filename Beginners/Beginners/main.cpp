#include "../algorithms/algorithms.h"
#include "../classes/classes.h"
#include "../lambda/lambda.h"

#include <iostream>

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
  //copy_and_swap();
  delegate_behavior_to_derived_classes();
  lexicographic_ordering();
  non_member_interface();
  pimpl();
  rule_of_five();
  rule_of_zero();
  virtual_constructor();

  // lambda
  std::cout << "lambda " << std::endl;
  declaring_lambda_expressions1();
  declaring_lambda_expressions2();
  calling_lambda_expressions1();
  calling_lambda_expressions2();
  nesting_lambda_expressions();
  high_order_lambda_expressions();
  function_lambda_expression();
  template_lambda_expression();
  eh_lambda_expression();
}
