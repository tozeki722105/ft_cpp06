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

// int main(int argc, char **argv)
int main()
{
	// if (argc != 2) {
	// 	std::cout << "Invalid arg count" << '\n';
	// 	return (0);
	// }
	// tryConvert(argv[1]);

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

	std::string testCases[] = {// 基本的なリテラル
			"a", "42", "42.0f", "42.0",

			// 境界値
			"2147483647", "-2147483648", "3.4028235e+38f", "-3.4028235e+38f", "1.1754942e-38f",
			"1.7976931348623157e+308", "-1.7976931348623157e+308",

			// 特殊値
			"+inf", "-inf", "nan", "+inff", "-inff", "nanf",

			// 浮動小数点の境界付近
			"3.4028234e+38f", "3.4028236e+38f", "1.1754942e-38f", "1.1754941e-38f",
			"1.7976931348623157e+308", "-1.7976931348623157e+308",

			// 異常なケース
			"", "123abc", "hello", "'abc'", "+-42"};

	for (size_t i = 0; i < sizeof(testCases) / sizeof(std::string); ++i) {
		std::cout << "Test Case: " << testCases[i] << std::endl;
		tryConvert(testCases[i]);
		std::cout << "-------------------------" << std::endl;
	}
}