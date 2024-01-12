/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2024/01/02 20:58:40                                            */
/*   Updated:  2024/01/03 04:48:19                                            */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <stack>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

typedef struct s_operation
{
		int	 lvalue;
		int	 rvalue;
		bool lvalue_set;
		bool rvalue_set;
		char operator_;
} t_operation;

static int resolve_operation(t_operation operaion)
{
	switch (operaion.operator_)
	{
		case '+':
		{
			return (operaion.lvalue + operaion.rvalue);
		}
		case '-':
		{
			return (operaion.lvalue - operaion.rvalue);
		}
		case '*':
		{
			return (operaion.lvalue * operaion.rvalue);
		}
		case '/':
		default:
		{
			return (operaion.lvalue / operaion.rvalue);
		}
	}
}

static int eval_inernal(std::stack<t_operation> &stack, std::string const &expr, size_t i)
{
	int			val;
	t_operation aux;

	aux.lvalue_set = false;
	aux.rvalue_set = false;
	while (true)
	{
		if ((stack.top().lvalue_set == true) && (stack.top().rvalue_set == true))
		{
			if (stack.size() == 1)
			{
				if (i != 0)
				{
					throw(0);
				}
				return (resolve_operation(stack.top()));
			}
			val = resolve_operation(stack.top());
			stack.pop();
			if (stack.top().rvalue_set == false)
			{
				stack.top().rvalue_set = true;
				stack.top().rvalue = val;
			}
			else
			{
				stack.top().lvalue_set = true;
				stack.top().lvalue = val;
			}
			continue;
		}
		if (i == 0)
		{
			throw(0);
		}
		if (isdigit(expr[i - 1]) == 0)
		{
			aux.operator_ = expr[i - 1];
			stack.push(aux);
			i--;
			continue;
		}
		if (stack.top().rvalue_set == false)
		{
			stack.top().rvalue_set = true;
			stack.top().rvalue = expr[i - 1] - '0';
			i--;
			continue;
		}
		stack.top().lvalue_set = true;
		stack.top().lvalue = expr[i - 1] - '0';
		i--;
	}
}

static int eval(std::string const &expr)
{
	size_t					i = expr.length();
	t_operation				aux;
	std::stack<t_operation> stack;

	if ((i == 0) && isdigit(expr[i - 1]) != 0)
	{
		return (expr[i - 1] - '0');
	}
	aux.operator_ = expr[i - 1];
	aux.lvalue_set = false;
	aux.rvalue_set = false;
	stack.push(aux);
	i--;
	if (isdigit(stack.top().operator_) != 0)
	{
		throw(std::exception());
	}
	return (eval_inernal(stack, expr, i));
}

int main(int argc, char **argv)
{
	std::string string;

	if (argc == 2)
	{
		try
		{
			string = argv[1];
			string.erase(std::remove_if(string.begin(), string.end(), isspace), string.end());
			if (string.empty())
			{
				std::cout << "empty expression\n";
				return (EXIT_FAILURE);
			}
			for (size_t i = 0; i < string.length(); i++)
			{
				bool table[UCHAR_MAX];

				memset(table, static_cast<int>(true), UCHAR_MAX);
				memset(&table[static_cast<unsigned>('0')], static_cast<int>(false), 10);
				table[static_cast<unsigned>('-')] = false;
				table[static_cast<unsigned>('+')] = false;
				table[static_cast<unsigned>('*')] = false;
				table[static_cast<unsigned>('/')] = false;
				if (table[static_cast<unsigned char>(string[i])] == true)
				{
					std::cout << "allowed characters are \"0123456789+-*/\"\n";
					return (EXIT_FAILURE);
				}
			}
			std::cout << eval(string) << '\n';
		}
		catch (std::bad_alloc const &)
		{
			std::cerr << "program ran out of memory\n";
		}
		catch (...)
		{
			std::cerr << "Error\n";
		}
	}
	else
	{
		std::cout << "program must recive a single argument\n";
	}
	return (EXIT_SUCCESS);
}

#pragma GCC diagnostic pop
