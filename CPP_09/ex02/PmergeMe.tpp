#include "PmergeMe.hpp"
// can delete this include .. it's just for vscode

template<typename C>
static int insert_at_index(C container, int index, int to_add)
{
	container.insert(container + index, to_add);
	return index;
}

// returns the index used to insert to_add
template<typename C>
int binary_insert(C container, int end_index, int to_add)
{
	int start_index = 0;
	while (start_index != end_index)
	{
		if (container[((end_index - start_index) / 2) + start_index] == to_add)
			return insert_at_index(container, (end_index - start_index) / 2 + start_index, to_add);
		if (container[((end_index - start_index) / 2) + start_index] > to_add)
		{
			start_index = ((end_index - start_index) / 2) + start_index + 1;
			if (start_index > end_index)
				return insert_at_index(container, end_index, to_add);
		}
		else if (container[((end_index - start_index) / 2) + start_index] < to_add)
		{
			end_index = ((end_index - start_index) / 2) + start_index - 1;
			if (end_index < start_index)
				return insert_at_index(container, start_index, to_add);
		}
	}
	if (container[start_index] > to_add)
		return insert_at_index(container, start_index, to_add);
	else
		return insert_at_index(container, start_index + 1, to_add);
}

static void update_big_pos(int const* old_pos, int current_size, int* new_pos)
{
	if (!new_pos)
		return ;
	int swap[current_size];
	for (int i = 0; i < current_size; ++i)
		swap[i] = new_pos[i];
	for (int i = 0; i < current_size; ++i)
		new_pos[i] = swap[old_pos[i]];
}

static void update_index_pos(int* new_pos, int index_new, int index_old)
{
	if (!new_pos)
		return ;
	int swap = new_pos[index_old];
	for (int i = index_old; i > index_new; --i)
		new_pos[i] = new_pos[i - 1];
	new_pos[index_new] = swap;
}

// template<typename C>
// static void loop_binary_insert(C container, int* new_pos, int const* old_pos)
// {
// }

// new_pos has to be a buffer that is at least container.size() big.
template<typename C>
void PmergeMe::merge_insert_sort(C container, int* new_pos)
{
	if (container.size() == 1)
	{
		if (new_pos)
			new_pos[0] = 0;
		return ;
	}
	// somehow keep track of the elements in new_pos
	C	pair_big(container.size() / 2);
	C	pair_sml(container.size() / 2);
	int	old_pos[container.size() / 2];

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
	if (container.size() % 1)
		pair_sml.insert(pair_sml.end(), *(container.rbegin()))
	merge_insert_sort(pair_big, old_pos);
	update_big_pos(old_pos, new_pos);
	container = pair_big;
	container.insert(container.begin(), pair_sml[old_pos[0]]);
	update_index_pos(new_pos, 0, pair_big.size() + old_pos[0]);
	// binary_insert
	// don't forget potential last solo element at the end of pair_sml
}
