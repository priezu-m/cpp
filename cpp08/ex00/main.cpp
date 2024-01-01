/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/28 14:16:07                                            */
/*   Updated:  2023/12/30 15:45:21                                            */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(void)
{
	std::vector<int>		   v;
	std::vector<int>::iterator it;

	v.push_back(1);
	v.push_back(1100);
	v.push_back(3);
	v.push_back(3);

	it = easyfind(v, 3);
	if ((v.begin() + 2) == it)
	{
		std::cout << "success\n";
	}
	else
	{
		std::cout << "failure\n";
	}
	return (0);
}

#pragma GCC diagnostic pop
