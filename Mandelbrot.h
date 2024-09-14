#include "App.h"

#ifndef MANDELBROT_H
#define MANDELBROT_H


class Mandelbrot {
public:
    Mandelbrot();

    Mandelbrot(int width, int height);

    Mandelbrot(const App& app);

    ~Mandelbrot();

private:
    App app_;
    sf::RenderWindow *window_;
};


#endif //MANDELBROT_H
