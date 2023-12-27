/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ScavTrap.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/18 00:28:19                                            */
/*   Updated:  2023/12/18 00:57:51                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap(void);
		explicit ScavTrap(std::string const &arg_name);
		ScavTrap(ScavTrap const &arg);
		~ScavTrap(void);
		ScavTrap operator=(ScavTrap const &arg);

		void	 guardGate(void);
};

#pragma GCC diagnostic pop
