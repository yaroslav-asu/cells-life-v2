#include "game_config.h"

GameConfig::GameConfig(unsigned int windowWidth, unsigned int windowHeight, unsigned int cellsSize) {
    this->windowSize = sf::Vector2f((float) windowWidth, (float) windowHeight);
    this->cellSize = cellsSize;
}
