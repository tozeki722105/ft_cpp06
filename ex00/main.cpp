#include <iostream>
#include <string>

#define HEAD_C "char: "
#define HEAD_I "int: "
#define HEAD_F "float: "
#define FOOT_F "f"
#define HEAD_D "double: "

bool isChar(const std::string &literal)
{
	return (literal.length() == 1);
}

bool isInt(const std::string &literal)
{
	return ()
}

void convert(const std::string &literal)
{
	if (isChar(literal)) {
		std::cout << HEAD_C << literal[0] << '\n'
				  << HEAD_I << static_cast<int>(literal[0]) << '\n'
				  << HEAD_F << static_cast<float>(literal[0]) << FOOT_F << '\n'
				  << HEAD_D << static_cast<double>(literal[0]) << std::endl;
	} else if (isInt(literal)) {
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	convert(argv[1]);
}