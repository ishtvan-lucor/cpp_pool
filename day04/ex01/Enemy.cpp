#include "Enemy.hpp"

Enemy::Enemy(int hp, const std::string &type): _hp(hp), _type(type)
{}

Enemy::Enemy(Enemy const &copy)
{
	*this = copy;
}

Enemy& Enemy::operator=(Enemy const &target)
{
	this->_hp = target.getHP();
	this->_type = target.getType();
	return (*this);
}

Enemy::~Enemy()
{}

void		Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	else if (damage > this->getHP())
		_hp = 0;
	else
		_hp -= damage;
}

int			Enemy::getHP() const
{
	return this->_hp;
}

std::string	Enemy::getType() const
{
	return this->_type;
}