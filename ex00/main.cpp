#include <iostream>

#include "ScalarConverter.hpp"

void tryConvert(const std::string &str)
{
	try {
		ScalarConverter::convert(str);
	} catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}
	// std::cout << "\n";
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Invalid arg count" << '\n';
		return (0);
	}
	tryConvert(argv[1]);

	// // char
	// tryConvert("a");
	// // int
	// tryConvert("99");
	// tryConvert("-2147483648");
	// tryConvert("-2147483649");  // overflow
	// // floating point
	// tryConvert("0.0f");
	// tryConvert("-4.2f");
	// tryConvert("0.0");
	// tryConvert("-4.2");
	// tryConvert("nanf");
	// tryConvert("+inf");
	// tryConvert("42.0f");
	// // invalid
	// tryConvert("1.23.4");
}
