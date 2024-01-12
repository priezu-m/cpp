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
