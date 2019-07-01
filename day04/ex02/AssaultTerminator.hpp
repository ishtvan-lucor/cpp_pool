#ifndef WAR_ASSAULTTERMINATOR_HPP
#define WAR_ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &copy);
	virtual ~AssaultTerminator();

	ISpaceMarine	*clone() const;
	void			battleCry() const;
	void			rangedAttack() const;
	void			meleeAttack() const;
};


#endif //WAR_ASSAULTTERMINATOR_HPP
