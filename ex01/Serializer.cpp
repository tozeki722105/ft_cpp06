#include "Serializer.hpp"

uintptr_t Serializer::serialize(const Data* ptr)
{
	if (!ptr)
		throw std::runtime_error("serialize: Invalid arg");
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}