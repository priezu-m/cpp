/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: megaphone.cpp                                                  */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/27 01:33:45                                            */
/*   Updated:  2023/11/30 11:59:32                                            */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wnull-arithmetic"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; argv[i][j] != NULL; j++)
		{
			argv[i][j] = static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << argv[i];
	}
	std::cout << '\n';
	return (EXIT_SUCCESS);
}

#pragma GCC diagnostic pop
