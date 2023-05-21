#include <SFML/Graphics.hpp>
#include "game.h"
#include "../interface/menus/main/main_menu.h"

Game::Game(sf::Vector2i size) {
    sf::Vector2i windowSize(size.x, size.y);
    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Cells Live");
    screens.push_back(new MainMenu(*window));
}

void Game::render() {
    screens[this->currentScreenType]->render(*window);
}

void Game::update() {
    screens[this->currentScreenType]->update();
}

void Game::start() {
    this->running = true;
    while (window->isOpen() && running) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();

        this->render();
        this->update();

        window->display();
    }
}

void Game::end() {
    this->running = false;
}

