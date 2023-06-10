#include "GameMenu.h"

namespace game_menu {
    std::vector<ButtonTemplate *> menuButtons = {
            new ButtonTemplate("Continue", &game::Game::startGame),
            new ButtonTemplate("Exit", &game::Game::exit)
    };
}


GameMenu::GameMenu(game::Game *game) : Menu(game, game_menu::menuButtons) {}