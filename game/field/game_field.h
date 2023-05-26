#ifndef CELLS_LIVE_GAME_FIELD_H
#define CELLS_LIVE_GAME_FIELD_H


#include "../../interface/screen/screen.h"
#include "../game.h"
#include <SFML/Graphics.hpp>
#include "../config/game_config.h"
#include "../cell/cell.h"


class GameField : public Screen {
public:
    Game *game;

    GameField(Game *, GameConfig);

    void render() override;

    std::vector<std::vector<Cell *>> field;
};


#endif //CELLS_LIVE_GAME_FIELD_H
