#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace minesweeper
{

class Mine: public sf::Drawable
{
    public:
        enum State { Active, Inactive };
    private:
        const static std::vector<sf::Color> DefaultColours;
    private:
        State m_State;
        unsigned m_TotalNeighbours;
        bool m_Show;
        sf::RectangleShape m_Block, m_Mine;
        sf::Text m_Text;
        unsigned m_Size;
        sf::Vector2f m_Position;
    public:
        Mine();
        void SetPosition(const sf::Vector2f& pos);
        inline const sf::Vector2f& GetPosition() const { return m_Position; }
        void SetSize(unsigned size);
        inline unsigned GetSize() const { return m_Size; }
        void SetBlockTexture(const sf::Texture& texture);
        void SetMineTexture(const sf::Texture& texture);
        void SetFont(const sf::Font& font);
        inline void SetState(State state) { m_State = state; }
        inline State GetState() const { return m_State; }
        void SetTotalNeighbours(unsigned totalNeighbours, const std::vector<sf::Color>& colours = Mine::DefaultColours);
        inline unsigned GetTotalNeighbours() const { return m_TotalNeighbours; }
        inline void SetVisible(bool visible) { m_Show = visible; }
        inline bool IsVisible() const { return m_Show; }
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}