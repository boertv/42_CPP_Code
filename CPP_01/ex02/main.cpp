#include <iostream>
#include <string>

int	main()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "address:   " << &string << "\npointer:   " << stringPTR << "\nreference: " << &stringREF << "\n\n";
	std::cout << "address:   " << string << "\npointer:   " << *stringPTR << "\nreference: " << stringREF << '\n';
}
