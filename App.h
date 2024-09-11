#include <SFML/Graphics.hpp>
#include <string>

class App {
public:
    App(int height, int width, std::string name = "Window");

    ~App();

private:
    int height_, width_;
    sf::RenderWindow *window_;
    std::string name_;
};
