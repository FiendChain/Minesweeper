#include "Minesweeper.hpp"

namespace minesweeper
{

Minesweeper::Minesweeper(unsigned width, unsigned height, float size, float density)
    : m_Width(width), m_Height(height), m_BlockSize(size),
      m_Density(density),
      m_MineField(width, height, size, density),
      m_State(State::Waiting) 
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
    case sf::Event::KeyPressed:
        switch (event.key.code)
        {
        case sf::Keyboard::R:
            ResetGame();
            break;
        }
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

void Minesweeper::StartGame(int col, int row)
{
    for (int offsetX = -1; offsetX <= 1; offsetX++)
        for (int offsetY = -1; offsetY <= 1; offsetY++)
        {
            m_MineField.RemoveMine(col+offsetX, row+offsetY);
        }

    FloodFillReveal(col, row);
    m_State = State::Start;
}

void Minesweeper::EndGame()
{
    for (int col = 0; col < m_Width; col++)
        for (int row = 0; row < m_Height; row++)
        {
            m_MineField.GetMine(col, row).SetVisible(true);
        }
    m_State = State::End;
}

void Minesweeper::ResetGame()
{
    m_State = State::Waiting;
    m_MineField.ResetGrid(m_Density);
}

void Minesweeper::LClickMine(int x, int y)
{
    int col = x / m_BlockSize;
    int row = y / m_BlockSize;
    if (!m_MineField.ValidateIndex(col, row))
        return;

    auto& mine = m_MineField.GetMine(col, row);

    switch (m_State)
    {
    case State::Waiting:
        StartGame(col, row);
        break;
    case State::Start:
        if (mine.IsFlagged()) break;
        switch (mine.GetState())
        {
        case Mine::State::Inactive:
            FloodFillReveal(col, row);
            break;
        case Mine::State::Active:
            mine.SetVisible(true);
            EndGame();
            break;
        }
        break;
    }   
}

void Minesweeper::RClickMine(int x, int y)
{
    int col = x / m_BlockSize;
    int row = y / m_BlockSize;

    if (!m_MineField.ValidateIndex(col, row))
        return;

    auto& mine = m_MineField.GetMine(col, row);
    mine.SetFlagged(!mine.IsFlagged());
}

void Minesweeper::FloodFillReveal(int col, int row)
{
    if (!m_MineField.ValidateIndex(col, row))
        return;

    auto& mine = m_MineField.GetMine(col, row);
    if (mine.IsVisible()) 
        return;
    if (mine.GetState() == Mine::State::Active)
        return;

    mine.SetVisible(true);
    if (mine.GetTotalNeighbours() > 0)
        return;

    for (int offsetX = -1; offsetX <= 1; offsetX++)
        for (int offsetY = -1; offsetY <= 1; offsetY++)
        {
            if (offsetX == 0 && offsetY == 0)
                continue;
            FloodFillReveal(col+offsetX, row+offsetY);
        }      
}

void Minesweeper::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_MineField, states);
}

}