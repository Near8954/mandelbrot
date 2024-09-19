cmake_minimum_required(VERSION 3.5.0)
project(Mandelbrot_set VERSION 0.1.0 LANGUAGES C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")


set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML")
set(SFML_DIR "/usr/lib/x86_64-linux-gnu/cmake/SFML")

add_executable(Mandelbrot_set
        App.cpp
        App.h

        Complex.cpp
        Complex.h

        main.cpp
)

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

