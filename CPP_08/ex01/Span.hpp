#ifndef SPAN_H
# define SPAN_H

#include <vector>

class Span
{
	std::vector<int>	_numbers;
	unsigned int		_max;

public:
	Span();
	Span(unsigned int N);
	Span(Span const& src);
	~Span();
	Span& operator=(Span const& rhs);

	void		addNumber(int nbr);
	void		addManyNumber(std::vector<int>::iterator const begin, std::vector<int>::iterator const end);
	std::size_t	shortestSpan();
	std::size_t	longestSpan() const;
};

#endif
