#pragma once
#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer(const int x, const int y);
    ~Renderer();
    void Draw(const sf::Shape* const shape) const;
    void Clear() const;
    void Display() const;
    bool isOpen() const;
    void Close() const;
    bool pollEvent(sf::Event* event) const;
    void DrawArray(const int* const arr, const int size);

private:
    int width, height;
    sf::RenderWindow* window;
};