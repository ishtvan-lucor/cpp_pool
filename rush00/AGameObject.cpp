//
// Created by Ishtvan KOLOSHYNSKY on 2019-06-30.
//

#include "AGameObject.hpp"

AGameObject::AGameObject() : _pos(Vec2(0, 0)), _alive(true)
{
}

AGameObject::AGameObject(const AGameObject &copy)
{
    *this = copy;
}

AGameObject &AGameObject::operator=(const AGameObject &copy)
{
    this->_pos = copy.getPos();
    this->_alive = copy.isAlive();
    return *this;
}

AGameObject::~AGameObject()
{
}

void AGameObject::move(Vec2 dir, float delta)
{
    Vec2 newPosition = (dir * delta) + this->_pos;
    this->_pos = newPosition;
}

bool AGameObject::collision(Vec2 const &obj)
{
    return (obj == this->_pos);
}

const Vec2 &AGameObject::getPos() const
{
    return _pos;
}

void AGameObject::setPos(const Vec2 &pos)
{
    _pos = pos;
}

bool AGameObject::isAlive() const
{
    return _alive;
}

void AGameObject::setAlive(bool alive)
{
    _alive = alive;
}

void AGameObject::display()
{
    mvprintw(this->_pos.getY(), this->_pos.getX(), this->_type.c_str());
}

void AGameObject::getDamaged()
{
    std::cout << "Fuck, I am damaged" << std::endl;
}
