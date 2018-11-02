#include "App/App.hpp"
#include "Minesweeper/Minesweeper.hpp"

int main(int argc, char *argv[])
{
    sf::Vector2f resolution(1920, 1080);
    unsigned blockSize = 20;
    app::App game(resolution.x, resolution.y, 60, "App");
    sf::Vector2f gridSize = resolution / (float)blockSize;
    game.SetRunnable<minesweeper::Minesweeper>(gridSize.x, gridSize.y, blockSize, 0.5);
    game.Run();
    
    return 0;
}