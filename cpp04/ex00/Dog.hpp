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

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &arg);
		~Dog(void);
		Dog operator=(const Dog &arg);

		void makeSound(void) const;
};

