#include "EnergyColorScheme.h"

EnergyColorScheme::EnergyColorScheme() : EnergyColorScheme(CellConfig()) {}

EnergyColorScheme::EnergyColorScheme(CellConfig config) {
    std::vector<sf::Color> gradient(config.maximumEnergy / 2);
    gradient = ColorScheme::gradient(
            sf::Color::Red, sf::Color::Yellow, config.maximumEnergy / 2
    );
    std::vector<sf::Color> gradientSecondPart = ColorScheme::gradient(
            sf::Color::Yellow, sf::Color::Green, config.maximumEnergy / 2
    );
    gradient.insert(gradient.end(), gradientSecondPart.begin(), gradientSecondPart.end());
    this->colors = gradient;
}

sf::Color EnergyColorScheme::color(unsigned int id) {
    return this->colors[id];
}

