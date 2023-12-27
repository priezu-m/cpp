/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Weapon.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 01:57:21                                            */
/*   Updated:  2023/12/04 02:01:41                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Weapon::Weapon(std::string const &arg_type) : type(arg_type)
{
}

Weapon::~Weapon(void)
{
}

std::string const &Weapon::getType(void) const
{
	return (type);
}

std::string Weapon::setType(std::string const &arg_type)
{
	type = arg_type;
	return (type);
}

#pragma GCC diagnostic pop
