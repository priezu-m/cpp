/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   Filename: main.cpp                                                       */
/*   Author:   Peru Riezu <riezumunozperu@gmail.com>                          */
/*   github:   https://github.com/priezu-m                                    */
/*   Licence:  GPLv3                                                          */
/*   Created:  2023/12/28 14:16:07                                            */
/*   Updated:  2023/12/29 13:48:58                                            */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <string>

;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic warning "-Weverything"
#pragma GCC diagnostic ignored "-Wempty-translation-unit"
#pragma GCC diagnostic ignored "-Wunused-macros"
#pragma GCC diagnostic ignored "-Wextra-semi"
;

class Base
{
	public:
		virtual ~Base(void);
};

Base::~Base(void)
{
}

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

static Base *generate(void)
{
	Base *p;
	// NOLINTNEXTLINE
	unsigned int const i = rand();

	std::cout << i << std::endl;
	switch (i % 3)
	{
		case 0:
			p = new A();
			break;
		case 1:
			p = new B();
			break;
		case 2:
			p = new C();
			break;
	}
	// NOLINTNEXTLINE
	return (p);
}

static void identify(Base *p)
{
	std::cout << "*" << std::endl;
	if (dynamic_cast<A *>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

static void identify(Base &p)
{
	A a;
	B b;
	C c;

	std::cout << "&" << std::endl;
	try
	{
		a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception __attribute__((unused)) & e)
	{
	}
	try
	{
		b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception __attribute__((unused)) & e)
	{
	}
	try
	{
		c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception __attribute__((unused)) & e)
	{
	}
}

int main(void)
{
	Base *p;

	srand(time(NULL));
	p = generate();
	identify(p);
	identify(*p);
}

#pragma GCC diagnostic pop
