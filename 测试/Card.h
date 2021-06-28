#pragma once
#include "Button.h"
#include "Resource.h"
#include <SFML/Graphics.hpp>
class Card : public Button {
private:
    int mode, no;
    sf::Texture* destory;
    sf::Texture* back;
    sf::Texture* front;
public:
    Card(const sf::Vector2f& _size, const sf::Vector2f& _pos);
    ~Card();
    int changeMode();
    void find();
    int getNumber();
    bool isPosInButton(sf::Vector2i i);
};

