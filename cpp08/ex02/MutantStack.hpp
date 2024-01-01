/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: MutantStack.hpp                                                */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/30 22:43:20                                            */
/*   Updated:  2023/12/30 23:01:18                                            */
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

#include <stack>

using std::stack;

template<typename T>
class MutantStack : public stack<T>
{
	public:
		typedef typename stack<T>::container_type::iterator				  iterator;
		typedef typename stack<T>::container_type::const_iterator		  const_iterator;
		typedef typename stack<T>::container_type::reverse_iterator		  reverse_iterator;
		typedef typename stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack(void);
		MutantStack(MutantStack const &ms);
		MutantStack &operator=(MutantStack const &ms);
		~MutantStack(void);

		iterator	   begin(void);
		const_iterator begin(void) const;
		iterator	   end(void);
		const_iterator end(void) const;
		iterator	   rbegin(void);
		const_iterator rbegin(void) const;
		iterator	   rend(void);
		const_iterator rend(void) const;
};

template<typename T>
MutantStack<T>::MutantStack(void)
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &ms) : stack<T>(ms)
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &ms)
{
	return (stack<T>::operator=(ms));
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}

#pragma GCC diagnostic pop
