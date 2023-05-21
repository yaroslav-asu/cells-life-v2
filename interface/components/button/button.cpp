#include "button.h"

Button::Button(int x, int y, sf::Vector2f size, std::string text) {
    this->width = size.x;
    this->height = size.y;

    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(x, y);

    this->font.loadFromFile("../fonts/roboto.ttf");
    this->text.setFillColor(sf::Color::White);

    this->text = sf::Text("text", font, 25);
    sf::Rect textRect = this->text.getGlobalBounds();

    this->text.setPosition(x + width / 2. - textRect.width / 2. - textRect.left,
                           y + height / 2. - textRect.height / 2. - textRect.top);

    sf::Rect textBounds = this->shape.getGlobalBounds();

    this->state = BTN_IDLE;
}


void Button::render(sf::RenderWindow &window) {
    window.draw(shape);
    window.draw(text);
}

void Button::update(sf::Vector2i mousePos) {
    this->state = BTN_IDLE;
    if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePos))) {
        this->state = BTN_HOVER;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->state = BTN_PRESSED;
        }
    }
    switch (this->state) {
        case BTN_IDLE:
            this->shape.setFillColor(sf::Color::Red);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(sf::Color::Blue);
            break;
        case BTN_PRESSED:
            this->shape.setFillColor(sf::Color::Yellow);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }
}

const bool Button::isPressed() {
    return this->state == BTN_PRESSED;
}