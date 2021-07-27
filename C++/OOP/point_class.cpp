#include "point_class.h"
#include "vector_class.h"

#include <iostream>
using namespace std;

Point3D::Point3D(double x=0, double y=0, double z=0)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void Point3D::print() const
{
	cout << "Point(" << m_x << ", " << m_y << ", " 
		<< m_z << ")" << endl;
}

void Point3D::moveByVector(const Vector3D& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}