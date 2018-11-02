#include "App.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace app 
{

App::App(unsigned width, unsigned height, unsigned fps, const std::string& title)
    : m_Width(width), m_Height(height),
      m_Fps(fps),
      m_Window(sf::VideoMode(width, height), title),
      m_Paused(false),
      m_Runnable(nullptr)
{ 
    m_Window.setFramerateLimit(fps);
    m_FpsCounter.SetFont(m_ResourceManager.GetFont());
}

void App::Run()
{
    while (m_Window.isOpen())
    {
        PollEvents();
        Update();
        Render();
    }
}

void App::PollEvents()
{
    sf::Event event;
    while (m_Window.pollEvent(event))
    {
        if (m_Runnable)
            m_Runnable->PollEvent(event);
        if (event.type == sf::Event::Closed)
        {
            m_Window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            PollKeyPresses(event.key.code);
        }
    }
}

void App::Resize(float x, float y) 
{
    sf::View view = m_Window.getView();
    m_Width = x;
    m_Height = y;
    view.setSize(x, y);
    m_Window.setView(view);
}

void App::SetFrameRate(unsigned fps)
{
    if (fps < 0 || fps > 1000) return;
    m_Fps = fps;
    m_Window.setFramerateLimit(fps);
}

void App::PollKeyPresses(sf::Keyboard::Key& key)
{
    switch (key)
    {
    case sf::Keyboard::LBracket:
        SetFrameRate(m_Fps-30);
        break;
    case sf::Keyboard::RBracket:
        SetFrameRate(m_Fps+30);
        break;
    case sf::Keyboard::R:
        // reset something
        break;
    case sf::Keyboard::P:
        m_Paused = !m_Paused;
        break;
    case sf::Keyboard::Space:
        if (m_Paused) Update();
        break;
    }
}

void App::Render()
{
    m_Window.clear(sf::Color::Black);
    if (m_Runnable)
        m_Window.draw(*m_Runnable);
    m_Window.draw(m_FpsCounter);
    m_Window.display();
}

void App::Update()
{
    m_FpsCounter.Update(m_ResourceManager.GetClock());
    if (!m_Paused && m_Runnable)
        m_Runnable->Update(0);
}

}



