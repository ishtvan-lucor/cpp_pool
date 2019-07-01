#include "Squad.hpp"

Squad::Squad() : _amount(0), _unit(NULL)
{
}

Squad::Squad(Squad const &copy)
{
	*this = copy;
}

Squad& Squad::operator=(Squad const &target)
{
	for (int i = 0; i < this->_amount; i++)
		delete this->_unit[i];
	delete _unit;

	this->_amount = target.getCount();
	this->_unit = new ISpaceMarine*[this->_amount];
	for (int i = 0; i < this->_amount; i++)
		this->push(target.getUnit(i));

	return (*this);
}

Squad::~Squad()
{
	for (int i = 0; i < this->_amount; i++)
		delete (this->_unit[i]);
	delete this->_unit;
}

int Squad::getCount() const
{
	return this->_amount;
}

ISpaceMarine *Squad::getUnit(int i) const
{
	if ( i < 0 || i >this->_amount)
		return (NULL);
	return (this->_unit[i]);
}

int Squad::push(ISpaceMarine *marine)
{
	if (!marine)
		return(this->_amount);
	for (int i = 0; i < this->_amount; i++)
	{
		if (this->_unit[i] == marine)
			return (this->_amount);
	}
	if (this->_amount <= 0)
	{
		this->_unit = new ISpaceMarine*[1];
		this->_unit[0] = marine;
	}
	else
	{
		ISpaceMarine	**newSquad;
		int					count = 0;

		newSquad = new ISpaceMarine*[this->_amount + 1];
		while (count < this->_amount)
		{
			newSquad[count] = this->_unit[count];
			count++;
		}
		newSquad[count] = marine;
		delete this->_unit;
		this->_unit = newSquad;
	}
	this->_amount++;
	return (this->_amount);
}

