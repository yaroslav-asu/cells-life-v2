#include "cell.h"
#include "color_scheme/color_scheme.h"

Cell::Cell(Game *game) : Cell(*(new CellConfig()), game) {}

Cell::Cell(CellConfig &config, Game *game) {
    this->game = game;
    this->size = config.size;
    this->mutationChance = config.mutationChance;
    this->energy = config.defaultEnergy;
    this->shape = sf::RectangleShape(sf::Vector2f((float) config.size, (float) config.size));
}

Cell::Cell(CellConfig &config, Game *game, sf::Vector2u coords) : Cell(config, game) {
    this->coords = coords;
    this->shape.setPosition((float) coords.x, (float) coords.y);
}

sf::Color Cell::color() {
    return this->game->colorSchemes[this->game->currentColorScheme]->color(energy);
}

void Cell::render() {
    this->shape.setFillColor(this->color());
    this->game->window->draw(this->shape);
}

void Cell::update() {

}
