#ifndef SORTITERATION_H
# define SORTITERATION_H

template <typename C>
class SortIteration
{
	C&		container;
	C		pair_sml;
	int*	new_pos;

	SortIteration();
	SortIteration(SortIteration const& src);
	SortIteration& operator=(SortIteration const& rhs);

	int insert_at_index(int index, int to_add);
	int binary_insert(int upper_index, int to_add);
	void loop_binary_insert(int lower_index, int upper_index, int upper_limit);

public:
	C		pair_big;
	int*	old_pos;

	~SortIteration();
	SortIteration(int size, C& container, int* new_pos);

	void create_pairs();
	void update_big_pos();
	void update_index_pos(int index_new, int index_old);
	void insert_pairs();
};

#include "SortIteration.tpp"
#endif
