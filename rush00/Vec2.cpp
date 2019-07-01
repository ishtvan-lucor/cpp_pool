//
// Created by Ishtvan KOLOSHYNSKY on 2019-06-30.
//

#include "Vec2.hpp"

Vec2::Vec2() : _x(0), _y(0)
{
}

Vec2::Vec2(int x, int y) : _x(x), _y(y)
{
}

Vec2::Vec2(Vec2 const &copy)
{
    *this = copy;
}

Vec2 &Vec2::operator=(Vec2 const &target)
{
    _x = target.getX();
    _y = target.getY();
    return (*this);
}

Vec2::~Vec2()
{
}

bool Vec2::operator==(const Vec2 &rhs) const
{
    return _x == rhs._x &&
           _y == rhs._y;
}

Vec2 Vec2::clampEdge(Vec2 edgeMin, Vec2 edgeMax)
{
    Vec2 v = *this;

    if (v._x < edgeMin.getX())
        v._x = edgeMin.getX();
    if (v._y < edgeMin.getY())
        v._y = edgeMin.getY();
    if (v._x > edgeMax.getX())
        v._x = edgeMax.getX();
    if (v._y > edgeMax.getY())
        v._y = edgeMax.getY();

    return (v);
}

bool Vec2::operator!=(const Vec2 &rhs) const
{
    return !(rhs == *this);
}

Vec2 Vec2::operator-(const Vec2 &b)
{
    Vec2 v;

    v.setX(this->_x - b.getX());
    v.setY(this->_y - b.getY());

    return (v);
}

Vec2 Vec2::operator+(const Vec2 &b)
{
    Vec2 v;

    v.setX(this->_x + b.getX());
    v.setY(this->_y + b.getY());

    return (v);
}

Vec2 Vec2::operator*(float b)
{
    Vec2 v;

    v.setX((int)roundf(this->_x * b));
    v.setY((int)roundf(this->_y * b));

    return (v);
}

int Vec2::getX() const
{
    return _x;
}

int Vec2::getY() const
{
    return _y;
}

void Vec2::setY(int y)
{
    _y = y;
}

void Vec2::setX(int x)
{
    _x = x;
}

bool Vec2::checkRadius(Vec2 v, int r)
{
    int ax = v.getX();
    int ay = v.getY();

    if (ay - r <= _y && ay + r >= _y)
    {
        if (ax - r <= _x && ax + r >= _x)
            return (true);
    }
    return (false);
}

bool Vec2::outOfEdge(Vec2 edgeMin, Vec2 edgeMax) const
{
    Vec2 v = *this;

    if (v._x < edgeMin.getX())
        return (true);
    if (v._y < edgeMin.getY())
        return (false);
    if (v._x > edgeMax.getX())
        return (true);
    if (v._y > edgeMax.getY())
        return (true);

    return (false);
}

