#include <SFML/Graphics/RenderWindow.hpp>
#include "main_menu.h"

MainMenu::MainMenu(sf::RenderWindow &window) {
    this->background.setFillColor(sf::Color::White);
    this->background.setSize(sf::Vector2f(window.getSize()));

    sf::Vector2f buttonSize(120, 60);
    std::vector <std::string> buttonsTitle{"Start", "Settings", "Exit"};
    int buttonsGap = 10;

    sf::Vector2i startButtonsPos(
            window.getSize().x / 2. - buttonSize.x / 2.,
            window.getSize().y / 2. - (buttonsTitle.size() * buttonSize.y + (buttonsTitle.size() - 1) * buttonsGap) / 2.
    );

    for (int i = 0; i < buttonsTitle.size(); i++) {
        buttons.push_back(
                new Button(
                        startButtonsPos.x,
                        startButtonsPos.y + buttonSize.y * i + buttonsGap * i,
                        buttonSize,
                        buttonsTitle[i]
                )
        );
    }
}

void MainMenu::render(sf::RenderTarget &target) {
    target.draw(this->background);
    for (Button *button: buttons) {
        button->render(target);
    }
}

void MainMenu::update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition();
    for (Button *button: buttons) {
        button->update(mousePos);
    }
}