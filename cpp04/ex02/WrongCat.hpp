/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: WrongCat.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:43:45                                            */
/*   Updated:  2023/12/19 15:38:08                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "WrongAnimal.hpp"

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

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat(void);

		void makeSound(void) const;
};

#pragma GCC diagnostic pop
