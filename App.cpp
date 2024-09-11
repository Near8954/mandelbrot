#include "App.h"

App::App(int height, int width, std::string name)
    : height_(height), width_(width), name_(std::move(name)) {
    window_ = new sf::RenderWindow(sf::VideoMode(height_, width_), name_);
    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                float x = event.mouseButton.x;
                float y = event.mouseButton.y;
            }
        }
        window_->clear();
        window_->display();
    }
}

App::~App() { delete window_; }
