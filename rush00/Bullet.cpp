#include "Bullet.hpp"

Bullet::Bullet(int x, int y)
{
    Vec2 v(x, y);
    this->_type = "๏";
    this->_pos = v;
}

Bullet::Bullet(Vec2 v)
{
    this->_type = "๏";
    this->_pos = v;
}

Bullet::~Bullet()
{
}

void Bullet::destroy(AGameObject &target)
{
    target.getDamaged();
}