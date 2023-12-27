/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: contact.hpp                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 12:35:26                                            */
/*   Updated:  2023/11/27 19:50:04                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		bool		initialized;

		Contact		operator=(Contact const &rvalue);
		Contact();
		Contact(Contact const &arg);
		Contact(std::string const &arg_first_name, std::string const &arg_last_name, std::string const &arg_nick_name,
				std::string const &arg_phone_number, std::string const &arg_darkest_secret);
		~Contact();
};

#pragma GCC diagnostic pop
