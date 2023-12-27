/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Harl.hpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 16:37:43                                            */
/*   Updated:  2023/12/04 18:21:57                                            */
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

class Harl
{
	private:
		typedef void (*fun_ptr)(void);
		static fun_ptr fun_table[8];

		static void	   debug(void);
		static void	   info(void);
		static void	   warning(void);
		static void	   error(void);

	public:
		static void complain(std::string const &level);
};

#pragma GCC diagnostic pop
