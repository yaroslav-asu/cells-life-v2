#ifndef CELLS_LIVE_CELL_H
#define CELLS_LIVE_CELL_H


#include "../../internal/renderable/Renderable.h"
#include "../Game.h"
#include "../config/cell/CellConfig.h"

class Cell : Renderable {
protected:
    unsigned short size;
    sf::RectangleShape shape;
    Game *game;

    virtual sf::Color color();

public:
    sf::Vector2u coords;

    Cell(CellConfig *, Game *);

    explicit Cell(Game *);

    Cell(CellConfig *, Game *, sf::Vector2<unsigned int>);

    void render(sf::RenderTarget *target);

    void update() override;
};


#endif //CELLS_LIVE_CELL_H
