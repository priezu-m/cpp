/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: WrongCat.cpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:58:19                                            */
/*   Updated:  2023/12/19 15:38:41                                            */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

WrongCat::WrongCat(void)
{
	WrongAnimal::type = "WrongCat";
	std::cout << "wrong cat constructor called\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "wrong cat destructor called\n";
}

void WrongCat::makeSound(void) const
{
	std::cout << "wrong cat sounds\n";
}

#pragma GCC diagnostic pop
