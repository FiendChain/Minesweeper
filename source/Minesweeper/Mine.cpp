#include "Mine.hpp"
#include <sstream>

namespace minesweeper
{

const std::vector<sf::Color> Mine::DefaultColours({  
    sf::Color::Transparent,
    sf::Color::Blue,
    sf::Color::Green,
    sf::Color::Red,
    sf::Color(153, 0, 153), // purple
    sf::Color::Black,
}); 

Mine::Mine()
    : m_State(State::Inactive),
      m_TotalNeighbours(0),
      m_Show(false)
{
    m_Block.setFillColor(sf::Color::Black);
    m_Mine.setFillColor(sf::Color::Transparent);
    m_Text.setFillColor(sf::Color::White);
    m_Text.setOutlineColor(sf::Color::Black);
    m_Text.setOutlineThickness(1.5f);
    SetSize(0);
    SetPosition(sf::Vector2f(0, 0));
}

void Mine::SetPosition(const sf::Vector2f& pos)
{
    m_Position = pos;
    m_Text.setPosition(pos);
    m_Block.setPosition(pos);
    m_Mine.setPosition(pos);
}

void Mine::SetSize(unsigned size)
{
    m_Size = size;
    m_Text.setCharacterSize(size);
    m_Block.setSize(sf::Vector2f(size, size));
    m_Mine.setSize(sf::Vector2f(size, size));
}

void Mine::SetBlockTexture(const sf::Texture& texture)
{
    m_Block.setTexture(&texture);
}

void Mine::SetMineTexture(const sf::Texture& texture)
{
    m_Mine.setTexture(&texture);
}

void Mine::SetFont(const sf::Font& font)
{
    m_Text.setFont(font);
}

void Mine::SetTotalNeighbours(unsigned totalNeighbours, const std::vector<sf::Color>& colours)
{
    m_TotalNeighbours = totalNeighbours;
    std::stringstream ss;
    ss << totalNeighbours;
    m_Text.setString(ss.str());
    if (totalNeighbours >= colours.size())
        m_Text.setFillColor(colours.at(colours.size()-1));
    else
        m_Text.setFillColor(colours.at(totalNeighbours));
}

void Mine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Block, states);
    
    if (!m_Show)
        return;
    
    switch (m_State)
    {
    case State::Active:
        target.draw(m_Mine, states);
        break;
    case State::Inactive:
        target.draw(m_Text, states);
        break;
    }
}

}