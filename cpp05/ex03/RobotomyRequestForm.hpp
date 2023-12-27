/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: RobotomyRequestForm.hpp                                        */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/23 13:58:33                                            */
/*   Updated:  2023/12/23 19:20:03                                            */
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
#pragma GCC diagnostic ignored "-Wpadded"
;

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm(void);
		explicit RobotomyRequestForm(std::string const &target_arg);
		RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
		~RobotomyRequestForm(void);

		bool execute(Bureaucrat const &bureaucrat);
};

#pragma GCC diagnostic pop
