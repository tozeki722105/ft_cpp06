#include <iostream>
#include <sstream>
#include <string>

typedef enum e_type {
	ERROR = 1,
	CHAR = 2,
	INT = 3,
	FLOAT = 4,
	DOUBLE = 5,
} t_type;

/// @param str must not empty
t_type getNumericType(const std::string &str)
{
	bool point_flag = false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '.')  // (.)が先頭
		return ERROR;

	for (; i + 1 < str.length(); i++) {
		// 初めての(.) && 次が数値
		if (!point_flag && str[i] == '.' && std::isdigit(str[i + 1]))
			point_flag = true;
		else if (!std::isdigit(str[i]))
			return ERROR;
	}

	if (str[i] == 'f' && point_flag)
		return FLOAT;
	else if (std::isdigit(str[i]))
		return point_flag ? DOUBLE : INT;
	return ERROR;
}

t_type getType(const std::string &str)
{
	if (str.empty())
		return ERROR;
	// 特殊ケース
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return FLOAT;
	if (str == "+inf" || str == "-inf" || str == "nan")
		return DOUBLE;

	// char type
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;

	//  numeric type
	if (str.find_first_not_of("0123456789+-.f") != std::string::npos)
		return ERROR;
	return (getNumericType(str));
}

void typePrintfChar(const std::string &str)
{
	char val = str[0];

	if (std::isprint(val))
		std::cout << "char: '" << val << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << static_cast<int>(val) << "\n";
	std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	std::cout << "double: " << static_cast<double>(val) << ".0\n";
}

#include <sstream>
void typePrintInt(const std::string &str)
{
	std::istringstream iss(str);
	int val;
	if (!(iss >> val))
		throw std::invalid_argument("Type overflow: Int");

	if (std::isprint(val))
		std::cout << "char: '" << static_cast<char>(val) << "'\n";
	else
		std::cout << "char: " << "Non displayable\n";
	std::cout << "int: " << val << "\n";
	std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	std::cout << "double: " << static_cast<double>(val) << ".0\n";
}

void typePrintFloat(const std::string &str)
{
	const_cast<std::string &>(str).resize(str.length() - 1);
	std::istringstream iss(str);
	float val;
	if (!(iss >> val))
		throw std::invalid_argument("Type overflow: Float");

	if (str == "nan" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	} else {
		if (std::isprint(static_cast<int>(val)))
			std::cout << "char: '" << static_cast<char>(val) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	if (val == static_cast<float>(static_cast<int>(val))) {
		std::cout << "float: " << val << ".0f\n";
		std::cout << "double: " << static_cast<double>(val) << ".0\n";
	} else {
		std::cout << "float: " << val << "f\n";
		std::cout << "double: " << static_cast<double>(val) << "\n";
	}
}

void typePrintDouble(const std::string &str)
{
	std::istringstream iss(str);
	double val;
	if (!(iss >> val))
		throw std::invalid_argument("Type overflow: Double");

	if (str == "nan" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	} else {
		if (std::isprint(static_cast<int>(val)))
			std::cout << "char: '" << static_cast<char>(val) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	if (val == static_cast<double>(static_cast<int>(val))) {
		std::cout << "float: " << static_cast<float>(val) << ".0f\n";
		std::cout << "double: " << val << ".0\n";
	} else {
		std::cout << "float: " << static_cast<float>(val) << "f\n";
		std::cout << "double: " << val << "\n";
	}
}

void convert(const std::string &str)
{
	switch (getType(str)) {
		case CHAR:
			typePrintfChar(str);
			break;
		case INT:
			typePrintInt(str);
			break;
		case FLOAT:
			typePrintFloat(str);
			break;
		case DOUBLE:
			typePrintDouble(str);
			break;
		default:
			throw std::invalid_argument("Non convertible string");
			break;
	}
}

void disp(const std::string &str)
{
	try {
		convert(str);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";
}

int main()
{
	// validケース
	// std::cout << "<Valid>\n";
	// char
	disp("a");
	// int
	disp("99");
	disp("2147483647");
	disp("-2147483649");
	//
	disp("0.0f");
	disp("-4.2f");
	disp("0.0");
	disp("-4.2");
	disp("nanf");
	disp("+inf");
	disp("42.0f");
	disp("gaganl");
}
