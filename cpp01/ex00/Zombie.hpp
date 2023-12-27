/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: zombie.hpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 12:01:43                                            */
/*   Updated:  2023/11/30 13:13:32                                            */
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

class Zombie
{
	private:
		const std::string name;

	public:
		explicit Zombie(std::string const &arg_name);
		~Zombie();
		void		   anounce(void) const;
		static Zombie *newZombie(std::string const &name);
		static void	   randomChump(std::string const &name);
};

#pragma GCC diagnostic pop
