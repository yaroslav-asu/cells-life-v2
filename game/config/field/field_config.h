#ifndef CELLS_LIVE_FIELD_CONFIG_H
#define CELLS_LIVE_FIELD_CONFIG_H


#include "../cell/cell_config.h"

class FieldConfig {
public:
    FieldConfig();

    FieldConfig(sf::Vector2u pixelSize, unsigned int cellSize);

    unsigned int rowCount;
    unsigned int columnCount;
    sf::Vector2u size;
    sf::Color backgroundColor;
};


#endif //CELLS_LIVE_FIELD_CONFIG_H
