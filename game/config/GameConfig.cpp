#include "GameConfig.h"
#include "field/FieldConfig.h"

GameConfig::GameConfig(CellConfig *cellConfig, FieldConfig *fieldConfig) {
    this->cellConfig = cellConfig;
    this->fieldConfig = fieldConfig;
}
