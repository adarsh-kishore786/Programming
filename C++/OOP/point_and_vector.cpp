/*
	point_and_vector.cpp

	Illustrates combining points and vectors.
*/

#include "vector_class.h"
#include "point_class.h"

int main()
{
	Point3D p {1, 2, 3};
	Vector3D v {2, 2, -3};

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}