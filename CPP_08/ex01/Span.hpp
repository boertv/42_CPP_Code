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

	size_t	size() const;
	void	addNumber(int nbr);
	void	addManyNumber(std::vector<int>::iterator const begin, std::vector<int>::iterator const end);
	size_t	shortestSpan();
	size_t	longestSpan() const;
};

#endif
