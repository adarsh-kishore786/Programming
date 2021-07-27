#ifndef VECTOR_CLASS
#define VECTOR_CLASS
#include "point_class.h"

class Vector3D
{
private:
	double m_x {};
	double m_y {};
	double m_z {};

public:
	Vector3D(double x=0, double y=0, double z=0);
	void print() const;
	friend void Point3D::moveByVector(const Vector3D& v);
};

#endif