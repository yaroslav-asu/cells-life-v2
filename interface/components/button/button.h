#ifndef CELLS_LIVE_BUTTON_H
#define CELLS_LIVE_BUTTON_H


#include <string>
#include <SFML/Graphics.hpp>

enum {
    BTN_IDLE, BTN_HOVER, BTN_PRESSED
};

class Button {
public:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    float width = 250, height = 100;
    unsigned short state;

    Button(int x, int y, sf::Vector2f size, std::string text);

    void render(sf::RenderWindow &window);

    void update(sf::Vector2i);

    const bool isPressed();
};


#endif //CELLS_LIVE_BUTTON_H
