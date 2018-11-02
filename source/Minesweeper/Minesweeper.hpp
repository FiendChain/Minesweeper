#pragma once
#include <SFML/Graphics.hpp>
#include "MineField.hpp" 
#include "../App/Base.hpp"
 
namespace minesweeper
{

class Minesweeper: public app::Base
{
    private:
        MineField m_MineField;
        const unsigned m_Width, m_Height, m_BlockSize;
    public:
        Minesweeper(unsigned width, unsigned height, unsigned size, float density);
        virtual void Update(float deltaTime) {}
        virtual void PollEvent(const sf::Event& event);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}