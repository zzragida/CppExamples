#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	list<string> dictionary, bWords;

	dictionary.push_back("aardvark");
	dictionary.push_back("ambulance");

	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");

	bWords.push_back("bathos");
	bWords.push_back("balderdash");

	if (bWords.size() > 0)
	{
		auto iterLastB = --(bWords.cend());

		list<string>::iterator it;
		for (it = dictionary.begin(); it != dictionary.end(); ++it)
		{
			if (*it > *iterLastB)
				break;
		}

		dictionary.splice(it, bWords);
	}

	for (auto it = dictionary.cbegin(); it != dictionary.cend(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
