#include <iostream>
#include <memory>
#include "AirlineTicket.h"

using namespace std;

int main()
{
	AirlineTicket myTicket;

	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	int cost = myTicket.calculatePriceInDollars();
	cout << "This ticket will cost $" << cost << endl;

	shared_ptr<AirlineTicket> myTicket2(new AirlineTicket());
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	int cost2 = myTicket2->calculatePriceInDollars();
	cout << "This other ticket will cost $" << cost2 << endl;

	AirlineTicket* myTicket3 = new AirlineTicket();
	delete myTicket3;

	return 0;
}
