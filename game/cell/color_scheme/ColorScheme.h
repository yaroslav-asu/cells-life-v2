#ifndef CELLS_LIVE_COLORSCHEME_H
#define CELLS_LIVE_COLORSCHEME_H

#include <SFML/Graphics.hpp>

enum {
    FOOD_COLOR_SCHEME, ENERGY_COLOR_SCHEME
};

class ColorScheme {
public:
    static std::vector<sf::Color> gradient(sf::Color from, sf::Color to, unsigned int length);

    virtual sf::Color color(unsigned int id);

};


#endif //CELLS_LIVE_COLORSCHEME_H
