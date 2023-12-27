/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:04:22                                            */
/*   Updated:  2023/12/05 17:03:55                                            */
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
		void  operator=(Fixed const &fixed);

		int	  getRawBits(void) const;
		void  setRawBits(int bits);
		float toFloat(void) const;
		int	  toInt(void) const;
};

std::ostream		  &operator<<(std::ostream &os, Fixed const &num);

#pragma GCC diagnostic pop
