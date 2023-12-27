/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Animal.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:30:47                                            */
/*   Updated:  2023/12/19 20:14:50                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Animal
{
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(Animal const &arg);
		virtual ~Animal(void);

		virtual void makeSound(void) const = 0;
		std::string	 getType(void) const;
};

#pragma GCC diagnostic pop
