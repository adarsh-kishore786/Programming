/*
	structs2.cpp

	Explores further aspects of structs.
*/

#include <iostream>

struct Point3D
{
	double x{};
	double y{};
	double z{};
};

// Structs can contain other structs
struct Sphere
{
	Point3D centre{};
	double radius{};
};

// We can assign a struct to a function as argument
void printPoint(Point3D p)
{
	std::cout << "(" << p.x << ", " << p.y
			  << ", " << p.z << ")" << std::endl;
}

Point3D getPoint(double x, double y, double z)
{
	return {x, y, z}; // We declared that struct Point3D would be 
					  // returned so no need to specify again
}

void printSphere(Sphere s)
{
	std::cout << "Centre: ";
	printPoint(s.centre);

	std::cout << "Radius: " << s.radius << std::endl;
}

Point3D getOrigin()
{
	return {}; //Default initialization used
}

Sphere getSphere(Point3D centre, double radius)
{
	return {centre, radius};
}

int main()
{
	Point3D p = getPoint(4.5, 33.6, 0);
	printPoint(p);

	Point3D o = getOrigin();
	printPoint(o);
	std::cout << std::endl;

	Sphere s = getSphere(p, 6.7);
	printSphere(s);
	std::cout << std::endl;

	Sphere s1 { {5, 6, 7}, 9};
	printSphere(s1);

	std::cout << "Size of Point3D struct is " << sizeof(Point3D) << std::endl;
	std::cout << "Size of Sphere is " << sizeof(Sphere) << std::endl;
}