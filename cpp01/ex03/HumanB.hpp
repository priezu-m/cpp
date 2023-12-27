/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: HumanB.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 01:24:16                                            */
/*   Updated:  2023/12/04 02:04:09                                            */
/*                                                                            */
/* ************************************************************************** */

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

class HumanB
{
	private:
		std::string name;
		Weapon	   *weapon;

	public:
		explicit HumanB(std::string const &arg_name);
		~HumanB(void);
		void setWeapon(Weapon &new_weapon);
		void attack(void) const;
};

#pragma GCC diagnostic pop
