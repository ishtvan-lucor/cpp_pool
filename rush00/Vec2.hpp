//
// Created by Ishtvan KOLOSHYNSKY on 2019-06-30.
//

#ifndef RUSH00_VEC2_HPP
#define RUSH00_VEC2_HPP

#include <math.h>
class Vec2
{
public:
  int _x;
  int _y;

public:
  Vec2();
  Vec2(int x, int y);
  Vec2(Vec2 const &copy);
  Vec2 &operator=(Vec2 const &target);
  virtual ~Vec2();

  bool operator==(const Vec2 &rhs) const;

  bool operator!=(const Vec2 &rhs) const;
  Vec2 operator+(Vec2 const &);
  Vec2 operator-(Vec2 const &);
  Vec2 operator*(float b);

  Vec2 clampEdge(Vec2 edgeMin, Vec2 edgeMax);
  bool outOfEdge(Vec2 edgeMin, Vec2 edgeMax) const;
  int getX() const;
  bool checkRadius(Vec2, int);
  void setX(int x);

  int getY() const;

  void setY(int y);
};

#endif //RUSH00_VEC2_HPP
