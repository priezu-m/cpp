/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Zombie.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 12:05:30                                            */
/*   Updated:  2023/12/02 01:38:06                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Zombie::Zombie(std::string const &arg_name) : name(arg_name)
{
}

void Zombie::anounce(void) const
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
	std::cout << name << " was destroyed\n";
}

#pragma GCC diagnostic pop
