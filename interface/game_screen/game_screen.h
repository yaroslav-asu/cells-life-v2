#ifndef CELLS_LIVE_GAME_SCREEN_H
#define CELLS_LIVE_GAME_SCREEN_H

#include <SFML/Graphics.hpp>

class GameScreen {
public:
    virtual void render();

    virtual void update(sf::Event);
};


#endif //CELLS_LIVE_GAME_SCREEN_H
