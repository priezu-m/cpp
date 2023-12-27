/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Form.hpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/22 16:51:35                                            */
/*   Updated:  2023/12/27 14:48:02                                            */
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

class Form
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
		Form(void);
		explicit Form(std::string const &name_arg);
		explicit Form(std::string const &name_arg, unsigned int grade_to_sing_arg, unsigned int grade_to_execute_arg);
		Form(Form const &form);
		virtual ~Form(void);

		bool		 beSigned(Bureaucrat const &bureaucrat);
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

std::ostream		  &operator<<(std::ostream &ostream, Form const &form);

#pragma GCC diagnostic pop
