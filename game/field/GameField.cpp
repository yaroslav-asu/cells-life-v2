#include <iostream>
#include "GameField.h"
#include "../cell/alive/AliveCell.h"

GameField::GameField(game::Game *game, GameConfig *config) {
    this->background = sf::RectangleShape(sf::Vector2f(config->fieldConfig->size));
    this->background.setFillColor(config->backgroundColor);
    this->game = game;
    this->rows = config->fieldConfig->rowCount;
    this->columns = config->fieldConfig->columnCount;
    this->config = config;
    initField();
    this->neighborsField = new NeighborsField(
            sf::Vector2u(config->fieldConfig->rowCount, config->fieldConfig->columnCount));
    this->generateRandomCells();
    this->neighborsField->update();
}

void GameField::render(sf::RenderTarget *target) {
    target->draw(this->background);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (this->field[i][j] != nullptr) {
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

void GameField::addCell(sf::Vector2u pos) {
    delete this->field[pos.x][pos.y];
    this->field[pos.x][pos.y] = new AliveCell(
            this->config->cellConfig, this->game,
            sf::Vector2u(pos.y * this->config->cellConfig->size, pos.x * this->config->cellConfig->size)
    );
    this->neighborsField->toAdd.push_back(pos);
}

void GameField::removeCell(sf::Vector2u pos) {
    delete this->field[pos.x][pos.y];
    this->field[pos.x][pos.y] = nullptr;
    this->neighborsField->toRemove.push_back(pos);
}

void GameField::update(sf::Event event) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (!game->paused) {
                auto neighbors = this->neighborsField->field[i][j];
                if (this->field[i][j] == nullptr && neighbors == 3) {
                    this->addCell(sf::Vector2u(i, j));
                } else if (this->field[i][j] != nullptr && neighbors != 2 && neighbors != 3) {
                    this->removeCell(sf::Vector2u(i, j));
                }
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Button::Left) {
            sf::Vector2i position = sf::Mouse::getPosition();
            this->addCell(sf::Vector2u(position.y / this->config->cellConfig->size,
                                       position.x / this->config->cellConfig->size));
        }
    }
    this->neighborsField->update();
}

void GameField::generateRandomCells() {
    for (unsigned int i = 0; i < this->rows; ++i) {
        for (unsigned int j = 0; j < this->columns; ++j) {
            if (rand() % 10 == 0) {
                this->addCell({i, j});
            }
        }
    }
}
