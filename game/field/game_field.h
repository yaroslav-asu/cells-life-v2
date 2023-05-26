#ifndef CELLS_LIVE_GAME_FIELD_H
#define CELLS_LIVE_GAME_FIELD_H


#include "../../interface/screen/screen.h"
#include "../game.h"
#include <SFML/Graphics.hpp>
#include "../config/game_config.h"


class GameField : public Screen {
public:
    Game *game;

    GameField(Game *, GameConfig);

    void render() override;
};


#endif //CELLS_LIVE_GAME_FIELD_H
