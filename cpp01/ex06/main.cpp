/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 15:38:33                                            */
/*   Updated:  2023/12/04 18:54:34                                            */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

int main(int argc, char **argv)
{
	Harl		costumer;
	std::string level("");

	if (argc == 2)
	{
		level = argv[1];
		if (level != "INFO" && level != "DEBUG" && level != "WARNING")
		{
			level = "";
		}
	}
	switch (level.size())
	{
		case 5:
			costumer.complain("DEBUG");
			__attribute__((fallthrough));
		case 4:
			costumer.complain("INFO");
			__attribute__((fallthrough));
		case 7:
			costumer.complain("WARNING");
			__attribute__((fallthrough));
		default:
			costumer.complain("ERROR");
	}
}
