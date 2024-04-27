#include "GummyBear.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

// Method to train the GummyBear, improving its stats
void GummyBear::train() {
    attackStat += 5; // Simply increasing attackStat for demonstration
    std::cout << "GummyBear is training and increases attack stat!\n";
}

// Attack method override
int GummyBear::attack(Character& opponent) const {
    int damage = attackStat + (rand() % 10) - (opponent.getDefenseStat() / 2);
    return std::max(0, damage); // Make sure damage doesn't go negative
}

// Standalone function to save a GummyBear to a file
void saveGummyBear(const GummyBear& bear, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << bear.getName() << "\n";
        file << bear.getLevel() << "\n";
        file << bear.getHealth() << "\n";
        file << bear.getAttackStat() << "\n";
        file << bear.getDefenseStat() << "\n";
        file << bear.getSpeedStat() << "\n";
        file.close();
    }
}

GummyBear loadGummyBear(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    int level, health, attackStat, defenseStat, speedStat;

    if (file.is_open()) {  // Corrected from 'if (file.is())' to 'if (file.is_open())'
        std::getline(file, name);
        file >> level >> health >> attackStat >> defenseStat >> speedStat;
        file.close();
    } else {
        // Optionally handle the case where the file could not be opened
        std::cerr << "Unable to open file: " << filename << std::endl;
        return GummyBear("Error", 0, 0, 0, 0, 0);  // Return a default GummyBear on error
    }

    return GummyBear(name, level, health, attackStat, defenseStat, speedStat);
}