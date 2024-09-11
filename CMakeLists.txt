cmake_minimum_required(VERSION 3.5.0)
project(Mandelbrot_set VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML")
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")


add_executable(Mandelbrot_set
        App.cpp
        App.h

        complex.cpp
        complex.h

        main.cpp)

include(CTest)

find_package(SFML 2.6.1 COMPONENTS network audio graphics window system REQUIRED)

target_link_libraries(${PROJECT_NAME}
        sfml-network
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
)

enable_testing()

