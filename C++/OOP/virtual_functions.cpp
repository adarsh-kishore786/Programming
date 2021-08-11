#include <iostream>
#include <string>
#include <string_view>
#include <array>

class Animal
{
protected:
    std::string m_name{};

    Animal(std::string_view name)
        : m_name{name}
    {}

    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = delete;

public:
    const std::string& getName() const { return m_name; }
    virtual std::string speak() const { return "???"; }
};

class Cat : public Animal
{
public:
    Cat(std::string_view name)
        : Animal(name)
    {}

    virtual std::string speak() const { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string_view name)
        : Animal(name)
    {}

    virtual std::string speak() const { return "Woof"; }
};

int main()
{
    const Cat cat{ "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << "\n";

    const Dog dog{ "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " <<
        dog.speak() << "\n";

    const Animal *pAnimal{ &cat };
    std::cout << "cat is named " << pAnimal->getName() << ", and it says " <<
        pAnimal->speak() << "\n";

    const Animal *pDog{ &dog };
    std::cout << "dog is named " << pDog->getName() << ", and it says " <<
        pDog->speak() << "\n\n";

    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const auto
        animals{ std::to_array<const Animal*>({&fred, &garbo, &misty,
        &pooky, &truffle, &zeke}) };

    for (const auto animal : animals)
        std::cout << animal->getName() << " says " << animal->speak() << "\n";
}
