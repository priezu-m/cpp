/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/20 14:19:54                                            */
/*   Updated:  2023/12/27 14:48:06                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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
	Bureaucrat	 b1("powerfull bureaucrat", 1);
	Bureaucrat	 b2("powerless bureaucrat", 25);
	Form		 f1("tax form", 10);
	Form		 f2("tax form", 10);

	std::cout << f1 << '\n';
	b1.singForm(&f1);
	b2.singForm(&f1);
	b2.singForm(&f2);
}

#pragma GCC diagnostic pop
