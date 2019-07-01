#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Mouse.hpp"

int main()
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Mouse		mo("Mikky");


	std::cout << robert << jim << joe << mo;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(mo);
	return 0;
}