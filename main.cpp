#include <SFML/Graphics.hpp>
#include "interface/components/button/button.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(500, 500), "Cells Live");
    Button button(100, 100, sf::Vector2f (140, 100), "Text");
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        button.render(window);
        button.update(sf::Mouse::getPosition());
        window.display();
    }
    return 0;
}
