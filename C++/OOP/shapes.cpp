#include <iostream>

class Shape
{
public:
    virtual std::ostream& print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Shape& sh)
    {
        return sh.print(os);
    }

    virtual ~Shape() {}
};

class Point
{
private:
    int m_x;
    int m_y;
    int m_z;

public:
    Point(int x=0, int y=0, int z=0)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p)
    {
        std::cout << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return os;
    }
};

class Triangle : public Shape
{
private:
    Point m_a {};
    Point m_b {};
    Point m_c {};

public:
    Triangle(Point a, Point b, Point c):
        m_a{ a }, m_b{ b }, m_c{ c } {}

    std::ostream& print(std::ostream& os) const override
    {
        os << "Triangle(" << m_a << ", " << m_b << ", " << m_c << ")";
        return os;
    }

    virtual ~Triangle() = default;
};

class Circle : public Shape
{
private:
    Point m_center {};
    int m_radius {};

public:
    Circle(Point center, int radius):
        m_center{center}, m_radius{radius} {}

    std::ostream& print(std::ostream& os) const override
    {
        os << "Circle(" << m_center << ", radius " << m_radius << ")";
        return os;
    }

    virtual ~Circle() = default;
};

int main()
{
    Circle c{ Point{ 1, 2, 3 }, 7 };
    std::cout << c << '\n';

    Triangle t{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}};
    std::cout << t << '\n';

    return 0;
}
