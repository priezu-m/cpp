/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/17 23:52:01                                            */
/*   Updated:  2023/12/18 00:21:35                                            */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(void)
{
	ClapTrap a("a");
	ClapTrap b(a);
	ClapTrap c;

	c = b;
	c.attack("not a");
	c.takeDamage(10);
	c.beRepaired(10);
}

#pragma GCC diagnostic pop
