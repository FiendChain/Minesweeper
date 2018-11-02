#pragma once

#include <SFML/Graphics.hpp>

namespace app 
{

class FpsCounter: public sf::Drawable
{
    private:
        sf::Time m_LastFrameRender;
        sf::Text m_Text;
        unsigned m_FrameTime;
        float m_Fps;
    public:
        FpsCounter();
        inline void SetPosition(const sf::Vector2f& position) { m_Text.setPosition(position); }
        inline void SetCharacterSize(float size) { m_Text.setCharacterSize(size); }
        inline void SetFont(const sf::Font& font) { m_Text.setFont(font); }
        void Update(const sf::Clock& clock);
    private:
        void SetFps(float fps);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}