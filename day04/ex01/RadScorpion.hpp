#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion( void );
	RadScorpion(RadScorpion const & copy);
	RadScorpion &operator=(RadScorpion const &target);
	virtual ~RadScorpion();
};


#endif //CPP_POOL_RADSCORPION_HPP
