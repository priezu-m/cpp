/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: zombieHorde.cpp                                                */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/02 01:39:15                                            */
/*   Updated:  2024/01/23 07:51:10                                            */
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
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
;

Zombie *Zombie::zombieHorde(int N, std::string const &name_in)
{
	Zombie *zombie_horde;

	if (N <= 0)
	{
		return (NULL);
	}
	zombie_horde = new Zombie[static_cast<unsigned>(N)]();
	if (zombie_horde == NULL)
	{
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].name = name_in;
	}
	return (zombie_horde);
}

#pragma GCC diagnostic pop
