#ifndef CELLS_LIVE_MAIN_MENU_H
#define CELLS_LIVE_MAIN_MENU_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../../components/button/button.h"

class MainMenu {
public:
    sf::RectangleShape background;
    std::vector<Button *> buttons;

    MainMenu(sf::Vector2i);

    void render(sf::RenderTarget &);

    void update();

    static void exit(sf::RenderWindow &);
};

#endif //CELLS_LIVE_MAIN_MENU_H
