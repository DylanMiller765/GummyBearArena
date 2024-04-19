
#pragma once
#include <string>

class Character {
protected:
    std::string name;
    int level;
    int health;
    int attackStat;
    int defenseStat;
    int speedStat;
    std::string uniqueIdentifier;

public:
    Character(const std::string& name, int level, int health, int attackStat, int defenseStat, int speedStat);
    virtual ~Character() = default;

    // Getters
    std::string getName() const;
    int getLevel() const;
    int getHealth() const;
    int getAttackStat() const;
    int getDefenseStat() const;
    int getSpeedStat() const;
    std::string getUniqueIdentifier() const;

    // Setters
    void setName(const std::string& name);
    void setLevel(int level);
    void setHealth(int health);
    void setAttackStat(int attackStat);
    void setDefenseStat(int defenseStat);
    void setSpeedStat(int speedStat);

    // Add more functionality as needed
};
