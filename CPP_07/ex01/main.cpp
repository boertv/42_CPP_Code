#include "iter.hpp"
#include <iostream>

template <typename T>
void increment(T arg)
{ ++arg; }

template <typename T>
void print_arr(T* arr, std::size_t len)
{
	size_t i;
	std::cout << "{";
	for (i = 0; i + 1 < len; i++)
		std::cout << arr[i] << ", ";
	std::cout << arr[i] << "}";
}

int	main()
{
	{
		std::cout << "char\n";
		char str[] = "12345";
		std::cout << "before: '" << str << "'\n";
		iter(str, 5, increment);
		std::cout << " after: '" << str << "'\n";
		std::cout << "\n";
	}
	{
		std::cout << "int\n";
		int array[] = {1, 2, 3, 4, 5};
		std::cout << "before: "; print_arr(array, 5); std::cout << "\n";
		iter(array, 5, increment);
		std::cout << " after: "; print_arr(array, 5); std::cout << "\n";
		std::cout << "\n";
	}
	{
		std::cout << "double\n";
		double array[] = {1.5, 2.5, 3.5, 4.5, 5.5};
		std::cout << "before: "; print_arr(array, 5); std::cout << "\n";
		iter(array, 5, increment);
		std::cout << " after: "; print_arr(array, 5); std::cout << "\n";
		std::cout << "\n";
	}
}
