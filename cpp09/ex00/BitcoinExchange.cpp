/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: BitcoinExchange.cpp                                            */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/01 13:00:03                                            */
/*   Updated:  2024/01/02 21:04:19                                            */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <exception>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <string>
#include <typeinfo>
#include <utility>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

typedef enum e_error_code
{
	ev_no_delimeter,
	ev_invalid_date,
	ev_invalid_value
} t_e_error_code;

static t_amount get_amount_throws(std::string line, char delimiter)
{
	std::string::size_type pos;
	std::string			   num;
	char				  *endptr;
	t_amount			   ret;

	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
	pos = line.find(delimiter);
	if (pos == line.length() - 1)
	{
		throw(ev_invalid_value);
	}
	num = line.substr(pos + 1, line.length() - 1);
	strtol(num.c_str(), &endptr, 10);
	if (&num[num.length()] == endptr)
	{
		long val = strtol(num.c_str(), NULL, 10);

		if (val > INT_MAX || val < INT_MIN)
		{
			throw(ev_invalid_value);
		}
		ret.amount.int_amount = static_cast<int>(val);
		ret.type = s_amount::e_int;
		return (ret);
	}
	strtod(num.c_str(), &endptr);
	if (&num[num.length()] == endptr)
	{
		double val = strtod(num.c_str(), NULL);

		if (std::isnan(val) == true)
		{
			throw(ev_invalid_value);
		}
		ret.amount.double_amount = val;
		ret.type = s_amount::e_double;
		return (ret);
	}
	throw(ev_invalid_value);
}

static std::string get_date_throws(std::string line, char delimiter)
{
	std::string::size_type pos;
	std::string			   date;

	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
	pos = line.find(delimiter);
	if (pos == std::string::npos)
	{
		throw(ev_no_delimeter);
	}
	date = line.substr(0, pos);
	if (date.length() < 7 || isdigit(date[date.length() - 1]) == 0 || isdigit(date[date.length() - 2]) == 0 ||
		isdigit(date[date.length() - 2]) > '1' ||
		(isdigit(date[date.length() - 2]) == '1' && date[date.length() - 1] > '2') || date[date.length() - 3] != '-' ||
		isdigit(date[date.length() - 4]) == 0 || isdigit(date[date.length() - 5]) == 0 ||
		isdigit(date[date.length() - 5]) > '1' ||
		(isdigit(date[date.length() - 5]) == '1' && date[date.length() - 4] > '2') || date[date.length() - 6] != '-')
	{
		throw(ev_invalid_date);
	}
	for (size_t i = 0; i < date.length() - 6; i++)
	{
		if (isdigit(date[i]) == 0)
		{
			throw(ev_invalid_date);
		}
	}
	return (date);
}

static std::pair<std::string, t_amount> parse_line(char *lineptr, char delimiter)
{
	std::string line(lineptr);
	std::string date = get_date_throws(line, delimiter);
	t_amount	amount = get_amount_throws(line, delimiter);

	return (std::pair<std::string, t_amount>(date, amount));
}

