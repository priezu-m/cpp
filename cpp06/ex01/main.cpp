/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/28 14:16:07                                            */
/*   Updated:  2023/12/29 13:27:05                                            */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <math.h>
#include <stdint.h>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Data
{
	public:
		std::string info;
		std::string info2;

		Data(void);
		Data(const std::string &info_init, const std::string &info2_init);
		Data(const Data &data);
		~Data(void);
};

Data::Data()
{
}

Data::Data(const std::string &info_init, const std::string &info2_init)
	: info(info_init), info2(info2_init)
{
}

Data::Data(const Data &data)
	: info(data.info), info2(data.info2)
{
}

Data::~Data()
{
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data data("hola\n", "prueba\n");

	std::cout << Serializer::deserialize(Serializer::serialize(&data))->info;
	std::cout << Serializer::deserialize(Serializer::serialize(&data))->info2;
}

#pragma GCC diagnostic pop
