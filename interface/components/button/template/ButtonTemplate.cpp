#include "ButtonTemplate.h"

ButtonTemplate::ButtonTemplate(std::string title, void (game::Game::*gameMethod)()) {
    this->title = title;
    this->callback = gameMethod;
}