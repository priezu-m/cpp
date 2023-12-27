/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Intern.cpp                                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/26 21:34:48                                            */
/*   Updated:  2023/12/27 13:09:09                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

AForm *Intern::makeForm(std::string const &form_name, std::string const &target)
{
	if (form_name == "presidential pardon" || form_name == "shruberry creation" || form_name == "robotomy request")
	{
		std::cout << "inter creates " << form_name << " form\n";
		switch (form_name[0])
		{
			case 'p':
			{
				return (new PresidentialPardonForm(target));
			}
			case 's':
			{
				return (new ShrubberyCreationForm(target));
			}
			case 'r':
			{
				return (new RobotomyRequestForm(target));
			}
		}
	}
	std::cout << "Ineter could not crete a " << form_name << " form, due to not knowing it\n";
	return (NULL);
}

#pragma GCC diagnostic pop
