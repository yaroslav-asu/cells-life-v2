#ifndef CELLS_LIVE_MAINMENU_H
#define CELLS_LIVE_MAINMENU_H


#include <SFML/Graphics.hpp>
#include "../../components/button/Button.h"
#include "../../screen/Screen.h"
#include "../../../game/Game.h"
#include "../Menu.h"

class MainMenu : public Menu {
public:
    explicit MainMenu(Game *);

    void render() override;

    void update(sf::Event event) override;
};


#endif //CELLS_LIVE_MAINMENU_H
