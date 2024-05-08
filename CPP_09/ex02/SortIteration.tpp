#include "SortIteration.hpp"
// can delete this include .. it's just for vscode

/* CONSTRUCTORS */
template<typename C>
SortIteration<C>::SortIteration() {}

template<typename C>
SortIteration<C>::~SortIteration()
{
	delete [] old_pos;
}

template<typename C>
SortIteration<C>::SortIteration(int size, C& container, int* new_pos)
	: container(container), pair_sml(size), new_pos(new_pos), pair_big(size)
{
	old_pos = new int[size];
}

template<typename C>
SortIteration<C>::SortIteration(SortIteration<C> const& src) : old_pos(nullptr) { this->operator=(src); }

template<typename C>
SortIteration<C>& SortIteration<C>::operator=(SortIteration<C> const& rhs)
{
	container = rhs.container;
	pair_big = rhs.pair_big;
	pair_sml = rhs.pair_sml;
	new_pos = rhs.new_pos;
	delete [] old_pos;
	old_pos = rhs.old_pos;
	return *this;
}

/* MEMBER FUNCTIONS */
template<typename C>
void SortIteration<C>::create_pairs()
{
	for (std::size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			pair_big[i / 2] = container[i];
			pair_sml[i / 2] = container[i + 1];
			if (new_pos)
			{
				new_pos[i / 2] = i;
				new_pos[pair_big.size() + i / 2] = i + 1;
			}
		}
		else
		{
			pair_big[i / 2] = container[i + 1];
			pair_sml[i / 2] = container[i];
			if (new_pos)
			{
				new_pos[i / 2] = i + 1;
				new_pos[pair_big.size() + i / 2] = i;
			}
		}
	}
	if (container.size() % 2)
	{
		pair_sml.push_back(container.back());
		if (new_pos)
			new_pos[container.size() - 1] = container.size() - 1;
	}
}

template<typename C>
void SortIteration<C>::update_big_pos()
{
	if (!new_pos)
		return ;

	int swap[pair_big.size()];
	for (std::size_t i = 0; i < pair_big.size(); ++i)
		swap[i] = new_pos[i];

	for (std::size_t i = 0; i < pair_big.size(); ++i)
		new_pos[i] = swap[old_pos[i]];
}

template<typename C>
void SortIteration<C>::update_index_pos(int index_new, int index_old)
{
	if (!new_pos)
		return ;
	int swap = new_pos[index_old];
	for (int i = index_old; i > index_new; --i)
		new_pos[i] = new_pos[i - 1];
	new_pos[index_new] = swap;
}

template<typename C>
int SortIteration<C>::insert_at_index(int index, int to_add)
{
//test
// std::cout << " inserting " << to_add << " at index " << index; PmergeMe::print_container(container, " in");
	typename C::iterator it = container.begin();
	std::advance(it, index);
	container.insert(it, to_add);
	return index;
}

// returns the index used to insert to_add
template<typename C>
int SortIteration<C>::binary_insert(int upper_limit, int to_add)
{
//test
// std::cout << "with upper_limit " << upper_limit;
	int lower_limit = 0;
	while (lower_limit != upper_limit)
	{
		if (container[((upper_limit - lower_limit) / 2) + lower_limit] == to_add)
			return insert_at_index((upper_limit - lower_limit) / 2 + lower_limit + 1, to_add);
		if (container[((upper_limit - lower_limit) / 2) + lower_limit] > to_add)
		{
			upper_limit = ((upper_limit - lower_limit) / 2) + lower_limit - 1;
			if (lower_limit > upper_limit)
				return insert_at_index(lower_limit, to_add);
		}
		else
		{
			lower_limit = ((upper_limit - lower_limit) / 2) + lower_limit + 1;
			if (lower_limit > upper_limit) // i don't think this ever happens?
				return insert_at_index(upper_limit, to_add);
		}
	}
	if (container[lower_limit] > to_add)
		return insert_at_index(lower_limit, to_add);
	else
		return insert_at_index(lower_limit + 1, to_add);
}

template<typename C>
void SortIteration<C>::loop_binary_insert(int lower_index, int upper_index, int upper_limit)
{
	if (static_cast<std::size_t>(upper_index) >= pair_sml.size() - 1)
	{
		upper_limit = container.size() - 1;
		upper_index = pair_sml.size() - 2;
		int insert_index = binary_insert(upper_limit, pair_sml.back());
		if (insert_index == upper_limit)
			--upper_limit;
		this->update_index_pos(insert_index, pair_big.size() + pair_sml.size() - 1);
	}
//test
// std::cout << "binary insert loop from " << upper_index << " to " << lower_index << "\n";
	for (; upper_index >= lower_index; --upper_index)
	{
		int insert_index = binary_insert(upper_limit, pair_sml[old_pos[upper_index]]);
		if (insert_index == upper_limit)
			--upper_limit;
		this->update_index_pos(insert_index, pair_big.size() + old_pos[upper_index]);
	}
}

template<typename C>
void SortIteration<C>::insert_pairs()
{
	std::size_t amount_done = 1;
	int			old_increment = 1;
	int			increment = 2;
//test
PmergeMe::print_container(container, "pre insert:");
PmergeMe::print_container(pair_sml, "inserting:");
std::cout << "old_pos:\t";
for (size_t i = 0; i < pair_big.size(); ++i)
std::cout << old_pos[i] << " ";
std::cout << "\n";

	container.insert(container.begin(), pair_sml[old_pos[0]]);
	update_index_pos(0, pair_big.size() + old_pos[0]);

	while (amount_done < pair_sml.size())
	{
		loop_binary_insert(amount_done, amount_done + increment - 1, amount_done * 2 + increment - 2);
		amount_done += increment;
		int temp = increment;
		increment = old_increment * 2 + increment;
		old_increment = temp;
	}
//test
PmergeMe::print_container(container, "post insert:");
}
