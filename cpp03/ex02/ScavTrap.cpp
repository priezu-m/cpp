/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ScavTrap.cpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/18 00:31:07                                            */
/*   Updated:  2024/01/28 13:37:49                                            */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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

ScavTrap::ScavTrap(void) : ClapTrap("default scav trap", 100, 50, 20)
{
	std::cout << get_name() << " consturcted whit scav trap default constructor\n";
}

ScavTrap::ScavTrap(std::string const &arg_name) : ClapTrap(arg_name, 100, 50, 20)
{
	std::cout << get_name() << " consturcted whit scav trap constructor\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << get_name() << " destroyed\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << get_name() << " is now in gate guarding mode\n";
}

ScavTrap::ScavTrap(ScavTrap const &arg)
	: ClapTrap(arg.get_name(), arg.get_hit_points(), arg.get_energy_points(), arg.get_attack_damage())
{
	std::cout << get_name() << " consturcted whit scav trap copy constructor\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (get_hit_points() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " is dead\n";
		return;
	}
	if (get_energy_points() == 0)
	{
		std::cout << "ScavTrap " << get_name() << " has no remaining energy points\n";
		return;
	}
	std::cout << "ScavTrap " << get_name() << " attacks " << target << " causing " << get_attack_damage() << " points of damage!\n";
	set_energy_points(get_energy_points() - 1);
}

ScavTrap ScavTrap::operator=(ScavTrap const &arg)
{
	set_attack_damage(arg.get_attack_damage());
	set_hit_points(arg.get_hit_points());
	set_name(arg.get_name());
	set_energy_points(arg.get_energy_points());
	std::cout << get_name() << " copyed whit assigment operation\n";
	return (*this);
}

#pragma GCC diagnostic pop
