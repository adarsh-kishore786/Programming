/*
	friend_functions.cpp

	Explores concept of friend functions.
*/

#include <iostream>
using namespace std;

class Temperature;
class Humidity; // Class prototypes

class Temperature
{
private:
	int m_temp;

public:
	Temperature(int temp=30)
	{
		m_temp = temp;
	}

	friend void printWeather(const Temperature &temp, const Humidity &humidity);
};

class Humidity
{
private:
	int m_humidity;

public:
	Humidity(int humidity=0)
	{
		m_humidity = humidity;
	}

	friend void printWeather(const Temperature &temp, const Humidity &humidity);
};

void printWeather(const Temperature &temp, const Humidity &humidity)
{
	cout << "The temperature is " << temp.m_temp << "\u00b0C and the " 
		<< "humidity is " << humidity.m_humidity << "%" << endl;
}

int main()
{
	Temperature temp { 27 };
	Humidity humidity { 92 };
	printWeather(temp, humidity);
}
