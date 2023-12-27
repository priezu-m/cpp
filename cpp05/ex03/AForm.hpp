/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: AForm.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/22 16:51:35                                            */
/*   Updated:  2023/12/23 19:24:31                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Bureaucrat;

class AForm
{
	protected:
		static unsigned int const highest_grade = 1;
		static unsigned int const lowest_grade = 150;
		std::string				  name;
		bool					  is_signed;
		bool					  is_executed;
		unsigned int const		  grade_to_sing;
		unsigned int const		  grade_to_execute;

	public:
		AForm(void);
		explicit AForm(std::string const &name_arg);
		explicit AForm(std::string const &name_arg, unsigned int grade_to_sing_arg, unsigned int grade_to_execute_arg);
		AForm(AForm const &form);
		virtual ~AForm(void);

		bool		 beSigned(Bureaucrat const &bureaucrat);
		virtual bool execute(Bureaucrat const &bureaucrat) = 0;
		unsigned int getGrade_to_execute(void) const;
		unsigned int getGrade_to_sing(void) const;
		bool		 getIs_signed(void) const;
		bool		 getIs_executed(void) const;
		std::string	 getName(void) const;

		class GradeTooHighException : public std::runtime_error
		{
			public:
				explicit GradeTooHighException(char const *const message);
				virtual char const *what() const throw();
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				explicit GradeTooLowException(char const *const message);
				virtual char const *what() const throw();
		};
};

std::ostream		  &operator<<(std::ostream &ostream, AForm const &form);

#pragma GCC diagnostic pop
