#include "cell_config.h"

CellConfig::CellConfig(unsigned short size, unsigned short mutationChance) {
    this->size = size;
    this->mutationChance = mutationChance;
}

CellConfig::CellConfig() {
    this->size = 5;
    this->mutationChance = 100;
}
