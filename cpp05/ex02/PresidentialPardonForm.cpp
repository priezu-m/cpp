/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: PresidentialPardonForm.cpp                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/26 16:12:20                                            */
/*   Updated:  2023/12/27 12:01:32                                            */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5), target("default target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target_arg)
	: AForm("presidential pardon", 25, 5), target(target_arg)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm)
	: AForm(presidentialPardonForm), target(presidentialPardonForm.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	AForm::is_signed = presidentialPardonForm.is_signed;
	AForm::is_executed = presidentialPardonForm.is_executed;
	target = presidentialPardonForm.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

bool PresidentialPardonForm::execute(Bureaucrat const &bureaucrat)
{
	if (is_signed == false)
	{
		std::cout << "Could not execute " << name << " is not singned\n";
		return (false);
	}
	if (is_executed == true)
	{
		std::cout << name << " was already executed\n";
		return (false);
	}
	if (bureaucrat.getGrade() > grade_to_execute)
	{
		std::cout << bureaucrat.getName() << "'s grade was too low to execute form " << name << '\n';
		return (false);
	}
	is_executed = true;
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
	return (true);
}

#pragma GCC diagnostic pop
