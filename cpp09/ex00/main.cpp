/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/01 12:43:20                                            */
/*   Updated:  2024/01/02 20:44:38                                            */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <new>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange bitcoin_exchange("data.csv");
			bitcoin_exchange.exchange(argv[1]);
		}
		catch (std::bad_alloc const &)
		{
			std::cerr << "program ran out of memory, aborting.\n";
		}
		catch (...)
		{
		}
	}
	else
	{
		std::cout << "program needs to recive the filename of a file whit a cuantity database \n";
	}
	return (0);
}

#pragma GCC diagnostic pop
