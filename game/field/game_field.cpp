#include "game_field.h"

GameField::GameField(Game *game, GameConfig config) {
    this->background = sf::RectangleShape(config.windowSize);
    this->background.setFillColor(config.backgroundColor);
    this->game = game;

}

void GameField::render() {
    this->game->window->draw(this->background);
}