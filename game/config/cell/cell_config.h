#ifndef CELLS_LIVE_CELL_CONFIG_H
#define CELLS_LIVE_CELL_CONFIG_H


class CellConfig {
public:
    unsigned short size;
    unsigned short mutationChance;

    CellConfig(unsigned short, unsigned short);

    CellConfig();

    unsigned int defaultEnergy;
    unsigned int maximumEnergy;
};


#endif //CELLS_LIVE_CELL_CONFIG_H
