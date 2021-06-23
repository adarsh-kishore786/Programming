#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage_per_move;
    int m_gold;

public:
    Creature(const std::string& name, char symbol, 
        int health, int damage_per_move, int gold)
    {
        m_name = name;
        m_symbol = symbol;
        m_health = health;
        m_damage_per_move = damage_per_move;
        m_gold = gold;
    }

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamagePerMove() const { return m_damage_per_move; }
    int getGold() const { return m_gold; }

    void reduceHealth(int amount) { m_health -= amount; }
    bool isDead() { return (m_health <= 0); }
    void addGold(int amount) { m_gold += amount; }
};

class Player: public Creature
{
protected:
    int m_level;

public:
    Player(const std::string& name):
        Creature(name, '@', 10, 1, 0),
        m_level { 1 } {}

    void levelUp()
    {
        m_level++;
        m_damage_per_move++;   
    }

    int getLevel() const { return m_level; }
    bool hasWon() const { return m_level >= 20; }
};

class Monster: public Creature
{
public:
    enum class Type
    {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    static const Creature& getDefaultCreature(Type type)
    {
        static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData {
          {  { "dragon", 'D', 20, 4, 100 },
             { "orc", 'o', 4, 2, 25 },
             { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(type));
    }

public:
    Monster(Type monster_type):
        Creature {getDefaultCreature(monster_type)}
        {}

    static Monster getRandomMonster()
    {
        int val = std::rand()/(RAND_MAX * 1.0) * static_cast<int>(Type::max_types);
        return Monster { static_cast<Type>(val) };
    }
};

int main()
{
    // std::cout << "Enter your name: ";
    // std::string name {};
    // std::cin >> name;

    // Player pl { name };
    // std::cout << "Welcome, " << pl.getName() << "\n";
    // std::cout << "You have " << pl.getHealth() << " health and are carrying "
    //          << pl.getGold() << " gold.\n";

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    for (int i = 0; i < 10; i++)
    {
        Monster m { Monster::getRandomMonster() };
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }
}