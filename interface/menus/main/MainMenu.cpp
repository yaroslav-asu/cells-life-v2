#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include "MainMenu.h"

std::vector<ButtonTemplate *> menuButtons = {
        new ButtonTemplate("Start", &game::Game::startGame),
        new ButtonTemplate("Exit", &game::Game::exit)
};

MainMenu::MainMenu(game::Game *game) : Menu(game, menuButtons) {}

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