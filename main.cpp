#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include "game/Game.h"

int main() {
    srand (time(NULL));
    Game game(sf::Vector2i(1500, 1200));
    game.run();
    return 0;
}
