/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.cpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:51:29                                            */
/*   Updated:  2023/12/07 18:22:44                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>

Fixed::Fixed(void) : num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int int_val)
{
	std::cout << "Int constructor called\n";

	if (((int_val > static_cast<int>((1U << (sizeof(int) * 8 - binary_ponint_position - 1)) - 1))) ||
		((int_val < 0) && (std::abs(int_val) > static_cast<int>(1U << (sizeof(int) * 8 - binary_ponint_position - 1)))))
	{
		throw(std::out_of_range("given integer value is not representable as a fixed value"));
	}
	if (int_val < 0)
	{
		num = -1;
		num -= static_cast<int>(static_cast<unsigned>((-int_val)) << static_cast<unsigned>(binary_ponint_position));
		if (num > 0)
		{
			num = static_cast<int>(1U << ((sizeof(int) * 8) - 1));
		}
		return;
	}
	num = static_cast<int>(static_cast<unsigned>(int_val) << static_cast<unsigned>(binary_ponint_position));
}

Fixed::Fixed(float float_val)
{
	float		 remainder;
	unsigned int decimal_part;
	unsigned int i;

	std::cout << "Float constructor called\n";
	if (std::isnan(float_val))
	{
		throw(std::domain_error("nan given as a initialization value for a Fixed"));
	}
	if (float_val >= 0)
	{
		num = Fixed(static_cast<int>(std::floor(float_val))).num;
	}
	else
	{
		num = Fixed(static_cast<int>(-std::floor(std::abs(float_val)))).num;
	}
	remainder = std::fmod(std::abs(float_val), 1.0F);
	decimal_part = 0;
	i = 7;
	for (float n = .5; n >= std::pow(2.0F, -8.0F); n /= 2)
	{
		if (remainder >= n)
		{
			remainder -= n;
			decimal_part |= 1U << i;
		}
		i--;
	}
	if (remainder >= std::pow(2.0F, -9.0F))
	{
		decimal_part++;
	}
	if (float_val > 0)
	{
		num = static_cast<int>(static_cast<unsigned>(num) | decimal_part);
		return;
	}
	num -= static_cast<int>(decimal_part);
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

float Fixed::toFloat(void) const
{
	std::string string_representation;
	char		buffer[11];
	char		base[9] = "00000000";
	char		additions[8][8] = {
		   [0] = {5, 0, 0, 0, 0, 0, 0, 0},
		   [1] = {2, 5, 0, 0, 0, 0, 0, 0},
		   [2] = {1, 2, 5, 0, 0, 0, 0, 0},
		   [3] = {0, 6, 2, 5, 0, 0, 0, 0},
		   [4] = {0, 3, 1, 2, 5, 0, 0, 0},
		   [5] = {0, 1, 5, 6, 2, 5, 0, 0},
		   [6] = {0, 0, 7, 8, 1, 2, 5, 0},
		   [7] = {0, 0, 3, 9, 0, 6, 2, 5},
	   };

	sprintf(buffer, "%d", toInt());
	string_representation = buffer;
	string_representation.push_back('.');
	for (unsigned i = 0; i < 8; i++)
	{
		if ((static_cast<unsigned>(num) & (1U << ((binary_ponint_position - 1) - i))) != 0)
		{
			for (int j = 0; j < 8; j++)
			{
				base[j] = static_cast<char>(base[j] + additions[i][j]);
			}
		}
	}
	for (int i = 7; i > 0; i--)
	{
		if (base[i] > '9')
		{
			base[i - 1]++;
			base[i] = static_cast<char>(base[i] - 10);
		}
	}
	string_representation.append(base);
	return (strtof(string_representation.c_str(), NULL));
}

int Fixed::toInt(void) const
{
	unsigned int res;

	res = static_cast<unsigned int>(num);
	res <<= 1U;
	res >>= binary_ponint_position + 1U;
	if (num < 0)
	{
		return (-(static_cast<int>(res)));
	}
	return (static_cast<int>(res));
}

std::ostream &operator<<(std::ostream &os, Fixed const &num)
{
	os << num.toFloat();
	return (os);
}
