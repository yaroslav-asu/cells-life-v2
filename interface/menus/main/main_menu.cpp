#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include <iostream>
#include "main_menu.h"

std::vector<ButtonTemplate *> menuButtons = {
        new ButtonTemplate("Start", &Game::startGame),
        new ButtonTemplate("Settings", &Game::openSettings),
        new ButtonTemplate("Exit", &Game::stop)
};

MainMenu::MainMenu(Game *game) : Menu(game, menuButtons) {}

void MainMenu::render() {
    this->game->window->draw(this->background);
    for (Button *button: buttons) {
        button->render(*this->game->window);
    }
}

void MainMenu::update(sf::Event event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    for (Button *button: buttons) {
        button->update(mousePos, event);
    }
}