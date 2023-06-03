#include "CellConfig.h"

CellConfig::CellConfig(unsigned short size) : CellConfig() {
    this->size = size;
}

CellConfig::CellConfig() {
    this->size = 100;
    this->defaultEnergy = 100;
    this->maximumEnergy = 200;
}
