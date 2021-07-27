/*
	overloading_io.cpp
*/

#include <iostream>

class Point
{
private:
	double m_x {};
	double m_y {};
	double m_z {};

public:
	Point(double x=0.0, double y=0.0, double z=0.0)
	: m_x {x}, m_y {y}, m_z {z} {}

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
	friend std::istream& operator>>(std::istream& in, Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "Point: (" << point.m_x << ", " << point.m_y << ", " 
		<< point.m_z << ") ";

	return out; // Return ostream so that we can do chaining
}

std::istream& operator>>(std::istream& in, Point& point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in; // For chaining
}

int main()
{
	const Point point1 {2.0, 3.0, 4.0};
	const Point point2 {6.0, 7.5, 8.0};

	Point point {};
	std::cout << "Enter a point: ";
	std::cin >> point;

	std::cout << point1 << "\n" << point2 << std::endl;
	std::cout << point << "\n";

	return 0;
}