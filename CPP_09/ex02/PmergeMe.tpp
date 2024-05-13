#include "PmergeMe.hpp"
#include "SortIteration.hpp"
// can delete this include .. it's just for vscode (i think)

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
//test
// print_container(iteration.pair_big, " pre sort:");
	merge_insert_sort(iteration.pair_big, iteration.big_pos);
//test
// print_container(iteration.pair_big, " post sort:");
// std::cout << "ppost sort:\t";
// for (size_t i = 0; i < iteration.pair_big.size(); ++i)
// std::cout << iteration.big_pos[i] << " ";
// std::cout << "\n";
	iteration.update_big_pos();
	container = iteration.pair_big;
	iteration.insert_pairs();
}

template<typename C>
void PmergeMe::print_container(C const& container, std::string msg)
{
	std::cout << msg << "\t";
	for (typename C::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}
