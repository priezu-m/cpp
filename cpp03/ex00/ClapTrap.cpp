/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ClapTrap.cpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/17 23:58:06                                            */
/*   Updated:  2023/12/18 15:55:06                                            */
/*                                                                            */
/* ************************************************************************** */

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

ClapTrap::ClapTrap(void) : name("default clap trap"), hit_points(10), energy_points(10), attack_damage(10)
{
	std::cout << name << " consturcted whit default constructor\n";
}

ClapTrap::ClapTrap(std::string const &arg_name) : name(arg_name), hit_points(10), energy_points(10), attack_damage(10)
{
	std::cout << name << " consturcted\n";
}

ClapTrap::ClapTrap(ClapTrap &arg)
	: name(arg.name), hit_points(arg.hit_points), energy_points(arg.energy_points), attack_damage(arg.attack_damage)
{
	std::cout << name << " consturcted, whit copy constructor\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << name << " destroyed\n";
}

ClapTrap ClapTrap::operator=(ClapTrap const &arg)
{
	name = arg.name;
	hit_points = arg.hit_points;
	energy_points = arg.energy_points;
	attack_damage = arg.attack_damage;
	std::cout << name << " copyed, whit assigment operation\n";
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is dead\n";
		return;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no remaining energy points\n";
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!\n";
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int ammout)
{
	if (hit_points == 0)
	{
		std::cout << "ClapTrap " << name << " is already dead\n";
	}
	std::cout << "ClapTrap " << name << " took " << ammout << " points of damage!\n";
	if (ammout > hit_points)
	{
		hit_points = 0;
	}
	else
	{
		hit_points -= ammout;
	}
	std::cout << hit_points << " hit points remaining\n";
}

void ClapTrap::beRepaired(unsigned int ammout)
{
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " has no remaining energy points\n";
		return;
	}
	std::cout << "ClapTrap " << name << " repaired " << ammout << " points of damage!\n";
	hit_points += ammout;
	energy_points--;
}

#pragma GCC diagnostic pop
