#ifndef CELLS_LIVE_MAIN_MENU_H
#define CELLS_LIVE_MAIN_MENU_H


#include <SFML/Graphics.hpp>
#include "../../components/button/button.h"
#include "../../game_screen/game_screen.h"

class MainMenu : public GameScreen {
public:
    sf::RectangleShape background;
    std::vector<Button *> buttons;

    explicit MainMenu(sf::RenderWindow &);

    void render(sf::RenderTarget &);

    static void exit(sf::RenderWindow &);

    void update();
};


#endif //CELLS_LIVE_MAIN_MENU_H
