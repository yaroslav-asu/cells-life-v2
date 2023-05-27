#ifndef CELLS_LIVE_GAMECONFIG_H
#define CELLS_LIVE_GAMECONFIG_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "cell/cell_config.h"
#include "field/field_config.h"


class GameConfig {
public:
    GameConfig(unsigned int, unsigned int, unsigned short);

    sf::Vector2f windowSize;
    sf::Color backgroundColor = sf::Color(180, 180, 180);
    CellConfig cellConfig;
    FieldConfig fieldConfig;
};


#endif //CELLS_LIVE_GAMECONFIG_H
