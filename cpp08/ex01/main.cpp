/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/30 15:49:37                                            */
/*   Updated:  2023/12/30 22:20:02                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <exception>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main()
{
	{
		Span sp(5);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
	}

	{
		Span sp(1);
		sp.addNumber(0);
		try
		{
			sp.addNumber(0);
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << '\n';
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << '\n';
		}
	}

	{
		const size_t	size = 100000;
		Span			sp(size);

		for (size_t i = 0; i < size; i++)
		{
			//NOLINTNEXTLINE
			sp.addNumber(rand());
		}
		std::cout << sp.shortestSpan() << '\n';
		std::cout << sp.longestSpan() << '\n';
	}
}

#pragma GCC diagnostic pop
