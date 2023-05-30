#ifndef CELLS_LIVE_MENU_H
#define CELLS_LIVE_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../screen/Screen.h"
#include "../components/button/Button.h"
#include "../components/button/template/ButtonTemplate.h"

class Menu : public Screen {
public:
    explicit Menu(Game *);

    Menu(Game *, std::vector<ButtonTemplate *> &);

    Game *game;
    
    std::vector<Button *> buttons;

    virtual void render(sf::RenderTarget *target);

    virtual void update(sf::Event event);
};


#endif //CELLS_LIVE_MENU_H
