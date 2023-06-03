#ifndef CELLS_LIVE_ALIVECELL_H
#define CELLS_LIVE_ALIVECELL_H


#include "../Cell.h"
#include "../../field/GameField.h"
#include <vector>

class AliveCell : public Cell {
protected:
    unsigned int energy;
    unsigned short mutationChance;

    sf::Color color() override;

    std::vector<std::vector<unsigned short>> genome;
    unsigned short genomeId = 0;

public:
    AliveCell(CellConfig *config, game::Game *game, sf::Vector2u coords);
    void reproduce();
};


#endif //CELLS_LIVE_ALIVECELL_H
