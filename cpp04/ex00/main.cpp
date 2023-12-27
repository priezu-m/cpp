/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:30:22                                            */
/*   Updated:  2023/12/19 19:02:34                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

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
	Dog	dog1;
	Dog dog2(dog1);
	Animal	dog_that_does_not_bark;
	Animal	a2(dog_that_does_not_bark);

	dog_that_does_not_bark.makeSound();

	{
		Animal const	  *meta = new Animal();
		Animal const	  *j = new Dog();
		WrongAnimal const *i = new WrongCat();
		WrongCat const	  *ii = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();				  // will output the cat sound!
		ii->makeSound();			  // will output the cat sound!
		ii->WrongAnimal::makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		delete ii;
	}
}

#pragma GCC diagnostic pop
