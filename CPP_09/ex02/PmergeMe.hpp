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

	template<typename C>
	static void binary_insert(C container, int end_index, int to_add);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& rhs);
	PmergeMe(int const* numbers, int size);

	void do_vector() const;
	void do_list() const;

	template<typename C>
	static void merge_insert_sort(C container, int* old_pos = nullptr);
};

# include "PmergeMe.tpp"
#endif
