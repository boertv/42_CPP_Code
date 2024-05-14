#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "> stack..\n";
	MutantStack<int> mstack;
	mstack.push(0);
	mstack.push(42);
	std::cout << "top value: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	for (int i = 1; i <= 19; ++i)
		mstack.push(i);
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "\n";
		std::stack<int> s(mstack);
	}
	std::cout << "\n";

	std::cout << "> list..\n";
	{
		std::list<int> lstack;
		lstack.push_back(0);
		lstack.push_back(42);
		std::cout << "top value: " << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << "size: " << lstack.size() << std::endl;
		for (int i = 1; i <= 19; ++i)
			lstack.push_back(i);
		{
			std::list<int>::iterator it = lstack.begin();
			std::list<int>::iterator ite = lstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
			std::cout << "\n";
		}
	}
	std::cout << "\n";

	std::cout << "swapping container..\n";
	MutantStack<int> swapper;
	swapper.push(0); swapper.push(42);
	std::cout << "size and top value before swap: " << mstack.size() << ", " << mstack.top() << "\n";
	mstack.swap(swapper);
	std::cout << "size and top value after swap:  " << mstack.size() << ", " << mstack.top() << "\n";
}
