#pragma once
#include <SFML/Graphics.hpp>
#include "MineField.hpp" 
#include "../App/Base.hpp"
 
namespace minesweeper
{

class Minesweeper: public app::Base
{
    private:
        enum State { Start, End, Waiting };
    private:
        MineField m_MineField;
        const unsigned m_Width, m_Height;
        const float m_BlockSize;
        const float m_Density;
        State m_State;
    public:
        Minesweeper(unsigned width, unsigned height, float size, float density);
        void SetFont(const sf::Font& font);
        void SetTexture(Mine::TextureType type, const sf::Texture& texture);
        virtual void Update(float deltaTime) {}
        virtual void PollEvent(const sf::Event& event);
    private:
        void LClickMine(int x, int y);
        void RClickMine(int x, int y);
        void StartGame(int col, int row);
        void EndGame();
        void ResetGame();
        void FloodFillReveal(int col, int row);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}