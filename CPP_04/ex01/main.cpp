#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	{
		std::cout << "DEEP COPY TEST\n";
		const Animal* j = new Dog();
		const Animal* cpy = new Dog(*(Dog *)(j));
		delete cpy;
		delete j;
		std::cout << '\n';
	}

	{
		std::cout << "THE ARRAY\n";
		Animal*	arr[4];
		for(int i = 0; i < 2; i++)
			arr[i] = new Dog();
		for(int i = 2; i < 4; i++)
			arr[i] = new Cat();
		for(int i = 0; i < 4; i++)
			delete arr[i];
	}
}
