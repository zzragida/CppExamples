#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

list<string> getTotalEnrollment(const vector<list<string>>& courceStudents,
																const list<string>& droppedStudents)
{
	list<string> allStudents;

	for (auto& lst : courceStudents)
	{
		allStudents.insert(allStudents.end(), lst.begin(), lst.end());
	}

	allStudents.sort();
	allStudents.unique();

	for (auto& str : droppedStudents)
	{
		allStudents.remove(str);
	}

	return allStudents;
}

void readStudentList(list<string>& students, ifstream& istr)
{
	string name;
	while (getline(istr, name))
	{
		cout << "Read name " << name << endl;
		students.push_back(name);
	}
}

void readCourseLists(vector<list<string>>& lists)
{
	for (int i = 1; ; i++)
	{
		ostringstream ostr;
		ostr << "course" << i << ".txt";
		
		ifstream istr(ostr.str().c_str());
		if (!istr)
		{
			cout << "Failed to open " << ostr.str() << endl;
			break;
		}

		list<string> newList;
		readStudentList(newList, istr);
		lists.push_back(newList);
	}
}

void readDroppedStudents(list<string>& students)
{
	ifstream istr("dropped.txt");
	readStudentList(students, istr);
}

int main()
{
	vector<list<string>> courseStudents;
	list<string> droppedStudents;

	readCourseLists(courseStudents);
	readDroppedStudents(droppedStudents);

	list<string> finalList = getTotalEnrollment(courseStudents, droppedStudents);
	
	copy(finalList.begin(), finalList.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}
