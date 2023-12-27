/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:03:22                                            */
/*   Updated:  2023/12/07 18:32:16                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(void)
{
	std::cout << "expected: -1\t gotten: " << Fixed(1.F) * Fixed(-1.F) << '\n';
	std::cout << "expected: 1\t gotten: " << Fixed(1.F) * Fixed(1) << '\n';
	std::cout << "expected: 1\t gotten: " << Fixed(-1.F) * Fixed(-1) << '\n';
	std::cout << "expected: 4\t gotten: " << Fixed(-2.F) * Fixed(-2) << '\n';
	std::cout << "expected: 4.5\t gotten: " << Fixed(-2.25F) * Fixed(-2) << '\n';
	std::cout << "expected: -4.5\t gotten: " << Fixed(2.25F) * Fixed(-2) << '\n';
	std::cout << "expected: -4.5\t gotten: " << Fixed(2.25F) / Fixed(-0.5F) << '\n';
	std::cout << "expected: 4.5\t gotten: " << Fixed(-2.25F) / Fixed(-0.5F) << '\n';
	std::cout << "expected: .09\t gotten: " << (Fixed(-2.25F) / Fixed(-2.5F) * Fixed(0))++  << '\n';
	std::cout << "expected: 0\t gotten: " << (--(Fixed(-2.25F) / Fixed(-2.5F) * Fixed(0)))  << '\n';
	std::cout << "expected: -.01\t gotten: " << --(--(Fixed(-2.25F) / Fixed(-2.5F) * Fixed(0)))  << '\n';
	std::cout << "expected: true\t gotten: " << (Fixed(1) < Fixed(2)) << '\n';
	std::cout << "expected: false\t gotten: " << (Fixed(1) > Fixed(2)) << '\n';
	std::cout << "expected: true\t gotten: " << (Fixed(1) != Fixed(2)) << '\n';
	std::cout << "expected: false\t gotten: " << (Fixed(1) == Fixed(2)) << '\n';
	std::cout << "expected: true\t gotten: " << (Fixed(1) == Fixed(1)) << '\n';
	std::cout << "expected: true\t gotten: " << (Fixed(-1) < Fixed(2)) << '\n';
	std::cout << "expected: false\t gotten: " << (Fixed(-1) > Fixed(2)) << '\n';
	std::cout << "expected: false\t gotten: " << (Fixed(-1) < Fixed(-2)) << '\n';
	std::cout << "expected: true\t gotten: " << (Fixed(-1) > Fixed(-2)) << '\n';
	return 0;
}

#pragma GCC diagnostic pop
