/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Dog.cpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 11:02:48                                            */
/*   Updated:  2023/12/19 19:06:25                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Dog::Dog(const Dog &arg)
	: Animal(arg)
{
	std::cout << "dog copy constructor called\n";
}

Dog::Dog(void)
{
	Animal::type = "Dog";
	std::cout << "dog constructor called\n";
}

Dog::~Dog(void)
{
	std::cout << "dog destructor called\n";
}

void Dog::makeSound(void) const
{
	std::cout << "dog sounds\n";
}

Dog Dog::operator=(const Dog &arg)
{
	std::cout << "dog assingment operator called\n";
	type = arg.type;
	return (*this);
}

#pragma GCC diagnostic pop
