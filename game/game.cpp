#include <SFML/Graphics.hpp>
#include <functional>
#include "game.h"
#include "../interface/menus/main/main_menu.h"

Game::Game(sf::Vector2i size) {
    sf::Vector2i windowSize(size.x, size.y);
    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Cells Live");

    screens.push_back(new MainMenu(this));
}

void Game::render() {
    this->currentScreen()->render(*window);
}

void Game::update(sf::Event event) {
    this->currentScreen()->update(event);
}

void Game::run() {
    this->running = true;
    while (window->isOpen() && running) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();

        this->render();
        this->update(event);

        window->display();
    }
}

GameScreen *Game::currentScreen() {
    return screens[this->currentScreenId];
}

void Game::stop(Game *game) {
    game->running = false;
}

void Game::openSettings(Game *game) {
    game->currentScreenId = SETTINGS_SCREEN;
}

void Game::startGame(Game *game) {
    game->currentScreenId = GAME_SCREEN;
}

