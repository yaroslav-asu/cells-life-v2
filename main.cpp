#include <SFML/Graphics.hpp>
#include "game/Game.h"

int main() {
    Game game(sf::Vector2i(500, 500));
    game.run();
    return 0;
}
