#include "color_scheme.h"

std::vector<sf::Color> ColorScheme::gradient(sf::Color from, sf::Color to, unsigned int length) {
    std::vector<sf::Color> colors;
    sf::Color current = from;
    int rStep = (int) (to.r - from.r) / (int) (length - 1);
    int gStep = (int) (to.g - from.g) / (int) (length - 1);
    int bStep = (int) (to.b - from.b) / (int) (length - 1);
    colors.push_back(from);
    for (int i = 0; i < length - 1; i++) {
        current.r = (current.r + rStep) % 256;
        current.g = (current.g + gStep) % 256;
        current.b = (current.b + bStep) % 256;
        colors.push_back(current);
    }
    return colors;
}

sf::Color ColorScheme::color(unsigned int id) {
    return {};
}
