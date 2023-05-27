#include "cell_config.h"

CellConfig::CellConfig(unsigned short size, unsigned short mutationChance) : CellConfig() {
    this->size = size;
    this->mutationChance = mutationChance;
}

CellConfig::CellConfig() {
    this->size = 5;
    this->mutationChance = 100;
    this->defaultEnergy = 100;
    this->maximumEnergy = 200;
}
