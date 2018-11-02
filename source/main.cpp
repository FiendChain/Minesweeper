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
            if (!m_MineTexture.loadFromFile("resources/textures/mine.png"))
                throw std::runtime_error("Couldn't load mine texture!");
        }
        const sf::Font& GetFont() const { return m_Font; }
        const sf::Texture& GetMineTexture() const { return m_MineTexture; }
};

int main(int argc, char *argv[])
{
    sf::Vector2f aspectRatio(16, 9);
    sf::Vector2f resolution(1920, 1080);
    sf::Vector2f gridSize = aspectRatio * 5.0f;
    float blockSize = resolution.x / gridSize.x;
    
    

    ResourceManager resourceManager;

    app::App game(resolution.x, resolution.y, 60, "App");
    game.SetFont(resourceManager.GetFont());
    auto& minesweeperGame = game.SetRunnable<minesweeper::Minesweeper>(gridSize.x, gridSize.y, blockSize, 0.05);
    minesweeperGame.SetFont(resourceManager.GetFont());
    minesweeperGame.SetTexture(minesweeper::Mine::TextureType::MineTex, resourceManager.GetMineTexture());

    game.Run();
    
    return 0;
}
