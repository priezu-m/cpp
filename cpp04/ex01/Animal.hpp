/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Animal.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:30:47                                            */
/*   Updated:  2023/12/19 19:06:05                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const &arg);
		Animal operator=(Animal const &arg);
		virtual ~Animal(void);

		virtual void makeSound(void) const;
		std::string	 getType(void) const;
};
