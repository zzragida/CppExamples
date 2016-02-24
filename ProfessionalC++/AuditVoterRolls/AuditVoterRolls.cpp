#include <algorithm>
#include <functional>
#include <map>
#include <list>
#include <iostream>
#include <utility>
#include <string>
#include <set>

using namespace std;

typedef map<string, list<string>> VotersMap;
typedef pair<const string, list<string>> DistrictPair;

set<string> getDuplicates(const VotersMap& votersByDistrict)
{
	list<string> allNames;
	for (auto& district : votersByDistrict)
		allNames.insert(allNames.end(), district.second.begin(), district.second.end());

	allNames.sort();

	set<string> duplicates;
	for (auto it = allNames.cbegin(); it != allNames.cend(); ++it)
	{
		it = adjacent_find(it, allNames.cend());
		if (it == allNames.end())
		{
			break;
		}
		duplicates.insert(*it);
	}

	return duplicates;
}

void auditVoterRolls(VotersMap& votersByDistrict,
										 const list<string>& convictedFelons)
{
	set<string> toRemove = getDuplicates(votersByDistrict);

	toRemove.insert(convictedFelons.cbegin(), convictedFelons.cend());

	for_each(votersByDistrict.begin(), votersByDistrict.end(),
		[&toRemove](DistrictPair& district) {
				auto it = remove_if(district.second.begin(), district.second.end(),
							[&](const string& name) {
									return (toRemove.count(name) > 0);
							});
		});
}

int main()
{
	VotersMap voters = {
		{"Orange", {"Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog"}},
		{"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark"}},
		{"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}
	};

	list<string> felons = {"Bob Buffalo", "Charles Cat"};

	auto printDistrict = [](const DistrictPair& district) {
			cout << district.first << ":";
			for (auto& str : district.second)
				cout << " {" << str << "}";
			cout << endl;
	};

	cout << "Before Audit: " << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;

	auditVoterRolls(voters, felons);

	cout << "After Audit: " << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;

	return 0;
}
