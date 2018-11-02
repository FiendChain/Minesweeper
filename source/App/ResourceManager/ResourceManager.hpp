#pragma once

#include <SFML/Graphics.hpp>
#include <random>

namespace app 
{

class ResourceManager
{
    private:
        sf::Font m_Font;
        sf::Clock m_Clock;
    public:
        ResourceManager();
        inline const sf::Font& GetFont() const { return m_Font; }
        inline const sf::Clock& GetClock() const { return m_Clock; }
};

}