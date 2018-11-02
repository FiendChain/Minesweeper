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
        const unsigned m_Width, m_Height;
        const float m_BlockSize;
    public:
        Minesweeper(unsigned width, unsigned height, float size, float density);
        void SetFont(const sf::Font& font);
        void SetTexture(Mine::TextureType type, const sf::Texture& texture);
        virtual void Update(float deltaTime) {}
        virtual void PollEvent(const sf::Event& event);
    private:
        void LClickMine(int x, int y);
        void RClickMine(int x, int y);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}