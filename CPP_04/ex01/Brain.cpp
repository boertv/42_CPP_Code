#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "someone grew a brain\n"; }

Brain::Brain(Brain const& src)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = src.ideas[i];
	}
	std::cout << "someone grew a brain\n";
}

Brain::~Brain() {
	std::cout << "someone's brain shriveled up\n"; }

Brain&	Brain::operator=(Brain const& rhs)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}
