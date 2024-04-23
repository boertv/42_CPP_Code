#ifndef ITER_H
# define ITER_H

# include <cstddef>

template <typename T>
void iter(T* address, std::size_t const len, void mod(T& el))
{
	for (std::size_t i = 0; i < len; i++)
	{
		mod(address[i]);
	}
}

#endif
