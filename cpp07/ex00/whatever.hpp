/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: whatever.hpp                                                   */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/29 13:55:47                                            */
/*   Updated:  2023/12/29 14:03:44                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

template<typename T>
void swap(T &x, T &y)
{
	const T tmp = x;

	x = y;
	y = tmp;
}

template<typename T>
T min(T &x, T &y)
{
	if (x < y)
	{
		return (x);
	}
	return (y);
}

template<typename T>
T max(T &x, T &y)
{
	if (x > y)
	{
		return (x);
	}
	return (y);
}

#pragma GCC diagnostic pop
