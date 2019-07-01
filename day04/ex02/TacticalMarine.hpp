#ifndef WAR_TACTICALMARINE_HPP
#define WAR_TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const& copy);
	virtual ~TacticalMarine();

	ISpaceMarine	*clone() const;
	void			battleCry() const;
	void			rangedAttack() const;
	void			meleeAttack() const;
};


#endif //WAR_TACTICALMARINE_HPP
