#include "cell.h"

Cell::Cell(Game *game) : Cell(*(new CellConfig()), game) {}

Cell::Cell(CellConfig &config, Game *game) {
    this->game = game;
    this->size = config.size;
    this->mutationChance = config.mutationChance;
    this->shape = sf::RectangleShape(sf::Vector2f((float) config.size, (float) config.size));
}

sf::Color Cell::color() {
    return {};
}

void Cell::render() {
    this->shape.setFillColor(this->color());
    this->game->window->draw(this->shape);
}

void Cell::update() {

}
