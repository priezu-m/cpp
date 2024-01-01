/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: BitcoinExchange.cpp                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/01 13:00:03                                            */
/*   Updated:  2024/01/01 16:16:55                                            */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <fcntl.h>
#include <fstream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

BitcoinExchange::BitcoinExchange(std::string const &value_database)
{
	set_value_database(value_database);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &bitcoin_exchange)
	: date_to_value(bitcoin_exchange.date_to_value)
{
}

BitcoinExchange BitcoinExchange::operator=(BitcoinExchange const &bitcoin_exchange)
{
	date_to_value = bitcoin_exchange.date_to_value;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::exchange(std::string cuantity_database)
{
}

void BitcoinExchange::set_value_database(std::string const &value_database)
{
	std::ifstream	dbf(value_database);

	if (dbf.good() == false)
	{
	}
}

#pragma GCC diagnostic pop
