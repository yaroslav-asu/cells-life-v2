#include <SFML/Graphics.hpp>
#include "interface/components/button/button.h"
#include "interface/menus/main/main_menu.h"

int main(){
    sf::Vector2i windowSize(500, 500);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Cells Live");
    MainMenu mainMenu = *new MainMenu(windowSize);
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        mainMenu.render(window);
        mainMenu.update();
        window.display();

    }
    return 0;
}
