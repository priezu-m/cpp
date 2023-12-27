/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.cpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:51:29                                            */
/*   Updated:  2023/12/07 18:26:22                                            */
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

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma GCC diagnostic ignored "-Wc99-designator"
;

Fixed::Fixed(void) : num(0)
{
}

Fixed::Fixed(int int_val)
{
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
}

Fixed::~Fixed(void)
{
}

void Fixed::operator=(Fixed const &fixed)
{
	num = fixed.num;
}

int Fixed::getRawBits(void) const
{
	return (num);
}

void Fixed::setRawBits(int bits)
{
	num = bits;
}

float Fixed::toFloat(void) const
{
	return (strtof(toString().c_str(), NULL));
}

int Fixed::toInt(void) const
{
	unsigned representaion;

	if (num < 0)
	{
		representaion = (1U << (sizeof(int) * 8 - (binary_ponint_position + 1))) - 1;
		representaion -= ((static_cast<unsigned>(num) << 1U) >> (binary_ponint_position + 1U));
		return (-static_cast<int>(representaion));
	}
	return (static_cast<int>((static_cast<unsigned>(num) >> static_cast<unsigned>(binary_ponint_position))));
}

std::string Fixed::toString() const
{
	int			integer_part = std::abs(toInt());
	std::string string_representation("");
	unsigned	decimal_part;
	char		buffer[11];
	char		base[] = "00000000";
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

	if (num < 0)
	{
		string_representation.push_back('-');
	}
	sprintf(buffer, "%d", integer_part);
	string_representation.append(buffer);
	string_representation.push_back('.');
	if (num >= 0)
	{
		decimal_part = static_cast<unsigned>(num) & ((1U << static_cast<unsigned>(binary_ponint_position)) - 1);
	}
	else
	{
		decimal_part = ~static_cast<unsigned>(num) & ((1U << static_cast<unsigned>(binary_ponint_position)) - 1);
	}
	for (unsigned int i = 0; i < 8; i++)
	{
		if ((decimal_part & (1U << ((binary_ponint_position - 1U) - i))) != 0)
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
			base[i - 1] = static_cast<char>(base[i - 1] + ((base[i] - '0') / 10));
			base[i] = static_cast<char>(((base[i] - '0') % 10) + '0');
		}
	}
	string_representation.append(base);
	return (string_representation);
}

std::ostream &operator<<(std::ostream &os, Fixed const &num)
{
	os << num.toString();
	return (os);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	if (x < y)
	{
		return (x);
	}
	return (y);
}

Fixed const &Fixed::min(Fixed const &x, Fixed const &y)
{
	if (x < y)
	{
		return (x);
	}
	return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	if (x > y)
	{
		return (x);
	}
	return (y);
}

Fixed const &Fixed::max(Fixed const &x, Fixed const &y)
{
	if (x > y)
	{
		return (x);
	}
	return (y);
}

bool Fixed::operator>(Fixed const &comparans) const
{
	return (num > comparans.num);
}

bool Fixed::operator>=(Fixed const &comparans) const
{
	return (num >= comparans.num);
}

bool Fixed::operator<(Fixed const &comparans) const
{
	return (num < comparans.num);
}

bool Fixed::operator<=(Fixed const &comparans) const
{
	return (num <= comparans.num);
}

bool Fixed::operator==(Fixed const &comparans) const
{
	return (num == comparans.num);
}

bool Fixed::operator!=(Fixed const &comparans) const
{
	return (num != comparans.num);
}

Fixed Fixed::operator+(Fixed const &addend) const
{
	Fixed ret;

	ret.setRawBits(num + addend.num);
	return (ret);
}

Fixed Fixed::operator-(Fixed const &subtrahend) const
{
	Fixed ret;

	ret.setRawBits(num - subtrahend.num);
	return (ret);
}

Fixed Fixed::operator*(Fixed const &multiplicand) const
{
	u_int64_t aux;
	Fixed   res;

	aux = static_cast<u_int64_t>(num) * static_cast<u_int64_t>(multiplicand.num);
	aux = aux >> static_cast<unsigned>(binary_ponint_position);
	res.setRawBits(static_cast<int>(aux));
	return (res);
}

static int64_t powi(int base, unsigned int exp)
{
	int res = 1;

	while (exp != 0)
	{
		if ((exp & 1U) != 0)
		{
			res *= base;
		}
		exp >>= 1U;
		base *= base;
	}
	return res;
}

Fixed Fixed::operator/(Fixed const &divisor) const
{
	int64_t	aux;
	Fixed	res;

	aux = num * powi(2, binary_ponint_position);
	aux = aux / divisor.num;
	res.setRawBits(static_cast<int>(aux));
	return (res);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	num++;
	return (copy);
}

Fixed Fixed::operator++()
{
	++num;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	num--;
	return (copy);
}

Fixed Fixed::operator--()
{
	--num;
	return (*this);
}

#pragma GCC diagnostic pop
