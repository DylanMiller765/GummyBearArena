#pragma once
#include "Character.h"

class Opponent : public Character {
public:
    Opponent(const std::string& name, int level, int health, int attackStat, int defenseStat, int speedStat);
    // Additional Opponent-specific functionality
};
