#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stack>

class App {
public:
    App(int height, int width, std::string name = "Window", bool wb = false);

    sf::RenderWindow *getWindow() const;

    void draw(std::vector<sf::Vertex> &drawables);

    friend void calculateVertices(std::vector<sf::Vertex> &vertices, double col_start, double col_end, double row_start,
                                  double row_end, int hei, int wid);

    ~App();

private:
    int height_, width_;
    sf::RenderWindow *window_;
    std::string name_;
    bool wb_;
};
