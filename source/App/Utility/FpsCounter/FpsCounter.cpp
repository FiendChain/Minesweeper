#include "FpsCounter.hpp"

#include <sstream>
#include <iomanip>

FpsCounter::FpsCounter()
{
    m_Text.setFillColor(sf::Color::White);
    m_Text.setOutlineColor(sf::Color::Black);
    m_Text.setOutlineThickness(2.0f);
    m_Text.setCharacterSize(20.0f);
    m_Text.setPosition(10, 10);
}

void FpsCounter::Update(const sf::Clock& clock)
{
    m_FrameTime = (clock.getElapsedTime() - m_LastFrameRender).asMilliseconds();
    m_LastFrameRender = clock.getElapsedTime();
    SetFps(1000.0f/(float)m_FrameTime);
}

void FpsCounter::SetFps(float fps)
{
    m_Fps = fps;
    std::stringstream ss;
    ss << std::setprecision(0) << std::fixed;
    ss << "Fps: " << fps;
    m_Text.setString(ss.str());
}

void FpsCounter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Text, states);
}
