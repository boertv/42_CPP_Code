#ifdef SORTITERATION_H
# ifndef SORTITERATION_T
#  define SORTITERATION_T

/* CONSTRUCTORS */
template<typename C>
SortIteration<C>::SortIteration()
	: new_pos(NULL), big_pos(NULL), sml_pos(NULL) {}

template<typename C>
SortIteration<C>::~SortIteration()
{
	delete [] big_pos;
	delete [] sml_pos;
}

template<typename C>
SortIteration<C>::SortIteration(int size, C& container, int* new_pos)
	: container(container), pair_big(size), pair_sml(size), new_pos(new_pos)
{
	big_pos = new int[size];
	sml_pos = new int[size + container.size() % 2];
}

template<typename C>
SortIteration<C>::SortIteration(SortIteration<C> const& src)
{
	big_pos = new int[src.pair_big.size()];
	sml_pos = new int[src.pair_sml.size()];
	this->operator=(src);
}

template<typename C>
SortIteration<C>& SortIteration<C>::operator=(SortIteration<C> const& rhs)
{
	container = rhs.container;
	pair_big = rhs.pair_big;
	pair_sml = rhs.pair_sml;
	for (size_t i = 0; i < pair_big.size() + pair_sml.size(); ++i)
		new_pos[i] = rhs.new_pos[i];
	for (size_t i = 0; i < pair_big.size(); ++i)
		big_pos[i] = rhs.big_pos[i];
	for (size_t i = 0; i < pair_sml.size(); ++i)
		sml_pos[i] = rhs.sml_pos[i];
	return *this;
}

/* GETTERS */
template<typename C>
int* SortIteration<C>::get_big_pos()
{ return big_pos; }

template<typename C>
C& SortIteration<C>::get_pair_big()
{ return pair_big; }

/* STATIC MEMBERS */
template<typename C>
int SortIteration<C>::at(std::vector<int> const& container, int index)
{
	return container[index];
}

// list specialization
template<typename C>
int SortIteration<C>::at(std::list<int> const& container, int index)
{
	std::list<int>::const_iterator it = container.begin();
	std::advance(it, index);
	return *it;
}

/* MEMBER FUNCTIONS */
template<typename C>
void SortIteration<C>::create_pairs(std::vector<int> const& type)
{
	(void)type;
	for (std::size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			pair_big[i / 2] = container[i];
			pair_sml[i / 2] = container[i + 1];
			if (new_pos)
			{
				new_pos[i / 2] = i;
				sml_pos[i / 2] = i + 1;
			}
		}
		else
		{
			pair_big[i / 2] = container[i + 1];
			pair_sml[i / 2] = container[i];
			if (new_pos)
			{
				new_pos[i / 2] = i + 1;
				sml_pos[i / 2] = i;
			}
		}
	}
	if (container.size() % 2)
	{
		pair_sml.push_back(container.back());
		sml_pos[pair_sml.size() - 1] = container.size() - 1;
	}
}

// list specialization
template<typename C>
void SortIteration<C>::create_pairs(std::list<int> const& type)
{
	(void)type;
	std::list<int>::const_iterator cont_it = container.begin();
	std::list<int>::iterator big_it = pair_big.begin();
	std::list<int>::iterator sml_it = pair_sml.begin();
	for (std::size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (*cont_it > *(std::next(cont_it)))
		{
			*big_it = *cont_it;
			*sml_it = *(std::next(cont_it));
			if (new_pos)
			{
				new_pos[i / 2] = i;
				sml_pos[i / 2] = i + 1;
			}
		}
		else
		{
			*big_it = *(std::next(cont_it));
			*sml_it = *cont_it;
			if (new_pos)
			{
				new_pos[i / 2] = i + 1;
				sml_pos[i / 2] = i;
			}
		}
		std::advance(cont_it, 2);
		std::advance(big_it, 1);
		std::advance(sml_it, 1);
	}
	if (container.size() % 2)
	{
		pair_sml.push_back(container.back());
		sml_pos[pair_sml.size() - 1] = container.size() - 1;
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
		new_pos[i] = swap[big_pos[i]];
}

template<typename C>
void SortIteration<C>::update_index_pos(int index_new, int sml_index)
{
	if (!new_pos)
		return ;
	for (int i = container.size() - 1; i > index_new; --i)
		new_pos[i] = new_pos[i - 1];
	new_pos[index_new] = sml_pos[sml_index];
}

template<typename C>
int SortIteration<C>::insert_at_index(int index, int to_add)
{
	typename C::iterator it = container.begin();
	std::advance(it, index);
	container.insert(it, to_add);
	return index;
}

// returns the index used to insert to_add
template<typename C>
int SortIteration<C>::binary_insert(int upper_limit, int to_add)
{
	int lower_limit = 0;
	while (lower_limit != upper_limit)
	{
		if (at(container, ((upper_limit - lower_limit) / 2) + lower_limit) == to_add)
			return insert_at_index((upper_limit - lower_limit) / 2 + lower_limit + 1, to_add);
		if (at(container, ((upper_limit - lower_limit) / 2) + lower_limit) > to_add)
		{
			upper_limit = ((upper_limit - lower_limit) / 2) + lower_limit - 1;
			if (lower_limit > upper_limit)
				return insert_at_index(lower_limit, to_add);
		}
		else
		{
			lower_limit = ((upper_limit - lower_limit) / 2) + lower_limit + 1;
			if (lower_limit > upper_limit)
				return insert_at_index(upper_limit, to_add);
		}
	}
	if (at(container, lower_limit) > to_add)
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
		int insert_index;
		if (pair_sml.size() > pair_big.size())
		{
			insert_index = binary_insert(upper_limit, pair_sml.back());
			update_index_pos(insert_index, pair_sml.size() - 1);
		}
		else
		{
			insert_index = binary_insert(upper_limit, at(pair_sml, big_pos[pair_big.size() - 1]));
			update_index_pos(insert_index, big_pos[pair_big.size() - 1]);
		}
		if (insert_index > upper_limit)
			--upper_limit;
	}
	for (; upper_index >= lower_index; --upper_index)
	{
		int insert_index = binary_insert(upper_limit, at(pair_sml, big_pos[upper_index]));
		if (insert_index > upper_limit)
			--upper_limit;
		update_index_pos(insert_index, big_pos[upper_index]);
	}
}

template<typename C>
void SortIteration<C>::insert_pairs()
{
	std::size_t	amount_done = 1;
	int			old_increment = 1;
	int			increment = 2;

	container.insert(container.begin(), at(pair_sml, big_pos[0]));
	update_index_pos(0, big_pos[0]);

	while (amount_done < pair_sml.size())
	{
		loop_binary_insert(amount_done, amount_done + increment - 1, amount_done * 2 + increment - 2);
		amount_done += increment;
		int temp = increment;
		increment = old_increment * 2 + increment;
		old_increment = temp;
	}
}

# endif
#endif
