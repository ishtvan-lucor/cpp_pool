#include "Star.hpp"

Star::Star(int x, int y)
{
    Vec2 v(x, y);
    this->_type = "༓";
    this->_pos = v;
}

Star::Star(Star const &copy)
{
	*this = copy;
}


Star::~Star()
{
}
