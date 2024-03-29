/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: FragTrap.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/18 14:57:46                                            */
/*   Updated:  2023/12/18 15:30:02                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		FragTrap(void);
		explicit FragTrap(std::string const &arg_name);
		FragTrap(FragTrap const &arg);
		~FragTrap(void);
		FragTrap operator=(FragTrap const &arg);

		void	 highFivesGuys(void);
};
