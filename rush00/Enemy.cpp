#include "Enemy.hpp"

Enemy::Enemy(int x, int y)
{
    Vec2 v(x, y);
	this->_type = "໑໑໑";
	this->_type2 = "<ൠ>";
	this->_pos = v;
	this->_pos._x += 1;
}

Enemy::~Enemy()
{
}

void Enemy::move(Vec2 dir, float f)
{
    Vec2 newPosition = dir * (rand() % 6) * f + this->_pos;
    this->_pos = newPosition;
}



void Enemy::display()
{
	mvprintw(this->_pos.getY(), this->_pos.getX(), this->_type.c_str());
	mvprintw(this->_pos.getY() + 1, this->_pos.getX(), this->_type2.c_str());
}