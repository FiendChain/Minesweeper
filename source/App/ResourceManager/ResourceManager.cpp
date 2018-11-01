#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
    if (!m_Font.loadFromFile("resources/fonts/Arial.ttf"))
    {
        throw std::runtime_error("Couldn't load font");
    }    
}