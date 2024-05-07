#ifndef SORTITERATION_H
# define SORTITERATION_H

template <typename C>
class SortIteration
{
	C	pair_big;
	C	pair_sml;
	int	old_pos[];

public:
	SortIteration();
	~SortIteration();
	SortIteration(int size);
	SortIteration(SortIteration const& src);
	SortIteration& operator=(SortIteration const& rhs);
};

#include "SortIteration.tpp"
#endif
