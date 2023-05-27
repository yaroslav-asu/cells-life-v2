#include "game_config.h"
#include "field/field_config.h"

GameConfig::GameConfig(unsigned int windowWidth, unsigned int windowHeight, unsigned short cellsSize) {
    this->windowSize = sf::Vector2f((float) windowWidth, (float) windowHeight);
    this->cellConfig = CellConfig(cellsSize, 100);
    this->fieldConfig = FieldConfig(sf::Vector2u(windowHeight,  windowWidth), cellConfig.size);
}
