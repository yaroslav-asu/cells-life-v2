#include "NeighborsField.h"

void NeighborsField::initField(sf::Vector2u fieldSize) {
    this->field.resize(fieldSize.x);
    for (int i = 0; i < fieldSize.x; ++i) {
        this->field[i].resize(fieldSize.y);
        for (int j = 0; j < fieldSize.y; ++j) {
            this->field[i][j] = 0;
        }
    }
}

NeighborsField::NeighborsField(sf::Vector2u size) {
    this->size = size;
    this->initField(size);
}

std::vector<sf::Vector2u> NeighborsField::cellsAround(sf::Vector2u pos) const {
    std::vector<sf::Vector2u> positions;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            sf::Vector2i currentPos = sf::Vector2i(pos.x + i, pos.y + j);
            if (0 < currentPos.x && currentPos.x < this->size.x && 0 < currentPos.y && currentPos.y < this->size.y &&
                !(i == 0 && j == 0)) {
                positions.emplace_back(currentPos);
            }
        }
    }
    return positions;
}

void NeighborsField::update() {
    for (auto pos: this->toRemove) {
        auto coords = this->cellsAround(pos);
        for (auto currentPos: coords) {
            this->field[currentPos.x][currentPos.y]--;
        }
    }
    for (auto pos: this->toAdd) {
        auto coords = this->cellsAround(pos);
        for (auto currentPos: coords) {
            this->field[currentPos.x][currentPos.y]++;
        }
    }
    this->toAdd.clear();
    this->toRemove.clear();
}

