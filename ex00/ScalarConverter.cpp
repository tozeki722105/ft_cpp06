#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>

void ScalarConverter::putCharPrintable(int c)
{
	if (std::isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

void ScalarConverter::typePutfChar(const std::string &str)
{
	char val = str[0];

	putCharPrintable(val);
	std::cout << "int: " << static_cast<int>(val) << "\n";
	std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	std::cout << "double: " << static_cast<double>(val) << ".0\n";
}

void ScalarConverter::typePutInt(const std::string &str)
{
	std::istringstream iss(str);
	int val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Int");

	putCharPrintable(val);
	std::cout << "int: " << val << "\n";
	std::cout << "float: " << static_cast<float>(val) << ".0f\n";
	std::cout << "double: " << static_cast<double>(val) << ".0\n";
}

template <typename T>
void ScalarConverter::typePutFloatingPoint(T val, const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	} else {
		putCharPrintable(static_cast<int>(val));
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
	if (val == static_cast<T>(static_cast<int>(val))) {
		std::cout << "float: " << static_cast<float>(val) << ".0f\n";
		std::cout << "double: " << static_cast<double>(val) << ".0\n";
	} else {
		std::cout << "float: " << static_cast<float>(val) << "f\n";
		std::cout << "double: " << static_cast<double>(val) << "\n";
	}
}
void ScalarConverter::typePutFloat(const std::string &str)
{
	const_cast<std::string &>(str).resize(str.length() - 1);
	std::istringstream iss(str);
	float val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Float");

	typePutFloatingPoint(val, str);
}

void ScalarConverter::typePutDouble(const std::string &str)
{
	std::istringstream iss(str);
	double val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Double");

	typePutFloatingPoint(val, str);
}

/// @param str must not empty
ScalarConverter::t_type ScalarConverter::getNumericType(const std::string &str)
{
	bool point_flag = false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '.')  // 符号を除いた先頭が(.)
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

ScalarConverter::t_type ScalarConverter::getType(const std::string &str)
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
	return getNumericType(str);
}

void ScalarConverter::convert(const std::string &str)
{
	switch (getType(str)) {
		case CHAR:
			typePutfChar(str);
			break;
		case INT:
			typePutInt(str);
			break;
		case FLOAT:
			typePutFloat(str);
			break;
		case DOUBLE:
			typePutDouble(str);
			break;
		default:
			throw std::invalid_argument("Non convertible string");
			break;
	}
}
