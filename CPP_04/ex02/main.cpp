#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	// AAnimal yikes;
	Cat	cookie;
	Dog	bob;

	std::cout << cookie.getType() << " says "; cookie.makeSound();
	std::cout << bob.getType() << " says "; bob.makeSound();
}
