/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: RobotomyRequestForm.cpp                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/23 16:04:25                                            */
/*   Updated:  2023/12/27 12:01:51                                            */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45), target("default target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target_arg)
	: AForm("robotomy request", 72, 45), target(target_arg)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm)
	: AForm(robotomyRequestForm), target(robotomyRequestForm.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	AForm::is_signed = robotomyRequestForm.is_signed;
	AForm::is_executed = robotomyRequestForm.is_executed;
	target = robotomyRequestForm.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

bool RobotomyRequestForm::execute(Bureaucrat const &bureaucrat)
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
	std::cout << "drilling noises " << target;
	std::srand(static_cast<unsigned int>(time(NULL)));
	// NOLINTNEXTLINE (rand is not thread safe)
	if (std::rand() % 2 == 0)
	{
		std::cout << " was robotomized\n";
	}
	else
	{
		std::cout << " robotomization failed\n";
	}
	return (true);
}

#pragma GCC diagnostic pop
