#include "Span.hpp"
#include <algorithm>

Span::Span() : _numbers(std::vector<int>()), _max(100) {}
Span::Span(unsigned int N) : _numbers(std::vector<int>()), _max(N) {}
Span::Span(Span const& src) { this->operator=(src); }
Span::~Span() {}
Span& Span::operator=(Span const& rhs)
{
	_numbers = rhs._numbers;
	_max = rhs._max;
	return *this;
}

void Span::addNumber(int nbr)
{
	if (_numbers.size() >= _max)
		throw (std::length_error("Span is at maximum capacity"));
	_numbers.push_back(nbr);
}

void Span::addManyNumber(std::vector<int>::iterator const begin, std::vector<int>::iterator const end)
{
	if (_numbers.size() >= _max)
		throw (std::length_error("Span is at maximum capacity"));
	std::vector<int>::iterator copy_end = end;
	if (end - begin + _numbers.size() > _max)
		copy_end -= (end - begin) - (_max - _numbers.size());
	_numbers.insert(_numbers.end(), begin, copy_end);
	if (copy_end != end)
		throw (std::length_error("Span is at maximum capacity"));
}

std::size_t Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw (std::range_error("not enough numbers for this operation"));
	return static_cast<size_t>(*(std::max_element(_numbers.begin(), _numbers.end())))
		- static_cast<size_t>(*(std::min_element(_numbers.begin(), _numbers.end())));
}

std::size_t Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw (std::range_error("not enough numbers for this operation"));
	std::sort(_numbers.begin(), _numbers.end());
	std::size_t result = static_cast<size_t>(*(_numbers.rbegin())) - static_cast<size_t>(*(std::next(_numbers.rbegin())));
	for (std::vector<int>::reverse_iterator rit = std::next(_numbers.rbegin()); std::next(rit) != _numbers.rend(); ++rit)
	{
		result = std::min<size_t>(result, static_cast<size_t>(*rit) - static_cast<size_t>(*(std::next(rit))));
		if (!result)
			return 0;
	}
	return result;
}
