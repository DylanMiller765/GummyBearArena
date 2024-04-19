// Game.cpp
#include "Game.h"
#include <iostream>
#include <string>

Game::Game() : running(true), currentState(MAIN_MENU) {}

void Game::run() {
    initialize();
    while (running) {
        processInput();
        update();
        render();
    }
}

void Game::initialize() {
    std::cout << "Welcome to Gummy Bear Arena!\n";
}

bool Game::isRunning() const {
    return running;
}

void Game::processInput() {
    switch (currentState) {
        case MAIN_MENU:
            mainMenu();
            break;
        case BATTLE:
            handleBattle();  // Ensure you call the correct function to handle battle logic.
            break;
        case TRAINING:
            // Placeholder or method for training logic
            std::cout << "Training session. Implement logic here.\n";
            break;
        case QUIT:
            running = false;
            break;
        default:
            std::cout << "Invalid state.\n";
            break;
    }
}

void Game::update() {
    // Update game state. This could involve updating game logic, checking for win conditions, etc.
    // Currently empty as we're focusing on structure.
}

void Game::render() {
    // Render the current state of the game. For now, we'll just simulate this by printing to the console.
    if (currentState == BATTLE) {
        std::cout << "Engaging in a fierce battle!\n";
    } else if (currentState == TRAINING) {
        std::cout << "Training in progress...\n";
    } else if (currentState == MAIN_MENU) {
        std::cout << "Main Menu:\n1: Start Battle\n2: Training\n3: Quit\nChoose an option: ";
    }
}

void Game::mainMenu() {
    int choice;
    std::cin >> choice;

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
            currentState = MAIN_MENU;  // Ensure the state remains at MAIN_MENU on invalid input.
            break;
    }
}

void Game::handleBattle() {
    // Simulate a battle scenario. Placeholder for more complex battle logic.
    std::cout << "You win the battle!\n";
    currentState = MAIN_MENU; // Go back to main menu after the battle
}
