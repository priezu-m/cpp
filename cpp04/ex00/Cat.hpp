/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Cat.hpp                                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:43:45                                            */
/*   Updated:  2023/12/19 18:08:04                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &arg);
		~Cat(void);
		Cat operator=(const Cat &arg);

		void makeSound(void) const;
};
