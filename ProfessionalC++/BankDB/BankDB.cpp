#include <utility>
#include "BankDB.h"

using namespace std;

bool BankDB::addAccount(const BankAccount& acct)
{
	auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));

	return res.second;
}

void BankDB::deleteAccount(int acctNum)
{
	mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int acctNum) throw(out_of_range)
{
	auto it = mAccounts.find(acctNum);

	if (it == mAccounts.end())
	{
		throw out_of_range("No account with that name");
	}

	return it->second;
}

BankAccount& BankDB::findAccount(const string& name) throw(out_of_range)
{
	for (auto& p : mAccounts)
	{
		if (p.second.getClientName() == name)
		{
			return p.second;
		}
	}

	throw out_of_range("No account with that name");
}

void BankDB::mergeDatabase(BankDB& db)
{
	mAccounts.insert(db.mAccounts.begin(), db.mAccounts.end());

	db.mAccounts.clear();
}
