#ifndef CELLS_LIVE_MAIN_MENU_H
#define CELLS_LIVE_MAIN_MENU_H


#include <SFML/Graphics.hpp>
#include "../../components/button/button.h"
#include "../../game_screen/game_screen.h"
#include "../../../game/game.h"
#include "../menu.h"

class MainMenu : public Menu {
public:
    explicit MainMenu(Game *);

    void render() override;

    void update(sf::Event event) override;
};


#endif //CELLS_LIVE_MAIN_MENU_H
