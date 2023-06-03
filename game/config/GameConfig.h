#ifndef CELLS_LIVE_GAMECONFIG_H
#define CELLS_LIVE_GAMECONFIG_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cell/CellConfig.h"
#include "field/FieldConfig.h"


class GameConfig {
public:
    GameConfig(CellConfig *cellConfig, FieldConfig *fieldConfig);

    sf::Color backgroundColor = sf::Color(180, 180, 180);
    CellConfig *cellConfig;
    FieldConfig *fieldConfig;
};


#endif //CELLS_LIVE_GAMECONFIG_H
