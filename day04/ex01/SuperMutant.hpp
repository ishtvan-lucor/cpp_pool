#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant( void );
	SuperMutant(SuperMutant const & copy);
	SuperMutant &operator=(SuperMutant const &target);
	virtual ~SuperMutant();

	virtual void	takeDamage(int damage);
};


#endif //CPP_POOL_SUPERMUTANT_HPP
