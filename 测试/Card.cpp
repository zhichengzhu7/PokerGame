#include "Card.h"

Card::Card(const sf::Vector2f& _size, const sf::Vector2f& _pos)
{
    mode = 0;
    no = Poker::randPoker();

    destory = new sf::Texture();
    destory->loadFromFile(sp_res);
    back = new sf::Texture();
    back->loadFromFile(bk_res);
    front = new sf::Texture();
    front->loadFromFile(Poker::getPokerResPath(no));

    setSize(_size);
    setPosition(_pos);
    setTexture(back);
}

Card::~Card()
{
    delete destory;
    delete back;
    delete front;
}

int Card::changeMode()
{
    if (mode == 2)
        return 0;
    mode = !mode;
    if (mode == 0) {
        setTexture(back);
        return -1;
    }
    if (mode == 1) {
        setTexture(front);
        return 1;
    }
}

void Card::find()
{
    mode = 2;
    setTexture(destory);
}

int Card::getNumber()
{
    return no;
}

bool Card::isPosInButton(sf::Vector2i i)
{
    if(mode == 2)
        return false;
    return Button::isPosInButton(i);
}
