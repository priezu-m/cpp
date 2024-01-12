/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Dog.hpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 11:02:56                                            */
/*   Updated:  2023/12/19 19:50:33                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog(void);
		Dog(Dog const &arg);
		~Dog(void);
		Dog	 operator=(Dog const &arg);

		void makeSound(void) const;
};
