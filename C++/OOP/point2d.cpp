/*
	point2d.cpp

	Defines a Point2d class.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point2d;

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	Point2d(double x=0, double y=0): m_x {x}, m_y {y}
	{}

	void print()
	{
		cout << "Point2d(" << m_x << ", " << m_y << ")" << endl;
	}

	friend double distanceFrom(const Point2d& p1, const Point2d& p2);
};

double distanceFrom(const Point2d& p1, const Point2d& p2)
{
	double dx = p1.m_x - p2.m_x;
	double dy = p1.m_y - p2.m_y;
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main()
{
	Point2d first {};
	Point2d second { 3.0, 4.0 };

	first.print();
	second.print();

	cout << "Distance between the two points: " << distanceFrom(first, second) << endl;

	return 0;
}