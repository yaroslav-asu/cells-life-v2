#include "game_field.h"

GameField::GameField(Game *game, FieldConfig config) {
    this->background = sf::RectangleShape(sf::Vector2f(config.size));
    this->background.setFillColor(config.backgroundColor);
    this->game = game;
    this->rows = config.rowCount;
    this->columns = config.columnCount;
    initField();
    auto a = CellConfig();
    this->field[10][10] = new Cell(a, game, sf::Vector2u(20, 20));
}

void GameField::render() {
    this->game->window->draw(this->background);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (this->field[i][j]) {
                this->field[i][j]->render();
            }
        }
    }
}

void GameField::initField() {
    this->field = std::vector<std::vector<Cell *>>(rows);
    for (int i = 0; i < rows; ++i) {
        this->field[i] = std::vector<Cell *>(columns);
    }
}