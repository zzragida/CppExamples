#include <iostream>
#include "AccessList.h"

using namespace std;

int main()
{
	AccessList fileX = {"nsolter", "kelp", "baduser"};
	fileX.removeUser("baduser");

	if (fileX.isAllowed("nsloter"))
	{
		cout << "nsolter has permissions" << endl;
	}

	if (fileX.isAllowed("baduser"))
	{
		cout << "baduser has permissions" << endl;
	}

	auto users = fileX.getAllUsers();
	for (auto& user : users)
	{
		cout << user << " ";
	}
	cout << endl;

	return 0;
}
