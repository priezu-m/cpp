/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Animal.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:40:55                                            */
/*   Updated:  2023/12/19 19:06:16                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Animal::Animal(const Animal &arg)
	: type(arg.type)
{
	std::cout << "animal copy constructor called\n";
}

Animal::Animal(void) : type("arquetypical animal")
{
	std::cout << "animal constructor called\n";
}

Animal::~Animal(void)
{
	std::cout << "animal destructor called\n";
}

void Animal::makeSound(void) const
{
	std::cout << "arquetypical animal sounds\n";
}

std::string Animal::getType(void) const
{
	return (type);
}

Animal Animal::operator=(const Animal &arg)
{
	std::cout << "animal assingment operator called\n";
	type = arg.type;
	return (*this);
}

#pragma GCC diagnostic pop
