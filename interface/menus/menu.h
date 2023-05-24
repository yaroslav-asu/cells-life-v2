#ifndef CELLS_LIVE_MENU_H
#define CELLS_LIVE_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../screen/screen.h"
#include "../components/button/button.h"
#include "../components/button/template/button_template.h"

class Menu : public Screen {
public:
    explicit Menu(Game *);

    Menu(Game *, std::vector<ButtonTemplate *> &);

    Game *game;

    sf::RectangleShape background;

    std::vector<Button *> buttons;

    virtual void render();

    virtual void update(sf::Event event);
};


#endif //CELLS_LIVE_MENU_H
