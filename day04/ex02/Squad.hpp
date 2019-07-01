#ifndef WAR_SQUAD_HPP
#define WAR_SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
private:
	int				_amount;
	ISpaceMarine	**_unit;

public:
	Squad();
	Squad(Squad const & copy);
	Squad &operator=(Squad const &target);
	virtual ~Squad();

	int				getCount() const;
	ISpaceMarine	*getUnit(int i) const;
	int				push(ISpaceMarine *marine);
};


#endif //WAR_SQUAD_HPP
