/*
	average.cpp
*/

#include <iostream>

class Average
{
private:
	double m_avg {};
	int m_count {};

public:
	Average(): m_avg {}, m_count {} {}
	Average(const Average& avg)
	{
		m_avg = avg.m_avg;
		m_count = avg.m_count;
	}

	friend Average& operator+(Average& avg, int val);
	friend Average& operator+=(Average& avg, int val);

	friend Average& operator-(Average& avg, int val);
	friend Average& operator-=(Average& avg, int val);
	friend std::ostream& operator<<(std::ostream& out, const Average& avg);
};

Average& operator+(Average& avg, int val)
{
	int total = avg.m_avg * avg.m_count + val;
	avg.m_count++;
	avg.m_avg = total * 1.0 / avg.m_count;

	return avg;
}

Average& operator+=(Average& avg, int val)
{
	return operator+(avg, val);
}

Average& operator-(Average& avg, int val)
{
	return operator+(avg, -val);
}

Average& operator-=(Average& avg, int val)
{
	return operator+=(avg, -val);
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	out << avg.m_avg << " ";
	return out;
}

int main()
{
	Average avg {};

	avg += 4;
	std::cout << avg << "\n";

	avg += 8;
	std::cout << avg << "\n";

	avg += 24;
	std::cout << avg << "\n";

	avg -= 10;
	std::cout << avg << "\n";

	(avg += 6) += 10;
	std::cout << avg << "\n";

	Average copy { avg };
	std::cout << copy << "\n";
}