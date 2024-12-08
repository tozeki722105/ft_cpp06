#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->c = 'b';
	data->num = 123;
	data->str = "hello world";

	uintptr_t serial = Serializer::serialize(data);
	Data *deserialData = Serializer::deserialize(serial);
	if (data->c == deserialData->c && data->num == deserialData->num &&
			data->str == deserialData->str) {
		std::cout << "ok!" << std::endl;
	} else {
		std::cout << "ko" << std::endl;
	}
}