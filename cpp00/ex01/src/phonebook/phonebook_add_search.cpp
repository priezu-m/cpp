/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: phonebook_add_search.cpp                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 19:28:17                                            */
/*   Updated:  2024/01/23 07:22:07                                            */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

static bool regex_match(std::string str)
{
	std::string::iterator iterator = str.begin();
	std::string::iterator end = str.end();

	while (iterator != end)
	{
		if (((*iterator == '+') && (iterator != str.begin())) ||
			(((*iterator < '0') || (*iterator > '9')) && (*iterator != ' ')))
		{
			return (false);
		}
		iterator++;
	}
	return (true);
}

static std::string promt_input_file_throws(std::string const &promt, bool const regex = false)
{
	std::string str;

	std::cout << promt;
	std::getline(std::cin, str);
	str = trim(str);
	if (str.empty() == true)
	{
		throw(e_field_cannot_be_empty_exeption);
	}
	if (regex == true)
	{
		if (regex_match(str) == false)
		{
			throw(e_phone_number_does_not_match_regex_exeption);
		}
	}
	return (str);
}

void Phonebook::add_throws(void)
{

	std::string first_name = promt_input_file_throws("first name: ");
	std::string last_name = promt_input_file_throws("last name: ");
	std::string nick_name = promt_input_file_throws("nick name: ");
	std::string phone_number = promt_input_file_throws("phone number: ", true);
	std::string darkest_secret = promt_input_file_throws("darkest secret: ");

	contacts[next_free_slot] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	next_free_slot = (next_free_slot + 1) % 8;
}

static void print_trunc(std::string const &str)
{
	for (size_t j = 10UL - std::min(10UL, str.size()); j > 0; j--)
	{
		std::cout << ' ';
	}
	std::cout << str.substr(0, 9);
	if (str.size() > 9)
	{
		std::cout << '.';
	}
	std::cout << '|';
}

void Phonebook::search(void)
{
	int			i;
	std::string str;

	if (contacts[0].get_initialized() == false)
	{
		std::cout << "phonebook is empty\n";
		return;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "|     index|first name| last name|  nickname|\n";
	std::cout << "---------------------------------------------\n";
	for (i = 0; i < 8; i++)
	{
		if (contacts[i].get_initialized() == false)
		{
			break;
		}
		std::cout << "|         " << i + 1 << '|';
		print_trunc(contacts[i].get_first_name());
		print_trunc(contacts[i].get_last_name());
		print_trunc(contacts[i].get_nick_name());
		std::cout << "\n---------------------------------------------\n";
	}
	std::cout << "select contact by index for lookup: ";
	std::getline(std::cin, str);
	str = trim(str);
	if (str.size() != 1)
	{
		std::cout << "invalid input given as index\n";
		return;
	}
	if (str[0] > '8' || str[0] < '1')
	{
		std::cout << "invalid index given\n";
		return;
	}
	std::cout << "first name: " << contacts[(str[0] - '0') - 1].get_first_name() << '\n';
	std::cout << "last name: " << contacts[(str[0] - '0') - 1].get_last_name() << '\n';
	std::cout << "nickname: " << contacts[(str[0] - '0') - 1].get_nick_name() << '\n';
	std::cout << "phone number: " << contacts[(str[0] - '0') - 1].get_phone_number() << '\n';
	std::cout << "darkest secret: " << contacts[(str[0] - '0') - 1].get_darkest_secret() << '\n';
}

#pragma GCC diagnostic pop
