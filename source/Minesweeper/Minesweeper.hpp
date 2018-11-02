#pragma once
#include <SFML/Graphics.hpp>
#include "MineField.hpp" 
 
namespace minesweeper
{

class Minesweeper: public sf::Drawable
{
    private:
        MineField m_MineField;
        const unsigned m_Width, m_Height, m_BlockSize;
    public:
        Minesweeper(unsigned width, unsigned height, unsigned size, float density);
        void PollEvent(const sf::Event& event);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}