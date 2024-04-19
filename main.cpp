#include "Game.h"
#include <iostream>

int main() {
    Game game; // Create the game instance

    try {
        game.run(); // Run the entire game loop
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
