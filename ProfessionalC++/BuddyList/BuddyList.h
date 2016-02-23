#include <map>
#include <string>
#include <list>

using std::multimap;
using std::string;
using std::list;

class BuddyList
{
public:
	BuddyList();

	void addBuddy(const string& name, const string& buddy);

	void removeBuddy(const string& name, const string& buddy);

	bool isBuddy(const string& name, const string& buddy) const;

	list<string> getBuddies(const string& name) const;

protected:
	multimap<string, string> mBuddies;
};
