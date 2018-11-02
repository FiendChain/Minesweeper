#include "MineField.hpp"
#include <random>

namespace minesweeper
{

MineField::MineField(unsigned width, unsigned height, float size, float density)
    : m_Width(width), m_Height(height), m_BlockSize(size),
      m_Mines(width*height)  
{
    for (unsigned col = 0; col < m_Width; col++)
        for (unsigned row = 0; row < m_Height; row++)
        {
            auto& mine = m_Mines.at(GetIndex(col, row));
            mine.SetSize(size);
            mine.SetVisible(false);
            mine.SetPosition(sf::Vector2f(col*size, row*size));
        }

    ResetGrid(density);
}

Mine& MineField::GetMine(int col, int row)
{
    return m_Mines.at(GetIndex(col, row));
}

void MineField::SetTexture(Mine::TextureType type, const sf::Texture& texture)
{
    for (auto& mine: m_Mines) 
        mine.SetTexture(type, texture);
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
            unsigned totalNeighbours = GetMooreNeighbours(col, row);
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
            if (   col+offsetX < 0 || col+offsetX >= (int)m_Width
                || row+offsetY < 0 || row+offsetY >= (int)m_Height)
                continue;
            if (m_Mines.at(GetIndex(col+offsetX, row+offsetY)).GetState() == Mine::Active)
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