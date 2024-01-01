/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Span.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/30 15:51:05                                            */
/*   Updated:  2023/12/30 22:20:55                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>
#include <limits.h>
#include <stdexcept>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

Span::Span(void) : size(0), shortest_span(UINT_MAX), longest_span(0)
{
}

Span::Span(unsigned int size_initer) : size(size_initer), shortest_span(UINT_MAX), longest_span(0)
{
	v.reserve(size);
}

Span::Span(Span const &span)
	: v(span.v), size(span.size), shortest_span(span.shortest_span), longest_span(span.longest_span)
{
}

Span::~Span(void)
{
}

static unsigned int abs_internal(int n)
{
	if (n < 0)
	{
		return (static_cast<unsigned int>(-n));
	}
	return (static_cast<unsigned int>(n));
}

void Span::addNumber(int n)
{
	if (v.size() < size)
	{
		v.push_back(n);
		if (v.size() > 1)
		{
			shortest_span = std::min(abs_internal(v[v.size() - 1] - v[v.size() - 2]), shortest_span);
			longest_span = std::max(abs_internal(v[v.size() - 1] - v[v.size() - 2]), longest_span);
		}
		return;
	}
	throw(std::range_error("Attempt to add an element beyond the amount that can be hold"));
}

unsigned int Span::shortestSpan(void)
{
	if (v.size() < 2)
	{
		throw(std::logic_error("Span between less than two elemenst is not defined"));
	}
	return (shortest_span);
}

unsigned int Span::longestSpan(void)
{
	if (v.size() < 2)
	{
		throw(std::logic_error("Span between less than two elemenst is not defined"));
	}
	return (longest_span);
}

#pragma GCC diagnostic pop
