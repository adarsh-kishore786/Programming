#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
private:
    int m_x;
    int m_y;

public:
    // Default constructor
    Point2D(): m_x{0}, m_y{0} {}

    Point2D(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    // overloaded output operator
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point)
    {
        os << "(" << point.m_x << ", " << point.m_y << ")";
        return os;
    }

    // Access functions
    void setPoint(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
};

#endif