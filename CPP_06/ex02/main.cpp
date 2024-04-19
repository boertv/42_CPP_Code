#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	static bool	first_run = false;

	if (!first_run)
	{
		first_run = true;
		srand(time(0));
	}
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return nullptr;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A const*>(p))
		return (void)(std::cout << "A\n");
	if (dynamic_cast<B const*>(p))
		return (void)(std::cout << "B\n");
	if (dynamic_cast<C const*>(p))
		return (void)(std::cout << "C\n");
}

void	identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A const&>(p);
		return (void)(std::cout << "A\n");
	}
	catch (...)
	{}
	try
	{
		(void) dynamic_cast<B const&>(p);
		return (void)(std::cout << "B\n");
	}
	catch (...)
	{}
	try
	{
		(void) dynamic_cast<C const&>(p);
		return (void)(std::cout << "C\n");
	}
	catch (...)
	{}
}

static void id_both(Base* p)
{
	std::cout << "p is of ptr type ";
	identify(p);
	std::cout << "p is of ref type ";
	identify(*p);
	delete p;
}

int	main()
{
	Base*	p;

	std::cout << "BASELINE TESTS:\n";
	p = new A;
	id_both(p);
	p = new B;
	id_both(p);
	p = new C;
	id_both(p);

	std::cout << "\n RANDOM TESTS:\n";
	for(int i = 0; i < 10; i++)
	{
		p = generate();
		id_both(p);
	}
}
