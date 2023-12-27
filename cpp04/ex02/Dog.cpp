/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Dog.cpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 11:02:48                                            */
/*   Updated:  2023/12/21 23:57:31                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Dog::Dog(Dog const &arg) : Animal(arg), brain(new Brain(*arg.brain))
{
	std::cout << "dog copy constructor called\n";
}

Dog::Dog(void) : brain(new Brain)
{
	Animal::type = "Dog";
	std::cout << "dog constructor called\n";
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "dog destructor called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "dog sounds\n";
}

Dog Dog::operator=(Dog const &arg)
{
	std::cout << "dog assingment operator called\n";
	type = arg.type;
	*brain = *arg.brain;
	return (*this);
}

#pragma GCC diagnostic pop
