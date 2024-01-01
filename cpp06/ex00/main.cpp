/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/28 14:16:07                                            */
/*   Updated:  2023/12/29 01:22:25                                            */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <math.h>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

typedef enum e_litteral_type
{
	e_char,
	e_int,
	e_float,
	e_double,
	e_invalid
} t_e_litteral_type;

static std::string trim(std::string const &str, std::string const &whitespace = " \t")
{
	const size_t strBegin = str.find_first_not_of(whitespace);
	const size_t strEnd = str.find_last_not_of(whitespace);
	const size_t strRange = strEnd - strBegin + 1;

	if (strBegin == std::string::npos)
	{
		return ""; // no content
	}
	return str.substr(strBegin, strRange);
}

static t_e_litteral_type get_litteral_type(std::string str)
{
	char *endptr;

	str = trim(str);
	if (str.empty())
	{
		return (e_invalid);
	}
	if (str.length() == 3 && isprint(str[1]) != 0 && str[0] == '\'' && str[2] == '\'')
	{
		return (e_char);
	}
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		return (e_float);
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		return (e_double);
	}
	strtol(str.c_str(), &endptr, 10);
	if (&str[str.length()] == endptr)
	{
		return (e_int);
	}
	strtod(str.c_str(), &endptr);
	if (&str[str.length()] == endptr)
	{
		return (e_double);
	}
	strtof(str.c_str(), &endptr);
	if (&str[str.length()] == endptr || ((*endptr == 'f') && (&str[str.length() - 1] == endptr)))
	{
		return (e_float);
	}
	return (e_invalid);
}

static void handle_char(char const *str)
{
	char val = str[1];

	if (isprint(static_cast<char>(val)) != 0)
	{
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	else
	{
		std::cout << "char: nonprintable\n";
	}
	std::cout << "int: " << static_cast<int>(val) << '\n';
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	std::cout << "double: " << static_cast<double>(val) << '\n';
}

static void handle_int(char const *str)
{
	long val = strtol(str, NULL, 10);

	if (val > INT_MAX || val < INT_MIN)
	{
		std::cout << "invalid litteral inputed\n";
		return;
	}
	if (val > CHAR_MAX || val < CHAR_MIN)
	{
		std::cout << "char: impossible\n";
	}
	else if (isprint(static_cast<char>(val)) != 0)
	{
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	else
	{
		std::cout << "char: nonprintable\n";
	}
	std::cout << "int: " << static_cast<int>(val) << '\n';
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	std::cout << "double: " << static_cast<double>(val) << '\n';
}

static void handle_float(char const *str)
{
	float val = strtof(str, NULL);

	if (val > CHAR_MAX || val < CHAR_MIN || isnan(val) == true)
	{
		std::cout << "char: impossible\n";
	}
	else if (isprint(static_cast<char>(val)) != 0)
	{
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	else
	{
		std::cout << "char: nonprintable\n";
	}
	if (val > static_cast<float>(INT_MAX - 127) || (val < static_cast<float>(INT_MIN + 128)) || isnan(val) == true)
	{
		std::cout << "int: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(val) << '\n';
	}
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	std::cout << "double: " << static_cast<double>(val) << '\n';
}

static void handle_double(char const *str)
{
	double val = strtod(str, NULL);

	if (val > CHAR_MAX || val < CHAR_MIN || isnan(val) == true)
	{
		std::cout << "char: impossible\n";
	}
	else if (isprint(static_cast<char>(val)) != 0)
	{
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	}
	else
	{
		std::cout << "char: nonprintable\n";
	}
	if (val > INT_MAX || val < INT_MIN || isnan(val) == true)
	{
		std::cout << "int: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(val) << '\n';
	}	
	std::cout << "float: " << static_cast<float>(val) << "f\n";
	std::cout << "double: " << static_cast<double>(val) << '\n';
}

int main(int argc, char **argv)
{
	t_e_litteral_type litteral_type;

	if (argc != 2)
	{
		std::cout << "one single argument should be passed to the program for it to function\n";
		return (EXIT_FAILURE);
	}
	litteral_type = get_litteral_type(argv[1]);
	switch (litteral_type)
	{
		case e_char:
		{
			handle_char(argv[1]);
			break;
		}
		case e_int:
		{
			handle_int(argv[1]);
			break;
		}
		case e_float:
		{
			handle_float(argv[1]);
			break;
		}
		case e_double:
		{
			handle_double(argv[1]);
			break;
		}
		case e_invalid:
		{
			std::cout << "invalid litteral inputed\n";
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

#pragma GCC diagnostic pop
