/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: HumanA.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 01:31:16                                            */
/*   Updated:  2023/12/04 01:35:40                                            */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

HumanA::HumanA(std::string const &arg_name, Weapon &arg_weapon) : name(arg_name), weapon(arg_weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}

#pragma GCC diagnostic pop
