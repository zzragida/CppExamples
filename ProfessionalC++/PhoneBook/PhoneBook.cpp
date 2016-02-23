#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template <class T>
void printMap(const T& m)
{
	for (auto& p : m)
	{
		cout << p.first << "(Phone: " << p.second << ")" << endl;
	}
	cout << "----------" <<endl;
}

int main()
{
	unordered_map<string, string> um;
	um.insert({
		{"Marc G.", "123-456789"},
		{"Zulija N", "987-654321"},
		{"Scott K", "654-987321"}
	});
	printMap(um);

	um.insert(make_pair("John D", "321-987654"));
	um["Johan G."] = "963-258147";
	um["Freddy K."] = "999-258147";
	um.erase("Freddy K.");
	printMap(um);

	int bucket = um.bucket("Marc G.");
	cout << "" << bucket
			 << " which contains the following "
			 << um.bucket_size(bucket) << " elements:" << endl;

	auto liter = um.cbegin(bucket);
	auto literEnd = um.cend(bucket);
	while (liter != literEnd)
	{
		cout << "\t" << liter->first << "(Phone: "
				 << liter->second << ")" << endl;
		++liter;
	}
	cout << "---------" << endl;

	cout << "There are " << um.bucket_count() << " buckets." << endl;
	cout << "Average number of elements in a bucket is " << um.load_factor() << endl;

	return 0;
}
