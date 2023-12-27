/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Fixed.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 20:04:22                                            */
/*   Updated:  2023/12/04 21:06:48                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
		Fixed(Fixed const &fixed);
		~Fixed(void);
		void operator=(Fixed const &fixed);

		int	 getRawBits(void) const;
		void setRawBits(int bits);
};

#pragma GCC diagnostic pop
