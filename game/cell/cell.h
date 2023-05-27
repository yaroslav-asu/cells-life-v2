#ifndef CELLS_LIVE_CELL_H
#define CELLS_LIVE_CELL_H


#include "../../internal/renderable/renderable.h"
#include "../game.h"
#include "../config/cell/cell_config.h"

class Cell : Renderable {
private:
    unsigned short size;
    unsigned short mutationChance;
    sf::RectangleShape shape;
    Game *game;
    unsigned int energy;
public:
    sf::Vector2u coords;

    Cell(CellConfig &, Game *);

    explicit Cell(Game *);

    Cell(CellConfig &, Game *, sf::Vector2<unsigned int>);

    void render();

    void update();

    sf::Color color();
};


#endif //CELLS_LIVE_CELL_H
