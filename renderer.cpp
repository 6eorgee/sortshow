#include "renderer.h"

Renderer::Renderer(const int x, const int y) : width(x), height(y) {
    window = new sf::RenderWindow(sf::VideoMode(x, y), "SortShow");
}

void Renderer::Draw(const sf::Shape* const shape) const {
    window->draw(*shape);
}

void Renderer::Clear() const {
    window->clear();
}

void Renderer::Display() const {
    window->display();
}

bool Renderer::isOpen() const {
    return window->isOpen();
}

void Renderer::Close() const {
    window->close();
}

bool Renderer::pollEvent(sf::Event* event) const {
    return window->pollEvent(*event);
}

void Renderer::DrawArray(const int* const arr, const int size) {
    int bar_width = (width - 10 - 2*size)/size;
    for (int i = 0; i < size; ++i) {
        int bar_height = arr[i] * 2;
        sf::RectangleShape rectangle(sf::Vector2f(bar_width, bar_height));
        rectangle.setFillColor(sf::Color::White);
        int left = 10 + (bar_width + 2)*i;
        int top = 500 - bar_height;
        rectangle.setPosition(sf::Vector2f(left, top)); 
        window->draw(rectangle);
    }
}

Renderer::~Renderer() {
    if (window->isOpen())
        window->close();
}
