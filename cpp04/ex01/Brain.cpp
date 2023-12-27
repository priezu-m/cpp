/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Brain.cpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 19:44:16                                            */
/*   Updated:  2023/12/19 20:10:04                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Brain::Brain(void)
{
	std::cout << "Brain constructed\n";
}

Brain::Brain(Brain const &arg)
{
	for (unsigned i = 0; i < sizeof(ideas) / sizeof(ideas[0]); i++)
	{
		ideas[0] = arg.ideas[0];
	}
	std::cout << "Brain copy constructed\n";
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed\n";
}

Brain const &Brain::operator=(Brain const &arg)
{
	if (this == &arg)
	{
		return (*this);
	}
	for (unsigned i = 0; i < sizeof(ideas) / sizeof(ideas[0]); i++)
	{
		ideas[0] = arg.ideas[0];
	}
	std::cout << "Brain assigned\n";
	return (*this);
}

#pragma GCC diagnostic pop
