#ifndef CELLS_LIVE_MENU_H
#define CELLS_LIVE_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../screen/Screen.h"
#include "../components/button/Button.h"
#include "../components/button/template/ButtonTemplate.h"

class Menu : public Screen {
public:
    explicit Menu(game::Game *);

    Menu(game::Game *, std::vector<ButtonTemplate *> &);

    game::Game *game;
    
    std::vector<Button *> buttons;

    virtual void render(sf::RenderTarget *target);

    virtual void update(sf::Event event);
};


#endif //CELLS_LIVE_MENU_H
