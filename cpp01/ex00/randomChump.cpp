/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: randomChump.cpp                                                */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/02 01:37:19                                            */
/*   Updated:  2023/12/02 01:37:41                                            */
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

void Zombie::randomChump(std::string const &name)
{
	const Zombie chump(name);

	chump.anounce();
}

#pragma GCC diagnostic pop
