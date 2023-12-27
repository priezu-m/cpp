/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Dog.hpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 11:02:56                                            */
/*   Updated:  2023/12/19 18:10:42                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma GCC diagnostic ignored "-Wsuggest-destructor-override"
#pragma GCC diagnostic ignored "-Wsuggest-override"
;

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &arg);
		~Dog(void);
		Dog operator=(const Dog &arg);

		void makeSound(void) const;
};

#pragma GCC diagnostic pop
