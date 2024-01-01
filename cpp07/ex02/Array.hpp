/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: Array.hpp                                                      */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/29 13:55:47                                            */
/*   Updated:  2023/12/29 18:00:27                                            */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stddef.h>
#include <stdexcept>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

template<typename T>
class Array
{
	private:
		T	  *array;
		size_t size;

	public:
		Array(void);
		explicit Array(unsigned n);
		Array(Array const &array_init);
		const Array &operator=(const Array &array_init);
		~Array(void);

		T &operator[](size_t i);
};

template<class T>
Array<T>::Array(void)
	: array(NULL), size(0)
{
}

template<class T>
Array<T>::Array(unsigned n)
	: array(new int[n]), size(n)
{
}

template<class T>
Array<T>::Array(Array const &array_init)
	: array(new int[array_init.size]), size(array_init.size)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = array_init.array[i];
	}
}

template<class T>
Array<T>::~Array(void)
{
	delete[] array;
}

template<class T>
T &Array<T>::operator[](size_t i)
{
	if (i >= size)
	{
		throw (std::out_of_range("attempt to access element outside the bounds of the array"));
	}
	return (array[i]);
}

template<class T>
const Array<T> &Array<T>::operator=(const Array<T> &array_init)
{
	if (this == &array_init)
	{
		return (*this);
	}
	if (size != array_init.size)
	{
		delete [] array;
		size = array_init.size;
		array = new int[size];
	}
	for (size_t i = 0; i < size; i++)
	{
		array[i] = array_init[i];
	}
}
#pragma GCC diagnostic pop
