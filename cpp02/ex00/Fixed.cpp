/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.cpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:51:29                                            */
/*   Updated:  2023/12/04 21:06:59                                            */
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

Fixed::Fixed(void) : num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &fixed) : num(fixed.num)
{
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

void Fixed::operator=(Fixed const &fixed)
{
	num = fixed.num;
	std::cout << "Copy assignment operator called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (num);
}

void Fixed::setRawBits(int bits)
{
	std::cout << "setRawBits member function called\n";
	num = bits;
}

#pragma GCC diagnostic pop