BitcoinExchange::BitcoinExchange(std::string const &value_database)
{
	static char						*lineptr;
	size_t							 line_size;
	size_t							 lineno;
	FILE *const						 fp = fopen(value_database.c_str(), "r");
	std::pair<std::string, t_amount> pair;

	if (fp == NULL)
	{
		perror(("failed to open " + value_database).c_str());
		throw(0);
	}
	errno = -1;
	for (lineno = 1; getline(&lineptr, &line_size, fp) != -1; lineno++)
	{
		if (lineno == 1)
		{
			if (lineptr == std::string("date,exchange_rate\n"))
			{
				continue;
			}
			std::cerr << "Could not parse line " << lineno << " of the value database\n";
			throw(0);
		}
		try
		{
			if (date_to_value.insert(parse_line(lineptr, ',')).second == false)
			{
				std::cerr << "duplicated element in line " << lineno << " of the value database\n";
			}
		}
		catch (t_e_error_code const &code)
		{
			switch (code)
			{
				case ev_invalid_date:
				{
					std::cerr << "invalid date in the line " << lineno << " of the value database\n";
					throw(code);
				}
				case ev_invalid_value:
				{
					std::cerr << "invalid value in the line " << lineno << " of the value database\n";
					throw(code);
				}
				case ev_no_delimeter:
				{
					std::cerr << "no delimiter in the line " << lineno << " of the value database\n";
					throw(code);
				}
			}
		}
	}
	if (errno >= 0)
	{
		perror(("failed to read from " + value_database).c_str());
		throw(0);
	}
	if (date_to_value.empty() == true)
	{
		std::cerr << "database is empty\n";
		throw(0);
	}
	fclose(fp);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &bitcoin_exchange)
	: date_to_value(bitcoin_exchange.date_to_value)
{
}

BitcoinExchange BitcoinExchange::operator=(BitcoinExchange const &bitcoin_exchange)
{
	date_to_value = bitcoin_exchange.date_to_value;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

static void exchange_helper(char *lineptr, std::map<std::string, t_amount> const &date_to_value)
{
	std::map<std::string, t_amount>::const_iterator it;
	std::pair<std::string, t_amount>				pair;

	pair = parse_line(lineptr, '|');

	if (((pair.second.type == s_amount::e_int) && (pair.second.amount.int_amount < 0)) ||
		((pair.second.type == s_amount::e_double) && (pair.second.amount.double_amount < 0)))
	{
		throw(ev_invalid_value);
	}
	it = date_to_value.upper_bound(pair.first);
	if (it == date_to_value.begin())
	{
		throw(ev_invalid_date);
	}
	it--;
	std::cout << pair.first << " => ";
	if (pair.second.type == s_amount::e_int)
	{
		std::cout << pair.second.amount.int_amount << " = ";
		if (it->second.type == s_amount::e_int)
		{
			std::cout << it->second.amount.int_amount * pair.second.amount.int_amount << '\n';
		}
		else
		{
			std::cout << it->second.amount.double_amount * pair.second.amount.int_amount << '\n';
		}
	}
	else
	{
		std::cout << pair.second.amount.double_amount << " = ";
		if (it->second.type == s_amount::e_int)
		{
			std::cout << it->second.amount.int_amount * pair.second.amount.double_amount << '\n';
		}
		else
		{
			std::cout << it->second.amount.double_amount * pair.second.amount.double_amount << '\n';
		}
	}
}

void BitcoinExchange::exchange(std::string const &cuantity_database) const
{
	static char *lineptr;
	size_t		 line_size;
	size_t		 lineno;
	FILE *const	 fp = fopen(cuantity_database.c_str(), "r");

	if (fp == NULL)
	{
		perror(("failed to open " + cuantity_database).c_str());
		throw(0);
	}
	errno = -1;
	for (lineno = 1; getline(&lineptr, &line_size, fp) != -1; lineno++)
	{
		if ((lineno == 1) && (lineptr == std::string("date | value\n")))
		{
			continue;
		}
		try
		{
			exchange_helper(lineptr, date_to_value);
		}
		catch (t_e_error_code const &code)
		{
			switch (code)
			{
				case ev_invalid_date:
				{
					std::cout << "invalid date in the line " << lineno << " of the cuantity database\n";
					continue;
				}
				case ev_invalid_value:
				{
					std::cout << "invalid value in the line " << lineno << " of the cuantity database\n";
					continue;
				}
				case ev_no_delimeter:
				{
					std::cout << "no delimiter in the line " << lineno << " of the cuantity database\n";
					continue;
				}
			}
		}
	}
	if (errno >= 0)
	{
		perror(("failed to read from " + cuantity_database).c_str());
		throw(0);
	}
	fclose(fp);
}

#pragma GCC diagnostic pop
