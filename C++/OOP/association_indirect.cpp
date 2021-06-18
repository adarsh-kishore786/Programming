/*
    association_indirect.cpp

    Associations between objects can be indirect 
    also, as this program demonstrates.
*/

#include <iostream>
#include <string>

class Car
{
private:
    std::string m_name;
    int m_id;

public:
    Car(const std::string& name, int id)
    {
        m_name = name;
        m_id = id;
    }

    const std::string& getName() const { return m_name; }
    int getId() const { return m_id; }
};

class CarLot
{
private:
    static Car s_carLot[4];

public:
    static Car* getCar(int id)
    {
        for (int i = 0; i < 4; i++)
            if (s_carLot[i].getId() == id)
                return &(s_carLot[i]);
        return nullptr;
    }
};

Car CarLot::s_carLot[4] { { "Prius", 4 }, { "Corolla", 17 }, {  "Accord", 84 }, 
                            { "Matrix", 62 } };

class Driver
{
private:
    std::string m_name;
    int m_carId; // we're associated with the car by ID rather than pointer
public:
    Driver(const std::string& name, int carId)
    {
        m_name = name;
        m_carId = carId;    
    }

    const std::string& getName() const { return m_name; }
    int getCarId() const { return m_carId; }
};

int main()
{
    Driver d { "Franz", 17 };
    Car *car { CarLot::getCar(d.getCarId()) };

    if (car)
        std::cout << d.getName() << " is driving a "<< car->getName() << "\n";
    else
        std::cout << d.getName() << " couldn't find his car!\n";

    return 0;   
}