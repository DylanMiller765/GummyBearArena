#include "GummyBear.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

class Game {
public:
    Game() : playerBear("Player1", 1, 100, 10, 10, 10), enemyBear("Enemy1", 1, 100, 10, 10, 10) {
        srand(time(NULL));  // Seed the random generator
        running = true;
        currentState = MAIN_MENU;
        gen = std::mt19937(rd()); // Initialize Mersenne Twister with random_device seed
        dis = std::uniform_int_distribution<>(0, 10); // Damage variance
    }

    void run();
    void initialize();
    bool isRunning() const;

private:
    void processInput();
    void update();
    void render();
    void mainMenu(int choice);
    void handleBattle();
    void trainGummyBear();

    bool running;
    GummyBear enemyBear; 
    GummyBear playerBear;  // Player's Gummy Bear
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    enum GameState {
        MAIN_MENU,
        BATTLE,
        TRAINING,
        QUIT
    } currentState, previousState;
};

void Game::initialize() {
    std::cout << "Welcome to Gummy Bear Arena!!\n";
}

void Game::run() {
    initialize();
    render();
    while (running) {
        processInput();
        update();
        render();
    }
}

void Game::processInput() {
    std::string input;
    if (currentState == MAIN_MENU) {
        std::getline(std::cin, input);
        try {
            int choice = std::stoi(input);
            mainMenu(choice);
        } catch (...) {
            std::cout << "Invalid input, please enter a number.\n";
        }
    }
}

void Game::update() {
    // Optional: Add logic here to manage updates such as cooldown reductions
}

void Game::render() {
    switch (currentState) {
        case MAIN_MENU:
            std::cout << "Main Menu:\n1: Start Battle\n2: Training\n3: Quit\n";
            break;
        case BATTLE:
            handleBattle();
            break;
        case TRAINING:
            trainGummyBear();
            break;
        case QUIT:
            std::cout << "Exiting Game.\n";
            running = false;
            break;
    }
}

void Game::mainMenu(int choice) {
    switch (choice) {
        case 1:
            currentState = BATTLE;
            break;
        case 2:
            currentState = TRAINING;
            break;
        case 3:
            currentState = QUIT;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}

void Game::handleBattle() {
    int playerAttack = playerBear.attack(enemyBear); // Correctly pass the enemy as an argument
    int enemyAttack = enemyBear.attack(playerBear);  // Correctly pass the player as an argument

    std::cout << "You strike the enemy for " << playerAttack << " damage.\n";
    std::cout << "Enemy strikes you for " << enemyAttack << " damage.\n";

    if (!enemyBear.getHealth()) {
        std::cout << "You have defeated the enemy!\n";
        currentState = MAIN_MENU;  // Return to main menu after the battle
        return;
    }

    if (!playerBear.getHealth()) {
        std::cout << "You have been defeated by the enemy!\n";
        currentState = MAIN_MENU;  // Return to main menu after the battle
        return;
    }

    std::cout << "Both fighters ready for the next round!\n";
}


void Game::trainGummyBear() {
    playerBear.train();
    std::cout << "Training complete. Stats increased!\n";
    currentState = MAIN_MENU;  // Return to main menu after training
}

int main() {
    Game game;
    game.run();
    return EXIT_SUCCESS;
}
