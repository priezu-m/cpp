/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 13:04:27                                            */
/*   Updated:  2023/12/02 01:36:55                                            */
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
	Zombie *heap_zombie = Zombie::newZombie(std::string("heap_zombie"));
	Zombie	stack_zombie(std::string("stack_zombie"));

	heap_zombie->anounce();
	stack_zombie.anounce();
	Zombie::randomChump("randomChump");
	delete (heap_zombie);
}

#pragma GCC diagnostic pop
