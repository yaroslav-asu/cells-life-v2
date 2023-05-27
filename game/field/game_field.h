#ifndef CELLS_LIVE_GAME_FIELD_H
#define CELLS_LIVE_GAME_FIELD_H


#include "../../interface/screen/screen.h"
#include "../game.h"
#include <SFML/Graphics.hpp>
#include "../config/game_config.h"
#include "../cell/cell.h"


class GameField : public Screen {
private:
    void initField();

    unsigned int rows, columns;

public:
    GameField(Game *game, FieldConfig config);

    Game *game;

    void render() override;

    std::vector<std::vector<Cell *>> field;
    void addCell(unsigned int x, unsigned int y);
};


#endif //CELLS_LIVE_GAME_FIELD_H
