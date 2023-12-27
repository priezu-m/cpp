/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:04:22                                            */
/*   Updated:  2023/12/07 02:16:27                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Fixed
{
	private:
		int				 num;
		static int const binary_ponint_position = 8;

	public:
		Fixed(void);
		explicit Fixed(int int_val);
		explicit Fixed(float float_val);
		Fixed(Fixed const &fixed);
		~Fixed(void);
		void				operator=(Fixed const &fixed);

		int					getRawBits(void) const;
		void				setRawBits(int bits);
		float				toFloat(void) const;
		std::string			toString(void) const;
		int					toInt(void) const;

		static Fixed	   &min(Fixed &x, Fixed &y);
		static Fixed const &min(Fixed const &x, Fixed const &y);
		static Fixed	   &max(Fixed &x, Fixed &y);
		static Fixed const &max(Fixed const &x, Fixed const &y);

		bool				operator>(Fixed const &comparans) const;
		bool				operator>=(Fixed const &comparans) const;
		bool				operator<(Fixed const &comparans) const;
		bool				operator<=(Fixed const &comparans) const;
		bool				operator==(Fixed const &comparans) const;
		bool				operator!=(Fixed const &comparans) const;
		Fixed				operator+(Fixed const &addend) const;
		Fixed				operator-(Fixed const &subtrahend) const;
		Fixed				operator*(Fixed const &multiplicand) const;
		Fixed				operator/(Fixed const &divisor) const;
		Fixed				operator++();
		Fixed				operator++(int);
		Fixed				operator--();
		Fixed				operator--(int);
};

std::ostream		  &operator<<(std::ostream &os, Fixed const &num);

#pragma GCC diagnostic pop
