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
          {  { "dragon", 'D', 10, 4, 100 },
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

void printStatus(const Player& p)
{
    int health = p.getHealth();
    if (p.getHealth() < 0)
        health = 0;
    std::cout << "You have " << health << " health and are carrying "
             << p.getGold() << " gold.\n";
}

bool runAwaySuccessful()
{
    double val = std::rand()/(RAND_MAX * 1.0);
    return (val > 0.5);
}

void gameOver(const Player& p)
{
    std::cout << "Sorry, you lost!\n";
    printStatus(p);
    exit(0);
}

void levelUp(Player& p, Monster& m)
{
    std::cout << m.getName() << " is dead!\n";
    std::cout << "You got " << m.getGold() << " gold!\n";
    p.addGold(m.getGold());
    p.levelUp();
    std::cout << "You levelled upto level " << p.getLevel() << "!\n\n";
}

void attackPlayer(Player& p, const Monster& m)
{
    int damage = m.getDamagePerMove();
    std::cout << m.getName() << " attacked! You lost " << damage << " HP.\n";
    p.reduceHealth(damage);

    if (p.getHealth() <= 0)
        gameOver(p);
}

void attackMonster(Player& p, Monster& m)
{
    std::cout << "You attacked first! ";

    std::cout << m.getName() << " lost " << p.getDamagePerMove() << " HP.\n";

    m.reduceHealth(p.getDamagePerMove());
    if (m.getHealth() <= 0)
        levelUp(p, m);

    if (m.getHealth() > 0) attackPlayer(p, m);
}

bool runAway(Player& p, Monster& m)
{
    if (runAwaySuccessful())
    {
        std::cout << "You ran away!\n\n";
        return true;
    }
    std::cout << "You failed to run!\n\n";
    attackPlayer(p, m);
    return false;
}

bool isWon(Player& p)
{
    return p.getLevel() >= 20;
}

char getChoice()
{
    char choice {};
    do 
    { 
        std::cout << "Would you like to (R)un or (F)ight?: ";
        std::cin >> choice;

        if (choice != 'r' && choice != 'R' && choice != 'f' && choice != 'F')
            std::cout << "That's an invalid choice. Try again.\n\n";
    }
    while (choice != 'r' && choice != 'R' && choice != 'f' && choice != 'F');

    return choice;
}

void battle(Player& p, Monster& m)
{
    while (p.getHealth() > 0 && m.getHealth() > 0)
    {
        char choice { getChoice() };
        if (choice == 'r' || choice == 'R')
        {
            if (runAway(p, m))
                return;
        }
        else
            attackMonster(p, m);
    }
}

Monster createMonster()
{
    Monster m{ Monster::getRandomMonster() };
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";    

    return m;
}

Player createPlayer()
{
    std::cout << "Enter your name: ";
    std::string name {};
    std::cin >> name;

    Player pl { name };
    std::cout << "Welcome, " << pl.getName() << " to the Dungeon Raider!\n\n";

    return pl;
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    Player pl { createPlayer() }; 
    while (pl.getHealth() > 0 && pl.getLevel() < 20)
    {
        printStatus(pl);
        Monster m { createMonster() };
        battle(pl, m);
    }

    if (isWon(pl))
    {
        std::cout << "You won! Your final stats are:\n";;
        printStatus(pl);
    }
}