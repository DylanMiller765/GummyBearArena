// FileManager.cpp
#include "FileManager.h"
#include <fstream>

void FileManager::saveGame(const std::string& filename) {
    std::ofstream file(filename);
    // Write game state to file
}

void FileManager::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    // Read game state from file
}
