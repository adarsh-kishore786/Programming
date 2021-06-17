#include "vector_class.h"
#include <iostream>
using namespace std;

Vector3D::Vector3D(double x=0, double y=0, double z=0)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void Vector3D::print() const
{
	cout << "Vector<" << m_x << ", " << m_y << ", " 
		<< m_z << ">" << endl;
}