#ifndef CELLS_LIVE_BUTTONTEMPLATE_H
#define CELLS_LIVE_BUTTONTEMPLATE_H

#include "../../../../game/Game.h"

#include <string>

class ButtonTemplate {
public:
    ButtonTemplate(std::string title, void(game::Game::*gameMethod)());

    std::string title;

    void (game::Game::*callback)();
};


#endif //CELLS_LIVE_BUTTONTEMPLATE_H
