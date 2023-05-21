#ifndef CELLS_LIVE_MAIN_MENU_H
#define CELLS_LIVE_MAIN_MENU_H


#include <SFML/Graphics.hpp>
#include "../../components/button/button.h"
#include "../../game_screen/game_screen.h"
#include "../../../game/game.h"

class MainMenu : public GameScreen {
public:
    sf::RectangleShape background;
    std::vector<Button *> buttons;

    explicit MainMenu(Game *);

    void render(sf::RenderTarget &);

    void update(sf::Event event);
};


#endif //CELLS_LIVE_MAIN_MENU_H
