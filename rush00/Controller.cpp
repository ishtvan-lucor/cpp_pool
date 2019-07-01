#include <iostream>
#include "Controller.hpp"
#include <ncurses.h>

Controller::Controller() : moveUp(false), moveDown(false), moveLeft(false), moveRight(false), attack(false), end(false)
{
}

Controller::~Controller()
{
}

void Controller::listen(char c)
{
    if (c == D)
        this->setRight();
    else if (c == S)
        this->setDown();
    else if (c == A)
        this->setLeft();
    else if (c == W)
        this->setUp();
    else if (c == SPACE)
        this->setAttack();
    else if (c == END)
        this->setEnd();
}

void Controller::setAttack()
{
    this->attack = true;
}
void Controller::setUp()
{
    this->moveUp = true;
}
void Controller::setDown()
{
    this->moveDown = true;
}
void Controller::setRight()
{
    this->moveRight = true;
}
void Controller::setLeft()
{
    this->moveLeft = true;
}

void Controller::setEnd()
{
    this->end = true;
}

void Controller::refresh(void)
{
    this->end = false;
    this->moveUp = false;
    this->moveDown = false;
    this->moveRight = false;
    this->moveLeft = false;
    this->attack = false;
}

Vec2 Controller::getVector()
{
    int x = 0;
    int y = 0;

    if (this->moveUp)
        y = -1;
    if (this->moveDown)
        y = 1;
    if (this->moveRight)
        x = 1;
    if (this->moveLeft)
        x = -1;

    Vec2 v(x, y);
    return (v);
}