#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class App {
public:
    explicit App(int height = 800, int width = 800, std::string name = "Window", bool wb = false);

    ~App();

    void draw(std::vector<sf::Vertex> &drawables);

    void draw(sf::Vector2f &clicked);

private:
    int height_, width_;
    sf::RenderWindow *window_;
    std::string name_;
    bool wb_;
};
