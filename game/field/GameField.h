#ifndef CELLS_LIVE_GAMEFIELD_H
#define CELLS_LIVE_GAMEFIELD_H


#include "../../interface/screen/Screen.h"
#include "../Game.h"
#include <SFML/Graphics.hpp>
#include "../config/GameConfig.h"
#include "../cell/Cell.h"
#include "neighbors/NeighborsField.h"


class GameField : public Screen {
private:
    void initField();

    unsigned int rows, columns;
    GameConfig *config;
    NeighborsField *neighborsField;

public:
    GameField(Game *game, GameConfig *config);

    Game *game;

    void render(sf::RenderTarget *target) override;

    std::vector<std::vector<Cell *>> field;

    void addCell(sf::Vector2u pos);
    void removeCell(sf::Vector2u pos);

    void update(sf::Event) override;

};


#endif //CELLS_LIVE_GAMEFIELD_H
