#include <string>

class WeatherPrediction
{
public:
	virtual void setCurrentTempFahrenheit(int inTemp);
	virtual void setPositionOfJupiter(int inDistanceFromMars);
	virtual int getTomorrowTempFahrenheit();
	virtual double getChanceOfRain();
	virtual void showResult();
	virtual std::string getTemperature() const;

protected:
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};
