#pragma once

#include <SFML/Graphics.hpp>

namespace app
{

class Base: public sf::Drawable
{
    public:
        virtual void PollEvent(const sf::Event& event) = 0;
        virtual void Update(float deltaTime) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

}