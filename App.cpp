#include "App.h"
#include "complex.h"

sf::Color get_color(int iter) {
    sf::Color color(iter * 47 % 255, iter * 85 % 255, iter * 92 % 255);
    return color;
}

double recalc(double start_base, double end_base, double start_result, double end_result, double x) {
    double base_len = end_base - start_base;
    double result_len = end_result - start_result;
    double res_x = result_len * x / base_len + start_result;
    return res_x;
}

void calculateVertices(std::vector<sf::Vertex> &vertices, double col_start, double col_end, double row_start,
                       double row_end, int hei, int wid) {
    vertices.clear();
    int iter_num = 255;
    double iinc = (col_end - col_start) / hei;
    double jinc = (row_end - row_start) / wid;
    double i = col_start;
    for (int x = 0; x < hei; i += iinc, ++x) {
        double j = row_start;
        for (int y = 0; y < wid; j += jinc, ++y) {
            Complex c = Complex(i, j);
            Complex z = Complex(0, 0);
            sf::Color color = sf::Color::Black;
            for (int ii = 0; ii < iter_num; ii++) {
                z = z * z + c;
                if (z.get_imag() * z.get_imag() + z.get_real() * z.get_real() > 4) {
                    color = get_color(ii);
                    break;
                }
            }
            sf::Vertex vertex = sf::Vertex(sf::Vector2f(x, y), color);
            vertices.push_back(vertex);
        }
    }
};


App::App(int height, int width, std::string name)
    : height_(height), width_(width), name_(std::move(name)) {
    window_ = new sf::RenderWindow(sf::VideoMode(height_, width_), name_);
    window_->clear(sf::Color(125, 125, 125, 255));
    window_->display();
    sf::Vector2f pressed, released;
    int iter_num = 255;
    sf::RectangleShape rect;
    std::vector<sf::Vertex> vertices;
    double row_start = -2;
    double col_start = -2;
    double row_end = 2;
    double col_end = 2;
    int hei = height_;
    int wid = width_;


    calculateVertices(vertices, col_start, col_end, row_start, row_end, hei, wid);

    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                pressed = sf::Vector2f(sf::Mouse::getPosition(*window_).x, sf::Mouse::getPosition(*window_).y);
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                released = sf::Vector2f(sf::Mouse::getPosition(*window_).x, sf::Mouse::getPosition(*window_).y);
                sf::Vector2f left_up = sf::Vector2f(std::min(pressed.x, released.x), std::min(pressed.y, released.y));
                sf::Vector2f right_down =
                        sf::Vector2f(std::max(pressed.x, released.x), std::max(pressed.y, released.y));


                double new_row_start = recalc(0, 800, row_start, row_end, left_up.x);
                // right_up.x / wid * (row_end - row_start);
                double new_row_end = recalc(0, 800, row_start, row_end, right_down.x);
                // left_down.x / wid * (row_end - row_start);
                double new_col_start = recalc(0, 800, col_start, col_end, left_up.y);
                // left_down.y / hei * (col_end - col_start);
                double new_col_end = recalc(0, 800, col_start, col_end, right_down.y);
                // right_up.y / hei * (col_end - col_start);

                std::cout << pressed.x << " " << pressed.y << " " << released.x << " " << released.y << "\n";
                std::cout << new_row_start << " " << new_row_end << " " << new_col_start << " " << new_col_end << "\n";

                row_start = new_row_start;
                row_end = new_row_end;
                col_start = new_col_start;
                col_end = new_col_end;

                if (row_start > row_end) {
                    std::swap(row_start, row_end);
                }
                if (col_start > col_end) {
                    std::swap(col_start, col_end);
                }

                // std::cout << col_start << ' ' << col_end << std::endl;
                // std::cout << row_start << ' ' << row_end << std::endl;

                calculateVertices(vertices, col_start, col_end, row_start, row_end, hei, wid);
            }
        }
        window_->clear(sf::Color(125, 125, 125, 255));
        draw(vertices);
        window_->display();
    }
}

void App::draw(std::vector<sf::Vertex> &drawables) {
    for (auto e: drawables) {
        window_->draw(&e, 1, sf::Points);
    }
}

sf::RenderWindow *App::getWindow() const {
    return window_;
}

App::~App() {
    delete window_;
}
