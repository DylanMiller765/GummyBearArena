// FileManager.h
#pragma once
#include <string>

class FileManager {
public:
    static void saveGame(const std::string& filename);
    static void loadGame(const std::string& filename);
};
