/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: trim.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 13:13:45                                            */
/*   Updated:  2023/11/27 13:15:49                                            */
/*                                                                            */
/* ************************************************************************** */

#include "trim.hpp"

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

std::string trim(std::string const &str, std::string const &whitespace)
{
	const size_t strBegin = str.find_first_not_of(whitespace);
	const size_t strEnd = str.find_last_not_of(whitespace);
	const size_t strRange = strEnd - strBegin + 1;

	if (strBegin == std::string::npos)
	{
		return ("");
	}
	return str.substr(strBegin, strRange);
}

#pragma GCC diagnostic pop
