#ifndef CELLS_LIVE_GAME_H
#define CELLS_LIVE_GAME_H


#include <SFML/System.hpp>
#include "../interface/game_screen/game_screen.h"

enum {
    MAIN_MENU_SCREEN, SETTINGS_SCREEN, GAME_SCREEN
};

class Game {
public:
    sf::RenderWindow *window;
    unsigned short currentScreenId = MAIN_MENU_SCREEN;
    bool running;

    std::vector<GameScreen *> screens;

    Game(sf::Vector2i size);

    void run();

    void render();

    void stop();

    void openSettings();

    void startGame();


private:
    GameScreen *currentScreen();

    void update(sf::Event event);
};


#endif //CELLS_LIVE_GAME_H
