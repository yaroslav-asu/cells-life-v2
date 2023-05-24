#ifndef CELLS_LIVE_MENU_H
#define CELLS_LIVE_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../game_screen/game_screen.h"
#include "../components/button/button.h"
#include "../components/button/template/button_template.h"

class Menu : public GameScreen {
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
