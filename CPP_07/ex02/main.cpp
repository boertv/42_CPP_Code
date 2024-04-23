#include "Array.hpp"
#include <iostream>

class Test
{
public:
	int val;
	Test() : val(0) {}
	Test(Test const& src) : val(src.val) {}
	~Test() {}
	Test& operator=(int rhs) { val = rhs; return *this; }
	Test& operator=(Test const& rhs) { val = rhs.val; return *this; }
};
std::ostream& operator<<(std::ostream& stream, Test const& rhs) { stream << rhs.val; return stream; }

template <typename T>
void print_arr(Array<T> arr)
{
	try
	{
		size_t i;
		std::cout << "{";
		for (i = 0; i + 1 < arr.size(); i++)
			std::cout << arr[i] << ", ";
		std::cout << arr[i] << "}";
	}
	catch (std::exception const& e)
	{ std::cout << "}"; }
}

int main()
{
	{
		std::cout << "empty..\n";
		Array<int> arr;
		std::cout << "size = " << arr.size() << "\n";
		print_arr(arr); std::cout << "\n";
		std::cout << "\n";
	}
	{
		std::cout << "int..\n";
		Array<int> arr(5);
		std::cout << "size = " << arr.size() << "\n";
		print_arr(arr); std::cout << "\n";
		try {
		arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4; }
		catch (std::exception const& e) {
			std::cout << e.what() << "\n"; }
		print_arr(arr); std::cout << "\n";
		try {
		arr[5] = 5; }
		catch (std::exception const& e) {
			std::cout << e.what() << " caught\n"; }
		print_arr(arr); std::cout << "\n";
		std::cout << "\n";
	}
	{
		std::cout << "float..\n";
		Array<float> arr(42);
		std::cout << "size = " << arr.size() << "\n";
		print_arr(arr); std::cout << "\n";
		try {
		arr[19] = 19.19; }
		catch (std::exception const& e) {
			std::cout << e.what() << "\n"; }
		print_arr(arr); std::cout << "\n";
		std::cout << "\n";
	}
	{
		std::cout << "class..\n";
		Array<Test> arr(5);
		std::cout << "size = " << arr.size() << "\n";
		print_arr(arr); std::cout << "\n";
		try {
		arr[2] = 19; }
		catch (std::exception const& e) {
			std::cout << e.what() << "\n"; }
		print_arr(arr); std::cout << "\n";
	}
}
