#include "Mine.hpp"
#include <sstream>
#include <iostream>

namespace minesweeper
{

static const sf::Color Grey(125, 125, 125);

const std::vector<sf::Color> Mine::DefaultColours({  
    sf::Color::Transparent,
    sf::Color::Blue,
    sf::Color::Green,
    sf::Color::Red,
    sf::Color(153, 0, 153), // purple
    sf::Color::Yellow
}); 

Mine::Mine()
    : m_State(State::Inactive),
      m_TotalNeighbours(0),
      m_Show(false), m_Flagged(false)
{
    m_Block.setOutlineColor(sf::Color::Black);
    m_Block.setOutlineThickness(1.0f);
    SetVisible(false);
    SetTotalNeighbours(0);
    SetSize(0);
    SetPosition(sf::Vector2f(0, 0));
}

void Mine::SetPosition(const sf::Vector2f& pos)
{
    m_Position = pos;
    m_Text.setPosition(sf::Vector2f(pos.x+3, pos.y-3));
    m_Block.setPosition(pos);
    m_Mine.setPosition(pos);
    m_Flag.setPosition(pos);
}

void Mine::SetSize(float size)
{
    m_Size = size;
    m_Text.setCharacterSize(size);
    sf::Vector2f sizeVector(size, size);
    m_Block.setSize(sizeVector);
    m_Mine.setSize(sizeVector);
    m_Flag.setSize(sizeVector);
}

void Mine::SetVisible(bool visible)
{
    m_Show = visible;
    if (visible)
        m_Block.setFillColor(sf::Color::White);
    else
        m_Block.setFillColor(Grey);

}

void Mine::SetTexture(TextureType type, const sf::Texture& texture)
{
    switch (type)
    {
    case Flag:  m_Flag.setTexture(&texture);  break;
    case Block: m_Block.setTexture(&texture); break;
    case MineTex:  m_Mine.setTexture(&texture);  break;
    }
}

void Mine::SetFont(const sf::Font& font)
{
    m_Text.setFont(font);
}

void Mine::SetTotalNeighbours(unsigned totalNeighbours, const std::vector<sf::Color>& colours)
{
    m_TotalNeighbours = totalNeighbours;
    m_Text.setString(std::to_string((int)totalNeighbours));
    if (totalNeighbours >= (unsigned)colours.size())
        m_Text.setFillColor(colours.at(colours.size()-1));
    else
        m_Text.setFillColor(colours.at(totalNeighbours));
}

void Mine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Block, states);
    
    if (!m_Show)
    {
        if (m_Flagged)
            target.draw(m_Flag, states);
        return;
    }
        
    switch (m_State)
    {
    case State::Active:
        target.draw(m_Mine, states);
        break;
    case State::Inactive:
        if (m_TotalNeighbours > 0)
            target.draw(m_Text, states);
        break;
    }
}

}