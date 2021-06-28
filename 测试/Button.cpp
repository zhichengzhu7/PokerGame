#include "Button.h"

Button::Button(const sf::Vector2f& _size, const sf::Vector2f& _pos, const sf::Texture* _res) {
    shape.setSize(_size);
    shape.setPosition(_pos);
    shape.setTexture(_res);
    pos = _pos;
    size = _size;
}

void Button::set(const sf::Vector2f& _size, const sf::Vector2f& _pos, const sf::Texture* _res) {
    shape.setSize(_size);
    shape.setPosition(_pos);
    shape.setTexture(_res);
    pos = _pos;
    size = _size;
}

void Button::setSize(const sf::Vector2f& _size) {
    shape.setSize(_size);
    size = _size;
}

void Button::setPosition(const sf::Vector2f& _pos) {
    shape.setPosition(_pos);
    pos = _pos;
}

void Button::setTexture(const sf::Texture* _res) {
    shape.setTexture(_res);
}

bool Button::isPosInButton(sf::Vector2i i) {
    if (i.x > pos.x && i.y > pos.y && i.x < pos.x + size.x && i.y < pos.y + size.y)
        return true;
    return false;
}

sf::RectangleShape Button::getShape() {
    return shape;
}
