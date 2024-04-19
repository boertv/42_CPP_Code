#include "Serializer.hpp"
#include "Data.hpp"

/* CONSTRUCTORS */
Serializer::Serializer() {}
Serializer::Serializer(Serializer const& src) { (void)src; }
Serializer::~Serializer() {}
Serializer& Serializer::operator=(Serializer const& rhs) { (void)rhs; return *this; }

/* STATIC MEMBERS */
std::uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(std::uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
