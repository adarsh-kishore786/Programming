#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>

using int16 = std::int_least16_t;
using int8 = std::int_least8_t;

class FixedPoint2
{
private:
    int16 m_integral_part;
    int8 m_fractional_part;

public:
    FixedPoint2(int16 integral_part=0, int8 fractional_part=0):
        m_integral_part{integral_part}, m_fractional_part{fractional_part}
    {
        if (m_integral_part < 0 || m_fractional_part < 0)
        {
            if (m_integral_part > 0)
                m_integral_part = -m_integral_part;
            if (m_fractional_part > 0)
                m_fractional_part = -m_fractional_part;
        }
    }

    FixedPoint2(double num)
    {
        m_integral_part = static_cast<int16>(std::round(num * 100) / 100);
        m_fractional_part = static_cast<int8>(std::round(num * 100) - m_integral_part * 100);
    }

    operator double() const
    {
        return m_integral_part + m_fractional_part / 100.0;
    }

    FixedPoint2& operator-()
    {
        m_integral_part = -m_integral_part;
        m_fractional_part = -m_fractional_part;

        return *this;
    }

    friend const std::string operator==(const FixedPoint2& fp1, const FixedPoint2& fp2);
};

std::ostream& operator<<(std::ostream& os, const FixedPoint2& fp)
{
    os << static_cast<double>(fp);
    return os;
}

std::istream& operator>>(std::istream& in, FixedPoint2& fp)
{
    double d{};
    in >> d;
    fp = FixedPoint2(d);

    return in;
}

const std::string operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    if (fp1.m_integral_part == fp2.m_integral_part && fp1.m_fractional_part == fp2.m_fractional_part)
        return "true";
    return "false";
}

const FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
    double num{static_cast<double>(fp1) + static_cast<double>(fp2)};
    return FixedPoint2(num);
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

// int main()
// {
// 	FixedPoint2 a{ 34, 56 };
// 	std::cout << a << '\n';
//
// 	FixedPoint2 b{ -2, 8 };
// 	std::cout << b << '\n';
//
// 	FixedPoint2 c{ 2, -8 };
// 	std::cout << c << '\n';
//
// 	FixedPoint2 d{ -2.08 };
// 	std::cout << d << '\n';
//
// 	FixedPoint2 e{ 0, -5 };
// 	std::cout << e << '\n';
//
// 	std::cout << static_cast<double>(e) << '\n';
//
//     // FixedPoint2 a{4321.25};
//     // std::cout << a << "\n";
//
// 	return 0;
// }

int main()
{
	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;
}
