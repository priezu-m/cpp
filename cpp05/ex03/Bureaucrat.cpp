/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Bureaucrat.cpp                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/20 14:20:14                                            */
/*   Updated:  2023/12/26 17:41:06                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Bureaucrat::Bureaucrat(void) : grade(lowest_grade), name("default bureaucrat")
{
}

Bureaucrat::Bureaucrat(std::string const &name_arg) : grade(lowest_grade), name(name_arg)
{
}

Bureaucrat::Bureaucrat(std::string const &name_arg, unsigned int grade_arg) : grade(grade_arg), name(name_arg)
{
	if (grade_arg < highest_grade)
	{
		throw(GradeTooHighException("could not construct bureaucrat"));
	}
	if (grade_arg > lowest_grade)
	{
		throw(GradeTooLowException("could not construct bureaucrat"));
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &arg) : grade(arg.grade), name(arg.name)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

bool Bureaucrat::singForm(AForm *form) const
{
	return (form->beSigned(*this));
}

bool Bureaucrat::executeForm(AForm *form) const
{
	bool const ret = form->execute(*this);

	if (ret == true)
	{
		std::cout << name << " executed " << form->getName() << '\n';
	}
	return (ret);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (grade);
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

unsigned int Bureaucrat::increaseGrade(void)
{
	grade--;
	if (grade < highest_grade)
	{
		throw(GradeTooHighException("could not increase bureaucrat's grade"));
	}
	return (grade);
}

unsigned int Bureaucrat::decreaseGrade(void)
{
	grade++;
	if (grade > lowest_grade)
	{
		throw(GradeTooLowException("could not decrease bureaucrat's grade"));
	}
	return (grade);
}

std::ostream &operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return (ostream);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(char const *const message) : runtime_error(message)
{
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade was higher than highest grade");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(char const *const message) : runtime_error(message)
{
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade was lower than lowest grade");
}

#pragma GCC diagnostic pop
