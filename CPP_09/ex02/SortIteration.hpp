#ifndef SORTITERATION_H
# define SORTITERATION_H

template <typename C>
class SortIteration
{
	C&		container;
	C		pair_sml;
	int*	new_pos;
	int*	sml_pos;

	SortIteration();
	SortIteration(SortIteration const& src);
	SortIteration& operator=(SortIteration const& rhs);

	static int at(std::vector<int> const& container, int index);
	static int at(std::list<int> const& container, int index);
	int insert_at_index(int index, int to_add);
	int binary_insert(int upper_index, int to_add);
	void loop_binary_insert(int lower_index, int upper_index, int upper_limit);
	void update_index_pos(int index_new, int index_old);

public:
	C		pair_big;
	int*	big_pos;

	~SortIteration();
	SortIteration(int size, C& container, int* new_pos);

	void create_pairs(std::vector<int> const& type);
	void create_pairs(std::list<int> const& type);
	void update_big_pos();
	void insert_pairs();
};

#include "SortIteration.tpp"
#endif
