#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack() {}
	MutantStack(MutantStack const& src) { this->operator=(src); }
	~MutantStack() {}
	MutantStack& operator=(MutantStack const& src) { std::stack<T, Container>::operator=(src); return *this; }

	typedef typename Container::iterator iterator;
	typename Container::iterator begin() { return this->c.begin(); }
	typename Container::iterator end() { return this->c.end(); }
};

#endif
