//
// Created by near on 12.09.24.
//

#include "Mandelbrot.h"

Mandelbrot::Mandelbrot(const App& app): app_(app) {
    window_ = app.getWindow();
}
