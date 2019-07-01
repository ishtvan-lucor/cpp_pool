#include "Player.hpp"

Player::Player(int x, int y)
{
    Vec2 v(x, y);
    this->_pos = v;
    this->_type = "ꆤ";
    this->_bullets = nullptr;
}

Player::~Player()
{
}

void Player::attack()
{
    system("afplay -t 0.5 laser.wav > /dev/null &");
    if (this->_bullets)
        delete this->_bullets;
    this->_bullets = new Bullet(this->_pos);
}

Bullet *Player::getBullet()
{
    return (this->_bullets);
}

void Player::setMovementEdge(int xMin, int yMin, int xMax, int yMax)
{
    this->_edgeMin = Vec2(xMin, yMin);
    this->_edgeMax = Vec2(xMax, yMax);
}

void Player::move(Vec2 dir, float f)
{
    Vec2 newPosition = (dir * f) + this->_pos;

    this->_pos = newPosition.clampEdge(this->_edgeMin, this->_edgeMax);
}