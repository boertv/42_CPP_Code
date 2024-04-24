#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

template <typename T>
void	print_container(T container)
{
	typename T::iterator it;
	std::cout << "{";
	for (it = container.begin(); std::next(it, 1) != container.end(); it++)
		std::cout << *it << ", ";
	std::cout << *it << "}\n";
}

template <typename T>
void	write_on_iterator(T const& it, T const& last, int const& value)
{
	if (it != last)
		*it = value;
}

int main()
{
	{
		std::vector<int> v(5);
		std::cout << "vector..\n";
		v[0] = 1; v[1] = 0; v[2] = 3; v[3] = 0; v[4] = 5;
		std::cout << "found " << *(easyfind(v, 0)) << " at index " << easyfind(v, 0) - v.begin() << "\n";
		std::cout << "found " << *(easyfind(v, 5)) << " at index " << easyfind(v, 5) - v.begin() << "\n";
		print_container(v);
		write_on_iterator(easyfind(v, 0), v.end(), 2);
		write_on_iterator(easyfind(v, 0), v.end(), 4);
		write_on_iterator(easyfind(v, 0), v.end(), 19);
		print_container(v);
		std::cout << "\n";
	}
	{
		std::cout << "deque..\n";
		std::deque<int> d(5);
		d[0] = 1; d[1] = 0; d[2] = 3; d[3] = 0; d[4] = 5;
		print_container(d);
		write_on_iterator(easyfind(d, 0), d.end(), 2);
		write_on_iterator(easyfind(d, 0), d.end(), 4);
		write_on_iterator(easyfind(d, 42), d.end(), 19);
		print_container(d);
		std::cout << "\n";
	}
	{
		std::cout << "list..\n";
		std::list<int> l(10);
		print_container(l);
		write_on_iterator(easyfind(l, 0), l.end(), 1);
		write_on_iterator(easyfind(l, 0), l.end(), 2);
		write_on_iterator(easyfind(l, 0), l.end(), 3);
		print_container(l);
		std::cout << "\n";
	}
}
