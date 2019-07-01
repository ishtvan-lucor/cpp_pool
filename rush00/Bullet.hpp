#ifndef BULLET_HPP
#define BULLET_HPP

#include <iostream>
#include <ncurses.h>
#include "Vec2.hpp"
#include "AGameObject.hpp"

class Bullet : public AGameObject
{
private:
public:
  Bullet(int, int);
  Bullet(Vec2);
  ~Bullet();
  void destroy(AGameObject &target);
};

#endif