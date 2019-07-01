//
// Created by Ishtvan KOLOSHYNSKY on 2019-06-30.
//

#ifndef RUSH00_AGAMEOBJECT_HPP
#define RUSH00_AGAMEOBJECT_HPP

#define WIDTH 50
#define HEIGHT 50

#include "Vec2.hpp"
#include <iostream>
#include <ncurses.h>

class AGameObject
{
protected:
  Vec2 _pos;
  bool _alive;
  std::string _type;
  std::string _type2;

public:
  AGameObject(void);
  AGameObject(const AGameObject &);
  AGameObject &operator=(const AGameObject &copy);
  virtual ~AGameObject();

  virtual void move(Vec2 dir, float delta);
  virtual void display();
  virtual void getDamaged();
  // virtual void shoot() = 0;
  virtual bool collision(Vec2 const &obj);

  const Vec2 &getPos() const;

  void setPos(const Vec2 &pos);

  bool isAlive() const;

  void setAlive(bool alive);
};

#endif //RUSH00_AGAMEOBJECT_HPP
