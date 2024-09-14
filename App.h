#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stack>

class App {
public:
    App(int height, int width, std::string name = "Window");

    sf::RenderWindow *getWindow() const;

    void draw(std::vector<sf::Vertex> &drawables);

    ~App();

private:
    int height_, width_;
    sf::RenderWindow *window_;
    std::string name_;
};
