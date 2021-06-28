#include "Game.h"

Game::Game() : _window(sf::VideoMode(1280, 900), title, sf::Style::Close | sf::Style::None) {
    
    backgroudRes = new sf::Texture();
    backgroudRes->loadFromFile(bg_res);
    startRes = new sf::Texture();
    startRes->loadFromFile(st_res);
    exitRes = new sf::Texture();
    exitRes->loadFromFile(ex_res);
    returnRes = new sf::Texture();
    returnRes->loadFromFile(re_res);

    _window.setFramerateLimit(120);
    _window.setVerticalSyncEnabled(false);

    backgroudShape.setSize({ 1280, 900 });
    backgroudShape.setPosition(0, 0);
    backgroudShape.setTexture(backgroudRes);

    startButton.set({ 470, 180 }, { 405, 360 }, startRes);
    exitButton.set({ 180, 180 }, { 900, 360 }, exitRes);
    returnButton.set({ 120, 120 }, { 1050, 670 }, returnRes);

    mode = 0;
    click = 0;
    clicked = false;
    won = false;
    number = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cardBoard[i][j] = NULL;
}

Game::~Game() {
    delete backgroudRes;
    delete startRes;
    delete exitRes;
    delete returnRes;
    destoryGame();
}

// for design the graphics
void Game::render() {
    _window.clear();
    _window.draw(backgroudShape);
    if (mode == 0) {
        _window.draw(startButton.getShape());
        _window.draw(exitButton.getShape());
    }
    else if (mode == 1) {
        _window.draw(returnButton.getShape());
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                _window.draw(cardBoard[i][j]->getShape());
    }
    _window.display();
}

// response for the event
void Game::processEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            _window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
            mousePos = sf::Mouse::getPosition(_window);
            if (checkButton() == false && mode == 1 && clicked == false && won == false) {
                isClickedCard();
                if (click == 2) {
                    clicked = true;
                    start = clock();
                }
            }
        }
    }
}

bool Game::checkButton() {
    if (mode == 0) {
        if (startButton.isPosInButton(mousePos)) {
            initGame();
            mode = 1;
            pressSound.openFromFile(ps_sound);
            pressSound.play();
            return true;
        }
        else if (exitButton.isPosInButton(mousePos)) {
            pressSound.openFromFile(ps_sound);
            pressSound.play();
            _window.close();
            return true;
        }
    }
    else if (mode == 1) {
        if (returnButton.isPosInButton(mousePos)) {
            mode = 0;
            pressSound.openFromFile(ps_sound);
            pressSound.play();
            return true;
        }
    }
}

void Game::initGame() {
    Poker::initPoker();
    click = 0;
    clicked = false;
    won = false;
    number = 0;
    destoryGame();
    for (int i = 0; i < rows * cols; i++) {
        int number = rand() % (rows * cols);
        while (cardBoard[number / cols][number % cols])
            number = (number + 1) % (rows * cols);
        int row = number / cols, col = number % cols;
        cardBoard[row][col] = new Card({ 105, 150 }, { float(165 * col + 225), float(160 * row + 50) });
    }
    startSound.openFromFile(st_sound);
    startSound.play();
}

void Game::destoryGame() {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (cardBoard[i][j]) {
                delete cardBoard[i][j];
                cardBoard[i][j] = NULL;
            }
}

bool Game::isClickedCard() {
    if (mode == 1) 
        for(int i = 0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if (cardBoard[i][j]->isPosInButton(mousePos)) {
                    click += cardBoard[i][j]->changeMode();
                    if (click == 1)
                        choicePos1 = { i, j };
                    if (click == 2)
                        choicePos2 = { i, j };
                    pressSound.openFromFile(ps_sound);
                    pressSound.play();
                    return true;
                }
    return false;
}

// cartoon
void Game::animation() {
    if (mode == 1) {
        if (clicked) {
            if (clock() - start > 500)
                clicked = false;
        }
        if (won) {
            if (clock() - start > 1500) {
                clicked = false;
                mode = 0;
            }
        }
    }
}

void Game::update() {
    if (mode == 1) {
        animation();
        if (click == 2 && clicked == false) {
            if (cardBoard[choicePos1.x][choicePos1.y]->getNumber() == cardBoard[choicePos2.x][choicePos2.y]->getNumber()) {
                cardBoard[choicePos1.x][choicePos1.y]->find();
                cardBoard[choicePos2.x][choicePos2.y]->find();
                rightSound.openFromFile(st_sound);
                rightSound.play();
                number += 2;
                if (number == rows * cols) {
                    winSound.openFromFile(win_sound);
                    winSound.play();
                    won = true;
                    start = clock();
                }
            }
            else {
                cardBoard[choicePos1.x][choicePos1.y]->changeMode();
                cardBoard[choicePos2.x][choicePos2.y]->changeMode();
                wrongSound.openFromFile(wy_sound);
                wrongSound.play();
            }
            click = 0;
        }
    }
}

void Game::Run() {
    while (_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}