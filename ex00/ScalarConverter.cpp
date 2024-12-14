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

bool isNanOrInf(const std::string &str)
{
	return str == "nan" || str == "+inf" || str == "-inf";
}

void ScalarConverter::typePutChar(const std::string &str)
{
	char val = str[0];

	// char
	putCharPrintable(static_cast<int>(val));
	// int
	std::cout << "int: " << static_cast<int>(val) << "\n";
	// float
	std::cout << "float: " << val << ".0f\n";
	// double
	std::cout << "double: " << val << ".0f\n";
}

void ScalarConverter::typePutInt(const std::string &str)
{
	std::istringstream iss(str);
	int val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Int");

	// char
	if (isOverFlow<int, char>(val))
		std::cout << "char: impossible\n";
	else
		putCharPrintable(static_cast<int>(val));
	// int
	std::cout << "int: " << static_cast<int>(val) << "\n";
	// float
	if (isOverFlow<int, float>(val))
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << val << ".0f\n";
	// double
	std::cout << "double: " << val << ".0f\n";
}

void ScalarConverter::typePutFloat(const std::string &str)
{
	const_cast<std::string &>(str).resize(str.length() - 1);
	std::istringstream iss(str);
	float val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Float");

	// char
	if (isNanOrInf(str) || isOverFlow<float, char>(val) || !isInt(val))
		std::cout << "char: impossible\n";
	else
		putCharPrintable(static_cast<int>(val));
	// int
	if (isNanOrInf(str) || isOverFlow<float, int>(val) || !isInt(val))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(val) << "\n";
	// float
	if (isInt(val))
		std::cout << "float: " << val << ".0f\n";
	else
		std::cout << "float: " << val << "f\n";
	// double
	if (isInt(val))
		std::cout << "double: " << val << ".0f\n";
	else
		std::cout << "double: " << val << "f\n";
}

void ScalarConverter::typePutDouble(const std::string &str)
{
	std::istringstream iss(str);
	double val;
	if (!(iss >> val))
		throw std::invalid_argument("Conversion failed: Double");

	// char
	if (isNanOrInf(str) || isOverFlow<double, char>(val) || !isInt(val))
		std::cout << "char: impossible\n";
	else
		putCharPrintable(static_cast<int>(val));
	// int
	if (isNanOrInf(str) || isOverFlow<double, int>(val) || !isInt(val))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(val) << "\n";
	// float
	if (isOverFlow<float>(val))
		std::cout << "float: impossible\n";
	else if (isInt(val))
		std::cout << "float: " << val << ".0f\n";
	else
		std::cout << "float: " << val << "f\n";
	// double
	if (isInt(val))
		std::cout << "double: " << val << ".0f\n";
	else
		std::cout << "double: " << val << "f\n";
}

/// @param str must not empty
ScalarConverter::e_type ScalarConverter::getNumericType(const std::string &str)
{
	bool point_flag = false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	// if (str[i] == '.')  // 符号を除いた先頭が(.)
	// 	return ERROR;

	for (; i + 1 < str.length(); i++) {
		// 初めての(.) && 次が数値
		if (!point_flag && str[i] == '.')  // && std::isdigit(str[i + 1])
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

ScalarConverter::e_type ScalarConverter::getType(const std::string &str)
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
	std::string::size_type e_pos = str.find('e');
	if (e_pos == std::string::npos)
		return (getNumericType(str));
	if (str.rfind('e') != e_pos)  // eが複数ある場合
		return ERROR;
	std::string mantissa = str.substr(0, e_pos);
	bool fFlag = (str.find('f') == str.length() - 1);  // fが最後尾に存在する場合　ex)42e3f
	std::string exponent = str.substr(e_pos + 1, str.length() - e_pos - 1 - fFlag);
	e_type mantissaType = getNumericType(mantissa);
	if (mantissaType == ERROR || mantissaType == FLOAT  // ex)42fe1,42fe2f
			|| getNumericType(exponent) != INT)
		return ERROR;
	return fFlag ? FLOAT : DOUBLE;
}

void ScalarConverter::convert(const std::string &str)
{
	switch (getType(str)) {
		case CHAR:
			typePutChar(str);
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
