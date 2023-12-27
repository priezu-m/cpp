/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Brain.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 19:40:19                                            */
/*   Updated:  2023/12/19 19:43:45                                            */
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

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(Brain const &arg);
		Brain const &operator=(Brain const &arg);
		~Brain(void);
};

#pragma GCC diagnostic pop
