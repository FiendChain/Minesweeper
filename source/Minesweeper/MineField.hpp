#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Mine.hpp"

namespace minesweeper
{

class MineField: public sf::Drawable
{
    private:
        std::vector<Mine> m_Mines;
        std::default_random_engine m_RngEngine;
        const unsigned m_Width, m_Height, m_BlockSize;
    public:
        MineField(unsigned width, unsigned height, unsigned size, float density);
        void ResetGrid(float density);
        void SetMineTexture(const sf::Texture& texture);
        void SetBlockTexture(const sf::Texture& texture);
        void SetFont(const sf::Font& font);
    private:
        inline int GetIndex(int col, int row) const { return row*m_Width + col; }
        void RandomiseGrid(float density);
        void GetMinesPerGrid();
        void UpdateGrid();
        unsigned GetMooreNeighbours(int col, int row, int range=1) const;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}