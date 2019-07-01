#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character*	zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy*		b = new RadScorpion();
	Enemy*		c = new SuperMutant();
	AWeapon*	pr = new PlasmaRifle();
	AWeapon*	pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	std::cout << std::endl;

	zaz->recoverAP();
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(c);
	zaz->attack(c);
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(c);
	zaz->attack(c);

	return 0;
}