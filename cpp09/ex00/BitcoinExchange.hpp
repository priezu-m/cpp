/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: BitcoinExchange.hpp                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/01 12:43:27                                            */
/*   Updated:  2024/01/01 16:03:27                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class BitcoinExchange
{
	private:
		std::map<std::string, float> date_to_value;

	public:
		BitcoinExchange(void);
		explicit BitcoinExchange(std::string const &value_database);
		BitcoinExchange(BitcoinExchange const &bitcoin_exchange);
		BitcoinExchange operator=(BitcoinExchange const &bitcoin_exchange);
		~BitcoinExchange(void);

		void exchange(std::string cuantity_database);
		void set_value_database(std::string const &value_database);
};

#pragma GCC diagnostic pop
