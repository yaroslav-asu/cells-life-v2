#include <SFML/Graphics.hpp>
#include <functional>
#include "Game.h"
#include "../interface/menus/main/MainMenu.h"
#include "../interface/menus/game/GameMenu.h"
#include "field/GameField.h"

Game::Game(sf::Vector2i size) {
    sf::Vector2i windowSize(size.x, size.y);
    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Cells Live");
    GameConfig config(500, 500, 5);

    screens.resize(10);
    screens[MAIN_MENU_SCREEN] = new MainMenu(this);
    screens[GAME_MENU_SCREEN] = new GameMenu(this);
    screens[GAME_FIELD_SCREEN] = new GameField(this, &config);

    colorSchemes.resize(10);
    colorSchemes[ENERGY_COLOR_SCHEME] = new EnergyColorScheme(config.cellConfig);
}

void Game::render() {
    this->currentScreen()->render(this->window);
}

void Game::update(sf::Event event) {
    this->currentScreen()->update(event);
}

void Game::run() {
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
    this->currentScreenId = GAME_FIELD_SCREEN;
}

void Game::pauseGame() {
    this->paused = true;
}

void Game::continueGame() {
    this->paused = false;
}