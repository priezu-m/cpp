/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 12:06:43                                            */
/*   Updated:  2023/11/27 20:14:17                                            */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook/phonebook.hpp"
#include "trim/trim.hpp"
#include <cstddef>
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

int main(void)
{
	std::string command;
	Phonebook	phonebook;

	std::getline(std::cin, command);
	command = trim(command);
	while (command != "EXIT" && std::cin.eof() == false && std::cin.fail() == false)
	{
		if (command == "ADD")
		{
			try
			{
				phonebook.add_throws();
			}
			catch (enum phonebook_exeptions exception)
			{
				if (exception == e_field_cannot_be_empty_exeption)
				{
					std::cout << "field cannot be empty, aborting ADD\n";
				}
				else
				{
					std::cout << "phone number does not match regex \"+?[0-9 ]*\", aborting ADD\n";
				}
			}
		}
		else if (command == "SEARCH")
		{
			phonebook.search();
		}
		else
		{
			std::cout << "Unknown command\n";
		}
		std::getline(std::cin, command);
		trim(command);
	}
}

#pragma GCC diagnostic pop
