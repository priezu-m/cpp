/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: FragTrap.cpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/18 15:30:08                                            */
/*   Updated:  2023/12/18 15:38:15                                            */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

FragTrap::FragTrap(void) : ClapTrap("default frag trap", 100, 100, 30)
{
	std::cout << get_name() << " consturcted whit frag trap default constructor\n";
}

FragTrap::FragTrap(std::string const &arg_name) : ClapTrap(arg_name, 100, 100, 30)
{
	std::cout << get_name() << " consturcted whit frag trap constructor\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << get_name() << " frag trap destroyed\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << get_name() << " please high five whit me\n";
}

FragTrap::FragTrap(FragTrap const &arg)
	: ClapTrap(arg.get_name(), arg.get_hit_points(), arg.get_energy_points(), arg.get_attack_damage())
{
	std::cout << get_name() << " consturcted whit frag trap copy constructor\n";
}

FragTrap FragTrap::operator=(FragTrap const &arg)
{
	set_attack_damage(arg.get_attack_damage());
	set_hit_points(arg.get_hit_points());
	set_name(arg.get_name());
	set_energy_points(arg.get_energy_points());
	std::cout << get_name() << " copyed whit assigment operation\n";
	return (*this);
}

#pragma GCC diagnostic pop
