#include <map>
#include <string>
#include <stdexcept>

class BankAccount
{
public:
	BankAccount(int acctNum, const std::string& name) : 
		mAcctNum(acctNum), mClientName(name)
	{
	}

	void setAcctNum(int acctNum)
	{
		mAcctNum = acctNum;
	}
	
	int getAcctNum() const
	{
		return mAcctNum;	
	}

	void setClientName(const std::string& name)
	{
		mClientName = name;
	}

	std::string getClientName() const
	{
		return mClientName;
	}

protected:
	int mAcctNum;
	std::string mClientName;
};


class BankDB
{
public:
	BankDB() {}

	bool addAccount(const BankAccount& acct);

	void deleteAccount(int acctNum);

	BankAccount& findAccount(int acctNum) throw(std::out_of_range);
	BankAccount& findAccount(const std::string& name) throw(std::out_of_range);

	void mergeDatabase(BankDB& db);

protected:
	std::map<int, BankAccount> mAccounts;
};
