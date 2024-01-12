/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ClapTrap.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/17 23:52:22                                            */
/*   Updated:  2023/12/18 01:02:21                                            */
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

	protected:
		std::string get_name(void) const;
		unsigned	get_hit_points(void) const;
		unsigned	get_energy_points(void) const;
		unsigned	get_attack_damage(void) const;

		void		set_name(std::string const &arg_name);
		void		set_hit_points(unsigned int arg_hit_points);
		void		set_energy_points(unsigned int arg_energy_points);
		void		set_attack_damage(unsigned int arg_attack_damage);

	public:
		ClapTrap(void);
		explicit ClapTrap(std::string const &arg_name);
		ClapTrap(std::string const &arg_name, unsigned int arg_hit_points, unsigned int arg_energy_points,
				 unsigned arg_attack_damage);
		ClapTrap(ClapTrap &arg);
		~ClapTrap(void);
		ClapTrap operator=(ClapTrap const &arg);

		void	 attack(std::string const &target);
		void	 takeDamage(unsigned int ammout);
		void	 beRepaired(unsigned int ammout);
};
