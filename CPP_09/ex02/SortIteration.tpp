#include "SortIteration.hpp"
// can delete this include .. it's just for vscode

/* CONSTRUCTORS */
template<typename C>
SortIteration<C>::SortIteration() {}

template<typename C>
SortIteration<C>::~SortIteration() {}

template<typename C>
SortIteration<C>::SortIteration(int size) : pair_big(size), pair_sml(size), old_pos[size] {}

template<typename C>
SortIteration<C>::SortIteration(SortIteration<C> const& src) { this->operator=(src); }

template<typename C>
SortIteration<C>& SortIteration<C>::operator=(SortIteration<C> const& rhs) { return *this; }

/* MEMBER FUNCTIONS */
