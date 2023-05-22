#ifndef CELLS_LIVE_BUTTON_H
#define CELLS_LIVE_BUTTON_H


#include <string>
#include <SFML/Graphics.hpp>
#include "../../../game/game.h"

enum {
    BTN_IDLE, BTN_HOVER, BTN_PRESSED, BTN_RELEASED
};

class Button {
private:
    void (*callback)(Game *);

    Game *game;
public:
    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
    float width, height;
    unsigned short state;

    Button(int, int, sf::Vector2f, std::string);

    Button(int x, int y, sf::Vector2f size, std::string text, Game *game, void (*callback)(Game *));

    void render(sf::RenderTarget &) const;

    bool isPressed() const;

    void click();

    void update(sf::Vector2i mousePos, sf::Event);
};


#endif //CELLS_LIVE_BUTTON_H
