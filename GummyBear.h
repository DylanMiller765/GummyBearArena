#pragma once
#include "Character.h"

class GummyBear : public Character {
public:
    using Character::Character; // Inherit constructors from Character
    virtual ~GummyBear() override {  // Override the destructor
        std::cout << "GummyBear destroyed\n";
    }
    int attack(Character& opponent) const override; // Declare without defining here
    void train() override; // Declare without defining here
    
    
};