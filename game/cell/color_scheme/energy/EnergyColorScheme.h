#ifndef CELLS_LIVE_ENERGYCOLORSCHEME_H
#define CELLS_LIVE_ENERGYCOLORSCHEME_H


#include "../ColorScheme.h"
#include "../../../config/cell/CellConfig.h"

class EnergyColorScheme : public ColorScheme {
public:
    EnergyColorScheme();

    explicit EnergyColorScheme(CellConfig *config);

    std::vector<sf::Color> colors;

    sf::Color color(unsigned int id);

};


#endif //CELLS_LIVE_ENERGYCOLORSCHEME_H
