#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>

class PmergeMe
{
	int const*			input;
	int					input_size;

	template<typename C>
	static void merge_insert_sort(C& container, int* big_pos = NULL);

public:
	std::vector<int>	vector;

	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& rhs);
	PmergeMe(int const* numbers, int size);

	template<typename C>
	static void print_container(C const& container, std::string msg);
	void sort_vector();
	void do_vector() const;
	void do_list() const;
};

# include "PmergeMe.tpp"
#endif
