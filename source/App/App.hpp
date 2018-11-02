#pragma once

#include "Camera/ControllableCamera.hpp"
#include "ResourceManager/ResourceManager.hpp"
#include "Utility/FpsCounter/FpsCounter.hpp"
#include "Base.hpp"

#include <SFML/Graphics.hpp>
#include <random>
#include <string>
#include <memory>

namespace app
{

class App
{
    private:
        unsigned m_Width, m_Height, m_Fps;
        bool m_Paused;
        sf::RenderWindow m_Window;
        sf::Clock m_Clock;
        std::default_random_engine m_RngEngine;
        ResourceManager m_ResourceManager;
        FpsCounter m_FpsCounter;
        std::unique_ptr<Base> m_Runnable;
    public:
        App(unsigned width, unsigned height, unsigned fps, const std::string& title);
        void Run();
    private:
        void PollEvents();
        void PollKeyPresses(sf::Keyboard::Key& key);
        void Resize(float x, float y);
        void SetFrameRate(unsigned fps);
        void Update();
        void Render();
};

}