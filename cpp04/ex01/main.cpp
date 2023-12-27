/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/19 10:30:22                                            */
/*   Updated:  2023/12/19 20:11:49                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

int main(void)
{
	const size_t animal_arr_size = 2;
	Animal		*animal_arr[animal_arr_size];
	size_t		 i;

	if (animal_arr_size == 0)
	{
		return (EXIT_SUCCESS);
	}
	for (i = 0; i < animal_arr_size / 2; i++)
	{
		animal_arr[i] = new Dog;
	}
	for (; i < animal_arr_size; i++)
	{
		animal_arr[i] = new Cat;
	}
	for (i = 0; i < animal_arr_size / 2; i++)
	{
		delete static_cast<Dog *>(animal_arr[i]);
	}
	for (; i < animal_arr_size; i++)
	{
		delete static_cast<Cat *>(animal_arr[i]);
	}
}

#pragma GCC diagnostic pop
