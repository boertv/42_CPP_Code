#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>

class PmergeMe
{
	int const*	input;
	int			input_size;

	PmergeMe();
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& rhs);

	template<typename C>
	static void print_container(C const& container, std::string const& msg);
	template<typename C>
	static void merge_insert_sort(C& container, int* new_pos = NULL);

public:
	~PmergeMe();
	PmergeMe(int const* const numbers, int size);

	void do_sort_print() const;
	void do_vector() const;
	void do_list() const;
};

# include "PmergeMe.tpp"
#endif
