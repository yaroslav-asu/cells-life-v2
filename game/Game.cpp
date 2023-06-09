#include <SFML/Graphics.hpp>
#include <functional>
#include "Game.h"
#include "../interface/menus/main/MainMenu.h"
#include "../interface/menus/game/GameMenu.h"
#include "field/GameField.h"
#include "spdlog/spdlog.h"

namespace game {
    Game::Game(sf::Vector2i size) {
        spdlog::info("Game init");
        sf::Vector2i windowSize(size.x, size.y);
        this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "");
        auto *cellConfig = new CellConfig(10);
        auto *fieldConfig = new FieldConfig(sf::Vector2u(size.x, size.y), cellConfig->size);
        auto *config = new GameConfig(cellConfig, fieldConfig);
        updateDelay = 300;

        screens.resize(10);
        spdlog::info("Game fields init");
        screens[MAIN_MENU_SCREEN] = new MainMenu(this);
        screens[GAME_MENU_SCREEN] = new GameMenu(this);
        screens[GAME_FIELD_SCREEN] = new GameField(this, config);
    }

    void Game::render() {
        this->currentScreen()->render(this->window);
    }

    void Game::update(sf::Event event) {
        this->currentScreen()->update(event);
    }

    void Game::run() {
        unsigned long long counter = 1;
        while (window->isOpen() && running) {
            sf::Event event{};
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    spdlog::info("Game force closed");
                    window->close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        openGameMenu();
                    }
                    if (event.key.code == sf::Keyboard::Space) {
                        togglePause();
                        break;
                    }
                }
                if(event.type == sf::Event::MouseButtonPressed){
                    if (this->currentScreenId == GAME_FIELD_SCREEN){
                        this->update(event);
                        this->render();
                        window->display();

                    }
                }
            }

            this->render();

            window->display();
            if (counter % updateDelay == 0 || this->currentScreenId != GAME_FIELD_SCREEN) {
                window->clear();
                this->update(event);
            }
            counter++;
        }
    }

    Screen *Game::currentScreen() {
        return screens[this->currentScreenId];
    }

    void Game::exit() {
        spdlog::info("Game closed");
        this->running = false;
    }

    void Game::openGameMenu() {
        spdlog::info("Game menu opened");
        this->currentScreenId = GAME_MENU_SCREEN;
    }

    void Game::startGame() {
        spdlog::info("Game started");
        this->currentScreenId = GAME_FIELD_SCREEN;
    }

    void Game::togglePause() {
        spdlog::info("Game pause toggled");
        this->paused = !this->paused;
    }

    void Game::continueGame() {
        spdlog::info("Game continued");
        this->paused = false;
    }
}