/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/20 14:19:54                                            */
/*   Updated:  2023/12/27 14:32:13                                            */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
	Bureaucrat			   b1("powerfull bureaucrat", 1);
	Bureaucrat			   b2("powerless bureaucrat", 25);
	PresidentialPardonForm f1("target_robot");
	PresidentialPardonForm f2(f1);
	Intern				   i1;

	delete i1.makeForm("presidential pardon", "target");
	f1 = f2;
	b1.singForm(&f1);
	b1.executeForm(&f1);
	b1.executeForm(&f1);
	b1.singForm(&f1);
	b2.singForm(&f2);
	b2.executeForm(&f2);
}

#pragma GCC diagnostic pop
