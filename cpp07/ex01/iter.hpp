/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: iter.hpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/29 13:55:47                                            */
/*   Updated:  2023/12/29 17:17:41                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stddef.h>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

template<typename T>
void iter(T *beginning, size_t size, void (*f)(T *))
{
	for (size_t i = 0; i < size; i++)
	{
		f(&beginning[i]);
	}
}

#pragma GCC diagnostic pop
