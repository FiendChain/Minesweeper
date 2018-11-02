#include "Minesweeper.hpp"

namespace minesweeper
{

Minesweeper::Minesweeper(unsigned width, unsigned height, float size, float density)
    : m_Width(width), m_Height(height), m_BlockSize(size),
      m_MineField(width, height, size, density) 
{

}

void Minesweeper::PollEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        switch (event.mouseButton.button)
        {
        case sf::Mouse::Button::Left:
            LClickMine(event.mouseButton.x, event.mouseButton.y);
            break;
        case sf::Mouse::Button::Right:
            RClickMine(event.mouseButton.x, event.mouseButton.y);
            break;
        }
        break;
    }
}

void Minesweeper::SetFont(const sf::Font& font)
{
    m_MineField.SetFont(font);
}

void Minesweeper::SetTexture(Mine::TextureType type, const sf::Texture& texture)
{
    m_MineField.SetTexture(type, texture);
}


void Minesweeper::LClickMine(int x, int y)
{
    int col = x / m_BlockSize;
    int row = y / m_BlockSize;
    if (   col >= 0 && col < (int)m_Width
        && row >= 0 && row < (int)m_Height)
    {
        auto& mine = m_MineField.GetMine(col, row);
        if (!mine.IsFlagged())
            m_MineField.GetMine(col, row).SetVisible(true);
    }
}

void Minesweeper::RClickMine(int x, int y)
{
    int col = x / m_BlockSize;
    int row = y / m_BlockSize;
    if (   col >= 0 && col < (int)m_Width
        && row >= 0 && row < (int)m_Height)
    {
        auto& mine = m_MineField.GetMine(col, row);
        mine.SetFlagged(!mine.IsFlagged());
    }
}

void Minesweeper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_MineField, states);
}

}