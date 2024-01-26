/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/20 14:19:54                                            */
/*   Updated:  2023/12/27 14:29:43                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main()
{
	try
	{
		Bureaucrat b1("powerfull bureaucrat", 1);
		std::cout << b1 << '\n';
		b1.increaseGrade();
	}
	catch (const std::exception &)
	{
	}
	try
	{
		Bureaucrat b2("powerless bureaucrat", 150);
		b2.decreaseGrade();
	}
	catch (const std::exception &)
	{
	}
	Bureaucrat b2("imposibly powerless bureaucrat", 151);
}

#pragma GCC diagnostic pop
