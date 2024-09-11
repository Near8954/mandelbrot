#include <iostream>
#include <vector>
#include "App.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;

            }
        }
        window.clear();
        window.display();
    }
    return 0;
}