#ifndef CELLS_LIVE_SCREEN_H
#define CELLS_LIVE_SCREEN_H

#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual void render();

    virtual void update(sf::Event);
};


#endif //CELLS_LIVE_SCREEN_H