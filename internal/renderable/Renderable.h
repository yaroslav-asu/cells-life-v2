#ifndef CELLS_LIVE_RENDERABLE_H
#define CELLS_LIVE_RENDERABLE_H


#include <SFML/Graphics/RectangleShape.hpp>

class Renderable {
    virtual void render();

    virtual void update();
};


#endif //CELLS_LIVE_RENDERABLE_H
