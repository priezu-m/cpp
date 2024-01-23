/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: phonebook_constructor_destructor.cpp                           */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 19:24:45                                            */
/*   Updated:  2024/01/23 07:22:28                                            */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Phonebook::Phonebook() : next_free_slot(0)
{
}

Phonebook::Phonebook(Phonebook const &arg) : next_free_slot(arg.next_free_slot)
{
	for (int i = 0; i < 8; i++)
	{
		if (arg.contacts[i].get_initialized() == false)
		{
			break;
		}
		contacts[i] = arg.contacts[i];
	}
}

Phonebook::~Phonebook()
{
}

#pragma GCC diagnostic pop
