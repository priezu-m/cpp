/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: newZombie.cpp                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/02 01:34:00                                            */
/*   Updated:  2023/12/02 01:38:03                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Zombie *Zombie::newZombie(std::string const &name)
{
	return (new Zombie(name));
}

#pragma GCC diagnostic pop
