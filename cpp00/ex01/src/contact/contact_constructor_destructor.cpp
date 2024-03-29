/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: contact_constructor_destructor.cpp                             */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 19:47:34                                            */
/*   Updated:  2024/01/23 07:26:44                                            */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Contact Contact::operator=(Contact const &rvalue)
{
	first_name = rvalue.first_name;
	last_name = rvalue.last_name;
	nick_name = rvalue.nick_name;
	phone_number = rvalue.phone_number;
	darkest_secret = rvalue.darkest_secret;
	initialized = true;
	return (*this);
}

Contact::Contact() : initialized(false)
{
}

Contact::Contact(Contact const &arg)
	: first_name(arg.first_name), last_name(arg.last_name), nick_name(arg.nick_name), phone_number(arg.phone_number),
	  darkest_secret(arg.darkest_secret), initialized(true)
{
}

Contact::Contact(std::string const &arg_first_name, std::string const &arg_last_name, std::string const &arg_nick_name,
				 std::string const &arg_phone_number, std::string const &arg_darkest_secret)
	: first_name(arg_first_name), last_name(arg_last_name), nick_name(arg_nick_name), phone_number(arg_phone_number),
	  darkest_secret(arg_darkest_secret), initialized(true)
{
}

Contact::~Contact()
{
}

std::string Contact::get_first_name(void) const
{
	return (first_name);
}

std::string Contact::get_last_name(void) const
{
	return (last_name);
}

std::string Contact::get_nick_name(void) const
{
	return (nick_name);
}

std::string Contact::get_phone_number(void) const
{
	return (phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (darkest_secret);
}

bool Contact::get_initialized(void) const
{
	return (initialized);
}

#pragma GCC diagnostic pop
