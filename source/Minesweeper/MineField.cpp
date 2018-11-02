#include "MineField.hpp"
#include <random>

namespace minesweeper
{

MineField::MineField(unsigned width, unsigned height, unsigned size, float density)
    : m_Width(width), m_Height(height), m_BlockSize(size),
      m_Mines(width*height)  
{
    for (unsigned col = 0; col < m_Width; col++)
        for (unsigned row = 0; row < m_Height; row++)
        {
            auto& mine = m_Mines.at(GetIndex(col, row));
            mine.SetSize(size);
            mine.SetVisible(true);
            mine.SetPosition(sf::Vector2f(col*size, row*size));
        }

    ResetGrid(density);
}

void MineField::SetMineTexture(const sf::Texture& texture)
{
    for (auto& mine: m_Mines) mine.SetMineTexture(texture);
}

void MineField::SetBlockTexture(const sf::Texture& texture)
{
    for (auto& mine: m_Mines) mine.SetBlockTexture(texture);
}

void MineField::SetFont(const sf::Font& font)
{
    for (auto& mine: m_Mines) mine.SetFont(font);
}


void MineField::ResetGrid(float density)
{
    RandomiseGrid(density);
    GetMinesPerGrid();
}

void MineField::RandomiseGrid(float density)
{
    std::uniform_real_distribution<float> probability_gen(0, 1);
    for (auto& mine: m_Mines)
    {
        float probability = probability_gen(m_RngEngine);
        if (probability < density)
            mine.SetState(Mine::Active);
        else
            mine.SetState(Mine::Inactive);
    }
}

void MineField::GetMinesPerGrid()
{
    for (int col = 0; col < m_Width; col++)
        for (int row = 0; row < m_Height; row++)
        {
            int totalNeighbours = GetMooreNeighbours(col, row);
            m_Mines.at(GetIndex(col, row)).SetTotalNeighbours(totalNeighbours);
        }
}

unsigned MineField::GetMooreNeighbours(int col, int row, int range) const
{
    unsigned totalNeighbours = 0;
    for (int offsetX = -range; offsetX <= range; offsetX++)
        for (int offsetY = -range; offsetY <= range; offsetY++)
        {
            if (offsetX == 0 && offsetY == 0)
                continue;
            if (   offsetX < 0 || offsetX >= (int)m_Width
                || offsetY < 0 || offsetY >= (int)m_Height)
                continue;
            if (m_Mines.at(GetIndex(col, row)).GetState() == Mine::Active)
                totalNeighbours++;
        }

    return totalNeighbours;
}

void MineField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const auto& mine: m_Mines)
    {
        target.draw(mine, states);
    }
}

}