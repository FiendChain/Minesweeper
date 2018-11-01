#include "App/App.hpp"

int main(int argc, char *argv[])
{
    sf::Vector2f aspectRatio(16, 9);
    sf::Vector2f resolution = aspectRatio * 10.0f;
    App app(resolution.x, resolution.y, 60, "App");
    app.Run();
    
    return 0;
}