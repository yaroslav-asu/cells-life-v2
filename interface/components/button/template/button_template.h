#ifndef CELLS_LIVE_BUTTON_TEMPLATE_H
#define CELLS_LIVE_BUTTON_TEMPLATE_H

#include "../../../../game/game.h"

#include <string>

class ButtonTemplate {
public:
    ButtonTemplate(std::string title, void(Game::*gameMethod)());

    std::string title;

    void (Game::*callback)();
};


#endif //CELLS_LIVE_BUTTON_TEMPLATE_H
