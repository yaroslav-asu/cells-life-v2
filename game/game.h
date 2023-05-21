#ifndef CELLS_LIVE_GAME_H
#define CELLS_LIVE_GAME_H


#include <SFML/System.hpp>
#include "../interface/game_screen/game_screen.h"

enum {
    MAIN_SETTINGS_SCREEN, GAME_SCREEN
};

class Game {
public:
    sf::RenderWindow *window;
    unsigned short currentScreenType = MAIN_SETTINGS_SCREEN;
    bool running;

    std::vector<GameScreen *> screens;

    Game(sf::Vector2i size);

    void start();

    void end();

    void render();

    void renderMainMenu();

    void update();
};


#endif //CELLS_LIVE_GAME_H
