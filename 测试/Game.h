#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Resource.h"
#include "Button.h"
#include "Card.h"
using namespace std;


class Game {
private:
    sf::RenderWindow _window;

    sf::Texture* backgroudRes;
    sf::Texture* startRes;
    sf::Texture* exitRes;
    sf::Texture* returnRes;

    Card* cardBoard[rows][cols];
    sf::RectangleShape backgroudShape;
    Button startButton;
    Button exitButton;
    Button returnButton;

    sf::Music winSound;
    sf::Music startSound;
    sf::Music pressSound;
    sf::Music wrongSound;
    sf::Music rightSound;

    int mode;
    int click;
    bool clicked;
    bool won;
    int number;
    sf::Vector2i mousePos;
    sf::Vector2i choicePos1;
    sf::Vector2i choicePos2;
    clock_t start;

    void update();
    void render();
    void processEvents();
    bool checkButton();
    void initGame();
    void destoryGame();
    bool isClickedCard();
    void animation();
public:
    Game();
    ~Game();
    void Run();
};
