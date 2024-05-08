#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe() : input(nullptr), input_size(0) {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const& src) { this->operator=(src); }
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{ input = rhs.input; input_size = rhs.input_size; vector = rhs.vector; return *this; }

PmergeMe::PmergeMe(int const* numbers, int size)
	: input(numbers), input_size(size), vector(input, input + input_size) {}

/* MEMBER FUNCTIONS */
void PmergeMe::sort_vector()
{
	PmergeMe::merge_insert_sort(vector);
}

void PmergeMe::do_vector() const
{
	std::cout << "Time to process a range of " << input_size << " elements with std::[vector] : ";
	std::clock_t start_time = clock();
	{
		// do data managing and sorting
		std::vector<int> container(input, input + input_size);
		PmergeMe::merge_insert_sort(container);
	}
	std::cout << 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC << "ms\n";
}

void PmergeMe::do_list() const
{
	std::cout << "Time to process a range of " << input_size << " elements with std::[list] : ";
	std::clock_t start_time = clock();
	{
		// do data managing and sorting
		// might have to use seperate code for this after all ... (no operator[])
		std::list<int> container(input, input + input_size);
	}
	std::cout << 1000.0 * (clock() - start_time) / CLOCKS_PER_SEC << "ms\n";
}
