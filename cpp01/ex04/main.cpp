/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/04 03:39:04                                            */
/*   Updated:  2024/01/23 08:11:58                                            */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

static std::string get_file_contents(char const *filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);

	if (in.fail() == true)
	{
		throw(std::exception());
	}
	in.exceptions(~static_cast<std::ios_base::iostate>(0)); // throw whit all exceptions found
	std::string contents;
	in.seekg(0, std::ios::end);
	contents.resize(static_cast<size_t>(in.tellg()));
	in.seekg(0, std::ios::beg);
	in.read(&contents[0], static_cast<std::streamsize>(contents.size()));
	in.close();
	return (contents);
}

static void write_to_file(std::string const &name, std::string const &content)
{
	std::ofstream out(name.c_str());

	if (out.fail() == true)
	{
		throw(std::exception());
	}
	out << content;
	out.close();
}

static void do_substitutions(char **argv)
{
	std::string in(get_file_contents(argv[1]));
	std::string find(argv[2]);
	std::string replace(argv[3]);
	size_t		pos;

	if (find == replace)
	{
		write_to_file(std::string(argv[1]).append(".replace"), in);
		return;
	}
	pos = in.find(find);
	while (pos != std::string::npos)
	{
		in.erase(pos, find.size());
		in.insert(pos, replace);
		pos = in.find(find);
	}
	write_to_file(std::string(argv[1]).append(".replace"), in);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of parameters, expected 3, given " << argc - 1 << '\n';
		return (EXIT_FAILURE);
	}
	try
	{
		do_substitutions(argv);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << ", aborting\n";
	}
}

#pragma GCC diagnostic pop
