/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: phonebook.hpp                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 12:27:15                                            */
/*   Updated:  2023/11/27 19:52:20                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../contact/contact.hpp"
#include "../trim/trim.hpp"
#include <cstddef>
#include <exception>
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

enum phonebook_exeptions
{
	e_field_cannot_be_empty_exeption,
	e_phone_number_does_not_match_regex_exeption
};

class Phonebook
{

	private:
		int		next_free_slot;
		Contact contacts[8];

	public:
		Phonebook();
		Phonebook(Phonebook const &arg);
		~Phonebook();
		void add_throws(void);
		void search(void);
};

#pragma GCC diagnostic pop
