/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: contact.hpp                                                    */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 12:35:26                                            */
/*   Updated:  2024/01/23 07:24:16                                            */
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
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;
		bool		initialized;

	public:
		Contact operator=(Contact const &rvalue);
		Contact();
		Contact(Contact const &arg);
		Contact(std::string const &arg_first_name, std::string const &arg_last_name, std::string const &arg_nick_name,
				std::string const &arg_phone_number, std::string const &arg_darkest_secret);
		~Contact();

		std::string get_first_name(void) const;
		std::string get_last_name(void) const;
		std::string get_nick_name(void) const;
		std::string get_phone_number(void) const;
		std::string get_darkest_secret(void) const;
		bool		get_initialized(void) const;
};

#pragma GCC diagnostic pop
