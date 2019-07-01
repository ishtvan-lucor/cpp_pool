#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Vec2.hpp"

#define D 100
#define S 115
#define A 97
#define W 119
#define SPACE 32
#define END 27

class Controller
{
  private:
    /* data */
  public:
    Controller();
    ~Controller();
    bool moveUp;
    bool moveDown;
    bool moveLeft;
    bool moveRight;
    bool attack;
    bool end;

    void setRight(void);
    void setLeft(void);
    void setUp(void);
    void setAttack(void);
    void setDown(void);
    void setEnd(void);

    void listen(char c);
    void refresh(void);
    Vec2 getVector(void);
};

#endif