#include <iostream>
#include <string>

class Person
{   
public:
    std::string m_name {};
    int m_age {};

    Person(const std::string& name = "", int age = 0):
        m_name { name }, m_age { age } {}

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class BaseballPlayer : public Person
{
public: 
    double m_battingAverage {};
    int m_homeRuns {};

    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0)
    {
        m_battingAverage = battingAverage;
        m_homeRuns = homeRuns;
    }
};

int main()
{
    BaseballPlayer joe {};
    joe.m_name = "Joe"; 

    std::cout << joe.getName() << "\n";
    return 0;
}