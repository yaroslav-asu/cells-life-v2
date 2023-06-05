#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include "game/Game.h"

int main() {
    srand (time(NULL));
    game::Game game(sf::Vector2i(500, 500));
    game.run();
    return 0;
}
