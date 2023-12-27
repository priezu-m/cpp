/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Weapon.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 13:56:42                                            */
/*   Updated:  2023/12/04 02:01:07                                            */
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

class Weapon
{
	private:
		std::string type;

	public:
		explicit Weapon(std::string const &arg_type);
		~Weapon(void);

		std::string const &getType(void) const;
		std::string		   setType(std::string const &arg_type);
};

#pragma GCC diagnostic pop
