#include <spdlog/spdlog.h>
#include "Button.h"

sf::Color idleColor(120, 120, 120);
sf::Color hoverColor(150, 150, 150);
sf::Color pressedColor(180, 180, 180);

Button::Button(int x, int y, sf::Vector2f size, std::string text) {
    this->width = size.x;
    this->height = size.y;
    this->_text = text;

    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(x, y);

    this->font.loadFromFile("../fonts/roboto.ttf");
    this->text.setFillColor(sf::Color::White);

    this->text = sf::Text(text, font, 25);
    sf::Rect textRect = this->text.getGlobalBounds();

    this->text.setPosition(x + width / 2. - textRect.width / 2. - textRect.left,
                           y + height / 2. - textRect.height / 2. - textRect.top);

    sf::Rect textBounds = this->shape.getGlobalBounds();

    this->state = BTN_IDLE;
}

Button::Button(int x, int y, sf::Vector2f size, std::string text, game::Game *game, void (game::Game::*callback)()) : Button(x, y,
                                                                                                                 size,
                                                                                                                 text) {
    spdlog::info("Button init");
    this->callback = callback;
    this->game = game;
}


void Button::render(sf::RenderTarget &target) const {
    target.draw(shape);
    target.draw(text);
}

void Button::update(sf::Vector2i mousePos, sf::Event event) {
    this->state = BTN_IDLE;
    if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePos))) {
        this->state = BTN_HOVER;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            this->state = BTN_PRESSED;
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            this->state = BTN_RELEASED;
        }
    }
    switch (this->state) {
        case BTN_IDLE:
            this->shape.setFillColor(idleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(hoverColor);
            break;
        case BTN_PRESSED:
            this->shape.setFillColor(pressedColor);
            break;
        case BTN_RELEASED:
            this->shape.setFillColor(idleColor);
            this->click();
            break;
        default:
            this->shape.setFillColor(idleColor);
            break;
    }
}

bool Button::isPressed() const {
    return this->state == BTN_PRESSED;
}

void Button::click() {
    spdlog::info("Button click: " + _text);
    if (callback) {
        ((*this->game).*callback)();
    }
}
