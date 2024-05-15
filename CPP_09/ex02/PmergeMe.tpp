#ifdef PMERGEME_H
# ifndef PMERGEME_T
#  define PMERGEME_T

#  include "SortIteration.hpp"

// new_pos has to be a buffer that is at least container.size() big.
template<typename C>
void PmergeMe::merge_insert_sort(C& container, int* new_pos)
{
	if (container.size() == 1)
	{
		if (new_pos)
			new_pos[0] = 0;
		return ;
	}
	SortIteration<C> iteration(container.size() / 2, container, new_pos);
	iteration.create_pairs(container);
	merge_insert_sort(iteration.get_pair_big(), iteration.get_big_pos());
	iteration.update_big_pos();
	container = iteration.get_pair_big();
	iteration.insert_pairs();
}

template<typename C>
void PmergeMe::print_container(C const& container, std::string const& msg)
{
	std::cout << msg << "\t";
	for (typename C::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}

# endif
#endif
