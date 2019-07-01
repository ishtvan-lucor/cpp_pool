#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>
#include "Vec2.hpp"
#include "AGameObject.hpp"

class Enemy : public AGameObject
{
private:
public:
  Enemy(int, int);
  ~Enemy();

  void move(Vec2, float);
	void display();
};

#endif