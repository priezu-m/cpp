/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/11/30 13:35:03                                            */
/*   Updated:  2023/11/30 13:41:15                                            */
/*                                                                            */
/* ************************************************************************** */

#include <string>
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
	std::string	string("HI THIS IS BRAIN");
	std::string	*stringPTR(&string);
	std::string	&stringREF(string);

	std::cout << "memory address of the string variable: " << &string << '\n';
	std::cout << "memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "memory address held by stringREF: " << &stringREF << '\n';
	std::cout << "value of the string variable: " << string << '\n';
	std::cout << "value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "value pointed to by stringREF: " << stringREF << '\n';
}

#pragma GCC diagnostic pop
