#pragma once
#include <SFML/Graphics.hpp>
class Button {
private:
    sf::RectangleShape shape;
    sf::Vector2f pos;
    sf::Vector2f size;
public:
    Button() {}
    Button(const sf::Vector2f& _size, const sf::Vector2f& _pos, const sf::Texture* _res);
    void set(const sf::Vector2f& _size, const sf::Vector2f& _pos, const sf::Texture* _res);
    void setSize(const sf::Vector2f& _size);
    void setPosition(const sf::Vector2f& _pos);
    void setTexture(const sf::Texture* _res);
    bool isPosInButton(sf::Vector2i);
    sf::RectangleShape getShape();
};

