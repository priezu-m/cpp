/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Bureaucrat.hpp                                                 */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/20 14:20:05                                            */
/*   Updated:  2023/12/23 16:55:38                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat
{
	private:
		static unsigned int const highest_grade = 1;
		static unsigned int const lowest_grade = 150;
		unsigned int			  grade;

	public:
		const std::string name;

		Bureaucrat(void);
		explicit Bureaucrat(std::string const &name_arg);
		explicit Bureaucrat(std::string const &name_arg, unsigned int grade_arg);
		Bureaucrat(Bureaucrat const &arg);
		~Bureaucrat(void);

		bool		 singForm(AForm *form) const;
		bool		 executeForm(AForm *form) const;
		unsigned int getGrade(void) const;
		std::string	 getName(void) const;
		unsigned int increaseGrade(void);
		unsigned int decreaseGrade(void);

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

std::ostream		  &operator<<(std::ostream &ostream, Bureaucrat const &bureaucrat);
