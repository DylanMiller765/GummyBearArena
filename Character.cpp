// Character.cpp
#include "Character.h"

Character::Character(const std::string& name, int level, int health, int attackStat, int defenseStat, int speedStat)
    : name(name), level(level), health(health), attackStat(attackStat), defenseStat(defenseStat), speedStat(speedStat) {
    // Unique identifier can be generated based on name or another scheme
    uniqueIdentifier = name + "_unique_id"; // Simplified example
}

std::string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
int Character::getHealth() const { return health; }
int Character::getAttackStat() const { return attackStat; }
int Character::getDefenseStat() const { return defenseStat; }
int Character::getSpeedStat() const { return speedStat; }
std::string Character::getUniqueIdentifier() const { return uniqueIdentifier; }

void Character::setName(const std::string& newName) { name = newName; }
void Character::setLevel(int newLevel) { level = newLevel; }
void Character::setHealth(int newHealth) { health = newHealth; }
void Character::setAttackStat(int newAttackStat) { attackStat = newAttackStat; }
void Character::setDefenseStat(int newDefenseStat) { defenseStat = newDefenseStat; }
void Character::setSpeedStat(int newSpeedStat) { speedStat = newSpeedStat; }
