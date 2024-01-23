/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 13:04:27                                            */
/*   Updated:  2024/01/23 07:54:17                                            */
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

int main(void)
{
	int const n = 10;
	Zombie	 *zombie_horde = Zombie::zombieHorde(n, "horde member");

	for (int i = 0; i < n; i++)
	{
		zombie_horde[i].anounce();
	}
	delete[] (zombie_horde);
}

#pragma GCC diagnostic pop
