/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Cat.cpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:58:19                                            */
/*   Updated:  2023/12/19 19:06:22                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
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

Cat::Cat(void)
{
	Animal::type = "Cat";
	std::cout << "cat constructor called\n";
}

Cat::Cat(const Cat &arg)
	: Animal(arg)
{
	std::cout << "cat copy constructor called\n";
}

Cat::~Cat(void)
{
	std::cout << "cat destructor called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "cat sounds\n";
}

Cat Cat::operator=(const Cat &arg)
{
	std::cout << "cat assingment operator called\n";
	type = arg.type;
	return (*this);
}

#pragma GCC diagnostic pop
