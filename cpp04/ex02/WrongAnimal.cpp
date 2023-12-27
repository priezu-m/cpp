/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: WrongAnimal.cpp                                                */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:40:55                                            */
/*   Updated:  2023/12/19 15:22:29                                            */
/*                                                                            */
/* ************************************************************************** */

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

WrongAnimal::WrongAnimal(void) : type("arquetypical wrong animal")
{
	std::cout << "wrong animal constructor called\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "wrong animal destructor called\n";
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "arquetypical wrong animal sounds\n";
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}

#pragma GCC diagnostic pop
