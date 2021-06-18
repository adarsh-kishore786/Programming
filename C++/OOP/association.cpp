/*
    association.cpp

    This program demonstrates association between
    objects. Association models a 'uses-a' 
    relationship between objects.
*/

#include <iostream>
#include <functional>
#include <cstdint>
#include <string>
#include <vector>

// Forward declaration
class Patient;

class Doctor
{
private:
    std::string m_name {};
    std::vector<std::reference_wrapper<const Patient>> m_patient {};

public:
    Doctor(const std::string name)
    {
        m_name = name;
    }

    void addPatient(Patient& patient);

    friend std::ostream& operator<<(std::ostream& os, const Doctor& doctor);

    const std::string& getName() const { return m_name; }
};

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctor{};

    void addDoctor(const Doctor& doctor)
    {
        m_doctor.push_back(doctor); 
    }

public:
    Patient(const std::string& name)
    {
        m_name = name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);

    const std::string& getName() const { return m_name; }

    friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
    m_patient.push_back(patient);
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& os, const Doctor& doctor)
{
    if (doctor.m_patient.empty())
    {
        os << doctor.getName() << " has no patients right now.";
        return os;
    }

    os << doctor.getName() << " is seeing patients: ";
    for (const auto& patient : doctor.m_patient)
        os << patient.get().getName() << " ";
    return os;
}  

std::ostream& operator<<(std::ostream& os, const Patient& patient)
{
    if (patient.m_doctor.empty())
    {
        os << patient.getName() << " is seeing no doctor right now.";
        return os;
    }
    os << patient.getName() << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctor)
        os << doctor.get().getName() << " ";
    return os;
}

int main()
{
    Patient dave { "Dave" };
    Patient frank { "Frank" };
    Patient betsy { "Betsy" };

    Doctor james { "James" };   
    Doctor scott { "Scott" };

    james.addPatient(dave);

    scott.addPatient(dave);
    scott.addPatient(betsy);

    std::cout << dave << "\n";
    std::cout << frank << "\n";
    std::cout << betsy << "\n";

    std::cout << james << "\n";
    std::cout << scott << "\n";

    return 0;
}