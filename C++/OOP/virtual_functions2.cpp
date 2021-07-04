#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    Animal(std::string name): m_name { name } {}

    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    const std::string& getName() const { return m_name; }
    std::string speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string name): Animal { name } {}

    std::string speak() const { return "Meow"; }
};

class Dog: public Animal 
{
public:
    Dog(std::string name): Animal { name } {}

    std::string speak() const { return "Woof"; }
};

int main()
{
    Cat cat { "Cat" };
    Animal &rCat { cat };
    Animal *pCat { &cat };

    std::cout << "cat is a " << cat.getName() << 
        " and says " << cat.speak() << "\n";
    std::cout << "rCat is a " << rCat.getName() <<
        " and says " << rCat.speak() << "\n";
    std::cout << "pCat is a " << pCat->getName() << 
        " and says " << pCat->speak() << "\n\n";

    Dog dog { "dog" };
    Animal &rDog { dog };
    Animal *pDog { &dog };

    std::cout << "dog is a " << dog.getName() << 
        " and says " << dog.speak() << "\n";
    std::cout << "rDog is a " << rDog.getName() << 
        " and says " << rDog.speak() << "\n";
    std::cout << "pDog is a " << pDog->getName() << 
        " and says " << pDog->speak() << "\n";

    return 0;
}