#include "CableCompany.h"

using namespace std;

void CableCompany::addPackage(const string& packageName,
															const bitset<kNumChannels>& channels)
{
	mPackages.insert({packageName, channels});
}

void CableCompany::removePackage(const string& packageName)
{
	mPackages.erase(packageName);
}

void CableCompany::newCustomer(const string& name, const string& package)
	throw(out_of_range)
{
	auto it = mPackages.find(package);
	if (it == mPackages.end())
	{
		throw out_of_range("Invalid package");
	}
	else
	{
		mCustomers.insert({name, it->second});
	}
}

void CableCompany::newCustomer(const string& name,
															 const bitset<kNumChannels>& channels)
{
	mCustomers.insert({name, channels});
}

void CableCompany::addChannel(const string& name, int channel)
{
	auto it = mCustomers.find(name);
	if (it != mCustomers.end())
	{
		it->second.set(channel);
	}
}

void CableCompany::removeChannel(const string& name, int channel)
{
	auto it = mCustomers.find(name);
	if (it != mCustomers.end())
	{
		it->second.reset(channel);
	}
}

void CableCompany::addPackageToCustomer(const string& name, const string& package)
{
	auto itPack = mPackages.find(package);
	auto itCust = mCustomers.find(name);
	if (itCust != mCustomers.end() && itPack != mPackages.end())
	{
		itCust->second |= itPack->second;
	}
}

void CableCompany::deleteCustomer(const string& name)
{
	mCustomers.erase(name);
}

bitset<kNumChannels>& CableCompany::getCustomerChannels(const string& name)
	throw(out_of_range)
{
	auto it = mCustomers.find(name);
	if (it != mCustomers.end())
	{
		return it->second;
	}

	throw out_of_range("No customer with that name");
}
