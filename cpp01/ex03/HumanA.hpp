/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: HumanA.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 14:02:54                                            */
/*   Updated:  2023/12/04 01:37:30                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class HumanA
{
	private:
		std::string name;
		Weapon	   &weapon;

	public:
		explicit HumanA(std::string const &arg_name, Weapon &arg_weapon);
		~HumanA(void);

		void attack(void) const;
};

#pragma GCC diagnostic pop
