/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/28 14:16:07                                            */
/*   Updated:  2023/12/29 17:24:12                                            */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstddef>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

static void f(int *n)
{
	(*n)++;
}

int main(void)
{
	int	arr[] = {1,2,3,4,5,6,7,8,9,10};

	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	iter(arr, sizeof(arr) / sizeof(arr[0]), f);
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	return (0);
}

#pragma GCC diagnostic pop
