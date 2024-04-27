#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Character {
protected:
    std::string name;
    int level;
    int health;
    int attackStat;
    int defenseStat;
    int speedStat;
    int cooldown;

public:
    Character(const std::string& name, int level, int health, int attackStat, int defenseStat, int speedStat)
    : name(name), level(level), health(health), attackStat(attackStat), defenseStat(defenseStat), speedStat(speedStat) {}

    virtual ~Character() {
        std::cout << "Character destroyed\n";
        }

    virtual int attack(Character& opponent) const {
        int damageVariance = rand() % 10;  // Random factor in attack
        int damage = attackStat + damageVariance - (opponent.defenseStat / 2);
        return std::max(0, damage);  // Ensure no negative damage
    }

    virtual void train() {
        attackStat += rand() % 5;  // Increase attack randomly between 0 and 4
        defenseStat += rand() % 3;  // Increase defense randomly between 0 and 2
        level++;  // Increment level
        std::cout << name << " has trained! Stats increased!\n";
    }

    std::string getName() const { return name; }
    int getLevel() const { return level; }
    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = std::max(0, newHealth); }
    int getAttackStat() const { return attackStat; }
    int getDefenseStat() const { return defenseStat; }
    int getSpeedStat() const { return speedStat; }
};
