#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <functional>
#include "main_menu.h"

void exit(Game *game) {
    game->window->close();
}

void openSettings(Game *game) {
    game->openSettings();
}

MainMenu::MainMenu(Game *game) {
    sf::RenderWindow *window = game->window;
    this->background.setFillColor(sf::Color::White);
    this->background.setSize(sf::Vector2f(game->window->getSize()));

    sf::Vector2f buttonSize(120, 60);
    std::vector<std::string> buttonsTitle{"Start", "Settings", "Exit"};
    typedef void (*func)(Game *);
    std::vector<func> buttonCallbacks{exit, openSettings, exit};
    int buttonsGap = 10;


    sf::Vector2i startButtonsPos(
            window->getSize().x / 2. - buttonSize.x / 2.,
            window->getSize().y / 2. -
            (buttonsTitle.size() * buttonSize.y + (buttonsTitle.size() - 1) * buttonsGap) / 2.
    );

    for (int i = 0; i < buttonsTitle.size(); i++)
        buttons.push_back(
                new Button(
                        startButtonsPos.x,
                        startButtonsPos.y + buttonSize.y * i + buttonsGap * i,
                        buttonSize,
                        buttonsTitle[i],
                        game,
                        buttonCallbacks[i]
                )
        );

}

void MainMenu::render(sf::RenderTarget &target) {
    target.draw(this->background);
    for (Button *button: buttons) {
        button->render(target);
    }
}

void MainMenu::update(sf::Event event) {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    for (Button *button: buttons) {
        button->update(mousePos, event);
    }
}