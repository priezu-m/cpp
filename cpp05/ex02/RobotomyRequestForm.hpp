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
