/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Span.hpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/30 15:49:45                                            */
/*   Updated:  2023/12/30 16:11:33                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Span
{
	private:
		std::vector<int> v;
		unsigned int	 size;
		unsigned int	 shortest_span;
		unsigned int	 longest_span;

	public:
		explicit Span(void);
		explicit Span(unsigned int size_initer);
		Span(Span const &span);
		~Span(void);

		void	 addNumber(int n);
		unsigned shortestSpan(void);
		unsigned longestSpan(void);
};

#pragma GCC diagnostic pop
