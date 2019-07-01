#ifndef STAR_HPP
#define STAR_HPP

#include <iostream>
#include <ncurses.h>
#include "Vec2.hpp"
#include "AGameObject.hpp"

class Star : public AGameObject
{
private:
public:
  Star(int, int);
	Star(Star const &copy);
  ~Star();
};

#endif