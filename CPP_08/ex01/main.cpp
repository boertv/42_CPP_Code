#include "Span.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "> add many numbers..\n";
		int	arr[] = {6, 3, 17, 9, 11};
		std::vector<int> ve;
		Span sp = Span(5);
		std::copy(arr, arr + 5, std::inserter(ve, ve.end()));
		try
		{
			sp.addNumber(9);
			sp.addNumber(16);
			sp.addManyNumber(ve.begin(), ve.end());
		}
		catch (std::exception const& e)
		{ std::cout << e.what() << " (" << sp.size() << ")\n"; }
		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";
		std::cout << "\n";
	}
	{
		std::cout << "> 100 000 numbers all up in there..\n";
		srand(time(0));
		Span sp(100000);
		try
		{
			while (true)
				sp.addNumber(rand());
		}
		catch (std::exception const& e)
		{ std::cout << e.what() << " (" << sp.size() << ")\n"; }
		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest : " << sp.longestSpan() << "\n";
	}
}
