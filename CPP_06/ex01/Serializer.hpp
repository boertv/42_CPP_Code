#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <cstdint>
struct Data;

class Serializer
{
	Serializer();
	Serializer(Serializer const& src);
	~Serializer();
	Serializer& operator=(Serializer const& rhs);

public:
	static std::uintptr_t serialize(Data* ptr);
	static Data* deserialize(std::uintptr_t raw);

};

#endif
