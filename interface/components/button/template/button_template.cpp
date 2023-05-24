#include "button_template.h"

ButtonTemplate::ButtonTemplate(std::string title, void (Game::*gameMethod)()) {
    this->title = title;
    this->callback = gameMethod;
}