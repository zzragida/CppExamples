#include <iostream>
#include "Muffin.h"

using namespace std;

int main()
{
	cout << "First, let's create a muffin in code and output it." << endl;

  Muffin m;
  m.setDescription("Giant_Blueberry_Muffin");
  m.setSize(42);
  m.setHasChocolateChips(false);

  m.output();

  cout << "Now we'll create a muffin from a string stream" << endl;

  istringstream instream("My_Muffin 2 true");
  Muffin m2 = createMuffin(instream);

  m2.output();

	return 0;
}
