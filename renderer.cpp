#include "renderer.h"

Renderer::Renderer(sf::RenderWindow* poWindow_p)
    : m_poWindow(poWindow_p)
{}

void Renderer::Draw(const sf::Shape* const shape) const
{
    if (m_poWindow)
    {
        m_poWindow->draw(*shape);
    }
}

void Renderer::Clear() const
{
    if (m_poWindow)
    {
        m_poWindow->clear();
    }
}

void Renderer::Display() const
{
    if (m_poWindow)
    {
        m_poWindow->display();
    }
}

void Renderer::DrawArray(const int* const arr, const int size) const
{
    if (!m_poWindow)
    {
        return;
    }

    int iMargin = 5;
    int iSpaceBetweenBars = 1;
    double dBarWidth = (m_poWindow->getSize().x - 2*iMargin - (size - 1)* iSpaceBetweenBars)
        / static_cast<double>(size);
    for (int i = 0; i < size; ++i)
    {
        double dBarHeight = arr[i] * 2;
        sf::RectangleShape oRectangle(sf::Vector2f(dBarWidth, dBarHeight));
        oRectangle.setFillColor(sf::Color::White);
        double dLeft = iMargin + (dBarWidth + iSpaceBetweenBars)*i;
        double dTop = 500 - dBarHeight;
        oRectangle.setPosition(sf::Vector2f(dLeft, dTop)); 
        m_poWindow->draw(oRectangle);
    }
}
