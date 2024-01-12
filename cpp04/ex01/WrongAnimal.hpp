/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: WrongAnimal.hpp                                                */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:30:47                                            */
/*   Updated:  2023/12/19 15:37:04                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		~WrongAnimal(void);

		void		makeSound(void) const;
		std::string getType(void) const;
};
