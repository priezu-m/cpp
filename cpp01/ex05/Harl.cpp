/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Harl.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 17:01:07                                            */
/*   Updated:  2023/12/04 18:23:01                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Harl::fun_ptr Harl::fun_table[8] = {error, error, error, error, info, debug, error, warning};

void		  Harl::debug(void)
{
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put\n"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\n"
				 "years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string const &level)
{
	if (level == "INFO" || level == "DEBUG" || level == "WARNING")
	{
		fun_table[level.size()]();
		return;
	}
	fun_table[0]();
}

#pragma GCC diagnostic pop
