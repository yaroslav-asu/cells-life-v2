#ifndef CELLS_LIVE_NEIGHBORSFIELD_H
#define CELLS_LIVE_NEIGHBORSFIELD_H


#include <vector>
#include <SFML/Graphics.hpp>
#include "../../cell/Cell.h"


class NeighborsField {
private:
    void initField(sf::Vector2u fieldSize);

protected:
    sf::Vector2u size;

    std::vector<sf::Vector2u> cellsAround(sf::Vector2u pos) const;

public:
    explicit NeighborsField(sf::Vector2u size);

    std::vector<std::vector<unsigned short>> field;

    std::vector<sf::Vector2u> toRemove, toAdd;

    void update();


};


#endif //CELLS_LIVE_NEIGHBORSFIELD_H
