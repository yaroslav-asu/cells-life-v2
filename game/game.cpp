#include <SFML/Graphics.hpp>
#include <functional>
#include "game.h"
#include "../interface/menus/main/main_menu.h"
#include "../interface/menus/game/game_menu.h"

Game::Game(sf::Vector2i size) {
    sf::Vector2i windowSize(size.x, size.y);
    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Cells Live");

    screens.insert(screens.begin() + MAIN_MENU_SCREEN, new MainMenu(this));
    screens.insert(screens.begin() + GAME_MENU_SCREEN, new GameMenu(this));
}

void Game::render() {
    this->currentScreen()->render();
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

Screen *Game::currentScreen() {
    return screens[this->currentScreenId];
}

void Game::exit() {
    this->running = false;
}

void Game::openGameMenu() {
    this->currentScreenId = GAME_MENU_SCREEN;
}

void Game::startGame() {
    this->currentScreenId = GAME_SCREEN;
}

void Game::pauseGame() {
    this->paused = true;
}

void Game::continueGame() {
    this->paused = false;
}