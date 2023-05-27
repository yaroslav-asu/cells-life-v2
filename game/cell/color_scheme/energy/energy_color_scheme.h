#ifndef CELLS_LIVE_ENERGY_COLOR_SCHEME_H
#define CELLS_LIVE_ENERGY_COLOR_SCHEME_H


#include "../color_scheme.h"
#include "../../../config/cell/cell_config.h"

class EnergyColorScheme : public ColorScheme {
public:
    EnergyColorScheme();

    explicit EnergyColorScheme(CellConfig config);

    std::vector<sf::Color> colors;

    sf::Color color(unsigned int id);

};


#endif //CELLS_LIVE_ENERGY_COLOR_SCHEME_H
