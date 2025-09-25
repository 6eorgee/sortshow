#ifndef RENDERER_H
#define RENDERER_H

#include "SFML/Graphics.hpp"

class Renderer
{
public:
    Renderer(sf::RenderWindow* poWindow_p);
    void Draw(const sf::Shape* const shape) const;
    void Clear() const;
    void Display() const;
    void DrawArray(const int* const arr, const int size) const;

private:
    sf::RenderWindow* m_poWindow = nullptr;
};

#endif // RENDERER_H