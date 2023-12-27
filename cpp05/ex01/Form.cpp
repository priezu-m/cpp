/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Form.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/22 17:22:43                                            */
/*   Updated:  2023/12/27 14:39:43                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Form::Form(void)
	: name("default form name"), is_signed(false), is_executed(false), grade_to_sing(lowest_grade),
	  grade_to_execute(lowest_grade)
{
}

Form::Form(std::string const &name_arg)
	: name(name_arg), is_signed(false), is_executed(false), grade_to_sing(lowest_grade), grade_to_execute(lowest_grade)
{
}

Form::Form(std::string const &name_arg, unsigned int grade_to_sing_arg, unsigned int grade_to_execute_arg)
	: name(name_arg), is_signed(false), is_executed(false), grade_to_sing(grade_to_sing_arg),
	  grade_to_execute(grade_to_execute_arg)
{
	if (grade_to_execute_arg > lowest_grade || grade_to_sing_arg > lowest_grade)
	{
		throw(GradeTooLowException("form could not be constructed"));
	}
	if (grade_to_execute_arg < highest_grade || grade_to_sing_arg < highest_grade)
	{
		throw(GradeTooHighException("form could not be constructed"));
	}
}

Form::Form(Form const &form)
	: name(form.name), is_signed(form.is_signed), is_executed(form.is_executed), grade_to_sing(form.grade_to_sing),
	  grade_to_execute(form.grade_to_execute)
{
}

Form::~Form(void)
{
}

bool Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (is_signed == true)
	{
		std::cout << name << " form was already singned\n";
		return (true);
	}
	if (grade_to_sing >= bureaucrat.getGrade())
	{
		std::cout << bureaucrat.name << " singned " << name << " form\n";
		is_signed = true;
		return (true);
	}
	std::cout << bureaucrat.name << "couldn't singn " << name << " form because his grade was not high enough\n";
	return (false);
}

unsigned int Form::getGrade_to_execute(void) const
{
	return (grade_to_execute);
}

unsigned int Form::getGrade_to_sing(void) const
{
	return (grade_to_sing);
}

bool Form::getIs_signed(void) const
{
	return (is_signed);
}

bool Form::getIs_executed(void) const
{
	return (is_executed);
}

std::string Form::getName(void) const
{
	return (name);
}

Form::GradeTooHighException::GradeTooHighException(char const *const message) : runtime_error(message)
{
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("grade was higher than highest grade");
}

Form::GradeTooLowException::GradeTooLowException(char const *const message) : runtime_error(message)
{
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("grade was lower than lowest grade");
}

std::ostream &operator<<(std::ostream &ostream, Form const &form)
{
	ostream << form.getName() << " grade needed to singn form " << form.getGrade_to_sing()
			<< " grade needed to execute " << form.getGrade_to_execute() << "<\n";
	return (ostream);
}

#pragma GCC diagnostic pop
