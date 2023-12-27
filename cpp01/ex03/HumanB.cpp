/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: HumanB.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 01:35:52                                            */
/*   Updated:  2023/12/04 02:04:25                                            */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma GCC diagnostic ignored "-Wglobal-constructors"
#pragma GCC diagnostic ignored "-Wexit-time-destructors"
;

static Weapon default_weapon("");

HumanB::HumanB(std::string const &arg_name) : name(arg_name), weapon(&default_weapon)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

#pragma GCC diagnostic pop
