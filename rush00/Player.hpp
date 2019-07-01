#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <ncurses.h>
#include "Vec2.hpp"
#include "AGameObject.hpp"
#include "Bullet.hpp"

class Player : public AGameObject
{
protected:
  Bullet *_bullets;
  Vec2 _edgeMin;
  Vec2 _edgeMax;

public:
  Player(int, int);
  ~Player();

  void attack();
  Bullet *getBullet(void);
  void setMovementEdge(int, int, int, int);
  void move(Vec2 dir, float f);
};

#endif