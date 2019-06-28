#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

class FragTrap
{
private:
	int			_hp;
	int			_max_hp;
	int			_ep;
	int			_max_ep;
	int			_lvl;
	std::string	_name;
	int			_melee_ad;
	int			_range_ad;
	int			_armor_dr;

public:
	FragTrap( std::string name );
	FragTrap( FragTrap const & copy);
	FragTrap &operator=(FragTrap const &rhs);
	~FragTrap();

	int			rangedAttack(std::string const & target);
	int			meleeAttack(std::string const & target);
	int			takeDamage(unsigned int amount);
	int			beRepaired(unsigned int amount);
	int			vaulthunter_dot_exe(std::string const & target);

	int			getHp( void ) const;
	int			getMaxHp( void ) const;
	int			getEp( void ) const;
	int			getMaxEp( void ) const;
	int			getLvl( void ) const;
	std::string	getName( void ) const;
	int			getMeleeAd( void ) const;
	int			getRangeAd( void ) const;
	int			getArmor_dr( void ) const;
	void		setHp( int x );
	void		setMaxHp( int x );
	void		setEp( int x);
	void		setMaxEp( int x );
	void		setLvl( int x);
	void		setName( std::string name);
	void		setMeleeAd( int x);
	void		setRangeAd( int x);
	void		setArmorDr( int x);
 };

#endif //CPP_POOL_FRAGTRAP_HPP
