#include <iostream>
#include <cstdint>

using int32 = std::int_least32_t;
using int8  = std::int_least8_t;

class Average
{
private:
    int32 m_sum {};
    int8 m_num {};

public:
    Average& operator+=(int n)
    {
        m_sum += n;
        m_num++;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Average& av);
};

std::ostream& operator<<(std::ostream& out, const Average& av)
{
    double avg = av.m_sum * 1.0 / av.m_num;
    std::cout << avg;
    return out;
}

int main()
{
    Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';
}
