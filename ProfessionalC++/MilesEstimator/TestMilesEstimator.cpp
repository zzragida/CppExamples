#include <iostream>
#include "EfficientCarMilesEstimator.h"

using namespace std;

int main()
{
	MilesEstimator milesEstimator;
	milesEstimator.setGallonsLeft(2);
	cout << "Normal estimator can go " << milesEstimator.getMilesLeft() << " more miles." << endl;

	EfficientCarMilesEstimator estimator;
	estimator.setGallonsLeft(2);
	cout << "Efficient estimator can go " << estimator.getMilesLeft() << " more miles." << endl;

	return 0;
}
