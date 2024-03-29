/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ClapTrap.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/17 23:52:22                                            */
/*   Updated:  2023/12/18 00:17:20                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap
{
	private:
		std::string	 name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		ClapTrap(void);
		explicit ClapTrap(std::string const &arg_name);
		ClapTrap(ClapTrap &arg);
		~ClapTrap(void);
		ClapTrap operator=(ClapTrap const &arg);

		void	 attack(std::string const &target);
		void	 takeDamage(unsigned int ammout);
		void	 beRepaired(unsigned int ammout);
};
