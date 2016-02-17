#include <iostream>
#include <sstream>

#include "WeatherPrediction.h"

using namespace std;

void WeatherPrediction::setCurrentTempFahrenheit(int inTemp)
{
	mCurrentTempFahrenheit = inTemp;
}

void WeatherPrediction::setPositionOfJupiter(int inDistanceFromMars)
{
	mDistanceFromMars = inDistanceFromMars;
}

int WeatherPrediction::getTomorrowTempFahrenheit()
{
	return (mDistanceFromMars / 1000) + mCurrentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain()
{
	return 0.5;
}

void WeatherPrediction::showResult()
{
	cout << "Result: " << (getChanceOfRain() * 100) << " chance."
			 << " Temp. " << getTomorrowTempFahrenheit() << endl;
}

std::string WeatherPrediction::getTemperature() const
{
	stringstream ss;
	ss << mCurrentTempFahrenheit;
	return ss.str();
}
