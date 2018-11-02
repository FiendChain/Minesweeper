#pragma once

#include "Camera/ControllableCamera.hpp"
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
        FpsCounter m_FpsCounter;
        ControllableCamera m_Camera;
        std::unique_ptr<Base> m_Runnable;
    public:
        App(unsigned width, unsigned height, unsigned fps, const std::string& title);
        void SetFont(const sf::Font& font);
        void Run();
        template <typename T, typename ...Args>
        T& SetRunnable(Args&& ...args);
    private:
        void PollEvents();
        void PollKeyPresses(sf::Keyboard::Key& key);
        void Resize(float x, float y);
        void SetFrameRate(unsigned fps);
        void Update();
        void Render();
};

template <typename T, typename ...Args>
T& App::SetRunnable(Args&& ...args) 
{
    T *runnable = new T(std::forward<Args>(args)...);
    m_Runnable = std::unique_ptr<Base>(runnable);
    return *runnable;
}

}