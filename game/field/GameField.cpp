#include "GameField.h"
#include "../cell/alive/AliveCell.h"

GameField::GameField(Game *game, GameConfig *config) {
    this->background = sf::RectangleShape(sf::Vector2f(config->fieldConfig.size));
    this->background.setFillColor(config->backgroundColor);
    this->game = game;
    this->rows = config->fieldConfig.rowCount;
    this->columns = config->fieldConfig.columnCount;
    this->config = config;
    initField();
    this->addCell(10, 10);
}

void GameField::render(sf::RenderTarget *target) {
    this->game->window->draw(this->background);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (this->field[i][j]) {
                this->field[i][j]->render(target);
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

void GameField::addCell(unsigned int x, unsigned int y) {
    this->field[x][y] = new AliveCell(this->config->cellConfig, this->game, sf::Vector2u(x*this->config->cellConfig.size, y*this->config->cellConfig.size));
}
