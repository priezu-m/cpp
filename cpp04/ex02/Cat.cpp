/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Cat.cpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:58:19                                            */
/*   Updated:  2023/12/21 23:57:28                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <new>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
;

Cat::Cat(void) : brain(new Brain)
{
	Animal::type = "Cat";
	std::cout << "cat constructor called\n";
}

Cat::Cat(Cat const &arg) : Animal(arg), brain(new Brain(*arg.brain))
{
	std::cout << "cat copy constructor called\n";
}

Cat::~Cat(void)
{
	std::cout << "cat destructor called\n";
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "cat sounds\n";
}

Cat Cat::operator=(Cat const &arg)
{
	std::cout << "cat assingment operator called\n";
	type = arg.type;
	*brain = *arg.brain;
	return (*this);
}

#pragma GCC diagnostic pop
