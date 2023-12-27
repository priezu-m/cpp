/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ShrubberyCreationForm.cpp                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/26 17:03:04                                            */
/*   Updated:  2023/12/27 12:02:00                                            */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <ios>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shruberry creation", 145, 137), target("default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target_arg)
	: AForm("shruberry creation", 145, 37), target(target_arg)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shruberryCreationForm)
	: AForm(shruberryCreationForm), target(shruberryCreationForm.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shruberryCreationForm)
{
	AForm::is_signed = shruberryCreationForm.is_signed;
	AForm::is_executed = shruberryCreationForm.is_executed;
	target = shruberryCreationForm.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

static bool execute_internal(std::string const &target)
{
	std::ofstream target_file(target.c_str());
	char		  ascii_trees[] =
		"           `-._\\/  .  \\ /    |/_\n               \\  _\\, y | \\//\n         _\\_.___\\, "
		"\\/ "
		"-.\\||\n           `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'\n                     |    |//\n    "
		" "
		"                |_    /\n                     |-   |\n                     |   =|\n                     |    "
		"|\n--------------------/ ,  . \\--------._\n";

	if (target_file.fail() == true)
	{
		std::cout << "system failure while opening the " << target << " file\n";
		return (false);
	}
	target_file.write(ascii_trees, sizeof(ascii_trees));
	if (target_file.fail() == true)
	{
		std::cout << "system failure while writing to the " << target << " file\n";
		return (false);
	}
	return (true);
}

bool ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat)
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
	is_executed = execute_internal(target + "_shrubbery");
	return (is_executed);
}

#pragma GCC diagnostic pop
