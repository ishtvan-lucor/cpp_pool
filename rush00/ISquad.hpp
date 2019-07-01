#ifndef WAR_ISQUAD_HPP
#define WAR_ISQUAD_HPP

#include "AGameObject.hpp"

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual AGameObject*	getGameObject(int) const = 0;
	virtual int				push(AGameObject*) = 0;
	//virtual int 			getCount(void) const;
};


#endif //WAR_ISQUAD_HPP
