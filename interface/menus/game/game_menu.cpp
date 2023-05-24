#include "game_menu.h"

namespace game_menu{
    std::vector<ButtonTemplate *> menuButtons = {
            new ButtonTemplate("Continue", &Game::startGame),
            new ButtonTemplate("Exit", &Game::exit)
    };
}


GameMenu::GameMenu(Game *game) : Menu(game, game_menu::menuButtons) {}