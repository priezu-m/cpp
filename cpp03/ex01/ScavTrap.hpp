/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ScavTrap.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/18 00:28:19                                            */
/*   Updated:  2024/01/28 13:35:24                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap(void);
		explicit ScavTrap(std::string const &arg_name);
		ScavTrap(ScavTrap const &arg);
		~ScavTrap(void);
		ScavTrap operator=(ScavTrap const &arg);

		void	 attack(const std::string &target);
		void	 guardGate(void);
};
