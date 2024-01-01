/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: easyfind.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/29 18:43:25                                            */
/*   Updated:  2023/12/30 15:45:10                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

template<typename T>
typename T::iterator easyfind(T &ints, int n)
{
	typename T::iterator const iterator = std::find(ints.begin(), ints.end(), n);

	if (iterator == ints.end())
	{
		return (static_cast<typename T::iterator>(NULL));
	}
	return (iterator);
}

#pragma GCC diagnostic pop
