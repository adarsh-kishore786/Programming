/*
	sprite_movement.cpp

	This program demonstrates the 
	possibilities of a simple program
	for the movements of a sprite on
	the world map.
*/

#include <iostream>
#include <complex>
using namespace std;

complex<double> init(double x, double y)
{
	complex<double> z {x, y};
	return z;
}

double X(complex<double>& z)
{
	return z.real();
}

double Y(complex<double>& z)
{
	return z.imag();
}

void setX(complex<double>& z, double x)
{
	z = {x, z.imag()};
}

void setY(complex<double>& z, double y)
{
	z = {z.real(), y};
}

void set(complex<double>& z, double x, double y)
{
	z = {x, y};
}

void print_coord(complex<double>& z)
{
	cout << "Current coordinates: " << z << endl;
}

int main()
{
	complex<double> coord = init(0, 0);
	print_coord(coord);

	cout << "Would you like to move? (Y/N) ";

	char ch;
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		double delx, dely;
		cout << "Enter the change in x and y coordinates:\n";
		cout << "del X: ";
		cin >> delx;

		cout << "del Y: ";
		cin >> dely;

		setX(coord, X(coord) + delx);
		setY(coord, Y(coord) + dely);

		cout << "New X coordinate: " << X(coord) << endl;
		cout << "New Y coordinate: " << Y(coord) << endl; 

		print_coord(coord);
	}
	else
	{
		cout << "Would you like to give new coordinates? (Y/N) ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			double xn, yn;
			cout << "New X: ";
			cin >> xn;

			cout << "New Y: ";
			cin >> yn;

			coord = init(xn, yn);

			print_coord(coord);
		}
		else
			cout << "I\"ll take that for a no.";
	}
}