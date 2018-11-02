#include "Minesweeper.hpp"

namespace minesweeper
{

Minesweeper::Minesweeper(unsigned width, unsigned height, unsigned size, float density)
    : m_Width(width), m_Height(height), m_BlockSize(size),
      m_MineField(width, height, size, density) 
{

}

void PollEvent(const sf::Event& event)
{
    switch (event.type)
    {
        
    }
}

void Minesweeper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_MineField, states);
}

}