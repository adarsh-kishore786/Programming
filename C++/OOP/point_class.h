#ifndef POINT_CLASS
#define POINT_CLASS

class Vector3D;
class Point3D
{
private:
	double m_x {};
	double m_y {};
	double m_z {};

public:
	Point3D(double x=0, double y=0, double z=0);
	void print() const;
	void moveByVector(const Vector3D& v);
};

#endif