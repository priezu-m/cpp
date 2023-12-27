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

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &arg);
		~Cat(void);
		Cat operator=(const Cat &arg);

		void makeSound(void) const;
};

#pragma GCC diagnostic pop
