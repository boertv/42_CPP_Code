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

// EXAMPLE
/*
input:
Container:	9 5 6 7 2 3
new_pos:	_ _ _ _ _ _

> Separate container in two, bigger and smaller of pairs and keep track of their positions

pair_big:	9 7 3
new_pos:	0 3 5 _ _ _	(keeping track in new_pos because that is where it will end up anyways)

pair_sml:	5 6 2
sml_pos:	1 2 4

> Sort the container of the bigger elements

		before:		sorted:
pair_big:	9 7 3		->	3 7 9
big_pos:	0 1 2		->	2 1 0

> update the positions of the bigger elements

		before:		sorted:
new_pos:	0 3 5 _ _ _	->	5 3 0 _ _ _

> input container = container of sorted bigger elements
> insert everything from the container of smaller elements

Container:
	Insert 1:
	container	-> 2 3 7 9
	new_pos	-> 4 5 3 0 _ _

	the rest:
	container	-> 2 3 5 6 7 9		(9 5 6 7 2 3)
	new_pos	-> 4 5 1 2 3 0		(0 1 2 3 4 5)
*/
