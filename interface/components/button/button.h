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
    float width, height;
    unsigned short state;

    Button(int, int, sf::Vector2f, std::string);

    void render(sf::RenderTarget &) const;

    void update(sf::Vector2i);

    const bool isPressed();
};


#endif //CELLS_LIVE_BUTTON_H
