#include "App/App.hpp"
#include "Minesweeper/Minesweeper.hpp"

#include <SFML/Graphics.hpp>

class ResourceManager
{
    private:
        sf::Font m_Font;
        sf::Texture m_BlockTexture;
        sf::Texture m_MineTexture;
    public:
        ResourceManager()
        {
            if (!m_Font.loadFromFile("resources/fonts/Arial.ttf"))
                throw std::runtime_error("Couldn't load font!");
        }
        const sf::Font& GetFont() const { return m_Font; }
};

int main(int argc, char *argv[])
{
    sf::Vector2f resolution(1920, 1080);
    unsigned blockSize = 20;
    sf::Vector2f gridSize = resolution / (float)blockSize;

    ResourceManager resourceManager;

    app::App game(resolution.x, resolution.y, 60, "App");
    game.SetFont(resourceManager.GetFont());
    auto& minesweeperGame = game.SetRunnable<minesweeper::Minesweeper>(gridSize.x, gridSize.y, blockSize, 0.5);
    minesweeperGame.SetFont(resourceManager.GetFont());

    game.Run();
    
    return 0;
}