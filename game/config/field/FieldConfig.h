#ifndef CELLS_LIVE_FIELDCONFIG_H
#define CELLS_LIVE_FIELDCONFIG_H


#include "../cell/CellConfig.h"

class FieldConfig {
public:
    FieldConfig();

    FieldConfig(sf::Vector2u pixelSize, unsigned int cellSize);

    unsigned int rowCount;
    unsigned int columnCount;
    sf::Vector2u size;
    sf::Color backgroundColor;
};


#endif //CELLS_LIVE_FIELDCONFIG_H
