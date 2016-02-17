#include <iostream>
#include "AirlineTicket.h"

using namespace std;

AirlineTicket::AirlineTicket()
{
	bHasEliteSuperRewardsStatus = false;
	mPassengerName = "Unknown Passenger";
	mNumberOfMiles = 0;
}

AirlineTicket::~AirlineTicket()
{
}

int AirlineTicket::calculatePriceInDollars() const
{
	if (getHasEliteSuperRewardsStatus())
	{
		return 0;
	}

	return static_cast<int>((getNumberOfMiles() * 0.1));
}

string AirlineTicket::getPassengerName() const
{
	return mPassengerName;
}

void AirlineTicket::setPassengerName(string inName)
{
	mPassengerName = inName;
}

int AirlineTicket::getNumberOfMiles() const
{
	return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int inMiles)
{
	mNumberOfMiles = inMiles;
}

bool AirlineTicket::getHasEliteSuperRewardsStatus() const
{
	return bHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool inStatus)
{
	bHasEliteSuperRewardsStatus = inStatus;
}
