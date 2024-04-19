#pragma once
#include <iostream>

class Game {
public:
    Game();          // Constructor
    void run();      // Runs the main loop
    void initialize();
    bool isRunning() const;

private:
    void processInput();
    void update();
    void render();
    void mainMenu();
    void handleBattle();

    bool running;
    enum GameState {
        MAIN_MENU,
        BATTLE,
        TRAINING,
        QUIT
    } currentState;
};
