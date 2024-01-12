/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: PresidentialPardonForm.hpp                                     */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/26 16:06:21                                            */
/*   Updated:  2023/12/26 16:12:12                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm(void);
		explicit PresidentialPardonForm(std::string const &target_arg);
		PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
		~PresidentialPardonForm(void);

		bool execute(Bureaucrat const &bureaucrat);
};
