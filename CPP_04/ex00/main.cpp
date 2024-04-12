#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << '\n';
		std::cout << j->getType() << " says "; j->makeSound();
		std::cout << i->getType() << " says "; i->makeSound();
		std::cout << meta->getType() << " says "; meta->makeSound();
		std::cout << '\n';
		delete i;
		delete j;
		delete meta;
	}
	std::cout << '\n';

	{
		std::cout << "WRONG ANIMAL TESTS\n";
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* c = new WrongCat();
		std::cout << '\n';
		std::cout << a->getType() << " says "; a->makeSound();
		std::cout << c->getType() << " says "; c->makeSound();
		delete a;
		delete c;
	}
}
