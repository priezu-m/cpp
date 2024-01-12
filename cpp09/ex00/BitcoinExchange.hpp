/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: BitcoinExchange.hpp                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/01 12:43:27                                            */
/*   Updated:  2024/01/02 19:21:19                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>

typedef struct s_amount
{
		union u_amount
		{
				double double_amount;
				int	   int_amount;
		} amount;

		enum e_type
		{
			e_int,
			e_double
		} type;
} t_amount;

class BitcoinExchange
{
	private:
		std::map<std::string, t_amount> date_to_value;

	public:
		BitcoinExchange(void);
		explicit BitcoinExchange(std::string const &value_database);
		BitcoinExchange(BitcoinExchange const &bitcoin_exchange);
		BitcoinExchange operator=(BitcoinExchange const &bitcoin_exchange);
		~BitcoinExchange(void);

		void exchange(std::string const &cuantity_database) const;
};
