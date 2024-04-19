#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	object;
	Data	*ptr = &object;

	ptr = Serializer::deserialize(Serializer::serialize(&object));
	std::cout << "address = " << &object << "\n" << "pointer = " << ptr << "\n";
}
