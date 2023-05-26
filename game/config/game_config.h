#ifndef CELLS_LIVE_GAMECONFIG_H
#define CELLS_LIVE_GAMECONFIG_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class GameConfig {
public:
    GameConfig(unsigned int, unsigned int, unsigned int);

    sf::Vector2f windowSize;
    unsigned int cellSize;
    sf::Color backgroundColor = sf::Color(180, 180, 180);
};


#endif //CELLS_LIVE_GAMECONFIG_H
