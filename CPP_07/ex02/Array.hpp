#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
	T*		_ptr;
	size_t	_size;
public:
	Array();
	Array(unsigned int n);
	Array(Array const& src);
	~Array();
	Array& operator=(Array const& rhs);
	T& operator[](size_t i) const;

	size_t size() const;
};

# include "Array.tpp"

#endif
