#ifndef CELLS_LIVE_ALIVECELL_H
#define CELLS_LIVE_ALIVECELL_H


#include "../Cell.h"
#include "../../field/GameField.h"
#include <vector>

class AliveCell : public Cell {
public:
    AliveCell(CellConfig *config, game::Game *game, sf::Vector2u coords);
};


#endif //CELLS_LIVE_ALIVECELL_H
