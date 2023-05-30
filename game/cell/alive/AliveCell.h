#ifndef CELLS_LIVE_ALIVECELL_H
#define CELLS_LIVE_ALIVECELL_H


#include "../Cell.h"

class AliveCell : public Cell {
protected:
    unsigned int energy;
    unsigned short mutationChance;

    sf::Color color() override;

public:
    AliveCell(CellConfig &config, Game *game, sf::Vector2u coords);

};


#endif //CELLS_LIVE_ALIVECELL_H
