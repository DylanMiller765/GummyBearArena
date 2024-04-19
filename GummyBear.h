#pragma once
#include "Character.h"
#include <fstream>

class GummyBear : public Character {
public:
    GummyBear(const std::string& name, int level, int health, int attackStat, int defenseStat, int speedStat);
    void train(); // Method to train the GummyBear, improving its stats
    // Additional GummyBear-specific functionality
};

void GummyBear::train() {
    // Example: Increment level and randomly increase some stats
    level++;
    attackStat += rand() % 5; // Increase attack by a random amount between 0 and 4
    defenseStat += rand() % 5; // Similar for defense
    // Ensure you seed the random number generator in your main program: srand(time(NULL));
}

void saveGummyBear(const GummyBear& bear, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << bear.getName() << "\n";
        file << bear.getLevel() << "\n";
        // Continue for other attributes
        file.close();
    }
    GummyBear loadGummyBear(const std::string& filename) {
    std::ifstream file(filename)
    std::string name;
    int level, health, attackStat, defenseStat, speedStat;

    if (file.is_open()) {
        std::getline(file, name);
        file >> level >> health >> attackStat >> defenseStat >> speedStat;
        file.close();
    }

    return GummyBear(name, level, health, attackStat, defenseStat, speedStat);
}

}

