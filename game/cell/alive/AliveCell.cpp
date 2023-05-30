#include "AliveCell.h"

AliveCell::AliveCell(CellConfig &config, Game *game, sf::Vector2u coords) : Cell(config, game, coords) {
    this->mutationChance = config.mutationChance;
    this->energy = config.defaultEnergy;
}

sf::Color AliveCell::color() {
    return this->game->colorSchemes[this->game->currentColorScheme]->color(energy);
}