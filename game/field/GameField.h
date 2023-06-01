#ifndef CELLS_LIVE_GAMEFIELD_H
#define CELLS_LIVE_GAMEFIELD_H


#include "../../interface/screen/Screen.h"
#include "../Game.h"
#include <SFML/Graphics.hpp>
#include "../config/GameConfig.h"
#include "../cell/Cell.h"


class GameField : public Screen {
private:
    void initField();

    unsigned int rows, columns;
    GameConfig *config;

public:
    GameField(Game *game, GameConfig *config);

    Game *game;

    void render(sf::RenderTarget *target) override;

    std::vector<std::vector<Cell *>> field;

    void addCell(unsigned int x, unsigned int y);
};


#endif //CELLS_LIVE_GAMEFIELD_H
