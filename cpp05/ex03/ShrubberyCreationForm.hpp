/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: ShrubberyCreationForm.hpp                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/26 16:20:59                                            */
/*   Updated:  2023/12/26 17:02:54                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm(void);
		explicit ShrubberyCreationForm(std::string const &target_arg);
		ShrubberyCreationForm(ShrubberyCreationForm const &shruberryCreationForm);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shruberryCreationForm);
		~ShrubberyCreationForm(void);

		bool execute(Bureaucrat const &bureaucrat);
};

#pragma GCC diagnostic pop
