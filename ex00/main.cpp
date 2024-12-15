#include <iostream>

#include "ScalarConverter.hpp"

void tryConvert(const std::string &str)
{
	// std::cout << "Test Case: " << str << '\n';
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

	// {
	// 	// char
	// 	tryConvert("a");
	// 	// int
	// 	tryConvert("99");
	// 	tryConvert("-2147483648");
	// 	tryConvert("-2147483649");  // overflow
	// 	// floating point
	// 	tryConvert("0.0f");
	// 	tryConvert("-4.2f");
	// 	tryConvert("0.0");
	// 	tryConvert("-4.2");
	// 	tryConvert("nanf");
	// 	tryConvert("+inf");
	// 	tryConvert("42.0f");

	// 	std::cout << "<イプシロンケース>\n";
	// 	tryConvert("4e2");
	// 	tryConvert("4e-2");
	// 	tryConvert("4.2e2");
	// 	tryConvert("4.2e-2");
	// 	tryConvert("4.2e-2f");

	// 	//?ケース
	// 	std::cout << "<?ケース>\n";
	// 	tryConvert(".42");
	// 	tryConvert(".42f");
	// 	tryConvert("-.42");
	// 	tryConvert("-.42f");
	// 	tryConvert("42.");
	// 	tryConvert("42.f");
	// 	tryConvert("42.e1");
	// 	tryConvert("42.e1f");
	// 	tryConvert(".42e1");
	// 	tryConvert(".42e1f");

	// 	// err
	// 	std::cout << "<エラーケース>\n";
	// 	tryConvert("");
	// 	tryConvert("1.23.4");
	// 	tryConvert("42f");
	// 	tryConvert("4.2fe1");
	// 	tryConvert("42.0e");
	// 	tryConvert("4.2f.");
	// 	tryConvert("-4-2");
	// 	tryConvert("-42-");
	// 	tryConvert("-42.-2");
	// 	tryConvert("2-4.2");
	// 	tryConvert("4.2e-0.2");
	// 	tryConvert("nAn");
	// 	tryConvert("+infff");
	// 	tryConvert("+iNfff");
	// }
}