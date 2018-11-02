#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace minesweeper
{

class Mine: public sf::Drawable
{
    public:
        enum State { Active, Inactive };
        enum TextureType { Block, MineTex, Flag };
    private:
        const static std::vector<sf::Color> DefaultColours;
    private:
        State m_State;
        unsigned m_TotalNeighbours;
        bool m_Show, m_Flagged;
        sf::RectangleShape m_Block, m_Mine, m_Flag;
        sf::Text m_Text;
        float m_Size;
        sf::Vector2f m_Position;
    public:
        Mine();
        void SetPosition(const sf::Vector2f& pos);
        inline const sf::Vector2f& GetPosition() const { return m_Position; }
        void SetSize(float size);
        inline float GetSize() const { return m_Size; }
        void SetTexture(TextureType type, const sf::Texture& texture);
        void SetFont(const sf::Font& font);
        inline void SetState(State state) { m_State = state; }
        inline State GetState() const     { return m_State; }
        void SetTotalNeighbours(unsigned totalNeighbours, const std::vector<sf::Color>& colours = Mine::DefaultColours);
        inline unsigned GetTotalNeighbours() const { return m_TotalNeighbours; }
        void SetVisible(bool visible);
        inline bool IsVisible() const        { return m_Show; }
        inline void SetFlagged(bool flagged) { m_Flagged = flagged; }
        inline bool IsFlagged() const        { return m_Flagged; }
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}